//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "RPN.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm2::CalcClick(TObject *Sender)
{
	AnsiString input = Expression->Text;
	input = GetPostString(input.c_str());
	Memo1->Text = input;
	vector<string> in;
	 float* k = new float[5];
	k[0] =  StrToFloat(a->Text);
	k[1] =  StrToFloat(b->Text);
	k[2] =  StrToFloat(c->Text);
	k[3] =  StrToFloat(d->Text);
	k[4] =  StrToFloat(e->Text);
	SetCalcVector(in,input.c_str(),k);
	Memo1->Lines->Add(FloatToStr(CalcPolish(in)));
}
//---------------------------------------------------------------------------
