# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "cs.h"




RET_CONT pop (node ** ref );
int push(int value ,  node ** ref );
void print_list ( node * );



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
    }
    else {
      printf("Wrong choice!");
    }
  }
}
	
