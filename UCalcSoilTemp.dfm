object frmCalcSoilTemp: TfrmCalcSoilTemp
  Left = 458
  Top = 199
  BorderIcons = [biHelp]
  BorderStyle = bsDialog
  Caption = 'Climate'
  ClientHeight = 540
  ClientWidth = 449
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object cmdMinTemp: TSpeedButton
    Left = 393
    Top = 56
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdMinTempClick
  end
  object cmdMaxTemp: TSpeedButton
    Left = 393
    Top = 80
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdMaxTempClick
  end
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 337
    Height = 13
    Caption = 
      '* If you want to open a new climate file, you can do it in the c' +
      'limate form'
  end
  object Label2: TLabel
    Left = 392
    Top = 36
    Width = 10
    Height = 13
    Caption = '(*)'
  end
  object cmdCancel: TBitBtn
    Left = 280
    Top = 504
    Width = 75
    Height = 25
    Caption = '&Cancel'
    TabOrder = 4
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
    Left = 360
    Top = 504
    Width = 75
    Height = 25
    Caption = '&Apply'
    Default = True
    TabOrder = 5
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
  object Edit2: TEdit
    Left = 9
    Top = 32
    Width = 113
    Height = 21
    TabStop = False
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 6
    Text = 'Climate file (*)'
  end
  object edPathFile: TEdit
    Left = 123
    Top = 32
    Width = 262
    Height = 21
    TabStop = False
    Color = 15395562
    Enabled = False
    ReadOnly = True
    TabOrder = 0
  end
  object sgClimate: TStringGrid
    Left = 77
    Top = 304
    Width = 272
    Height = 185
    TabStop = False
    ColCount = 4
    RowCount = 367
    FixedRows = 2
    TabOrder = 3
    RowHeights = (
      24
      15
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24
      24)
  end
  object Edit5: TEdit
    Left = 9
    Top = 56
    Width = 113
    Height = 21
    TabStop = False
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 7
    Text = 'Minimum temperature'
  end
  object Edit6: TEdit
    Left = 9
    Top = 80
    Width = 113
    Height = 21
    TabStop = False
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 8
    Text = 'Maximum temperature'
  end
  object edMinTemp: TEdit
    Left = 123
    Top = 56
    Width = 262
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 1
  end
  object edMaxTemp: TEdit
    Left = 123
    Top = 80
    Width = 262
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 2
  end
  object RichEdit36: TRichEdit
    Left = 8
    Top = 125
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
      'Kind of soil texture')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 9
  end
  object cbSoilTexture: TComboBox
    Left = 134
    Top = 125
    Width = 107
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 10
  end
  object RichEdit5: TRichEdit
    Left = 8
    Top = 150
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
      'Soil depth')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 11
  end
  object edSoilDepth: TEdit
    Left = 136
    Top = 155
    Width = 65
    Height = 21
    TabOrder = 12
  end
  object RichEdit6: TRichEdit
    Left = 208
    Top = 157
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
      'm')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 13
  end
  object RichEdit8: TRichEdit
    Left = 8
    Top = 187
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
      'Maximum soil depth')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 14
  end
  object edMaxDepth: TEdit
    Left = 136
    Top = 193
    Width = 65
    Height = 21
    TabOrder = 15
  end
  object RichEdit9: TRichEdit
    Left = 208
    Top = 192
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
      'cm')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 16
  end
  object butGenSoilTemp: TButton
    Left = 98
    Top = 232
    Width = 229
    Height = 57
    Caption = 'Generate Soil Temperature'
    TabOrder = 17
    OnClick = butGenSoilTempClick
  end
  object butSaveET0: TButton
    Left = 144
    Top = 504
    Width = 131
    Height = 25
    Caption = 'Save Soil Temperature ...'
    TabOrder = 18
    OnClick = butSaveET0Click
  end
  object odClimate: TOpenDialog
    Options = [ofHideReadOnly, ofNoChangeDir, ofEnableSizing]
    Left = 9
    Top = 416
  end
  object sdResult: TSaveDialog
    DefaultExt = 'csv'
    Filter = 'CSV (Comma delimited) (*.csv)|*.csv'
    Title = 'Save ...'
    Left = 56
    Top = 496
  end
end
