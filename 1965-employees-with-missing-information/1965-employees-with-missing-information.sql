# Write your MySQL query statement below

select employee_id
from Employees
where employee_id not in(
   
    select employee_id
    from salaries
    
)
Union

select employee_id
from salaries
where employee_id not in(
   
    select employee_id
    from Employees
    
)

order by employee_id ;




