#include <GameLoop.h>
#include <Map.h>
#include <SDL2/SDL_timer.h>
#include <iostream>

void GameLoop::launch() {
  std::cout << "Starting" << std::endl;
  if (SDL_Init(SDL_INIT_EVERYTHING)) {
    std::cout << "Error SDL init:" << SDL_GetError() << std::endl;
  }
  SDL_Window *win = SDL_CreateWindow("Bodee and Bopdee", SDL_WINDOWPOS_CENTERED,
                                     SDL_WINDOWPOS_CENTERED, 1400, 900, 0);
  SDL_Renderer *renderer =
      SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  Map map = Map(renderer);

  bool close = false;
  while (!close) {
    SDL_Event event;
    SDL_RenderClear(renderer);
    map.update();
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        close = event.type == SDL_QUIT;
    }
    SDL_RenderPresent(renderer);
  }

  map.destroy();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(win);
  SDL_Quit();
}
