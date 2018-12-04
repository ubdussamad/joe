#ifndef LINE_READER_H_
#define LINE_READER_H_


typedef struct return_node return_node_t;

struct return_node {
  int code; //Return Code.
  int width; //Width of the data in bytes.
  long unsigned int addr; //Base pointer to the string.
};

long long unsigned  load_file ();
return_node_t get_line();


#endif
