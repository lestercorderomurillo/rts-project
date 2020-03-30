#ifndef RTS_BUILDING
#define RTS_BUILDING

#include "Unit.hpp"

namespace RTS{

    class Building : public Unit{
    public:
      Building(GameManager*, int, int, int);
      ~Building();

      void presetTick();
      void tick();
      void draw();

   };

 }

 #endif
