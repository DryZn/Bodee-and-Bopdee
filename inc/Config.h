#pragma once
#include <SDL_image.h>
#include <iostream>

struct Config {
  Config(int w, int h) : width(w), height(h){};
  int width, height;
  SDL_Renderer *renderer;
  void setRenderer(SDL_Renderer *rend);
};
