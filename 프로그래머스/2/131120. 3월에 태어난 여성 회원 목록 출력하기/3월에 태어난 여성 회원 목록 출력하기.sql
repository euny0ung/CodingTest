-- 코드를 입력하세요
SELECT MEMBER_ID, MEMBER_NAME, GENDER, TO_CHAR(DATE_OF_BIRTH, 'YYYY-MM-DD') as DATE_OF_BIRTH
from member_profile
where gender = 'W' and tlno is NOT NULL and substr(TO_CHAR(date_of_birth, 'YYYY-MM-DD'), 6, 2) = '03'
order by member_id