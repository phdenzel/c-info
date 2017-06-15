/*
 * info_types.c
 *
 * @author: phdenzel
 */

#include <stdio.h>
#include <math.h>


void explainTypes() {
  // types
  int integerType;
  short shortType;
  long longType;
  long long longlongType;
  float floatType;
  double doubleType;
  long double longdoubleType;
  char charType;
  // type sizes
  int i, s, l, ll, f, d, ld, c;
  i = sizeof(integerType);
  s = sizeof(shortType);
  l = sizeof(longType);
  ll= sizeof(longlongType);
  f = sizeof(floatType);
  d = sizeof(doubleType);
  ld= sizeof(longdoubleType);
  c = sizeof(charType);
  // number ranges
  long long imax, smax, cmax;
  imax = pow(2, 8*i-1)-1;
  smax = pow(2, 8*s-1)-1;
  cmax = pow(2, 8*c-1)-1;
  
  printf("char:\t\thas a size of %2d bytes, i.e. from -%10lld to %10lld\n",
         c, cmax+1, cmax);
  printf("short:\t\thas a size of %2d bytes, i.e. from -%10lld to %10lld\n",
         s, smax+1, smax);
  printf("int:\t\thas a size of %2d bytes, i.e. from -%10lld to %10lld\n",
         i, imax+1, imax);
  printf("long:\t\thas a size of %2d bytes, i.e. %3d bits\n",
         l, 8*l);
  printf("long long:\thas a size of %2d bytes, i.e. %3d bits\n",
         ll, 8*ll);
  printf("float:\t\thas a size of %2d bytes, i.e. %3d bits\n",
         f, 8*f);
  printf("double:\t\thas a size of %2d bytes, i.e. %3d bits\n",
         d, 8*d);
  printf("long double:\thas a size of %2d bytes, i.e. %3d bits\n",
         ld, 8*ld);
  
}

int main(int argc, char **argv) {

  printf("C-TYPES\n");
  explainTypes();
  printf("The values of numbers are evenly divided around 0.\n");
  printf("To double the range of positive numbers for a type, use 'unsigned <type>'.\n");

  return 0;
}
