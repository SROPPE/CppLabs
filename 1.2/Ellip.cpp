//---------------------------------------------------------------------------

#pragma hdrstop
#include <vcl.h>
#include "Ellip.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
 bool Ellip::CheckMousePos(TForm *Form2,int x, int y)
{
   if (x2-x1 > 0 && y2-y1>0)
	{
	   if (x-x1>0 && y - y1>0 && x-x2<0 && y-y2<0)
	   {
		  return true;
	   }
	}
	else if (x2-x1> 0 && y2-y1<0)
	{
	   if (x-x1>0 && y - y1<0 && x-x2<0 && y-y2>0)
	   {
		  return true;
	   }
	}
	  else if (x2-x1<0 && y2-y1>0)
	{
	   if (x-x1<0 && y - y1>0 && x-x2>0 && y-y2<0)
	   {
		  return true;
	   }
	}
	  else if (x2-x1< 0 && y2-y1<0)
	{
	  if (x-x1<0 && y - y1<0 && x-x2>0 && y-y2>0)
	   {
		  return true;
	   }
	}
   return false;
}
Ellip::Ellip(int x1,int y1, int x2, int y2)
{
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
	rad1 =  abs((this->x2-this->x1)/2) * PIXEL_SIZE;
	rad2 =  abs((this->y2-this->y1)/2) * PIXEL_SIZE;
	area = rad1 * rad2 * PII;
	prmtr = 4 * (PII * rad1 * rad2 + (rad1 - rad2) * (rad1 - rad2))/(rad1 + rad2);
}
Ellip::Ellip()
{

}
void Ellip::SetEllipseCords(int x1,int y1, int x2, int y2)
{
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
	rad1 =  abs((this->x2-this->x1)/2) * PIXEL_SIZE;
	rad2 =  abs((this->y2-this->y1)/2) * PIXEL_SIZE;
	area = rad1 * rad2 * PII;
	prmtr = 4 * (PII * rad1 * rad2 + (rad1 - rad2) * (rad1 - rad2))/(rad1 + rad2);
}
void Ellip::Draw(TForm2 *F,int x1,int y1,int x2,int y2)
{
	F->ClearImage(F);
	F->Image1->Canvas->Ellipse(x1, y1, x2,y2);

}
int Ellip::GetX1()
{
	return this->x1;
}
int Ellip::GetX2()
{
	return this->x2;
}
int Ellip::GetY2()
{
	return this->y2;
}
int Ellip::GetY1()
{
	return this->y1;
}
float Ellip::ZoomIn(float scp)
{
	  float	xChanger = abs(x2-x1)/4+1;
	  float yChanger = abs(y2-y1)/4+1;
	if (x1-x2<0 && y1-y2<0)
	{
		x1+=xChanger;
		x2-= xChanger;
		y1+=yChanger;
		y2-= yChanger;
    }
	else if (x1-x2>0 && y1-y2<0)
	 {
		x1-=xChanger;
		x2+= xChanger;
		y1+=yChanger;
		y2-= yChanger;
	}
	else if (x1-x2>0 && y1-y2>0)
	 {
		x1-=xChanger;
		x2+= xChanger;
		y1-=yChanger;
		y2+= yChanger;
	}
	else if (x1-x2<0 && y1-y2>0)
	{
		x1+=xChanger;
		x2-= xChanger;
		y1+=yChanger;
		y2-= yChanger;
	}
	return scp/2;
}

float Ellip::ZoomOut(float scp)
{

	  float	xChanger = abs(x2-x1)/2+1;
	  float yChanger = abs(y2-y1)/2+1;
	if (x1-x2<0 && y1-y2<0)
	{
		x1-=xChanger;
		x2+= xChanger;
		y1-=yChanger;
		y2+= yChanger;
    }
	else if (x1-x2>0 && y1-y2<0)
	 {
	 x1+=xChanger;
		x2-= xChanger;
		y1-=yChanger;
		y2+= yChanger;
	}
	else if (x1-x2>0 && y1-y2>0)
	 {
		x1+=xChanger;
		x2-= xChanger;
		y1+=yChanger;
		y2-= yChanger;
	}
	else if (x1-x2<0 && y1-y2>0)
	{
		x1-=xChanger;
		x2+= xChanger;
		y1+=yChanger;
		y2-= yChanger;
	}
	return 2*scp;
}

