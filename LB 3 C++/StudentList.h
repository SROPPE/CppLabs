//---------------------------------------------------------------------------

#ifndef StudentListH
#define StudentListH
#include "List.h"
#include "Student.h"
#include <fstream>
class StudentList
{
public:
	List<Student> list;
	StudentList()
	{
	fstream filein("Students.txt");
	Student temp;
	int p = 0;
	int num = 0;
	int i = 0;
	char str1[80];

	while (!filein.eof())
	{
		i++;
		if (i == 6)
		{
			list.Add(temp);
			i = 1;
			num++;
		}
		char str[80];
		filein.getline(str, 80);
		int j = 1;
		while (str[j] != ':' && str[j] != '\0')
			j++;
		p += j + 2;
		filein.seekg(p, ios_base::beg);
		if (i == 2)
		{
			filein.getline(str, 80);
			temp.name = str;
			p += strlen(str) + 2;
		}
		else if (i == 3)
		{
			filein.getline(str, 80);
			p += strlen(str) + 2;
			temp.groupNumber = str;
		}
		else if (i == 4)
		{
			filein.getline(str, 80);
			for (int i = 0; i < strlen(str); i++)
			{
				if (str[i] == '.')
				{
					str[i] = ',';
				}
			}
			p += strlen(str) + 2;
			temp.avarageMark = atof(str);
		}
		else if (i == 5)
		{
			filein.getline(str, 80);
			for (int i = 0; i < strlen(str); i++)
			{
				if (str[i] == '.')
				{
					str[i] == ',';
				}
			}
			p += strlen(str) + 2;
			temp.income = atof(str);
		}
	}

	list.Add(temp);
	filein.close();


	}

	Student *ShowStudent(AnsiString name)
{
	for (int i = 0; i < list.GetSize(); i++)
	{
		if (list[i].name == name)
			return &list[i];
	}
	return nullptr;
}
AnsiString GetList()
{
	AnsiString res = "";
	for (int i =0 ; i < list.GetSize();i++)
	{
		res+=list[i].ShowStudent();
	}
    return res;
}
AnsiString FindStudent(AnsiString name)
{
    AnsiString res = "";
	Student *temp = ShowStudent(name);
	if (temp == nullptr)
	{
		res = "Студента нет в списке";
	}
	else
		res = temp->ShowStudent();
	return res;
}
AnsiString ShowStudentByIncome(int minIncome)
{
	AnsiString res;
	for (int i = 0; i < list.GetSize(); i++)
	{
		if (list[i].income >= minIncome)
		{
			 res+= list[i].ShowStudent();
		}
	}
	return res;
}
AnsiString ShowStudentByIncomeAvarageMark(int minIncome, float avgMark)
{
	AnsiString res = "";
	for (int i = 0; i < list.GetSize(); i++)
	{
		if (list[i].income >= 2*minIncome && list[i].avarageMark<avgMark)
		{
			res+=list[i].ShowStudent();
		}
	}
	return res;
}
void AddNewStudent(Student temp)
{
	list.Add(temp);
}
void DeleteStudent(AnsiString name, AnsiString group)
{

   for (int i = 0; i <  list.GetSize(); i++)
	{
		if (list[i].name == name && list[i].groupNumber == group)
		{
			list.Delete(i);
			break;
		}
	}
}
};
//---------------------------------------------------------------------------
#endif
