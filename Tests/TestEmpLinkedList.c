#include"../EmployeePayload/employeeNode.h"
#include"../Node/node.h"
#include"../linkedlist/linkedlist.h"
#include"stddef.h"

void TEST_EMP_LINKEDLIST(){
    printf("1---creating the employee data \n");

    Employee g =Employee_create("youssif",45,"junior SWengineer");
    printf("2---printing the employee data \n");
    printf("here is the employee data : \n name : %s \n age : %i \n jobtitle : %s \n ",g.name,g.age,g.jobtitle);
    printf("here is the emp name : %s \n",Employee_getName(&g));
    printf("here is the emp age : %i \n",Employee_getage(&g));
    printf("here is the emp job title : %s \n",Employee_jobTitle(&g));
    printf("3---creating the node that contains employee data \n");
    NodeData d;
    d.emp=g;
    Node n= Node_Create(employee,NULL,d);
    printf("4---printing the node that contains employee data \n");
    Node_print(&n);
    printf("5---creating the  linked list \n");
    /*LinkedList l=LinkedList_Create();
    printf("6---inserting into the linked list node of emoloyee \n");
    LinkedList_InsertNode(&l,&n);
    printf("7--- printing the linked list \n");
    LinkedList_view(&l);
    printf("8---getting the job of first employee in the list /n");
    char * name = (char *)LinkedList_getField(&l,1,EMP_NAME);
    printf("here is the name of employee in index 1 of the linked list %s \n",name);*/





}
