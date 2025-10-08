-- # Write your MySQL query statement below
-- with low as(
--     select count(account_id) as l from accounts
--     where income < 20000
-- ),avrg as(
--     select count(account_id) as av from accounts
--     where income between 20000 and 50000
-- ),high as(
--     select count(account_id) as h from accounts
--     where income > 50000
-- )

-- select l,av,h 
-- from low,avrg,high;

with temp as(
    select
        case 
        when income < 20000 then 'Low Salary'
        when ((income >= 20000) and (income <= 50000)) then 'Average Salary'
        when income > 50000 then 'High Salary'
        end as category
    from accounts
)
select category, count(category) as accounts_count from temp
group by category

union

select 'Average Salary' , 0 
where not exists (select 1 from temp where category = "Average Salary")
order by accounts_count desc;