#include"Menus.h"
#include"stdint-gcc.h"
#include"stdio.h"
#include"../Node/node.h"
#include"../LinkedList/linkedlist.h"
#include"stdlib.h"
#include"string.h"
void Menu_main(){
       LinkedList l= LinkedList_Create();
while(1){
//printf("\n I AM IN THE BEGININNG OF THE FUNCTION AND HERE IS THE ADDRESS OF THE FIRST NODE________>>> %p \n",l.first);
//Node * reserve=l.first;
//printf("\n I AM IN THE BEGININNG OF THE FUNCTION AND HERE IS THE ADDRESS OF THE FIRST NODE________>>> %p \n",l.first);

    int choice;
    printf("--------------WELCOME TO THE EMOLYEE PROGRAM---------------- \n");
    printf("please select from the options below \n");
    printf("1--->insert new employee \n");
    printf("2--->view certain employee by index\n");
    printf("3--->delete  employee \n");
    printf("4--->modify data of certain  employee by index \n");
    printf("5--->display all existing employees \n");
    fflush(stdin);
    //printf("\n I AM IN THE BEGININNG OF THE FUNCTION AND HERE IS THE ADDRESS OF THE FIRST NODE________>>> %p \n",l.first);
    scanf("%i",&choice);

    //l.first=reserve;
    //printf("\n I AM JUST AFTER THE BEGIN OF THE FUNCTION AND HERE IS THE ADDRESS OF THE FIRST NODE________>>> %p  %p\n",l.first,reserve);
    switch (choice){
        case 1:{
           //printf("\n I AM AFTER THE BEGIN OF THE FUNCTION AND HERE IS THE ADDRESS OF THE FIRST NODE________>>> %p \n",l.first);
           NodeData d= Form_NewEmployee();
          // printf("\n I AM BEFORE THE MIDDLE OF THE FUNCTION AND HERE IS THE ADDRESS OF THE FIRST NODE________>>> %p \n",l.first);
          Node* n=Node_CreateDynamic(employee,NULL,&d);
   // printf("\n I AM IN THE MIDDLE OF THE FUNCTION AND HERE IS THE ADDRESS OF THE FIRST NODE________>>> %p \n",l.first);
          LinkedList_InsertNode(&l,n);
          break;
        }
        case 2 :{

            int index=INPUT_GetIndex();
            printf("before the call of the function \n");
            printf("here is the response code %i /n",LinkedList_viewItemByIndex( &l,index));
            break;
        }
        case 3 :{
            int index=INPUT_GetIndex();
            LinkedList_deleteItemByIndex(&l,index);
            break;
        }
        case 4 :{
           int index= INPUT_GetIndex();
           int field=INPUT_FieldName();
           fflush(stdin);
           switch (field){
               case 2:{
                   uint8_t age;
                   printf("please enter age \n");
                   scanf("%i",age);
                   LinkedList_updateItemByIndex(&l,index,field,age,NULL);
                   break;
               }
                case 1:
                case 3:{
                   char word[20];
                   printf("please enter word \n");
                   fgets(word,20,stdin);
                   LinkedList_updateItemByIndex(&l,index,field,0,word);
                   break;
               }
                default:
                    printf("invalid choice \n");
                    break;
           }
        }

        case 5:{
            LinkedList_view(&l);
            break;
        }
        default:{
            printf("invalid choice \n");
            break;
        }

    }


}

}

NodeData Form_NewEmployee(){
    char name[20];
    char jobtitle[20];
    int age ;
    printf("please enter the employee name \n");
    fflush(stdin);
    fgets(name,sizeof(name),stdin);
    printf("please enter the employee age \n");
    fflush(stdin);
    scanf("%i",&age);
    printf("please enter the employee job title \n");
    fflush(stdin);
    fgets(jobtitle,sizeof(jobtitle),stdin);
    NodeData d;
    d.emp.age=age;
    d.emp.jobtitle= malloc(strlen(jobtitle)+1);
    d.emp.name=malloc(strlen(name)+1);
    strcpy(d.emp.name,name);
    strcpy(d.emp.jobtitle,jobtitle);
    return d;
}

int  INPUT_GetIndex(){
    int index;
    printf("please enter the index \n");
    fflush(stdin);
    scanf("%i",&index);
    printf("after the scanf \n");
    return index;

}

int INPUT_FieldName(){
    int selection;
    printf("please select the field to be modified \n");
    printf("   1--edit name \n");
    printf("   2--edit age \n");
    printf("   3--edit job title \n");
    scanf("%i",&selection);
    return selection;
}
























