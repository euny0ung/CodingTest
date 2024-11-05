-- 코드를 입력하세요
-- 동물 아이디, 이름, 중성화 여부를 아이디 순으로 조회
-- 중성화 되어있다면 O, 아니면 X로 표시 (if문 사용?)
SELECT ANIMAL_ID, NAME, IF(SEX_UPON_INTAKE LIKE "Spayed%" OR SEX_UPON_INTAKE LIKE "Neutered%", "O", "X") AS 중성화
FROM ANIMAL_INS
ORDER BY ANIMAL_ID