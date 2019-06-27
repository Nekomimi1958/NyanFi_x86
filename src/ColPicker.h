//----------------------------------------------------------------------//
// NyanFi																//
//  カラーピッカー														//
//----------------------------------------------------------------------//
#ifndef ColPickerH
#define ColPickerH

//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.Actions.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ActnList.hpp>

//---------------------------------------------------------------------------
class TColorPicker : public TForm
{
__published:	// IDE で管理されるコンポーネント
	TAction *StartRepAction;
	TActionList *ActionList1;
	TButton *ExeRepBtn;
	TCheckBox *Ave9pxCheckBox;
	TCheckBox *CmpColCheckBox;
	TCheckBox *SafeColCheckBox;
	TComboBox *FmtComboBox;
	TComboBox *RepComboBox;
	TEdit *ColEdit;
	TGroupBox *RepeatGroupBox;
	TImage *ColImage;
	TLabel *ColLabel;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *RepSttLabel;
	TLabeledEdit *RepCntEdit;
	TPanel *Col2Panel;
	TPanel *ColPanel;
	TPanel *Panel1;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall StartRepActionExecute(TObject *Sender);
	void __fastcall StartRepActionUpdate(TObject *Sender);

private:
	bool Repeating;		//連続取得中
	int  RepCount;
	UnicodeString RepCopyBuff;
	UnicodeString DefColCaption;

public:		// ユーザー宣言
	TImage *ViewImage;

	__fastcall TColorPicker(TComponent* Owner);
	void __fastcall UpdateStt(int x = 0, int y = 0, float ratio = 1.0);
	void __fastcall CopyColor();
};
//---------------------------------------------------------------------------
extern PACKAGE TColorPicker *ColorPicker;
//---------------------------------------------------------------------------
#endif
