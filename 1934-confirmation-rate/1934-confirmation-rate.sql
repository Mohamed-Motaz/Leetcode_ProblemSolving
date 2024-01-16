# Write your MySQL query statement below


select signups.user_id, 
ROUND(
    IFNULL(confirmed.count, 0)/ IFNULL(total.count, 1) ,2)
    as confirmation_rate
from signups
left join (
    select user_id, count(*) as count
    from confirmations
    group by user_id, action
    having action = "confirmed"
    ) as confirmed
on signups.user_id = confirmed.user_id
left join (
    select user_id, count(*) as count
    from confirmations
    group by user_id
    ) as total
on signups.user_id = total.user_id;


