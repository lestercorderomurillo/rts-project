#include "units/buildings/Woodcutter.hpp"

namespace RTS{

  Woodcutter::Woodcutter(GameManager* ptr, int t, int x, int y) : Building(ptr, t, x, y){
    this->setTexture(this->gameManager->getBatch()->getTexture(1));
  }

  Woodcutter::~Woodcutter(){

  }
}
