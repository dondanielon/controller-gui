#include "Controller.h"

Controller::Controller() : joystick(nullptr), lj_axisX(0), lj_axisY(0), rj_axisX(0), rj_axisY(0) {}

Controller::~Controller()
{
  shutdown();
}

bool Controller::initialize()
{
  if (SDL_Init(SDL_INIT_JOYSTICK) < 0)
  {
    std::cerr << "Failed to initialize SDL joystick: " << SDL_GetError() << std::endl;
    return false;
  }

  if (SDL_NumJoysticks() < 1)
  {
    std::cerr << "No joysticks connected!" << std::endl;
    return false;
  }

  joystick = SDL_JoystickOpen(0);

  if (!joystick)
  {
    std::cerr << "Failed to open joysticks: " << SDL_GetError() << std::endl;
    return false;
  }

  return true;
}

void Controller::update()
{
  SDL_JoystickUpdate();
  lj_axisX = SDL_JoystickGetAxis(joystick, 0);
  lj_axisY = SDL_JoystickGetAxis(joystick, 1);
  rj_axisX = SDL_JoystickGetAxis(joystick, 2);
  rj_axisY = SDL_JoystickGetAxis(joystick, 3);
}

void Controller::shutdown()
{
  if (joystick)
  {
    SDL_JoystickClose(joystick);
    joystick = nullptr;
  }

  SDL_QuitSubSystem(SDL_INIT_JOYSTICK);
}

int Controller::getLJAxisX() const
{
  return lj_axisX;
}

int Controller::getLJAxisY() const
{
  return lj_axisY;
}

int Controller::getRJAxisX() const
{
  return rj_axisX;
}

int Controller::getRJAxisY() const
{
  return rj_axisY;
}
