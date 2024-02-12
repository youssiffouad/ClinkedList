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
    printf("\n\n\n 9---creating and adding 10 more nodes \n");


    Employee g2 =Employee_create("omar",24,"senior SWengineer");
    NodeData d2;
    d2.emp.age=g2.age;
    d2.emp.name=malloc(strlen(g2.name)+1);
    strcpy(d2.emp.name,g2.name);
    d2.emp.jobtitle=malloc(strlen(g2.jobtitle)+1);
    strcpy(d2.emp.jobtitle,g2.jobtitle);
    free(g2.name);
    free(g2.jobtitle);
    Node n2= Node_Create(employee,NULL,&d2);
    LinkedList_InsertNode(&l,&n2);

    Employee g3 =Employee_create("safa",25,"embedded developer");
    NodeData d3;
    d3.emp.age=g3.age;
    d3.emp.name=malloc(strlen(g3.name)+1);
    strcpy(d3.emp.name,g3.name);
    d3.emp.jobtitle=malloc(strlen(g3.jobtitle)+1);
    strcpy(d3.emp.jobtitle,g3.jobtitle);
    free(g3.name);
    free(g3.jobtitle);
    Node n3= Node_Create(employee,NULL,&d3);
    LinkedList_InsertNode(&l,&n3);

    Employee g4 =Employee_create("Mahmoud",30,"senior system engineer");
    NodeData d4;
    d4.emp.age=g4.age;
    d4.emp.name=malloc(strlen(g4.name)+1);
    strcpy(d4.emp.name,g4.name);
    d4.emp.jobtitle=malloc(strlen(g4.jobtitle)+1);
    strcpy(d4.emp.jobtitle,g4.jobtitle);
    free(g4.name);
    free(g4.jobtitle);
    Node n4= Node_Create(employee,NULL,&d4);
    LinkedList_InsertNode(&l,&n4);





    free(n.data.emp.jobtitle);
    free(n.data.emp.name);





}
