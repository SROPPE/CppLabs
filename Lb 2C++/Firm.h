//---------------------------------------------------------------------------
#include <string>
#ifndef FirmH
#define FirmH
//---------------------------------------------------------------------------
#endif
class Firm
{
	public:
	   void SetFirmName(std::string name);
	   void SetFirmCareer(std::string career);
	   void SetFirmSalary(int salary);
	   void SetFirmVacation(int vacation);
	   void SetFirmHigher(bool higher);
	   void SetFirmMaxAge(int age);
	   void SetFirmMinAge(int age);
	   void SetFirmExp(int age);

		std::string GetFirmName();
		std::string GetFirmCareer();
		int GetFirmSalary();
		int GetFirmVacation();
		bool GetFirmHigher();
		int GetFirmMaxAge();
		int GetFirmMinAge();
		int GetFirmExp();
	protected:
	std::string Name;
	std::string Career;
	int Salary;
	int Vacation;
	bool Higher;
	int MaxAge;
	int MinAge;
	int Experience;

};