#ifndef RTS_GAME_SCENE_WORLD
#define RTS_GAME_SCENE_WORLD

#include "../Scene.hpp"
#include "../GameManager.hpp"
#include "../rendering/BaseRendering.hpp"
#include "../rendering/GridRendering.hpp"

#include "WorldScene/Camera.hpp"

namespace RTS{

    class WorldScene : public Scene{

    private:
      BaseRendering*  debugging;
      GridRendering*  gridRenderer;

      Camera*         camera;
      bool            refresh_tilemap;
      
    public:
      WorldScene(GameManager* ptr);
      ~WorldScene();
      void tick();
      void draw();

   };

 }

 #endif
