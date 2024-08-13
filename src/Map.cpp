#include <Map.h>
#include <SDL2/SDL_video.h>

void Map::update(double deltaTime, const Uint8 *keyboard) {
  Displayable::update();
  std::list<GameObject>::iterator it;
  for (it = _obstacles.begin(); it != _obstacles.end(); it++)
    it->update();
  _bodee.update(deltaTime, keyboard);
}
