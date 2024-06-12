-- 코드를 입력하세요
-- SELECT product_id, product_name, product_cd, category, price
-- from food_product
-- where price = (
--     select max(price)
--     from food_product
-- )

select product_id, product_name, product_cd, category, price
from (select * from food_product order by price desc)
where rownum=1