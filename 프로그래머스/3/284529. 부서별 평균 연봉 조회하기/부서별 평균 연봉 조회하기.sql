-- 코드를 작성해주세요
SELECT DEPT_ID, DEPT_NAME_EN, ROUND(AVG(SAL), 0) AS AVG_SAL
FROM HR_EMPLOYEES
JOIN HR_DEPARTMENT
USING (DEPT_ID)
GROUP BY DEPT_ID
ORDER BY AVG_SAL DESC