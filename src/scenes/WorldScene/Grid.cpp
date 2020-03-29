using namespace sf;

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

      int setTileID(int, int);
      int setPoint(int, int, char);

   };

 }

 #endif
