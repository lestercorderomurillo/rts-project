#include <SFML/Graphics.hpp>
#include "scenes/WorldScene/Grid.hpp"
#include "rendering/GridRendering.hpp"

using namespace std;
using namespace sf;

namespace RTS{

    GridRendering::GridRendering(GameManager* ptra, Grid* ptrb, Camera* ptrc){
      this->gameManager = ptra;
      this->grid        = ptrb;
      this->camera      = ptrc;
    }

    void GridRendering::tick(){

        this->gl_vertexes.setPrimitiveType(Quads);
        this->gl_vertexes.resize(this->grid->getMapSize() * this->grid->getMapSize() * 4);

        int cx = this->camera->getX() + 100;
        int cy = this->camera->getY() + 100;

        for(int x = 0; x < this->grid->getMapSize(); x++){
          for(int y = 0; y < this->grid->getMapSize(); y++){

              int fx = cx + ((x - y) * (this->grid->getTileWidth()/2));
              int fy = cy + ((x + y) * (this->grid->getTileHeight()/2));

              this->gl_vertexfx = &gl_vertexes[((this->grid->getMapSize() * y) + x) * 4];
              this->gl_vertexfx[0].position = Vector2f(fx , fy );
              this->gl_vertexfx[1].position = Vector2f(fx + (TILEW / 2), fy + (TILEH / 2));
              this->gl_vertexfx[2].position = Vector2f(fx , fy + TILEH);
              this->gl_vertexfx[3].position = Vector2f(fx - (TILEW / 2), fy + (TILEH / 2));

              for(int ci = 0; ci < 4; ci++){
                this->gl_vertexfx[ci].color = Color(190, 222, 145);
              }
              
              for(unsigned int fc = 0; fc < 4; fc++){
                Vector2f fp = this->gameManager->getWindow()->mapPixelToCoords(
                  Vector2i(this->gl_vertexfx[fc].position.x,
                          this->gl_vertexfx[fc].position.y
                          )
                  );
                this->gl_vertexfx[fc].position = fp;
              }
          }
        }
        
    }

    void GridRendering::draw(RenderTarget& gl_target, RenderStates gl_states) const{
        gl_states.transform *= getTransform();
        gl_states.texture    = &gl_texture;
        gl_target.draw(gl_vertexes, gl_states);
    }

   

 }