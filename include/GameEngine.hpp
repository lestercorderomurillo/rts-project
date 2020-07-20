#ifndef RTS_GAME_ENGINE
#define RTS_GAME_ENGINE

#include "GameManager.hpp"
#include "Scene.hpp"
#include <string>

namespace RTS{

    class GameEngine{
    private:
    
      GameManager*    game_manager;
      Scene*         current_scene;

    public:
      GameEngine();
      ~GameEngine();

      std::string getWorkingDirectory();
      int fetchResources();
      void runGameLoop();

   };

 }

 #endif
