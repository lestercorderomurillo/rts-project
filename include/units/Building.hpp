#ifndef RTS_BUILDING
#define RTS_BUILDING

#include "Unit.hpp"

namespace RTS{

    class Building : public Unit{
    protected:
      

    public:
      Building();

      void defaultTick();
      void tick();
      void draw();

   };

 }

 #endif
