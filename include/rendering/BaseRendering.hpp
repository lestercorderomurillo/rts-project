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

        GameManager*       gmptr;
        FloatRect       r_bounds;
        Text              r_text;
        Color        p_textColor;
        int           p_textSize;

    public:

      BaseRendering(GameManager* gm_ptr);
      void setTextColor(Color color);
      void setTextSize(int size);
      void drawText(string value, int x, int y, bool relative);

   };

 }

 #endif
