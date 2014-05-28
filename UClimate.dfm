object frmClimate: TfrmClimate
  Left = 459
  Top = 173
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Climate database'
  ClientHeight = 396
  ClientWidth = 997
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
    Left = 233
    Top = 168
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdMinTempClick
  end
  object cmdMaxTemp: TSpeedButton
    Left = 233
    Top = 192
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdMaxTempClick
  end
  object cmdPrecip: TSpeedButton
    Left = 233
    Top = 216
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdPrecipClick
  end
  object cmdRadiation: TSpeedButton
    Left = 233
    Top = 240
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdRadiationClick
  end
  object cmdET0: TSpeedButton
    Left = 233
    Top = 264
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdET0Click
  end
  object cmdIrrigation: TSpeedButton
    Left = 233
    Top = 288
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdIrrigationClick
  end
  object cmdSoil: TSpeedButton
    Left = 233
    Top = 312
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdSoilClick
  end
  object cmdDay: TSpeedButton
    Left = 233
    Top = 96
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdDayClick
  end
  object cmdMonth: TSpeedButton
    Left = 233
    Top = 120
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdMonthClick
  end
  object cmdYear: TSpeedButton
    Left = 233
    Top = 144
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdYearClick
  end
  object cmdSunshine: TSpeedButton
    Left = 233
    Top = 338
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdSunshineClick
  end
  object Bevel1: TBevel
    Left = 0
    Top = 56
    Width = 997
    Height = 3
  end
  object cmdCancel: TBitBtn
    Left = 816
    Top = 352
    Width = 75
    Height = 25
    Caption = '&Cancel'
    TabOrder = 6
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
    Left = 896
    Top = 352
    Width = 75
    Height = 25
    Caption = '&Apply'
    Default = True
    TabOrder = 7
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
    Top = 72
    Width = 113
    Height = 21
    TabStop = False
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 8
    Text = 'Climate file'
  end
  object edPathFile: TEdit
    Left = 123
    Top = 72
    Width = 862
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 0
  end
  object sgClimate: TStringGrid
    Left = 273
    Top = 104
    Width = 712
    Height = 233
    TabStop = False
    ColCount = 13
    RowCount = 367
    FixedRows = 2
    TabOrder = 5
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
    Top = 168
    Width = 113
    Height = 21
    TabStop = False
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 9
    Text = 'Minimum temperature'
  end
  object Edit6: TEdit
    Left = 9
    Top = 192
    Width = 113
    Height = 21
    TabStop = False
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 10
    Text = 'Maximum temperature'
  end
  object Edit7: TEdit
    Left = 9
    Top = 216
    Width = 113
    Height = 21
    TabStop = False
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 11
    Text = 'Precipitation'
  end
  object Edit8: TEdit
    Left = 9
    Top = 240
    Width = 113
    Height = 21
    TabStop = False
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 12
    Text = 'Radiation'
  end
  object edMinTemp: TEdit
    Left = 123
    Top = 168
    Width = 105
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 1
  end
  object edMaxTemp: TEdit
    Left = 123
    Top = 192
    Width = 105
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 2
  end
  object edPrecip: TEdit
    Left = 123
    Top = 216
    Width = 105
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 3
  end
  object edRad: TEdit
    Left = 123
    Top = 240
    Width = 105
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 4
  end
  object Edit1: TEdit
    Left = 9
    Top = 264
    Width = 113
    Height = 21
    TabStop = False
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 13
    Text = 'Evapotranspiration'
  end
  object edET: TEdit
    Left = 123
    Top = 264
    Width = 105
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 14
  end
  object Edit4: TEdit
    Left = 9
    Top = 288
    Width = 113
    Height = 21
    TabStop = False
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 15
    Text = 'Irrigation'
  end
  object edIrri: TEdit
    Left = 123
    Top = 288
    Width = 105
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 16
  end
  object Edit10: TEdit
    Left = 9
    Top = 312
    Width = 113
    Height = 21
    TabStop = False
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 17
    Text = 'Soil temperature'
  end
  object edSoilTemp: TEdit
    Left = 123
    Top = 312
    Width = 105
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 18
  end
  object Edit3: TEdit
    Left = 9
    Top = 96
    Width = 113
    Height = 21
    TabStop = False
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 19
    Text = 'Day'
  end
  object edDay: TEdit
    Left = 123
    Top = 96
    Width = 105
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 20
  end
  object Edit11: TEdit
    Left = 9
    Top = 120
    Width = 113
    Height = 21
    TabStop = False
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 21
    Text = 'Month'
  end
  object edMonth: TEdit
    Left = 123
    Top = 120
    Width = 105
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 22
  end
  object Edit13: TEdit
    Left = 9
    Top = 144
    Width = 113
    Height = 21
    TabStop = False
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 23
    Text = 'Year'
  end
  object edYear: TEdit
    Left = 123
    Top = 144
    Width = 105
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 24
  end
  object Edit9: TEdit
    Left = 9
    Top = 338
    Width = 113
    Height = 21
    TabStop = False
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 25
    Text = 'Sunshine'
  end
  object edSunshine: TEdit
    Left = 123
    Top = 338
    Width = 105
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 26
  end
  object butImportClimateData: TBitBtn
    Left = 8
    Top = 12
    Width = 209
    Height = 33
    Caption = 'Import climate data from ascii file'
    TabOrder = 27
    OnClick = butImportClimateDataClick
    Glyph.Data = {
      66090000424D660900000000000036000000280000001C0000001C0000000100
      18000000000030090000120B0000120B00000000000000000000A0A0A0A0A0A0
      A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0
      A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0
      A0A0A0A0A0A0A0A0A0A0A0A0A0A0FFFFFFF0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F1F1F1F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0A0
      A0A0FFFFFFF0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F1F1F1F0F0F0F0F0F0F1F1
      F1F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0000000000000000000000000000000F0F0
      F0F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      000000808000F0F0F0FFFF00FFFFFFFFFF00000000F0F0F0F0F0F0A0A0A0FFFF
      FFF0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0000000FFFF00F0F0F0FFFF00FFFFFF
      FFFFFFFFFF00808000000000F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0000000F0F0F0808000F0F0F0FFFF00FFFFFFFFFF00808000000000
      F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0000000FFFF00F0
      F0F0FFFF00FFFFFFFFFFFFFFFF00808000000000F0F0F0A0A0A0FFFFFFF0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0000000F0F0F0808000F0F0F0FFFF00FFFFFFFF
      FF00808000000000F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0000000FFFF00F0F0F0FFFF00FFFFFFFFFFFFFFFF00808000000000F0F0F0A0
      A0A0FFFFFFF0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0000000F0F0F00000000000
      00000000000000000000808000000000F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0000000000000808000FFFF00FFFF00FFFF00FFFF000000
      00000000F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0000000
      FFFFFFFFFFFF808000808000FFFF00FFFF00FFFF00000000F0F0F0A0A0A0FFFF
      FFF0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0000000FFFF00FFFFFFFFFFFF
      808000808000000000F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A0A0A0
      A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0000000000000000000000000000000F0F0F0F0F0F0
      F0F0F0A0A0A0FFFFFFF0F0F00000000000000000000000000000000000000000
      00000000000000000000000000A0A0A0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0
      000000F0F0F0000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0F0F00000
      00A0A0A0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0000080F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0000000FFFFFF000000FFFFFF
      808000808000808000808000FFFFFFF0F0F0000000A0A0A0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0000080000080000080F0F0F0F0F0F0F0F0F0F0F0F0A0
      A0A0FFFFFFF0F0F0000000F0F0F0000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFF0F0F0000000A0A0A0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0000080F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0000000FF
      FFFF000000FFFFFF808000808000808000808000FFFFFFF0F0F0000000A0A0A0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0000080F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0000000F0F0F0000000FFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFF0F0F0000000A0A0A0F0F0F0F0F0F0000080000080
      000080000080000080F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0A0A0A0FFFF
      FFF0F0F0000000FFFFFF000000FFFFFF808000808000808000808000FFFFFFF0
      F0F0000000A0A0A0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0000000F0F0F00000
      00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0F0F0000000A0A0A0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0A0A0A0FFFFFFF0F0F00000000000000000000000000000000000000000
      00000000000000000000000000A0A0A0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0
      000000F0F0F00000008080008080008080008080008080008080008080000000
      00A0A0A0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0000000000000000000000000
      000000000000000000000000000000000000000000F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0A0
      A0A0FFFFFFF0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0A0A0A0FFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFF}
  end
  object butLoadClimateDatabase: TBitBtn
    Left = 224
    Top = 12
    Width = 161
    Height = 33
    Caption = 'Open climate database'
    TabOrder = 28
    OnClick = butLoadClimateDatabaseClick
    Glyph.Data = {
      66090000424D660900000000000036000000280000001C0000001C0000000100
      18000000000030090000120B0000120B00000000000000000000A0A0A0A0A0A0
      A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0
      A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0
      A0A0A0A0A0A0A0A0A0A0A0A0A0A0FFFFFFF0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0A0
      A0A0FFFFFFF0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000F0F0F0F0F0F0A0A0A0FFFF
      FFF0F0F0F0F0F0A0A0A0F0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FF
      FFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFF
      F0F0F0FFFFFF000000F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A0FFFF
      FFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0
      F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0000000F0F0F0
      F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A0F0F0F0FFFFFFF0F0F00000000000
      00000000000000000000000000000000000000000000000000000000000000FF
      FFFFF0F0F0FFFFFFF0F0F0FFFFFF000000F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0
      F0F0F0A0A0A0FFFFFFF0F0F000000000000000FFFFF0F0F000FFFFF0F0F000FF
      FFF0F0F000FFFFF0F0F000FFFFF0F0F000FFFF000000FFFFFFF0F0F0FFFFFFF0
      F0F0000000F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A0F0F0F0FFFFFF
      00000000FFFF00000000FFFFF0F0F000FFFFF0F0F000FFFFF0F0F000FFFFF0F0
      F000FFFFF0F0F000FFFF000000FFFFFFF0F0F0FFFFFF000000F0F0F0F0F0F0A0
      A0A0FFFFFFF0F0F0F0F0F0A0A0A0FFFFFFF0F0F0000000FFFFFF000000F0F0F0
      00FFFFF0F0F000FFFFF0F0F000FFFFF0F0F000FFFFF0F0F000FFFFF0F0F00000
      00F0F0F0FFFFFFF0F0F0000000F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0
      A0A0F0F0F0FFFFFF00000000FFFFFFFFFF000000F0F0F000FFFFF0F0F000FFFF
      F0F0F000FFFFF0F0F000FFFFF0F0F000FFFFF0F0F0000000F0F0F0FFFFFF0000
      00F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A0FFFFFFF0F0F0000000FF
      FFFF00FFFFFFFFFF000000000000000000000000000000F0F0F000FFFFF0F0F0
      00FFFFF0F0F000FFFF000000FFFFFFF0F0F0000000F0F0F0F0F0F0A0A0A0FFFF
      FFF0F0F0F0F0F0A0A0A0F0F0F0FFFFFF00000000FFFFFFFFFF00FFFFFFFFFF00
      FFFFFFFFFF00FFFFFFFFFF000000000000000000000000000000000000FFFFFF
      F0F0F0FFFFFF000000F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A0FFFF
      FFF0F0F0000000FFFFFF00FFFFFFFFFF00FFFFFFFFFF00FFFFFFFFFF00FFFFFF
      FFFF00FFFFFFFFFF00FFFF000000FFFFFFF0F0F0FFFFFFF0F0F0000000F0F0F0
      F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A0F0F0F0FFFFFF00000000FFFFFFFF
      FF00FFFFFFFFFF00FFFFFFFFFF00FFFFFFFFFF00FFFFFFFFFF00FFFFFFFFFF00
      0000F0F0F0FFFFFFF0F0F0FFFFFF000000F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0
      F0F0F0A0A0A0FFFFFFF0F0F0000000FFFFFF00FFFFFFFFFF00FFFFFFFFFF00FF
      FFFFFFFF00FFFFFFFFFF00FFFFFFFFFF00FFFF000000FFFFFFF0F0F0FFFFFFF0
      F0F0000000F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A0F0F0F0FFFFFF
      00000000FFFFFFFFFF00FFFFFFFFFF00FFFF0000000000000000000000000000
      00000000000000FFFFFFF0F0F0FFFFFFF0F0F0FFFFFF000000F0F0F0F0F0F0A0
      A0A0FFFFFFF0F0F0F0F0F0A0A0A0FFFFFFF0F0F0FFFFFF000000000000000000
      000000000000FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFF
      FFF0F0F0FFFFFFF0F0F0000000F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0
      A0A0F0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFF
      F0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFF0000
      00F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A0FFFFFFF0F0F0FFFFFFF0
      F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0
      FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0000000F0F0F0F0F0F0A0A0A0FFFF
      FFF0F0F0F0F0F0A0A0A000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A0FFFF
      FF000000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF
      0000FF0000FF0000FF0000FF0000000000FFFFFF000000FFFFFF000000F0F0F0
      F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0
      A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0
      A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0A0
      A0A0FFFFFFF0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0A0A0A0FFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFF}
  end
  object butSaveClimateDatabase: TBitBtn
    Left = 392
    Top = 12
    Width = 161
    Height = 33
    Caption = 'Save climate database'
    TabOrder = 29
    OnClick = butSaveClimateDatabaseClick
    Glyph.Data = {
      66090000424D660900000000000036000000280000001C0000001C0000000100
      18000000000030090000120B0000120B00000000000000000000A0A0A0A0A0A0
      A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0
      A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0
      A0A0A0A0A0A0A0A0A0A0A0A0A0A0FFFFFFF0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0A0
      A0A0FFFFFFF0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000F0F0F0F0F0F0A0A0A0FFFF
      FFF0F0F0F0F0F0A0A0A0F0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FF
      FFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFF
      F0F0F0FFFFFF000000F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A0FFFF
      FFF0F0F0FFFFFFF0F0F000000000000000000000000000000000000000000000
      0000000000000000000000000000F0F0F0F0F0F0FFFFFFF0F0F0000000F0F0F0
      F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A0F0F0F0FFFFFFF0F0F0000000FFFF
      00FFFFFF000000F0F0F0FFFF00FFFF00FFFFFFF0F0F0F0F0F0000000FFFF00FF
      FFFF000000FFFFFFF0F0F0FFFFFF000000F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0
      F0F0F0A0A0A0FFFFFFF0F0F0FFFFFF000000FFFFFFFFFF00000000F0F0F0FFFF
      00FFFF00FFFFFFF0F0F0F0F0F0000000FFFFFFFFFF00000000F0F0F0FFFFFFF0
      F0F0000000F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A0F0F0F0FFFFFF
      F0F0F0000000FFFF00FFFFFF000000F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0000000FFFF00FFFFFF000000FFFFFFF0F0F0FFFFFF000000F0F0F0F0F0F0A0
      A0A0FFFFFFF0F0F0F0F0F0A0A0A0FFFFFFF0F0F0FFFFFF000000FFFFFFFFFF00
      808000000000000000000000000000000000000000808000FFFFFFFFFF000000
      00F0F0F0FFFFFFF0F0F0000000F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0
      A0A0F0F0F0FFFFFFF0F0F0000000FFFF00FFFFFFFFFF00FFFFFFFFFF00FFFFFF
      FFFF00FFFFFFFFFF00FFFFFFFFFF00FFFFFF000000FFFFFFF0F0F0FFFFFF0000
      00F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A0FFFFFFF0F0F0FFFFFF00
      0000FFFFFF808000000000000000000000000000000000000000000000000000
      808000FFFF00000000F0F0F0FFFFFFF0F0F0000000F0F0F0F0F0F0A0A0A0FFFF
      FFF0F0F0F0F0F0A0A0A0F0F0F0FFFFFFF0F0F0000000FFFF00000000FFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFF000000FFFFFF
      F0F0F0FFFFFF000000F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A0FFFF
      FFF0F0F0FFFFFF000000FFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFF000000FFFF00000000F0F0F0FFFFFFF0F0F0000000F0F0F0
      F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A0F0F0F0FFFFFFF0F0F0000000FFFF
      00000000FFFFFF800000800000800000FFFFFF800000800000FFFFFF000000FF
      FFFF000000FFFFFFF0F0F0FFFFFF000000F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0
      F0F0F0A0A0A0FFFFFFF0F0F0FFFFFF000000FFFFFF000000FFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFF00000000F0F0F0FFFFFFF0
      F0F0000000F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A0F0F0F0FFFFFF
      F0F0F0000000000000000000FFFFFF8000008000008000008000008000008000
      00FFFFFF000000000000000000FFFFFFF0F0F0FFFFFF000000F0F0F0F0F0F0A0
      A0A0FFFFFFF0F0F0F0F0F0A0A0A0FFFFFFF0F0F0FFFFFF000000F0F0F0000000
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000F0F0F00000
      00F0F0F0FFFFFFF0F0F0000000F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0
      A0A0F0F0F0FFFFFFF0F0F0F0F0F0000000000000000000000000000000000000
      000000000000000000000000000000000000F0F0F0FFFFFFF0F0F0FFFFFF0000
      00F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A0FFFFFFF0F0F0FFFFFFF0
      F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0
      FFFFFFF0F0F0FFFFFFF0F0F0FFFFFFF0F0F0000000F0F0F0F0F0F0A0A0A0FFFF
      FFF0F0F0F0F0F0A0A0A000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A0FFFF
      FF000000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF0000FF
      0000FF0000FF0000FF0000FF0000000000FFFFFF000000FFFFFF000000F0F0F0
      F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0
      A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0
      A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0A0F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0A0A0A0FFFFFFF0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0A0
      A0A0FFFFFFF0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0
      F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0A0A0A0FFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFF}
  end
  object odClimate: TOpenDialog
    DefaultExt = 'csv'
    Filter = 
      'CSV (Comma delimited) (*.csv)|*.csv|Formatted Text (Space delimi' +
      'ted) (*.prn)|*.prn'
    Options = [ofHideReadOnly, ofNoChangeDir, ofEnableSizing]
    Left = 297
    Top = 184
  end
  object sdSave: TSaveDialog
    DefaultExt = 'csv'
    Filter = 'CSV (Comma delimited) (*.csv)|*.csv'
    Title = 'Save climate setting ...'
    Left = 272
    Top = 344
  end
  object odClimateSetting: TOpenDialog
    DefaultExt = 'csv'
    Filter = 'CSV (Comma delimited) (*.csv)|*.csv'
    Options = [ofHideReadOnly, ofNoChangeDir, ofEnableSizing]
    Left = 305
    Top = 344
  end
end
