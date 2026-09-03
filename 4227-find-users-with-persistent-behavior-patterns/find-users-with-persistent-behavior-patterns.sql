# Write your MySQL query statement below
WITH prev AS (
    SELECT
        user_id,
        action_date,
        action,
        LAG(action) OVER (
            PARTITION BY user_id
            ORDER BY action_date
        ) AS prev_action,
        LAG(action_date) OVER (
            PARTITION BY user_id
            ORDER BY action_date
        ) AS prev_date
    FROM activity
),

marked AS (
    SELECT *,
        CASE
            WHEN prev_action = action
             AND action_date = DATE_ADD(prev_date, INTERVAL 1 DAY)
            THEN 0
            ELSE 1
        END AS is_new
    FROM prev
),

grouped AS (
    SELECT *,
        SUM(is_new) OVER (
            PARTITION BY user_id
            ORDER BY action_date
        ) AS streak_id
    FROM marked
),

streaks AS (
    SELECT
        user_id,
        action,
        streak_id,
        COUNT(*) AS streak_length,
        MIN(action_date) AS start_date,
        MAX(action_date) AS end_date
    FROM grouped
    GROUP BY user_id, action, streak_id
    HAVING COUNT(*) >= 5
),

ranked AS (
    SELECT *,
        ROW_NUMBER() OVER (
            PARTITION BY user_id
            ORDER BY streak_length DESC
        ) AS rn
    FROM streaks
)

SELECT
    user_id,
    action,
    streak_length,
    start_date,
    end_date
FROM ranked
WHERE rn = 1
ORDER BY streak_length DESC, user_id ASC;