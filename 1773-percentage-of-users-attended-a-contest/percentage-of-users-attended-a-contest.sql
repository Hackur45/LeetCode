WITH temp AS (
    SELECT 
        contest_id, 
        COUNT(distinct user_id) AS tp
    FROM Register
    GROUP BY contest_id
    order by contest_id
)
SELECT 
    t.contest_id,
    ROUND((t.tp / (SELECT COUNT(*) FROM Users)) * 100, 2) AS percentage
FROM temp t
ORDER BY percentage desc, t.contest_id asc;
