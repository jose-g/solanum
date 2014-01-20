object frmReportGraphMenuTwoSeries: TfrmReportGraphMenuTwoSeries
  Left = 624
  Top = 302
  BorderStyle = bsDialog
  Caption = 'Reports menu'
  ClientHeight = 301
  ClientWidth = 478
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox2: TGroupBox
    Left = 385
    Top = 216
    Width = 78
    Height = 75
    Caption = 'GroupBox2'
    TabOrder = 0
    TabStop = True
    object SpeedButton4: TSpeedButton
      Left = 22
      Top = 30
      Width = 35
      Height = 35
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000120B0000120B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00330000000000
        03333377777777777F333301BBBBBBBB033333773F3333337F3333011BBBBBBB
        0333337F73F333337F33330111BBBBBB0333337F373F33337F333301110BBBBB
        0333337F337F33337F333301110BBBBB0333337F337F33337F333301110BBBBB
        0333337F337F33337F333301110BBBBB0333337F337F33337F333301110BBBBB
        0333337F337F33337F333301110BBBBB0333337F337FF3337F33330111B0BBBB
        0333337F337733337F333301110BBBBB0333337F337F33337F333301110BBBBB
        0333337F3F7F33337F333301E10BBBBB0333337F7F7F33337F333301EE0BBBBB
        0333337F777FFFFF7F3333000000000003333377777777777333}
      NumGlyphs = 2
      ParentFont = False
      OnClick = SpeedButton4Click
    end
    object RichEdit2: TRichEdit
      Left = 12
      Top = 5
      Width = 57
      Height = 22
      TabStop = False
      Alignment = taCenter
      BiDiMode = bdLeftToRight
      BorderStyle = bsNone
      Color = clBlack
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentBiDiMode = False
      ParentFont = False
      ReadOnly = True
      TabOrder = 1
    end
    object RichEdit1: TRichEdit
      Left = 8
      Top = 0
      Width = 57
      Height = 22
      TabStop = False
      Alignment = taCenter
      BiDiMode = bdLeftToRight
      Color = 12713983
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Lines.Strings = (
        'Close')
      ParentBiDiMode = False
      ParentFont = False
      ReadOnly = True
      TabOrder = 0
    end
  end
  object GroupBox1: TGroupBox
    Left = 9
    Top = 8
    Width = 456
    Height = 201
    TabOrder = 1
    TabStop = True
    object RichEdit3: TRichEdit
      Left = 173
      Top = 5
      Width = 113
      Height = 22
      TabStop = False
      Alignment = taCenter
      BiDiMode = bdLeftToRight
      BorderStyle = bsNone
      Color = clBlack
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentBiDiMode = False
      ParentFont = False
      ReadOnly = True
      TabOrder = 2
    end
    object RichEdit4: TRichEdit
      Left = 169
      Top = 0
      Width = 113
      Height = 22
      TabStop = False
      Alignment = taCenter
      BiDiMode = bdLeftToRight
      Color = 12713983
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMaroon
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Lines.Strings = (
        'Graph reports list')
      ParentBiDiMode = False
      ParentFont = False
      ReadOnly = True
      TabOrder = 1
    end
    object Button2: TButton
      Left = 23
      Top = 100
      Width = 201
      Height = 33
      Caption = 'Fresh tuber yield'
      TabOrder = 0
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 231
      Top = 100
      Width = 201
      Height = 33
      Caption = 'Canopy cover'
      TabOrder = 3
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 231
      Top = 52
      Width = 201
      Height = 33
      Caption = 'Dry tuber yield'
      TabOrder = 4
      OnClick = Button4Click
    end
    object Button6: TButton
      Left = 23
      Top = 52
      Width = 201
      Height = 33
      Caption = 'Total dry biomass'
      TabOrder = 5
      OnClick = Button6Click
    end
    object Button5: TButton
      Left = 127
      Top = 148
      Width = 201
      Height = 33
      Caption = 'Box Plotting'
      TabOrder = 6
      OnClick = Button5Click
    end
  end
end
