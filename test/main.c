#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long unsigned  load_file ();
typedef struct return_node return_node_t;
struct return_node {
  int code;
  int width;
  long unsigned int addr;
};

int main ( int argc, char * argv [] )  {

  return_node_t cont = get_line( argv[1] , atoi(argv[2]) );
   if ( cont.code == 0 ) {
     printf("Line is: %s" , (char *) cont.addr );
   }
   else if ( cont.code == -2 ) {
     printf("No line like that!\n");
   }
   else {
     printf("Nothing is okay, file is bogus!\n");
   }
}



return_node_t get_line ( char * file , int usr_lin_num ) {

  static int state = 0;
  /* If the file is already read , no need to call
     read again.
  */
  static long unsigned int buffer;
  if (!state) {
    long unsigned int temp = load_file( file );
    buffer = temp;
    state = 1;
  }
  return_node_t container;
  
  if (buffer==0) { container.code = -1; return(container); } //File read Problem

  char * stringified_buffer = (char *) buffer;

  int counter = 0; int lin_num = 0; int  last_line_sp = 0;

  while (0x1) {

    if ( strlen(stringified_buffer) < counter+1 ) {
      container.code = -2;
      return(container);
    }

    char ch = stringified_buffer[counter];

    if ( ( ch == '\n' ) ||  (ch == '\0') ) {
      lin_num++;
      if (lin_num == (usr_lin_num + 1)) {
	break;
      }
      last_line_sp = counter;
    }
    counter++;
  }

  //Counter has line end
  //last line sp has the starting point in the array
  int width = counter - last_line_sp;
  char * line = (char *) malloc ( (size_t) width+1 );
  for ( int i=0 ; i < (width-1) ; i++ ) {
    line[i] = stringified_buffer[last_line_sp+1+i];
  }
  line[width+1] = '\0';
  container.width = width;
  container.code = 0;
  container.addr = (long long unsigned) line;

  return(container);
}

/* Return 1 if file can't be read else
   returns the pointer (long long unsigned)
   to the buffer carring the string. 
*/
long long unsigned load_file ( char * file ) {
  FILE * fp;fp = fopen( file ,"r" );if (fp == NULL){
  printf("Please provide a file name in the arguments.\n");
  return(1);}fseek( fp , 0 , SEEK_END );
  long fsize = ftell ( fp );fseek( fp , 0 , SEEK_SET );
  char * buffer = ( char * ) malloc ( (size_t) fsize );
  long long unsigned buff_num = (long long unsigned) buffer;
  int i =0;for ( i=0;  i < fsize ;  i++) {
  char ch = fgetc(fp);memcpy ( (char *)(buff_num + i) , &ch ,  1);}
  char end = '\0';memcpy(  (char *)(buff_num + i) , &end , 1 );
  return( buff_num );}
