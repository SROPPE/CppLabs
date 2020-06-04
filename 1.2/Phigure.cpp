#include "Phigure.h"
#include <vcl.h>
#pragma hdrstop
#pragma package(smart_init)

void Phigure::APSync(TForm2 *Form)
{
 Form->Perimetr->Caption= "P = " + FloatToStr(floor(prmtr*1000)/1000) + "sm";
 Form->Square->Caption= "S = " + FloatToStr(floor(area*1000)/1000) + "sm";

}

