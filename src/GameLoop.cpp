#include <GameLoop.h>
#include <SDL2/SDL_video.h>
#include <SDL_image.h>
#include <iostream>

void GameLoop::launch() {
  std::cout << "Starting" << std::endl;
  if (SDL_Init(SDL_INIT_EVERYTHING)) {
    std::cout << "Error SDL init:" << SDL_GetError() << std::endl;
  }
  SDL_Window *win = SDL_CreateWindow("Bodee and Bopdee", SDL_WINDOWPOS_CENTERED,
                                     SDL_WINDOWPOS_CENTERED, 400, 400, 0);

  bool close = false;
  while (!close) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        close = event.type == SDL_QUIT;
    }
  }

  SDL_DestroyWindow(win);
  SDL_Quit();
}
