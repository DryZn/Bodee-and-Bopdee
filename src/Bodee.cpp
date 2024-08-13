#include <Bodee.h>
#include <string.h>

Bodee::Bodee(Config *config) : GameObject(config, 15, 9, 2, 5, 0, 0, 0, 0) {
  for (int i = 1; i <= 2; i++)
    waiting[i - 1] =
        Displayable::loadTexture("bodee/wait/" + std::to_string(i));
  int i = 0;
  for (int i_name = 1; i_name <= 9; i_name++) {
    running[i] =
        Displayable::loadTexture("bodee/run/" + std::to_string(i_name));
    // duplicate some images
    if (i_name == 3 | i_name == 8) {
      running[i + 1] = running[i + 2] = running[i];
      i += 3;
    } else
      i++;
  }
  texture = waiting[0];
  std::cout << SDL_GetError();
}

void Bodee::update(double deltaTime, const Uint8 *keyboard) {
  anim_start += (int)(deltaTime * 100);
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
    texture = running[(anim_start / 4) % 13];
  } else {
    texture = waiting[(anim_start / 40) % 2];
  }
  SDL_RenderCopyEx(renderer, texture, NULL, &dest, 0, NULL, side);
}

void Bodee::destroy() {
  Displayable::destroy();
  for (int i = 0; i < 2; i++)
    SDL_DestroyTexture(waiting[i]);
}
