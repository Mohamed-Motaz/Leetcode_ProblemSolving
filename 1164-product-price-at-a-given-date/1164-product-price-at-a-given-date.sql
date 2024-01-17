# Write your MySQL query statement below

SELECT products.product_id as product_id, IFNULL(p.new_price, 10) as price
FROM products
LEFT JOIN 
(
    SELECT product_id, new_price
    FROM products
    WHERE (product_id, change_date) 
    IN
    (
        SELECT product_id, MAX(change_date)
        FROM products
        WHERE change_date <= "2019-08-16"
        GROUP BY product_id
    ) 
) as p on products.product_id = p.product_id
GROUP BY product_id
