#ifndef RTS_GAME_SCENE_WORLD
#define RTS_GAME_SCENE_WORLD

#define _UNIT_LIMIT      24
#define _BUILDINGS_LIMIT 32

#include "../GameManager.hpp"
#include "../Scene.hpp"         
#include "../rendering/BaseRendering.hpp"
#include "../rendering/GridRendering.hpp"

#include "WorldScene/Camera.hpp"
#include "WorldScene/units/Building.hpp"

#include <list>

namespace RTS{

    class WorldScene : public Scene{

    private:
      BaseRendering*       free_renderer;
      GridRendering*       grid_renderer;
      Grid*                         grid;
      Camera*                     camera;
      list<Building*>   stored_buildings;
      list<Unit*>           stored_units;
      bool        update_depth_scheduled;
      
    public:
      WorldScene(GameManager*    gm_ptr);
      ~WorldScene();
      void clonefromWorldDescriptor(string src);
      int  spawnUnit(Unit* unit);
      int  spawnBuilding(Building* unit);
      void tick();
      void tickEvent(Event* eventHandler);
      void draw();
      void executeDepthSort();
      void scheduleDepthSort();

   };

 }

 #endif
