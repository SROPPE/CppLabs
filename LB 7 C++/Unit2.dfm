object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 358
  ClientWidth = 715
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Number: TEdit
    Left = 32
    Top = 16
    Width = 121
    Height = 21
    TabOrder = 0
    Text = 'Number'
    OnChange = NumberChange
  end
  object Main: TMemo
    Left = 312
    Top = 8
    Width = 385
    Height = 89
    Lines.Strings = (
      'Main')
    TabOrder = 1
  end
  object Add: TButton
    Left = 32
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Add'
    TabOrder = 2
    OnClick = AddClick
  end
  object Button1: TButton
    Left = 216
    Top = 136
    Width = 75
    Height = 25
    Caption = 'ShowR'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 216
    Top = 272
    Width = 75
    Height = 25
    Caption = 'ShowL'
    TabOrder = 4
    OnClick = Button2Click
  end
  object Right: TMemo
    Left = 312
    Top = 120
    Width = 385
    Height = 89
    Lines.Strings = (
      'Memo1')
    TabOrder = 5
  end
  object Left: TMemo
    Left = 312
    Top = 232
    Width = 385
    Height = 89
    Lines.Strings = (
      'Memo1')
    TabOrder = 6
  end
  object Button3: TButton
    Left = 216
    Top = 32
    Width = 75
    Height = 25
    Caption = 'Show'
    TabOrder = 7
    OnClick = Button3Click
  end
end
