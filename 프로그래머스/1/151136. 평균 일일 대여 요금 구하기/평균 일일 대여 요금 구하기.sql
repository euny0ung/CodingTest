-- 코드를 입력하세요
SELECT round(avg(daily_fee),0) as AVERAGE_FEE
from CAR_RENTAL_COMPANY_CAR
where car_type = 'SUV'