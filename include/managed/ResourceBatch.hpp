#ifndef RTS_BATCH
#define RTS_BATCH
#define MEMORY_SIZE 32

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstddef>
#include <stdlib.h>
#include "LogSystem.hpp"

using namespace sf;
using namespace std;

 namespace RTS{

    class ResourceBatch{
      
    private:

      LogSystem*  output;
      int         errorCounter;
      Font        fonts[MEMORY_SIZE];
      Texture     textures[MEMORY_SIZE];

    public:

      ResourceBatch(LogSystem*);
      ~ResourceBatch();

      void addTexture(int storeTo, string path);
      void addFont(int storeTo, string path);
      Texture* getTexture(int from);
      Font* getFont(int from);
      int numErrors();

   };

 }

 #endif
