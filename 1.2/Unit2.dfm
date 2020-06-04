object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 346
  ClientWidth = 695
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
    Left = 0
    Top = 0
    Width = 514
    Height = 345
    OnMouseDown = Image1MouseDown
    OnMouseMove = Image1MouseMove
    OnMouseUp = Image1MouseUp
  end
  object Square: TLabel
    Left = 536
    Top = 72
    Width = 17
    Height = 13
    Caption = 'S ='
  end
  object Perimetr: TLabel
    Left = 536
    Top = 104
    Width = 17
    Height = 13
    Caption = 'P ='
  end
  object ZoomSaver: TLabel
    Left = 585
    Top = 271
    Width = 6
    Height = 13
    Caption = '1'
  end
  object Label1: TLabel
    Left = 536
    Top = 151
    Width = 82
    Height = 13
    Caption = #1059#1075#1086#1083' '#1087#1086#1074#1086#1088#1086#1090#1072': '
  end
  object Label2: TLabel
    Left = 536
    Top = 271
    Width = 30
    Height = 13
    Caption = 'Zoom:'
  end
  object Polygon: TRadioButton
    Left = 536
    Top = 31
    Width = 113
    Height = 17
    Caption = 'Polygon'
    TabOrder = 0
    OnClick = PolygonClick
  end
  object Circle: TRadioButton
    Left = 536
    Top = 8
    Width = 113
    Height = 17
    Caption = 'Circle'
    TabOrder = 1
    OnClick = CircleClick
  end
  object Stop: TButton
    Left = 612
    Top = 182
    Width = 75
    Height = 25
    Caption = 'Stop spin'
    TabOrder = 2
    OnClick = StopClick
  end
  object Clear: TButton
    Left = 560
    Top = 317
    Width = 75
    Height = 25
    Caption = 'Clear'
    TabOrder = 3
    OnClick = ClearClick
  end
  object ZoomOut: TButton
    Left = 624
    Top = 290
    Width = 25
    Height = 25
    Caption = '-'
    TabOrder = 4
    OnClick = ZoomOutClick
  end
  object ZoomIn: TButton
    Left = 624
    Top = 259
    Width = 25
    Height = 25
    Caption = '+'
    TabOrder = 5
    OnClick = ZoomInClick
  end
  object NumberOfVertices: TEdit
    Left = 603
    Top = 31
    Width = 46
    Height = 21
    TabOrder = 6
    OnChange = NumberOfVerticesChange
  end
  object Spin: TButton
    Left = 531
    Top = 182
    Width = 75
    Height = 25
    Caption = 'Spin'
    TabOrder = 7
    OnClick = SpinClick
  end
  object Deg: TEdit
    Left = 638
    Top = 148
    Width = 49
    Height = 21
    TabOrder = 8
    Text = 'Deg'
    OnChange = DegChange
  end
  object SetRotate: TCheckBox
    Left = 560
    Top = 213
    Width = 105
    Height = 17
    Caption = #1058#1086#1095#1082#1072' '#1087#1086#1074#1086#1088#1086#1090#1072
    TabOrder = 9
    OnClick = SetRotateClick
  end
  object Timer: TTimer
    Enabled = False
    Interval = 10
    OnTimer = TimerTimer
    Left = 664
    Top = 312
  end
end
