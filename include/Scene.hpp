#ifndef RTS_GAME_SCENE
#define RTS_GAME_SCENE
#include "GameManager.hpp"

namespace RTS{

    class Scene{
    protected:
      GameManager* game_manager;

    public:
      Scene(GameManager* gm_ptr);
      virtual ~Scene();
      virtual void tick();
      virtual void tickEvent(Event* eventHandler);
      virtual void draw();

   };

 }

 #endif
