
# SELECT d.name as Department, e.name as Employee, e.salary as Salary
# FROM EMPLOYEE as e
# INNER JOIN DEPARTMENT as d
# ON e.departmentId = d.id
# INNER JOIN
# (
#     SELECT COUNT(distinct salary)
#     FROM EMPLOYEE
#     WHERE salary > e.salary AND departmentId = e.departmentId
#     LIMIT 3
# ) as S
# < 3


# BETTER PERF


SELECT d.name as Department, e1.name as Employee, e1.salary as Salary
FROM EMPLOYEE as e1
INNER JOIN DEPARTMENT as d
ON e1.departmentId = d.id
LEFT JOIN Employee as e2
ON e1.salary < e2.salary AND e1.departmentId = e2.departmentId
GROUP BY e1.id
HAVING COUNT(distinct e2.salary) <= 2; 