#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "lib/cs.h"
//#include <pcre2.h> //Don't include it without proper declarations
lin_return_t subroutine(void);

<<<<<<< HEAD
int main ( void ) {
  lin_return_t call =  subroutine();
  int buffer[ call.length ];
  int counter = 0;
  for ( int i = 0 ; i <= call.length ; i++ ) {
    counter++;
    RET_CONT tmp = pop ( &call.data );
    if ( tmp.code != -1 ) {
      buffer[i] = tmp.value;
=======
typedef struct node node;
struct node {
  int value; // Cast it to char for generic stuff
  node * successor;
};

typedef struct ret_conti RET_CONTI;
struct ret_conti {
  int length;
  node * data;
};

typedef struct ret_cont RET_CONT;
struct ret_cont {
  int code;
  int value;
};

/* FUNCTION DEFS */

RET_CONT pop (node ** ref );

int push(int value ,  node ** ref );

int get_length ( node * );

RET_CONT pop (node ** ref );
int push(int value ,  node ** ref );
void print_list ( node * );

int get_length ( node * ptr ) {
  if (ptr == NULL) { return(0); }
  int count = 0;
  while (1) {
    if ( (*ptr).successor == NULL ) {
      return(count+1);
    }
    else {
      ptr = (*ptr).successor;
      count++;
    }
  }
}

RET_CONT pop(node ** ref) {
  if ((*ref) == NULL) { //Returns an container having the return status code and value
    RET_CONT instance;
    instance.code = -1;
    return( instance); }
  else if ( (**ref).successor == NULL ) {
    RET_CONT instance;
    instance.code = 0;
    instance.value = (**ref).value;
    free((*ref));
    *ref = NULL;
    return(instance); }
  else {
    node * last_ptr;
    node * weak_ref_ptr = *ref;
    while (1) {
      if ( (*weak_ref_ptr).successor == NULL ) {
	RET_CONT instance;
	instance.code = 0;
	instance.value = (*weak_ref_ptr).value;
	free(weak_ref_ptr);
	(*last_ptr).successor = NULL;
	return(instance);
      }
      else {
	last_ptr = weak_ref_ptr;
	weak_ref_ptr = (*weak_ref_ptr).successor;
      }
    }
  }
}

int push ( int value , node ** ref ) {
  node * chunk = (node * ) malloc ( sizeof(node) );
  if ( chunk == NULL ) {return(-1);} /* Malloc failed to get fresh memory */
  (*chunk).value = value; // Type cast these 8 bytes into whatever the hell you want 
  (*chunk).successor = NULL; // to make it genric
  if (*ref==NULL) { *ref=chunk; } // Refrencing freshly alloc mem to the intial pointer
  else { //Make sure that the pinter never goes to anything but NULL or node pointer
    node * tmp_ref = *ref;
    while (1) { if ( (*tmp_ref).successor == NULL ) {
    (*tmp_ref).successor = chunk;break;}
    tmp_ref = (*tmp_ref).successor;}}return(0);}

void print_list( node * ref ) {
if (ref == NULL) {return;}printf("\n[");while (1) {
printf("%d, ",(*ref).value );ref = (*ref).successor;
if (ref == NULL) {break;}}printf("]\n");}

int test ( void ) {
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
>>>>>>> 276c9dcaca28ed253947169c466156edc852fd94
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

<<<<<<< HEAD
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
=======

RET_CONTI read_line (void) {
  static FILE *file_pointer;
  file_pointer = fopen( "test_text" , "r"); // Reading from file
  RET_CONTI line;
  if (!file_pointer) { // Fail safe
    line.data = NULL;
    line.length = -1;
    return(line);
  }

  line.data = NULL;
  line.length = 0;
  char c;
  do {
    c = getc(file_pointer); // Append each character everytime to the buffer
    push( (int) c  , &line.data );
  }
  while(c != EOF ||(c != '\n'));
  
  line.length = get_length( line.data );
  if (c == EOF) {
    fclose(file_pointer);
  }
  return( line );
  }

int main (void) {
  RET_CONTI z = read_line ();
  char buffer [ z.length ];
  for ( int i = 0; i != z.length ; i++ ) {
    buffer[z.length - i] = (char) (pop( &z.data ).value); // Appending chars to the array buffer in reverse mannner from the stack 
  }
  printf("The string is: %s" , buffer );
  return(0);
}
  
>>>>>>> 276c9dcaca28ed253947169c466156edc852fd94
