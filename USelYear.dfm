object frmSelYear: TfrmSelYear
  Left = 667
  Top = 258
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Year selection'
  ClientHeight = 500
  ClientWidth = 350
  Color = clBtnFace
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
  object Label1: TLabel
    Left = 16
    Top = 11
    Width = 49
    Height = 13
    Caption = 'All years'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 224
    Top = 11
    Width = 26
    Height = 13
    Caption = 'Past'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 224
    Top = 235
    Width = 37
    Height = 13
    Caption = 'Future'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object cmdCancel: TBitBtn
    Left = 176
    Top = 464
    Width = 75
    Height = 25
    Caption = '&Cancel'
    TabOrder = 0
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
    Left = 256
    Top = 464
    Width = 75
    Height = 25
    Caption = '&Apply'
    Default = True
    TabOrder = 1
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
  object lbAllYears: TListBox
    Left = 8
    Top = 32
    Width = 121
    Height = 417
    ItemHeight = 13
    MultiSelect = True
    TabOrder = 2
  end
  object lbPast: TListBox
    Left = 216
    Top = 32
    Width = 121
    Height = 193
    ItemHeight = 13
    TabOrder = 3
  end
  object lbFuture: TListBox
    Left = 216
    Top = 256
    Width = 121
    Height = 193
    ItemHeight = 13
    TabOrder = 4
  end
  object buAddOneItemToPast: TButton
    Left = 152
    Top = 64
    Width = 41
    Height = 25
    Caption = '>'
    TabOrder = 5
    OnClick = buAddOneItemToPastClick
  end
  object butDelAllItemsFromPast: TButton
    Left = 140
    Top = 160
    Width = 65
    Height = 25
    Caption = 'Delete all'
    TabOrder = 6
    OnClick = butDelAllItemsFromPastClick
  end
  object butDelItemFromPast: TButton
    Left = 152
    Top = 128
    Width = 41
    Height = 25
    Caption = 'X'
    TabOrder = 7
    OnClick = butDelItemFromPastClick
  end
  object butAddAllToPast: TButton
    Left = 152
    Top = 96
    Width = 41
    Height = 25
    Caption = '>>'
    TabOrder = 8
    OnClick = butAddAllToPastClick
  end
  object buAddOneItemToFuture: TButton
    Left = 152
    Top = 296
    Width = 41
    Height = 25
    Caption = '>'
    TabOrder = 9
    OnClick = buAddOneItemToFutureClick
  end
  object butAddAllToFuture: TButton
    Left = 152
    Top = 328
    Width = 41
    Height = 25
    Caption = '>>'
    TabOrder = 10
    OnClick = butAddAllToFutureClick
  end
  object butDelItemFromFuture: TButton
    Left = 152
    Top = 360
    Width = 41
    Height = 25
    Caption = 'X'
    TabOrder = 11
    OnClick = butDelItemFromFutureClick
  end
  object butDelAllItemsFromFuture: TButton
    Left = 140
    Top = 392
    Width = 65
    Height = 25
    Caption = 'Delete all'
    TabOrder = 12
    OnClick = butDelAllItemsFromFutureClick
  end
end
