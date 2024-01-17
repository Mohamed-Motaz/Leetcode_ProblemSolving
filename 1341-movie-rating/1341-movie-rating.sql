# Write your MySQL query statement below

(
SELECT users.name as results
FROM MovieRating as m
INNER JOIN users
ON users.user_id = m.user_id
GROUP BY (m.user_id)
ORDER BY COUNT(*) DESC, users.name
LIMIT 1
)
UNION ALL
(
SELECT movies.title as results
FROM MovieRating as m
INNER JOIN movies
ON movies.movie_id = m.movie_id
WHERE SUBSTR(created_at, 1, 7) = "2020-02"
GROUP BY (m.movie_id)
ORDER BY AVG(m.rating) DESC, movies.title
LIMIT 1
)


# (
# SELECT users.name as results
# FROM MovieRating as m
# INNER JOIN users
# ON users.user_id = m.user_id
# GROUP BY (m.user_id)
# HAVING COUNT(*) = 
#         (SELECT COUNT(*) as cnt 
#          FROM MovieRating 
#          GROUP BY user_id 
#          ORDER BY cnt 
#          DESC 
#          LIMIT 1)
# ORDER BY users.name
# LIMIT 1
# )
# UNION ALL
# (
# SELECT movies.title as results
# FROM MovieRating as m
# INNER JOIN movies
# ON movies.movie_id = m.movie_id
# WHERE SUBSTR(created_at, 1, 7) = "2020-02"
# GROUP BY (m.movie_id)
# HAVING AVG(m.rating) = 
#         (SELECT AVG(rating) as rating 
#          FROM MovieRating 
#          WHERE SUBSTR(created_at, 1, 7) = "2020-02"
#          GROUP BY movie_id 
#          ORDER BY rating 
#          DESC 
#          LIMIT 1)
# ORDER BY movies.title
# LIMIT 1
# )