#include "scenes/WorldScene/Camera.hpp"
namespace RTS{

    Camera::Camera(RenderWindow* ptr){
        this->rw_wnd_ptr = ptr;
        this->is_being_dragged = false;
    }

    void Camera::tick(){

        Vector2i mousePosition = Mouse::getPosition(*(this->rw_wnd_ptr));
        if (Mouse::isButtonPressed(Mouse::Right)){
            if(this->is_being_dragged){

                Vector2i delta = position_last - mousePosition;
                this->position_current += delta;
                this->rw_wnd_ptr->setMouseCursorVisible(false);
                Mouse::setPosition(Vector2i(this->position_last.x, this->position_last.y), *(this->rw_wnd_ptr));

            }else{

                this->is_being_dragged = true;
                this->position_last = mousePosition;
            }
        }else{
            this->rw_wnd_ptr->setMouseCursorVisible(true);
            if(this->is_being_dragged){
                this->is_being_dragged = false;
            }
        }
    }

    float Camera::getX(){
        return this->position_current.x;
    }

    float Camera::getY(){
        return this->position_current.y;
    }
}