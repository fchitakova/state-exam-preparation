SELECT * FROM MOVIEEXEC;

SELECT DISTINCT NAME 
FROM MOVIEEXEC
WHERE NETWORTH = (SELECT MIN(NETWORTH) FROM MOVIEEXEC);