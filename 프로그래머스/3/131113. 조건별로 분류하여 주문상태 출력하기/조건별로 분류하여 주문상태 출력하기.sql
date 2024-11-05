-- 코드를 입력하세요
-- 22년 5월 1일까지는 출고완료, 이후는 출고대기, 미정이면 출고미정
-- 주문 ID 기준 오름차순
SELECT ORDER_ID, PRODUCT_ID, DATE_FORMAT(OUT_DATE, '%Y-%m-%d') AS OUT_DATE,
    CASE
        WHEN OUT_DATE IS NULL THEN '출고미정'
        WHEN OUT_DATE <= '2022-05-01' THEN '출고완료'
        ELSE '출고대기'
    END AS '출고여부'
FROM FOOD_ORDER
ORDER BY ORDER_ID