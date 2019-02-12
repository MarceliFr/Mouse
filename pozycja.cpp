//---------------------------------------------------------------------------
#include "pozycja.h"
//---------------------------------------------------------------------------
Pozycja::Pozycja(){
        GetCursorPos(&pt);
}
Pozycja::~Pozycja(){}

int Pozycja::getPozX(){
        return pt.x;
}
int Pozycja::getPozY(){
        return pt.y;
}
