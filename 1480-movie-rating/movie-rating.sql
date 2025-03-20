# Write your MySQL query statement below
(select u.name as results from MovieRating m join users u on u.user_id=m.user_id group by 1 order by count(1) desc, name limit 1)
union all 
(select mo.title as results from MovieRating m join movies mo on m.movie_id=mo.movie_id where created_at>'2020-01-31'  and created_at<'2020-03-01' group by 1 order by avg(m.rating) desc, title limit 1);




-- (SELECT name AS results
-- FROM MovieRating JOIN Users USING(user_id)
-- GROUP BY name
-- ORDER BY COUNT(*) DESC, name
-- LIMIT 1)

-- UNION ALL

-- (SELECT title AS results
-- FROM MovieRating JOIN Movies USING(movie_id)
-- WHERE EXTRACT(YEAR_MONTH FROM created_at) = 202002
-- GROUP BY title
-- ORDER BY AVG(rating) DESC, title
-- LIMIT 1);