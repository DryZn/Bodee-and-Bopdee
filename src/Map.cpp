#include <Map.h>
#include <SDL2/SDL_video.h>

Map::Map(SDL_Renderer *renderer) {
  rend = renderer;
  SDL_Surface *surf_bg = IMG_Load("data/bg.png");
  bg = SDL_CreateTextureFromSurface(rend, surf_bg);
  SDL_FreeSurface(surf_bg);
}

void Map::update() { SDL_RenderCopy(rend, bg, NULL, NULL); }

void Map::destroy() { SDL_DestroyTexture(bg); }
