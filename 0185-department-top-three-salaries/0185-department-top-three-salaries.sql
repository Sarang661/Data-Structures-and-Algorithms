# Write your MySQL query statement below
select D.Name as Department, E.Name as Employee, E.Salary as Salary 
  from Employee E, Department D
   where (select count(distinct(Salary)) from Employee 
           where DepartmentId = E.DepartmentId and Salary > E.Salary) in (0, 1, 2)
         and 
           E.DepartmentId = D.Id 
         order by E.DepartmentId, E.Salary DESC;