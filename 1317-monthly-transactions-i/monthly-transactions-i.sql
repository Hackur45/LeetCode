# Write your MySQL query statement below
select 
    date_format(t.trans_date, '%Y-%m') as month,
    t.country as country,
    count(*) as trans_count,
    sum(case when t.state like 'approved' then 1 else 0 end) as approved_count,
    sum(t.amount) as trans_total_amount,
    sum(case when t.state like 'approved' then t.amount else 0 end) as approved_total_amount
    from transactions t
group by date_format(t.trans_date,'%Y-%m'),t.country;