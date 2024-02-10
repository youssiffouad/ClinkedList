#ifndef EMPLOYEENODE_H_INCLUDED
#define EMPLOYEENODE_H_INCLUDED
#include"stdint-gcc.h"
typedef struct{
    char *name;
    uint8_t age;
    char * jobtitle;
} Employee;

typedef enum{
    EMP_NAME,
    EMP_AGE,
    EMP_JOBTITLE,
} EN_EMPLOYEE_ATTRIBUTES;

Employee Employee_create(char*, uint8_t,char*);

Employee Employee_print(Employee *);

char * Employee_getName(Employee *);

uint8_t Employee_getage(Employee *);

char *Employee_jobTitle(Employee *);
#endif // EMPLOYEENODE_H_INCLUDED
