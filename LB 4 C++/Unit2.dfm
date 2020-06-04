object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 349
  ClientWidth = 630
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 42
    Top = 77
    Width = 65
    Height = 13
    Caption = #1042#1099#1088#1072#1078#1077#1085#1080#1077': '
  end
  object Expression: TEdit
    Left = 42
    Top = 96
    Width = 121
    Height = 21
    TabOrder = 0
    Text = 'a/(b+c-d*e)'
  end
  object Calc: TButton
    Left = 42
    Top = 136
    Width = 75
    Height = 25
    Caption = #1056#1072#1089#1089#1095#1080#1090#1072#1090#1100
    TabOrder = 1
    OnClick = CalcClick
  end
  object Memo1: TMemo
    Left = 224
    Top = 8
    Width = 398
    Height = 321
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
  end
  object a: TEdit
    Left = 42
    Top = 183
    Width = 40
    Height = 21
    TabOrder = 3
    Text = 'a'
  end
  object d: TEdit
    Left = 88
    Top = 210
    Width = 40
    Height = 21
    TabOrder = 4
    Text = 'd'
  end
  object c: TEdit
    Left = 42
    Top = 210
    Width = 40
    Height = 21
    TabOrder = 5
    Text = 'c'
  end
  object e: TEdit
    Left = 42
    Top = 236
    Width = 40
    Height = 21
    TabOrder = 6
    Text = 'e'
  end
  object b: TEdit
    Left = 88
    Top = 183
    Width = 40
    Height = 21
    TabOrder = 7
    Text = 'b'
  end
end
