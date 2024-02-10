#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include"../Node/node.h"


typedef struct{
Node * first ;
Node * last;
uint8_t noOfNodes;
}LinkedList;

typedef enum{
    LINKEDLIST_EMPTY =-1,
    LINKEDLIST_SENT_NULL_POINTER =-2,
    LINKEDLIST_SENT_NULL_PTRToNODE=-3,
    LINKEDLIST_INDX_GT_SIZE=-4,
    LINKEDLIST_SUCCESS=1,

}EN_LINKEDLIST_STATE;


uint8_t LinkedList_getNoOfNodes(LinkedList *);

EN_LINKEDLIST_STATE LinkedList_InsertNode(LinkedList *,Node *);

LinkedList LinkedList_Create();

EN_LINKEDLIST_STATE LinkedList_view(LinkedList *);

EN_LINKEDLIST_STATE LinkedList_updateItemByIndex(LinkedList *,uint8_t ,Node *);

EN_LINKEDLIST_STATE LinkedList_deleteItemByIndex(LinkedList *,uint8_t);


//the 3rd argument is for field choice (send it with any no if the node is just a number)
void * LinkedList_getField(LinkedList *,uint8_t ,uint8_t);




#endif // LINKEDLIST_H_INCLUDED
