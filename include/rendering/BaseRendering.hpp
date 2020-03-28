#ifndef RTS_RENDERING_BASE
#define RTS_RENDERING_BASE

#include <SFML/Graphics.hpp>
#include "GameManager.hpp"
#include <string>

using namespace sf;
using namespace std;

namespace RTS{

    class BaseRendering{
        
    private:

        GameManager* gmptr;
        FloatRect    r_bounds;
        Text         r_text;
        Color        p_textColor;
        int          p_textSize;

    public:

      BaseRendering(GameManager*);
      void setTextColor(Color);
      void setTextSize(int);
      void drawText(string, int, int, bool);

   };

 }

 #endif
