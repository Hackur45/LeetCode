# Write your MySQL query statement below

WITH internal AS (
    SELECT 
        a.machine_id as machine_id, 
        a.process_id, 
        b.timestamp - a.timestamp AS se
    FROM Activity a
    JOIN Activity b
      ON a.machine_id = b.machine_id
     AND a.process_id = b.process_id
    WHERE a.activity_type = 'start'
      AND b.activity_type = 'end'
)

SELECT 
    machine_id,
    ROUND(AVG(se),3) AS processing_time
FROM internal
GROUP BY machine_id;
