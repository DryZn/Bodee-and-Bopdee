#pragma once
#include <Displayable.h>

class Bodee : public Displayable {
private:
  SDL_RendererFlip side = SDL_FLIP_NONE;
  int speed = 300;
  int anim_start = 0;
  SDL_Texture *waiting[2];
  int waitingTimeFrame;
  SDL_Rect dest;

public:
  Bodee(Config *config);
  void update(double deltaTime, const Uint8 *keyboard) override;
  void destroy() override;
};
