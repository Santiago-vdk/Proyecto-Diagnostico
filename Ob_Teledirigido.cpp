#include "Ob_Teledirigido.h"
#include <QDebug>
void Ob_Teledirigido::mover(){
    if (_posX-10 > 0){

       _posX -= 5;
    }
    else{
        _salud = 0;
    }
}
Ob_Teledirigido::~Ob_Teledirigido(){

}
