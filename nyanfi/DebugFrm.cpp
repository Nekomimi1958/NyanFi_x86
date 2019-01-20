//----------------------------------------------------------------------//
// NyanFi																//
//  デバッグ情報														//
//----------------------------------------------------------------------//
#include <vcl.h>
#pragma hdrstop
#include <memory>
#include "UserFunc.h"
#include "UserMdl.h"
#include "usr_excmd.h"
#include "Global.h"
#include "DebugFrm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDebugForm *DebugForm = NULL;

//---------------------------------------------------------------------------
__fastcall TDebugForm::TDebugForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::FormCreate(TObject *Sender)
{
	ListBuff = new TStringList();

	PrevScrPanel  = new UsrScrollPanel(PrevPanel,  PreviewListBox, USCRPNL_FLAG_P_WP | USCRPNL_FLAG_L_WP);
	ReferScrPanel = new UsrScrollPanel(ReferPanel, ReferListBox,   USCRPNL_FLAG_P_WP | USCRPNL_FLAG_L_WP);

	ReferListBox->Tag = LBTAG_OPT_FIF1;
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::FormShow(TObject *Sender)
{
	IniFile->LoadPosInfo(this, DialogCenter);

	ReferSplitter->Color = col_Splitter;

	PreviewListBox->Font->Assign(TxtPrvFont);
	PreviewListBox->Color		= col_bgView;
	PreviewListBox->Font->Color = col_fgView;
	PreviewListBox->Tag 		= LBTAG_OPT_LNNO;
	PreviewListBox->TabWidth	= 4;
	set_ListBoxItemHi(PreviewListBox);
	set_UsrScrPanel(PrevScrPanel);

	ReferListBox->Font->Assign(FileInfFont);
	ReferListBox->Color		    = col_bgInf;
	ReferListBox->Font->Color   = col_fgInf;
	set_ListBoxItemHi(ReferListBox);
	set_UsrScrPanel(ReferScrPanel);

	ReferPanel->Height = IniFile->ReadIntGen(_T("DebugReferHeight"), 200);

	ToolBar1->Font->Assign(ToolBarFont);
	ToolBar1->Font->Color		  = col_fgTlBar;
	ToolBar1->GradientStartColor  = col_bgTlBar1;
	ToolBar1->GradientEndColor	  = col_bgTlBar2;
	ToolBar1->HotTrackColor		  = col_htTlBar;

	XCMD_ShowDebugInf();
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if (XCMD_Debugging && XCMD_xlp && !XCMD_xlp->EndOfCmds)
		CanClose = msgbox_Sure(_T("デバックを中止してコマンドの実行を終了しますか?"));
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	IniFile->SavePosInfo(this);
	IniFile->WriteIntGen(_T("DebugReferHeight"),	ReferPanel->Height);

	ExitAction->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::FormDestroy(TObject *Sender)
{
	delete PrevScrPanel;
	delete ReferScrPanel;
	delete ListBuff;
}

//---------------------------------------------------------------------------
void __fastcall TDebugForm::UpdateToolBar()
{
	for (int i=0; i<ToolBar1->ButtonCount; i++) {
		TToolButton *bp = ToolBar1->Buttons[i];
		if (bp && bp->Action) bp->Action->Update();
	}
}

//---------------------------------------------------------------------------
//プレビュー内容の設定
//---------------------------------------------------------------------------
void __fastcall TDebugForm::SetPreview(TStringList *lst, int idx)
{
	if (!FileName.IsEmpty())
		Caption = UnicodeString().cat_sprintf(_T("デバッグ - %s"), ExtractFileName(FileName).c_str());
	
	ListBuff->Assign(lst);
	ListBuff->Insert(0, EmptyStr);

	TListBox *lp = PreviewListBox;
	assign_FileListBox(lp, ListBuff, -1, PrevScrPanel);
	ListBoxSetIndex(lp, idx + 1);
	lp->Invalidate();

	UpdateToolBar();
}

//---------------------------------------------------------------------------
void __fastcall TDebugForm::PreviewListBoxEnter(TObject *Sender)
{
	ReferListBox->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::PreviewListBoxData(TWinControl *Control, int Index, UnicodeString &Data)
{
	Data = (Index>=0 && Index<ListBuff->Count)? ListBuff->Strings[Index] : EmptyStr;
}

//---------------------------------------------------------------------------
//プレビューの描画
//---------------------------------------------------------------------------
void __fastcall TDebugForm::PreviewListBoxDrawItem(TWinControl *Control, int Index,
          TRect &Rect, TOwnerDrawState State)
{
	TListBox *lp = (TListBox*)Control;
	TCanvas  *cv = lp->Canvas;
	TRect     rc = Rect;

	//行番号
	LineNoOut(cv, rc, Index);

	//テキスト
	cv->Brush->Color = State.Contains(odSelected)? col_selItem : col_bgView;
	cv->FillRect(rc);
	PrvTextOut(lp, Index, cv, rc,
		is_SelFgCol(State)? col_fgSelItem : col_fgView,
		4, NULL, "*.nbt");

	//カーソル
	if (lp->ItemIndex==Index) {
		int lw = 1;
		int yp = Rect.Bottom - lw;
		draw_Line(cv, Rect.Left, yp, Rect.Right, yp, lw, col_Cursor, psSolid);
	}
}
//---------------------------------------------------------------------------
//プレビュー/参照情報でのキー操作
//---------------------------------------------------------------------------
void __fastcall TDebugForm::ReferListBoxKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	UnicodeString KeyStr = get_KeyStr(Key, Shift);
	if (SameText(KeyStr, KeyStr_Copy)) EditCopyAction->Execute();
}
//---------------------------------------------------------------------------
//参照情報の描画
//---------------------------------------------------------------------------
void __fastcall TDebugForm::ReferListBoxDrawItem(TWinControl *Control, int Index,
          TRect &Rect, TOwnerDrawState State)
{
	draw_InfListBox((TListBox*)Control, Rect, Index, State);
}

//---------------------------------------------------------------------------
//キー操作
//---------------------------------------------------------------------------
void __fastcall TDebugForm::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (SpecialKeyProc(this, Key, Shift, _T(HELPTOPIC_XC) _T("#Debug"))) return;

	UnicodeString KeyStr = get_KeyStr(Key, Shift);
	if (KeyStr.Length()==1) {
		switch (KeyStr[1]) {
		case 'S': StepAction->Execute();	break;
		case 'G': GoAction->Execute();		break;
		case 'B': BreakAction->Execute();	break;
		case 'Q': QuitAction->Execute();	break;
		case 'X': ExitAction->Execute();	break;
		case 'V': VarListAction->Execute();	break;
		case 'E': EditAction->Execute();	break;
		case 'H': HelpAction->Execute();	break;
		}

		UpdateToolBar();
	}
}

//---------------------------------------------------------------------------
//コピー
//---------------------------------------------------------------------------
void __fastcall TDebugForm::EditCopyActionExecute(TObject *Sender)
{
	ExeCmdListBox(ReferListBox, _T("ClipCopy"));
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::EditCopyActionUpdate(TObject *Sender)
{
	TListBox *lp = ReferListBox;
	((TAction*)Sender)->Enabled = lp && lp->SelCount>0;
}

//---------------------------------------------------------------------------
//ステップ実行
//---------------------------------------------------------------------------
void __fastcall TDebugForm::StepActionExecute(TObject *Sender)
{
	XCMD_Debug_Step = true;
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::StepActionUpdate(TObject *Sender)
{
	((TAction*)Sender)->Enabled = XCMD_IsBusy && XCMD_Debugging;
}
//---------------------------------------------------------------------------
//実行
//---------------------------------------------------------------------------
void __fastcall TDebugForm::GoActionExecute(TObject *Sender)
{
	XCMD_Debug_Go = true;
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::GoActionUpdate(TObject *Sender)
{
	((TAction*)Sender)->Enabled = XCMD_IsBusy && XCMD_Debugging && !XCMD_Debug_Go;
}
//---------------------------------------------------------------------------
//停止
//---------------------------------------------------------------------------
void __fastcall TDebugForm::BreakActionExecute(TObject *Sender)
{
	XCMD_Debug_Go = false;
	XCMD_ShowDebugInf();
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::BreakActionUpdate(TObject *Sender)
{
	((TAction*)Sender)->Enabled = XCMD_IsBusy && XCMD_Debugging && XCMD_Debug_Go;
}

//---------------------------------------------------------------------------
//デバッグモード終了
//---------------------------------------------------------------------------
void __fastcall TDebugForm::QuitActionExecute(TObject *Sender)
{
	XCMD_Debug_Quit = true;
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::QuitActionUpdate(TObject *Sender)
{
	((TAction*)Sender)->Enabled = XCMD_IsBusy && XCMD_Debugging;
}

//---------------------------------------------------------------------------
//コマンドの実行を終了
//---------------------------------------------------------------------------
void __fastcall TDebugForm::ExitActionExecute(TObject *Sender)
{
	XCMD_Debug_Exit = true;
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::ExitActionUpdate(TObject *Sender)
{
	((TAction*)Sender)->Enabled = XCMD_IsBusy && XCMD_Debugging;
}

//---------------------------------------------------------------------------
//変数一覧
//---------------------------------------------------------------------------
void __fastcall TDebugForm::VarListActionExecute(TObject *Sender)
{
	if (XCMD_IsBusy && XCMD_Debugging)
		XCMD_Debug_List = true;
	else
		XCMD_ListVar();
}

//---------------------------------------------------------------------------
//エディタで開く
//---------------------------------------------------------------------------
void __fastcall TDebugForm::EditActionExecute(TObject *Sender)
{
	if (!open_by_TextEditor(FileName, PreviewListBox->ItemIndex)) msgbox_ERR(GlobalErrMsg);
}
//---------------------------------------------------------------------------
void __fastcall TDebugForm::EditActionUpdate(TObject *Sender)
{
	((TAction*)Sender)->Enabled = !FileName.IsEmpty();
}

//---------------------------------------------------------------------------
//ヘルプ
//---------------------------------------------------------------------------
void __fastcall TDebugForm::HelpActionExecute(TObject *Sender)
{
	XCMD_Debug_Help = true;
}
//---------------------------------------------------------------------------

