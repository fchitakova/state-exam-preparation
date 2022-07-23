-- Подусловие 4.1 1)

-- SELECT STUDIONAME
-- FROM MOVIE
-- WHERE INCOLOR = 'Y'
-- INTERSECT
-- SELECT STUDIONAME
-- FROM MOVIE
-- WHERE LENGTH IS NULL;


-- Подусловие 4.1.) Посочете заявката, която за всяка актриса извежда името и броят на чернобелите филми, в които е участвала. Ако не -> да извежда 0 срещу името на актрисата

-- A) ГРЕШНО -> INCOLOR в HAVING не се съдържа в агрегиращата функция, нито в group by!!!
-- SELECT NAME, COUNT(DISTINCT TITLE)
-- FROM MOVIE 
-- RIGHT JOIN STARSIN ON TITLE = MOVIE.TITLE AND YEAR = MOVIEYEAR
-- RIGHT JOIN MOVIESTAR ON NAME = STARNAME
-- WHERE GENDER = 'F'
-- GROUP BY NAME
-- HAVING INCOLOR = 'N';

-- Б)  ВЯРНО
-- SELECT NAME, COUNT(TITLE)
-- FROM MOVIESTAR LEFT JOIN STARSIN ON NAME = STARNAME
-- LEFT JOIN MOVIE ON MOVIETITLE = TITLE  AND MOVIEYEAR = YEAR AND INCOLOR = 'N'
-- WHERE GENDER = 'F'
-- GROUP BY NAME;

