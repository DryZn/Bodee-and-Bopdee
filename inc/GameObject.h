#pragma once
#include <Displayable.h>

class GameObject : public Displayable {
private:
  void init(Config *config, int w, int h, int x, int y, double hbX1,
            double hbY1, double hbX2, double hbY2);

protected:
  SDL_Rect dest;
  int hitbox[4];

public:
  GameObject(Config *config, const char *img_path, int w, int h, int x, int y,
             double hbX1 = 0, double hbY1 = 0, double hbX2 = 1,
             double hbY2 = 1);
  GameObject(Config *config, int w, int h, int x, int y, double hbX1,
             double hbY1, double hbX2, double hbY2Y);
  void update() override;
  int getHitbox(int index) { return hitbox[index]; };
};
