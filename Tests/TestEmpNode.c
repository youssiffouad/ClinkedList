#include"../EmployeePayload/employeeNode.h"
#include"stddef.h"
#include"../Node/node.h"
#include"stdio.h"


void Test_Emp_Node_Script(){
    printf("i will create employee data \n ");
    Employee e=Employee_create("youssif",25,"SW engineer");
    NodeData d;
    d.emp=e;
    printf("here is the employee data : \n name : %s \n age : %i \n jobtitle : %s \n ",e.name,e.age,e.jobtitle);
    printf("i will create a node of employee \n");
    Node n =Node_Create(employee,NULL,&d);

    printf("i will print the node \n");
    printf("the status of node printing is %i \n,", Node_print(&n));
}


