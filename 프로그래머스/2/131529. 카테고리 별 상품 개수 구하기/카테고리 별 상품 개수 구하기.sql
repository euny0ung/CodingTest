-- 코드를 입력하세요
-- PRODUCT_CODE 앞 두자리 기준으로 상품 묶어서 출력
-- 카테고리 코드 기준 오름차순
SELECT SUBSTRING(PRODUCT_CODE, 1,2) AS CATEGORY, COUNT(*)
FROM PRODUCT
GROUP BY CATEGORY
ORDER BY CATEGORY