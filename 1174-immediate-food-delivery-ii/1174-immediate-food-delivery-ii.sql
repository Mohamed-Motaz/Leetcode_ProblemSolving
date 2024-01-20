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
# )
# SELECT *
# #COUNT(*), COUNT(distinct first_orders.customer_id), ROUND( COUNT(*) / COUNT(distinct first_orders.customer_id), 2) as immediate_percentage
# FROM delivery
# INNER JOIN first_orders
# ON delivery.customer_id = first_orders.customer_id
# WHERE (delivery.customer_id, first_orders.first_order) 
# IN
#     (
#         SELECT customer_id, order_date
#         FROM delivery
#         WHERE order_date = customer_pref_delivery_date
#     );





