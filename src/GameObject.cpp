#include "GameObject.h"

GameObject::GameObject(Config *config, const char *img_path, int w, int h,
                       int x, int y, double hbX1, double hbY1, double hbX2,
                       double hbY2)
    : Displayable(config, img_path) {
  init(config, w, h, x, y, hbX1, hbY1, hbX2, hbY2);
}

GameObject::GameObject(Config *config, int w, int h, int x, int y, double hbX1,
                       double hbY1, double hbX2, double hbY2)
    : Displayable(config) {
  init(config, w, h, x, y, hbX1, hbY1, hbX2, hbY2);
}

void GameObject::init(Config *config, int w, int h, int x, int y, double hbX1,
                      double hbY1, double hbX2, double hbY2) {
  dest.w = config->width / w;
  dest.h = config->height / h;
  dest.x = config->width / x;
  dest.y = config->height / y;
  hitbox[0] = dest.x + dest.w * hbX1;
  hitbox[1] = dest.y + dest.h * hbY1;
  hitbox[2] = dest.x + dest.w * hbX2;
  hitbox[3] = dest.y + dest.h * hbY2;
}

void GameObject::update() { SDL_RenderCopy(renderer, texture, NULL, &dest); }
