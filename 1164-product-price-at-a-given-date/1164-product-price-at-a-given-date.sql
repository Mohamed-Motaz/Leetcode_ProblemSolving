# Write your MySQL query statement below

#great question

# #first sol ######################################################################################
# #first case, get all that have a change date before 8-16
# SELECT product_id, 10 as price
# FROM products
# GROUP BY product_id
# HAVING MIN(change_date) > "2019-08-16"

# UNION ALL

# #second case, get all that have a change date before 8-16
# SELECT product_id, new_price
#     FROM products
#     WHERE (product_id, change_date) 
#     IN
#     (
#         SELECT product_id, MAX(change_date)
#         FROM products
#         WHERE change_date <= "2019-08-16"
#         GROUP BY product_id
#     ) 



#second sol ######################################################################################

# SELECT products.product_id as product_id, IFNULL(p.new_price, 10) as price
# FROM products
# LEFT JOIN 
# (
#     SELECT product_id, new_price
#     FROM products
#     WHERE (product_id, change_date) 
#     IN
#     (
#         SELECT product_id, MAX(change_date)
#         FROM products
#         WHERE change_date <= "2019-08-16"
#         GROUP BY product_id
#     ) 
# ) as p on products.product_id = p.product_id
# GROUP BY product_id

#third sol ######################################################################################

SELECT products.product_id as product_id, IFNULL(p.new_price, 10) as price
FROM products
LEFT JOIN 
(
    SELECT products.product_id, products.new_price
    FROM products
    INNER JOIN
    (
        SELECT product_id, MAX(change_date) as change_date
        FROM products
        WHERE change_date <= "2019-08-16"
        GROUP BY product_id
    ) as pp
    ON products.product_id = pp.product_id AND products.change_date = pp.change_date
) as p on products.product_id = p.product_id
GROUP BY product_id
