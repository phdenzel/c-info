/*
 * C programming test of SDL2 library
 * @author: phdenzel
 * Runtime test
 */

#include <stdio.h>
#include <SDL2/SDL.h>

#include "c-std/vector4.h"


void SDL_RenderFillCircle(SDL_Renderer* rend, int x0, int y0, int radius) {
	// Uses the midpoint circle algorithm to draw a filled circle
	int x = radius;
	int y = 0;
	int radiusError = 1 - x;
	while (x >= y) {
		SDL_RenderDrawLine(rend, x + x0, y + y0, -x + x0, y + y0);
		SDL_RenderDrawLine(rend, y + x0, x + y0, -y + x0, x + y0);
		SDL_RenderDrawLine(rend, -x + x0, -y + y0, x + x0, -y + y0);
		SDL_RenderDrawLine(rend, -y + x0, -x + y0, y + x0, -x + y0);
		y++;
		if (radiusError < 0)
			radiusError += 2 * y + 1;
		else {
			x--;
			radiusError += 2 * (y - x + 1);
		}
	}
}

int processEvents(SDL_Window *window, int is_running, vector4_t *position) {
  SDL_Event event;

  while(SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_WINDOWEVENT_CLOSE: {
      if (window) {
        SDL_DestroyWindow(window);
        window = NULL;
        is_running = 0;
      }
    } break;
    case SDL_KEYDOWN: {
      switch (event.key.keysym.sym) {
      case SDLK_ESCAPE: {
        is_running = 0;
      } break;
      case SDLK_LEFT: {
        position->x -= 10;
      } break;
      case SDLK_RIGHT: {
        position->x += 10;
      } break;
      case SDLK_UP: {
        position->y -= 10;
      } break;
      case SDLK_DOWN: {
        position->y += 10;
      } break;
      }
    } break;
    case SDL_QUIT: {
      is_running = 0;
    } break;   
    }
  }

  const Uint8 *state = SDL_GetKeyboardState(NULL);
  if (state[SDL_SCANCODE_LEFT]) {
    position->x -= 10;
  }
  if (state[SDL_SCANCODE_RIGHT]) {
    position->x += 10;
  }
  if (state[SDL_SCANCODE_UP]) {
    position->y -= 10;
  }
  if (state[SDL_SCANCODE_DOWN]) {
    position->y += 10;
  }
  
  return is_running;
  
}

void renderDrawRectangle(SDL_Renderer *renderer, vector4_t *position) {
  // draw the white rectangle
  // backgtound grey
  SDL_SetRenderDrawColor(renderer, 42, 47, 56, 255);
  SDL_RenderClear(renderer);
  // draw white rectangle
  SDL_SetRenderDrawColor(renderer, 222, 222, 222, 255);
  SDL_Rect rect = { position->x, position->y, position->t, position->t };
  SDL_RenderFillRect(renderer, &rect); // structs are passed by value!
  // show
  SDL_RenderPresent(renderer);
  
}

void renderDrawCircle(SDL_Renderer *renderer, vector4_t *position) {
  // draw the white rectangle
  // backgtound grey
  SDL_SetRenderDrawColor(renderer, 42, 47, 56, 255);
  SDL_RenderClear(renderer);
  // draw white cicle
  SDL_SetRenderDrawColor(renderer, 222, 222, 222, 255);
  SDL_RenderFillCircle(renderer, position->x, position->y, position->t);  
  // show
  SDL_RenderPresent(renderer);
  
}

int main(void) {

  SDL_Window *window;
  SDL_Renderer *renderer;
  vector4_t position;
  position.t = 10; // width and height, resp. radius
  position.x = 220;
  position.y = 140;

  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow("Test window",
                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            640, 480,
                            0);

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  int is_running = 1;
  
  while(is_running) {
    // do we want to continue?
    is_running = processEvents(window, is_running, &position);
    
    // draw stuff
    // renderDrawRectangle(renderer, &position);
    renderDrawCircle(renderer, &position);

    // have mercy on CPU
    SDL_Delay(10);
    
  }

  // clean up
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  
  return 0;
  
}
