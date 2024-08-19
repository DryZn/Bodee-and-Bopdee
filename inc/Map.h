#pragma once
#include <Bodee.h>

class Map : public Displayable {
private:
  Bodee _bodee;
  std::list<GameObject> _obstacles;

public:
  Map(Config *config, Bodee bodee, std::list<GameObject> obstacles)
      : Displayable(config, "bg"), _bodee(bodee), _obstacles(obstacles){};
  void update(double deltaTime, const Uint8 *keyboard) override;
};
