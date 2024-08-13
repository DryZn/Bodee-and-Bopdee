#pragma once
#include <GameObject.h>

class Bodee : public GameObject {
private:
  SDL_RendererFlip side = SDL_FLIP_NONE;
  int speed = 320;
  int anim_start = 0;
  SDL_Texture *waiting[2];
  int sizeWait;
  SDL_Texture *running[13];
  int sizeRun;
  int waitingTimeFrame;

public:
  Bodee(Config *config);
  void update(double deltaTime, const Uint8 *keyboard) override;
  void destroy() override;
};
