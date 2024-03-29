//----------------------------------------------------------------------//
// NyanFi																//
//  Gitタグ設定															//
//----------------------------------------------------------------------//
#include "UserFunc.h"
#include "UserMdl.h"
#include "Global.h"
#include "GitTag.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSetGitTagDlg *SetGitTagDlg = NULL;

//---------------------------------------------------------------------------
__fastcall TSetGitTagDlg::TSetGitTagDlg(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSetGitTagDlg::FormShow(TObject *Sender)
{
	IniFile->LoadPosInfo(this, DialogCenter);

	NameEdit->Text = EmptyStr;
	AnnotateMemo->Lines->Clear();

	if (IsCommit) {
		Caption = "コミット";
		TagPanel->Visible	 = false;
		CommitPanel->Visible = true;
		TagPanel->Visible	 = false;
		AnnotateMemo->SetFocus();
	}
	else {
		Caption = "コミットにタグを付ける";
		CommitPanel->Visible = false;
		TagPanel->Visible	 = true;
		AnnotateCheckBox->Checked = IniFile->ReadBoolGen(_T("GitTagAnnotate"));
		NameEdit->SetFocus();
	}

	GitParam = EmptyStr;

	SetDarkWinTheme(this);
	AnnotateMemo->Color 	  = get_WinColor();
	AnnotateMemo->Font->Color = get_TextColor();
}
//---------------------------------------------------------------------------
void __fastcall TSetGitTagDlg::FormClose(TObject *Sender, TCloseAction &Action)
{
	IniFile->SavePosInfo(this);

	if (!IsCommit) IniFile->WriteBoolGen(_T("GitTagAnnotate"), AnnotateCheckBox->Checked);

	IsCommit = false;
}

//---------------------------------------------------------------------------
//確定
//---------------------------------------------------------------------------
void __fastcall TSetGitTagDlg::OkActionExecute(TObject *Sender)
{
	if (IsCommit || AnnotateCheckBox->Checked) {
		std::unique_ptr<TStringList> fbuf(new TStringList());
		fbuf->Assign(AnnotateMemo->Lines);
		fbuf->LineBreak = "\n";
		fbuf->WriteBOM	= false;
		saveto_TextUTF8(EditMsgFile, fbuf.get());
	}

	//コミット
	if (IsCommit) {
		GitParam.sprintf(_T("commit -F \"%s\""), yen_to_slash(EditMsgFile).c_str());
	}
	//タグ
	else {
		GitParam = "tag";
		if (AnnotateCheckBox->Checked) {
			GitParam.cat_sprintf(_T(" -a -F \"%s\""), yen_to_slash(EditMsgFile).c_str());
		}
		GitParam.cat_sprintf(_T(" %s"), NameEdit->Text.c_str());
		if (!CommitID.IsEmpty()) GitParam.cat_sprintf(_T(" %s"), CommitID.c_str());
	}
}
//---------------------------------------------------------------------------
void __fastcall TSetGitTagDlg::OkActionUpdate(TObject *Sender)
{
	TAction *ap = (TAction *)Sender;

	if (IsCommit) {
		ap->Enabled = !AnnotateMemo->Lines->Text.IsEmpty();
	}
	else {
		ap->Enabled = !NameEdit->Text.IsEmpty()
			&& (!AnnotateCheckBox->Checked || !AnnotateMemo->Lines->Text.IsEmpty());
		AnnotateMemo->Color = get_WinColor(!AnnotateCheckBox->Checked);
	}
}

//---------------------------------------------------------------------------
void __fastcall TSetGitTagDlg::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	UnicodeString KeyStr = get_KeyStr(Key, Shift);
	if (equal_ESC(KeyStr)) {
		Key = 0;
		ModalResult = mrCancel;
	}
	else if (SameText(KeyStr, "Ctrl+ENTER")) {
		Key = 0;
		OkAction->Execute();
		ModalResult = mrOk;
	}
}
//---------------------------------------------------------------------------

