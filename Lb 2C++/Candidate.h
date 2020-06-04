//---------------------------------------------------------------------------
#include <string>
#include <map>
#ifndef CandidateH
#define CandidateH
//---------------------------------------------------------------------------
#endif
class Candidate
{
	public:
	Candidate(std::string name,std::string date,bool higher,std::string career,
	int salary,std::map<std::string,int> workList);
    Candidate();

	   void SetCndName(std::string name);
	   void SetCndDate(std::string date);
	   void SetCndHigher(bool higher);
	   void SetCndCareer(std::string career);
	   void SetCndSalary(int salary);
	   void SetCndWorkList(std::string key, int value);

	   std::string GetCndName();
	   std::string GetCndDate();
	   bool GetCndHigher();
	   std::string GetCndCareer();
	   int GetCndSalary();
	   std::map<std::string,int> GetCndWorkList();
	   void ClearList();
       int GetCndWorkExp(std::string);
	protected:
	   std::string Name ="";
	   std::string Date ="";
	   bool Higher;
	   std::string Career = "";
       int Salary;
	   std::map<std::string,int> WorkList;
};