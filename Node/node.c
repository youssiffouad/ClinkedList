#include "node.h"
#include"stddef.h"
Node  Node_Create(EN_NODE_DataType type,Node * nextptrArg,NodeData dataArg){

    Node n={.nodetype=type,.nextptr=nextptrArg,.data=dataArg};
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

}
