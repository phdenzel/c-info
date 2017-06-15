/*
 * info_arrays.c
 *
 * @author: phdenzel
 */

#include <stdio.h>


int max(int array[], size_t size) {
  
  int current_max = 0; 
  for (int i=0; i<size; i++) {
    if (current_max < array[i]) {
      current_max = array[i];
    }
  }
  return current_max;
  
}

void printArray(int array[], size_t size) {

  printf("Array:\t");
  for (int i=0; i<size; i++) {
    printf("%d  ", array[i]);
  }
  printf("\n");
  
}


int main(int argc, char **argv) {
  printf("C-Arrays:\n");
  // initialize
  int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  size_t n = sizeof array / sizeof *array;
  // print
  printArray(array, n);
  // maximum
  int maximum = max(array, n);
  printf("The maximum of the array is %d\n", maximum);
  // info about arrays
  printf("Arrays are passed to a function by reference. \n");
  printf("This means that you can actually change their values in memory, \n");
  printf("whereas primitive types are passed by value, meaning changes inside a \n");
  printf("function do not affect their global value.\n");
  printf("If you want to emulate the passing by value of an array, use \n");
  printf("'function(const int array[])'\n");
  
}
