//---------------------------------------------------------------------------

#ifndef RPNH
#define RPNH
using namespace std;
#include<iostream>
#include <vector>
#include <set>
#include <stack>
#include<string>
struct Stack
{
	char sign;
	struct Stack* next;
};
struct Stack* PushFront(Stack*, char);
char PopFront(Stack**);
int CaclPriority(char);
AnsiString GetPostString(string instring)
{
	struct Stack* operationStack = NULL;
	char outstring [50];
	int i = 0, point = 0;
	while (instring[i] != '\0' && instring[i] != '=')
	{
		if (instring[i] == ')')
		{
			while ((operationStack->sign) != '(')
				outstring[point++] = PopFront(&operationStack);
			PopFront(&operationStack);
		}
		if (instring[i] >= 'a' && instring[i] <= 'z')
			outstring[point++] = instring[i];
		if (instring[i] == '(')
			operationStack = PushFront(operationStack, '(');
		if (instring[i] == '+' || instring[i] == '-' || instring[i] == '/' || instring[i] == '*')
		{
			if (operationStack == NULL)
				operationStack = PushFront(operationStack, instring[i]);
			else
				if (CaclPriority(operationStack->sign) < CaclPriority(instring[i]))
					operationStack = PushFront(operationStack, instring[i]);
				else
				{
					while ((operationStack != NULL)
						&& (CaclPriority(operationStack->sign) >= CaclPriority(instring[i])))
						outstring[point++] = PopFront(&operationStack);
					operationStack = PushFront(operationStack, instring[i]);
				}
		}
		i++;
	}
	while (operationStack != NULL)
		outstring[point++] = PopFront(&operationStack);
	return outstring;
}
bool IsOperator(char a)
{
	char operators[4] = { '*','/','-','+' };
	for (int i = 0; i < 4; i++)
	{
		if (a == operators[i])
			return true;
	}
	return false;
}
double FindOperation(const double& op1,
	const double& op2,
	const char& operation)
{
	double result = 0.0;
	switch (operation)
	{
	case ('+'):  result = op1 + op2;
		break;
	case ('-'):  result = op1 - op2;
		break;
	case ('*'):  result = op1 * op2;
		break;
	case ('/'):  result = op1 / op2;
		break;
	}
	return result;
}
int CaclPriority(char a)
{
	switch (a)
	{
	case '*':
	case '/':
		return 3;

	case '-':
	case '+':
		return 2;

	case '(':
		return 1;
	}
}
double CalcPolish(const vector<string>& expr)
{
	const set<string> operators = { "+", "-", "*", "/" };
	stack<double>* operands = new stack<double>();
	for (const auto& e : expr)
	{
		if (operators.find(e) != operators.end())
		{
			double  x2 = operands->top();
			operands->pop();
			double  x1 = operands->top();
			operands->pop();
			operands->push(FindOperation(x1, x2, e[0]));
		}
		else
			operands->push(atof(e.c_str()));
	}

	return operands->top();
}
void SetCalcVector(vector<string> &in,string input,float *k)
{

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] >= 'a' && input[i] <= 'z')
		{
			in.push_back(to_string(k[input[i] - 'a']));
		}
		else
		{
			string g =" ";
			g[0]=input[i];
			in.push_back(g);
		}
	}
}
struct Stack* PushFront(Stack* head, char a)
{
	Stack* ptr =new Stack();
	ptr->sign = a;
	ptr->next = head;
	return ptr;
}
char PopFront(Stack** head)
{
	struct Stack* ptr;
	char a;
	ptr = *head;
	a = ptr->sign;
	*head = ptr->next;
	delete ptr;
	return a;
}
//---------------------------------------------------------------------------
#endif
