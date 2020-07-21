#ifndef RTS_GAME_ENGINE
#define RTS_GAME_ENGINE

#include "GameManager.hpp"
#include "Scene.hpp"
#include <string>

using namespace std;

namespace RTS{

    class GameEngine{
    private:
    
      GameManager*    game_manager;
      Scene*         current_scene;

    public:
      GameEngine();
      ~GameEngine();

      static int  current_fpsec_hr;
      static int  current_fpsec_lr;
      static float   current_delta;
      static bool    gameIsRunning;

      string getWorkingDirectory();
      static int getInternalFramesPerSecond();
      int fetchResources();
      void runGameLoop();

   };

   void thread_fps_sync();

 }

 #endif
