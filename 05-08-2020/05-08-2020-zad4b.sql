SELECT DISTINCT m.name AS NAME, YEAR(m.BIRTHDATE) AS BIRTH_YEAR, COUNT(studioname) AS STUDIOS
FROM MOVIESTAR m
LEFT JOIN STARSIN on m.name = STARNAME
LEFT JOIN MOVIE on title = movietitle
WHERE  (SELECT DISTINCT COUNT(*) 
        FROM STARSIN             
        JOIN MOVIE ON movietitle = title
        WHERE STARNAME = m.NAME) <= 6 AND 
        m.GENDER = 'F'
GROUP BY m.NAME, m.BIRTHDATE;






