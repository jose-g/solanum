object frmCalcET0: TfrmCalcET0
  Left = 591
  Top = 44
  BorderIcons = [biHelp]
  BorderStyle = bsDialog
  Caption = 'Calculator ET0 y Sunshine'
  ClientHeight = 780
  ClientWidth = 654
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object cmdMinTemp: TSpeedButton
    Left = 592
    Top = 69
    Width = 28
    Height = 27
    Caption = '...'
    OnClick = cmdMinTempClick
  end
  object cmdMaxTemp: TSpeedButton
    Left = 592
    Top = 98
    Width = 28
    Height = 28
    Caption = '...'
    OnClick = cmdMaxTempClick
  end
  object cmdRad: TSpeedButton
    Left = 592
    Top = 128
    Width = 28
    Height = 27
    Caption = '...'
    OnClick = cmdRadClick
  end
  object cmdSunshine: TSpeedButton
    Left = 592
    Top = 197
    Width = 28
    Height = 27
    Caption = '...'
    OnClick = cmdSunshineClick
  end
  object Label1: TLabel
    Left = 10
    Top = 10
    Width = 411
    Height = 16
    Caption = 
      '* If you want to open a new climate file, you can do it in the c' +
      'limate form'
  end
  object Label2: TLabel
    Left = 591
    Top = 42
    Width = 13
    Height = 16
    Caption = '(*)'
  end
  object cmdCancel: TBitBtn
    Left = 443
    Top = 729
    Width = 92
    Height = 30
    Caption = '&Cancel'
    TabOrder = 5
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
    Left = 542
    Top = 729
    Width = 92
    Height = 30
    Caption = '&Apply'
    Default = True
    TabOrder = 6
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
    Left = 11
    Top = 39
    Width = 139
    Height = 24
    TabStop = False
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 7
    Text = 'Climate file (*)'
  end
  object edPathFile: TEdit
    Left = 151
    Top = 39
    Width = 431
    Height = 24
    TabStop = False
    Color = 15395562
    Enabled = False
    ReadOnly = True
    TabOrder = 0
  end
  object sgClimate: TStringGrid
    Left = 42
    Top = 236
    Width = 571
    Height = 228
    TabStop = False
    ColCount = 6
    RowCount = 367
    FixedRows = 2
    TabOrder = 4
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
    Left = 11
    Top = 69
    Width = 139
    Height = 24
    TabStop = False
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 8
    Text = 'Minimum temperature'
  end
  object Edit6: TEdit
    Left = 11
    Top = 98
    Width = 139
    Height = 24
    TabStop = False
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 9
    Text = 'Maximum temperature'
  end
  object Edit8: TEdit
    Left = 11
    Top = 128
    Width = 139
    Height = 24
    TabStop = False
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 10
    Text = 'Radiation'
  end
  object edMinTemp: TEdit
    Left = 151
    Top = 69
    Width = 431
    Height = 24
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 1
  end
  object edMaxTemp: TEdit
    Left = 151
    Top = 98
    Width = 431
    Height = 24
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 2
  end
  object edRad: TEdit
    Left = 151
    Top = 128
    Width = 431
    Height = 24
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 3
  end
  object Edit3: TEdit
    Left = 11
    Top = 197
    Width = 139
    Height = 24
    TabStop = False
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 11
    Text = 'Sunshine'
  end
  object edSunshine: TEdit
    Left = 151
    Top = 197
    Width = 431
    Height = 24
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 12
  end
  object RichEdit14: TRichEdit
    Left = 10
    Top = 500
    Width = 149
    Height = 26
    TabStop = False
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Latitude degrees')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 13
  end
  object edLatDegree: TEdit
    Left = 167
    Top = 500
    Width = 80
    Height = 24
    TabOrder = 14
  end
  object RichEdit17: TRichEdit
    Left = 256
    Top = 498
    Width = 60
    Height = 28
    TabStop = False
    Alignment = taCenter
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 15
  end
  object RichEdit1: TRichEdit
    Left = 10
    Top = 529
    Width = 149
    Height = 26
    TabStop = False
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Latitude minutes')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 16
  end
  object edLatMinutes: TEdit
    Left = 167
    Top = 529
    Width = 80
    Height = 24
    TabOrder = 17
  end
  object RichEdit2: TRichEdit
    Left = 256
    Top = 528
    Width = 60
    Height = 27
    TabStop = False
    Alignment = taCenter
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 18
  end
  object RichEdit3: TRichEdit
    Left = 10
    Top = 559
    Width = 149
    Height = 26
    TabStop = False
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Latitude seconds')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 19
  end
  object edLatSeconds: TEdit
    Left = 167
    Top = 559
    Width = 80
    Height = 24
    TabOrder = 20
  end
  object RichEdit4: TRichEdit
    Left = 256
    Top = 558
    Width = 60
    Height = 27
    TabStop = False
    Alignment = taCenter
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 21
  end
  object RichEdit5: TRichEdit
    Left = 10
    Top = 588
    Width = 149
    Height = 26
    TabStop = False
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Hemisphere')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 22
  end
  object cbHemisphere: TComboBox
    Left = 167
    Top = 588
    Width = 120
    Height = 22
    Style = csOwnerDrawVariable
    ItemHeight = 16
    TabOrder = 23
    Items.Strings = (
      'Northern'
      'Southern')
  end
  object RichEdit6: TRichEdit
    Left = 10
    Top = 618
    Width = 149
    Height = 43
    TabStop = False
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Elevation above sea '
      'level')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 24
  end
  object edz: TEdit
    Left = 167
    Top = 626
    Width = 80
    Height = 24
    TabOrder = 25
  end
  object RichEdit7: TRichEdit
    Left = 256
    Top = 626
    Width = 60
    Height = 28
    TabStop = False
    Alignment = taCenter
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'm')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 26
  end
  object RichEdit8: TRichEdit
    Left = 10
    Top = 667
    Width = 149
    Height = 26
    TabStop = False
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Soil heat flux density')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 27
    Visible = False
  end
  object edG: TEdit
    Left = 167
    Top = 667
    Width = 80
    Height = 24
    TabOrder = 28
    Visible = False
  end
  object RichEdit9: TRichEdit
    Left = 256
    Top = 666
    Width = 80
    Height = 27
    TabStop = False
    Alignment = taCenter
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'MJ.m-2.d-1')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 29
    Visible = False
  end
  object RichEdit10: TRichEdit
    Left = 10
    Top = 697
    Width = 149
    Height = 25
    TabStop = False
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Albedo')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 30
  end
  object edAlbedo: TEdit
    Left = 167
    Top = 697
    Width = 80
    Height = 24
    TabOrder = 31
  end
  object RichEdit11: TRichEdit
    Left = 256
    Top = 695
    Width = 60
    Height = 27
    TabStop = False
    Alignment = taCenter
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 32
  end
  object RichEdit12: TRichEdit
    Left = 354
    Top = 500
    Width = 149
    Height = 26
    TabStop = False
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Kind of wind')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 33
  end
  object cbSelect_Wind_cat: TComboBox
    Left = 512
    Top = 500
    Width = 119
    Height = 22
    Style = csOwnerDrawVariable
    ItemHeight = 16
    TabOrder = 34
    Items.Strings = (
      'Weak'
      'Moderate'
      'Strong'
      'Calm')
  end
  object Edit9: TEdit
    Left = 354
    Top = 529
    Width = 149
    Height = 24
    TabStop = False
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 35
    Text = 'Thermal conditions'
    Visible = False
  end
  object cbThermalCond: TComboBox
    Left = 512
    Top = 529
    Width = 119
    Height = 22
    Style = csOwnerDrawVariable
    ItemHeight = 16
    TabOrder = 36
    Visible = False
    Items.Strings = (
      'Cold'
      'Temperate'
      'Warm')
  end
  object RichEdit13: TRichEdit
    Left = 354
    Top = 559
    Width = 277
    Height = 43
    TabStop = False
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Angstrom-Prescott Empirical transmissivity '
      'coefficients')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 37
  end
  object cbSelect_AP: TComboBox
    Left = 354
    Top = 608
    Width = 277
    Height = 22
    Style = csOwnerDrawVariable
    ItemHeight = 16
    TabOrder = 38
    Items.Strings = (
      'Andean region'
      'A.Von Humbolt, Peru'
      'Weberbaur,Peru'
      'Huayao, Peru'
      'Puno, Peru'
      'Patna, India'
      'San Ramon, Peru')
  end
  object butGenerateET0: TButton
    Left = 374
    Top = 660
    Width = 238
    Height = 40
    Caption = 'Generate ET0 y Sunshine'
    TabOrder = 39
    OnClick = butGenerateET0Click
  end
  object chbSunshine: TCheckBox
    Left = 10
    Top = 167
    Width = 218
    Height = 21
    Caption = 'I have sunshine data'
    TabOrder = 40
    OnClick = chbSunshineClick
  end
  object butSaveET0: TButton
    Left = 248
    Top = 729
    Width = 189
    Height = 30
    Caption = 'Save ET0 y Sunshine ...'
    TabOrder = 41
    OnClick = butSaveET0Click
  end
  object odClimate: TOpenDialog
    Options = [ofHideReadOnly, ofNoChangeDir, ofEnableSizing]
    Left = 497
    Top = 384
  end
  object sdResult: TSaveDialog
    DefaultExt = 'csv'
    Filter = 'CSV (Comma delimited) (*.csv)|*.csv'
    Title = 'Save ...'
    Left = 240
    Top = 592
  end
end
