#include "GameEngine.hpp"
#include "managed/LogSystem.hpp"
#include "scenes/WorldScene.hpp"
#include "scenes/WorldScene/units/buildings/Woodcutter.hpp"

namespace RTS{

   WorldScene::WorldScene(GameManager* gm_ptr) : Scene(gm_ptr){
      this->grid           = new Grid();
      this->camera         = new Camera(this->game_manager->getWindow());
      this->free_renderer  = new BaseRendering(this->game_manager);
      this->grid_renderer  = new GridRendering(this->game_manager, this->grid, this->camera);
      this->free_renderer->setTextColor(Color(255,255,255));
      this->free_renderer->setTextSize(18);

      // Here, we need a map loader, who loads the map from a file
      spawnBuilding(new Woodcutter(this->game_manager, this->camera, TEAM_RED, 10, 10));

      this->grid->setTileCircleAreaID(14, 14, Grid::TILE_GRASS, 9);
      this->grid->setTileCircleAreaHeight(14, 14, 45, 5);

      scheduleDepthSort();
   }

   int WorldScene::spawnUnit(Unit* unit){
      int unitID = this->stored_units.size();
      if(unitID < _UNIT_LIMIT){
         this->stored_units.push_back(unit);
         return unitID;
      }
      this->game_manager->getLogger()->out(1, "Out of memory: spawn unit assert failed. ");
      return -1;
      
   }

   int WorldScene::spawnBuilding(Building* unit){
      int unitID = this->stored_buildings.size();
      if(unitID < _BUILDINGS_LIMIT){
         this->stored_buildings.push_back(unit);
         return unitID;
      }
      this->game_manager->getLogger()->out(1, "Out of memory: spawn building assert failed. ");
      return -1;
   }

   WorldScene::~WorldScene(){
      delete this->grid_renderer;
      delete this->free_renderer;
      delete this->camera;
      delete this->grid;

      while(!this->stored_buildings.empty()){
         auto del_ptr = this->stored_buildings.back();
         delete del_ptr;
         this->stored_buildings.pop_back();
      }

      while(!this->stored_units.empty()){
         auto del_ptr = this->stored_units.back();
         delete del_ptr;
         this->stored_units.pop_back();
      }
   }

   void WorldScene::tickEvent(Event* eventHandler){

      if (eventHandler->type == sf::Event::KeyPressed){
         switch(eventHandler->key.code){
            case sf::Keyboard::F2: 
               this->grid_renderer->renderDebug = !(this->grid_renderer->renderDebug);
            break;
            case sf::Keyboard::F4:
               Unit::shadow_render_flag = !(Unit::shadow_render_flag);
            break;
            default: break;
         }
      }
   }

   void WorldScene::tick(){

      this->camera->tick();
      this->grid_renderer->tick();

      list<Building*>::iterator it_build;
      for (it_build = this->stored_buildings.begin(); it_build != stored_buildings.end(); it_build++){
         (*it_build)->tick();
      }
      

      list<Unit*>::iterator it_unit;
      for (it_unit = this->stored_units.begin(); it_unit != stored_units.end(); it_unit++){
         (*it_unit)->tick();
      }

      if(update_depth_scheduled){
         executeDepthSort();
      }
   }

   void WorldScene::executeDepthSort(){
      this->update_depth_scheduled = false;
      this->stored_buildings.sort(Unit::SortByPosition());
      this->stored_units.sort(Unit::SortByPosition());
   }

   void WorldScene::scheduleDepthSort(){
      this->update_depth_scheduled = true;
   }

   void WorldScene::draw(){

      this->game_manager->getWindow()->draw(*(this->grid_renderer));

      list<Building*>::iterator it_build;
      for (it_build = this->stored_buildings.begin(); it_build != stored_buildings.end(); it_build++){
         (*it_build)->draw();
      }

      list<Unit*>::iterator it_unit;
      for (it_unit = this->stored_units.begin(); it_unit != stored_units.end(); it_unit++){
         (*it_unit)->draw();
      }

      this->free_renderer->drawText(PROJECTNAME, 20, 25 * 1, true);
      this->free_renderer->drawText("frames-per-second: " + to_string(GameEngine::getInternalFramesPerSecond()) + " | 60", 20, 25 * 2, true);
      this->free_renderer->drawText("delta-last-time: "  + to_string(GameEngine::current_delta), 20, 25 * 3, true);
      this->free_renderer->drawText("render-viewcoord-xy: " + to_string((int)(-this->camera->getX())) + " | " + to_string((int)(-this->camera->getY())), 20, 25 * 4, true);
      this->free_renderer->drawText("[F2] testfx-grid-enable: " + to_string(this->grid_renderer->renderDebug), 20, 25 * 5, true);
      this->free_renderer->drawText("[F3] fx-heightmap-enable: false", 20, 25 * 6, true);
      this->free_renderer->drawText("[F4] fx-shadow-enable: " + to_string(Unit::shadow_render_flag), 20, 25 * 7, true);
      this->free_renderer->drawText("[F5] fx-multitexturing-enable: false", 20, 25 * 8, true);
   }

}
