#include "node.h"
#include"stddef.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
Node  Node_Create(EN_NODE_DataType type,Node * nextptrArg,NodeData* dataArg){

    printf("the parameterssssssssssssssssss i got %s \n",dataArg->emp.jobtitle);
    Node n={.nodetype=type,.nextptr=nextptrArg};
    n.data.emp.age=dataArg->emp.age;
    n.data.emp.jobtitle=malloc(strlen(dataArg->emp.jobtitle)+1);
    n.data.emp.name=malloc(strlen(dataArg->emp.name)+1);
    strcpy(n.data.emp.name,dataArg->emp.name);
    strcpy(n.data.emp.jobtitle,dataArg->emp.jobtitle);
    printf("the trial name %s \n the trial job title %s \n",n.data.emp.name,n.data.emp.jobtitle);
    return n;
}

EN_NODE_STATE Node_print(Node * n){
    if(n==NULL){
        return NODE_SENT_NULL_PTR;
    }
    if(n->nodetype==smallNo){
        printf("the node is of type smallno and equals %i \n ", n->data.smallValue);
    }
    else if(n->nodetype==employee){
        printf("the node is of type employee and here is the data \n");
        Employee_print(&(n->data.emp));
    }

    return NODE_SUCCESS;
}


/*void Node_Copy(Node *original,Node *copied){
    copied->number=original->number;
    copied->nextptr=original->nextptr;
}*/

void * Node_GetData(Node * n,uint8_t choice){
    if(n->nodetype==smallNo){
        return &(n->data.smallValue);
    }

    if(n->nodetype==employee){

        switch(choice){
        case EMP_NAME:{
            static char* ename;
            ename=Employee_getName(&(n->data.emp));
            return ename;
        }


        case EMP_AGE:{
            static uint8_t age;
            age=Employee_getage(&(n->data.emp));
            return & age;
        }


        case EMP_JOBTITLE:{
             static char * ejob;
            ejob=Employee_jobTitle(&(n->data.emp));
            return ejob;
        }


        default:
            return NULL;
        }
    }
    return NULL;
}
