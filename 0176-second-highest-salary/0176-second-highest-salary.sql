# Write your MySQL query statement below
WITH res as (
    SELECT distinct salary
    FROM employee
    ORDER BY salary DESC
    LIMIT 1
    OFFSET 1
)
SELECT (CASE WHEN COUNT(*) = 0 THEN NULL
        ELSE salary END) as SecondHighestSalary
FROM res
