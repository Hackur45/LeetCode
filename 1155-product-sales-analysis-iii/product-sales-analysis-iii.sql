WITH fy AS (
    SELECT product_id AS id, MIN(year) AS fyear
    FROM Sales
    GROUP BY product_id
) 
SELECT 
    b.product_id, 
    b.year AS first_year, 
    b.quantity AS quantity, 
    b.price AS price
FROM sales b
JOIN fy a 
    ON a.id = b.product_id 
   AND a.fyear = b.year;
