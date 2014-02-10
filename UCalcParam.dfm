object frmCalcParam: TfrmCalcParam
  Left = 59
  Top = 136
  Width = 1792
  Height = 1108
  BorderIcons = [biSystemMenu, biMaximize]
  Caption = 'Parameter Calculator'
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
    Left = 444
    Top = 69
    Width = 29
    Height = 27
    Caption = '...'
    Visible = False
    OnClick = cmdMinTempClick
  end
  object cmdMaxTemp: TSpeedButton
    Left = 444
    Top = 98
    Width = 29
    Height = 28
    Caption = '...'
    Visible = False
    OnClick = cmdMaxTempClick
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
    Left = 443
    Top = 44
    Width = 13
    Height = 16
    Caption = '(*)'
  end
  object Label7: TLabel
    Left = 1477
    Top = 719
    Width = 79
    Height = 16
    Caption = 'Variety name'
  end
  object Label8: TLabel
    Left = 581
    Top = 10
    Width = 34
    Height = 16
    Caption = 'EDay'
    Visible = False
  end
  object Label9: TLabel
    Left = 788
    Top = 69
    Width = 38
    Height = 16
    Caption = 'Wmax'
    Visible = False
  end
  object Label10: TLabel
    Left = 788
    Top = 108
    Width = 9
    Height = 16
    Caption = 'A'
    Visible = False
  end
  object Label11: TLabel
    Left = 926
    Top = 10
    Width = 49
    Height = 16
    Caption = 'cover1p'
    Visible = False
  end
  object Label12: TLabel
    Left = 926
    Top = 118
    Width = 69
    Height = 16
    Caption = 'GrowthZero'
    Visible = False
  end
  object Label13: TLabel
    Left = 1552
    Top = 620
    Width = 29
    Height = 16
    Caption = 'RUE'
    Visible = False
  end
  object Label14: TLabel
    Left = 1647
    Top = 689
    Width = 30
    Height = 16
    Caption = 'DMC'
    Visible = False
  end
  object Label15: TLabel
    Left = 1252
    Top = 12
    Width = 153
    Height = 16
    Caption = 'GrowthZero2 for gompertz'
    Visible = False
  end
  object RichEdit6: TRichEdit
    Left = 1631
    Top = 638
    Width = 58
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
      'g/MJ '
      'PAR')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 40
    Visible = False
  end
  object cmdCancel: TBitBtn
    Left = 1457
    Top = 926
    Width = 189
    Height = 30
    Caption = '&Close'
    TabOrder = 33
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
    TabOrder = 1
    Text = 'Climate file (*)'
  end
  object edPathFile: TEdit
    Left = 151
    Top = 39
    Width = 283
    Height = 24
    TabStop = False
    Color = 15395562
    Enabled = False
    ReadOnly = True
    TabOrder = 10
  end
  object sgClimate: TStringGrid
    Left = 16
    Top = 148
    Width = 517
    Height = 227
    TabStop = False
    ColCount = 6
    RowCount = 367
    FixedRows = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSelect]
    PopupMenu = GridMenu
    TabOrder = 0
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
    TabOrder = 2
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
    TabOrder = 3
    Text = 'Maximum temperature'
  end
  object edMinTemp: TEdit
    Left = 151
    Top = 69
    Width = 283
    Height = 24
    TabStop = False
    Color = 15395562
    Enabled = False
    ReadOnly = True
    TabOrder = 11
  end
  object edMaxTemp: TEdit
    Left = 151
    Top = 98
    Width = 283
    Height = 24
    TabStop = False
    Color = 15395562
    Enabled = False
    ReadOnly = True
    TabOrder = 12
  end
  object butProcess: TButton
    Left = 800
    Top = 591
    Width = 282
    Height = 40
    Caption = 'Calculate parameters ...'
    TabOrder = 26
    OnClick = butProcessClick
  end
  object butSaveTT: TButton
    Left = 1457
    Top = 876
    Width = 191
    Height = 31
    Caption = 'Save Thermal time'
    TabOrder = 32
    OnClick = butSaveTTClick
  end
  object Edit9: TEdit
    Left = 542
    Top = 177
    Width = 123
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
    TabOrder = 4
    Text = 'Planting date'
  end
  object Edit12: TEdit
    Left = 542
    Top = 256
    Width = 123
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
    TabOrder = 5
    Text = 'Harvest date'
  end
  object dtpHarvestDate: TDateTimePicker
    Left = 542
    Top = 286
    Width = 119
    Height = 24
    CalAlignment = dtaLeft
    Date = 33156.3422648727
    Time = 33156.3422648727
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 14
  end
  object dtpPlantingDate: TDateTimePicker
    Left = 542
    Top = 207
    Width = 119
    Height = 24
    CalAlignment = dtaLeft
    Date = 284.342264872699
    Time = 284.342264872699
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 13
  end
  object sgClimateSel: TStringGrid
    Left = 676
    Top = 148
    Width = 517
    Height = 424
    TabStop = False
    ColCount = 7
    RowCount = 367
    FixedRows = 2
    TabOrder = 6
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
  object butSelectData: TButton
    Left = 551
    Top = 325
    Width = 93
    Height = 31
    Caption = 'Select data'
    TabOrder = 15
    OnClick = butSelectDataClick
  end
  object tchCanopy: TChart
    Left = 20
    Top = 404
    Width = 641
    Height = 307
    Legend.Alignment = laLeft
    Legend.CustomPosition = True
    Legend.Left = 70
    Legend.LegendStyle = lsSeries
    Legend.ResizeChart = False
    Legend.Top = 10
    Title.Text.Strings = (
      'Growth functions')
    BottomAxis.Automatic = False
    BottomAxis.AutomaticMaximum = False
    BottomAxis.AutomaticMinimum = False
    BottomAxis.AxisValuesFormat = '###0.###'
    BottomAxis.ExactDateTime = False
    BottomAxis.Increment = 500
    BottomAxis.LabelStyle = talValue
    BottomAxis.Maximum = 2000
    BottomAxis.Title.Caption = 'Thermal time'
    LeftAxis.Automatic = False
    LeftAxis.AutomaticMaximum = False
    LeftAxis.AutomaticMinimum = False
    LeftAxis.Maximum = 1
    LeftAxis.Title.Caption = 'Y'
    View3D = False
    TabOrder = 7
    object Series3: TLineSeries
      Marks.Callout.Brush.Color = clBlack
      Marks.Visible = False
      Title = 'Canopy Cover'
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series1: TLineSeries
      Marks.Callout.Brush.Color = clBlack
      Marks.Visible = False
      SeriesColor = clBlue
      Title = 'Tuber Partition'
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
  object tchf1f2: TChart
    Left = 20
    Top = 729
    Width = 641
    Height = 307
    Legend.CustomPosition = True
    Legend.Left = 355
    Legend.ResizeChart = False
    Legend.Top = 10
    Title.Text.Strings = (
      'Derivatives')
    BottomAxis.Automatic = False
    BottomAxis.AutomaticMaximum = False
    BottomAxis.AutomaticMinimum = False
    BottomAxis.AxisValuesFormat = '###0.###'
    BottomAxis.ExactDateTime = False
    BottomAxis.Increment = 500
    BottomAxis.LabelsSeparation = 100
    BottomAxis.LabelStyle = talValue
    BottomAxis.Maximum = 2000
    BottomAxis.Title.Caption = 'Thermal time'
    LeftAxis.LabelsAngle = 90
    LeftAxis.LabelStyle = talValue
    LeftAxis.Title.Caption = 'Rate canopy cover'
    RightAxis.AxisValuesFormat = '#.# x10E-#'
    RightAxis.LabelsAngle = 90
    RightAxis.LabelStyle = talValue
    View3D = False
    TabOrder = 8
    object Series2: TLineSeries
      Marks.Callout.Brush.Color = clBlack
      Marks.Callout.Length = 0
      Marks.Visible = False
      Title = 'f'#39'(Canopy cover)'
      ClickableLine = False
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series4: TLineSeries
      Marks.Callout.Brush.Color = clBlack
      Marks.Callout.Length = 0
      Marks.Visible = False
      SeriesColor = clBlue
      Title = 'f'#39#39'(Tuber partition)'
      VertAxis = aRightAxis
      ClickableLine = False
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
  object GroupBox1: TGroupBox
    Left = 1221
    Top = 128
    Width = 513
    Height = 484
    Caption = '  Parameters  '
    TabOrder = 25
    object Label3: TLabel
      Left = 59
      Top = 59
      Width = 10
      Height = 16
      Caption = 'tu'
    end
    object Label4: TLabel
      Left = 59
      Top = 148
      Width = 8
      Height = 16
      Caption = 'b'
    end
    object Label5: TLabel
      Left = 59
      Top = 236
      Width = 11
      Height = 16
      Caption = 'te'
    end
    object Label6: TLabel
      Left = 59
      Top = 325
      Width = 14
      Height = 16
      Caption = 'tm'
    end
    object RichEdit16: TRichEdit
      Left = 89
      Top = 48
      Width = 158
      Height = 41
      TabStop = False
      BiDiMode = bdLeftToRight
      Color = 3696250
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Lines.Strings = (
        'TT at maximum tuber '
        'partition rate')
      ParentBiDiMode = False
      ParentFont = False
      ReadOnly = True
      TabOrder = 0
    end
    object edtu: TEdit
      Left = 256
      Top = 55
      Width = 80
      Height = 24
      TabOrder = 1
      OnKeyPress = edtuKeyPress
    end
    object RichEdit24: TRichEdit
      Left = 345
      Top = 54
      Width = 60
      Height = 27
      TabStop = False
      BiDiMode = bdLeftToRight
      Color = 3696250
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Lines.Strings = (
        #176'Cd')
      ParentBiDiMode = False
      ParentFont = False
      ReadOnly = True
      TabOrder = 2
    end
    object RichEdit11: TRichEdit
      Left = 89
      Top = 135
      Width = 158
      Height = 41
      TabStop = False
      BiDiMode = bdLeftToRight
      Color = 3696250
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Lines.Strings = (
        'TT just before the tuber '
        'initiation process')
      ParentBiDiMode = False
      ParentFont = False
      ReadOnly = True
      TabOrder = 3
    end
    object edb: TEdit
      Left = 256
      Top = 143
      Width = 80
      Height = 24
      TabOrder = 4
      OnKeyPress = edbKeyPress
    end
    object RichEdit3: TRichEdit
      Left = 89
      Top = 223
      Width = 158
      Height = 40
      TabStop = False
      BiDiMode = bdLeftToRight
      Color = 3696250
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Lines.Strings = (
        'TT at maximum canopy '
        'cover')
      ParentBiDiMode = False
      ParentFont = False
      ReadOnly = True
      TabOrder = 5
    end
    object edte: TEdit
      Left = 256
      Top = 230
      Width = 80
      Height = 24
      TabOrder = 6
      OnKeyPress = edteKeyPress
    end
    object Edit15: TEdit
      Left = 345
      Top = 230
      Width = 60
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
      Text = #176'Cd'
    end
    object RichEdit2: TRichEdit
      Left = 89
      Top = 311
      Width = 158
      Height = 41
      TabStop = False
      BiDiMode = bdLeftToRight
      Color = 3696250
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      Lines.Strings = (
        'TT at the maximum '
        'canopy cover growth rate')
      ParentBiDiMode = False
      ParentFont = False
      ReadOnly = True
      TabOrder = 8
    end
    object edtm: TEdit
      Left = 256
      Top = 319
      Width = 80
      Height = 24
      TabOrder = 9
      OnKeyPress = edtmKeyPress
    end
    object Edit1: TEdit
      Left = 345
      Top = 319
      Width = 60
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
      Text = #176'Cd'
    end
    object butDoSimulation: TButton
      Left = 185
      Top = 423
      Width = 145
      Height = 31
      Caption = 'Adjust parameters'
      TabOrder = 11
      OnClick = butDoSimulationClick
    end
    object tb_tu: TTrackBar
      Left = 84
      Top = 92
      Width = 336
      Height = 41
      Max = 50
      Min = -50
      Orientation = trHorizontal
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 12
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = tb_tuChange
      OnEnter = tb_tuEnter
    end
    object tb_b: TTrackBar
      Left = 84
      Top = 181
      Width = 336
      Height = 41
      Max = 50
      Min = -50
      Orientation = trHorizontal
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 13
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = tb_bChange
      OnEnter = tb_bEnter
    end
    object tb_te: TTrackBar
      Left = 84
      Top = 270
      Width = 336
      Height = 40
      Max = 50
      Min = -50
      Orientation = trHorizontal
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 14
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = tb_teChange
      OnEnter = tb_teEnter
    end
    object tb_tm: TTrackBar
      Left = 84
      Top = 358
      Width = 336
      Height = 41
      Max = 50
      Min = -50
      Orientation = trHorizontal
      Frequency = 1
      Position = 0
      SelEnd = 0
      SelStart = 0
      TabOrder = 15
      TickMarks = tmBottomRight
      TickStyle = tsAuto
      OnChange = tb_tmChange
      OnEnter = tb_tmEnter
    end
    object Edit16: TEdit
      Left = 345
      Top = 142
      Width = 60
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
      TabOrder = 16
      Text = #176'Cd'
    end
  end
  object Edit3: TEdit
    Left = 492
    Top = 30
    Width = 198
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
    Text = 'Emergence day'
  end
  object edEmDay: TEdit
    Left = 699
    Top = 30
    Width = 80
    Height = 24
    TabOrder = 16
  end
  object RichEdit19: TRichEdit
    Left = 788
    Top = 30
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
    Lines.Strings = (
      'dap')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 24
  end
  object RichEdit8: TRichEdit
    Left = 492
    Top = 65
    Width = 198
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
      'Maximum canopy cover index')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 27
  end
  object edMaxgc: TEdit
    Left = 699
    Top = 63
    Width = 80
    Height = 24
    TabOrder = 17
  end
  object Edit8: TEdit
    Left = 866
    Top = 30
    Width = 199
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
    TabOrder = 34
    Text = 'Days to reach 1% canopy cover'
  end
  object RichEdit9: TRichEdit
    Left = 866
    Top = 65
    Width = 199
    Height = 45
    TabStop = False
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Days at maximum canopy cover ')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 35
  end
  object edGrowthZero: TEdit
    Left = 1073
    Top = 84
    Width = 80
    Height = 24
    TabOrder = 20
    Text = '75'
  end
  object edcover1p: TEdit
    Left = 1073
    Top = 30
    Width = 80
    Height = 24
    TabOrder = 19
    Text = '19'
  end
  object RichEdit10: TRichEdit
    Left = 492
    Top = 101
    Width = 198
    Height = 28
    TabStop = False
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Maximum harvest index')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 36
  end
  object edA: TEdit
    Left = 699
    Top = 101
    Width = 80
    Height = 24
    TabOrder = 18
  end
  object GroupBox2: TGroupBox
    Left = 1349
    Top = 975
    Width = 326
    Height = 178
    Caption = '  After Simulation  '
    TabOrder = 28
    Visible = False
    object Edit7: TEdit
      Left = 16
      Top = 89
      Width = 143
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
      TabOrder = 0
      Text = 'Minimum fresh yield'
    end
    object Edit10: TEdit
      Left = 16
      Top = 128
      Width = 143
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
      TabOrder = 1
      Text = 'Maximum fresh yield'
    end
    object Edit13: TEdit
      Left = 167
      Top = 89
      Width = 80
      Height = 24
      TabOrder = 2
    end
    object Edit14: TEdit
      Left = 167
      Top = 128
      Width = 80
      Height = 24
      TabOrder = 3
    end
  end
  object RichEdit1: TRichEdit
    Left = 1162
    Top = 30
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
    Lines.Strings = (
      'dap')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 37
  end
  object RichEdit4: TRichEdit
    Left = 1162
    Top = 82
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
      'dap')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 38
  end
  object butSavePar: TButton
    Left = 1457
    Top = 827
    Width = 191
    Height = 31
    Caption = 'Save parameters'
    TabOrder = 31
    OnClick = butSaveParClick
  end
  object butAddParDB: TButton
    Left = 1457
    Top = 778
    Width = 191
    Height = 31
    Caption = 'Add parameter to DB'
    TabOrder = 30
    OnClick = butAddParDBClick
  end
  object edNameCrop: TEdit
    Left = 1477
    Top = 738
    Width = 149
    Height = 24
    TabOrder = 29
  end
  object RichEdit7: TRichEdit
    Left = 1381
    Top = 630
    Width = 153
    Height = 40
    TabStop = False
    BiDiMode = bdLeftToRight
    Color = 3696250
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Average radiation use '
      'efficiency')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 39
    Visible = False
  end
  object edRUE: TEdit
    Left = 1542
    Top = 639
    Width = 80
    Height = 24
    TabOrder = 21
    Visible = False
  end
  object edDMC: TEdit
    Left = 1558
    Top = 679
    Width = 80
    Height = 24
    TabOrder = 22
    Visible = False
  end
  object Edit17: TEdit
    Left = 1381
    Top = 679
    Width = 172
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
    TabOrder = 41
    Text = 'Dry matter content of tubers'
    Visible = False
  end
  object tch1: TChart
    Left = 679
    Top = 689
    Width = 642
    Height = 356
    BottomWall.Color = 8454143
    Legend.Alignment = laLeft
    Legend.Bevel = bvRaised
    Legend.CheckBoxes = True
    Legend.CustomPosition = True
    Legend.Font.Style = [fsBold]
    Legend.FontSeriesColor = True
    Legend.Frame.Width = 2
    Legend.Left = 55
    Legend.ResizeChart = False
    Legend.Top = 20
    MarginLeft = 1
    MarginRight = 5
    Title.Brush.Color = clWhite
    Title.Color = 23737
    Title.Font.Shadow.Color = clBlack
    Title.Text.Strings = (
      'Fresh tuber yield')
    BottomAxis.Axis.Color = clWhite
    BottomAxis.LabelStyle = talValue
    BottomAxis.Title.Caption = 'days'
    LeftAxis.Axis.Color = clWhite
    LeftAxis.Title.Caption = 't / ha'
    View3D = False
    Zoom.Animated = True
    ParentColor = True
    TabOrder = 42
    PrintMargins = (
      15
      24
      15
      24)
    object Edit4: TEdit
      Left = 6
      Top = 325
      Width = 143
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
      TabOrder = 0
      Text = 'Expected fresh yield'
    end
    object Edit11: TEdit
      Left = 158
      Top = 325
      Width = 80
      Height = 24
      TabOrder = 1
    end
    object RichEdit5: TRichEdit
      Left = 246
      Top = 324
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
      Lines.Strings = (
        't / ha')
      ParentBiDiMode = False
      ParentFont = False
      ReadOnly = True
      TabOrder = 2
    end
    object LineSeries1: TLineSeries
      Marks.Callout.Brush.Color = clBlack
      Marks.DrawEvery = 20
      Marks.Style = smsValue
      Marks.Visible = False
      SeriesColor = clBlue
      Title = 'Fresh tuber yield'
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
      Data = {
        0019000000000000000000364000000000000051400000000000C05040000000
        00004066400000000000004D4000000000000052400000000000804940000000
        00000042400000000000804F4000000000000051400000000000805740000000
        0000804940000000000040574000000000004067400000000000507340000000
        0000E074400000000000D076400000000000D074400000000000307B40000000
        0000607840000000000020714000000000007077400000000000607440000000
        00007075400000000000107740}
    end
  end
  object tc1: TTeeCommander
    Left = 679
    Top = 650
    Width = 642
    Height = 40
    Panel = tchCanopy
    ParentShowHint = False
    TabOrder = 43
  end
  object RichEdit12: TRichEdit
    Left = 1236
    Top = 28
    Width = 198
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
      'Days at physiological maturity')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 44
  end
  object edGrowthZero2: TEdit
    Left = 1255
    Top = 55
    Width = 80
    Height = 24
    TabOrder = 23
    Text = '100'
  end
  object RichEdit13: TRichEdit
    Left = 1344
    Top = 55
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
    Lines.Strings = (
      'dap')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 45
  end
  object edtuberinit: TEdit
    Left = 1391
    Top = 87
    Width = 50
    Height = 24
    Enabled = False
    TabOrder = 46
    Text = '0'
  end
  object chkbtuberinit: TCheckBox
    Left = 1240
    Top = 88
    Width = 145
    Height = 17
    Caption = 'Use tuber initiation'
    TabOrder = 47
    OnClick = chkbtuberinitClick
  end
  object RichEdit14: TRichEdit
    Left = 1448
    Top = 86
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
    Lines.Strings = (
      'dap')
    ParentBiDiMode = False
    ParentFont = False
    ReadOnly = True
    TabOrder = 48
  end
  object odClimate: TOpenDialog
    Options = [ofHideReadOnly, ofNoChangeDir, ofEnableSizing]
    Left = 353
  end
  object sdResult: TSaveDialog
    DefaultExt = 'csv'
    Filter = 'CSV (Comma delimited) (*.csv)|*.csv'
    Options = [ofHideReadOnly, ofNoChangeDir, ofEnableSizing]
    Title = 'Save ...'
    Left = 384
  end
  object GridMenu: TPopupMenu
    Left = 416
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
