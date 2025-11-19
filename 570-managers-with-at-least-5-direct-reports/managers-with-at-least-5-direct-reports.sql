# Write your MySQL query statement below
with getmgid as(
    select managerId as id from employee
    group by managerid
    having count(managerId) >= 5
)
select a.name
from employee a join getmgid b
on a.id = b.id