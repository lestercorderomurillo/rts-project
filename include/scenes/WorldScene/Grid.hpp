#ifndef RTS_GAME_SCENE_WORLD_GRID
#define RTS_GAME_SCENE_WORLD_GRID

#define MAPSIZE 32
#define TILEW 48
#define TILEH 24

namespace RTS{

    class Grid{

    private:
        int world_tile[MAPSIZE][MAPSIZE];
        int world_grid[(MAPSIZE + 1)*(MAPSIZE + 1)][(MAPSIZE + 1)*(MAPSIZE + 1)];

    public:
      Grid();
      void reset();
      int getTileID(int, int);
      int getPoint(int, int, char);
      int getMapSize();
      int getTileWidth();
      int getTileHeight();
      void setTileID(int, int, int);
      void setPoint(int, int, char, int);

   };

 }

 #endif
