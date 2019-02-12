//---------------------------------------------------------------------------

#ifndef POZYCJAH
#define POZYCJAH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class Pozycja{
private:
        POINT pt;
        int pozX, pozY;

public:
        Pozycja();
        ~Pozycja();

        int getPozX();
        int getPozY();
};
//---------------------------------------------------------------------------
#endif
