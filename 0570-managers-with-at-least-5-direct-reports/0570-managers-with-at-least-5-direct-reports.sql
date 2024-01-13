# Write your MySQL query statement below

# select name from 
# employee
# where id in
# (
#     select managerId
#     from employee
#     where managerId IS NOT NULL
#     group by managerId
#     having count(*) >= 5
# );


select e2.name
from employee as e2
inner join employee as e1
on e2.id = e1.managerId
group by e1.managerId
having count(*) >= 5;

# select e2.name
# from employee as e1
# inner join employee as e2
# on e1.managerId = e2.id
# where e1.managerId IS NOT NULL
# group by e1.managerId
# having count(*) >= 5