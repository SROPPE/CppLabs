//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <string>
#include <map>
#include <fstream>
#include<iostream>
#include <cstring>
#include "Unit2.h"
#include "Candidate.h"
#include "Firm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
Firm firmWorkList[40];
std::map<int,Candidate> candidateList;
std::map<int,Firm> vacancyList;
int  sizeVacList = 0;
int  sizeCndList = 0;
bool freeCnd[100];
bool freeVac[100];
std::string UnicToString(System::UnicodeString str)
 {
	char cur[20];
	for (int i = 0; i < str.Length(); i++) {
		 cur[i] = str[i+1];
	}
	cur[str.Length()]  = '\0';
	return cur;
 }
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//------------------ ---------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
Firms->Items->LoadFromFile("Firm.txt");
CurrentFile->Items->LoadFromFile("CurrFile.txt");
InputCnd();
	ShowInfo->Enabled = false;
	Name->Enabled =false;
	Age->Enabled = false;
	CheckBox1->Enabled  = false ;
	Career->Enabled = false;
	Salary->Enabled = false;
	CheckBox1->Enabled  = false;
	Add->Enabled  = false;
	ExpInLastWork->Enabled = false;
	LastWork->Enabled = false;
	std::map<std::string,int>::iterator cur;
	std::map<std::string,int> a =candidateList[0].GetCndWorkList();
   cur=a.begin();
  ofstream out("rgeg.txt");
   out<<(*cur).first;
	std::string f = "ПИСЬКАНОСЫЙЖОПАХУЙ";
  f[3]= (*cur).first[0];
	AddLabel->Caption =(*cur).first[0];
    OutputCndList();
for (int i = 0; i<100; i++)
{
	 freeCnd[i] = true;
	 freeVac[i] = true;
}

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
bool LineCheck(std::string str)
{
for (int i = 0; i <str.length() ; i++)
{
  if (str[i]=='#')
  {
	  return false;
  }
}
return true;
}

std::string InputСorrector(std::string inputString)
{

int i = 0;
	for (; i < inputString.length(); i++)
	{

	   if(inputString[i] ==':')
		{
			i+=2;
			break;
		}

	}
 std::string buffer= inputString.substr(i);
	return buffer;
}


void TForm2::InputCnd()
{
	Candidate buffer;

    OpenDialog1->Execute();
	ifstream filein(OpenDialog1->FileName.c_str());
	int currCnd = 0;
	std::string str;
	int i = 0;
	while (!filein.eof())
	{

		i++;
		if(i!=7)
		getline(filein,str);
		if(LineCheck(str))
		{


		if (i == 2)
		{
			buffer.SetCndName(InputСorrector(str));

		}
		else if(i==3)
		{
			buffer.SetCndDate(InputСorrector(str));
		}
		else if (i == 4)
		{

			if (InputСorrector(str) =="true")
			 {
			 buffer.SetCndHigher(true);
			}
			else if (InputСorrector(str) == "false")
			 {
				buffer.SetCndHigher(false);
			}

		
		}
		else if (i == 5)
		{
			buffer.SetCndCareer(InputСorrector(str));
		}
		else if (i ==6) 
		{
			buffer.SetCndSalary(std::stoi(InputСorrector(str)));
		}
		else if (i ==7) 
		{
		int currLine = 0;
		std::string buff;
		std::string buffWork;
		std::string buffDur;
		while(true)
			{
			getline(filein,buff);
			if (LineCheck(buff))
				{
				currLine++;
				if (currLine  == 1)
					buffWork = buff;
					else if(currLine ==2)
					  {	buffDur = buff;
					   currLine = 0;
					   buffer.SetCndWorkList(buffWork,stoi(buffDur));
					  }


				}
			else break;
			}
		}
		}
         if(i ==7)
			{   i=1;
				candidateList.emplace(sizeCndList,buffer);
				buffer.ClearList();
				sizeCndList++;
			}

	}
}


void TForm2::InputVacancy()
{
	char path[20];
	for (int i = 0; i < Firms->Text.Length(); i++) {
		 path[i] = Firms->Text[i+1];
	}
	path[Firms->Text.Length()]  = '\0';
	char r[]  =".txt";
	strcat(path,r);
	ifstream filein(path);
	std::string a;
	Firm buffer;
	int currentLine =1;
	 while(!filein.eof())
	 {  getline(filein,a);
		if (currentLine == 1)
		{
		   buffer.SetFirmCareer(a);
		}
		else if  (currentLine ==2)
		{
		   buffer.SetFirmSalary(stoi(a));
		}
		else if  (currentLine ==3)
		{
		   buffer.SetFirmVacation(stoi(a));
		}
		else if (currentLine ==4)
		 {
		   if (a == "true") {
			  buffer.SetFirmHigher(true);
		   }
		   else if (a == "false")
		   {
			   buffer.SetFirmHigher(false);
		   }
		 }
			else if (currentLine ==5)
		 {
		   buffer.SetFirmMinAge(stoi(a));
		 }
			else if (currentLine ==6)
		 {
			   buffer.SetFirmMaxAge(stoi(a));
		 }
				else if (currentLine ==7)
		 {
			   buffer.SetFirmName(UnicToString(Firms->Text));
			   buffer.SetFirmExp(stoi(a));
			   vacancyList.emplace(sizeVacList,buffer);
			   currentLine=0;
			   sizeVacList++;
		 }
		 currentLine++;
	 }
}
void TForm2::OutputCorrectCnd(std::string name)
{
	char path[25];
	for (int i = 0; i < name.length(); i++) {
		 path[i] = name[i];
	}
	path[name.length()]  = '\0';
	char r[]  ="Buffer.txt";
	strcat(path,r);
   ofstream out(path);
   for (int i = 0; i < sizeCndList; i++) {
	  if (!freeCnd[i] && candidateList[i].GetCndName()!="")
	  {
		   out <<"Ф.И.О.: "<< candidateList[i].GetCndName()<<std::endl;
		   out <<"Возраст: "<< candidateList[i].GetCndDate()<<std::endl;
		   out <<"Высшее образование: " <<candidateList[i].GetCndHigher()<<std::endl;
		   out <<"Желаемая должность: " <<candidateList[i].GetCndCareer()<<std::endl;
		   out <<"Минимальный требуемый оклад: "<< candidateList[i].GetCndSalary()<<std::endl;
		   out <<"Опыт работы: "<< candidateList[i].GetCndWorkExp(candidateList[i].GetCndCareer())<<std::endl;
	  }
   }
   out.close();
	Memo1->Lines->LoadFromFile(path);
}
void TForm2::OutputCndList()
{
   ofstream out("Candidat.txt");
   for (int i = 0; i < sizeCndList; i++) {
   if (candidateList[i].GetCndName()!="")
	{
		   out <<"Кандидат #"<<i<<std::endl;
		   out <<"Ф.И.О.: "<< candidateList[i].GetCndName()<<std::endl;
		   out <<"Возраст: "<< candidateList[i].GetCndDate()<<std::endl;
		   out <<"Высшее образование: " <<candidateList[i].GetCndHigher()<<std::endl;
		   out <<"Желаемая должность: " <<candidateList[i].GetCndCareer()<<std::endl;
		   out <<"Минимальный оклад: "<< candidateList[i].GetCndSalary()<<std::endl;
	std::map<std::string,int> a =candidateList[i].GetCndWorkList();
	 for(auto it = a.begin();it != a.end(); ++it)
	 {
		out << (*it).first<< std::endl<< it->second << std::endl;
	 }
	 a.clear();
   }

   }
   out<<"Кандидат #"<<sizeCndList;
   out.close();

}
bool CheckVacReq(Candidate cnd, Firm firm)
{
  if (cnd.GetCndCareer() == firm.GetFirmCareer())
  {
	if ((cnd.GetCndHigher() == firm.GetFirmHigher() ||
	cnd.GetCndHigher() >= firm.GetFirmHigher()) &&
	firm.GetFirmSalary()>=cnd.GetCndSalary() &&
	cnd.GetCndWorkExp(firm.GetFirmCareer()) >= firm.GetFirmExp() &&
	2020-stoi(cnd.GetCndDate()) >= firm.GetFirmMinAge() &&
	2020 - stoi(cnd.GetCndDate()) <= firm.GetFirmMaxAge())
	{
	   return true;
	}
	return false;
  }
  else
  return false;
}
void TForm2::VacComparer(std::string firmName)
{
	candidateList[0];
	vacancyList[0];
	for (int i = 0; i < sizeVacList; i++)
	{
	  for (int j = 0; j < sizeCndList; j++)
	  {
		if (vacancyList[i].GetFirmName() == firmName)
		{
			if (CheckVacReq(candidateList[j],vacancyList[i]))
			{
			freeCnd[j] = false;
			freeVac[i] = false;
			}
		}
		else break;
	  }
	}
}
void TForm2::OutputFreeVac(std::string name)
{
	char path[25];
	for (int i = 0; i < name.length(); i++) {
		 path[i] = name[i];
	}
	path[name.length()]  = '\0';
	char r[]  ="Free.txt";
	strcat(path,r);
	ofstream out(path,std::ios_base::trunc);
	for(int i= 0;i <sizeVacList; i++)
	{
	if (freeVac[i] && vacancyList[i].GetFirmName()==name)
	{
	out <<"Вакансия: "<< vacancyList[i].GetFirmCareer()<<std::endl;
	out <<"Зарплата: "<< vacancyList[i].GetFirmSalary()<<std::endl;
	out <<"Количество дней отпуска: " <<vacancyList[i].GetFirmVacation()<<std::endl;
	out <<"Наличие высшего образования: " <<vacancyList[i].GetFirmHigher()<<std::endl;
	out <<"Максимальный возраст: "<< vacancyList[i].GetFirmMaxAge()<<std::endl;
	out <<"Минимальный возраст: "<< vacancyList[i].GetFirmMinAge()<<std::endl;
	out <<"Опыт работы: "<< vacancyList[i].GetFirmExp()<<std::endl;
	}

	}
	 out.close();
		Memo1->Lines->LoadFromFile(path);
}
void TForm2::OutputFreeCnd()
{

	ofstream out("CndFree.txt");
	for(int i= 0;i <sizeCndList; i++)
	{
	if (freeCnd[i] && candidateList[i].GetCndName()!="")
	{
	out <<"Ф.И.О.: "<< candidateList[i].GetCndName()<<std::endl;
	out <<"Возраст: "<< candidateList[i].GetCndDate()<<std::endl;
	out <<"Высшее образование: " <<candidateList[i].GetCndHigher()<<std::endl;
	out <<"Желаемая должность: " <<candidateList[i].GetCndCareer()<<std::endl;
	out <<"Минимальный требуемый оклад: "<< candidateList[i].GetCndSalary()<<std::endl;
	}

	}
	out.close();
		Memo1->Lines->LoadFromFile("CndFree.txt");
}
void __fastcall TForm2::FirmsChange(TObject *Sender)
{

  vacancyList.clear();
InputVacancy();
ShowInfo->Enabled = true;
for (int i = 0; i < 100; i++) {
	freeCnd[i] = true;
	freeVac[i] = true;
}
}
//---------------------------------------------------------------------------
bool inputSaver[5];
void __fastcall TForm2::NameClick(TObject *Sender)
{
   Name->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::AgeClick(TObject *Sender)
{
   Age->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::CareerClick(TObject *Sender)
{
   Career->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SalaryClick(TObject *Sender)
{
   Salary->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::LastWorkClick(TObject *Sender)
{
   LastWork->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ExpInLastWorkClick(TObject *Sender)
{
	ExpInLastWork->Text ="";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::NameChange(TObject *Sender)
{
  inputSaver[0] = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::AgeChange(TObject *Sender)
{
	inputSaver[1] = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::CareerChange(TObject *Sender)
{
  inputSaver[2] = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SalaryChange(TObject *Sender)
{
  inputSaver[3] = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::AddClick(TObject *Sender)
{
	Candidate buffer;
  bool p = true;
   for (int i = 0; i < 4; i++) {
		 if (inputSaver[i] == false)
		 {
			 p = false;
			 AddLabel->Caption = "Некорректный ввод";
			 break;
		 }
   }
   if (p)
   {
   try {
	  buffer.SetCndName(UnicToString(Name->Text));
	  buffer.SetCndDate(UnicToString(Age->Text));
	  buffer.SetCndHigher(CheckBox1->Checked);
	  buffer.SetCndCareer(UnicToString(Career->Text));
	  buffer.SetCndSalary(stoi(UnicToString(Salary->Text)));
	  std::string bufWork  = UnicToString(LastWork->Text);
	  int bufDur =stoi(UnicToString(ExpInLastWork->Text));
	  buffer.SetCndWorkList(bufWork,bufDur);
		candidateList.emplace(sizeCndList,buffer);
				sizeCndList++;
   }
   catch(...)
   {
	 AddLabel->Caption = "Ошибо4ка ввода";
   }
		for (int i = 0; i < 5; i++) {
		 inputSaver[i] = false;
		}
		Name->Text ="Full Name";
		Age->Text = "Age";
		CheckBox1->Checked  = false;
		Career->Text = "Career";
		Salary->Text = "Salary";
        ShowInfo->Enabled = false;
	Name->Enabled =false;
	Age->Enabled = false;
	CheckBox1->Enabled  = false ;
	Career->Enabled = false;
	Salary->Enabled = false;
	CheckBox1->Enabled  = false;
	Add->Enabled  = false;
    	ExpInLastWork->Enabled = false;
	LastWork->Enabled = false;
	   AddNewCnd->Enabled  =true;
    OutputCndList();
   }

}
//---------------------------------------------------------------------------
void Sort(std::string career)
{

	for (int i = 1; i < sizeCndList; i++)
	{
		Candidate k = candidateList[i];
		int x = candidateList[i].GetCndWorkExp(career);
		int j = i - 1;
		while (x > candidateList[j].GetCndWorkExp(career))
		{
		candidateList[j + 1] = candidateList[j];
			j--;
			if (j < 0)
				break;
		}
		candidateList[j + 1] = k;
		Form2->AddLabel->Caption = candidateList[j+1].GetCndName()[0];
	}
	for (int i =0; i < sizeCndList; i++) {
		freeCnd[i] = true;
	}
}
void DeleteCnd(int number)
 {
   candidateList.erase(number);
 }

void __fastcall TForm2::AddNewCndClick(TObject *Sender)
{
		Name->Enabled =true;
		Age->Enabled = true;
		CheckBox1->Enabled  = true ;
		Career->Enabled = true;
		Salary->Enabled = true;
		CheckBox1->Enabled  = true;
		Add->Enabled  = true;
		ExpInLastWork->Enabled = true;
		LastWork->Enabled = true;
        AddNewCnd->Enabled  =false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ShowInfoClick(TObject *Sender)
{
std::string tool = UnicToString(CurrentFile->Text);
std::string firmName = UnicToString(Firms->Text);
VacComparer(firmName);

if (tool == "Free vacancy")
{
 OutputFreeVac(firmName);
}
else if(tool  == "Free candidates")
{
 OutputFreeCnd();
}
else if (tool =="Correct candidates" )
 OutputCorrectCnd(firmName);


}
//---------------------------------------------------------------------------

void __fastcall TForm2::DeleteClick(TObject *Sender)
{
DeleteCnd(stoi(UnicToString(CndNumber->Text)));
ShowInfo->Enabled = false;
}
//-------------------------------------------------------------------------


void __fastcall TForm2::CndNumberClick(TObject *Sender)
{
CndNumber->Text = "";
}
//---------------------------------------------------------------------------


void __fastcall TForm2::SortBtnClick(TObject *Sender)
{
ShowInfo->Enabled = false;
Sort(UnicToString(SortCareerExp->Text));
std::string firmName = UnicToString(Firms->Text);
VacComparer(firmName);
OutputCndList();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SaveClick(TObject *Sender)
{
SaveDialog1 = new TSaveDialog(Form2);
SaveDialog1->Filter = "Text files (*.txt)|*.TXT|";
if( SaveDialog1->Execute() )
 {
  Memo1->Lines->SaveToFile(SaveDialog1->FileName);
 }
//---------------------------------------------------------------------------
}
