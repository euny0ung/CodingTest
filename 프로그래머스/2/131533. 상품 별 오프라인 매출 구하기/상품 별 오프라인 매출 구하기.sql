-- 코드를 입력하세요
-- 상품ID, 상품코드, 판매가
-- 상품판매ID, 상품ID, 판매량, 판매일
-- 상품 코드별 매출액(판매가*판매량) 합계 출력, 매출액 기준 내림차순 -> 상품코드 기준 오름차순
SELECT PRODUCT_CODE, SUM(P.PRICE*OS.SALES_AMOUNT) AS SALES
FROM PRODUCT AS P JOIN OFFLINE_SALE AS OS
ON P.PRODUCT_ID = OS.PRODUCT_ID
GROUP BY P.PRODUCT_CODE
ORDER BY SALES DESC, P.PRODUCT_CODE ASC
