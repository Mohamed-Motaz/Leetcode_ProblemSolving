# Write your MySQL query statement below



select distinct l1.num as ConsecutiveNums
FROM logs as l1
INNER JOIN logs as l2 on l2.id = l1.id + 1 AND l2.num = l1.num
INNER JOIN logs as l3 on l3.id = l2.id + 1 AND l3.num = l2.num


