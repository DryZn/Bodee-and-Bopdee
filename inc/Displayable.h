#pragma once
#include <Config.h>
#include <string>

class Displayable {
protected:
  SDL_Texture *texture;
  SDL_Renderer *renderer;
  SDL_Texture *loadTexture(std::string img_path) const;

public:
  Displayable(Config *config) : renderer(config->renderer){};
  Displayable(Config *config, const char *img_path);
  virtual void update();
  virtual void update(double deltaTime, const Uint8 *keyboard){};
  // use ~Displayable instead
  virtual void destroy();
};
