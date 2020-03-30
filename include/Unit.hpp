#ifndef RTS_UNIT
#define RTS_UNIT

#define TEAM_RED    0
#define TEAM_BLUE   1
#define TEAM_GREEN  2
#define TEAM_YELLOW 3

#include <SFML/Graphics.hpp>
#include "GameManager.hpp"

using namespace sf;
using namespace std;

namespace RTS{

    class Unit{

    protected:
      GameManager*   gameManager;
      Sprite         texture;
      int            position_x;
      int            position_y;
      int            health_cur;
      int            health_max;
      int            teamtag;
      string         nametag;

    public:
      Unit(GameManager*, int, int, int);
      virtual ~Unit();

      void setTexture(Texture*);
      void resetHealth(int);

      virtual void tick() = 0;
      virtual void draw() = 0;

   };

 }

 #endif
