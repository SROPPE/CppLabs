object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 434
  ClientWidth = 764
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
    Left = 320
    Top = 8
    Width = 436
    Height = 385
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object AddPanel: TPanel
    Left = 129
    Top = 8
    Width = 185
    Height = 385
    Caption = 'AddPanel'
    TabOrder = 1
    Visible = False
    object NameLabel: TLabel
      Left = 32
      Top = 69
      Width = 35
      Height = 13
      Caption = #1060'.'#1048'.'#1054':'
    end
    object GroupLabel: TLabel
      Left = 32
      Top = 117
      Width = 40
      Height = 13
      Caption = #1043#1088#1091#1087#1087#1072':'
    end
    object AvarageMarkLabel: TLabel
      Left = 32
      Top = 164
      Width = 78
      Height = 13
      Caption = #1057#1088#1077#1076#1085#1080#1081' '#1073#1072#1083#1083': '
    end
    object Incomelabel: TLabel
      Left = 32
      Top = 212
      Width = 33
      Height = 13
      Caption = #1044#1086#1093#1086#1076
    end
    object NameEdit: TEdit
      Left = 32
      Top = 88
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object IncomeEdit: TEdit
      Left = 32
      Top = 231
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object AvarageMarkEdit: TEdit
      Left = 32
      Top = 185
      Width = 121
      Height = 21
      TabOrder = 2
    end
    object GroupEdit: TEdit
      Left = 32
      Top = 137
      Width = 121
      Height = 21
      TabOrder = 3
    end
    object Add: TButton
      Left = 62
      Top = 286
      Width = 75
      Height = 25
      Caption = 'Add'
      TabOrder = 4
      OnClick = AddClick
    end
  end
  object DeletePanel: TPanel
    Left = 129
    Top = 8
    Width = 185
    Height = 385
    Caption = 'DeletePanel'
    TabOrder = 2
    Visible = False
    object Label1: TLabel
      Left = 40
      Top = 117
      Width = 35
      Height = 13
      Caption = #1060'.'#1048'.'#1054':'
    end
    object Label2: TLabel
      Left = 40
      Top = 164
      Width = 40
      Height = 13
      Caption = #1043#1088#1091#1087#1087#1072':'
    end
    object NameDeleteEdit: TEdit
      Left = 40
      Top = 136
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object GroupDeleteEdit: TEdit
      Left = 40
      Top = 183
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object Delete: TButton
      Left = 62
      Top = 261
      Width = 75
      Height = 25
      Caption = 'Delete'
      TabOrder = 2
      OnClick = DeleteClick
    end
  end
  object FindPanel: TPanel
    Left = 129
    Top = 8
    Width = 185
    Height = 385
    Caption = 'FindPanel'
    TabOrder = 3
    Visible = False
    object Label3: TLabel
      Left = 24
      Top = 164
      Width = 35
      Height = 13
      Caption = #1060'.'#1048'.'#1054':'
    end
    object NameFind: TEdit
      Left = 24
      Top = 183
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object Find: TButton
      Left = 37
      Top = 246
      Width = 75
      Height = 25
      Caption = 'Find'
      TabOrder = 1
      OnClick = FindClick
    end
  end
  object SortPanel: TPanel
    Left = 129
    Top = 8
    Width = 185
    Height = 385
    Caption = 'SortPanel'
    TabOrder = 4
    Visible = False
    object Label4: TLabel
      Left = 6
      Top = 163
      Width = 172
      Height = 13
      Caption = #1042#1074#1077#1076#1080#1090#1077' '#1084#1080#1085#1080#1084#1072#1083#1100#1085#1091#1102' '#1079#1072#1088#1087#1083#1072#1090#1091': '
    end
    object Label5: TLabel
      Left = 6
      Top = 212
      Width = 119
      Height = 13
      Caption = #1042#1074#1077#1076#1080#1090#1077' '#1089#1088#1077#1076#1085#1080#1081' '#1073#1072#1083#1083':'
    end
    object SortByIncomeBTN: TRadioButton
      Left = 8
      Top = 58
      Width = 145
      Height = 17
      Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1082#1072' '#1087#1086' '#1076#1086#1093#1086#1076#1091
      TabOrder = 0
      OnClick = SortByIncomeBTNClick
    end
    object SortByIncomeAvarageMark: TRadioButton
      Left = 8
      Top = 90
      Width = 177
      Height = 17
      Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1082#1072' '#1087#1086' '#1073#1072#1083#1083#1091' '#1080' '#1076#1086#1093#1086#1076#1091
      TabOrder = 1
      OnClick = SortByIncomeAvarageMarkClick
    end
    object MinIncomeEdit: TEdit
      Left = 24
      Top = 185
      Width = 121
      Height = 21
      TabOrder = 2
    end
    object MinAvgMarkEdit: TEdit
      Left = 24
      Top = 231
      Width = 121
      Height = 21
      TabOrder = 3
    end
    object Sort: TButton
      Left = 46
      Top = 279
      Width = 75
      Height = 25
      Caption = 'Sort'
      TabOrder = 4
      OnClick = SortClick
    end
  end
  object RadioButton1: TRadioButton
    Left = 10
    Top = 33
    Width = 113
    Height = 17
    Caption = 'Add'
    TabOrder = 5
    OnClick = RadioButton1Click
  end
  object RadioButton2: TRadioButton
    Left = 10
    Top = 56
    Width = 113
    Height = 17
    Caption = 'Delete'
    TabOrder = 6
    OnClick = RadioButton2Click
  end
  object RadioButton3: TRadioButton
    Left = 10
    Top = 79
    Width = 113
    Height = 17
    Caption = 'Find'
    TabOrder = 7
    OnClick = RadioButton3Click
  end
  object RadioButton4: TRadioButton
    Left = 10
    Top = 98
    Width = 113
    Height = 17
    Caption = 'ShowList'
    TabOrder = 8
    OnClick = RadioButton4Click
  end
  object RadioButton5: TRadioButton
    Left = 10
    Top = 121
    Width = 113
    Height = 17
    Caption = 'Sort'
    TabOrder = 9
    OnClick = RadioButton5Click
  end
end
