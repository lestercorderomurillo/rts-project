#include "scenes/WorldScene/Unit.hpp"

namespace RTS{

  bool Unit::shadow_render_flag = true;

  Unit::Unit(GameManager* gm_ptr, Camera* cam_ptr, int team, int x, int y, string name){
    this->game_manager = gm_ptr;
    this->camera      = cam_ptr;
    this->teamtag     = team;
    this->nametag     = name;
    this->position_x  = x;
    this->position_y  = y;
    this->game_manager->getLogger()->out(this->nametag + " has been spawned. (" + to_string(x) + ", " + to_string(y) + ")");
  }

  Unit::~Unit(){
    this->game_manager->getLogger()->out(this->nametag + " has been killed.");
  }

  void Unit::resetHealth(int value, float regen){
    this->health_maximum = value;
    this->health_current = value;
    this->health_regen   = regen;
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

  Vector2f Unit::getPosition(){
    return Vector2f(position_x, position_y);
  }

  int Unit::getCurrentHealth(){
    return this->health_current;
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