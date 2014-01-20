object frmClimateAM: TfrmClimateAM
  Left = 538
  Top = 111
  BorderIcons = [biHelp]
  BorderStyle = bsDialog
  Caption = 'Climate'
  ClientHeight = 610
  ClientWidth = 732
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
  object cmdOpenClimate: TSpeedButton
    Left = 481
    Top = 8
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdOpenClimateClick
  end
  object cmdMinTemp: TSpeedButton
    Left = 481
    Top = 104
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdMinTempClick
  end
  object cmdMaxTemp: TSpeedButton
    Left = 481
    Top = 128
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdMaxTempClick
  end
  object cmdPrecip: TSpeedButton
    Left = 481
    Top = 152
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdPrecipClick
  end
  object cmdRadiation: TSpeedButton
    Left = 481
    Top = 176
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdRadiationClick
  end
  object cmdET0: TSpeedButton
    Left = 481
    Top = 200
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdET0Click
  end
  object cmdIrrigation: TSpeedButton
    Left = 481
    Top = 224
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdIrrigationClick
  end
  object cmdSoil: TSpeedButton
    Left = 481
    Top = 248
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdSoilClick
  end
  object cmdDay: TSpeedButton
    Left = 481
    Top = 32
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdDayClick
  end
  object cmdMonth: TSpeedButton
    Left = 481
    Top = 56
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdMonthClick
  end
  object cmdYear: TSpeedButton
    Left = 481
    Top = 80
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdYearClick
  end
  object cmdCancel: TBitBtn
    Left = 552
    Top = 488
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
    Left = 632
    Top = 488
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
    Top = 8
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
    Text = 'Climate file'
  end
  object edPathFile: TEdit
    Left = 123
    Top = 8
    Width = 350
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 0
  end
  object sgClimate: TStringGrid
    Left = 9
    Top = 280
    Width = 712
    Height = 185
    TabStop = False
    ColCount = 12
    RowCount = 367
    FixedRows = 2
    PopupMenu = GridMenu
    TabOrder = 5
    OnMouseDown = sgClimateMouseDown
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
    TabOrder = 9
    Text = 'Minimun temperature'
  end
  object Edit6: TEdit
    Left = 9
    Top = 128
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
    Text = 'Maximun temperature'
  end
  object Edit7: TEdit
    Left = 9
    Top = 152
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
    Text = 'Precipitation'
  end
  object Edit8: TEdit
    Left = 9
    Top = 176
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
    TabOrder = 12
    Text = 'Radiation'
  end
  object edMinTemp: TEdit
    Left = 123
    Top = 104
    Width = 350
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 1
  end
  object edMaxTemp: TEdit
    Left = 123
    Top = 128
    Width = 350
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 2
  end
  object edPrecip: TEdit
    Left = 123
    Top = 152
    Width = 350
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 3
  end
  object edRad: TEdit
    Left = 123
    Top = 176
    Width = 350
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 4
  end
  object Edit1: TEdit
    Left = 9
    Top = 200
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
    TabOrder = 13
    Text = 'Evapotranspiration'
  end
  object edET: TEdit
    Left = 123
    Top = 200
    Width = 350
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 14
  end
  object Edit4: TEdit
    Left = 9
    Top = 224
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
    TabOrder = 15
    Text = 'Irrigation'
  end
  object edIrri: TEdit
    Left = 123
    Top = 224
    Width = 350
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 16
  end
  object Edit10: TEdit
    Left = 9
    Top = 248
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
    TabOrder = 17
    Text = 'Soil temperature'
  end
  object edSoilTemp: TEdit
    Left = 123
    Top = 248
    Width = 350
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 18
  end
  object Edit3: TEdit
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
    TabOrder = 19
    Text = 'Day'
  end
  object edDay: TEdit
    Left = 123
    Top = 32
    Width = 350
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 20
  end
  object Edit11: TEdit
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
    TabOrder = 21
    Text = 'Month'
  end
  object edMonth: TEdit
    Left = 123
    Top = 56
    Width = 350
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 22
  end
  object Edit13: TEdit
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
    TabOrder = 23
    Text = 'Year'
  end
  object edYear: TEdit
    Left = 123
    Top = 80
    Width = 350
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 24
  end
  object Edit9: TEdit
    Left = 8
    Top = 480
    Width = 161
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
    TabOrder = 25
    Text = 'Planting date'
  end
  object Edit12: TEdit
    Left = 8
    Top = 512
    Width = 161
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
    TabOrder = 26
    Text = 'Harvest date'
  end
  object dtpPlantingDate: TDateTimePicker
    Left = 176
    Top = 480
    Width = 97
    Height = 21
    CalAlignment = dtaLeft
    Date = 34264.3422648727
    Time = 34264.3422648727
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 27
  end
  object dtpHarvestDate: TDateTimePicker
    Left = 176
    Top = 512
    Width = 97
    Height = 21
    CalAlignment = dtaLeft
    Date = 34447.3422648727
    Time = 34447.3422648727
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 28
  end
  object Edit14: TEdit
    Left = 8
    Top = 544
    Width = 161
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
    TabOrder = 29
    Text = 'Emergency days'
  end
  object edEmDay: TEdit
    Left = 176
    Top = 544
    Width = 65
    Height = 21
    TabOrder = 30
  end
  object RichEdit19: TRichEdit
    Left = 248
    Top = 544
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
      'day')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 31
  end
  object Button1: TButton
    Left = 320
    Top = 496
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 32
    OnClick = Button1Click
  end
  object Edit15: TEdit
    Left = 416
    Top = 496
    Width = 121
    Height = 21
    TabOrder = 33
    Text = 'Edit15'
  end
  object Edit16: TEdit
    Left = 416
    Top = 560
    Width = 121
    Height = 21
    TabOrder = 34
    Text = 'Edit16'
  end
  object Edit17: TEdit
    Left = 416
    Top = 528
    Width = 121
    Height = 21
    TabOrder = 35
    Text = 'Edit17'
  end
  object Edit18: TEdit
    Left = 536
    Top = 168
    Width = 121
    Height = 21
    TabOrder = 36
    Text = 'Edit18'
  end
  object odClimate: TOpenDialog
    DefaultExt = 'csv'
    Filter = 
      'CSV (Comma delimited) (*.csv)|*.csv|Formatted Text (Space delimi' +
      'ted) (*.prn)|*.prn'
    Options = [ofHideReadOnly, ofNoChangeDir, ofEnableSizing]
    Left = 17
    Top = 400
  end
  object GridMenu: TPopupMenu
    Left = 560
    Top = 104
    object SetPlantingDate: TMenuItem
      Caption = 'Set planting date'
      OnClick = SetPlantingDateClick
    end
    object SetHarvestDate: TMenuItem
      Caption = 'Set harvest date'
      OnClick = SetHarvestDateClick
    end
  end
end
