#include <SFML/Graphics.hpp>
#include "rendering/GridRendering.hpp"
#define MAPSIZE 8
#define TILEW 48
#define TILEH 24

using namespace std;
using namespace sf;

namespace RTS{

    GridRendering::GridRendering(GameManager* ptr){
      this->gameManager = ptr;
    }

    void GridRendering::tick(){

        this->gl_vertexes.setPrimitiveType(Quads);
        this->gl_vertexes.resize(MAPSIZE * MAPSIZE * 4);

        Vertex* quad = &gl_vertexes[0];
        int cx = 100;
        int cy = 100;
        quad[0].position = Vector2f(cx , cy );
        quad[1].position = Vector2f(cx + (TILEW / 2), cy + (TILEH / 2));
        quad[2].position = Vector2f(cx , cy + TILEH);
        quad[3].position = Vector2f(cx - (TILEW / 2), cy + (TILEH / 2));

        quad[0].color = Color(190, 222, 145);
        quad[1].color = Color(190, 222, 145);
        quad[2].color = Color(190, 222, 145);
        quad[3].color = Color(190, 222, 145);

        for(unsigned int fc = 0; fc < 4; fc++){
          Vector2f fp = this->gameManager->getWindow()->mapPixelToCoords(Vector2i(quad[fc].position.x,quad[fc].position.y));
          quad[fc].position = fp;
        }
        
        
        
    }

    void GridRendering::draw(RenderTarget& gl_target, RenderStates gl_states) const{
        gl_states.transform *= getTransform();
        gl_states.texture    = &gl_texture;
        gl_target.draw(gl_vertexes, gl_states);
    }

   

 }