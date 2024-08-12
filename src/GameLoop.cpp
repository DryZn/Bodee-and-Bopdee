#include <Bodee.h>
#include <GameLoop.h>
#include <Map.h>
#include <SDL2/SDL_timer.h>

void GameLoop::launch() {
  std::cout << "Starting" << std::endl;
  if (SDL_Init(SDL_INIT_EVERYTHING)) {
    std::cout << "Error SDL init:" << SDL_GetError() << std::endl;
  }
  Config *config = new Config(1260, 710);
  SDL_Window *win = SDL_CreateWindow("Bodee and Bopdee", SDL_WINDOWPOS_CENTERED,
                                     SDL_WINDOWPOS_CENTERED, config->width,
                                     config->height, 0);
  SDL_Renderer *renderer =
      SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  config->setRenderer(renderer);
  Bodee bodee = Bodee(config);
  Map map = Map(config, bodee);

  double deltaTime;
  Uint64 last_frame = 0;
  Uint64 current_frame = 0;
  bool close = false;
  SDL_Event event;
  while (!close) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        close = event.type == SDL_QUIT;
    }
    current_frame = SDL_GetPerformanceCounter();
    deltaTime = (double)(current_frame - last_frame) /
                (double)SDL_GetPerformanceFrequency();
    map.update(deltaTime, SDL_GetKeyboardState(NULL));
    SDL_RenderPresent(renderer);
    last_frame = current_frame;
    // limit to aproximately 60 fps
    SDL_Delay(14);
  }

  map.destroy();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(win);
  SDL_Quit();
}
