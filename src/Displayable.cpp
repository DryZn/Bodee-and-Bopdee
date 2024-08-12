#include <Displayable.h>
#include <SDL2/SDL_video.h>

Displayable::Displayable(Config *config, const char *img_path)
    : renderer(config->renderer) {
  texture = loadTexture(std::string(img_path));
}

SDL_Texture *Displayable::loadTexture(std::string img_path) const {
  std::string path = "data/" + img_path + ".png";
  SDL_Surface *surface = IMG_Load(path.data());
  // surface->format is always the same
  Uint32 colorKey = SDL_MapRGB(surface->format, 255, 255, 255);
  SDL_SetColorKey(surface, SDL_TRUE, colorKey);
  SDL_Texture *_texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
  return _texture;
}

void Displayable::update() { SDL_RenderCopy(renderer, texture, NULL, NULL); }

void Displayable::destroy() { SDL_DestroyTexture(texture); }
