# Write your MySQL query statement below

SELECT DISTINCT p.project_id,round(sum(e.experience_years)over(partition by project_id)/ COUNT(e.employee_id) OVER (PARTITION BY p.project_id),2) as average_years
FROM Project p Left Join Employee e
ON p.employee_id = e.employee_id;