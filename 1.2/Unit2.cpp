//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Phigure.h"
#include "Ellip.h"
#include "Polygon.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
double lastX=0;
double lastY=0;
TDrawingTool DrawingTool;
MyPoint a0(400, 200);
MyPoint b0(100, 300);
MyPoint c0(200, 200);
double alfa = 0;
Ellip ellipse;
class Polygon polygon;
class Polygon circle;
TSituation Situation;
bool Moving = false;
MyPoint ellipse1(0,0);
MyPoint ellipse2(0,0);
double PointHandler[100];
int SizeOfPointHandler = 0;

void TForm2::ClearImage(TForm2 *F)
{
	F->Image1->Canvas->Brush->Color = clWhite;
	F->Image1->Canvas->FillRect(Rect(0,0, F->Image1->Width, F->Image1->Height));
}
//---------------------------------------------------------------------------
  void __fastcall TForm2::DrawFigure(int X, int Y)
 {

	switch(DrawingTool) {


	case  dtEllipse:
ClearImage(Form2);
Image1->Canvas->Ellipse(lastX, lastY, X,Y);
ellipse.SetEllipseCords(lastX,lastY,X,Y);
ellipse.APSync(Form2);
	break;

	case dtPolygon:
	  polygon.Draw(Image1->Canvas, StartPoint, EndPoint, TopCount, clBlack, pmCopy);
	  default:break;
	break;
}

}
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
if (SetCords) {
	polygon.rotateX = X;
	polygon.rotateY=Y;
	SetCords = false;
	SetRotate->Checked = false;
}  else
{
		Image1->Canvas->MoveTo(X, Y);
		lastX = X; lastY = Y;
  switch (Situation)
		 {

		case Drawing:

		  switch (DrawingTool)
			 {

				case dtEllipse:

				case dtPolygon:
				DrawingPol = true;
				StartPoint = Point(lastX, lastY);
				EndPoint = StartPoint;
				polygon.Draw(Image1->Canvas, StartPoint, EndPoint, TopCount, clBlack, pmCopy);
				polygon.SizeOfPointHandler=0;
				default:break;

			 }break;
		case Drawn:
         switch (DrawingTool)
			 {

				case dtEllipse:
					if (ellipse.CheckMousePos(Form2, lastX, lastY))
					{
					   Moving = true;
					}
					else if (!ellipse.CheckMousePos(Form2,lastX,lastY))
					{
					   Situation =  Drawing;
					}
				case dtPolygon:
				   if (polygon.center.CheckMousePos(Form2, lastX, lastY))
				   {

					   Moving = true;
				   }
				   else
				   {
                        DrawingPol = true;
                       Situation = Drawing;
                   }
				default:break;

			 }break;


		 break;
		}
           }
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
if (SetCords) {
	polygon.rotateX = X;
	polygon.rotateY=Y;
	SetCords = false;
	SetRotate->Checked = false;
}  else 	switch (Situation)
		 {
		case Drawing:

			if (DrawingTool == dtPolygon && DrawingPol)
				{
                  ClearImage(Form2);
				  polygon.Draw(Image1->Canvas, StartPoint, EndPoint, TopCount, clBlack, pmCopy);
				  polygon.SetPolygonCords(polygon.PointHandler,polygon.SizeOfPointHandler);
				  DrawingPol = 0;
				  polygon.APSync(Form2);
				  polygon.CenterMass(Form2);
				  Situation = Drawn;

				}
				else if (DrawingTool == dtEllipse)
				{
				DrawFigure(X,Y);
				Situation = Drawn;
				}
				Spin->Enabled =true;
				Stop->Enabled =true;

				break;
		case Drawn:

		Moving = false;
		 switch(DrawingTool)
		 {
		 case dtEllipse:
		 {
		  ellipse.SetEllipseCords(ellipse1.x,ellipse1.y, ellipse2.x,ellipse2.y); break;}
		  case dtPolygon:
		  {
		  for (int i = 0; i < polygon.SizeOfPointHandler; i++)
		  {
			if ((i+1)%2 ==1)
			 {
				polygon.PointHandler[i]+=X-lastX;
			}
			else
			polygon.PointHandler[i] +=Y-lastY;

		  }
		  polygon.SetPolygonCords(polygon.PointHandler,polygon.SizeOfPointHandler);
		  polygon.CenterMass(Form2);break;
		   }
		  default:break;
		 }
		  break;
		}




}
//---------------------------------------------------------------------------

void __fastcall TForm2::CircleClick(TObject *Sender)
{
   TopCount = 70;
   DrawingTool = dtPolygon;
   NumberOfVertices->Enabled = false;
   ZoomSaver->Caption = "1";
   Polygon->Enabled=true;
   Circle->Enabled = false;
   ZoomIn->Enabled = true;
 ZoomOut->Enabled = true;

}

void __fastcall TForm2::FormCreate(TObject *Sender)
{
Image1->Canvas->FillRect(Image1->Canvas->ClipRect);
Deg->Text="1";
NumberOfVertices->Text = "5";
Spin->Enabled = false;
Stop->Enabled = false;
ZoomIn->Enabled = false;
 ZoomOut->Enabled = false;

}

//---------------------------------------------------------------------------

void __fastcall TForm2::StopClick(TObject *Sender)
{

 Timer->Enabled = false;
 Stop->Enabled = false;
 Spin->Enabled = true;
 ZoomIn->Enabled = true;
 ZoomOut->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TForm2::TimerTimer(TObject *Sender)
{
	try
	   {
		polygon.RotatePolygon(Form2,StrToFloat(Deg->Text));
		ClearImage(Form2);
		polygon.RotatePolygon(Form2,StrToFloat(Deg->Text));
	   }
	   catch (...) {
		Timer->Enabled =false;
		Deg->Text = "";
	   }

}
//---------------------------------------------------------------------------

void __fastcall TForm2::ClearClick(TObject *Sender)
{

ClearImage(Form2);
DrawingPol = 0;
Deg->Text = "";
DrawingTool=dtNothing;
ellipse.SetEllipseCords(1,2,3,4);
Polygon->Checked =false;
Circle->Checked= false;
Spin->Enabled = false;
Stop->Enabled = false;
ZoomSaver->Caption  = "1";
Situation = Drawing;
Moving = false;
Polygon->Enabled  = true;
Circle->Enabled = true;
}

//---------------------------------------------------------------------------



void __fastcall TForm2::ZoomInClick(TObject *Sender)
{
		switch (DrawingTool)
		 {

		case dtEllipse:
		{
		ZoomSaver->Caption = FloatToStr(ellipse.ZoomOut(StrToFloat(ZoomSaver->Caption)));
		ClearImage(Form2);
		ellipse.Draw(Form2,ellipse.GetX1(),ellipse.GetY1(),ellipse.GetX2(),ellipse.GetY2());
		break;
		}
		case dtPolygon:
		{
		ClearImage(Form2);
		ZoomSaver->Caption = FloatToStr(polygon.ZoomOut(Form2,StrToFloat(ZoomSaver->Caption)));


		break;
		}
		default:
		break;

		}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ZoomOutClick(TObject *Sender)
{
   	switch (DrawingTool)
		{

		case dtEllipse:  {
		ZoomSaver->Caption = FloatToStr(ellipse.ZoomIn(StrToFloat(ZoomSaver->Caption)));
		ClearImage(Form2);
		ellipse.Draw(Form2,ellipse.GetX1(),ellipse.GetY1(),ellipse.GetX2(),ellipse.GetY2());
		break;
		}
		case dtPolygon:
        	ClearImage(Form2);
		ZoomSaver->Caption = FloatToStr(polygon.ZoomIn(Form2,StrToFloat(ZoomSaver->Caption)));
		break;
		default:;
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
  if(Moving)
  {
	switch (DrawingTool) {
		  case dtEllipse: {
		int changedX = X-lastX;
		int changedY = Y-lastY;
		ellipse.Draw(Form2, ellipse.GetX1()+changedX, ellipse.GetY1()+changedY,
		ellipse.GetX2()+changedX,ellipse.GetY2()+changedY);
		ellipse1.x = ellipse.GetX1()+changedX;
		ellipse1.y = ellipse.GetY1()+changedY;
		ellipse2.x = ellipse.GetX2()+changedX;
		ellipse2.y = ellipse.GetY2()+changedY;
		break;
		}
		  case dtPolygon :
		  {
			double changedX = X-lastX;
			double changedY = Y-lastY;
            ClearImage(Form2);
			polygon.Moove(Form2,changedX,changedY);

		   break;
		  }
           default:
		;
	}

  }

  if (DrawingPol && DrawingTool == dtPolygon && Moving!=true)
		{

		polygon.Draw(Image1->Canvas, StartPoint, EndPoint, TopCount, clBlack, pmNotXor);
		polygon.SizeOfPointHandler =0;
		EndPoint = Point(X, Y);
		polygon.Draw(Image1->Canvas, StartPoint, EndPoint, TopCount, clBlack, pmNotXor);
		polygon.SizeOfPointHandler =0;
	   }
}
void __fastcall TForm2::PolygonClick(TObject *Sender)
{
NumberOfVertices->Enabled = true;
TopCount = StrToInt(NumberOfVertices->Text);
DrawingTool = dtPolygon;
ZoomSaver->Caption = "1";
Polygon->Enabled=false;
Circle->Enabled = true;
 ZoomIn->Enabled = true;
 ZoomOut->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::NumberOfVerticesChange(TObject *Sender)
{
	try {
	if (StrToInt(NumberOfVertices->Text)>30 ) {
			throw "";
	}
		 TopCount = StrToInt(NumberOfVertices->Text);

}
 catch (...) {
		 NumberOfVertices->Text="";
}
}//---------------------------------------------------------------------------
void __fastcall TForm2::SpinClick(TObject *Sender)
{
Timer->Enabled = true;
Spin->Enabled = false;
Stop->Enabled = true;
 ZoomIn->Enabled = false;
 ZoomOut->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::DegChange(TObject *Sender)
{
	try
	{
	 StrToFloat(Deg->Text);
	}
	catch (...)
	{
	Deg->Text="";
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SetRotateClick(TObject *Sender)
{
SetCords = true;
}
//---------------------------------------------------------------------------

