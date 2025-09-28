# Write your MySQL query statement below
with firstlogin as(
    select player_id as id, min(event_date) as fl
    from activity
    group by player_id
)
select round(count(distinct a.player_id)/count(distinct b.id),2) as fraction
from firstlogin b left join activity a
on a.player_id = b.id and DATEDIFF(a.event_date, b.fl) = 1;