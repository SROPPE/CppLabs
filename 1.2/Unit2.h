//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
TPoint StartPoint, EndPoint;
bool SetCords = false;
int TopCount = 4;
int TopCountCircle = 50;
bool DrawingPol = false;
enum TDrawingTool {
	dtEllipse, dtPolygon,dtNothing
};
enum TSituation
 {
	 Drawing,Drawn
 };
class TForm2 : public TForm
{
__published:	// IDE-managed Components

	TRadioButton *Polygon;
	TRadioButton *Circle;
	TImage *Image1;
	TButton *Stop;
    TTimer *Timer;
	TLabel *Square;
	TLabel *Perimetr;
	TButton *Clear;
	TButton *ZoomOut;
	TButton *ZoomIn;
	TLabel *ZoomSaver;
	TEdit *NumberOfVertices;
	TButton *Spin;
	TLabel *Label1;
	TEdit *Deg;
	TLabel *Label2;
	TCheckBox *SetRotate;
	void __fastcall DrawFigure(int X, int Y);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall CircleClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall StopClick(TObject *Sender);
	void __fastcall TimerTimer(TObject *Sender);
	void __fastcall ClearClick(TObject *Sender);
	void __fastcall ZoomInClick(TObject *Sender);
	void __fastcall ZoomOutClick(TObject *Sender);
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall PolygonClick(TObject *Sender);
	void __fastcall NumberOfVerticesChange(TObject *Sender);
	void __fastcall SpinClick(TObject *Sender);
	void __fastcall DegChange(TObject *Sender);
	void __fastcall SetRotateClick(TObject *Sender);


private:	// User declarations
public:
	void ClearImage(TForm2 *F);
	void __fastcall FigureChill(TObject *Sender);
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
