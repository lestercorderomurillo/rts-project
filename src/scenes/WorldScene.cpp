#include "scenes/WorldScene.hpp"

namespace RTS{

   WorldScene::WorldScene(GameManager* ptr) : Scene(ptr){
      this->debugging       = new BaseRendering(this->gameManager);
      //this->gridRenderer    = new GridRendering(this->gameManager);
      this->camera          = new Camera(this->gameManager->getWindow());
      this->refresh_tilemap = true;
   }

   WorldScene::~WorldScene(){
      delete this->debugging;
      delete this->camera;
      //delete this->gridRenderer;
   }

   void WorldScene::tick(){
      this->camera->tick();
      if(this->refresh_tilemap){
         this->refresh_tilemap = false;
         //this->gridRenderer->tick();
      }
   }

   void WorldScene::draw(){
      debugging->setTextColor(Color(255,255,255));
      debugging->setTextSize(18);
      debugging->drawText("(" + to_string(this->camera->getX()) + ", " + to_string(this->camera->getY()) + ")", 20, 20, true);
      //this->gameManager->getWindow()->draw(*this->gridRenderer);
   }

}
