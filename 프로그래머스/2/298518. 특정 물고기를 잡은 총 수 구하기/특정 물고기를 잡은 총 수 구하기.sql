-- 코드를 작성해주세요
# select count(*) as fish_count
# from fish_info
# where fish_type in (select fish_type from fish_name_info
#                    where fish_type in ('BASS', 'SNAPPER'))

SELECT count(*) as fish_count from fish_info
WHERE fish_type in (SELECT fish_type from fish_name_info
WHERE fish_name in ('bass','snapper'))