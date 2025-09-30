with temp as (
    select reports_to, 
           count(*) as reports_count,
           round(avg(age)) as average_age
    from employees
    where reports_to is not null
    group by reports_to
)
select t.reports_to as employee_id, 
       e.name as name, 
       t.reports_count as reports_count, 
       t.average_age
from employees e 
join temp t 
  on e.employee_id = t.reports_to
  order by employee_id;
