//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef PhigureH
#define PhigureH
#include "Unit2.h"
//---------------------------------------------------------------------------

struct MyPoint
 {
	 public:
	 MyPoint(double x, double y)
	  {
		  this->x = x;
		  this->y = y;
	  }
	  MyPoint()
	  {

      }
	 double x;
	 double y;

 };

class Phigure
{
	protected:
		double area;
		double prmtr;
		double alpha;
        static constexpr double PIXEL_SIZE = 0.02645833333333;
		static constexpr float PII = 3.14159;
		double matr[2][2];
	public:

		void APSync(TForm2 *Form);
		float SmToPix(float);
		double DegToRad(double);
		void Rotate();
        void ChangeInfo(TForm2* F);
		void CalcMatrix();
};

#endif
