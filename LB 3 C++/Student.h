//---------------------------------------------------------------------------
#pragma once
#ifndef StudentH
#define StudentH

#include <System.Classes.hpp>
using namespace std;
class Student
{
public:
	AnsiString name ="";
	AnsiString groupNumber="";
	float avarageMark=0.f;
	float income = 0.f;
	AnsiString ShowStudent()
	{   AnsiString res = "";
		res =
			"���: " + name + "\n" +
			"����� ������: " + groupNumber + "\n" +
			"������� ����: " + FloatToStr(avarageMark) + "\n"  +
			"����� �� ����� �����: "+ FloatToStr(income) + "\n";
		 return res;
   }
};
//---------------------------------------------------------------------------
#endif
