//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
TDrawingTool DrawingTool;
class Ell
 {
	 public:
	 Ell(int curX1,int curY1,int curX2, int curY2)
	 {
		 this->curX1= curX1;
		 this->curX2= curX2;
		 this->curY2= curY2;
		 this->curY1= curX1;
	 }
		 Ell()
	 {

	 }
	 void SetEllipsCords(int curX1,int curY1,int curX2, int curY2)
	 {
		 this->curX1= curX1;
		 this->curX2= curX2;
		 this->curY2= curY2;
		 this->curY1= curY1;
	 }
	 void EllipseFlexLeft(TForm2 *F,TImage *Image1)
	  {
		 curX1++;
		 curX2++;
		 CanvasClear(F);
		 Image1->Canvas->Ellipse(curX1,curY1,curX2,curY2);
	  }
	   void EllipseFlexUp(TForm2 *F,TImage *Image1)
	  {
		 curY1--;
		 curY2--;
		 CanvasClear(F);
		 Image1->Canvas->Ellipse(curX1,curY1,curX2,curY2);
	  }
	   void EllipseFlexƒ‡ÛÌ(TForm2 *F,TImage *Image1)
	  {
		 curY1++;
		 curY2++;
		 CanvasClear(F);
		 Image1->Canvas->Ellipse(curX1,curY1,curX2,curY2);
	  }
		void EllipseFlexRight(TForm2 *F,TImage *Image1)
	  {
		 curX1--;
		 curX2--;
		 CanvasClear(F);
		 Image1->Canvas->Ellipse(curX1,curY1,curX2,curY2);
	  }
	 private:

	 protected:
	 void CanvasClear(TForm2 *F)
	 {
         F->Image1->Canvas->Brush->Color = clWhite;
		  F->Image1->Canvas->FillRect(Rect(0,0, F->Image1->Width, F->Image1->Height));
     }
		int curX1;
		int curX2;
		int curY1;
		int curY2;
 };
 class Balloon : public Ell
{
	public:
	 void BalloonBoom(TForm2 *F,TImage *Image1, TLabel *Label1)
	  {
		  if(curX1)
		 {
		  CanvasClear(F);
		  curX1 = 0;
		  curX2 = 0;
		  curY1 = 0;
		  curY2 = 0;
		  Label1->Caption= "ÿ‡ Ò‰ÂÎ‡Î ·ÛÏ";
		   }
	  }
};
 Balloon el;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//--------------------------------------------------------------------------
int lastX=0;
int lastY=0;


void __fastcall TForm2::EllipseClick(TObject *Sender)
{
   DrawingTool = dtEllipse;
}
//---------------------------------------------------------------------------
  void __fastcall TForm2::DrawFigure(int X, int Y)
 {

switch(DrawingTool) {
case dtLine:

case dtRectangle:

Image1->Canvas->LineTo(X, Y);
lastX = -1; lastY = -1; break;

case  dtEllipse:
el.SetEllipsCords(lastX,lastY,X,Y);
Image1->Canvas->Ellipse(lastX, lastY, X,Y);
 break;

case dtRoundRect:

Image1->Canvas->Rectangle(lastX,lastY, X,Y);

lastX = -1; lastY = -1; break;

}

}
void __fastcall TForm2::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
		Image1->Canvas->MoveTo(X, Y);
		lastX = X; lastY = Y;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	DrawFigure(X, Y);
	lastX = -1;
	lastY = -1;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
Image1->Canvas->FillRect(
Image1->Canvas->ClipRect);
}
//---------------------------------------------------------------------------





void __fastcall TForm2::UpClick(TObject *Sender)
{
 el.EllipseFlexUp(Form2,Image1);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::DownClick(TObject *Sender)
{
   el.EllipseFlexƒ‡ÛÌ(Form2,Image1);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RightClick(TObject *Sender)
{
  el.EllipseFlexRight(Form2,Image1);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::LeftClick(TObject *Sender)
{
  el.EllipseFlexLeft(Form2,Image1);
}
//---------------------------------------------------------------------------


void __fastcall TForm2::BoomClick(TObject *Sender)
{
 el.BalloonBoom(Form2,Image1,Label1);
}
//---------------------------------------------------------------------------

