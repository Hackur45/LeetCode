# Write your MySQL query statement below
# first find all the first orders of the customers
# after that find the immediate orders from first orders

with cte as(
    select delivery_id, customer_id, order_date,customer_pref_delivery_date, row_number() over(partition by customer_id order by order_date) as rn
    from Delivery 
),
firstOrders as(
    select delivery_id as id, customer_id as cust_id, order_date, customer_pref_delivery_date as cpd
    from cte 
    where rn = 1
)
-- select round(count(*)*100/ (select count(*) from delivery),2) as immediate_percentage
-- from firstOrders;

select round(count(case when order_date = cpd then 1 end)*100 / count(*),2) as immediate_percentage from firstOrders;

