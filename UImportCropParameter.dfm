object frmImportCropParameter: TfrmImportCropParameter
  Left = 526
  Top = 230
  Width = 205
  Height = 339
  BorderIcons = [biSystemMenu]
  Caption = 'Import ...'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object chkLB: TCheckListBox
    Left = 8
    Top = 16
    Width = 169
    Height = 225
    ItemHeight = 16
    TabOrder = 0
  end
  object butOpen: TButton
    Left = 16
    Top = 256
    Width = 75
    Height = 25
    Caption = 'Open ...'
    TabOrder = 1
    OnClick = butOpenClick
  end
  object butImport: TButton
    Left = 96
    Top = 256
    Width = 75
    Height = 25
    Caption = 'Import'
    TabOrder = 2
    OnClick = butImportClick
  end
  object chkbSelect: TCheckBox
    Left = 8
    Top = 260
    Width = 81
    Height = 17
    Caption = 'Select all'
    TabOrder = 3
    Visible = False
    OnClick = chkbSelectClick
  end
  object odAbrir: TOpenDialog
    Filter = 'CSV (Comma delimited) (*.csv)|*.csv'
    Left = 88
    Top = 160
  end
  object sdResult: TSaveDialog
    DefaultExt = 'csv'
    Filter = 'CSV (Comma delimited) (*.csv)|*.csv'
    Title = 'Save ...'
    Left = 56
    Top = 160
  end
end
