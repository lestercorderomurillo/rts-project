#ifndef RTS_UNIT
#define RTS_UNIT

#include "GameManager.hpp"

namespace RTS{

    class Unit{

    protected:
      GameManager*   gameManager;

      int            position_x;
      int            position_y;
      int            health_current;
      int            health_max;
      string         nametag;

    public:
      Unit(GameManager*);

      virtual void tick();
      virtual void draw();

   };

 }

 #endif
