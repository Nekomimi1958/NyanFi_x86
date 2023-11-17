//----------------------------------------------------------------------//
// NyanFi																//
//  オプション設定														//
//----------------------------------------------------------------------//
#ifndef OptDlgH
#define OptDlgH

//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.Actions.hpp>
#include <System.ImageList.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.StdActns.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.BaseImageCollection.hpp>
#include <Vcl.ImageCollection.hpp>
#include <Vcl.VirtualImageList.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include "usr_scale.h"
#include "usr_swatch.h"
#include "usr_hintwin.h"
#include "MarkList.h"
#include "UserMdl.h"

//---------------------------------------------------------------------------
#define MAX_KEYTABS	5

//---------------------------------------------------------------------------
class TOptionDlg : public TForm
{
__published:	// IDE で管理されるコンポーネント
	TAction *AddAssoAction;
	TAction *AddDrvAction;
	TAction *AddEtcEditorAction;
	TAction *AddExtColAction;
	TAction *AddKeyAction;
	TAction *AddMenuAction;
	TAction *AddPrtDirAction;
	TAction *AddStdCmdAction;
	TAction *AddToolAction;
	TAction *ChgAssoAction;
	TAction *ChgDrvAction;
	TAction *ChgEtcEditorAction;
	TAction *ChgExtColAction;
	TAction *ChgKeyAction;
	TAction *ChgMenuAction;
	TAction *ChgStdCmdAction;
	TAction *ChgToolAction;
	TAction *ConfigSpiAction;				//<<<<<<<X86_SPI
	TAction *DefTagColAction;
	TAction *DelDrvAction;
	TAction *DelKeyAction;
	TAction *DisableColAction;
	TAction *DisableTimColAction;
	TAction *EditFile1Action;
	TAction *EditFile2Action;
	TAction *EditFileAction;
	TAction *FindColDownAction;
	TAction *FindColUpAction;
	TAction *FindEvDownAction;
	TAction *FindEvUpAction;
	TAction *FindKeyDownAction;
	TAction *FindKeyUpAction;
	TAction *OkAction;
	TActionList *ActionList1;
	TButton *AddColBtn;
	TButton *AddDirBtn;
	TButton *AddDrvBtn;
	TButton *AddEdtBtn;
	TButton *AddExtBtn;
	TButton *AddKeyBtn;
	TButton *AddMenuBtn;
	TButton *AlRightBtn;
	TButton *AppColorBtn;
	TButton *AppDesignBtn;
	TButton *AsoAddBtn;
	TButton *AsoChgBtn;
	TButton *AsoDelBtn;
	TButton *AsoRefBtn;
	TButton *CanButton;
	TButton *ChgColBtn;
	TButton *ChgDrvBtn;
	TButton *ChgEdtBtn;
	TButton *ChgExtBtn;
	TButton *ChgKeyBtn;
	TButton *ChgMenuBtn;
	TButton *CmdAddBtn;
	TButton *CmdChgBtn;
	TButton *CmdDelBtn;
	TButton *DelColBtn;
	TButton *DelDirBtn;
	TButton *DelDrvBtn;
	TButton *DelEdtBtn;
	TButton *DelExtBtn;
	TButton *DelKeyBtn;
	TButton *DelMenuBtn;
	TButton *DisableBtn;
	TButton *DisableTagBtn;
	TButton *DisableTimBtn;
	TButton *DowAssBtn;
	TButton *DowCmdBtn;
	TButton *DowColBtn;
	TButton *DowEdtBtn;
	TButton *DowExtBtn;
	TButton *DowMenuBtn;
	TButton *EvEditBtn;
	TButton *EvEditT1Btn;
	TButton *EvEditT2Btn;
	TButton *ExEditBtn;
	TButton *ExpColBtn;
	TButton *ExpKeyBtn;
	TButton *FindDownBtn;
	TButton *FindDownColBtn;
	TButton *FindDownEvBtn;
	TButton *FindKeyBtn;
	TButton *FindUpBtn;
	TButton *FindUpColBtn;
	TButton *FindUpEvBtn;
	TButton *InpColBtn;
	TButton *InpKeyBtn;
	TButton *L_RefIniPatBtn;
	TButton *MaxHiBtn;
	TButton *MaxWdBtn;
	TButton *OkButton;
	TButton *R_RefIniPatBtn;
	TButton *RefBgImg1Btn;
	TButton *RefBgImg2Btn;
	TButton *RefBinEdtBtn;
	TButton *RefCmdGitExeBtn;
	TButton *RefCmdPrmBtn;
	TButton *RefCmdsBtn;
	TButton *RefCmdsT1Btn;
	TButton *RefCmdsT2Btn;
	TButton *RefColBtn;
	TButton *RefDirBtn;
	TButton *RefEtcEdt1Btn;
	TButton *RefExeBtn;
	TButton *RefExtColBtn;
	TButton *RefExtTxViewerBtn;
	TButton *RefFontBtn;
	TButton *RefHomeWorkBtn;
	TButton *RefImgEdtBtn;
	TButton *RefMenuIconBtn;
	TButton *RefMenuPrmBtn;
	TButton *RefMigemoBtn;
	TButton *RefSndFindFinBtn;
	TButton *RefSndTaskFinBtn;
	TButton *RefSndWarnBtn;
	TButton *RefSndWatchBtn;
	TButton *RefSpImg2Btn;
	TButton *RefSpImgBtn;
	TButton *RefStdCmdPrmBtn;
	TButton *RefSusieDirBtn;				//<<<<<<<X86_SPI
	TButton *RefTagColBtn;
	TButton *RefTimColBtn;
	TButton *RefTmpDirBtn;
	TButton *RefTxtEditBtn;
	TButton *RefVDrvBtn;
	TButton *SpiConfigBtn;					//<<<<<<<X86_SPI
	TButton *TestSndFindFinBtn;
	TButton *TestSndTaskFinBtn;
	TButton *TestSndWarnBtn;
	TButton *TestSndWatchBtn;
	TButton *UpAssBtn;
	TButton *UpCmdBtn;
	TButton *UpColBtn;
	TButton *UpEdtBtn;
	TButton *UpExtBtn;
	TButton *UpMenuBtn;
	TCheckBox *AddToRecentCheckBox;
	TCheckBox *AllowDkMdCheckBox;
	TCheckBox *AltBackSlashCheckBox;
	TCheckBox *AltCheckBox;
	TCheckBox *AniGifCheckBox;
	TCheckBox *AnimateGifCheckBox;
	TCheckBox *AozoraCheckBox;
	TCheckBox *AppAltCheckBox;
	TCheckBox *AppCtrlCheckBox;
	TCheckBox *AppendLogCheckBox;
	TCheckBox *AppMinCheckBox;
	TCheckBox *AppShiftCheckBox;
	TCheckBox *AppWinCheckBox;
	TCheckBox *AsoSortCheckBox;
	TCheckBox *AutoCompCheckBox;
	TCheckBox *AutoDelWLCheckBox;
	TCheckBox *AutoHotkeyCheckBox;
	TCheckBox *BeepTopEndCheckBox;
	TCheckBox *BinMemMapedCheckBox;
	TCheckBox *CacheThumbADSCheckBox;
	TCheckBox *CheckUncCheckBox;
	TCheckBox *ClickableUrlCheckBox;
	TCheckBox *CloseOtherCheckBox;
	TCheckBox *ColOnlyFExtCheckBox;
	TCheckBox *ColorHintCheckBox;
	TCheckBox *CompInTitleBarCheckBox;
	TCheckBox *CopyNoBuffCheckBox;
	TCheckBox *CopyTagsCheckBox;
	TCheckBox *CtrlCheckBox;
	TCheckBox *DecDfmStrCheckBox;
	TCheckBox *DelDplDirHistCheckBox;
	TCheckBox *DelUseTrsCheckBox;
	TCheckBox *DirHistCsrPosCheckBox;
	TCheckBox *DirHistSrotMdCheckBox;
	TCheckBox *DirJumboCheckBox;
	TCheckBox *DispRegNameCheckBox;
	TCheckBox *DivDirInfUDCheckBox;
	TCheckBox *DivFlistUDCheckBox;
	TCheckBox *DlgCenterCheckBox;
	TCheckBox *DlgMoveAltCheckBox;
	TCheckBox *DlgMoveCtrlCheckBox;
	TCheckBox *DlgMoveShiftCheckBox;
	TCheckBox *DlgSizeAltCheckBox;
	TCheckBox *DlgSizeCtrlCheckBox;
	TCheckBox *DlgSizeShiftCheckBox;
	TCheckBox *DontClrSelAppCheckBox;
	TCheckBox *DontClrSelEditCheckBox;
	TCheckBox *DontClrSelWinCheckBox;
	TCheckBox *DotPerUserCheckBox;
	TCheckBox *DowAfterStdCheckBox;
	TCheckBox *EmHdlnCheckBox;
	TCheckBox *EmNumCheckBox;
	TCheckBox *EmRemCheckBox;
	TCheckBox *EmRsvCheckBox;
	TCheckBox *EmRubyCheckBox;
	TCheckBox *EmStrCheckBox;
	TCheckBox *EmSymCheckBox;
	TCheckBox *EscHelpCheckBox;
	TCheckBox *ExtSavDirHistCheckBox;
	TCheckBox *FindPathColCheckBox;
	TCheckBox *FindTagsColCheckBox;
	TCheckBox *FindTagsSortCheckBox;
	TCheckBox *FixListCheckBox;
	TCheckBox *FixWinCheckBox;
	TCheckBox *FlatInfPanelCheckBox;
	TCheckBox *FlCsrVisiCheckBox;
	TCheckBox *ForceDelCheckBox;
	TCheckBox *FormatJsonCheckBox;
	TCheckBox *GrayScaleCheckBox;
	TCheckBox *HideAtrCheckBox;
	TCheckBox *HideCsrFullCheckBox;
	TCheckBox *HideScrBarCheckBox;
	TCheckBox *HideScrCheckBox;
	TCheckBox *HideThumbCheckBox;
	TCheckBox *HideTitMenuCheckBox;
	TCheckBox *HintTopEndCheckBox;
	TCheckBox *HotAltCheckBox;
	TCheckBox *HotCtrlCheckBox;
	TCheckBox *HotShiftCheckBox;
	TCheckBox *HotWinCheckBox;
	TCheckBox *ImgEditSglCheckBox;
	TCheckBox *ImgSttIsBtmCheckBox;
	TCheckBox *IncSea1ExitCheckBox;
	TCheckBox *IncSeaCaseCheckBox;
	TCheckBox *IncSeaFuzzyCheckBox;
	TCheckBox *IncSeaLoopCheckBox;
	TCheckBox *InhAltMenuCheckBox;
	TCheckBox *InheritDotCheckBox;
	TCheckBox *IniPathToTab1CheckBox;
	TCheckBox *IniSeaAltCheckBox;
	TCheckBox *IniSeaByNumCheckBox;
	TCheckBox *IniSeaBySignCheckBox;
	TCheckBox *IniSeaCtrlCheckBox;
	TCheckBox *IniSeaShiftCheckBox;
	TCheckBox *IniTabHomeAllCheckBox;
	TCheckBox *InsHrArtCheckBox;
	TCheckBox *InsHrNavCheckBox;
	TCheckBox *InsHrSctCheckBox;
	TCheckBox *InZipImgCheckBox;
	TCheckBox *KeepCurListWdCheckBox;
	TCheckBox *KeepOnResizeCheckBox;
	TCheckBox *KeepZoomCheckBox;
	TCheckBox *LimitBinCsrCheckBox;
	TCheckBox *LogDebugInfCheckBox;
	TCheckBox *LogDestinationCheckBox;
	TCheckBox *LogErrMsgCheckBox;
	TCheckBox *LogErrOnlyCheckBox;
	TCheckBox *LogFullPathCheckBox;
	TCheckBox *LogHideSkipCheckBox;
	TCheckBox *LoopCurCheckBox;
	TCheckBox *LoopFlCsrCheckBox;
	TCheckBox *MarkdownCheckBox;
	TCheckBox *MarkImgCheckBox;
	TCheckBox *MigemoCheckBox;
	TCheckBox *ModalScrCheckBox;
	TCheckBox *MulInstCheckBox;
	TCheckBox *NoChkDirHistCheckBox;
	TCheckBox *NoChkRUncCheckBox;
	TCheckBox *NoChkWUncCheckBox;
	TCheckBox *NoRoundWinCheckBox;
	TCheckBox *NoSpcFExtCheckBox;
	TCheckBox *NotShowNoTaskCheckBox;
	TCheckBox *NotSortWLCheckBox;
	TCheckBox *NotThumbIfArcCheckBox;
	TCheckBox *OmitEndOfNameCheckBox;
	TCheckBox *OpenAddDrvCheckBox;
	TCheckBox *OpenDirByStdCheckBox;
	TCheckBox *OpenOnlyCurAppCheckBox;
	TCheckBox *OpenOnlyCurEditCheckBox;
	TCheckBox *OpenOnlyCurWinCheckBox;
	TCheckBox *OpnStdResCheckBox;
	TCheckBox *PathInTitleBarCheckBox;
	TCheckBox *PermitCmdsCheckBox;
	TCheckBox *PrevTailCheckBox;
	TCheckBox *PrevTxtToInfCheckBox;
	TCheckBox *PriFExtColCheckBox;
	TCheckBox *PrtFileCheckBox;
	TCheckBox *PrtSubCheckBox;
	TCheckBox *RegWkCsrPosCheckBox;
	TCheckBox *ReloadActCheckBox;
	TCheckBox *RemoveCdRoCheckBox;
	TCheckBox *RevTagColCheckBox;
	TCheckBox *RotViewImgCheckBox;
	TCheckBox *RstViewLnCheckBox;
	TCheckBox *SaveLogCheckBox;
	TCheckBox *ScrBarFoldCheckBox;
	TCheckBox *SeekBindDirCheckBox;
	TCheckBox *SeekSwapNPCheckBox;
	TCheckBox *SelBaseOnlyCheckBox;
	TCheckBox *SelByMouseCheckBox;
	TCheckBox *SelCheckBox;
	TCheckBox *SelIconCheckBox;
	TCheckBox *SetCursorCheckBox;
	TCheckBox *ShiftCheckBox;
	TCheckBox *ShowAdsInfCheckBox;
	TCheckBox *ShowArcCopyPrgCheckBox;
	TCheckBox *ShowByteSizeCheckBox;
	TCheckBox *ShowClsTabBtnCheckBox;
	TCheckBox *ShowCopyHintCheckBox;
	TCheckBox *ShowCrCheckBox;
	TCheckBox *ShowDirTypeCheckBox;
	TCheckBox *ShowDuplNotifyCheckBox;
	TCheckBox *ShowFilePropCheckBox;
	TCheckBox *ShowHeaderCheckBox;
	TCheckBox *ShowIconCheckBox;
	TCheckBox *ShowImgPrvCheckBox;
	TCheckBox *ShowKeyHintCheckBox;
	TCheckBox *ShowLnCsrCheckBox;
	TCheckBox *ShowLnNoCheckBox;
	TCheckBox *ShowMainMenuCheckBox;
	TCheckBox *ShowMsgHintCheckBox;
	TCheckBox *ShowNoKeyHintCheckBox;
	TCheckBox *ShowPopDirBtnCheckBox;
	TCheckBox *ShowPopTabBtnCheckBox;
	TCheckBox *ShowProcInfCheckBox;
	TCheckBox *ShowRulerCheckBox;
	TCheckBox *ShowSpaceCheckBox;
	TCheckBox *ShowTabCheckBox;
	TCheckBox *ShowTargetInfCheckBox;
	TCheckBox *ShowTooltipCheckBox;
	TCheckBox *SplashCheckBox;
	TCheckBox *StdMenuFileCheckBox;
	TCheckBox *StdResultListCheckBox;
	TCheckBox *StdTabGroupCheckBox;
	TCheckBox *SureAdjPosCheckBox;
	TCheckBox *SureCancelCheckBox;
	TCheckBox *SureCmpDelCheckBox;
	TCheckBox *SureCopyCheckBox;
	TCheckBox *SureDefNoCheckBox;
	TCheckBox *SureDeleteCheckBox;
	TCheckBox *SureExecCheckBox;
	TCheckBox *SureExitCheckBox;
	TCheckBox *SureMoveCheckBox;
	TCheckBox *SureOtherCheckBox;
	TCheckBox *SureUnPackCheckBox;
	TCheckBox *SureWorkListCheckBox;
	TCheckBox *SymColToCheckBox;
	TCheckBox *SyncItemCheckBox;
	TCheckBox *SysAtrCheckBox;
	TCheckBox *TabGrInTitleBarCheckBox;
	TCheckBox *TaskTrayCheckBox;
	TCheckBox *ThumbExifCheckBox;
	TCheckBox *ThumbFExtCheckBox;
	TCheckBox *ThumbNameCheckBox;
	TCheckBox *ThumbScrCheckBox;
	TCheckBox *ThumbTagCheckBox;
	TCheckBox *TileIfCheckBox;
	TCheckBox *ToolBarISideCheckBox;
	TCheckBox *TvCsrVisiCheckBox;
	TCheckBox *TxtSttIsBtmCheckBox;
	TCheckBox *UncToNetDriveCheckBox;
	TCheckBox *UnRegCmdCheckBox;
	TCheckBox *UseIndIconCheckBox;
	TCheckBox *UseSpiFirstCheckBox;				//<<<<<<<X86_SPI
	TCheckBox *UseXd2txCheckBox;
	TCheckBox *ViewArcInfCheckBox;
	TCheckBox *CheckTSCheckBox;
	TCheckBox *WarnDisconCheckBox;
	TCheckBox *WarnLowBatheckBox;
	TCheckBox *WarnPowFailCheckBox;
	TCheckBox *WorkToDirHistCheckBox;
	TCheckListBox *ExtMenuListBox;
	TCheckListBox *ExtToolListBox;
	TColorBox *ModalColorBox;
	TComboBox *AppKeyComboBox;
	TComboBox *AppPrmComboBox;
	TComboBox *AsoAppComboBox;
	TComboBox *BgImgModeComboBox;
	TComboBox *BgImgSubModeComboBox;
	TComboBox *CmdComboBox;
	TComboBox *DblClickFlComboBox;
	TComboBox *DefDropComboBox;
	TComboBox *FontComboBox;
	TComboBox *HotKeyComboBox;
	TComboBox *Key2ComboBox;
	TComboBox *KeyComboBox;
	TComboBox *L_IniMaskComboBox;
	TComboBox *LayoutComboBox;
	TComboBox *MaxTasksComboBox;
	TComboBox *MenuCmdComboBox;
	TComboBox *OpenByModeComboBox;
	TComboBox *PrmComboBox;
	TComboBox *R_IniMaskComboBox;
	TComboBox *ScaleOptComboBox;
	TComboBox *ScrBarStyleComboBox;
	TComboBox *SizeDecDgtComboBox;
	TComboBox *SizeFmtComboBox;
	TComboBox *StdCmdComboBox;
	TComboBox *TabStyleComboBox;
	TComboBox *ThumbOptComboBox;
	TComboBox *VirDrvComboBox;
	TComboBox *WheelBtnF0ComboBox;
	TComboBox *WheelBtnF1ComboBox;
	TComboBox *WheelBtnF2ComboBox;
	TComboBox *WheelBtnF3ComboBox;
	TComboBox *WheelBtnIComboBox;
	TComboBox *WheelBtnVComboBox;
	TComboBox *WheelCmdF0ComboBox;
	TComboBox *WheelCmdF1ComboBox;
	TComboBox *WheelCmdF2ComboBox;
	TComboBox *WheelCmdF3ComboBox;
	TComboBox *WheelCmdI0ComboBox;
	TComboBox *WheelCmdI1ComboBox;
	TComboBox *WheelCmdI2ComboBox;
	TComboBox *WheelCmdI3ComboBox;
	TComboBox *WheelCmdV0ComboBox;
	TComboBox *WheelCmdV1ComboBox;
	TComboBox *WheelCmdV2ComboBox;
	TComboBox *WheelCmdV3ComboBox;
	TComboBox *X1BtnFComboBox;
	TComboBox *X1BtnIComboBox;
	TComboBox *X1BtnVComboBox;
	TComboBox *X2BtnFComboBox;
	TComboBox *X2BtnIComboBox;
	TComboBox *X2BtnVComboBox;
	TEdit *BinaryEditorEdit;
	TEdit *DlgMoveEdit;
	TEdit *DlgSizeEdit;
	TEdit *ExtTxViewerEdit;
	TEdit *FoldWdEdit;
	TEdit *HomeWorkListEdit;
	TEdit *ImageEditorEdit;
	TEdit *KnobImgEdit;
	TEdit *L_IniPatEdit;
	TEdit *R_IniPatEdit;
	TEdit *SndFindFinEdit;
	TEdit *SndTaskFinEdit;
	TEdit *SndWarnEdit;
	TEdit *SndWatchEdit;
	TEdit *SttBarFmtEdit;
	TEdit *TextEditorEdit;
	TEdit *TimerCmd2Edit;
	TEdit *TimerCnd2Edit;
	TEdit *VirDriveEdit;
	TGroupBox *AppListGroupBox;
	TGroupBox *BgImageGroupBox;
	TGroupBox *BinEditGroupBox;
	TGroupBox *BorderLRGroupBox;
	TGroupBox *CompDelGroupBox;
	TGroupBox *CopyGroupBox;
	TGroupBox *DeleteGroupBox;
	TGroupBox *DirHistGroupBox;
	TGroupBox *DispGroupBox;
	TGroupBox *DlgKeyGroupBox;
	TGroupBox *DriveInfGroupBox;
	TGroupBox *DuplGroupBox;
	TGroupBox *EmpGroupBox;
	TGroupBox *EtcEditGroupBox;
	TGroupBox *EtcGroupBox;
	TGroupBox *EtcWarnGroupBox;
	TGroupBox *ExeCmdLineGroupBox;
	TGroupBox *ExtColGroupBox;
	TGroupBox *ExtTxViewerGroupBox;
	TGroupBox *FileEditGroupBox;
	TGroupBox *FileInfoGroupBox;
	TGroupBox *FileListGroupBox;
	TGroupBox *FoldGroupBox;
	TGroupBox *FontGroupBox;
	TGroupBox *H2TGroupBox;
	TGroupBox *HotKeyGroupBox;
	TGroupBox *ImgEditGroupBox;
	TGroupBox *ImgPrvGroupBox;
	TGroupBox *IncSearchGroupBox;
	TGroupBox *IniSearchGroupBox;
	TGroupBox *IniWinSizeGroupBox;
	TGroupBox *IniWorkListGroupBox;
	TGroupBox *KeyCmdGroupBox;
	TGroupBox *KeyKeyGroupBox;
	TGroupBox *LayoutGroupBox;
	TGroupBox *LeftPathGroupBox;
	TGroupBox *LogGroupBox;
	TGroupBox *MarkImgGroupBox;
	TGroupBox *ModalEfctGroupBox;
	TGroupBox *MouseFlGroupBox;
	TGroupBox *MouseIvGroupBox;
	TGroupBox *MouseTvGroupBox;
	TGroupBox *OpeGroupBox;
	TGroupBox *OpenByAppGroupBox;
	TGroupBox *OpenByWinGroupBox;
	TGroupBox *OpenStdGroupBox;
	TGroupBox *OptColGroupBox;
	TGroupBox *PlayGroupBox;
	TGroupBox *PrtDirGroupBox;
	TGroupBox *RecentGroupBox;
	TGroupBox *RightPathGroupBox;
	TGroupBox *SndFindGroupBox;
	TGroupBox *SndTaskGroupBox;
	TGroupBox *SndWarnGroupBox;
	TGroupBox *SndWatchGroupBox;
	TGroupBox *SpiGroupBox;				//<<<<<<<X86_SPI
	TGroupBox *SplitterGroupBox;
	TGroupBox *SttBarGroupBox;
	TGroupBox *SureMsgGroupBox;
	TGroupBox *SyncLRGroupBox;
	TGroupBox *TabGroupBox;
	TGroupBox *TagColGroupBox;
	TGroupBox *TaskGroupBox;
	TGroupBox *TaskManGroupBox;
	TGroupBox *ThumbGroupBox;
	TGroupBox *TimColGroupBox;
	TGroupBox *TimeGroupBox;
	TGroupBox *TimerGroupBox;
	TGroupBox *TxtEditGroupBox;
	TGroupBox *TxtPrvGroupBox;
	TGroupBox *VirDrvGroupBox;
	TGroupBox *WatchGroupBox;
	TGroupBox *WebSearchGroupBox;
	TGroupBox *WorkListGroupBox;
	THeaderControl *ExtMenuHeader;
	THeaderControl *ExtToolHeader;
	THeaderControl *KeyHeaderControl;
	TImage *SpuitImage;
	TImage *SpuitImage2;
	TImage *SpuitImage3;
	TImage *SpuitImage4;
	TLabel *DlgMoveLabel;
	TLabel *DlgSizeLabel;
	TLabel *KeyboardLabel;
	TLabel *MenuAliasLabel;
	TLabel *ToolAliasLabel;
	TLabeledEdit *AsoExtEdit;
	TLabeledEdit *AutoRenFmtEdit;
	TLabeledEdit *BatLowLimitEdit;
	TLabeledEdit *BdrMovWdLabeledEdit;
	TLabeledEdit *BgColAlphaEdit;
	TLabeledEdit *BgImg1Edit;
	TLabeledEdit *BgImg2Edit;
	TLabeledEdit *CellAlphaEdit;
	TLabeledEdit *ClockFmtEdit;
	TLabeledEdit *CmdGitExeEdit;
	TLabeledEdit *CmpDelOwCntEdit;
	TLabeledEdit *CursorAlphaEdit;
	TLabeledEdit *CursorWidthEdit;
	TLabeledEdit *DelBlkClsEdit;
	TLabeledEdit *DelBlkIdEdit;
	TLabeledEdit *DirBraEdit;
	TLabeledEdit *DirDelimiterEdit;
	TLabeledEdit *DirKetEdit;
	TLabeledEdit *DrvInfFmtNEdit;
	TLabeledEdit *DrvInfFmtREdit;
	TLabeledEdit *DrvInfFmtSEdit;
	TLabeledEdit *EmpBin1Edit;
	TLabeledEdit *EmpBin2Edit;
	TLabeledEdit *EmpBin3Edit;
	TLabeledEdit *EtcEditorEdit;
	TLabeledEdit *EventCmdsEdit;
	TLabeledEdit *ExtColorEdit;
	TLabeledEdit *ExtTxViewerFmtEdit;
	TLabeledEdit *FExt7zDllEdit;
	TLabeledEdit *FExtEtcEdit;
	TLabeledEdit *FExtExeFileEdit;
	TLabeledEdit *FExtGetInfEdit;
	TLabeledEdit *FExtImgEdit;
	TLabeledEdit *FExtImgPrvEdit;
	TLabeledEdit *FExtMaxWidthEdit;
	TLabeledEdit *FExtNoImgPrvEdit;
	TLabeledEdit *FExtNoInfEdit;
	TLabeledEdit *FExtNoIViewEdit;
	TLabeledEdit *FExtStdEdit;
	TLabeledEdit *FindColEdit;
	TLabeledEdit *FindEdit;
	TLabeledEdit *FindEvEdit;
	TLabeledEdit *FindKeyEdit;
	TLabeledEdit *FindPathWdEdit;
	TLabeledEdit *FindTagsWdEdit;
	TLabeledEdit *FindXColEdit;
	TLabeledEdit *FitMaxZoomEdit;
	TLabeledEdit *FixedLimitEdit;
	TLabeledEdit *FrmMgnEdit;
	TLabeledEdit *FwCntTaskFinEdit;
	TLabeledEdit *FwCntWarnEdit;
	TLabeledEdit *FwTmTaskFinEdit;
	TLabeledEdit *FwTmWarnEdit;
	TLabeledEdit *GetFaviUrlEdit;
	TLabeledEdit *HdrStrEdit;
	TLabeledEdit *HideTimeEdit;
	TLabeledEdit *IconCacheEdit;
	TLabeledEdit *ImgGridHEdit;
	TLabeledEdit *ImgGridVEdit;
	TLabeledEdit *InfPrvWaitEdit;
	TLabeledEdit *IniWinHiEdit;
	TLabeledEdit *IniWinLeftEdit;
	TLabeledEdit *IniWinTopEdit;
	TLabeledEdit *IniWinWdEdit;
	TLabeledEdit *InsHrClsEdit;
	TLabeledEdit *IntrPgEdit;
	TLabeledEdit *KeyFilterEdit;
	TLabeledEdit *KeyHintTimeEdit;
	TLabeledEdit *LeftMarginEdit;
	TLabeledEdit *LimitBinEdit;
	TLabeledEdit *LimitSndEdit;
	TLabeledEdit *LimitTxtEdit;
	TLabeledEdit *ListInterLnEdit;
	TLabeledEdit *ListPercentEdit;
	TLabeledEdit *ListWheelScrLnEdit;
	TLabeledEdit *LogIntervalEdit;
	TLabeledEdit *MarkFextEdit;
	TLabeledEdit *MarkMemoEdit;
	TLabeledEdit *MarkPathEdit;
	TLabeledEdit *MaxDirHistEdit;
	TLabeledEdit *MaxLogFilesEdit;
	TLabeledEdit *MaxLogLinesEdit;
	TLabeledEdit *MenuAliasEdit;
	TLabeledEdit *MenuIconEdit;
	TLabeledEdit *MenuPrmEdit;
	TLabeledEdit *MenuTitEdit;
	TLabeledEdit *MigemoDirEdit;
	TLabeledEdit *MigemoMinEdit;
	TLabeledEdit *MinShowTimeEdit;
	TLabeledEdit *ModalAlphaEdit;
	TLabeledEdit *MsgHintTimeEdit;
	TLabeledEdit *NoCachePathEdit;
	TLabeledEdit *NoDirHistPathEdit;
	TLabeledEdit *NoImgPrvPathEdit;
	TLabeledEdit *NoInfPathEdit;
	TLabeledEdit *NopDtctTimeEdit;
	TLabeledEdit *NormalWaitTimeEdit;
	TLabeledEdit *NotifyTaskTimeEdit;
	TLabeledEdit *NoWatchPathEdit;
	TLabeledEdit *PinMarkEdit;
	TLabeledEdit *PrvActTailLnEdit;
	TLabeledEdit *PrvTxtInfLnEdit;
	TLabeledEdit *PrvTxtTailLnEdit;
	TLabeledEdit *RemoteWaitTimeEdit;
	TLabeledEdit *SpImg2Edit;
	TLabeledEdit *SpImgEdit;
	TLabeledEdit *SplitWidth2Edit;
	TLabeledEdit *SplitWidthEdit;
	TLabeledEdit *StdCmdPrmEdit;
	TLabeledEdit *SusieDirEdit;					//<<<<<<<X86_SPI
	TLabeledEdit *TabWidthEdit;
	TLabeledEdit *TabXWdEdit;
	TLabeledEdit *TempDirEdit;
	TLabeledEdit *TextEditorFrmtEdit;
	TLabeledEdit *TextEditorFrmt2Edit;
	TLabeledEdit *TextInterLnEdit;
	TLabeledEdit *ThumbBdrEdit;
	TLabeledEdit *ThumbSizeEdit;
	TLabeledEdit *TileIfSzEdit;
	TLabeledEdit *TimerCmd1Edit;
	TLabeledEdit *TimerCnd1Edit;
	TLabeledEdit *TmStampFmtEdit;
	TLabeledEdit *ToleranceEdit;
	TLabeledEdit *ToolAliasEdit;
	TLabeledEdit *ToolDirEdit;
	TLabeledEdit *ToolExeEdit;
	TLabeledEdit *ToolPrmEdit;
	TLabeledEdit *ToolTitEdit;
	TLabeledEdit *ViewTab4Edit;
	TLabeledEdit *ViewTabXEdit;
	TLabeledEdit *ViewWheelScrLnEdit;
	TLabeledEdit *WatchIntervalEdit;
	TLabeledEdit *WebSeaUrlEdit;
	TListBox *AssociateListBox;
	TListBox *EtcEditorListBox;
	TListBox *EventListBox;
	TListBox *ExtColListBox;
	TListBox *KeyListBox;
	TListBox *OptColListBox;
	TListBox *PrtDirListBox;
	TListBox *SpiListBox;				//<<<<<<<X86_SPI
	TListBox *StdCmdListBox;
	TListBox *TagColListBox;
	TListBox *TimColListBox;
	TListBox *VirDrvListBox;
	TMenuItem *Frmt_B_Item;
	TMenuItem *Frmt_D_Item;
	TMenuItem *Frmt_F_Item;
	TMenuItem *Frmt_N_Item;
	TMenuItem *Frmt_O_Item;
	TMenuItem *Frmt_P_Item;
	TMenuItem *Frmt_Q_Item;
	TMenuItem *Frmt_R_Item;
	TMenuItem *Frmt_X_Item;
	TPageControl *PageControl1;
	TPanel *AsoPanel;
	TPanel *BevelPanel1;
	TPanel *BevelPanel2;
	TPanel *BevelPanel3;
	TPanel *BottomPanel;
	TPanel *ExtMenuPanel;
	TPanel *ExtToolPanel;
	TPanel *KeySetPanel;
	TPanel *KeySpcPanel;
	TPanel *RefExtColPanel;
	TPanel *SpuitPanel;
	TPanel *SpuitPanel2;
	TPanel *SpuitPanel3;
	TPanel *SpuitPanel4;
	TPopupMenu *TestPopupMenu;
	TPopupMenu *ToolPopupMenu;
	TRadioButton *FitFoldRadioBtn;
	TRadioButton *IniWin0RadioBtn;
	TRadioButton *IniWin1RadioBtn;
	TRadioButton *IniWork0RadioBtn;
	TRadioButton *IniWork1RadioBtn;
	TRadioButton *L_IniPatMod0RadioBtn;
	TRadioButton *L_IniPatMod1RadioBtn;
	TRadioButton *L_IniPatMod2RadioBtn;
	TRadioButton *R_IniPatMod0RadioBtn;
	TRadioButton *R_IniPatMod1RadioBtn;
	TRadioButton *R_IniPatMod2RadioBtn;
	TRadioButton *SetFoldRadioBtn;
	TRadioGroup *IniModeIRadioGroup;
	TRadioGroup *KeybdRadioGroup;
	TRadioGroup *L_IniSortRadioGroup;
	TRadioGroup *PrtDirRadioGroup;
	TRadioGroup *R_IniSortRadioGroup;
	TShape *Shape1;
	TShape *Shape2;
	TShape *Shape3;
	TShape *Shape4;
	TShape *Shape5;
	TShape *Shape6;
	TSpeedButton *RefToolFmtBtn;
	TTabControl *KeyTabControl;
	TTabSheet *AssoSheet;
	TTabSheet *CommandSheet;
	TTabSheet *DesignSheet;
	TTabSheet *EditorSheet;
	TTabSheet *EventSheet;
	TTabSheet *ExtMenuSheet;
	TTabSheet *ExtToolSheet;
	TTabSheet *FontColSheet;
	TTabSheet *General2Sheet;
	TTabSheet *GeneralSheet;
	TTabSheet *ImgViewerSheet;
	TTabSheet *KeySetSheet;
	TTabSheet *MouseSheet;
	TTabSheet *NotifySheet;
	TTabSheet *StartupSheet;
	TTabSheet *TxtViewerSheet;
	TVirtualImageList *IconVImgListP;
	TImageCollection *ImgCollectionP;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormDestroy(TObject *Sender);
	bool __fastcall FormHelp(WORD Command, THelpEventData Data, bool &CallHelp);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall PageControl1Change(TObject *Sender);
	void __fastcall PageControl1DrawTab(TCustomTabControl *Control, int TabIndex, const TRect &Rect, bool Active);
	void __fastcall KeybdRadioGroupClick(TObject *Sender);
	void __fastcall RefTmpDirBtnClick(TObject *Sender);
	void __fastcall RefMigemoBtnClick(TObject *Sender);
	void __fastcall RefCmdGitExeBtnClick(TObject *Sender);
	void __fastcall EtcEditorListBoxDrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);
	void __fastcall EtcEditorListBoxClick(TObject *Sender);
	void __fastcall RefEditorBtnClick(TObject *Sender);
	void __fastcall RefSoundBtnClick(TObject *Sender);
	void __fastcall TestSoundBtnClick(TObject *Sender);
	void __fastcall ExtSavDirHistCheckBoxClick(TObject *Sender);
	void __fastcall LayoutChange(TObject *Sender);
	void __fastcall RefBgImgBtnClick(TObject *Sender);
	void __fastcall ScrBarStyleComboBoxClick(TObject *Sender);
	void __fastcall FontComboBoxDrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);
	void __fastcall RefFontBtnClick(TObject *Sender);
	void __fastcall OptColListBoxDrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);
	void __fastcall RefColBtnClick(TObject *Sender);
	void __fastcall ModalColorBoxChange(TObject *Sender);
	void __fastcall DisableColActionExecute(TObject *Sender);
	void __fastcall DisableColActionUpdate(TObject *Sender);
	void __fastcall DisableTimColActionExecute(TObject *Sender);
	void __fastcall DisableTimColActionUpdate(TObject *Sender);
	void __fastcall SpuitImageMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall SpuitImageMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall ModalAlphaEditChange(TObject *Sender);
	void __fastcall ExtColListBoxClick(TObject *Sender);
	void __fastcall ExtColListBoxDrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);
	void __fastcall RefExtColBtnClick(TObject *Sender);
	void __fastcall AddExtColActionExecute(TObject *Sender);
	void __fastcall AddExtColActionUpdate(TObject *Sender);
	void __fastcall ChgExtColActionExecute(TObject *Sender);
	void __fastcall ChgExtColActionUpdate(TObject *Sender);
	void __fastcall FindXColEditChange(TObject *Sender);
	void __fastcall TagColListBoxDrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);
	void __fastcall RefTagColBtnClick(TObject *Sender);
	void __fastcall DefTagColActionExecute(TObject *Sender);
	void __fastcall DefTagColActionUpdate(TObject *Sender);
	void __fastcall RevTagColCheckBoxClick(TObject *Sender);
	void __fastcall FindColEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FindColDownActionExecute(TObject *Sender);
	void __fastcall FindColDownActionUpdate(TObject *Sender);
	void __fastcall FindColUpActionExecute(TObject *Sender);
	void __fastcall FindColUpActionUpdate(TObject *Sender);
	void __fastcall FindColEditChange(TObject *Sender);
	void __fastcall OptListBoxKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall RefSusieDirBtnClick(TObject *Sender);					//<<<<<<<X86_SPI
	void __fastcall ConfigSpiActionExecute(TObject *Sender);				//<<<<<<<X86_SPI
	void __fastcall ConfigSpiActionUpdate(TObject *Sender);					//<<<<<<<X86_SPI
	void __fastcall AddEtcEditorActionExecute(TObject *Sender);
	void __fastcall AddEtcEditorActionUpdate(TObject *Sender);
	void __fastcall ChgEtcEditorActionExecute(TObject *Sender);
	void __fastcall ChgEtcEditorActionUpdate(TObject *Sender);
	void __fastcall ExtToolListBoxClick(TObject *Sender);
	void __fastcall ToolTitEditChange(TObject *Sender);
	void __fastcall AddToolActionExecute(TObject *Sender);
	void __fastcall ChgToolActionExecute(TObject *Sender);
	void __fastcall ChgToolActionUpdate(TObject *Sender);
	void __fastcall RefExeBtnClick(TObject *Sender);
	void __fastcall RefToolFmtBtnClick(TObject *Sender);
	void __fastcall FrmtItemClick(TObject *Sender);
	void __fastcall RefDirBtnClick(TObject *Sender);
	void __fastcall ExtMenuListBoxClick(TObject *Sender);
	void __fastcall MenuCmdComboBoxChange(TObject *Sender);
	void __fastcall MenuTitEditChange(TObject *Sender);
	void __fastcall AddMenuActionExecute(TObject *Sender);
	void __fastcall ChgMenuActionExecute(TObject *Sender);
	void __fastcall ChgMenuActionUpdate(TObject *Sender);
	void __fastcall RefCmdsBtnClick(TObject *Sender);
	void __fastcall RefMenuIconBtnClick(TObject *Sender);
	void __fastcall AssociateListBoxClick(TObject *Sender);
	void __fastcall AssociateListBoxMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall TestAdvancedDrawItem(TObject *Sender, TCanvas *ACanvas, const TRect &ARect, TOwnerDrawState State);
	void __fastcall TestPopupMenuPopup(TObject *Sender);
	void __fastcall AsoAppComboBoxDropDown(TObject *Sender);
	void __fastcall AddAssoActionExecute(TObject *Sender);
	void __fastcall ChgAssoActionExecute(TObject *Sender);
	void __fastcall ChgAssoActionUpdate(TObject *Sender);
	void __fastcall AsoRefBtnClick(TObject *Sender);
	void __fastcall OptListBoxDrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);
	void __fastcall OptMenuListBoxDrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);
	void __fastcall ExtMenuHeaderSectionResize(THeaderControl *HeaderControl, THeaderSection *Section);
	void __fastcall ExtToolHeaderSectionResize(THeaderControl *HeaderControl, THeaderSection *Section);
	void __fastcall KeyTabControlDrawTab(TCustomTabControl *Control, int TabIndex, const TRect &Rect, bool Active);
	void __fastcall KeyTabControlChanging(TObject *Sender, bool &AllowChange);
	void __fastcall KeyTabControlChange(TObject *Sender);
	void __fastcall KeyHeaderControlDrawSection(THeaderControl *HeaderControl, THeaderSection *Section,
			const TRect &Rect, bool Pressed);
	void __fastcall ExtHeaderDrawSection(THeaderControl *HeaderControl, THeaderSection *Section,
		const TRect &Rect, bool Pressed);
	void __fastcall KeyHeaderControlSectionClick(THeaderControl *HeaderControl, THeaderSection *Section);
	void __fastcall KeyComboBoxDrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);
	void __fastcall CmdComboBoxDrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);
	void __fastcall CmdComboBoxChange(TObject *Sender);
	void __fastcall UnRegCmdCheckBoxClick(TObject *Sender);
	void __fastcall KeyListBoxClick(TObject *Sender);
	void __fastcall KeyListBoxDblClick(TObject *Sender);
	void __fastcall KeySetClick(TObject *Sender);
	void __fastcall KeyFilterEdit_Change(TObject *Sender);
	void __fastcall KeyFilterEdit_KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall KeyFilterEdit_KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall FindKeyBtnClick(TObject *Sender);
	void __fastcall FindKeyEditChange(TObject *Sender);
	void __fastcall FindKeyEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FindKeyDownActionExecute(TObject *Sender);
	void __fastcall FindKeyDownActionUpdate(TObject *Sender);
	void __fastcall FindKeyUpActionExecute(TObject *Sender);
	void __fastcall FindKeyUpActionUpdate(TObject *Sender);
	void __fastcall KeyListBoxDrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);
	void __fastcall RefCmdPrmBtnClick(TObject *Sender);
	void __fastcall AddKeyActionExecute(TObject *Sender);
	void __fastcall AddKeyActionUpdate(TObject *Sender);
	void __fastcall ChgKeyActionExecute(TObject *Sender);
	void __fastcall ChgKeyActionUpdate(TObject *Sender);
	void __fastcall DelKeyActionExecute(TObject *Sender);
	void __fastcall DelKeyActionUpdate(TObject *Sender);
	void __fastcall FindEditChange(TObject *Sender);
	void __fastcall RefIniPatBtnClick(TObject *Sender);
	void __fastcall L_IniPatMod1RadioBtnClick(TObject *Sender);
	void __fastcall R_IniPatMod1RadioBtnClick(TObject *Sender);
	void __fastcall RefHomeWorkBtnClick(TObject *Sender);
	void __fastcall RefVDrvBtnClick(TObject *Sender);
	void __fastcall VirDrvListBoxClick(TObject *Sender);
	void __fastcall AddDrvActionExecute(TObject *Sender);
	void __fastcall AddDrvActionUpdate(TObject *Sender);
	void __fastcall ChgDrvActionExecute(TObject *Sender);
	void __fastcall ChgDrvActionUpdate(TObject *Sender);
	void __fastcall DelDrvActionExecute(TObject *Sender);
	void __fastcall DelDrvActionUpdate(TObject *Sender);
	void __fastcall InpColBtnClick(TObject *Sender);
	void __fastcall ExpColBtnClick(TObject *Sender);
	void __fastcall InpKeyBtnClick(TObject *Sender);
	void __fastcall ExpKeyBtnClick(TObject *Sender);
	void __fastcall AlRightBtnClick(TObject *Sender);
	void __fastcall MaxWdBtnClick(TObject *Sender);
	void __fastcall MaxHiBtnClick(TObject *Sender);
	void __fastcall IniWinSizeChange(TObject *Sender);
	void __fastcall StdCmdListBoxClick(TObject *Sender);
	void __fastcall StdCmdComboBoxChange(TObject *Sender);
	void __fastcall StdCmdListBoxDrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);
	void __fastcall RefStdCmdPrmBtnClick(TObject *Sender);
	void __fastcall AddStdCmdActionExecute(TObject *Sender);
	void __fastcall AddStdCmdActionUpdate(TObject *Sender);
	void __fastcall ChgStdCmdActionExecute(TObject *Sender);
	void __fastcall ChgStdCmdActionUpdate(TObject *Sender);
	void __fastcall EventListBoxClick(TObject *Sender);
	void __fastcall EventCmdsEditChange(TObject *Sender);
	void __fastcall FindEvEditChange(TObject *Sender);
	void __fastcall FindEvEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FindEvDownActionExecute(TObject *Sender);
	void __fastcall FindEvDownActionUpdate(TObject *Sender);
	void __fastcall FindEvUpActionExecute(TObject *Sender);
	void __fastcall FindEvUpActionUpdate(TObject *Sender);
	void __fastcall EditFileActionExecute(TObject *Sender);
	void __fastcall EditFileActionUpdate(TObject *Sender);
	void __fastcall PrtDirListBoxDrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);
	void __fastcall AddPrtDirActionExecute(TObject *Sender);
	void __fastcall AppDesignBtnClick(TObject *Sender);
	void __fastcall AppColorBtnClick(TObject *Sender);
	void __fastcall OkActionExecute(TObject *Sender);
	void __fastcall OkActionUpdate(TObject *Sender);
	void __fastcall CanButtonClick(TObject *Sender);

private:	// ユーザー宣言
	MarkList *FindMarkList;
	TStringList *FontBufList;
	TStringList *ColBufList;
	TStringList *KeyListBuf[5];

	int inh_KeySet;
	int KeySortMode;
	int PrevListIdx;
	int SpuitTag;

	int MaxWd_AssExt;
	int MaxWd_Ev;
	int MaxWd_Tag;

	bool DlgInitialized;
	bool IsDkAll;
	bool IsDkKey;

	UsrSwatchPanel *SwatchPanel;

	TLabel *KeyKeyLabel;

	void __fastcall WmFormShowed(TMessage &msg);

	void __fastcall WmDpiChanged(TMessage &msg)
	{
		TForm::Dispatch(&msg);
		RefreshDarkMode(this);
		UpdateMaxItemWidth();
	}

	void __fastcall InitializeOptListBox();
	void __fastcall SetWinTheme(bool force = false);
	void __fastcall DeselectComboBox(TGroupBox *gp);
	void __fastcall UpdateMaxItemWidth();

	UnicodeString __fastcall GetCmdModeStr(int idx = 0);
	UnicodeString __fastcall GetCmdKeyStr();
	bool __fastcall IsFirstCmdKey();

	bool __fastcall CheckDuplExt(int skip_idx = -1);
	void __fastcall SetKeyComboBox();
	void __fastcall UpdateKeyComboStt();
	void __fastcall SetExtToolExeName(UnicodeString fnam);
	void __fastcall ChangeExtToolList(bool add);
	void __fastcall ChangeExtMenuList(bool add);
	void __fastcall ChangeAssociateList(bool add);
	void __fastcall SortKeyListBox(UnicodeString item = EmptyStr);
	void __fastcall ChangeKeyList(bool add);
	bool __fastcall CheckKeyAction(bool ok, bool add = false);
	bool __fastcall MatchKeyItem(int idx);
	void __fastcall SetCmdCombo(UnicodeString kwd = EmptyStr);
	void __fastcall SortAssoListBox(UnicodeString item);
	void __fastcall UpdateSpiListBox();						//<<<<<<<X86_SPI
	TCustomListBox * __fastcall GetCurListBox();

	void __fastcall UpdateAlias(UnicodeString o_name, UnicodeString n_name);
	UnicodeString __fastcall get_AliasInfo(UnicodeString alias);
	bool __fastcall CheckDuplAliasMsg(UnicodeString alias, TCheckListBox *lp);

	void __fastcall ChangeStdCmdList(bool add);

	void __fastcall WmDropped(TMessage &msg);

	void __fastcall WmNyanFiFlIcon(TMessage &msg)
	{
		AssociateListBox->Invalidate();
		ExtMenuListBox->Invalidate();
		ExtToolListBox->Invalidate();
		EtcEditorListBox->Invalidate();
	}

	void __fastcall WmNyanFiClsEdItm(TMessage &msg)
	{
		UserModule->InitializeListBox(GetCurListBox());
	}

public:		// ユーザー宣言
	bool KeySetOnly;		//キー設定のみ表示

	bool LayoutChanged;
	bool WinSizeChanged;
	bool TlBarColChanged;
	bool DlgFontChanged;

	UsrHintWindow *SplashHint;

	__fastcall TOptionDlg(TComponent* Owner);
	void __fastcall SetSheet(UnicodeString prm);

	BEGIN_MESSAGE_MAP
		VCL_MESSAGE_HANDLER(WM_FORM_SHOWED,		TMessage,	WmFormShowed)
		VCL_MESSAGE_HANDLER(WM_DPICHANGED,		TMessage,	WmDpiChanged)
		VCL_MESSAGE_HANDLER(WM_FORM_DROPPED,	TMessage,	WmDropped)
		VCL_MESSAGE_HANDLER(WM_NYANFI_FLICON,	TMessage,	WmNyanFiFlIcon)
		VCL_MESSAGE_HANDLER(WM_NYANFI_CLSEDITM,	TMessage,	WmNyanFiClsEdItm)
	END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern PACKAGE TOptionDlg *OptionDlg;
//---------------------------------------------------------------------------
#endif
