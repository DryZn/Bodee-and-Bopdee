#include <Map.h>
#include <SDL2/SDL_video.h>

void Map::update(double deltaTime, const Uint8 *keyboard) {
  Displayable::update();
  _bodee.update(deltaTime, keyboard);
}
