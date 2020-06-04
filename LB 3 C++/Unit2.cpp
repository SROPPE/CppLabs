//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "StudentList.h"
TForm2 *Form2;

using namespace std;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm2::SortByIncomeBTNClick(TObject *Sender)
{
  MinAvgMarkEdit->Visible = false;

}
//---------------------------------------------------------------------------

void __fastcall TForm2::SortByIncomeAvarageMarkClick(TObject *Sender)
{
 MinAvgMarkEdit->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::RadioButton1Click(TObject *Sender)
{
   AddPanel->Visible = true;
	DeletePanel->Visible = false;
	SortPanel->Visible = false;
	FindPanel->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton2Click(TObject *Sender)
{
	DeletePanel->Visible = true;
	AddPanel->Visible = false;
	SortPanel->Visible = false;
	FindPanel->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton3Click(TObject *Sender)
{
 FindPanel->Visible = true;
 DeletePanel->Visible = false;
 AddPanel->Visible = false;
 SortPanel->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton4Click(TObject *Sender)
{
	Memo1->Lines->Text = students.GetList();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton5Click(TObject *Sender)
{
	SortPanel->Visible = true;
		DeletePanel->Visible = false;
		   AddPanel->Visible = false;
			FindPanel->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::AddClick(TObject *Sender)
{
     Student buff;
	buff.name =NameEdit->Text;
	buff.groupNumber=GroupEdit->Text;
	buff.avarageMark=StrToFloat(AvarageMarkEdit->Text);
	buff.income = StrToFloat(IncomeEdit->Text);
   students.AddNewStudent(buff);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FindClick(TObject *Sender)
{
  AnsiString name = "";
  name = NameFind->Text;
  Memo1->Lines->Text = students.FindStudent(name);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::DeleteClick(TObject *Sender)
{
	AnsiString name = NameDeleteEdit->Text, group = GroupDeleteEdit->Text;
	students.DeleteStudent(name,group);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SortClick(TObject *Sender)
{
	if(MinAvgMarkEdit->Visible){
	AnsiString res = "";
	int income = StrToInt(MinIncomeEdit->Text);
	float avgMark =0.f;
	avgMark = StrToFloat(MinAvgMarkEdit->Text);
	res = students.ShowStudentByIncomeAvarageMark(income, avgMark);
	Memo1->Lines->Text = res;
	}
	else
	{
	AnsiString res;
	int income = StrToInt(MinIncomeEdit->Text);
	res = students.ShowStudentByIncome(income);
	Memo1->Lines->Text = res;
	}
}
//---------------------------------------------------------------------------

