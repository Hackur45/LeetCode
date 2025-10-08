# Write your MySQL query statement below
with temp as(
    select id, student,
        case 
            when id%2 = 0 then id-1
            when id%2 = 1 and id = (select max(id) from seat) then id
            when id%2 = 1 then id+1
        end as rks
    from seat
)
select rks as id, student from temp
order by rks;