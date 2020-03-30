#include "units/Building.hpp"
#include "scenes/WorldScene/Grid.hpp"

namespace RTS{

  Building::Building(GameManager* ptr, Camera* c, int t, int x, int y) : Unit(ptr, c, t, x, y){
    this->shadow.setPointCount(6);
    this->shadow.setFillColor(Color(0, 0, 0, 128));
  }

  Building::~Building(){

  }

  void Building::presetTick(){
    int fx = this->camera->getX() + this->texture_offset_x + ((position_x - position_y) * (TILEW/2));
    int fy = this->camera->getY() + this->texture_offset_y + ((position_x + position_y) * (TILEH/2));
    this->texture_position = this->gameManager->getWindow()->mapPixelToCoords(Vector2i(fx,fy));
    this->texture.setPosition(this->texture_position.x, this->texture_position.y);
    this->renderShadow();
  }

  void Building::presetDraw(){
    this->gameManager->getWindow()->draw(this->shadow);
    this->gameManager->getWindow()->draw(this->texture);
  }

  void Building::tick(){
    this->presetTick();
  }

  void Building::draw(){
    this->presetDraw();
  }

  void Building::setShadow(Vector2f p1, Vector2f p2 ,Vector2f p3, Vector2f p4, float scale){
    this->sp[0] = p1 * scale;
    this->sp[1] = p2 * scale;
    this->sp[2] = p3 * scale;
    this->sp[3] = p4 * scale;
  }

  void Building::renderShadow(){
    int w = 50;
    this->shadow.setPoint(0, Vector2f(this->texture_position.x + sp[0].x     , this->texture_position.y + sp[0].y));
    this->shadow.setPoint(1, Vector2f(this->texture_position.x + sp[1].x     , this->texture_position.y + sp[1].y));
    this->shadow.setPoint(2, Vector2f(this->texture_position.x + sp[1].x + w , this->texture_position.y + sp[1].y));
    this->shadow.setPoint(3, Vector2f(this->texture_position.x + sp[2].x + w , this->texture_position.y + sp[2].y));
    this->shadow.setPoint(4, Vector2f(this->texture_position.x + sp[3].x + w , this->texture_position.y + sp[3].y));
    this->shadow.setPoint(5, Vector2f(this->texture_position.x + sp[3].x     , this->texture_position.y + sp[3].y));
  }
    
}
