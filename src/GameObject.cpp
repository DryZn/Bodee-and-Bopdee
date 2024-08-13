#include "GameObject.h"

GameObject::GameObject(Config *config, const char *img_path, int w, int h,
                       int x, int y, int hbW, int hbH, int hbx, int hby)
    : Displayable(config, img_path), _hitbox{hbW, hbH, hbx, hby} {
  init(config, w, h, x, y);
}

GameObject::GameObject(Config *config, int w, int h, int x, int y, int hbW,
                       int hbH, int hbX, int hbY)
    : Displayable(config), _hitbox{hbW, hbH, hbX, hbY} {
  init(config, w, h, x, y);
}

void GameObject::init(Config *config, int w, int h, int x, int y) {
  dest.w = config->width / w;
  dest.h = config->height / h;
  dest.x = config->width / x;
  dest.y = config->height / y;
}

void GameObject::update() { SDL_RenderCopy(renderer, texture, NULL, &dest); }
