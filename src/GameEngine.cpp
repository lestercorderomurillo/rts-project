//#define WINDOWS
#ifdef WINDOWS
  #include <direct.h>
  #define GetCurrentDir _getcwd
#else
  #include <unistd.h>
  #define GetCurrentDir getcwd
#endif

#include <string>
#include "GameEngine.hpp"
#include "scenes/WorldScene.hpp"

using namespace std;

namespace RTS{

    string GameEngine::getWorkingDirectory() {
      char chrArray[FILENAME_MAX];
      GetCurrentDir(chrArray,FILENAME_MAX);
      string strFormat(chrArray);
      return strFormat;
    }

   GameEngine::GameEngine(){

     this->gameManager = new GameManager();
     
     this->gameManager->getLogger()->out("Working Directory: " + getWorkingDirectory());

     if (fetchResources()){
        this->currentScene = new WorldScene(this->gameManager);
        runGameLoop();
     }else{
        this->gameManager->getLogger()->out(2, "Error while loading resources.");
     }

   }

   GameEngine::~GameEngine(){
     delete this->gameManager;
   }

   int GameEngine::fetchResources(){
      this->gameManager->getBatch()->addFont(0, getWorkingDirectory() + "/assets/fonts/common.ttf");
      this->gameManager->getBatch()->addTexture(0, getWorkingDirectory() + "/assets/images/tiles.png");
      this->gameManager->getBatch()->addTexture(1, getWorkingDirectory() + "/assets/images/woodcutter_basement.png");
      this->gameManager->getBatch()->addTexture(2, getWorkingDirectory() + "/assets/images/woodcutter_full.png");
      return (this->gameManager->getBatch()->numErrors() == 0);
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
