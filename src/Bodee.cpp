#include <Bodee.h>
#include <string.h>

Bodee::Bodee(Config *config) : Displayable(config) {
  dest.w = config->width / 18;
  dest.h = config->height / 10.3;
  dest.x = 0;
  dest.y = 0;
  for (int i = 1; i <= 2; i++)
    waiting[i - 1] =
        Displayable::loadTexture("bodee/waiting/" + std::to_string(i));
  texture = waiting[0];
  std::cout << SDL_GetError();
}

void Bodee::update(double deltaTime, const Uint8 *keyboard) {
  if (keyboard[SDL_SCANCODE_W] | keyboard[SDL_SCANCODE_S] |
      keyboard[SDL_SCANCODE_A] | keyboard[SDL_SCANCODE_D]) {
    dest.y += speed * deltaTime *
              (-keyboard[SDL_SCANCODE_W] + keyboard[SDL_SCANCODE_S]);
    if (keyboard[SDL_SCANCODE_A]) {
      dest.x -= speed * deltaTime;
      side = SDL_FLIP_NONE;
    }
    if (keyboard[SDL_SCANCODE_D]) {
      dest.x += speed * deltaTime;
      side = SDL_FLIP_HORIZONTAL;
    }
  } else {
    anim_start += (int)(deltaTime * 100);
    texture = waiting[(anim_start / 40) % 2];
  }
  SDL_RenderCopyEx(renderer, texture, NULL, &dest, 0, NULL, side);
}

void Bodee::destroy() {
  Displayable::destroy();
  for (int i = 0; i < 2; i++)
    SDL_DestroyTexture(waiting[i]);
}
