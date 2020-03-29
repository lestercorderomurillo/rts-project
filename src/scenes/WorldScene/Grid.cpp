#include "scenes/WorldScene/Grid.hpp"

namespace RTS{

    Grid::Grid(){
       reset();
       setPoint(1,1,0,15);
    }

    void Grid::reset(){
      for(int x = 0; x < MAPSIZE; x++){
        for(int y = 0; y < MAPSIZE; y++){
          this->world_tile[x][y] = 0;
        }
      }

      for(int x = 0; x < (MAPSIZE+1)*(MAPSIZE+1); x++){
        for(int y = 0; y < (MAPSIZE+1)*(MAPSIZE+1); y++){
          this->world_grid[x][y] = 0;
        }
      }
    }

    int Grid::getTileID(int x, int y){
      return this->world_tile[x][y];
    }

    int Grid::getPoint(int x, int y, char p){
      switch(p){
        case 0: return this->world_grid[x+0][y+0]; break;
        case 1: return this->world_grid[x+1][y+0]; break;
        case 2: return this->world_grid[x+1][y+1]; break;
        case 3: return this->world_grid[x+0][y+1]; break;
      }
      return (-1);
    }

    void Grid::setTileID(int x, int y, int value){
      this->world_tile[x][y] = value;
    }

    void Grid::setPoint(int x, int y, char p, int value){
      switch(p){
        case 0: this->world_grid[x+0][y+0] = value; break;
        case 1: this->world_grid[x+1][y+0] = value; break;
        case 2: this->world_grid[x+1][y+1] = value; break;
        case 3: this->world_grid[x+0][y+1] = value; break;
      }
    }
   
 }