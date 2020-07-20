#ifndef RTS_BUILDING
#define RTS_BUILDING

#include "scenes/WorldScene/Unit.hpp"

namespace RTS{

    class Building : public Unit{
    protected:
      RectangleShape   healthbar_background;
      RectangleShape      healthbar_current;

      ConvexShape              shadow_shape;
      Vector2f             shadow_points[4];    

      int                     workers_on_me;  
      int                     shadow_spread;

      Sprite               basement_texture;

    public:
      Building(GameManager* gm_ptr, Camera* cam_ptr, int team, int x, int y);
      ~Building();

      void setBasementTexture(Texture* texture_ptr);
      void setShadow(Vector2f p1, Vector2f p2 ,Vector2f p3, Vector2f p4, float scale, float spread);

      void renderShadow();
      void renderSprite();
      void renderHealthbar();

      Sprite* getBasementSprite();


      void presetTick();
      void presetDraw();

      virtual void tick();
      virtual void draw();

      void initBuild();

   };

 }

 #endif
