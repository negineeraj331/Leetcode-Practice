# Write your MySQL query statement below
SELECT email as Email 
FROM Person
Group BY email
HAVING COUNT(email)>1;