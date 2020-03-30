#include "units/buildings/Woodcutter.hpp"

namespace RTS{

  Woodcutter::Woodcutter(GameManager* ptr, Camera* c, int t, int x, int y) : Building(ptr, c, t, x, y){
    this->setTexture(this->gameManager->getBatch()->getTexture(2));
    this->setShadow(Vector2f(160, 232), Vector2f(340, 324), Vector2f(443, 271), Vector2f(263, 182), .5f);
    this->getSprite()->setScale(.5f, .5f);
    this->resetOffset(-30, 20);
  }

  Woodcutter::~Woodcutter(){

  }
  
}
