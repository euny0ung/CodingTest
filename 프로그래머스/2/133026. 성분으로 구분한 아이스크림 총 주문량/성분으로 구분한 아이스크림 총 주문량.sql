-- 코드를 입력하세요
SELECT INGREDIENT_TYPE,SUM(TOTAL_ORDER)
FROM ICECREAM_INFO I LEFT JOIN FIRST_HALF H ON I.FLAVOR = H.FLAVOR
GROUP BY INGREDIENT_TYPE