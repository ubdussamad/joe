#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/cs.h"
//#include <pcre2.h> //Don't include it without proper declarations


int main ( void ) {
  int will;
  int  val;
  node * ptr = NULL;
  while (1) {
    printf("hit: ");
    scanf("%d" , &will );
    if ( will == 1) {
      printf("enter: ");
      scanf("%d" , &val );
      push( val , &ptr );
    }
    else if (will == 2) {
      print_list( ptr );
    }
    else if (will == 3) {
      RET_CONT return_data = pop ( &ptr );
      if (return_data.code == 0) {
	printf("Popped value: %d\n",return_data.value );
      }
      else {
	printf("Pop exited with returncode %d\n",return_data.code);
      }
    }
    else {
      printf("Wrong choice!");
    }
  }
}


/*
int read_lines (char * line_ptr) {
  FILE *file_pointer;
  long long unsigned int nxt_buffer_len = 0;
  const long long unsigned int line_count = 0;
  file_pointer = fopen( "test_text" , "r"); // Reading from file
  
  if (!line_count) {
    
    return(0);
  }
  
  
  if (!file_pointer) {return(-1);} // Fail safe
  
  do {
    char c;
    c = getc(file_pointer);
    printf("%c",c);
  }
  while(c != EOF);
  fclose(file_pointer);
  return(nxt_buffer_len);
  }*/
