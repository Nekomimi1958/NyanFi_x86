//----------------------------------------------------------------------//
// NyanFi																//
//  テキストファイルの結合ダイアログ									//
//----------------------------------------------------------------------//
#ifndef JoinDlgH
#define JoinDlgH

//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>

//-----------------------------------------------------
class TJoinTextDlg : public TForm
{
__published:	// IDE で管理されるコンポーネント
	TAction *EditTmpltAction;
	TAction *JoinAction;
	TActionList *ActionList1;
	TButton *CanButton;
	TButton *DelItemBtn;
	TButton *DownItemBtn;
	TButton *EditTmpltBtn;
	TButton *OkButton;
	TButton *RefTpltBtn;
	TButton *UpItemBtn;
	TCheckBox *BomCheckBox;
	TComboBox *OutCodeComboBox;
	TComboBox *OutLnBrkComboBox;
	TLabel *Label1;
	TLabel *Label2;
	TLabeledEdit *OutNameEdit;
	TLabeledEdit *TemplateEdit;
	TListBox *SrcFileListBox;
	TPanel *OpPanel;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall JoinActionUpdate(TObject *Sender);
	void __fastcall SrcFileListBoxKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall RefTpltBtnClick(TObject *Sender);
	void __fastcall EditTmpltActionExecute(TObject *Sender);
	void __fastcall EditTmpltActionUpdate(TObject *Sender);
	void __fastcall SrcFileListBoxDrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);

private:	// ユーザー宣言
	void __fastcall WmDpiChanged(TMessage &msg)
	{
		TForm::Dispatch(&msg);
		SetDarkWinTheme(this, true);
	}

public:		// ユーザー宣言
	__fastcall TJoinTextDlg(TComponent* Owner);

	BEGIN_MESSAGE_MAP
		VCL_MESSAGE_HANDLER(WM_DPICHANGED,	TMessage,	WmDpiChanged)
	END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern PACKAGE TJoinTextDlg *JoinTextDlg;
//---------------------------------------------------------------------------
#endif
