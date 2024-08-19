#include <Bodee.h>
#include <string.h>

void Bodee::init() {
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
  jump = Displayable::loadTexture("bodee/jump");
  levitate = Displayable::loadTexture("bodee/levitate");
  fall = Displayable::loadTexture("bodee/fall");
}

void Bodee::incX(int inc) {
  dest.x += inc;
  hitbox[0] += inc;
  hitbox[2] += inc;
}

void Bodee::incY(int inc) {
  dest.y += inc;
  hitbox[1] += inc;
  hitbox[3] += inc;
}

void Bodee::move(double deltaTime, std::list<GameObject> obstacles, Sense sense,
                 Direction dir, float acceleration) {
  int inc = speed * deltaTime * sense * acceleration;
  int iObs = (dir + 2) % 4;
  int dirOpp = (dir + 1) % 4;
  int dirOpp2 = (dir + 3) % 4;
  bool dirY = dir % 2;
  int senseOpp = dirY ? sense : -sense;
  for (std::list<GameObject>::iterator obs = obstacles.begin();
       obs != obstacles.end(); obs++) {
    if (hitbox[dir] * sense <= obs->getHitbox(iObs) * sense &&
        obs->getHitbox(iObs) * sense < (hitbox[dir] + inc) * sense) {
      if (!(hitbox[dirOpp] * senseOpp > obs->getHitbox(dirOpp2) * senseOpp ||
            obs->getHitbox(dirOpp) * senseOpp > hitbox[dirOpp2] * senseOpp)) {
        inc = obs->getHitbox(iObs) - hitbox[dir];
        obs = obstacles.end();
      }
    }
  }
  dirY ? incY(inc) : incX(inc);
}

void Bodee::update(double deltaTime, const Uint8 *keyboard,
                   std::list<GameObject> obstacles) {
  anim_start += (int)(deltaTime * 100);
  if (keyboard[SDL_SCANCODE_A] | keyboard[SDL_SCANCODE_D]) {
    if (keyboard[SDL_SCANCODE_A]) {
      move(deltaTime, obstacles, Sense::neg, Direction::right);
      side = SDL_FLIP_NONE;
    }
    if (keyboard[SDL_SCANCODE_D]) {
      move(deltaTime, obstacles, Sense::pos, Direction::left);
      side = SDL_FLIP_HORIZONTAL;
    }
    texture = running[(anim_start / 4) % 13];
  } else
    texture = waiting[(anim_start / 40) % 2];
  // handle jump
  if (!falling && (keyboard[SDL_SCANCODE_W] | jumping)) {
    if (!jumping) {
      jumping = true;
      airTime = defaultJumpTime;
    }
    int y = dest.y;
    move(deltaTime, obstacles, Sense::neg, Direction::up, airTime);
    if (y != dest.y) {
      airTime -= deltaTime * airAccel;
      texture = airTime < 1 ? levitate : jump;
    } else {
      jumping = false;
      falling = true;
      airTime = defaultAirTime;
    }
  } else {
    // handle gravity
    int y = dest.y;
    move(deltaTime, obstacles, Sense::pos, Direction::down, airTime);
    if (y != dest.y) {
      texture = airTime < 1 ? levitate : fall;
      airTime += deltaTime * airAccel;
    } else {
      airTime = defaultAirTime;
      falling = false;
    }
  }
  SDL_RenderCopyEx(renderer, texture, NULL, &dest, 0, NULL, side);
}

void Bodee::destroy() {
  Displayable::destroy();
  for (int i = 0; i < 2; i++)
    SDL_DestroyTexture(waiting[i]);
  for (int i = 0; i < 13; i++)
    SDL_DestroyTexture(running[i]);
  SDL_DestroyTexture(jump);
  SDL_DestroyTexture(levitate);
  SDL_DestroyTexture(fall);
}
