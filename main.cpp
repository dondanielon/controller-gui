#include "Controller.h"
#include "Gui.h"

int main()
{
  Controller controller;
  Gui gui;

  if (!controller.initialize() || !gui.initialize())
  {
    return -1;
  }

  bool running = true;
  SDL_Event event;

  while (running)
  {
    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
      {
        running = false;
      }
    }

    controller.update();
    gui.render(controller);
  }

  controller.shutdown();
  gui.shutdown();

  return 0;
}
