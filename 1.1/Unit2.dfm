object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 301
  ClientWidth = 549
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 8
    Top = 8
    Width = 434
    Height = 285
    OnMouseDown = Image1MouseDown
    OnMouseUp = Image1MouseUp
  end
  object Label1: TLabel
    Left = 448
    Top = 112
    Width = 3
    Height = 13
  end
  object Ellipse: TButton
    Left = 448
    Top = 8
    Width = 88
    Height = 25
    Caption = #1069#1083#1083#1080#1087#1089
    TabOrder = 0
    OnClick = EllipseClick
  end
  object Up: TButton
    Left = 480
    Top = 200
    Width = 25
    Height = 25
    Caption = 'U'
    TabOrder = 1
    OnClick = UpClick
  end
  object Down: TButton
    Left = 480
    Top = 231
    Width = 25
    Height = 25
    Caption = 'D'
    TabOrder = 2
    OnClick = DownClick
  end
  object Right: TButton
    Left = 448
    Top = 231
    Width = 25
    Height = 25
    Caption = 'R'
    TabOrder = 3
    OnClick = RightClick
  end
  object Left: TButton
    Left = 511
    Top = 231
    Width = 25
    Height = 25
    Caption = 'L'
    TabOrder = 4
    OnClick = LeftClick
  end
  object Boom: TButton
    Left = 448
    Top = 152
    Width = 88
    Height = 25
    Caption = #1042#1079#1088#1099#1074
    TabOrder = 5
    OnClick = BoomClick
  end
end