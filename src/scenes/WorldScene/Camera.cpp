#include "scenes/WorldScene/Camera.hpp"
namespace RTS{

    Camera::Camera(RenderWindow* ptr){
        this->windowPtr = ptr;
        this->isBeingDragged = false;
    }

    void Camera::tick(){

        Vector2i mousePosition = Mouse::getPosition(*(this->windowPtr));
        if (Mouse::isButtonPressed(Mouse::Right)){
            if(this->isBeingDragged){

                Vector2i delta = lastPosition - mousePosition;
                this->currentPosition += delta;
                this->windowPtr->setMouseCursorVisible(false);
                Mouse::setPosition(Vector2i(this->lastPosition.x, this->lastPosition.y), *(this->windowPtr));

            }else{

                this->isBeingDragged = true;
                this->lastPosition = mousePosition;
            }
        }else{
            this->windowPtr->setMouseCursorVisible(true);
            if(this->isBeingDragged){
                this->isBeingDragged = false;
            }
        }
    }

    float Camera::getX(){
        return this->currentPosition.x;
    }

    float Camera::getY(){
        return this->currentPosition.y;
    }
}