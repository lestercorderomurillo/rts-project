#ifndef RTS_GAME_SCENE_WORLD_GRID
#define RTS_GAME_SCENE_WORLD_GRID
#include <SFML/Graphics.hpp>
#include <cmath>

#define MAPSIZE 32
#define EPSILON 2
#define TILEW 48
#define TILEH 24

using namespace sf;

namespace RTS{

    class Grid{

    private:
        int   world_tile[MAPSIZE][MAPSIZE];
        int   world_grid[(MAPSIZE + 1)*(MAPSIZE + 1)][(MAPSIZE + 1)*(MAPSIZE + 1)];
        Color world_lite[(MAPSIZE + 1)*(MAPSIZE + 1)][(MAPSIZE + 1)*(MAPSIZE + 1)];

    public:
      Grid();
      void reset();
      void updateLighting();
      int getTileID(int, int);
      int getPoint(int, int, int);
      void setTileID(int, int, int);
      void setPoint(int, int, int, int);
      void setTileHeight(int, int, int);
      void setTileAreaHeight(int, int, int, int);
      void setTileCircleAreaHeight(int, int, int, int);
      void setTileCircleAreaID(int, int, int, int);
      Color getPointColor(int, int, int);

   };

 }

 #endif
