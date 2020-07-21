//#define WINDOWS
#ifdef WINDOWS
  #define _S "/"
#else
  #include <libgen.h>
  #include <unistd.h>
  #define _S "/"
#endif

#include <typeinfo>
#include <typeindex>
#include <thread>
#include <string>
#include "GameEngine.hpp"
#include "scenes/WorldScene.hpp"
using namespace std;

string homepath;

namespace RTS{

  int GameEngine::current_fpsec_hr = 0;
  int GameEngine::current_fpsec_lr = 0;
  float GameEngine::current_delta  = 0;
  bool GameEngine::gameIsRunning   = true;

  void thread_fps_sync(){
    while(GameEngine::gameIsRunning){
      GameEngine::current_fpsec_lr = GameEngine::current_fpsec_hr;
      sleep(1);
    }
  }

#ifdef WINDOWS
  string GameEngine::getWorkingDirectory() {
    int pos = homepath.find_last_of("/\\");
    return homepath.substr(0, pos);
  }
#else
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
#endif

  GameEngine::GameEngine(){

    this->game_manager = new GameManager();
    this->current_scene = nullptr;
    this->game_manager->getLogger()->out("Running at: " + getWorkingDirectory());

    if (fetchResources()){

      this->game_manager->getLogger()->out("All game assets loaded.");
      this->game_manager->getLogger()->out("Success! Engine started.");
      
      std::thread th_fps_meter(thread_fps_sync);

      this->current_scene = new WorldScene(this->game_manager);
      runGameLoop();

      th_fps_meter.join();
    }else{
      this->game_manager->getLogger()->out(2, "Aborting game...");
    }

  }

  GameEngine::~GameEngine(){
    if(this->current_scene != nullptr){
      delete this->current_scene;
    }
    delete this->game_manager;
  }

  int GameEngine::fetchResources(){
    this->game_manager->getLogger()->out("Resolving game assets...");
    this->game_manager->getBatch()->addFont(0,    getWorkingDirectory() + _S + "assets" + _S + "fonts" + _S + "common.ttf");
    this->game_manager->getBatch()->addTexture(0, getWorkingDirectory() + _S + "assets" + _S + "images" + _S + "tiles.png");
    this->game_manager->getBatch()->addTexture(1, getWorkingDirectory() + _S + "assets" + _S + "images" + _S + "woodcutter_basement.png");
    this->game_manager->getBatch()->addTexture(2, getWorkingDirectory() + _S + "assets" + _S + "images" + _S + "woodcutter_full.png");
    return (this->game_manager->getBatch()->numErrors() == 0);
  }

  int GameEngine::getInternalFramesPerSecond(){
    return GameEngine::current_fpsec_lr;
  }

  void GameEngine::runGameLoop(){

    Event event;
    Clock clock;

    float lastTime    = 0;
    float currentTime = 0;

    Time clockTime;
     
    while (this->game_manager->getWindow()->isOpen()){

      clockTime                    = clock.restart();
      GameEngine::current_delta    = clockTime.asSeconds();
      currentTime                  = clockTime.asSeconds();
      GameEngine::current_fpsec_hr = (int)(1.f / (currentTime));
      lastTime                     = currentTime;
     
      while (this->game_manager->getWindow()->pollEvent(event)){

        if (event.type == Event::Closed){
          GameEngine::gameIsRunning = false;
          this->game_manager->getWindow()->close();
        }

        if (event.type == sf::Event::Resized){
          View renewset;
          renewset.setSize(event.size.width, event.size.height);
          this->game_manager->getWindow()->setView(renewset);
        }
        
        this->current_scene->tickEvent(&event);
        
      }

      this->current_scene->tick();

      this->game_manager->getWindow()->clear(Color(32,32,32));
      this->current_scene->draw();
      this->game_manager->getWindow()->display();

    }

  }

}

int main(int argc, char* argv[]){
  homepath = string(argv[0]);
  RTS::GameEngine game;
  return 0;
}
