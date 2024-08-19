#pragma once
#include <GameObject.h>
#include <list>

class Bodee : public GameObject {
private:
  SDL_RendererFlip side = SDL_FLIP_NONE;
  const int speed = 320;
  const double defaultAirTime = 0.5;
  double airTime = defaultAirTime;
  const int airAccel = 6;
  const int defaultJumpTime = 3;
  int anim_start = 0;
  bool jumping = false;
  bool falling = true;
  SDL_Texture *waiting[2], *running[13];
  void incX(int inc);
  void incY(int inc);
  enum Sense : short { pos = 1, neg = -1 };
  enum Direction : short { left = 2, down = 3, right = 0, up = 1 };
  void move(double deltaTime, std::list<GameObject> obstacles, Sense sense,
            Direction dir, float acceleration = 1.0);
  SDL_Texture *jump, *levitate, *fall;

public:
  Bodee(Config *config)
      : GameObject(config, 15, 9, 2, 5, 0.3, 0.15, 0.7, 0.94){};
  void init();
  void update(double deltaTime, const Uint8 *keyboard,
              std::list<GameObject> obstacles);
  void destroy() override;
};
