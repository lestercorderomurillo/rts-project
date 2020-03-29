#ifndef RTS_GAME_SCENE_WORLD_GRID_RENDERER
#define RTS_GAME_SCENE_WORLD_GRID_RENDERER

#include <SFML/Graphics.hpp>
#include "GameManager.hpp"
#include "scenes/WorldScene/Grid.hpp"
#include "scenes/WorldScene/Camera.hpp"

using namespace std;
using namespace sf;

namespace RTS{

    class GridRendering : public Drawable, public Transformable{

    private:
        GameManager* gameManager;
        Camera*      camera;
        Grid*        grid;

        VertexArray  gl_vertexes;
        Vertex*      gl_vertexfx;
        Texture      gl_texture;

    public:
      GridRendering(GameManager*, Grid*, Camera*);

      void tick();
      virtual void draw(RenderTarget&, RenderStates) const;
      
   };

 }

 #endif
