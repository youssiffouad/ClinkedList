#include"../EmployeePayload/employeeNode.h"
#include"../Node/node.h"
#include"../linkedlist/linkedlist.h"
#include"stddef.h"
#include"stdio.h"
#include"string.h"
#include"stdlib.h"

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
    printf("created node data 1 \n");
    d.emp.age=g.age;
    printf("created node data 2\n");
    d.emp.name=malloc(strlen(g.name)+1);
    strcpy(d.emp.name,g.name);
    printf("created node data 3\n");
    d.emp.jobtitle=malloc(strlen(g.jobtitle)+1);
    strcpy(d.emp.jobtitle,g.jobtitle);
    free(g.name);
    free(g.jobtitle);
    printf("created node data 4\n");
    Node n= Node_Create(employee,NULL,&d);
    printf("fdjagklnadsklffgf,gklertkoewfdgg  %s \n",d.emp.jobtitle);
    printf("4---printing the node that contains employee data \n");
    Node_print(&n);
    printf("5---creating the  linked list \n");
    LinkedList l=LinkedList_Create();
    printf("6---inserting into the linked list node of emoloyee \n");
    LinkedList_InsertNode(&l,&n);
    printf("7--- printing the linked list \n");
    LinkedList_view(&l);
    printf("8---getting the age of first employee in the list /n");
    uint8_t age = *(uint8_t *)LinkedList_getField(&l,1,EMP_AGE);
    printf("here is the age of employee in index 1 of the linked list %i \n",age);
    free(n.data.emp.jobtitle);
    free(n.data.emp.name);





}
