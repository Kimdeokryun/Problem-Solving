-- 코드를 입력하세요
WITH RECURSIVE hours AS (
    SELECT 0 AS hour
    UNION ALL
    SELECT hour + 1 FROM hours WHERE hour < 23
)

SELECT hours.hour as HOUR, IFNULL(a.count, 0) as COUNT
FROM hours
LEFT JOIN (SELECT HOUR(datetime) as HOUR, COUNT(*) as count
           FROM animal_outs
           GROUP BY HOUR
           ORDER BY HOUR) a
ON hours.hour = a.HOUR;