#include <stdio.h>
#include "lib/foo.h"
static void read ();

int main ( void ) {

  for (  int i = 0; i < 4; i++ ) {
    char buffer [5];
    read( buffer );
    buffer [4] = '\0';
    
    printf( "%s\n" , buffer );
  }
  return(0);
}


void read ( char buffer[4]  ) {
  FILE * pointer;
  static int count = 0;
  int counter = 0;
  pointer = fopen( "text" , "r" );
  if (pointer == NULL) { printf("Locha!");return;}
  char ch;
  fseek ( pointer , count  , SEEK_SET );
  count +=5;
  while (ch != EOF) {
    ch = fgetc( pointer );
    buffer [ counter ] = ch;
    if (counter == 4) {break;}
    counter++;
  }
  return;
}
