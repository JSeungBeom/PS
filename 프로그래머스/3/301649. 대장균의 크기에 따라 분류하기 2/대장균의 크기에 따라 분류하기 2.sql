SELECT ID, 
(CASE
WHEN PERCENT_RANK() OVER (ORDER BY SIZE_OF_COLONY DESC) * 100 <= 25 THEN 'CRITICAL'
WHEN PERCENT_RANK() OVER (ORDER BY SIZE_OF_COLONY DESC) * 100 <= 50 THEN 'HIGH'
WHEN PERCENT_RANK() OVER (ORDER BY SIZE_OF_COLONY DESC) * 100 <= 75 THEN 'MEDIUM'
ELSE 'LOW'
END) COLONY_NAME
FROM ECOLI_DATA
ORDER BY ID