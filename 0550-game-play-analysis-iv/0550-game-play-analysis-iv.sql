# Write your MySQL query statement below


WITH mn as
(
    SELECT player_id, MIN(event_date) as first_day
    FROM activity
    GROUP BY player_id
), 
cnt as
(
    SELECT COUNT(*) as total_logged_twice
    FROM activity as a
    INNER JOIN mn
    ON a.player_id = mn.player_id
    WHERE DATE_SUB(event_date, INTERVAL 1 DAY) = mn.first_day
)

SELECT ROUND(
            CAST(cnt.total_logged_twice as DECIMAL) / 
            CAST(COUNT(distinct activity.player_id) as DECIMAL), 
    2) as fraction
FROM cnt
INNER JOIN activity;



