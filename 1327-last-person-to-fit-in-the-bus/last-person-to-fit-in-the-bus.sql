# Write your MySQL query statement below
with cte as(
    select turn, person_id, person_name, weight
    from Queue
    order by turn
),
running as(
    select turn, person_id, person_name, sum(weight) over(order by turn) as rs
    from cte
)
select person_name
from running
where rs = (
    select max(rs) from running 
    where rs <= 1000
)