#include "rendering/BaseRendering.hpp"
namespace RTS{

    BaseRendering::BaseRendering(GameManager* ptr){
        this->gmptr = ptr;
    }

    void BaseRendering::setTextColor(Color color){
        this->p_textColor = color;
    }

    void BaseRendering::setTextSize(int size){
        this->p_textSize = size;
    }

    void BaseRendering::drawText(string value, int x, int y, bool relative){

        if(relative){
            this->r_text.setPosition(this->gmptr->getWindow()->mapPixelToCoords(Vector2i(x,y)));
        }else{
            this->r_text.setPosition(Vector2f(x,y));
        }

        this->r_text.setString(value);
        this->r_text.setFont(*(this->gmptr->getBatch()->getFont(0)));
        this->r_text.setCharacterSize(this->p_textSize);
        this->r_text.setFillColor(this->p_textColor);

        this->gmptr->getWindow()->draw(r_text);
    }
}