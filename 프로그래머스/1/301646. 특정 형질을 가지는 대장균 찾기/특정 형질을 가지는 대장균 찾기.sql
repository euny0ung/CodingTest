-- 1이나 3을 보유하려면 100, 001, 101이어야함.ㅡ 101과 OR 연산했을 때 101, 2를 보유하지 않으려면 10과 AND 연산했을 때 FALSE
select count(ID) AS COUNT
FROM ECOLI_DATA AS ED
WHERE GENOTYPE & 5 > 0 AND (NOT GENOTYPE & 2)