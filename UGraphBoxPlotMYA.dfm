object frmGraphBoxPlotMYA: TfrmGraphBoxPlotMYA
  Left = 445
  Top = 229
  Width = 769
  Height = 500
  Caption = 'Box plot (Past and Future scenarios)'
  Color = 140
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object tc1: TTeeCommander
    Left = 16
    Top = 8
    Width = 721
    Height = 33
    Panel = tch1
    Color = 4868757
    ParentShowHint = False
    TabOrder = 0
  end
  object tch1: TChart
    Left = 16
    Top = 41
    Width = 721
    Height = 408
    BottomWall.Color = 8454143
    Legend.Bevel = bvRaised
    Legend.CheckBoxes = True
    Legend.Color = 4473992
    Legend.CustomPosition = True
    Legend.Font.Style = [fsBold]
    Legend.FontSeriesColor = True
    Legend.Frame.Width = 2
    Legend.Left = 535
    Legend.ResizeChart = False
    Legend.Top = 41
    Legend.Visible = False
    MarginBottom = 6
    MarginLeft = 1
    MarginRight = 2
    Title.Brush.Color = clWhite
    Title.Color = 23737
    Title.Font.Color = clYellow
    Title.Font.Height = -16
    Title.Font.Style = [fsBold]
    Title.Font.Shadow.Color = clBlack
    Title.Text.Strings = (
      'FRESH TUBER YIELD')
    Title.Transparent = False
    BottomAxis.Axis.Color = clWhite
    BottomAxis.Labels = False
    BottomAxis.LabelsFont.Color = clWhite
    BottomAxis.LabelsFont.Style = [fsBold]
    BottomAxis.LabelStyle = talText
    BottomAxis.Title.Caption = 'Time'
    BottomAxis.Title.Font.Color = clLime
    BottomAxis.Title.Font.Style = [fsBold]
    BottomAxis.Title.Visible = False
    LeftAxis.Axis.Color = clWhite
    LeftAxis.LabelsFont.Color = clWhite
    LeftAxis.LabelsFont.Style = [fsBold]
    LeftAxis.Title.Font.Color = clLime
    LeftAxis.Title.Font.Style = [fsBold]
    MaxPointsPerPage = 6
    View3D = False
    Zoom.Animated = True
    Color = 3421287
    TabOrder = 1
    PrintMargins = (
      15
      24
      15
      24)
    object Label8: TLabel
      Left = 619
      Top = 18
      Width = 73
      Height = 13
      Caption = 'All scenarios'
      Color = 3421287
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
      Visible = False
    end
    object Label4: TLabel
      Left = 296
      Top = 384
      Width = 26
      Height = 13
      Caption = 'Past'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 416
      Top = 384
      Width = 37
      Height = 13
      Caption = 'Future'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
end
