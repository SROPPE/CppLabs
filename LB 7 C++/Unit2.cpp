//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm2 *Form2;
	HashTable<int> left(100);
	HashTable<int> right(100);
	HashTable<int> a(100);

template<typename T>
void createRLTables(HashTable<int> a,HashTable<int> &left,HashTable<int> &right,T item)
{
	for (int i = 0; i < a.size; i++)
	{
		int size1 = a.items[i].node.GetSize();
		if (size1 != 0)
			for (int k = 0; k < size1; k++)
			{
				int c = a.items[i].node[k];
				if (c >= item)
					right.Add(c);
				else
					left.Add(c);
			}
	}
}
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	int r = 55;
	a.Add(r);
	a.Add(43);
	a.Add(2345);
	a.Add(4356);
	createRLTables<int>(a,left,right, 60);
	Number->Text ="1";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::NumberChange(TObject *Sender)
{
	try
	{
	if (StrToInt(Number->Text) <0)
	{
			throw "";
	}
	}
	 catch (...)
	{
		 Number->Text="";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::AddClick(TObject *Sender)
{
 a.Add(Number->Text.ToInt());
 left.Clear();
 right.Clear();
 createRLTables(a,left,right,60);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
char t[1000];
std::string buff = a.GetTable();
for (int i = 0; i <= a.GetTable().length(); i++)
{
t[i] = buff[i];
}
 Main->Lines->Text =t;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	  char t[1000];
std::string buff = right.GetTable();
for (int i = 0; i <= right.GetTable().length(); i++)
{
t[i] = buff[i];
}
 Right->Lines->Text =t;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
char t[1000];
std::string buff = left.GetTable();
for (int i = 0; i <= left.GetTable().length(); i++)
{
t[i] = buff[i];
}
 Left->Lines->Text =t;
}
//---------------------------------------------------------------------------
