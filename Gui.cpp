#include "Gui.h"

Gui::Gui() : window(nullptr), renderer(nullptr) {}

Gui::~Gui()
{
  shutdown();
}

bool Gui::initialize()
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cerr << "Failed to initialize SDL video: " << SDL_GetError() << std::endl;
    return false;
  }

  window = SDL_CreateWindow("Controller GUI", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
  if (!window)
  {
    std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
    return false;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer)
  {
    std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
    return false;
  }

  return true;
}

void Gui::render(const Controller &controller)
{
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  int centerX_Left = 200;
  int centerX_Rigth = 600;
  int centerY = 300;
  int radius = 50;

  int posX_Left = centerX_Left + (controller.getLJAxisX() / 32767.0) * radius;
  int posY_Left = centerY + (controller.getLJAxisY() / 32767.0) * radius;
  int posX_Right = centerX_Rigth + (controller.getRJAxisX() / 32767.0) * radius;
  int posY_Right = centerY + (controller.getRJAxisY() / 32767.0) * radius;

  SDL_Rect rectLeft = {posX_Left - 10, posY_Left - 10, 20, 20};
  SDL_Rect rectRight = {posX_Right - 10, posY_Right - 10, 20, 20};
  SDL_RenderFillRect(renderer, &rectLeft);
  SDL_RenderFillRect(renderer, &rectRight);

  SDL_RenderPresent(renderer);
}

void Gui::shutdown()
{
  if (renderer)
  {
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
  }
  if (window)
  {
    SDL_DestroyWindow(window);
    window = nullptr;
  }
  SDL_QuitSubSystem(SDL_INIT_VIDEO);
}
