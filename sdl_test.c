/*
 * C programming test of SDL2 library
 * @author: phdenzel
 */

#include <stdio.h>
#include <SDL2/SDL.h>


int main(void) {

  SDL_Window *window;
  SDL_Renderer *renderer;

  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow("Test window",
                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            640, 480,
                            0);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  // backgtound grey
  SDL_SetRenderDrawColor(renderer, 42, 47, 56, 255);
  SDL_RenderClear(renderer);
  // draw white rectangle
  SDL_SetRenderDrawColor(renderer, 222, 222, 222, 255);
  SDL_Rect rect = { 220, 140, 200, 200 };
  SDL_RenderFillRect(renderer, &rect); // structs are passed by value!
  // show
  SDL_RenderPresent(renderer);
  SDL_Delay(5000);
  // clean up
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  
  return 0;
  
}
