//---------------------------------------------------------------------------
#ifndef PolygonH
#define PolygonH
#include "Phigure.h"
#include "Ellip.h"
//---------------------------------------------------------------------------

class Polygon: public Phigure
{
	protected:
		int corn;
		MyPoint* tops;
		double cords[1000];


	public:
		Polygon();
        double centerX, centerY;
		Ellip center;
		double rotateX = 100;
		double rotateY = 100;
		void SetPolygonCords(double *arr, int size);
		void  Draw(TCanvas *Canvas, TPoint TopLeft, TPoint BottomRight,
			 int TopCount, TColor LineColor, TPenMode AMode);
		void DrawPoint(TForm2 *F,double *arr,int size);
		float ZoomIn(TForm2 *F,float scp);
		float ZoomOut(TForm2 *F,float scp);
		void Moove(TForm2 *F,double changedX,double changedY);
		double OutputPerimeter();
		double OutputArea();
		void CenterMass(TForm2 *F);
		double PointHandler[1000];
		void RotatePolygon(TForm2 *F,double degree);
		int SizeOfPointHandler = 0;
};
#endif

