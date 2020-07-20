#ifndef RTS_BUILDING_WOODCUTTER
#define RTS_BUILDING_WOODCUTTER

#include "scenes/WorldScene/units/Building.hpp"

namespace RTS{

    class Woodcutter : public Building{
    public:
      Woodcutter(GameManager* gm_ptr, Camera* cam_ptr, int team, int x, int y);
      ~Woodcutter();

   };

 }

 #endif
