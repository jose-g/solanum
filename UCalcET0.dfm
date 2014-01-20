object frmCalcET0: TfrmCalcET0
  Left = 360
  Top = 169
  BorderIcons = [biHelp]
  BorderStyle = bsDialog
  Caption = 'Calculator ET0'
  ClientHeight = 634
  ClientWidth = 531
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
    Left = 481
    Top = 56
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdMinTempClick
  end
  object cmdMaxTemp: TSpeedButton
    Left = 481
    Top = 80
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdMaxTempClick
  end
  object cmdRad: TSpeedButton
    Left = 481
    Top = 104
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdRadClick
  end
  object cmdSunshine: TSpeedButton
    Left = 481
    Top = 160
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdSunshineClick
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
    Left = 480
    Top = 34
    Width = 10
    Height = 13
    Caption = '(*)'
  end
  object cmdCancel: TBitBtn
    Left = 360
    Top = 592
    Width = 75
    Height = 25
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
    Left = 440
    Top = 592
    Width = 75
    Height = 25
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
    TabOrder = 7
    Text = 'Climate file (*)'
  end
  object edPathFile: TEdit
    Left = 123
    Top = 32
    Width = 350
    Height = 21
    TabStop = False
    Color = 15395562
    Enabled = False
    ReadOnly = True
    TabOrder = 0
  end
  object sgClimate: TStringGrid
    Left = 34
    Top = 192
    Width = 464
    Height = 185
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
    TabOrder = 8
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
    TabOrder = 9
    Text = 'Maximum temperature'
  end
  object Edit8: TEdit
    Left = 9
    Top = 104
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
    TabOrder = 10
    Text = 'Radiation'
  end
  object edMinTemp: TEdit
    Left = 123
    Top = 56
    Width = 350
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 1
  end
  object edMaxTemp: TEdit
    Left = 123
    Top = 80
    Width = 350
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 2
  end
  object edRad: TEdit
    Left = 123
    Top = 104
    Width = 350
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 3
  end
  object Edit3: TEdit
    Left = 9
    Top = 160
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
    TabOrder = 11
    Text = 'Sunshine'
  end
  object edSunshine: TEdit
    Left = 123
    Top = 160
    Width = 350
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 12
  end
  object RichEdit14: TRichEdit
    Left = 8
    Top = 406
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
      'Latitude degrees')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 13
  end
  object edLatDegree: TEdit
    Left = 136
    Top = 406
    Width = 65
    Height = 21
    TabOrder = 14
  end
  object RichEdit17: TRichEdit
    Left = 208
    Top = 405
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
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 15
  end
  object RichEdit1: TRichEdit
    Left = 8
    Top = 430
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
      'Latitude minutes')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 16
  end
  object edLatMinutes: TEdit
    Left = 136
    Top = 430
    Width = 65
    Height = 21
    TabOrder = 17
  end
  object RichEdit2: TRichEdit
    Left = 208
    Top = 429
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
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 18
  end
  object RichEdit3: TRichEdit
    Left = 8
    Top = 454
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
      'Latitude seconds')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 19
  end
  object edLatSeconds: TEdit
    Left = 136
    Top = 454
    Width = 65
    Height = 21
    TabOrder = 20
  end
  object RichEdit4: TRichEdit
    Left = 208
    Top = 453
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
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 21
  end
  object RichEdit5: TRichEdit
    Left = 8
    Top = 478
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
      'Hemisphere')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 22
  end
  object cbHemisphere: TComboBox
    Left = 136
    Top = 478
    Width = 97
    Height = 22
    Style = csOwnerDrawVariable
    ItemHeight = 16
    TabOrder = 23
    Items.Strings = (
      'Northern'
      'Southern')
  end
  object RichEdit6: TRichEdit
    Left = 8
    Top = 502
    Width = 121
    Height = 35
    TabStop = False
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -11
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
    Left = 136
    Top = 509
    Width = 65
    Height = 21
    TabOrder = 25
  end
  object RichEdit7: TRichEdit
    Left = 208
    Top = 509
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
    TabOrder = 26
  end
  object RichEdit8: TRichEdit
    Left = 8
    Top = 542
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
      'Soil heat flux density')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 27
  end
  object edG: TEdit
    Left = 136
    Top = 542
    Width = 65
    Height = 21
    TabOrder = 28
  end
  object RichEdit9: TRichEdit
    Left = 208
    Top = 541
    Width = 65
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
      'MJ.m-2.d-1')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 29
  end
  object RichEdit10: TRichEdit
    Left = 8
    Top = 566
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
      'Albedo')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 30
  end
  object edAlbedo: TEdit
    Left = 136
    Top = 566
    Width = 65
    Height = 21
    TabOrder = 31
  end
  object RichEdit11: TRichEdit
    Left = 208
    Top = 565
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
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 32
  end
  object RichEdit12: TRichEdit
    Left = 288
    Top = 406
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
      'Kind of wind')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 33
  end
  object cbSelect_Wind_cat: TComboBox
    Left = 416
    Top = 406
    Width = 97
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
    Left = 288
    Top = 430
    Width = 121
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
    TabOrder = 35
    Text = 'Thermal conditions'
  end
  object cbThermalCond: TComboBox
    Left = 416
    Top = 430
    Width = 97
    Height = 22
    Style = csOwnerDrawVariable
    ItemHeight = 16
    TabOrder = 36
    Items.Strings = (
      'Cold'
      'Temperate'
      'Warm')
  end
  object RichEdit13: TRichEdit
    Left = 288
    Top = 454
    Width = 225
    Height = 35
    TabStop = False
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -11
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
    Left = 288
    Top = 494
    Width = 225
    Height = 22
    Style = csOwnerDrawVariable
    ItemHeight = 16
    TabOrder = 38
    Items.Strings = (
      'Andean region Frere et al 1975'
      'A.Von Humbolt, Peru Baigorria et al 2004'
      'Weberbaur,Peru Baigorria et al 2004'
      'Huayao, Peru Baigorria et al 2004'
      'Puno, Peru Baigorria et al 2004'
      
        'Patna, India (regression estimated) M. Akhlaque Ahmed et al., 20' +
        '09'
      'San Ramon, Peru Baigorria et al 2004')
  end
  object butGenerateET0: TButton
    Left = 304
    Top = 536
    Width = 193
    Height = 33
    Caption = 'Generate ET0'
    TabOrder = 39
    OnClick = butGenerateET0Click
  end
  object chbSunshine: TCheckBox
    Left = 8
    Top = 136
    Width = 177
    Height = 17
    Caption = 'I have sunshine data'
    TabOrder = 40
    OnClick = chbSunshineClick
  end
  object butSaveET0: TButton
    Left = 280
    Top = 592
    Width = 75
    Height = 25
    Caption = 'Save ET0 ...'
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
