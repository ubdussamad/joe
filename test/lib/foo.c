#include <stdio.h>
#include <stdlib.h>
#include "foo.h"




int sum ( int x  , int y ) {
  node a;
  a.num = x;
  a.max = y;
  return( a.num + a.max + 100 );
}
