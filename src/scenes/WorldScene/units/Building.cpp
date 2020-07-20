#include "scenes/WorldScene/Grid.hpp"
#include "scenes/WorldScene/units/Building.hpp"

namespace RTS{

  Building::Building(GameManager* gm_ptr, Camera* cam_ptr, int team, int x, int y) : Unit(gm_ptr, cam_ptr, team, x, y){

    this->workers_on_me = 0;

    this->shadow_shape.setPointCount(6);
    this->shadow_shape.setFillColor(Color(0, 0, 0, 0));

    this->healthbar_background.setSize(Vector2f(100, 4));
    this->healthbar_background.setFillColor(Color(0, 0, 0, 200));
    this->healthbar_background.setOutlineColor(Color(64, 64, 64, 200));
    this->healthbar_background.setOutlineThickness(1.0f);

    this->healthbar_current.setSize(Vector2f(100, 4));
    this->healthbar_current.setFillColor(Color(0, 0, 0, 200));
    this->healthbar_current.setOutlineColor(Color(64, 64, 64, 200));
    this->healthbar_current.setOutlineThickness(1.0f);
     
  }

  Building::~Building(){

  }

  void Building::initBuild(){

    this->health_current = 0;

    // only for debug !
    this->workers_on_me = 2;

  }

  void Building::presetTick(){

    int fx = this->camera->getX() + this->texture_offset_x + ((position_x - position_y) * (TILEW/2));
    int fy = this->camera->getY() + this->texture_offset_y + ((position_x + position_y) * (TILEH/2));

    this->texture_position = this->game_manager->getWindow()->mapPixelToCoords(Vector2i(fx,fy));

    this->renderShadow();
    this->renderSprite();
    this->renderHealthbar();

  }

  void Building::presetDraw(){

    this->game_manager->getWindow()->draw(this->shadow_shape);

    float healthbar_percentage = this->getPercentage(this->health_current, this->health_maximum);

    if(healthbar_percentage < 100.0f){
      this->game_manager->getWindow()->draw(this->basement_texture);
    }

    if(healthbar_percentage >= 50.0f){
      this->game_manager->getWindow()->draw(this->texture);
    }

    if(this->health_current < this->health_maximum){
      this->game_manager->getWindow()->draw(this->healthbar_background);
      this->game_manager->getWindow()->draw(this->healthbar_current);
    }

  }

  void Building::tick(){
    this->presetTick();
  }

  void Building::draw(){
    this->presetDraw();
  }

  void Building::setShadow(Vector2f p1, Vector2f p2 ,Vector2f p3, Vector2f p4, float scale, float spread){

    this->shadow_spread = 50;

    this->shadow_points[0] = p1 * scale;
    this->shadow_points[1] = p2 * scale;
    this->shadow_points[2] = p3 * scale;
    this->shadow_points[3] = p4 * scale;
  }

  void Building::renderSprite(){

    float displace = this->getPercentage(this->health_current, this->health_maximum) * 4.0f * 2.0f;

    int displace_texture  = round10((int)max(displace  - 400.0f, 0.0f), 2);
    int displace_basement = round10((int)min(displace        , 400.0f), 2);

    this->texture.setPosition(this->texture_position.x, this->texture_position.y + 200 - displace_texture/2);
    this->texture.setTextureRect(IntRect(0, 400 - displace_texture, 600, displace_texture));

    this->basement_texture.setPosition(this->texture_position.x, this->texture_position.y + 200 - displace_basement/2);
    this->basement_texture.setTextureRect(IntRect(0, 400 - displace_basement, 600, displace_basement));


  }

  void Building::renderShadow(){

    this->shadow_shape.setFillColor(Color(0, 0, 0, (int) 
    clamp(0.0f, 140.0f, this->getPercentage(this->health_current, this->health_maximum)*2.8f - 45.0f )));

    float local_spread = (float) (this->shadow_spread) * 
    clamp(0.0f, 100.0f, this->getPercentage(this->health_current, this->health_maximum)*2.8f - 20.0f ) / 100.0f;
    
    this->shadow_shape.setPoint(0, Vector2f(this->texture_position.x + shadow_points[0].x         
                                    ,(this->texture_position.y + shadow_points[0].y)));
    this->shadow_shape.setPoint(1, Vector2f(this->texture_position.x + shadow_points[1].x                       
                                    ,(this->texture_position.y + shadow_points[1].y)));
    this->shadow_shape.setPoint(2, Vector2f(this->texture_position.x + shadow_points[1].x + local_spread
                                    ,(this->texture_position.y + shadow_points[1].y)));
    this->shadow_shape.setPoint(3, Vector2f(this->texture_position.x + shadow_points[2].x + local_spread
                                    ,(this->texture_position.y + shadow_points[2].y)));
    this->shadow_shape.setPoint(4, Vector2f(this->texture_position.x + shadow_points[3].x + local_spread
                                    ,(this->texture_position.y + shadow_points[3].y)));
    this->shadow_shape.setPoint(5, Vector2f(this->texture_position.x + shadow_points[3].x                       
                                    ,(this->texture_position.y + shadow_points[3].y)));
  }

  void Building::renderHealthbar(){
    if((this->health_current < this->health_maximum) && this->workers_on_me > 0){

      this->health_current += (1 * this->workers_on_me);
      float healthbar_percentage = this->getPercentage(this->health_current, this->health_maximum);
      this->healthbar_current.setSize(Vector2f( healthbar_percentage * 1.0f , 4.0f));

      Color healthbar_color(0,0,0);

      if(healthbar_percentage <= 25.0f){
        healthbar_color = Color(190, 0, 0, 200);
      }else if(healthbar_percentage <= 45.0f){
        healthbar_color = Color(190, 115, 35, 200);
      }else if(healthbar_percentage <= 75.0f){
        healthbar_color = Color(165, 225, 25, 200);
      }else{
        healthbar_color = Color(100, 185, 55, 200);
      }

      this->healthbar_current.setFillColor(healthbar_color);

    }

    this->healthbar_background.setPosition(this->texture_position.x + 100, this->texture_position.y + 185);
    this->healthbar_current.setPosition(this->texture_position.x    + 100, this->texture_position.y + 185);

  }


  void Building::setBasementTexture(Texture* texture_ptr){
    texture_ptr->generateMipmap();
    this->basement_texture = Sprite(*texture_ptr);
  }

  Sprite* Building::getBasementSprite(){
    return &(this->basement_texture);
  }

    
}
