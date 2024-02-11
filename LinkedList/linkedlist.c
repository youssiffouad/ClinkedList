#include "linkedlist.h"
#include"stddef.h"
#include"stdio.h"



LinkedList LinkedList_Create(){
LinkedList l={.first=NULL,.last=NULL,.noOfNodes=0};
return l;
}



EN_LINKEDLIST_STATE LinkedList_InsertNode(LinkedList *l,Node * newNode){
    if(l ==NULL){
        return LINKEDLIST_SENT_NULL_POINTER;
    }
     if(newNode ==NULL){
        return LINKEDLIST_SENT_NULL_PTRToNODE;
    }
if(l->first==NULL){
    l->first=newNode;
    l->last=newNode;
    printf("here is the first of the linked list %p \n",l->first);
  }
else{
 l->last->nextptr=newNode;
 l->last=newNode;
}

newNode->nextptr=NULL;
l->noOfNodes++;
return LINKEDLIST_SUCCESS;
}

EN_LINKEDLIST_STATE LinkedList_view(LinkedList *l){
     if(l ==NULL){
        return LINKEDLIST_SENT_NULL_POINTER;
    }
    printf("here is the first of the linked list %p \n",l->first);
    Node * iterator=l->first;
    uint8_t counter=0;
    while(iterator !=NULL){
        Node_print(iterator);
        iterator=iterator->nextptr;
        counter++;
    }
    return LINKEDLIST_SUCCESS;
}

uint8_t LinkedList_getNoOfNodes(LinkedList * l){
return l->noOfNodes;
}


EN_LINKEDLIST_STATE LinkedList_updateItemByIndex(LinkedList * L,uint8_t index ,Node *newNode){
    if(L ==NULL){
        return LINKEDLIST_SENT_NULL_POINTER;
    }
    if(newNode ==NULL){
        return LINKEDLIST_SENT_NULL_PTRToNODE;
    }
    if(index>L->noOfNodes){
        return LINKEDLIST_INDX_GT_SIZE;
    }
    if(index== 1){
        newNode->nextptr=L->first->nextptr;
        L->first=newNode;
    }

    else{
        Node * iterator=L->first;
        for(uint8_t i=1;i<index-1;i++){
            iterator=iterator->nextptr;
        }
        Node * deletedNode=iterator->nextptr;
        newNode->nextptr=deletedNode->nextptr;
        iterator->nextptr=newNode;
        if(index==L->noOfNodes){
            L->last=newNode;
        }
    }
    return LINKEDLIST_SUCCESS;

}



EN_LINKEDLIST_STATE LinkedList_deleteItemByIndex(LinkedList * L,uint8_t index){
    if(L==NULL){
        return LINKEDLIST_SENT_NULL_POINTER;
    }
    if(L->first==NULL){
        printf("the list is  empty  \n");
        return LINKEDLIST_EMPTY;
    }
    if(index>L->noOfNodes){
        printf("the  index sent is larger than size \n");
        return LINKEDLIST_INDX_GT_SIZE;
    }

         Node* iterator =L->first;
         Node* iteratortrail=iterator;
         if(index==1){
            iterator=iterator->nextptr;
            iteratortrail=iteratortrail->nextptr;
            L->first=iterator;
            }
         else{

                iterator=iterator->nextptr;

            for(uint8_t i=1;i<index-1;i++){
                iterator=iterator->nextptr;
                iteratortrail=iteratortrail->nextptr;
            }
            iteratortrail->nextptr=iterator->nextptr;
        }
        if(index== L->noOfNodes){
            L->last=iteratortrail;
        }
        L->noOfNodes--;
        return LINKEDLIST_SUCCESS;

}

void * LinkedList_getField(LinkedList * l,uint8_t index,uint8_t choice){
    if(l==NULL){
        printf("the sent linked list is pointing to null \n");
        return NULL;
    }
    if(index >l->noOfNodes){
        printf("the sent index is larger than the size of the  linked list \n");
        return NULL;
    }
    Node * iterator=l->first;
    uint8_t counter=1;
    while(counter != index){
        iterator=iterator->nextptr;
    }


    return Node_GetData(iterator,choice);
}















