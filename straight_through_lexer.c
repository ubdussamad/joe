#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/cs.h"
//#include <pcre2.h> //Don't include it without proper declarations
lin_return_t subroutine(void);

int main ( void ) {
  lin_return_t call =  subroutine();
  int buffer[ call.length ];
  int counter = 0;
  for ( int i = 0 ; i <= call.length ; i++ ) {
    counter++;
    RET_CONT tmp = pop ( &call.data );
    if ( tmp.code != -1 ) {
      buffer[i] = tmp.value;
    }
    else {
      break;
    }
  }
  printf("Value: %d" , buffer[0] );
  printf( " Counter was incremented %d times. \n" , counter );
  
  return(0);
}

lin_return_t subroutine(void) {
  static FILE * file_pointer;
  file_pointer = fopen ( "test_text" , "r" );

  char c;
  lin_return_t container;
  int counter = 1;
  do {
    c = fgetc( file_pointer );
    if ( c == '\n' ) {
      return ( container ); }
    else {
      counter++;
      push ( (int) c , &container.data );
    }
  } while ( c != EOF );
  container.length = -1;
  return ( container );
}
