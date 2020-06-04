//---------------------------------------------------------------------------

#pragma hdrstop

#include "Firm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void Firm::SetFirmName(std::string name)
{
	 Name = name;
}
void Firm::SetFirmCareer(std::string career)
{
	 Career = career;
}
void Firm::SetFirmSalary(int salary)
{
	 Salary = salary;
}
void Firm::SetFirmVacation(int vacation)
{
	 Vacation = vacation;
}
void Firm::SetFirmHigher(bool higher)
{
	 Higher = higher;
}
void Firm::SetFirmMaxAge(int age)
{
	 MaxAge = age;
}
void Firm::SetFirmMinAge(int age)
{
	 MinAge = age;
}
void Firm::SetFirmExp(int exp)
{
	 Experience = exp;
}


std::string Firm::GetFirmName()
{
	return Name   ;
}
std::string Firm::GetFirmCareer()
{
	return Career ;
}
int Firm::GetFirmSalary()
{
	return Salary ;
}
int Firm::GetFirmVacation()
{
   return  Vacation ;
}
bool Firm::GetFirmHigher()
{
   return Higher;
}
int Firm::GetFirmMaxAge()
{
	return MaxAge ;
}
int Firm::GetFirmMinAge()
{
   return MinAge ;
}
int Firm::GetFirmExp()
{
   return Experience;
}
