with ltr as(
    select requester_id as person, count(*) as ltrs
    from RequestAccepted
    group by requester_id
),
rtl as(
    select accepter_id as person,count(*) rtls
    from RequestAccepted
    group by accepter_id
),
combined as(
    (select person , ltrs as total from ltr)
    union all 
    (select person , rtls as total from rtl)
)
select person as id, sum(total) as num
from combined
group by person
order by num desc
limit 1; 