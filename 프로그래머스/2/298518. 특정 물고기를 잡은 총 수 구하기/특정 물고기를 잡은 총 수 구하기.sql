-- 코드를 작성해주세요
# select count(*) as fish_count
# from fish_info
# where fish_type in (select fish_type from fish_name_info
#                    where fish_name in ('BASS', 'SNAPPER'))

select count(*) as fish_count
from fish_info a left join fish_name_info b
on a.fish_type = b.fish_type
where b.fish_name in ('BASS', 'SNAPPER')
