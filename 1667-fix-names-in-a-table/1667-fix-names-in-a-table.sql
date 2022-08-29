# Write your MySQL query statement below

# update Users set name=SUBSTRING(name, 1, 1)+SUBSTRING(name, 2, Length(name)-1);


Select user_id,  Concat(UPPER(SUBSTRING(name, 1, 1)) ,Lower(SUBSTRING(name, 2, Length(name)-1)) )as "name"
from Users
order by user_id  ;
