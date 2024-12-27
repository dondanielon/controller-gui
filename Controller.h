#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL2/SDL.h>
#include <iostream>

class Controller
{
public:
  Controller();
  ~Controller();

  bool initialize();
  void update();
  void shutdown();

  int getLJAxisY() const;
  int getLJAxisX() const;
  int getRJAxisY() const;
  int getRJAxisX() const;

private:
  SDL_Joystick *joystick;
  int lj_axisX;
  int lj_axisY;
  int rj_axisX;
  int rj_axisY;
};

#endif