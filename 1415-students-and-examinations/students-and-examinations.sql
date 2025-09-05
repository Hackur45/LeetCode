-- WITH unq AS (
--     SELECT 
--         student_id AS sid,
--         subject_name AS subname,
--         COUNT(*) AS subcount
--     FROM Examinations
--     GROUP BY student_id, subject_name
-- ),
-- comb AS (
--     SELECT 
--         a.student_id, 
--         a.student_name, 
--         b.subject_name
--     FROM Students a 
--     CROSS JOIN Subjects b
-- )
-- SELECT 
--     s.student_id, 
--     s.student_name, 
--     s.subject_name, 
--     COALESCE(u.subcount, 0) AS attended_exams
-- FROM comb s
-- LEFT JOIN unq u
--     ON u.sid = s.student_id
--    AND u.subname = s.subject_name
-- ORDER BY s.student_id, s.subject_name;


SELECT s.student_id, s.student_name, sub.subject_name,COALESCE(COUNT(e.student_id),0) AS attended_exams
FROM Students s JOIN Subjects sub LEFT JOIN Examinations  e
ON e.student_id = s.student_id and sub.subject_name = e.subject_name
GROUP BY s.student_id, sub.subject_name
ORDER BY s.student_id,sub.subject_name; 