# Write your MySQL query statement below


SELECT customer_id
FROM customer
GROUP BY customer_id
HAVING COUNT(distinct product_key) = (SELECT COUNT(*) from product)



# #clean up
# WITH clean_up as
# (
#     SELECT customer_id, product_key
#     FROM customer
#     GROUP BY customer_id, product_key
# ),
# counts as 
# (
#     SELECT customer_id, COUNT(*) as prods
#     FROM clean_up
#     GROUP BY customer_id
# ),
# tot_prods as
# (
#     SELECT COUNT(*) as cnt
#     FROM product
# )

# SELECT customer_id
# FROM counts
# JOIN tot_prods
# WHERE prods = tot_prods.cnt;

