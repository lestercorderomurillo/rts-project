#include "GameManager.hpp"

namespace RTS{

   GameManager::GameManager(){
     
     ContextSettings glset;
     View            viewset;

     glset.antialiasingLevel = 8;
     viewset.setSize(1280, 720);
     viewset.setCenter(0, 0);

     this->logger = new LogSystem();
     this->window = new RenderWindow(VideoMode(1280, 720), "Project", Style::Default, glset);
     this->window->setFramerateLimit(60);
     this->window->setView(viewset);
     this->batch = new ResourceBatch(this->logger);

   }

   GameManager::~GameManager(){
     delete this->logger;
     delete this->window;
     delete this->batch;
   }

   LogSystem* GameManager::getLogger(){
     return this->logger;
   }

   RenderWindow* GameManager::getWindow(){
     return this->window;
   }

   ResourceBatch* GameManager::getBatch(){
     return this->batch;
   }

}
