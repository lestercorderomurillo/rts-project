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
        Grid*        grid;

        VertexArray  gl_vertexes;
        Texture      gl_texture;

    public:
      GridRendering(GameManager* ptr);

      void tick();
      virtual void draw(RenderTarget& gl_target, RenderStates gl_states) const;
      

   };

 }

 #endif
