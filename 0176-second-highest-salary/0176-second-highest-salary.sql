# Write your MySQL query statement below

SELECT (
    CASE 
    WHEN COUNT(distinct salary)=1 THEN NULL
    ELSE (SELECT salary FROM Employee GROUP BY salary ORDER BY salary DESC LIMIT 1 OFFSET 1 )
    END) 
    as SecondHighestSalary
FROM employee



# MY NEW SOL
# WITH res as (
#     SELECT distinct salary
#     FROM employee
#     ORDER BY salary DESC
#     LIMIT 1
#     OFFSET 1
# )
# SELECT (CASE WHEN COUNT(*) = 0 THEN NULL
#         ELSE salary END) as SecondHighestSalary
# FROM res

