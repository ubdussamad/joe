/*  Suite for Lexical Analysis for the Joe Programming Lanaguage.
 *  Author: Mohammed S. Haque <ubdussamad@gmail.com>
 *  License: MIT
 *  Comes Under NO WARRANTY whatsoever.
 *  Ref: 01_23OCT18
 *
 *  Currently Using POSIX regular expression lib.
 *  This compiler will only be built for Linux environment.
 *  For further Documentaion and suport visit..
 *  its repo at: https://github.com/ubdussamad/joe
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include "lib/line_reader.h"

int main ( int agrc , char * argv [] ) {
  for ( int i=0; i < 5; i++ ) {
    return_node_t cont = get_line( argv[1] , i );
    if( cont.code == -1 ) {
      printf("File error Occured!");
      return(0);
    }
    else if (cont.code == -2 )  {
      printf("Line index Overflow!");
    }
    else if ( cont.code == 0 ) {
      printf("%s" , (char *) cont.addr );
    }
    else {
      printf("An Unknown Error Occured!");
    }
  } 
  printf("Hellow World!\n");
  return(0);
}
