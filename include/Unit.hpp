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
      GameManager*   gameManager;
      Camera*        camera;
      Sprite         texture;
      int            position_x;
      int            position_y;
      int            health_cur;
      int            health_max;
      int            teamtag;
      string         nametag;

      int            texture_offset_x;
      int            texture_offset_y;
      Vector2f       texture_position;

    public:
      Unit(GameManager*, Camera*, int, int, int);
      virtual ~Unit();

      void setTexture(Texture*);
      void resetHealth(int);
      void resetOffset(int, int);

      Sprite* getSprite();

      virtual void tick() = 0;
      virtual void draw() = 0;

   };

 }

 #endif
