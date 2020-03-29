#include <SFML/Graphics.hpp>
#include "rendering/GridRendering.hpp"

using namespace std;
using namespace sf;

namespace RTS{

    GridRendering::GridRendering(GameManager* ptr){
      this->gameManager = ptr;
    }

    void GridRendering::tick(){

    }

    void GridRendering::draw(RenderTarget& gl_target, RenderStates gl_states) const{
        gl_states.transform *= getTransform();
        gl_states.texture    = &gl_texture;
        gl_target.draw(gl_vertexes, gl_states);
    }

   

 }