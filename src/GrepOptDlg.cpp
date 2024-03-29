//----------------------------------------------------------------------//
// NyanFi																//
//  GREP拡張設定														//
//----------------------------------------------------------------------//
#include "usr_shell.h"
#include "UserFunc.h"
#include "UserMdl.h"
#include "Global.h"
#include "MainFrm.h"
#include "GrepOptDlg.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGrepExOptDlg *GrepExOptDlg = NULL;

//---------------------------------------------------------------------------
__fastcall TGrepExOptDlg::TGrepExOptDlg(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TGrepExOptDlg::FormCreate(TObject *Sender)
{
	UserModule->SetUsrPopupMenu(this);

	//コントロールのタグに、対応する変数のポインタを設定
	OutFileEdit->Tag		= (NativeInt)&GrepFileName;
	AppNameEdit->Tag		= (NativeInt)&GrepAppName;
	AppParamEdit->Tag		= (NativeInt)&GrepAppParam;
	AppDirEdit->Tag 		= (NativeInt)&GrepAppDir;
	FileFmtEdit->Tag		= (NativeInt)&GrepFileFmt;
	InsStrWEdit->Tag		= (NativeInt)&GrepInsStrW;
	InsStrW2Edit->Tag		= (NativeInt)&GrepInsStrW2;
	RepCrEdit->Tag			= (NativeInt)&GrepRepCrStr;
	FExtBakEdit->Tag		= (NativeInt)&FExtRepBackup;
	RepBakDirEdit->Tag		= (NativeInt)&RepBackupDir;
	LogFileEdit->Tag		= (NativeInt)&ReplaceLogName;
	AppEnabledCheckBox->Tag = (NativeInt)&GrepAppEnabled;
	AppendCheckBox->Tag 	= (NativeInt)&GrepAppend;
	TrimLeftCheckBox->Tag	= (NativeInt)&GrepTrimLeft;
	RepTabCheckBox->Tag 	= (NativeInt)&GrepReplaceTab;
	RepCrCheckBox->Tag		= (NativeInt)&GrepReplaceCr;
	BakRepCheckBox->Tag 	= (NativeInt)&BackupReplace;
	SaveLogCheckBox->Tag	= (NativeInt)&SaveReplaceLog;
	AppendLogCheckBox->Tag	= (NativeInt)&ReplaceAppend;
	OpenLogCheckBox->Tag	= (NativeInt)&OpenReplaceLog;

	//ドロップターゲットを設定
	usr_SH->AddTargetList(this, AppNameEdit);
}
//---------------------------------------------------------------------------
void __fastcall TGrepExOptDlg::FormShow(TObject *Sender)
{
	SetDarkWinTheme(this);
	SampleMemo->Color		= get_WinColor();
	SampleMemo->Font->Color = get_TextColor();

	//タグを用いてコントロールに値を設定
	BringOptionByTag(this);

	switch (GrepOutMode) {
	case  1: OutMode1Btn->Checked = true; break;
	case  2: OutMode2Btn->Checked = true; break;
	default: OutMode0Btn->Checked = true;
	}

	//検索
	if (NyanFiForm->GrepPageControl->ActivePage==NyanFiForm->FindSheet) {
		OutModeSheet->TabVisible = true;
		OutFormSheet->TabVisible = true;
		ReplaceSheet->TabVisible = false;
		InsStrWEdit->Enabled	 = true;
		InsStrW2Edit->Enabled	 = true;
	}
	//置換
	else {
		OutModeSheet->TabVisible = false;
		OutFormSheet->TabVisible = true;
		ReplaceSheet->TabVisible = true;
		InsStrWEdit->Enabled	 = false;
		InsStrW2Edit->Enabled	 = false;
	}
	SampleChange(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TGrepExOptDlg::FormClose(TObject *Sender, TCloseAction &Action)
{
	GrepOutMode = OutMode1Btn->Checked? 1 : OutMode2Btn->Checked? 2: 0;
}

//---------------------------------------------------------------------------
//ヘルプ
//---------------------------------------------------------------------------
bool __fastcall TGrepExOptDlg::FormHelp(WORD Command, THelpEventData Data, bool &CallHelp)
{
	if (Command==HELP_CONTEXT || Command==HELP_CONTEXTPOPUP) {
		UnicodeString topic = (NyanFiForm->GrepPageControl->ActivePage==NyanFiForm->FindSheet)? HELPTOPIC_GR : HELPTOPIC_RP;
		topic += "#Option";
		HtmlHelpTopic(topic.c_str());
		CallHelp = false;
	}

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TGrepExOptDlg::PageControl1DrawTab(TCustomTabControl *Control,
	int TabIndex, const TRect &Rect, bool Active)
{
	draw_OwnerTab(Control, TabIndex, Rect, Active, IsDarkMode);
}

//---------------------------------------------------------------------------
//ロップ受け入れ
//---------------------------------------------------------------------------
void __fastcall TGrepExOptDlg::WmDropped(TMessage &msg)
{
	SetExtNameToCtrl(DroppedList->Strings[0], (TWinControl *)msg.WParam);
}

//---------------------------------------------------------------------------
//出力ファイルの参照
//---------------------------------------------------------------------------
void __fastcall TGrepExOptDlg::RefOutBtnClick(TObject *Sender)
{
	UserModule->PrepareOpenDlg(_T("出力ファイルの指定"), F_FILTER_TXT);
	UserModule->OpenDlgToEdit(OutFileEdit);
	SetFocus();
}

//---------------------------------------------------------------------------
//起動アプリの参照
//---------------------------------------------------------------------------
void __fastcall TGrepExOptDlg::RefAppBtnClick(TObject *Sender)
{
	UnicodeString fnam = AppNameEdit->Text;
	UserModule->PrepareOpenDlg(_T("起動アプリケーションの指定"), F_FILTER_EXE, fnam.c_str(), ExtractFilePath(fnam));
	UserModule->OpenDlgToEdit(AppNameEdit);
	SetFocus();
}
//---------------------------------------------------------------------------
//作業ディレクトリの参照
//---------------------------------------------------------------------------
void __fastcall TGrepExOptDlg::RefDirBtnClick(TObject *Sender)
{
	UnicodeString dnam = GrepAppDir;
	if (UserModule->SelectDirEx(_T("作業ディレクトリ"), dnam)) AppDirEdit->Text = dnam;
}

//---------------------------------------------------------------------------
//サンプル表示の更新
//---------------------------------------------------------------------------
void __fastcall TGrepExOptDlg::SampleChange(TObject *Sender)
{
	SampleMemo->Lines->Clear();

	UnicodeString f_inf = FileFmtEdit->Text;
	if (f_inf.IsEmpty()) f_inf = "$F $L:";

	f_inf = ReplaceStr(f_inf, "$F", "D:\\hoge.txt");
	f_inf = ReplaceStr(f_inf, "$L", "123");
	f_inf = conv_esc_char(f_inf);

	std::unique_ptr<TStringList> l_list(new TStringList());
	UnicodeString ln_str;
	if (NyanFiForm->GrepPageControl->ActivePage==NyanFiForm->FindSheet) {
		ln_str = "これは検索の";
		ln_str += conv_esc_char(InsStrWEdit->Text);
		ln_str += "マッチ語";
		ln_str += conv_esc_char(InsStrW2Edit->Text);
		ln_str += "です。";
	}
	else {
		ln_str = "これは置換結果のサンプルです。";
	}

	ln_str += "\nこれは2行目です。行頭にタブはありません。\n\tこれは3行目です。行頭にタブがあります。";

	if (RepTabCheckBox->Checked) ln_str = ReplaceStr(ln_str, "\t", " ");
	if (TrimLeftCheckBox->Checked) {
		TStringDynArray l_lst = SplitString(ln_str, "\n");
		ln_str = EmptyStr;
		for (int j=0; j<l_lst.Length; j++) {
			if (!ln_str.IsEmpty()) ln_str += "\n";
			ln_str += TrimLeft(l_lst[j]);
		}
	}

	if (RepCrCheckBox->Checked)
		ln_str = ReplaceStr(ln_str, "\n", conv_esc_char(RepCrEdit->Text));
	else
		ln_str = ReplaceStr(ln_str, "\n", "\r\n");

	SampleMemo->Text = f_inf + ln_str;
}

//---------------------------------------------------------------------------
//バックアップ先の参照
//---------------------------------------------------------------------------
void __fastcall TGrepExOptDlg::RefBakBtnClick(TObject *Sender)
{
	UnicodeString dnam = GrepAppDir;
	if (UserModule->SelectDirEx(_T("バックアップ先"), dnam)) RepBakDirEdit->Text = dnam;
}

//---------------------------------------------------------------------------
//ログファイルの参照
//---------------------------------------------------------------------------
void __fastcall TGrepExOptDlg::RefLogBtnClick(TObject *Sender)
{
	UserModule->PrepareOpenDlg(_T("置換ログファイルの指定"), F_FILTER_TXT);
	UserModule->OpenDlgToEdit(LogFileEdit);
	SetFocus();
}
//---------------------------------------------------------------------------
//確定
//---------------------------------------------------------------------------
void __fastcall TGrepExOptDlg::OkButtonClick(TObject *Sender)
{
	//コントロールのタグにしたがって変更を適用
	ApplyOptionByTag((TForm *)this);
}
//---------------------------------------------------------------------------

