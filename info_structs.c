/*
 * info_structs.c
 *
 * @author: phdenzel
 */

#include <stdio.h>


struct particle {
  double x, y;   // Position
  double vx, vy; // Velocity
  double ax, ay; // Acceleration
  float m;       // Mass
  float q;       // Charge
  double e;      // Eccentricity
};

int main(int argc, char **argv) {

  printf("C-Structs\n");

  struct particle p;
  p.x = 200;
  p.y = 200;
  p.vx = p.vy = 0.1;
  p.ax = p.ay = 0;
  p.m = 1;
  p.q = 0;
  p.e = 1;

  printf("Particle struct\n");
  printf("Particle position: %f %f\n", p.x, p.y);
  printf("Particle velocity: %f %f\n", p.vx, p.vy);
  printf("Particle acceleration: %f %f\n", p.ax, p.ay);
  printf("Particle mass: %f\n", p.m);
  printf("Particle charge: %f\n", p.q);
  printf("Particle eccentricity: %f\n", p.e);

  // info about structs
  printf("structs in C are the closest thing to classes in other languages,\n");
  printf("in fact, they are probably the origin of OOP.\n");
  printf("Using 'typedef struct Foo {...} Foo;' declares a struct and\n");
  printf("adds it to the type namespace as well as the tag namespace.\n");
  printf("On the other hand, 'struct Foo {};' only declares a tag,\n");
  printf("and therefore declarations always have to be made with 'struct Foo x;',\n");
  printf("instead of 'Foo x;'.\n");

  printf("When dealing with pointers, '->' acts as a dereferencer and an accesor.\n");
  printf("It is a short-hand for something like '(*foo).x' for a 'struct Foo *foo'\n");
  printf("For normal variables '.' can simply access the structs properties.\n");
  
}
