#ifndef RTS_UNIT
#define RTS_UNIT

#define TEAM_RED    0
#define TEAM_BLUE   1
#define TEAM_GREEN  2
#define TEAM_YELLOW 3

#include <SFML/Graphics.hpp>
#include "GameManager.hpp"

#include "scenes/WorldScene/Camera.hpp"

using namespace sf;
using namespace std;

namespace RTS{

    class Unit{

    protected:
      GameManager*   game_manager;
      Camera*        camera;

      Sprite         texture;
      
      int            position_x;
      int            position_y;
      int            health_current;
      int            health_maximum;
      int            teamtag;
      string         nametag;

      int            texture_offset_x;
      int            texture_offset_y;
      Vector2f       texture_position;

    public:
      Unit(GameManager* gm_ptr, Camera* cam_ptr, int team, int x, int y);
      virtual ~Unit();
      void setTexture(Texture* texture_ptr);
      void resetHealth(int value);
      void resetOffset(int offset_x, int offset_y);
      float getPercentage(float value, float total);
      Sprite* getSprite();

      virtual void tick() = 0;
      virtual void draw() = 0;

      int round10(int value, int roundfactor);
      float clamp(float minvalue, float maxvalue, float value);

   };

 }

 #endif
