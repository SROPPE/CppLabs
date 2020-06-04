//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <string>
//---------------------------------------------------------------------------
char pathFileName[40];
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TComboBox *Firms;
	TOpenDialog *OpenDialog1;
	TMemo *Memo1;
	TLabel *Label1;
	TButton *ShowInfo;
	TComboBox *CurrentFile;
	TButton *AddNewCnd;
	TEdit *Age;
	TEdit *Career;
	TEdit *Salary;
	TCheckBox *CheckBox1;
	TButton *Add;
	TButton *Delete;
	TEdit *CndNumber;
	TEdit *Name;
	TLabel *AddLabel;
	TEdit *LastWork;
	TEdit *ExpInLastWork;
	TButton *SortBtn;
	TEdit *SortCareerExp;
	TSaveDialog *SaveDialog1;
	TButton *Save;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FirmsChange(TObject *Sender);
	void __fastcall NameClick(TObject *Sender);
	void __fastcall AgeClick(TObject *Sender);
	void __fastcall CareerClick(TObject *Sender);
	void __fastcall SalaryClick(TObject *Sender);
	void __fastcall NameChange(TObject *Sender);
	void __fastcall AgeChange(TObject *Sender);
	void __fastcall CareerChange(TObject *Sender);
	void __fastcall SalaryChange(TObject *Sender);
	void __fastcall AddClick(TObject *Sender);
	void __fastcall AddNewCndClick(TObject *Sender);
	void __fastcall ShowInfoClick(TObject *Sender);
	void __fastcall DeleteClick(TObject *Sender);
	void __fastcall LastWorkClick(TObject *Sender);
	void __fastcall ExpInLastWorkClick(TObject *Sender);
	void __fastcall CndNumberClick(TObject *Sender);
	void __fastcall SortBtnClick(TObject *Sender);
	void __fastcall SaveClick(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
	void _fastcall InputCnd();
	void _fastcall InputVacancy();
	void _fastcall OutputCorrectCnd(std::string name);
	void _fastcall VacComparer(std::string firmName);
	void _fastcall OutputFreeVac(std::string firmName);
	void _fastcall OutputFreeCnd();
	void _fastcall OutputCndList();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
