# Write your MySQL query statement below

select id  as id, if(id  in (select p_id from Tree) ,if(id = (select id from Tree where p_id is null), "Root", "Inner") , if(id = (select id from Tree where p_id is null), "Root", "Leaf")) as type
from Tree;
