#pragma once
#include <SDL_image.h>

class Map {
private:
  SDL_Texture *bg;
  SDL_Renderer *rend;

public:
  Map(SDL_Renderer *renderer);
  void update();
  void destroy();
};
