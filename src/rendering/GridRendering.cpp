#include <SFML/Graphics.hpp>
#include "scenes/WorldScene/Grid.hpp"
#include "rendering/GridRendering.hpp"
using namespace std;
using namespace sf;

namespace RTS{

    GridRendering::GridRendering(GameManager* gm_ptr, Grid* grid_ptr, Camera* cam_ptr){
      this->gameManager = gm_ptr;
      this->grid        = grid_ptr;
      this->camera      = cam_ptr;
      this->renderDebug = false;
      this->gl_texture  = *this->gameManager->getBatch()->getTexture(0);
    }

    void GridRendering::tick(){

        this->gl_vertexes.setPrimitiveType(Quads);
        this->gl_vertexes.resize(MAPSIZE * MAPSIZE * 4);

        int cx = this->camera->getX() + 100;
        int cy = this->camera->getY() + 100;

        for(int x = 0; x < MAPSIZE; x++){
          for(int y = 0; y < MAPSIZE; y++){

              int fx = cx + ((x - y) * (TILEW/2));
              int fy = cy + ((x + y) * (TILEH/2));

              this->gl_vertexfx = &gl_vertexes[((MAPSIZE * y) + x) * 4];

              int tile = this->grid->getTileID(x,y);
              if(this->renderDebug){
                tile = 0;
              }
              int tx = tile % (gl_texture.getSize().x / TILEW);
              int ty = tile / (gl_texture.getSize().x / TILEW);

              this->gl_vertexfx[0].position = Vector2f(fx , fy - this->grid->getPoint(x, y, 0));
              this->gl_vertexfx[1].position = Vector2f(fx + (TILEW / 2), fy + (TILEH / 2) - this->grid->getPoint(x, y, 1));
              this->gl_vertexfx[2].position = Vector2f(fx , fy + TILEH - this->grid->getPoint(x, y, 2));
              this->gl_vertexfx[3].position = Vector2f(fx - (TILEW / 2), fy + (TILEH / 2) - this->grid->getPoint(x, y, 3));

              this->gl_vertexfx[0].texCoords = Vector2f((tx+0) * (TILEW+1), (ty+0) * (TILEW+2));
              this->gl_vertexfx[1].texCoords = Vector2f((tx+1) * (TILEW-1), (ty+0) * (TILEW+2));
              this->gl_vertexfx[2].texCoords = Vector2f((tx+1) * (TILEW-1), (ty+1) * (TILEW-2));
              this->gl_vertexfx[3].texCoords = Vector2f((tx+0) * (TILEW+1), (ty+1) * (TILEW-2));

              for(int c = 0; c<4 ;c++){
                this->gl_vertexfx[c].color = this->grid->getPointColor(x, y, c);
                if(tile == 0 && !this->renderDebug){
                  this->gl_vertexfx[c].color = Color::Transparent;
                }
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