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
			"Имя: " + name + "\n" +
			"Номер группы: " + groupNumber + "\n" +
			"Средний балл: " + FloatToStr(avarageMark) + "\n"  +
			"Доход на члена семьи: "+ FloatToStr(income) + "\n";
		 return res;
   }
};
//---------------------------------------------------------------------------
#endif
