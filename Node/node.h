#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include"../EmployeePayload/employeeNode.h"
#include<stdint-gcc.h>
typedef enum{
    smallNo,
    largeNo,
    employee,
} EN_NODE_DataType;

typedef enum{
    NODE_SUCCESS=1,
    NODE_SENT_NULL_PTR=-1,
} EN_NODE_STATE;

typedef union {
    int smallValue;
    int largeValue;
    Employee emp;

} NodeData;

typedef struct{
const EN_NODE_DataType nodetype;
NodeData data;
struct Node * nextptr;
} Node;

Node  Node_Create(EN_NODE_DataType ,Node * ,NodeData );

void Node_Copy(Node *,Node *);

void * Node_GetData(Node *,uint8_t);

EN_NODE_STATE Node_print(Node *);


#endif // NODE_H_INCLUDED
