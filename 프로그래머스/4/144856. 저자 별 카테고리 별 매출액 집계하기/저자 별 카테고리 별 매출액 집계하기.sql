
SELECT AUTHOR_ID, AUTHOR_NAME, CATEGORY, SUM(SALES * PRICE) AS TOTAL_SALES
FROM BOOK A
JOIN AUTHOR B
USING(AUTHOR_ID)
JOIN
(SELECT BOOK_ID, SUM(SALES) AS SALES
FROM BOOK_SALES
WHERE DATE_FORMAT(SALES_DATE, "%Y-%m") = '2022-01'
GROUP BY BOOK_ID) C
USING (BOOK_ID)
GROUP BY AUTHOR_ID, CATEGORY
ORDER BY AUTHOR_ID, CATEGORY DESC
