#include "scenes/WorldScene/Unit.hpp"

namespace RTS{

  Unit::Unit(GameManager* gm_ptr, Camera* cam_ptr, int team, int x, int y){
    this->game_manager = gm_ptr;
    this->camera      = cam_ptr;
    this->teamtag     = team;
    this->position_x  = x;
    this->position_y  = y;
    this->game_manager->getLogger()->out("Unit has been spawned.");
  }

  Unit::~Unit(){
    this->game_manager->getLogger()->out("Unit has been killed.");
  }

  void Unit::resetHealth(int value){
    this->health_maximum = value;
    this->health_current = value;
  }

  void Unit::resetOffset(int offset_x, int offset_y){
    this->texture_offset_x = offset_x;
    this->texture_offset_y = offset_y;

  }

  Sprite* Unit::getSprite(){
    return &(this->texture);
  }

  void Unit::setTexture(Texture* texture_ptr){
    texture_ptr->generateMipmap();
    this->texture = Sprite(*texture_ptr);
  }

  float Unit::getPercentage(float value, float total){
    return ((float)(value) / (float)(total))*100.0f;
  }

  int Unit::round10(int value, int roundfactor){
    int a = (value / roundfactor) * roundfactor; 
    int b = a + roundfactor; 
    return (value - a > b - value)? b : a; 
  }

  float Unit::clamp(float minvalue, float maxvalue, float value){
    return max(minvalue, min(value, maxvalue));
  }

 }