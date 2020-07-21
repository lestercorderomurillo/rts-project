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

      bool         renderDebug;
      GridRendering(GameManager* gm_ptr, Grid* grid_ptr, Camera* cam_ptr);

      void tick();
      virtual void draw(RenderTarget& gl_target, RenderStates gl_states) const;
      
   };

 }

 #endif
