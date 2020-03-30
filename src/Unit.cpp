#include "Unit.hpp"

namespace RTS{

  Unit::Unit(GameManager* ptr, int t, int x, int y){
    this->gameManager = ptr;
    this->teamtag     = t;
    this->position_x  = x;
    this->position_y  = y;
    this->gameManager->getLogger()->out("Unit has been spawned.");
  }

  Unit::~Unit(){
    this->gameManager->getLogger()->out("Unit has been killed.");
  }

  void Unit::resetHealth(int h){
    this->health_max = h;
    this->health_cur = h;
  }

  void Unit::setTexture(Texture* txt){
    this->texture = Sprite(*txt);
  }

 }