//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int c=5;
    struct node a,b,*head ;
    a.value = c;
    a.next=&b;
    head=&a;
    b.value=head->value+3;

    //ex1
    printf("ex.1\n" );
    struct node x;
    b.next=&x;
    b.next->value=11;
    /*
    x.value=11;
    a.next->next->value=11; == [(*(*a.next).next)->value=11;] 
    head->next->next->value=11;
    */
    x.next=NULL;

    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
    printf("%d\n", head ->next->next->value );

/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */
    
    //ex2
    printf("ex.2\n" );
    struct node f;
    f.next=&a;
    head=&f;
    f.value=2;

    printf("%d\n", head ->value );
    printf("%d\n", head ->next->value );
    printf("%d\n", head ->next->next->value );
    printf("%d\n", head ->next->next->next->value );
/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
*/
    typedef struct node* NodePtr;
    NodePtr tmp=head; //add temp value to faciliate
        
    //ex3 เอาtmpวิ่งชี้ไม่ต้องเขียนซ้ำบ่อยๆ
    printf("ex.3\n" );
    int i,n=4;
    for(i=0; i<n; i++)
    {
    printf("%3d", tmp->value);
    tmp= tmp->next;
    }
    printf("\n");
    /*  Exercise III Use loop to print everything
        int i,n=5;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
          // What is missing??? tmp= tmp+1
        }
    */
    //ex.4
    printf("ex.4\n");
    tmp=head;  //ดึงtmpกลับมาใช้
    while(tmp!=NULL)
    {
        printf("%3d", tmp->value);
        tmp=tmp->next;
    }
    printf("\n");

   /*  Exercise IV change to while loop!! (you can use NULL to help)
       
         while(){
            printf("%3d", tmp->value);
           // What is missing???
        }
    */

    //ex.5
    printf("ex.5\n");
    head = (NodePtr) malloc(sizeof(struct node));
    tmp=head;
    for(i=0; i<3; i++)
    //สร้างอีก 3 โหนดมาต่อท้าย
    //ใส่ค่า i+3 ในvalue
    {
    tmp->value=i+3;
    tmp->next = (NodePtr) malloc(sizeof(struct node));    
    tmp= tmp->next;
    }
    tmp->value=i+3;
    tmp->next=NULL;

    for(tmp=head; tmp!=NULL; tmp=tmp->next)
    {
        printf("%3d", tmp->value);
    }
    printf("\n");

/*
typedef struct node* NodePtr;
    typedef struct node Node;
//struct node *head,*temp;
    NodePtr head, temp;
//เชื่อมmallocได้2วิธี
*/

 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
          
     */

    //ex.6
    printf("ex.6\n");
    
    for(tmp=head; tmp!=NULL; tmp=head)
    {//ขยับhead
        head=head->next;
        //printf("%3d\n", tmp->value);
        printf("freeing %d\n", tmp->value);
        free(tmp);
    }


    /*  Exercise VI Free all node !!
         //use a loop to help
          
     */
    
    return 0;
}
