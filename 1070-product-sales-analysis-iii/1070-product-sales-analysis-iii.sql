# Write your MySQL query statement below



WITH first_year as
(
    SELECT product_id, MIN(year) as first_year
    FROM Sales
    GROUP BY product_id
)
SELECT s.product_id, fy.first_year, s.quantity, s.price
FROM Sales as s
INNER JOIN first_year as fy
ON 
    s.product_id = fy.product_id 
    AND
    s.year = fy.first_year;











































# SELECT product_id, year as first_year, quantity, price
# FROM sales
# WHERE 
#     (product_id, year) 
# IN
# (
#     SELECT product_id, MIN(year) as first_year
#     FROM SALES
#     GROUP BY product_id
# )