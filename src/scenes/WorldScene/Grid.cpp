#include "scenes/WorldScene/Grid.hpp"

namespace RTS{

    Grid::Grid(){
       reset();
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
      this->updateLighting();
    }

    void Grid::updateLighting(){
      for(int x = 0; x < (MAPSIZE+1)*(MAPSIZE+1); x++){
        for(int y = 0; y < (MAPSIZE+1)*(MAPSIZE+1); y++){
          this->world_lite[x][y] = Color(230,230,230);
        }
      }

      for(int x = 1; x < (MAPSIZE+1)*(MAPSIZE+1) -1; x++){
        for(int y = 1; y < (MAPSIZE+1)*(MAPSIZE+1) -1; y++){
          if((this->world_grid[x][y] > this->world_grid[x+1][y]) || (this->world_grid[x][y] > this->world_grid[x][y-1])){
            this->world_lite[x][y] = Color(200,200,200);
          }

          if((this->world_grid[x][y] > this->world_grid[x-1][y]) || (this->world_grid[x][y] > this->world_grid[x][y+1])){
            this->world_lite[x][y] = Color(255,255,255);
          }
        }
      }
    }

    int Grid::getTileID(int x, int y){
      return this->world_tile[x][y];
    }

    int Grid::getPoint(int x, int y, int p){
      if(x < 0 || x == MAPSIZE || y < 0 || y == MAPSIZE){
        return 0;
      }
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

    void Grid::setPoint(int x, int y, int p, int value){
      switch(p){
        case 0: this->world_grid[x+0][y+0] = value; break;
        case 1: this->world_grid[x+1][y+0] = value; break;
        case 2: this->world_grid[x+1][y+1] = value; break;
        case 3: this->world_grid[x+0][y+1] = value; break;
      }
      this->updateLighting();
    }

    void Grid::setTileHeight(int x, int y, int value){
      this->world_grid[x+0][y+0] = value;
      this->world_grid[x+1][y+0] = value;
      this->world_grid[x+1][y+1] = value;
      this->world_grid[x+0][y+1] = value; 
      this->updateLighting();
    }

    void Grid::setTileAreaHeight(int x, int y, int value, int area){
      for(int xx = 0; xx < MAPSIZE; xx++){
        for(int yy = 0; yy < MAPSIZE; yy++){
          this->setTileHeight(x + xx, y + yy, value);
        }
      }
    }

    void Grid::setTileCircleAreaHeight(int a, int b, int value, int area){
      for(int x = 0; x < MAPSIZE; x++){
        for(int y = 0; y < MAPSIZE; y++){

         if ( ( pow((x-a),2) + pow((y-b),2) - pow(area,2) ) < pow(EPSILON,2)){
          this->setTileHeight(x, y, value);
         }

        }
      }
      this->updateLighting();
    }

    void Grid::setTileCircleAreaID(int a, int b, int value, int area){

      for(int x = 0; x < MAPSIZE; x++){
        for(int y = 0; y < MAPSIZE; y++){

         if ( ( pow((x-a),2) + pow((y-b),2) - pow(area,2) ) < pow(EPSILON,2)){
          this->setTileID(x, y, value);
         }

        }
      }

    }


    Color Grid::getPointColor(int x, int y, int p){
      switch(p){
        case 0: return this->world_lite[x+0][y+0]; break;
        case 1: return this->world_lite[x+1][y+0]; break;
        case 2: return this->world_lite[x+1][y+1]; break;
        case 3: return this->world_lite[x+0][y+1]; break;
      }
      return Color(255,255,255);
    }
   
 }