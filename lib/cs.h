#ifndef CS_H_   /* Include guard */
#define CS_H_

typedef struct node node;
struct node {
  int value; // Cast it to char for generic stuff
  node * successor;
};
typedef struct ret_cont RET_CONT;
struct ret_cont {
  int code;
  int value;
};

RET_CONT pop (node ** ref );
int push(int value ,  node ** ref );
void print_list ( node * );

#endif // COMPOUND_STRUCTURES_H_
