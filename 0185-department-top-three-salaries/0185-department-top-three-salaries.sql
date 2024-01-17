# Write your MySQL query statement below

SELECT d.name as Department, e.name as Employee, e.salary as Salary
FROM EMPLOYEE as e
INNER JOIN DEPARTMENT as d
ON e.departmentId = d.id
WHERE
#correlated subquery
(
    SELECT COUNT(distinct salary)
    FROM EMPLOYEE
    WHERE salary > e.salary AND departmentId = e.departmentId
    LIMIT 3
) < 3
