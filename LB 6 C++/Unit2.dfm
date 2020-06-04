object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 433
  ClientWidth = 724
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 328
    Top = 8
    Width = 388
    Height = 401
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object RadioButton1: TRadioButton
    Left = 8
    Top = 66
    Width = 113
    Height = 17
    Caption = 'Add'
    TabOrder = 1
    Visible = False
    OnClick = RadioButton1Click
  end
  object RadioButton2: TRadioButton
    Left = 8
    Top = 89
    Width = 113
    Height = 17
    Caption = 'Delete'
    TabOrder = 2
    Visible = False
    OnClick = RadioButton2Click
  end
  object RadioButton3: TRadioButton
    Left = 8
    Top = 112
    Width = 113
    Height = 17
    Caption = 'Find'
    TabOrder = 3
    Visible = False
    OnClick = RadioButton3Click
  end
  object RadioButton4: TRadioButton
    Left = 8
    Top = 135
    Width = 113
    Height = 17
    Caption = 'Print'
    TabOrder = 4
    Visible = False
    OnClick = RadioButton4Click
  end
  object CreationPanel: TPanel
    Left = 127
    Top = 105
    Width = 185
    Height = 214
    TabOrder = 5
    object Label1: TLabel
      Left = 33
      Top = 76
      Width = 120
      Height = 13
      Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1101#1083#1077#1084#1077#1085#1090#1086#1074':'
    end
    object Number: TEdit
      Left = 33
      Top = 95
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object Create: TButton
      Left = 54
      Top = 122
      Width = 75
      Height = 25
      Caption = #1057#1086#1079#1076#1072#1090#1100
      TabOrder = 1
      OnClick = CreateClick
    end
  end
  object AddPanel: TPanel
    Left = 127
    Top = 114
    Width = 185
    Height = 213
    TabOrder = 6
    Visible = False
    object Label2: TLabel
      Left = 33
      Top = 75
      Width = 100
      Height = 13
      Caption = #1042#1074#1077#1076#1080#1090#1077' '#1079#1085#1072#1095#1077#1085#1080#1077': '
    end
    object AddEdit: TEdit
      Left = 33
      Top = 94
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object Add: TButton
      Left = 54
      Top = 121
      Width = 75
      Height = 25
      Caption = 'Add'
      TabOrder = 1
      OnClick = AddClick
    end
  end
  object DeletePanel: TPanel
    Left = 127
    Top = 112
    Width = 185
    Height = 220
    TabOrder = 7
    Visible = False
    object Label3: TLabel
      Left = 24
      Top = 63
      Width = 100
      Height = 13
      Caption = #1042#1074#1077#1076#1080#1090#1077' '#1079#1085#1072#1095#1077#1085#1080#1077': '
    end
    object DeleteEdit: TEdit
      Left = 24
      Top = 83
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object Delete: TButton
      Left = 41
      Top = 110
      Width = 75
      Height = 25
      Caption = 'Delete'
      TabOrder = 1
      OnClick = DeleteClick
    end
  end
  object FindPanel: TPanel
    Left = 127
    Top = 107
    Width = 185
    Height = 220
    TabOrder = 8
    Visible = False
    object Label5: TLabel
      Left = 33
      Top = 69
      Width = 100
      Height = 13
      Caption = #1042#1074#1077#1076#1080#1090#1077' '#1079#1085#1072#1095#1077#1085#1080#1077': '
    end
    object FindEdit: TEdit
      Left = 33
      Top = 88
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object Find: TButton
      Left = 54
      Top = 115
      Width = 75
      Height = 25
      Caption = 'Find'
      TabOrder = 1
      OnClick = FindClick
    end
  end
  object PrintPanel: TPanel
    Left = 127
    Top = 112
    Width = 185
    Height = 220
    TabOrder = 9
    Visible = False
    object PreOrder: TRadioButton
      Left = 41
      Top = 53
      Width = 113
      Height = 17
      Caption = 'PreOrder'
      TabOrder = 0
    end
    object Inorder: TRadioButton
      Left = 41
      Top = 76
      Width = 113
      Height = 17
      Caption = 'Inorder'
      TabOrder = 1
    end
    object PostOrder: TRadioButton
      Left = 41
      Top = 101
      Width = 113
      Height = 17
      Caption = 'PostOrder'
      TabOrder = 2
    end
    object Print: TButton
      Left = 41
      Top = 133
      Width = 75
      Height = 25
      Caption = 'Print'
      TabOrder = 3
      OnClick = PrintClick
    end
  end
  object Claculate: TButton
    Left = 8
    Top = 170
    Width = 75
    Height = 25
    Caption = 'Claculate'
    TabOrder = 10
    Visible = False
    OnClick = ClaculateClick
  end
end
