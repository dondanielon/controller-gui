#ifndef GUI_H
#define GUI_H

#include <SDL2/SDL.h>
#include "Controller.h"

class Gui
{
public:
  Gui();
  ~Gui();

  bool initialize();
  void render(const Controller &controller);
  void shutdown();

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
};

#endif // GUI_H
