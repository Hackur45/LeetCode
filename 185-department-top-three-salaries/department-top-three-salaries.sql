# Write your MySQL query statement below
with toprankers as(
    select id, name , salary, departmentId, dense_rank() over(partition by departmentId order by salary desc) as rnk
    from Employee
),
topthrees as(
    select name, salary, departmentid, rnk
    from toprankers
    where rnk in (1,2,3)
)
select b.name as Department, a.name as Employee, a.salary as Salary
from topthrees a join department b
on a.departmentid = b.id
-- select * from topthrees;
-- select * from toprankers