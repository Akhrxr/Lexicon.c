/****************************************************************************************
* Akhror Rakhmatov, arakhmat@ucsc.edu, PA1
*  Lex.c
*  Actual usage of the list adt
*****************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"List.h"

int main(int argc, char **argv) {
    int* unsorted;
    unsigned lines = 0;
    FILE *in, *out;
    char token;
    if (argc != 3) {
        fprintf( stderr, "Incorrect number of command line arguments, please include a file in and file out only\n" );
    }
    in = fopen(argv[1], "r");
    if( in==NULL ){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
    }
    out = fopen(argv[2], "w");
    if( out==NULL ){
      printf("Unable to open file %s for writing\n", argv[2]);
      exit(1);
    }
    for (token = getc(in); token != EOF; token = getc(in)) {
        if (token == '\n') { // Increment count if this character is newline
            lines++;
        }
    }
    fclose(in);
    unsorted = (int*)malloc(lines * sizeof(int));
    List sorted = newList();
    int count = 0;
    for (token = getc(in); token != EOF; token = getc(in)) {
      if (token == '\n') { // Increment count if this character is newline
        unsorted[count] = token;
      }
    }
    prepend(sorted, 0);
    for (unsigned i = 1; i <= lines; ++i) {
      moveFront(sorted);
      while (strcmp(unsorted[index(sorted)], unsorted[i]) < 0 && index(sorted) < length(sorted)) {
        moveNext(sorted);
      }
      if (strcmp(unsorted[index(sorted)], unsorted[i]) < 0) {
        insertAfter(sorted, i);
      }
      else {
        insertBefore(sorted, i);
      }
    }
    moveFront(sorted);
    while (index(sorted) < length(sorted)) {
      fprintf(out, "%d, ", get(sorted));
    }
    fclose(out);
}