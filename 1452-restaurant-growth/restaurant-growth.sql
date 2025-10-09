# Write your MySQL query statement below
with temp as(
    select visited_on, sum(amount) as s
    from customer
    group by visited_on
    order by visited_on
),
runningsum as(
    select
    row_number() over(order by visited_on) as rn, 
    visited_on, sum(s) over(order by visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) as rs
    from temp
),
justsixdayswale as(
    select  b.visited_on as visited_on, b.rs as ls
    from runningsum a  join runningsum b
    on datediff(b.visited_on,a.visited_on) = 6
)
select visited_on, ls as amount, round(ls/7,2) as average_amount  from justsixdayswale;