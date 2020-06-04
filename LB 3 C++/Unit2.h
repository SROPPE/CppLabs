//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "StudentList.h"
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TButton *Add;
	TButton *Delete;
	TButton *Find;
	TButton *Sort;
	TPanel *AddPanel;
	TEdit *NameEdit;
	TEdit *GroupEdit;
	TEdit *AvarageMarkEdit;
	TEdit *IncomeEdit;
	TLabel *NameLabel;
	TLabel *GroupLabel;
	TLabel *AvarageMarkLabel;
	TLabel *Incomelabel;
	TPanel *DeletePanel;
	TEdit *NameDeleteEdit;
	TEdit *GroupDeleteEdit;
	TLabel *Label1;
	TLabel *Label2;
	TPanel *FindPanel;
	TEdit *NameFind;
	TLabel *Label3;
	TPanel *SortPanel;
	TRadioButton *SortByIncomeBTN;
	TRadioButton *SortByIncomeAvarageMark;
	TEdit *MinIncomeEdit;
	TEdit *MinAvgMarkEdit;
	TLabel *Label4;
	TLabel *Label5;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TRadioButton *RadioButton4;
	TRadioButton *RadioButton5;
	void __fastcall SortByIncomeBTNClick(TObject *Sender);
	void __fastcall SortByIncomeAvarageMarkClick(TObject *Sender);
	void __fastcall RadioButton1Click(TObject *Sender);
	void __fastcall RadioButton2Click(TObject *Sender);
	void __fastcall RadioButton3Click(TObject *Sender);
	void __fastcall RadioButton4Click(TObject *Sender);
	void __fastcall RadioButton5Click(TObject *Sender);
	void __fastcall AddClick(TObject *Sender);
	void __fastcall FindClick(TObject *Sender);
	void __fastcall DeleteClick(TObject *Sender);
	void __fastcall SortClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
	StudentList students;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
