#pragma once
#include <Displayable.h>

class GameObject : public Displayable {
private:
  int _hitbox[4]; // use a class instead?

protected:
  SDL_Rect dest;

public:
  GameObject(Config *config, const char *img_path, int w, int h, int x, int y,
             int hbW, int hbH, int hbx, int hby);
  GameObject(Config *config, int w, int h, int x, int y, int hbW, int hbH,
             int hbX, int hbY);
  void init(Config *config, int w, int h, int x, int y);
  void update() override;
};
