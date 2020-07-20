#ifndef RTS_GAME_SCENE_WORLD
#define RTS_GAME_SCENE_WORLD

#include "../GameManager.hpp"
#include "../Scene.hpp"         
#include "../rendering/BaseRendering.hpp"
#include "../rendering/GridRendering.hpp"

#include "WorldScene/Camera.hpp"
#include "WorldScene/units/Building.hpp"

#include <list>
#include <queue>

namespace RTS{

    class WorldScene : public Scene{

    private:
      BaseRendering*       free_renderer;
      GridRendering*       grid_renderer;

      Camera*                     camera;
      Grid*                         grid;

      list<Building*>   stored_buildings;
      list<Unit*>           stored_units;

      queue<Building>      render_buffer;
      
    public:
      WorldScene(GameManager*    gm_ptr);
      ~WorldScene();
      void tick();
      void draw();

   };

 }

 #endif
