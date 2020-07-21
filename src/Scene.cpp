#include "Scene.hpp"

namespace RTS{

   Scene::Scene(GameManager* ptr){
     this->game_manager = ptr;
   }

   Scene::~Scene(){
   }

   void Scene::tick(){
   }

   void Scene::tickEvent(Event* eventHandler){
   }

   void Scene::draw(){
   }

}
