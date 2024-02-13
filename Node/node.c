#include "node.h"
#include"stddef.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
Node  Node_Create(EN_NODE_DataType type,Node * nextptrArg,NodeData* dataArg){

//if type == employee
    Node n={.nodetype=type,.nextptr=nextptrArg};
    n.data.emp.age=dataArg->emp.age;
    n.data.emp.jobtitle=malloc(strlen(dataArg->emp.jobtitle)+1);
    n.data.emp.name=malloc(strlen(dataArg->emp.name)+1);
    strcpy(n.data.emp.name,dataArg->emp.name);
    strcpy(n.data.emp.jobtitle,dataArg->emp.jobtitle);

    return n;
}

EN_NODE_STATE Node_CreateFromUser(Node *n){
    if(n==NULL){
        return NODE_SENT_NULL_PTR;
    }
    //if type == employee

    n->nextptr=NULL;
    fflush(stdin);
    printf("enter employee name \n");
    n->data.emp.name=malloc(15);
    gets(n->data.emp.name);
    printf("please enter employee age \n");
    scanf("%i",&(n->data.emp.age));
    fflush(stdin);
    printf("please enter employee job title \n ");
    n->data.emp.jobtitle=malloc(15);
    gets(n->data.emp.jobtitle);
    printf(" I FINISHEDDDDDDD \n");
    return NODE_SUCCESS;
}
Node * Node_CreateDynamic(EN_NODE_DataType Argtype,Node *ArgNextPtr ,NodeData* dataArg){

    Node * dynamicNode=malloc(sizeof(Node));
    dynamicNode->nodetype=Argtype;
    dynamicNode->nextptr=ArgNextPtr;
    dynamicNode->data.emp.age=dataArg->emp.age;
     printf("i arrived here 1 \n");
    dynamicNode->data.emp.jobtitle=malloc(strlen(dataArg->emp.jobtitle)+1);
    dynamicNode->data.emp.name=malloc(strlen(dataArg->emp.name)+1);
    strcpy(dynamicNode->data.emp.name,dataArg->emp.name);
      printf("i arrived here 2 \n");
      printf("here is the employee name %s \n ",dynamicNode->data.emp.name);
    strcpy(dynamicNode->data.emp.jobtitle,dataArg->emp.jobtitle);
      printf("i arrived here 3 \n");

    return dynamicNode;
}

EN_NODE_STATE Node_print(Node * n){
    printf("i cam here \n");
    printf("%p",n);
    if(n==NULL){
        printf("sent null pointer to node \n");
        return NODE_SENT_NULL_PTR;

    }
    if(n->nodetype==smallNo){
        printf("i cam here small no \n");
        printf("the node is of type smallno and equals %i \n ", n->data.smallValue);
    }
    else if(n->nodetype==employee){
        printf("i cam here employee \n");
        printf("the node is of type employee and here is the data \n");
        Employee_print(&(n->data.emp));
    }
    else{

        printf("other case taaaaaaaaaaannnnnnnnya \n");
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

EN_NODE_STATE Node_ModifyData(Node * n,uint8_t choice,uint8_t Argnumber, char * Argstring){
    if(n==NULL){
        return NODE_SENT_NULL_PTR;
    }
    if(n->nodetype==smallNo){
       //call modify fn of small NO (ÈÏá ãÇ ÊßÊÈåÇ åäÇ æ ÊÚãá ÒÍãÉ)

    }

    if(n->nodetype==employee){

        switch(choice){
        case EMP_NAME:{
           strcpy(n->data.emp.name,Argstring);
           break;
        }


        case EMP_AGE:{
           n->data.emp.age=Argnumber;
           break;
        }


        case EMP_JOBTITLE:{
            n->data.emp.jobtitle=Argstring;
            break;
        }


        default:
            break;
        }
    }
    return NODE_SUCCESS;
}





























