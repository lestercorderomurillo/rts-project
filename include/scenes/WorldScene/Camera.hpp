#ifndef RTS_GAME_SCENE_WORLD_CAMERA
#define RTS_GAME_SCENE_WORLD_CAMERA
#include <SFML/Graphics.hpp>

using namespace sf;

namespace RTS{

    class Camera{

    private:
        RenderWindow* windowPtr;
        Vector2i currentPosition;
        Vector2i lastPosition;
        bool isBeingDragged;

    public:
      Camera(RenderWindow* ptr);

      void tick();
      float getX();
      float getY();

   };

 }

 #endif
