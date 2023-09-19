/****************************************************************************************
 * Akhror Rakhmatov, arakhmat@ucsc.edu, PA1
*  ListTest.c
*  Test client for List ADT
*  Used TestClient.h from examples
*****************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"List.h"
#include"List.c"

int main(int argc, char* argv[]){
   
   List B = newList();
   List A = newList();
   List D = NULL;
   int i;

   for(i=1; i<=50; i++){
      append(A,i);
      prepend(B,i);
   }

   printList(stdout,A); 
   printf("\n");
   printList(stdout,B); 
   printf("\n");

   for(moveFront(A); index(A)>=0; moveNext(A)){
      printf("%d ", get(A));
   }
   printf("\n");
   for(moveBack(B); index(B)>=0; movePrev(B)){
      printf("%d ", get(B));
   }
   printf("\n");

   D = copyList(A);
   printf("%s\n", equals(B,B)?"true":"false");
   printf("%s\n", equals(B,D)?"true":"false");
   printf("%s\n", equals(D,A)?"true":"false");
   printf("%s\n", equals(B,A)?"true":"false");


   moveFront(A);
   for(i=0; i<3; i++) moveNext(A); // at index 5
   insertBefore(A, -1);            // at index 6
   for(i=0; i<12; i++) moveNext(A); // at index 15
   insertAfter(A, -2);
   for(i=0; i<5; i++) movePrev(A); // at index 10
   delete(A);
   printList(stdout,A);
   printf("\n");
   printf("%d\n", length(A));
   clear(A);
   printf("%d\n", length(A));
   clear(B);

   append(A, 5);
    prepend(A, 7);
    append(A, 2);
    moveBack(A);
    insertAfter(A, 43);
    deleteBack(A);
    delete (A);
    if (back(A) != 5)
      return 1;
    return 0;

   moveFront(B);
   deleteFront(B);
   moveBack(B);
   deleteBack(B);
   moveBack(B);
   movePrev(B);
   movePrev(B);
   delete(B);
   moveBack(B);
   delete(B);
   moveFront(B);
   delete(B);
   moveFront(B);
   moveNext(B);
   delete(B);

   freeList(&A);
   freeList(&B);
   freeList(&D);

   return(0);
}