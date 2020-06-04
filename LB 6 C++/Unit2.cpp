//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Tree.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
	Tree *tree = new Tree();
	Node* root = new Node(4);
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::CreateClick(TObject *Sender)
{
Form2->Memo1->Text ="";
tree->root = tree->Insert(root, 3);
int a;
for (int i = 0; i < StrToInt(Number->Text); i++)
	{
		 a = rand()%10000;
		tree->Insert(root,a);
	}
	tree->Inorder(Form2->Memo1,root);
RadioButton1->Visible = true;
RadioButton2->Visible = true;
RadioButton3->Visible = true;
RadioButton4->Visible = true;
Claculate->Visible = true;
CreationPanel->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RadioButton1Click(TObject *Sender)
{
 AddPanel->Visible = true;
 DeletePanel->Visible = false;
 FindPanel->Visible = false;
 PrintPanel->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RadioButton2Click(TObject *Sender)
{
   AddPanel->Visible = false;
 DeletePanel->Visible = true;
 FindPanel->Visible = false;
 PrintPanel->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RadioButton3Click(TObject *Sender)
{
	AddPanel->Visible = false;
 DeletePanel->Visible= false;
 FindPanel->Visible = true;
 PrintPanel->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::RadioButton4Click(TObject *Sender)
{
AddPanel->Visible = false;
 DeletePanel->Visible = false;
 FindPanel->Visible = false;
 PrintPanel->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::PrintClick(TObject *Sender)
{
  Memo1->Text = "";
  if(PreOrder->Checked ==true)
  tree->PreOrder(Form2->Memo1,root);
  else if(PostOrder->Checked == true)
  tree->PostOrder(Form2->Memo1,root);
  else if(Inorder->Checked == true)
  tree->Inorder(Form2->Memo1,root);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FindClick(TObject *Sender)
{

  if( tree->Find(root, StrToInt(FindEdit->Text)) != nullptr)
  Memo1->Text = "Ёлемент найден";
  else Memo1->Text = "Ёлемент отсутсвтует";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::DeleteClick(TObject *Sender)
{
	tree->Remove(root,StrToInt(DeleteEdit->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::AddClick(TObject *Sender)
{
	tree->Insert(root,StrToInt(AddEdit->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ClaculateClick(TObject *Sender)
{
Memo1->Text = "Ѕлижайший элемент: " + IntToStr(tree->CalcNeareast(root));
}
//---------------------------------------------------------------------------
