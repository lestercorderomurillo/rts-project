#ifndef RTS_GAME_SCENE_WORLD_GRID_RENDERER
#define RTS_GAME_SCENE_WORLD_GRID_RENDERER
#include <SFML/Graphics.hpp>
#include "GameManager.hpp"

using namespace std;
using namespace sf;

namespace RTS{

    class GridRendering : public Drawable, public Transformable{

    private:
        GameManager* gameManager;
        VertexArray  gl_vertexes;
        Texture      gl_texture;

    public:
      GridRendering(GameManager* ptr);

      void tick();
      virtual void draw(RenderTarget& gl_target, RenderStates gl_states) const;
      /*virtual void draw(RenderTarget& gl_target, RenderStates gl_states) const{
        gl_states.transform *= getTransform();
        gl_states.texture    = &gl_texture;
        gl_target.draw(gl_vertexes, gl_states);
      }*/

   };

 }

 #endif
