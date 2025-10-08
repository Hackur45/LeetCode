select product_id, new_price AS price
from products
where (product_id, change_date) IN (
    select product_id, MAX(change_date)
    from products
    where change_date <= '2019-08-16'
    group BY product_id
)

union

SELECT product_id, 10 AS price
FROM products
WHERE product_id NOT IN (
    SELECT DISTINCT product_id
    FROM products
    WHERE change_date <= '2019-08-16'
);
