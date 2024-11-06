with cte as (
	-- 개발자 및 스킬코드 조인 
    select ID, EMAIL, group_concat(NAME,'|', CATEGORY separator '|') as SKILL
    from DEVELOPERS
    inner join SKILLCODES
    	-- 코드는 비트로 구성되어, 해당 스킬을 갖고 있다면 비트 연산으로 1을 반환
        on SKILL_CODE & CODE
    group by ID, EMAIL
)
-- 스킬코드에 따라 등급 분류
select *
from (
    select 
        case when (SKILL like '%Front End%' and SKILL like '%Python%')
             then 'A'
             when (SKILL like '%C#%')
             then 'B'
             when (SKILL like '%Front End%')
             then 'C'
        end as GRADE
        , ID
        , EMAIL
    from cte
) as subquery
-- 등급이 포함되지 않는 개발자 제외
where GRADE is not NULL
order by GRADE, ID