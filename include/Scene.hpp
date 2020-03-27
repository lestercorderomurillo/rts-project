#ifndef RTS_GAME_SCENE
#define RTS_GAME_SCENE
#include "GameManager.hpp"

namespace RTS{

    class Scene{
      GameManager* gameManager;

    public:
      Scene(GameManager*);
      virtual ~Scene();
      virtual void tick();
      virtual void draw();

   };

 }

 #endif
