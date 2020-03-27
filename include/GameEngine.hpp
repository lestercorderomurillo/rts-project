#ifndef RTS_GAME_ENGINE
#define RTS_GAME_ENGINE

#include "GameManager.hpp"
#include "Scene.hpp"

namespace RTS{

    class GameEngine{
      GameManager*   gameManager;
      Scene*         currentScene;

    public:
      GameEngine();
      ~GameEngine();

      int fetchResources();
      void runGameLoop();

   };

 }

 #endif
