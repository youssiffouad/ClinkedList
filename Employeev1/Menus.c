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


    uint8_t choice;
    printf("--------------WELCOME TO THE EMOLYEE PROGRAM---------------- \n");
    printf("please select from the options below \n");
    printf("1--->insert new employee \n");
    printf("2--->view certain employee by index\n");
    printf("3--->delete  employee \n");
    printf("4--->modify data of certain  employee by index \n");
    printf("5--->display all existing employees \n");
    scanf("%i",&choice);
    switch (choice){
        case 1:{
          NodeData d= Form_NewEmployee();
          printf("i survived \n");
          Node n=Node_Create(employee,NULL,&d);
          printf("i survived *2 \n");
          LinkedList_InsertNode(&l,&n);
          printf("i survived *3 \n");
          break;
        }
        case 2 :{
            uint8_t index=INPUT_GetIndex();
            LinkedList_viewItemByIndex( &l,index);
            break;
        }
        case 3 :{
            uint8_t index=INPUT_GetIndex();
            LinkedList_deleteItemByIndex(&l,index);
            break;
        }
        case 4 :{
           uint8_t index= INPUT_GetIndex();
           uint8_t field=INPUT_FieldName();
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

uint8_t  INPUT_GetIndex(){
    uint8_t index;
    printf("please enter the index \n");
    scanf("%i",&index);
    return index;

}

uint8_t INPUT_FieldName(){
    uint8_t selection;
    printf("please select the field to be modified \n");
    printf("   1--edit name \n");
    printf("   2--edit age \n");
    printf("   3--edit job title \n");
    scanf("%i",&selection);
    return selection;
}
























