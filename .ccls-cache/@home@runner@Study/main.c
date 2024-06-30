#include <stdio.h>


int main(void) {

  int x = 1648;
  int y = 285758;

  int *p = &x;

  int aux = 0;
  aux = *p;
  *p = y; 
  p = &y;
  *p = aux;

  printf("value of x on y = %d\nValue of y on x = %d\n", x, y);
  

  
  
  return 0;
}