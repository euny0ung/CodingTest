-- 코드를 입력하세요
-- SELECT count(*) as USERS
-- from user_info
-- where age between 20 and 29 and extract(year from joined) = 2021

select count(*) as users
from user_info
where age between 20 and 29 and to_char(joined, 'YYYY') = 2021

-- select count(*) as users
-- from user_info
-- where age between 20 and 29 and substr(to_char(joined, 'YYYY-MM-DD'), 0,4)=2021