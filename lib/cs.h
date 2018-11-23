#ifndef CS_H_   /* Include guard */
#define CS_H_

/* DATA TYPE DEFS */


typedef struct node node;
struct node {
  int value; // Cast it to char for generic stuff
  node * successor;
};

typedef struct ret_conti lin_return_t;
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

void test ( void );

void print_list (  node * ref );



  
#endif // COMPOUND_STRUCTURES_H_
