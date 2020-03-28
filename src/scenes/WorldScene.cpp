#include "scenes/WorldScene.hpp"

namespace RTS{

   WorldScene::WorldScene(GameManager* ptr) : Scene(ptr){
      this->debugging = new BaseRendering(this->gameManager);
      this->camera    = new Camera(this->gameManager->getWindow());
   }

   WorldScene::~WorldScene(){
      delete this->debugging;
      delete this->camera;
   }

   void WorldScene::tick(){
      this->camera->tick();
   }

   void WorldScene::draw(){
     debugging->setTextColor(Color(255,255,255));
     debugging->setTextSize(18);
     debugging->drawText("(" + to_string(this->camera->getX()) + ", " + to_string(this->camera->getY()) + ")", 20, 20, true);

   }

}
