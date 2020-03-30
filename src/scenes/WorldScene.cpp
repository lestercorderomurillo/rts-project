#include "scenes/WorldScene.hpp"
#include "units/buildings/Woodcutter.hpp"

namespace RTS{

   WorldScene::WorldScene(GameManager* ptr) : Scene(ptr){
      this->grid          = new Grid();
      this->camera        = new Camera(this->gameManager->getWindow());
      this->debugging     = new BaseRendering(this->gameManager);
      this->gridRenderer  = new GridRendering(this->gameManager, this->grid, this->camera);

      this->dummy         = new Woodcutter(this->gameManager, this->camera, TEAM_RED, 10, 10);
      this->debugging->setTextColor(Color(255,255,255));
      this->debugging->setTextSize(14);
   }

   WorldScene::~WorldScene(){
      delete this->debugging;
      delete this->camera;
      delete this->gridRenderer;
      delete this->grid;
      delete this->dummy;
   }

   void WorldScene::tick(){
      this->camera->tick();
      this->gridRenderer->tick();
      this->dummy->tick();
   }

   void WorldScene::draw(){
      this->gameManager->getWindow()->draw(*(this->gridRenderer));
      this->dummy->draw();
      this->debugging->drawText("(" + to_string(this->camera->getX()) + ", " + to_string(this->camera->getY()) + ")", 20, 20, true);
   }

}
