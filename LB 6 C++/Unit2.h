//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TEdit *Number;
	TLabel *Label1;
	TButton *Create;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TRadioButton *RadioButton4;
	TPanel *CreationPanel;
	TPanel *AddPanel;
	TEdit *AddEdit;
	TLabel *Label2;
	TButton *Add;
	TPanel *DeletePanel;
	TLabel *Label3;
	TEdit *DeleteEdit;
	TButton *Delete;
	TPanel *FindPanel;
	TLabel *Label5;
	TEdit *FindEdit;
	TButton *Find;
	TPanel *PrintPanel;
	TRadioButton *PreOrder;
	TRadioButton *Inorder;
	TRadioButton *PostOrder;
	TButton *Print;
	TButton *Claculate;
	void __fastcall CreateClick(TObject *Sender);
	void __fastcall RadioButton1Click(TObject *Sender);
	void __fastcall RadioButton2Click(TObject *Sender);
	void __fastcall RadioButton3Click(TObject *Sender);
	void __fastcall RadioButton4Click(TObject *Sender);
	void __fastcall PrintClick(TObject *Sender);
	void __fastcall FindClick(TObject *Sender);
	void __fastcall DeleteClick(TObject *Sender);
	void __fastcall AddClick(TObject *Sender);
	void __fastcall ClaculateClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
