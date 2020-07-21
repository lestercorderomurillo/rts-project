#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstddef>
#include <stdlib.h>
#include "managed/ResourceBatch.hpp"

using namespace sf;
using namespace std;

namespace RTS{

    ResourceBatch::ResourceBatch(LogSystem* ptr){
      this->output = ptr;
      this->errorCounter = 0;
    }

    ResourceBatch::~ResourceBatch(){
    }
    

    void ResourceBatch::addTexture(int storeTo, string path){
      {
        ErrBlock outlock;
        if (!textures[storeTo].loadFromFile(path)){
          this->errorCounter++;
          this->output->out(2, "Error while loading '"  + path.substr((size_t)(path.find("images"))) + "'");
        }else{
          textures[storeTo].setSmooth(false);
        }
      }
    }

    void ResourceBatch::addFont(int storeTo, string path){
      {
        ErrBlock outlock;
        if (!fonts[storeTo].loadFromFile(path)){
          this->errorCounter++;
          this->output->out(2, "Error while loading '"  + path.substr((size_t)(path.find("font"))) + "'");
        }
      }
      
    }

    Texture* ResourceBatch::getTexture(int from){
      return &(textures[from]);
    }

    Font* ResourceBatch::getFont(int from){
      return &(fonts[from]);
    }

    int ResourceBatch::numErrors(){
      return this->errorCounter;
    }

 }