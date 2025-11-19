-- # Write your MySQL query statement below
-- with getmgid as(
--     select managerId as id from employee
--     group by managerid
--     having count(managerId) >= 5
-- )
-- select a.name
-- from employee a join getmgid b
-- on a.id = b.id


select a.name
from employee a join 
(select b.managerId as id from employee b group by managerId having count(managerId) >= 5) as c
on a.id = c.id
