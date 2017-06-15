/*
 * info_flow_control.c
 *
 * @author: phdenzel
 */

#include <stdio.h>


int bitHalve(int x) {
  return x >> 1;
}

int bitDouble(int x) {
  return x << 1;
}

void runForLoop(int x, int from, int to) {
  // Starting from
  printf("Original value of x is %d\n", x);
  // Loop
  for (int i=from; i<to; i++) {
    x = bitHalve(x);
    printf("\tFor-loop #%d: x is %d\n", i, x);
  }
  
}

void runWhileLoop(int x, int from, int to) {
  // Starting from
  printf("Original value of x is %d\n", x);
  int count=from;
  // Loop
  while (count < to) {
    x = bitHalve(x);
    printf("\tWhile-loop #%d: x is %d\n", count, x);
    count++;
  }
  
}

void runDoLoop(int x, int from, int to) {
  // Starting from
  printf("Original value of x is %d\n", x);
  int count=from;
  // Loop
  do {
    x = bitHalve(x);
    printf("\tDo-loop #%d: x is %d\n", count, x);
  } while (++count < to);
  
}

void runIfCondition(int x) {
  // If checks
  if (x <= 256) {
    printf("If condition says I should halve x\n");
    x = bitHalve(x);
  } else if (x <= 512) {
    printf("Else if condition says I should double x\n");
    x = bitDouble(x);
  } else {
    printf("No condition was true... setting x to 2\n");
    x = 2;
  }
  printf("Value of x is %d\n", x);
  
}


int main(int argc, char **argv) {
  printf("C-FLOW-CONTROL\n");
  // Loops
  int x = 256;
  printf("Loops\n");
  runForLoop(x, 0, 4);
  runWhileLoop(x, 0, 4);
  runDoLoop(x, 0, 4);
  //Conditionals
  x = 512;
  printf("If conditions\n");
  runIfCondition(x);
  
}
