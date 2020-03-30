#ifndef RTS_BUILDING_WOODCUTTER
#define RTS_BUILDING_WOODCUTTER

#include "units/Building.hpp"

namespace RTS{

    class Woodcutter : public Building{
    public:
      Woodcutter(GameManager*, int, int, int);
      ~Woodcutter();

   };

 }

 #endif
