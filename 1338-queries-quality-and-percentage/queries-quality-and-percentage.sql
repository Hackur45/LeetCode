SELECT 
    q.query_name,
    ROUND(AVG(q.rating / q.position), 2) AS quality,
    (
        SELECT 
            round(COUNT(*) * 100.0 / 
            (SELECT COUNT(*) 
             FROM Queries q2 
             WHERE q2.query_name = q.query_name),2)
        FROM Queries q1
        WHERE q1.query_name = q.query_name
          AND q1.rating < 3
    ) AS poor_query_percentage
FROM Queries q
GROUP BY q.query_name;
