#ifndef RTS_GAME_SCENE_WORLD_CAMERA
#define RTS_GAME_SCENE_WORLD_CAMERA

#include <SFML/Graphics.hpp>

using namespace sf;

namespace RTS{

    class Camera{

    private:
        RenderWindow*      rw_wnd_ptr;
        Vector2i     position_current;
        Vector2i        position_last;
        bool         is_being_dragged;

    public:
      Camera(RenderWindow* rw_ptr);

      void tick();
      float getX();
      float getY();

   };

 }

 #endif
