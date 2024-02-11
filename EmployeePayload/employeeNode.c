#include"employeeNode.h"
#include"../Node/node.h"
#include"string.h"
#include"stdio.h"
#include"stdlib.h"
Employee Employee_create(char* argname, uint8_t argage,char* argjobtitle){
    Employee e;
    e.name = malloc(strlen(argname) + 1);
    e.age=argage;
    strcpy(e.name,argname);
    e.jobtitle=malloc(strlen(argjobtitle)+1);
    strcpy(e.jobtitle,argjobtitle);

    return e;
}

void Employee_print(Employee *p){
    printf("here is the employee data: \n ");
    printf("the employee name : %s \n",p->name);
    printf("the employee age : %i \n",p->age);
    printf("the employee job title : %s \n",p->jobtitle);

}

char * Employee_getName(Employee *e){
    printf("from inside hte fn her is the name %s \n",e->name);

    return e->name;
}


uint8_t Employee_getage(Employee *e){
    return e->age;
}

char *Employee_jobTitle(Employee *e){
    return e->jobtitle;
}
