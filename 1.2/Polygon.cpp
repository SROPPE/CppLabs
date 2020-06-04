//---------------------------------------------------------------------------

#pragma hdrstop

#include "Polygon.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Polygon::Polygon()
{


}
void Polygon::DrawPoint(TForm2 *F,double *arr,int size)
{
	   for (int i = 0; i < size; i+=2)
	   {
	   if(i+3<size)
		 {
		   //	F->Image1->Canvas->LineTo(cords[i],cords[i+1]);
		   F->Image1->Canvas->MoveTo(cords[i],cords[i+1]);
		   F->Image1->Canvas->LineTo(cords[i+2],arr[i+3]);
		   F->Image1->Canvas->MoveTo(cords[i+2],cords[i+3]);

		 }
		else break;
	   }
	   CenterMass(F);

}
void Polygon::RotatePolygon(TForm2 *F,double degree)
{
	degree = degree / 180 * M_PI;
	for(int i = 0; i < SizeOfPointHandler; i+=2)
	{

	   double x = PointHandler[i], y = PointHandler[i+1];
		PointHandler[i] = (x - rotateX) * cos(degree) - (y - rotateY) * sin(degree) +  rotateX;
		PointHandler[i+1]= (x - rotateX ) * sin(degree) + (y- rotateY ) * cos(degree) + rotateY;
	}
	SetPolygonCords(PointHandler,SizeOfPointHandler);
	DrawPoint(F,cords,SizeOfPointHandler);
}
void Polygon::Draw(TCanvas *Canvas, TPoint TopLeft, TPoint BottomRight,
	 int TopCount, TColor LineColor, TPenMode AMode)
{
  Canvas->Pen->Color = LineColor;
  Canvas->Pen->Mode = AMode;
  int R1 = (BottomRight.x - TopLeft.x)/2, R2 = (BottomRight.y - TopLeft.y)/2;
  TPoint Center = Point((BottomRight.x + TopLeft.x)/2, (BottomRight.y + TopLeft.y)/2);
  Canvas->MoveTo(Center.x+sin(0)*R1, Center.y-cos(0)*R2);
  for (int i = 0; i <= TopCount; i++)
  {
	Canvas->LineTo(Center.x+sin(i*2*M_PI/TopCount)*R1+1, Center.y-cos(i*2*M_PI/TopCount)*R2-1);
	PointHandler[SizeOfPointHandler]=Center.x+sin(i*2*M_PI/TopCount)*R1+1;
	SizeOfPointHandler++;
	PointHandler[SizeOfPointHandler] = Center.y-cos(i*2*M_PI/TopCount)*R2-1;
	SizeOfPointHandler++;
  }
}
void Polygon::Moove(TForm2 *F,double changedX, double changedY)
{

	 for (int i = 0; i < SizeOfPointHandler; i++) {
			if ((i+1)%2 ==1) {
				PointHandler[i]+=changedX;
			}
			else
			PointHandler[i] +=changedY;
	 }
	  for (int i = 0; i < SizeOfPointHandler; i+=2)
	   {
	   if(i+3<SizeOfPointHandler)
		 {
		   //	F->Image1->Canvas->LineTo(cords[i],cords[i+1]);
		   F->Image1->Canvas->MoveTo(PointHandler[i],PointHandler[i+1]);
		   F->Image1->Canvas->LineTo(PointHandler[i+2],PointHandler[i+3]);
		   F->Image1->Canvas->MoveTo(PointHandler[i+2],PointHandler[i+3]);

		 }
		else break;
	   }
	   for (int i = 0; i < SizeOfPointHandler; i++) {
		  PointHandler[i] = cords[i];
	   }
}
void Polygon::CenterMass(TForm2 *F)
 {
   double x=0;
   double y=0;
   int size = SizeOfPointHandler;
   for (int i =0; i  < SizeOfPointHandler; i++) {
	   if ((i+1)%2 == 1)
	   {

		  x+=cords[i];
	   }
	   else
	   y+=cords[i];
   }

   F->Image1->Canvas->Ellipse((x*2/size) -5, (y*2/size)-5,(x*2/size) +5,(y*2/size)+5);
   center.SetEllipseCords((x*2/size) -5, (y*2/size)-5,(x*2/size) +5,(y*2/size)+5);
 }
double Polygon::OutputPerimeter()
{
	double res = 0;
	for(int i = 0; i < SizeOfPointHandler; i+=2)
	if ((i+1)%2 ==1 && i-2>=0) {
	res +=sqrt((cords[i - 2] - cords[i]) *
	(cords[i - 2] - cords[i]) *PIXEL_SIZE *PIXEL_SIZE+
	(cords[i - 1]- cords[i+1]) *
	(cords[i - 1] - cords[i+1]) * PIXEL_SIZE*PIXEL_SIZE);
	}
	prmtr = res;
	 return res;

}
double Polygon::OutputArea()
{
    double res = 0;

	for(int i = 0; i < SizeOfPointHandler -1; i+=2)
	if ((i+1)%2==1 && i+2<SizeOfPointHandler) {
		res += (cords[i+1] + cords[i + 3] ) / 2 *
		 (cords[i + 2] - cords[i]);
	}

	area = abs(res * PIXEL_SIZE *PIXEL_SIZE);
	return abs(res);
}
void Polygon::SetPolygonCords(double *arr,int size)
{
	for (int i = 0; i < size; i++)
	{
		cords[i] = arr[i];
	}
	OutputArea();
	OutputPerimeter();

}
float Polygon::ZoomIn(TForm2 *F,float scp)
{

  for (int i = 0; i < SizeOfPointHandler; i++) {
	 cords[i] /=2 ;
	 PointHandler[i] = cords[i];
  }
  DrawPoint(F,cords,SizeOfPointHandler);
  return scp/2;
}
float Polygon::ZoomOut(TForm2 *F,float scp)
{

  for (int i = 0; i < SizeOfPointHandler; i++) {
	  cords[i] *=2;
		PointHandler[i] = cords[i];
  }
  DrawPoint(F,cords,SizeOfPointHandler);
  return 2*scp;
}
