#include <stdio.h>
int main () { 
  float x, *px = &x;
  *px = 5 * 5;
  x= x/5;
  printf("%.2f", *px);
  printf("\n%.2f", x);
  return 0;
}