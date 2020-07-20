//#define WINDOWS
#ifdef WINDOWS
  #include <direct.h>
#else
  #include <libgen.h>
  #include <unistd.h>
#endif

#include <string>
#include "GameEngine.hpp"
#include "scenes/WorldScene.hpp"

using namespace std;

namespace RTS{

    string GameEngine::getWorkingDirectory() {
      char result[1000];
      ssize_t count = readlink("/proc/self/exe", result, 1000);
      const char *path;

      if (count != -1) {
          path = dirname(result);
      }

      string strFormat(path);
      return strFormat;
    }

   GameEngine::GameEngine(){

     this->game_manager = new GameManager();
     
     this->game_manager->getLogger()->out("Working Directory: " + getWorkingDirectory());

     if (fetchResources()){
        this->current_scene = new WorldScene(this->game_manager);
        runGameLoop();
     }else{
        this->game_manager->getLogger()->out(2, "Error while loading resources.");
     }

   }

   GameEngine::~GameEngine(){
     delete this->game_manager;
     delete this->current_scene;
   }

   int GameEngine::fetchResources(){
      this->game_manager->getBatch()->addFont(0, getWorkingDirectory() + "/assets/fonts/common.ttf");
      this->game_manager->getBatch()->addTexture(0, getWorkingDirectory() + "/assets/images/tiles.png");
      this->game_manager->getBatch()->addTexture(1, getWorkingDirectory() + "/assets/images/woodcutter_basement.png");
      this->game_manager->getBatch()->addTexture(2, getWorkingDirectory() + "/assets/images/woodcutter_full.png");
      return (this->game_manager->getBatch()->numErrors() == 0);
   }

   void GameEngine::runGameLoop(){

     Event event;
     
     while (this->game_manager->getWindow()->isOpen()){

        while (this->game_manager->getWindow()->pollEvent(event)){

          if (event.type == Event::Closed){
            this->game_manager->getWindow()->close();
          }

          if (event.type == sf::Event::Resized){
            this->game_manager->getLogger()->out("Window has been resized.");
            View renewset;
            renewset.setSize(event.size.width, event.size.height);
            this->game_manager->getWindow()->setView(renewset);
          }

        }

        this->game_manager->getWindow()->clear(Color(32,32,32));
        this->current_scene->tick();
        this->current_scene->draw();

        this->game_manager->getWindow()->display();

      }

   }

}

int main(){
  RTS::GameEngine game;
  return 0;
}
