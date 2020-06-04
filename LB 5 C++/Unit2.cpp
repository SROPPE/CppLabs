//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
using namespace std;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------



void __fastcall TForm2::Button1Click(TObject *Sender)
{
  Image1->Picture->LoadFromFile(imageQueue.PopFront().c_str());
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormActivate(TObject *Sender)
{

		imageQueue.PushBack("1.PNG");
		imageQueue.PushBack("3.PNG");
		imageQueue.PushBack("5.PNG");
		imageQueue.PushBack("6.PNG");
		for (int i = 0; i < imageQueue.GetSize(); i++)
		{
		ListBox1->Items->Add(imageQueue.PopFront().c_str());
		}

}
//---------------------------------------------------------------------------

