#MY SOL
SELECT ROUND( 
    COUNT(*)
    /
    (SELECT COUNT(distinct player_id) FROM Activity)
    , 2) AS fraction
FROM Activity
WHERE (player_id, DATE_SUB(event_date, INTERVAL 1 DAY))
IN (
    SELECT player_id, MIN(event_date) as first_login
    FROM Activity
    GROUP BY player_id
)



# # Write your MySQL query statement below


# #####################CTE#######################
# # WITH mn as
# # (
# #     SELECT player_id, MIN(event_date) as first_day
# #     FROM activity
# #     GROUP BY player_id
# # ), 
# # cnt as
# # (
# #     SELECT COUNT(*) as total_logged_twice
# #     FROM activity as a
# #     INNER JOIN mn
# #     ON a.player_id = mn.player_id
# #     AND DATE_SUB(event_date, INTERVAL 1 DAY) = mn.first_day
# # )

# # # SELECT ROUND(
# # #             CAST(cnt.total_logged_twice as DECIMAL) / 
# # #             CAST(COUNT(distinct activity.player_id) as DECIMAL), 
# # #     2) as fraction
# # # FROM cnt
# # # INNER JOIN activity;

# # SELECT ROUND(
# #     (SELECT total_logged_twice from cnt) /
# #     (SELECT count(player_id) from mn),
# #     2) as fraction;



# #NORMAL SOL

# SELECT 
#     ROUND(
#         COUNT(*) / 
#         (SELECT COUNT(Distinct player_id) from activity), 
#     2) as fraction
# FROM activity
# WHERE (player_id, DATE_SUB(event_date, INTERVAL 1 DAY)) in
# (
#     SELECT player_id, min(event_date) as first_login
#     FROM activity
#     GROUP BY player_id
# )





