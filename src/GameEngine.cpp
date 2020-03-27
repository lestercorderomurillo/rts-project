#include "GameEngine.hpp"
#include "scenes/WorldScene.hpp"

namespace RTS{

   GameEngine::GameEngine(){

     this->gameManager = new GameManager();
     this->currentScene = new WorldScene(this->gameManager);

     if (fetchResources()){
        runGameLoop();
     }else{
       this->gameManager->getLogger()->out(2, "Error while loading resources.");
     }

   }

   GameEngine::~GameEngine(){
     delete this->gameManager;
   }

   int GameEngine::fetchResources(){
     return 1;
   }

   void GameEngine::runGameLoop(){

     Event event;

     while (this->gameManager->getWindow()->isOpen()){

        while (this->gameManager->getWindow()->pollEvent(event)){

          if (event.type == Event::Closed){
            this->gameManager->getWindow()->close();
          }

          if (event.type == sf::Event::Resized){
            this->gameManager->getLogger()->out("Window has been resized.");
            View renewset;
            renewset.setSize(event.size.width, event.size.height);
            this->gameManager->getWindow()->setView(renewset);
          }

        }

        this->gameManager->getWindow()->clear(Color(32,32,32));
        this->currentScene->tick();
        this->currentScene->draw();
        this->gameManager->getWindow()->display();

      }

   }

}

int main(){
  RTS::GameEngine game;
  return 0;
}
