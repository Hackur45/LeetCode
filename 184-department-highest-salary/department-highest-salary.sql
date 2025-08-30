SELECT t.dname AS Department,
       t.ename AS Employee,
       t.salary AS Salary
FROM (
    SELECT e.id AS eid, 
           e.name AS ename, 
           e.salary, 
           e.departmentId AS edid,
           d.id AS did, 
           d.name AS dname
    FROM Employee e 
    JOIN Department d
    ON e.departmentId = d.id
) AS t
WHERE t.salary = (
    SELECT MAX(e2.salary)
    FROM Employee e2
    WHERE e2.departmentId = t.edid
);
