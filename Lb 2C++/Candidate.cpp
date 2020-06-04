//---------------------------------------------------------------------------

#pragma hdrstop

#include "Candidate.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Candidate::Candidate()
 {

 }
Candidate::Candidate(std::string name,std::string date,bool higher,std::string career,int salary,std::map<std::string,int> workList)
{

  SetCndDate(date);
  SetCndHigher(higher);
  SetCndCareer(career);
  SetCndSalary(salary);

}
void Candidate::SetCndName(std::string name)
{
	  Name = name;

}
void Candidate::SetCndDate(std::string date)
{
	Date = date;
}
void Candidate::SetCndHigher(bool higher)
{
	Higher = higher;
}
void Candidate::SetCndCareer(std::string career)
{
	Career = career;
}
void Candidate::SetCndSalary(int salary)
{
	Salary = salary;
}
void Candidate::SetCndWorkList(std::string key, int value)
{
std::string l  = key;
int p = value;
	WorkList.insert(std::make_pair(key,value));
 int i = 0;
}

std::string Candidate::GetCndName()
{
	return Name;
}
 std::string  Candidate::GetCndDate()
{
	return Date;
}
 bool Candidate::GetCndHigher()
{
	return Higher;
}
 std::string  Candidate::GetCndCareer()
{
	return Career;
}
int Candidate::GetCndSalary()
{
    return Salary;
}
 std::map<std::string,int> Candidate::GetCndWorkList()
{
	return WorkList;
}

int Candidate::GetCndWorkExp(std::string career)
{
int i =  WorkList[career];
	return WorkList[career];
}
void Candidate::ClearList()
{
	WorkList.clear();
}
