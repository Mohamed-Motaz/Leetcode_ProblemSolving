# Write your MySQL query statement below


SELECT d.name as Department, e1.name as Employee, e1.salary
FROM employee e1
INNER JOIN department as d
ON e1.departmentId = d.id
WHERE (
    SELECT COUNT(distinct salary)
    FROM employee e2
    WHERE e2.departmentId = e1.departmentId
    AND e2.salary > e1.salary
) <= 2