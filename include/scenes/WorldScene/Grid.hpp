#ifndef RTS_GAME_SCENE_WORLD_GRID
#define RTS_GAME_SCENE_WORLD_GRID
#define MAPSIZE 32
#define EPSILON 2
#define TILEW 48
#define TILEH 24

#include <SFML/Graphics.hpp>
#include <cmath>

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
      int getTileID(int x, int y);
      int getPoint(int x, int y, int point);
      void setTileID(int x, int y, int value);
      void setPoint(int x, int y, int point, int value);
      void setTileHeight(int x, int y, int value);
      void setTileAreaHeight(int x, int y, int value, int area_x, int area_);
      void setTileCircleAreaHeight(int x, int y, int value, int area);
      void setTileCircleAreaID(int x, int y, int value, int area);
      Color getPointColor(int x, int y, int point);

   };

 }

 #endif
