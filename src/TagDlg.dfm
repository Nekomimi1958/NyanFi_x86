object TagManDlg: TTagManDlg
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  ClientHeight = 291
  ClientWidth = 310
  Color = clBtnFace
  Constraints.MinHeight = 320
  Constraints.MinWidth = 320
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  KeyPreview = True
  Position = poDesigned
  ShowHint = True
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  TextHeight = 15
  object ListPanel: TPanel
    Left = 0
    Top = 23
    Width = 310
    Height = 158
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    OnResize = ListPanelResize
    DesignSize = (
      310
      158)
    object TagCheckListBox: TCheckListBox
      Left = 0
      Top = 0
      Width = 306
      Height = 158
      Align = alLeft
      Anchors = [akLeft, akTop, akRight, akBottom]
      BorderStyle = bsNone
      DoubleBuffered = True
      ItemHeight = 13
      ParentDoubleBuffered = False
      Style = lbOwnerDrawFixed
      TabOrder = 0
      OnClick = TagCheckListBoxClick
      OnClickCheck = TagCheckListBoxClickCheck
      OnDblClick = TagCheckListBoxDblClick
      OnDrawItem = TagCheckListBoxDrawItem
      OnKeyDown = TagCheckListBoxKeyDown
      OnKeyPress = TagCheckListBoxKeyPress
    end
    object BlankPanel: TPanel
      Left = 290
      Top = 142
      Width = 14
      Height = 14
      Anchors = [akRight, akBottom]
      AutoSize = True
      BevelOuter = bvNone
      Color = clAppWorkSpace
      ParentBackground = False
      TabOrder = 1
      Visible = False
      StyleElements = [seBorder]
      object ShowOptBtn: TSpeedButton
        Left = 0
        Top = 0
        Width = 14
        Height = 14
        Flat = True
        OnClick = ChgOptBtnClick
      end
    end
  end
  object OptPanel: TPanel
    Left = 0
    Top = 215
    Width = 310
    Height = 76
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    object InpOptPanel: TPanel
      Left = 0
      Top = 38
      Width = 310
      Height = 38
      Align = alBottom
      BevelOuter = bvNone
      TabOrder = 1
      DesignSize = (
        310
        38)
      object HideOptBtn: TSpeedButton
        Left = 293
        Top = 23
        Width = 18
        Height = 16
        Anchors = [akTop, akRight]
        Flat = True
        OnClick = ChgOptBtnClick
      end
      object CanButton: TButton
        Left = 215
        Top = 4
        Width = 76
        Height = 26
        Anchors = [akTop, akRight]
        Cancel = True
        Caption = #12461#12515#12531#12475#12523
        ModalResult = 2
        TabOrder = 2
        OnClick = CanButtonClick
      end
      object OkButton: TButton
        Left = 131
        Top = 4
        Width = 76
        Height = 26
        Anchors = [akTop, akRight]
        Caption = 'OK'
        Default = True
        ModalResult = 1
        TabOrder = 1
      end
      object HidePanel: TPanel
        Left = 0
        Top = 0
        Width = 128
        Height = 38
        Align = alLeft
        BevelOuter = bvNone
        TabOrder = 0
        object HideCheckBox: TCheckBox
          Left = 10
          Top = 8
          Width = 119
          Height = 17
          Action = HideAction
          Caption = #20837#21147#27396#12434#38560#12377'(&H)'
          TabOrder = 0
        end
      end
    end
    object FindOptPanel: TPanel
      Left = 0
      Top = 6
      Width = 310
      Height = 32
      Align = alBottom
      BevelOuter = bvNone
      TabOrder = 0
      object AndPanel: TPanel
        Left = 0
        Top = 0
        Width = 104
        Height = 32
        Align = alLeft
        BevelOuter = bvNone
        TabOrder = 0
        object AndCheckBox: TCheckBox
          Left = 10
          Top = 8
          Width = 90
          Height = 17
          Action = AndAction
          Caption = '&AND'#26908#32034
          TabOrder = 0
        end
      end
      object SelMaskPanel: TPanel
        Left = 104
        Top = 0
        Width = 206
        Height = 32
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 1
        object SelMaskCheckBox: TCheckBox
          Left = 4
          Top = 8
          Width = 179
          Height = 17
          Action = SelMaskAction
          Caption = #36984#25246#38917#30446#12384#12369#12434#27531#12377'(&M)'
          TabOrder = 0
        end
      end
      object ResLinkPanel: TPanel
        Left = 104
        Top = 0
        Width = 206
        Height = 32
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 2
        object ResLinkCheckBox: TCheckBox
          Left = 4
          Top = 8
          Width = 200
          Height = 17
          Action = ResLinkAction
          Caption = #32080#26524#12522#12473#12488#12363#12425#21453#23550#20596#12408#21453#26144'(&R)'
          TabOrder = 0
        end
      end
    end
  end
  object InpPanel: TPanel
    Left = 0
    Top = 0
    Width = 310
    Height = 23
    Align = alTop
    AutoSize = True
    BevelOuter = bvNone
    TabOrder = 3
    object TagEdit: TEdit
      Left = 0
      Top = 0
      Width = 310
      Height = 23
      Align = alTop
      PopupMenu = UserModule.EditPopupMenuE
      TabOrder = 0
      OnChange = TagEditChange
      OnKeyDown = TagEditKeyDown
      OnKeyPress = TagEditKeyPress
    end
  end
  object SetColPanel: TPanel
    Left = 0
    Top = 181
    Width = 310
    Height = 34
    Hint = #12479#12464#21029#37197#33394
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    object RefTagColBtn: TButton
      Tag = 3
      Left = 36
      Top = 6
      Width = 36
      Height = 22
      Action = SetColorAction
      Caption = '...'
      TabOrder = 0
    end
    object SpuitPanel: TPanel
      Left = 10
      Top = 6
      Width = 22
      Height = 22
      BevelOuter = bvLowered
      TabOrder = 1
      StyleElements = [seBorder]
      object SpuitImage: TImage
        Tag = 3
        Left = 1
        Top = 1
        Width = 20
        Height = 20
        Align = alClient
        Center = True
        Picture.Data = {
          0954506E67496D61676589504E470D0A1A0A0000000D49484452000000140000
          001408060000008D891D0D0000000774494D4507E708170A351F1885EFE80000
          00097048597300000EC300000EC301C76FA8640000000467414D410000B18F0B
          FC6105000000674944415478DAD5D4310EC0200C03C0FAE7FC9C06D1214211D8
          5009F0C4109F92053C3F0777812971259BCBEE0DDF93418F458BED05236CFAE4
          162B50D4A3C082596A0158035BCC4332C86034C86214A8604350C5BAA045C628
          50C186E03720FD423D7039E7832F4C325415354458800000000049454E44AE42
          6082}
        Stretch = True
        Transparent = True
        OnMouseDown = SpuitImageMouseDown
        OnMouseUp = SpuitImageMouseUp
      end
    end
    object DisableTagBtn: TButton
      Left = 76
      Top = 6
      Width = 70
      Height = 22
      Action = DefColorAction
      Caption = #12487#12501#12457#12523#12488
      TabOrder = 2
    end
    object RevColCheckBox: TCheckBox
      Left = 154
      Top = 8
      Width = 58
      Height = 17
      Action = RevColAction
      Caption = #21453#36578
      TabOrder = 3
    end
    object BevelPanel1: TPanel
      Left = 0
      Top = 32
      Width = 310
      Height = 2
      Align = alBottom
      AutoSize = True
      BevelOuter = bvNone
      TabOrder = 4
      object Shape1: TShape
        Left = 0
        Top = 0
        Width = 310
        Height = 1
        Align = alTop
        Brush.Style = bsClear
        Pen.Color = clBtnShadow
      end
      object Shape2: TShape
        Left = 0
        Top = 1
        Width = 310
        Height = 1
        Align = alTop
        Brush.Style = bsClear
        Pen.Color = clBtnHighlight
      end
    end
  end
  object TagPopupMenu: TPopupMenu
    OnPopup = TagPopupMenuPopup
    Left = 32
    Top = 56
    object RenTagItem: TMenuItem
      Action = RenTagAction
    end
    object DelTagItem: TMenuItem
      Action = DelTagAction
    end
    object Sep_1: TMenuItem
      Caption = '-'
    end
    object SetColItem: TMenuItem
      Action = SetColorAction
    end
    object DefColItem: TMenuItem
      Action = DefColorAction
    end
    object Sep_2: TMenuItem
      Caption = '-'
    end
    object CountTagItem: TMenuItem
      Action = CountTagAction
    end
    object ShowCountItem: TMenuItem
      Action = ShowTagCountAction
    end
    object Sep_3: TMenuItem
      Caption = '-'
    end
    object TrimDataItem: TMenuItem
      Action = TrimDataAction
    end
    object MakeNbtItem: TMenuItem
      Caption = #12467#12510#12531#12489#12501#12449#12452#12523#12392#12375#12390#20445#23384
      object MakeNbtCurItem: TMenuItem
        Action = MakeNbtCurAction
      end
      object MakeNbtOppItem: TMenuItem
        Action = MakeNbtOppAction
      end
    end
  end
  object ActionList1: TActionList
    Left = 104
    Top = 56
    object RenTagAction: TAction
      Caption = #12479#12464#21517#12398#22793#26356'(&R)'
      OnExecute = RenTagActionExecute
      OnUpdate = SelActionUpdate
    end
    object DelTagAction: TAction
      Caption = #12479#12464#21517#12398#21066#38500'(&D)'
      OnExecute = DelTagActionExecute
      OnUpdate = SelActionUpdate
    end
    object SetColorAction: TAction
      Caption = #12479#12464#33394#12398#35373#23450'(&O)'
      OnExecute = SetColorActionExecute
      OnUpdate = SelActionUpdate
    end
    object DefColorAction: TAction
      Caption = #12479#12464#33394#12434#12487#12501#12457#12523#12488#12395#25147#12377
      OnExecute = DefColorActionExecute
      OnUpdate = SelActionUpdate
    end
    object TrimDataAction: TAction
      Caption = #12479#12464#12487#12540#12479#12398#25972#29702'(&U)'
      OnExecute = TrimDataActionExecute
    end
    object CountTagAction: TAction
      Caption = #12479#12464#12398#20351#29992#25968#12434#12459#12454#12531#12488'(&C)'
      OnExecute = CountTagActionExecute
      OnUpdate = CountTagActionUpdate
    end
    object ShowTagCountAction: TAction
      Caption = #12479#12464#12398#20351#29992#25968#12434#24120#12395#34920#31034'(&S)'
      OnExecute = ShowTagCountActionExecute
      OnUpdate = ShowTagCountActionUpdate
    end
    object MakeNbtCurAction: TAction
      Caption = #12459#12524#12531#12488#20596#12391#26908#32034'(&C)...'
      OnExecute = MakeNbtActionExecute
      OnUpdate = MakeNbtActionUpdate
    end
    object MakeNbtOppAction: TAction
      Tag = 1
      Caption = #21453#23550#20596#12391#26908#32034'(&O)...'
      OnExecute = MakeNbtActionExecute
      OnUpdate = MakeNbtActionUpdate
    end
    object AndAction: TAction
      OnExecute = AndActionExecute
    end
    object SelMaskAction: TAction
      OnExecute = SelMaskActionExecute
    end
    object HideAction: TAction
      OnExecute = HideActionExecute
    end
    object RevColAction: TAction
      OnExecute = RevColActionExecute
    end
    object ResLinkAction: TAction
      OnExecute = ResLinkActionExecute
    end
  end
end
