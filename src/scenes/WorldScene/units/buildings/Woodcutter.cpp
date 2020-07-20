#include "scenes/WorldScene/units/buildings/Woodcutter.hpp"

namespace RTS{

  Woodcutter::Woodcutter(GameManager* gm_ptr, Camera* cam_ptr, int team, int x, int y) : 
  Building(gm_ptr, cam_ptr, team, x, y){

    this->setBasementTexture(this->game_manager->getBatch()->getTexture(1));
    this->setTexture(        this->game_manager->getBatch()->getTexture(2));
    
    this->setShadow(Vector2f(160, 232), Vector2f(340, 324), Vector2f(443, 271), Vector2f(263, 182), .5f, 60);

    this->getSprite()->setScale(.5f, .5f);
    this->getBasementSprite()->setScale(.5f, .5f);

    this->resetOffset(-30, 20);

    this->resetHealth(3000);
    this->initBuild();
  }

  Woodcutter::~Woodcutter(){

  }
  
}
