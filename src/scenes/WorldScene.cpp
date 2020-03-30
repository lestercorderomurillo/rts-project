#include "scenes/WorldScene.hpp"
#include "Unit.hpp"

namespace RTS{

   WorldScene::WorldScene(GameManager* ptr) : Scene(ptr){
      this->grid          = new Grid();
      this->camera        = new Camera(this->gameManager->getWindow());
      this->debugging     = new BaseRendering(this->gameManager);
      this->gridRenderer  = new GridRendering(this->gameManager, this->grid, this->camera);
      /*this->grid->setTileCircleAreaHeight(8, 8, 5, 5);
      this->grid->setTileCircleAreaHeight(8, 8, 10, 4);
      this->grid->setTileCircleAreaHeight(8, 8, 15, 3);
      this->grid->setTileCircleAreaID(8, 8, 1, 5);*/

      Unit dummy(this->gameManager);
   }

   WorldScene::~WorldScene(){
      delete this->debugging;
      delete this->camera;
      delete this->gridRenderer;
      delete this->grid;
   }

   void WorldScene::tick(){
      this->camera->tick();
      this->gridRenderer->tick();
   }

   void WorldScene::draw(){
      debugging->setTextColor(Color(255,255,255));
      debugging->setTextSize(14);
      debugging->drawText("(" + to_string(this->camera->getX()) + ", " + to_string(this->camera->getY()) + ")", 20, 20, true);
      this->gameManager->getWindow()->draw(*this->gridRenderer);
   }

}
