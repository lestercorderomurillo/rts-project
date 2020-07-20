#include "scenes/WorldScene.hpp"
#include "scenes/WorldScene/units/buildings/Woodcutter.hpp"

namespace RTS{

   WorldScene::WorldScene(GameManager* ptr) : Scene(ptr){
      this->grid          = new Grid();
      this->camera        = new Camera(this->game_manager->getWindow());
      this->free_renderer  = new BaseRendering(this->game_manager);
      this->grid_renderer  = new GridRendering(this->game_manager, this->grid, this->camera);
      this->free_renderer->setTextColor(Color(255,255,255));
      this->free_renderer->setTextSize(14);


      this->stored_buildings.push_front(new Woodcutter(this->game_manager, this->camera, TEAM_RED, 10, 10));

      //this->dummy = new Woodcutter(this->gameManager,this->camera, TEAM_RED, 10, 10);
   }

   WorldScene::~WorldScene(){
      delete this->free_renderer;
      delete this->camera;
      delete this->grid_renderer;
      delete this->grid;
      //delete this->dummy;
   }

   void WorldScene::tick(){
      this->camera->tick();
      this->grid_renderer->tick();
     // this->dummy->tick();
   }

   void WorldScene::draw(){
      this->game_manager->getWindow()->draw(*(this->grid_renderer));
     // this->dummy->draw();

      /*for(){

      }*/

      
      this->free_renderer->drawText("(" + to_string(this->camera->getX()) + ", " + to_string(this->camera->getY()) + ")", 20, 20, true);
   }

}
