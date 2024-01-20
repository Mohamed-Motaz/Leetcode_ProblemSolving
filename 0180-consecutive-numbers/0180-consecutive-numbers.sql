# Write your MySQL query statement below



#MY SOL


SELECT distinct l1.num as ConsecutiveNums
FROM Logs as l1
INNER JOIN Logs as l2 
ON l1.id + 1 = l2.id AND l1.num = l2.num
INNER JOIN Logs as l3
ON l2.id + 1 = l3.id AND l2.num = l3.num;


# # select distinct l1.num as ConsecutiveNums
# # FROM logs as l1
# # INNER JOIN logs as l2 on l2.id = l1.id + 1 AND l2.num = l1.num
# # INNER JOIN logs as l3 on l3.id = l2.id + 1 AND l3.num = l2.num


# set @prev = null;
# set @conCount = 0;

# select distinct t.Num as ConsecutiveNums from
# (select Num,
# case
# when @prev = Num then @conCount := @conCount + 1
# when (@prev := Num) is not null then @conCount := 1
# end as ConCount
# from Logs
# ) as t
# where t.ConCount = 3