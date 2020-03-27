#ifndef RTS_GAME_SCENE_WORLD
#define RTS_GAME_SCENE_WORLD

#include "../Scene.hpp"
#include "../GameManager.hpp"

namespace RTS{

    class WorldScene : public Scene{

    public:
      WorldScene(GameManager* ptr);
      ~WorldScene();
      void tick();
      void draw();

   };

 }

 #endif
