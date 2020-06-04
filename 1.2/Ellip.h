//---------------------------------------------------------------------------
#ifndef EllipH
#define EllipH
#include "Phigure.h"

 class Ellip: public Phigure
{
	private:
		int x1,y1,x2,y2;
		float rad1;
		float rad2;
	public:
		Ellip(int x1, int y1, int x2, int y2);
		Ellip();
		float ZoomIn(float);
		float ZoomOut(float);
		void SetEllipseCords(int,int,int,int);
		bool CheckMousePos(TForm *Form2, int, int);
		void Draw(TForm2 *F,int x1,int y1,int x2,int y2);
		int GetX1();
		int GetX2();
		int GetY1();
        int GetY2();
};
#endif

