//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MouseControl.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

POINT pt;
int pozX, pozY;

void TForm1::odczyt(){
        GetCursorPos(&pt);
        pozX = pt.x;
        pozY = pt.y;

        Label1->Caption = "X = " + IntToStr(pt.x);
        Label2->Caption = "Y = " + IntToStr(pt.y);
}
bool TForm1::sprawdz(){
        if(LabeledEdit1->Text == "" || LabeledEdit2->Text == ""){
                ShowMessage("Wpisz wspó³rzêdne X i Y przed klikniêciem przycisku!");
                return FALSE;
        }else{
                int x, y;
                AnsiString sx = LabeledEdit1->Text;
                AnsiString sy = LabeledEdit2->Text;
                if(TryStrToInt(sx, x) && TryStrToInt(sy, y)){
                        int xmax = GetSystemMetrics(SM_CXSCREEN);
                        int ymax = GetSystemMetrics(SM_CYSCREEN);
                        if(x<0 || x>xmax){
                                ShowMessage("Wspó³rzêdna X musi siê zawieraæ pomiêdzy 0, a " + IntToStr(xmax) + "!");
                                return FALSE;
                        }else if(y<0 || y>ymax){
                                ShowMessage("Wspó³rzêdna Y musi siê zawieraæ pomiêdzy 0, a " + IntToStr(ymax) + "!");
                                return FALSE;
                        }else{
                                return TRUE;
                        }
                }else{
                        ShowMessage("Wartoœci musz¹ byæ liczbami!");
                        return FALSE;
                }
        }
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner){
                //Pozycja * Odczyt = new Pozycja();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender){
        odczyt();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender){
        if(sprawdz() == TRUE) SetCursorPos(StrToInt(LabeledEdit1->Text), StrToInt(LabeledEdit2->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender){
        if(Button2->Caption == "Ukryj"){
                Button2->Caption = "Poka¿";
                ShowCursor(FALSE);
        }else{
                Button2->Caption = "Ukryj";
                ShowCursor(TRUE);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LabeledEdit1Enter(TObject *Sender){
        if(sprawdz() == TRUE) SetCursorPos(StrToInt(LabeledEdit1->Text), StrToInt(LabeledEdit2->Text));
}
//---------------------------------------------------------------------------

