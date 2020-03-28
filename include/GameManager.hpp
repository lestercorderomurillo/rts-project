#ifndef RTS_GAME_MANAGER
#define RTS_GAME_MANAGER

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include "managed/LogSystem.hpp"
#include "managed/ResourceBatch.hpp"

using namespace sf;

namespace RTS{

    class GameManager{
    private:

      RenderWindow*  window;
      LogSystem*     logger;
      ResourceBatch* batch;

    public:
      GameManager();
      ~GameManager();

      LogSystem* getLogger();
      RenderWindow* getWindow();
      ResourceBatch* getBatch();

   };

 }

 #endif
