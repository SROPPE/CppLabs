object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 474
  ClientWidth = 935
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 594
    Top = 8
    Width = 84
    Height = 13
    Caption = #1058#1077#1082#1091#1097#1072#1103' '#1092#1080#1088#1084#1072':'
  end
  object AddLabel: TLabel
    Left = 712
    Top = 128
    Width = 87
    Height = 13
    Caption = #1059#1082#1072#1078#1080#1090#1077' '#1076#1072#1085#1085#1099#1077
  end
  object Firms: TComboBox
    Left = 712
    Top = 5
    Width = 101
    Height = 21
    TabOrder = 0
    Text = 'Firms'
    OnChange = FirmsChange
  end
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 569
    Height = 466
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
  end
  object ShowInfo: TButton
    Left = 594
    Top = 53
    Width = 75
    Height = 25
    Caption = #1055#1086#1082#1072#1079#1072#1090#1100
    TabOrder = 2
    OnClick = ShowInfoClick
  end
  object CurrentFile: TComboBox
    Left = 712
    Top = 55
    Width = 101
    Height = 21
    TabOrder = 3
    Text = 'CurrentFile'
  end
  object AddNewCnd: TButton
    Left = 594
    Top = 99
    Width = 75
    Height = 25
    Caption = 'AddNewCnd'
    TabOrder = 4
    OnClick = AddNewCndClick
  end
  object Name: TEdit
    Left = 594
    Top = 152
    Width = 121
    Height = 21
    TabOrder = 5
    Text = #1060'.'#1048'.'#1054'.'
    OnChange = NameChange
    OnClick = NameClick
  end
  object Age: TEdit
    Left = 784
    Top = 152
    Width = 121
    Height = 21
    TabOrder = 6
    Text = #1042#1086#1079#1088#1072#1089#1090
    OnChange = AgeChange
    OnClick = AgeClick
  end
  object Career: TEdit
    Left = 594
    Top = 196
    Width = 121
    Height = 21
    TabOrder = 7
    Text = 'Career'
    OnChange = CareerChange
    OnClick = CareerClick
  end
  object Salary: TEdit
    Left = 784
    Top = 196
    Width = 121
    Height = 21
    TabOrder = 8
    Text = 'Salary'
    OnChange = SalaryChange
    OnClick = SalaryClick
  end
  object CheckBox1: TCheckBox
    Left = 688
    Top = 248
    Width = 125
    Height = 17
    Caption = #1042#1099#1089#1096#1077#1077' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1077
    TabOrder = 9
  end
  object Add: TButton
    Left = 712
    Top = 336
    Width = 75
    Height = 25
    Caption = 'Add'
    TabOrder = 10
    OnClick = AddClick
  end
  object Delete: TButton
    Left = 603
    Top = 384
    Width = 75
    Height = 25
    Caption = 'Delete'
    TabOrder = 11
    OnClick = DeleteClick
  end
  object CndNumber: TEdit
    Left = 712
    Top = 386
    Width = 121
    Height = 21
    TabOrder = 12
    Text = 'CndNumber'
    OnClick = CndNumberClick
  end
  object LastWork: TEdit
    Left = 594
    Top = 296
    Width = 121
    Height = 21
    TabOrder = 13
    Text = 'LastWork'
    OnClick = LastWorkClick
  end
  object ExpInLastWork: TEdit
    Left = 784
    Top = 296
    Width = 121
    Height = 21
    TabOrder = 14
    Text = 'ExpInLastWork'
    OnClick = ExpInLastWorkClick
  end
  object SortBtn: TButton
    Left = 603
    Top = 434
    Width = 75
    Height = 25
    Caption = 'Sort'
    TabOrder = 15
    OnClick = SortBtnClick
  end
  object SortCareerExp: TEdit
    Left = 712
    Top = 434
    Width = 121
    Height = 21
    TabOrder = 16
    Text = 'SortCareerExp'
  end
  object Save: TButton
    Left = 863
    Top = 408
    Width = 42
    Height = 25
    Caption = 'Save'
    TabOrder = 17
    OnClick = SaveClick
  end
  object OpenDialog1: TOpenDialog
    Left = 720
    Top = 408
  end
  object SaveDialog1: TSaveDialog
    Left = 760
    Top = 408
  end
end
