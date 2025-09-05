WITH temp AS (
    SELECT 
        a.id,
        a.name,
        COUNT(*) AS cnt
    FROM Employee a
    JOIN Employee b
        ON a.id = b.managerId
    GROUP BY a.id, a.name
)
SELECT 
name
FROM temp
WHERE cnt >= 5;
