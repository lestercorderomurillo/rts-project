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
      GameManager*      game_manager;
      Camera*                 camera;

      Sprite                 texture;
      
      float               position_x;
      float               position_y;
      float           health_current;
      float           health_maximum;
      float             health_regen;
      int                    teamtag;
      string                 nametag;

      int           texture_offset_x;
      int           texture_offset_y;
      Vector2f      texture_position;

    public:

      static bool shadow_render_flag;
      
      struct SortByPosition{
        bool operator()(Unit* unit_left, Unit* unit_right){
          return ((unit_left->getPosition().x + unit_left->getPosition().y)
              <  (unit_right->getPosition().x + unit_right->getPosition().y));
        }
      };

      Unit(GameManager* gm_ptr, Camera* cam_ptr, int team, int x, int y, string name);
      virtual ~Unit();
      void setTexture(Texture* texture_ptr);
      void resetHealth(int value, float regen);
      void resetOffset(int offset_x, int offset_y);
      Sprite* getSprite();

      virtual void tick() = 0;
      virtual void draw() = 0;

      Vector2f getPosition();
      int      getCurrentHealth();

      // move to utils...
      float getPercentage(float value, float total);
      int round10(int value, int roundfactor);
      float clamp(float minvalue, float maxvalue, float value);

   };

 }

 #endif
