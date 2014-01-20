object frmNitrogenAM: TfrmNitrogenAM
  Left = 410
  Top = 343
  BorderStyle = bsDialog
  Caption = 'Nitrogen Dynamics'
  ClientHeight = 209
  ClientWidth = 270
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object cmdCancel: TBitBtn
    Left = 104
    Top = 170
    Width = 75
    Height = 25
    Caption = '&Cancel'
    TabOrder = 2
    OnClick = cmdCancelClick
    Glyph.Data = {
      DE010000424DDE01000000000000760000002800000024000000120000000100
      0400000000006801000000000000000000001000000000000000000000000000
      80000080000000808000800000008000800080800000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
      333333333333333333333333000033338833333333333333333F333333333333
      0000333911833333983333333388F333333F3333000033391118333911833333
      38F38F333F88F33300003339111183911118333338F338F3F8338F3300003333
      911118111118333338F3338F833338F3000033333911111111833333338F3338
      3333F8330000333333911111183333333338F333333F83330000333333311111
      8333333333338F3333383333000033333339111183333333333338F333833333
      00003333339111118333333333333833338F3333000033333911181118333333
      33338333338F333300003333911183911183333333383338F338F33300003333
      9118333911183333338F33838F338F33000033333913333391113333338FF833
      38F338F300003333333333333919333333388333338FFF830000333333333333
      3333333333333333333888330000333333333333333333333333333333333333
      0000}
    NumGlyphs = 2
  end
  object cmdApply: TBitBtn
    Left = 184
    Top = 170
    Width = 75
    Height = 25
    Caption = '&Apply'
    Default = True
    TabOrder = 3
    OnClick = cmdApplyClick
    Glyph.Data = {
      DE010000424DDE01000000000000760000002800000024000000120000000100
      0400000000006801000000000000000000001000000000000000000000000000
      80000080000000808000800000008000800080800000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
      3333333333333333333333330000333333333333333333333333F33333333333
      00003333344333333333333333388F3333333333000033334224333333333333
      338338F3333333330000333422224333333333333833338F3333333300003342
      222224333333333383333338F3333333000034222A22224333333338F338F333
      8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
      33333338F83338F338F33333000033A33333A222433333338333338F338F3333
      0000333333333A222433333333333338F338F33300003333333333A222433333
      333333338F338F33000033333333333A222433333333333338F338F300003333
      33333333A222433333333333338F338F00003333333333333A22433333333333
      3338F38F000033333333333333A223333333333333338F830000333333333333
      333A333333333333333338330000333333333333333333333333333333333333
      0000}
    NumGlyphs = 2
  end
  object cbOM: TComboBox
    Left = 134
    Top = 13
    Width = 107
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 0
  end
  object RichEdit36: TRichEdit
    Left = 8
    Top = 13
    Width = 121
    Height = 21
    TabStop = False
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Kind of organic matters')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 1
  end
  object RichEdit25: TRichEdit
    Left = 8
    Top = 117
    Width = 121
    Height = 33
    TabStop = False
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Amount of fertilizer '
      'applied')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 4
  end
  object edAmountFert: TEdit
    Left = 136
    Top = 123
    Width = 65
    Height = 21
    TabOrder = 5
  end
  object RichEdit28: TRichEdit
    Left = 208
    Top = 125
    Width = 49
    Height = 22
    TabStop = False
    Alignment = taCenter
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'kg/ha')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 6
  end
  object RichEdit1: TRichEdit
    Left = 8
    Top = 85
    Width = 121
    Height = 21
    TabStop = False
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Kind of fertilizer')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 7
  end
  object cbFert: TComboBox
    Left = 134
    Top = 85
    Width = 107
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 8
  end
  object RichEdit2: TRichEdit
    Left = 8
    Top = 45
    Width = 121
    Height = 33
    TabStop = False
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Amount of organic '
      'matter applied')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 9
  end
  object edFOMi: TEdit
    Left = 136
    Top = 51
    Width = 65
    Height = 21
    TabOrder = 10
  end
  object RichEdit3: TRichEdit
    Left = 208
    Top = 53
    Width = 49
    Height = 22
    TabStop = False
    Alignment = taCenter
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'kg/ha')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 11
  end
end
