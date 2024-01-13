# Write your MySQL query statement below

select name from 
employee
where id in
(
    select managerId
    from employee
    where managerId IS NOT NULL
    group by managerId
    having count(*) >= 5
);