object frmCalcParameter: TfrmCalcParameter
  Left = 290
  Top = 203
  BorderIcons = [biHelp]
  BorderStyle = bsDialog
  Caption = 'Climate'
  ClientHeight = 465
  ClientWidth = 425
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
    Left = 393
    Top = 8
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdOpenClimateClick
  end
  object cmdMinTemp: TSpeedButton
    Left = 393
    Top = 32
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdMinTempClick
  end
  object cmdMaxTemp: TSpeedButton
    Left = 393
    Top = 56
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdMaxTempClick
  end
  object cmdRad: TSpeedButton
    Left = 393
    Top = 80
    Width = 23
    Height = 22
    Caption = '...'
    OnClick = cmdRadClick
  end
  object cmdCancel: TBitBtn
    Left = 264
    Top = 424
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
    Left = 344
    Top = 424
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
    TabOrder = 7
    Text = 'Climate file'
  end
  object edPathFile: TEdit
    Left = 123
    Top = 8
    Width = 262
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 0
  end
  object sgClimate: TStringGrid
    Left = 77
    Top = 112
    Width = 272
    Height = 185
    TabStop = False
    ColCount = 4
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
    TabOrder = 8
    Text = 'Minimun temperature'
  end
  object Edit6: TEdit
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
    TabOrder = 9
    Text = 'Maximun temperature'
  end
  object Edit8: TEdit
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
    TabOrder = 10
    Text = 'Radiation'
  end
  object edMinTemp: TEdit
    Left = 123
    Top = 32
    Width = 262
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 1
  end
  object edMaxTemp: TEdit
    Left = 123
    Top = 56
    Width = 262
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 2
  end
  object edRad: TEdit
    Left = 123
    Top = 80
    Width = 262
    Height = 21
    TabStop = False
    Color = 15395562
    ReadOnly = True
    TabOrder = 3
  end
  object DateTimePicker1: TDateTimePicker
    Left = 176
    Top = 320
    Width = 97
    Height = 21
    CalAlignment = dtaLeft
    Date = 34264.3422648727
    Time = 34264.3422648727
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 11
  end
  object Edit4: TEdit
    Left = 8
    Top = 320
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
    TabOrder = 12
    Text = 'Planting date'
  end
  object Edit1: TEdit
    Left = 8
    Top = 352
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
    TabOrder = 13
    Text = 'Harvest date'
  end
  object DateTimePicker2: TDateTimePicker
    Left = 176
    Top = 352
    Width = 97
    Height = 21
    CalAlignment = dtaLeft
    Date = 34447.3422648727
    Time = 34447.3422648727
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 14
  end
  object Edit3: TEdit
    Left = 8
    Top = 384
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
    TabOrder = 15
    Text = 'Emergency days'
  end
  object butGetThermalTime: TButton
    Left = 288
    Top = 320
    Width = 113
    Height = 25
    Caption = 'Get Thermal Time'
    TabOrder = 16
    OnClick = butGetThermalTimeClick
  end
  object edEmDay: TEdit
    Left = 176
    Top = 384
    Width = 65
    Height = 21
    TabOrder = 17
  end
  object RichEdit19: TRichEdit
    Left = 248
    Top = 384
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
    TabOrder = 18
  end
  object odClimate: TOpenDialog
    DefaultExt = 'csv'
    Filter = 
      'CSV (Comma delimited) (*.csv)|*.csv|Formatted Text (Space delimi' +
      'ted) (*.prn)|*.prn'
    Options = [ofHideReadOnly, ofNoChangeDir, ofEnableSizing]
    Left = 17
    Top = 224
  end
end
