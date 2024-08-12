#pragma once
#include <Bodee.h>
#include <Displayable.h>

class Map : public Displayable {
private:
  Bodee _bodee;

public:
  Map(Config *config, Bodee bodee) : Displayable(config, "bg"), _bodee(bodee){};
  void update(double deltaTime, const Uint8 *keyboard) override;
};
