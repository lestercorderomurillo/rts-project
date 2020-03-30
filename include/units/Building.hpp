#ifndef RTS_BUILDING
#define RTS_BUILDING

#include "Unit.hpp"

namespace RTS{

    class Building : public Unit{
    protected:
      ConvexShape shadow;
      Vector2f    sp[4];      

    public:
      Building(GameManager*, Camera*, int, int, int);
      ~Building();

      void setShadow(Vector2f, Vector2f, Vector2f, Vector2f, float);
      void renderShadow();

      void presetTick();
      void presetDraw();

      virtual void tick();
      virtual void draw();

   };

 }

 #endif
