#include "Unit.hpp"

namespace RTS{

  Unit::Unit(GameManager* ptr, Camera* c, int t, int x, int y){
    this->gameManager = ptr;
    this->camera      = c;
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

  void Unit::resetOffset(int ox, int oy){
    this->texture_offset_x = ox;
    this->texture_offset_y = oy;

  }

  Sprite* Unit::getSprite(){
    return &(this->texture);

  }

  void Unit::setTexture(Texture* txt){
    this->texture = Sprite(*txt);
  }

 }