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
#include "rendering/BaseRendering.hpp"

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
     this->currentScene = new WorldScene(this->gameManager);

     this->gameManager->getLogger()->out("Working Directory: " + getWorkingDirectory());

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
     this->gameManager->getBatch()->addFont(0, getWorkingDirectory() + "/assets/fonts/common.ttf");
     return (this->gameManager->getBatch()->numErrors() == 0);
   }

   void GameEngine::runGameLoop(){

     Event event;

     BaseRendering test_prof(this->gameManager);
     test_prof.setTextColor(Color(255,255,255));
     test_prof.setTextSize(18);

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
        //this->currentScene->tick();
        //this->currentScene->draw();
        test_prof.drawText("prueba de funcionamiento", 20, 20, true);

        this->gameManager->getWindow()->display();

      }

   }

}

int main(){
  RTS::GameEngine game;
  return 0;
}
