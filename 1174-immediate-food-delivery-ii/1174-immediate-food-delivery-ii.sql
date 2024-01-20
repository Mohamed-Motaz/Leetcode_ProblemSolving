# MY SOL
WITH first_orders AS
(
    SELECT customer_id, MIN(order_date) as order_date
    FROM Delivery
    GROUP BY customer_id
)
SELECT ROUND(
        (COUNT(*))
        /
        (SELECT COUNT(*) FROM first_orders)
        * 100
    ,2) AS immediate_percentage
FROM Delivery as d
INNER JOIN first_orders as fo
ON d.customer_id = fo.customer_id 
    AND d.order_date = fo.order_date
WHERE d.order_date = d.customer_pref_delivery_date



# # Write your MySQL query statement below
# WITH first_orders as
# (
#     SELECT customer_id, MIN(order_date) as first_order
#     FROM delivery
#     GROUP BY customer_id
# ),
# first_orders_immediate as
# (
#     SELECT delivery.customer_id, delivery.order_date
#     FROM delivery
#     JOIN first_orders
#     ON delivery.customer_id = first_orders.customer_id
#     AND delivery.order_date = first_orders.first_order
#     WHERE delivery.order_date = delivery.customer_pref_delivery_date
# )

# SELECT ROUND(
#     (CAST((SELECT COUNT(*) FROM first_orders_immediate) AS FLOAT)
#         / 
#     CAST((SELECT COUNT(first_orders.customer_id) from first_orders) AS FLOAT)
#     )* 100
#     ,2) as immediate_percentage

# SELECT ROUND(AVG(order_date = customer_pref_delivery_date) * 100, 2) as immediate_percentage
# FROM delivery
# WHERE 
#     (customer_id, order_date)
# IN
#     (
#     SELECT customer_id, MIN(order_date) as first_order
#     FROM delivery
#     GROUP BY customer_id
#     );