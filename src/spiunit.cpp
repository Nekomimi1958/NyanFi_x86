//----------------------------------------------------------------------//
// Susie 32bit 書庫 Plug-in 操作クラス									//
//																		//
//----------------------------------------------------------------------//
#include "usr_str.h"
#include "usr_file_ex.h"
#include "usr_shell.h"
#include "usr_arc.h"
#include "spiunit.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
__fastcall TSpiList::TSpiList(): TList()
{
}

//---------------------------------------------------------------------------
SpiUnit::SpiUnit(UnicodeString spidir)
{
	PlgList = new TSpiList();
	if (spidir.IsEmpty()) return;

	try {
		SpiDir = IncludeTrailingPathDelimiter(spidir);
		TSearchOption opt = TSearchOption::soTopDirectoryOnly;
		TStringDynArray f_list = TDirectory::GetFiles(SpiDir, "*.SPI", opt);

		for (int i=0; i<f_list.Length; ++i) {
			UnicodeString dllnam = f_list[i];
			HMODULE handle = ::LoadLibrary(dllnam.c_str());	if (!handle) continue;
			spi_info *sp = new spi_info;
			sp->hDLL			 = handle;
			sp->GetPluginInfo	 = (SPI_GetPluginInfo)   ::GetProcAddress(handle, "GetPluginInfo");
			sp->IsSupported 	 = (SPI_IsSupported)     ::GetProcAddress(handle, "IsSupported");
			sp->GetPictureInfo	 = (SPI_GetPictureInfo)  ::GetProcAddress(handle, "GetPictureInfo");
			sp->GetPicture		 = (SPI_GetPicture)      ::GetProcAddress(handle, "GetPicture");
			sp->ConfigurationDlg = (SPI_ConfigurationDlg)::GetProcAddress(handle, "ConfigurationDlg");

			sp->GetArchiveInfo	 = (SPI_GetArchiveInfo)  ::GetProcAddress(handle, "GetArchiveInfo");
			sp->GetArchiveInfoW  = (SPI_GetArchiveInfoW) ::GetProcAddress(handle, "GetArchiveInfoW");
			sp->GetFileInfo 	 = (SPI_GetFileInfo)	 ::GetProcAddress(handle, "GetFileInfo");
			sp->GetFileInfoW	 = (SPI_GetFileInfoW)	 ::GetProcAddress(handle, "GetFileInfoW");
			sp->GetFile 		 = (SPI_GetFile)		 ::GetProcAddress(handle, "GetFile");
			sp->GetFileW		 = (SPI_GetFileW)		 ::GetProcAddress(handle, "GetFileW");

			bool flag = false;
			if (sp->GetPluginInfo && sp->IsSupported) {
				char ibuf[8];
				if ((*sp->GetPluginInfo)(0, ibuf, 5)>=4) {
					char tbuf[256];
					const char *null_char = "";
					sp->FileName = dllnam;
					sp->FileInfo = ((*sp->GetPluginInfo)(1, tbuf, 256)>0)? tbuf : null_char;
					sp->FileExt  = ((*sp->GetPluginInfo)(2, tbuf, 256)>0)? tbuf : null_char;
					sp->FileType = ((*sp->GetPluginInfo)(3, tbuf, 256)>0)? tbuf : null_char;
					UnicodeString tmp;
					//Import / Normal
					if (ibuf[2]=='I' && ibuf[3]=='N' && sp->GetPictureInfo && sp->GetPicture) {
						sp->is_Arc	 = false;
						sp->VerType  = tmp.sprintf(_T("%c%cIN"), ibuf[0], ibuf[1]);
						PlgList->Add(sp);
						flag = true;
					}
					//Archive extractor / Multi-picture
					else if (ibuf[2]=='A' && ibuf[3]=='M' && sp->GetArchiveInfo && sp->GetFileInfo && sp->GetFile) {
						sp->is_Arc	 = true;
						sp->VerType  = tmp.sprintf(_T("%c%cAM"), ibuf[0], ibuf[1]);
						//アーカイバDLLが対応しているものは除外
						TStringDynArray xlst = split_strings_semicolon(sp->FileExt);
						bool ok = true;
						for (int j=0; j<xlst.Length; j++) {
							UnicodeString fext = ReplaceStr(ExtractFileExt(xlst[j]), "*", EmptyStr);
							if (test_FileExt(fext, FEXT_ZIP FEXT_7Z FEXT_LHA FEXT_CAB FEXT_TAR FEXT_RAR FEXT_ISO)) {
								ok = false; break;
							}
						}
						if (ok) {
							PlgList->Add(sp);
							flag = true;
						}
					}
				}
			}

			if (!flag) {
				::FreeLibrary(handle);
				delete sp;
			}
		}
	}
	catch(...) {
		return;
	}
}

//---------------------------------------------------------------------------
SpiUnit::~SpiUnit()
{
	for (int i=0; i<PlgList->Count; i++) {
		::FreeLibrary(PlgList->Items[i]->hDLL);
		delete PlgList->Items[i];
	}
	delete PlgList;
}

//---------------------------------------------------------------------------
//対応拡張子かチェック
//---------------------------------------------------------------------------
bool SpiUnit::TestFExt(UnicodeString fext, bool is_arc)
{
	if (fext.IsEmpty() || SameStr(fext, ".")) return false;
	if (!StartsStr('.', fext)) fext.Insert(".", 1);

	bool found = false;
	for (int i=0; i<PlgList->Count; i++) {
		spi_info *sp = PlgList->Items[i];
		if (is_arc && !sp->is_Arc) continue;
		if (!is_arc && sp->is_Arc) continue;
		if (test_FileExt(fext, ReplaceStr(ReplaceStr(sp->FileExt, "*", EmptyStr), ";", "."))) {
			found = true; break;
		}
	}
	return found;
}

//---------------------------------------------------------------------------
//対応画像拡張子のリストを取得
//---------------------------------------------------------------------------
UnicodeString SpiUnit::GetImgFExt()
{
	UnicodeString ret_str;
	for (int i=0; i<PlgList->Count; i++) {
		spi_info *sp = PlgList->Items[i];
		if (sp->is_Arc) continue;
		ret_str += ReplaceStr(ReplaceStr(sp->FileExt, "*", EmptyStr), ";", EmptyStr);
	}
	return ret_str;
}

//---------------------------------------------------------------------------
//対応するプラグインを探す
//---------------------------------------------------------------------------
spi_info* SpiUnit::FindPlugin(UnicodeString fnam, bool is_arc)
{
	if (!FileExists(fnam)) return NULL;
	if (PlgList->Count==0) return NULL;

	UnicodeString fext = ExtractFileExt(fnam);
	if (fext.IsEmpty() || SameStr(fext, ".")) return NULL;

	spi_info *r_sp = NULL;

	//書庫系はまず拡張子でチェック
	if (is_arc) {
		for (int i=0; i<PlgList->Count; i++) {
			spi_info *sp = PlgList->Items[i];
			if (sp->is_Arc && ContainsText(sp->FileExt, fext)) {
				r_sp = sp; break;
			}
		}
		if (r_sp) return r_sp;
	}

	try {
		char fstr[MAX_PATH];
		strcpy(fstr, AnsiString(fnam).c_str());

		//ファイルの先頭2KBを読み込む
		std::unique_ptr<TFileStream> fs(new TFileStream(fnam, fmOpenRead | fmShareDenyNone));
		std::unique_ptr<char[]> fbuf(new char[SPI_CHECKSIZE]);
		::ZeroMemory(fbuf.get(), SPI_CHECKSIZE);
		DWORD dw = (DWORD)(fbuf.get());
		if (fs->Read(fbuf.get(), SPI_CHECKSIZE)>0) {
			//プラグインを探す
			for (int i=0; i<PlgList->Count; i++) {
				spi_info *sp = PlgList->Items[i];
				if (is_arc && !sp->is_Arc) continue;
				if (!is_arc && sp->is_Arc) continue;
				if ((*sp->IsSupported)((LPSTR)fstr, dw) != 0) {
					r_sp = sp; break;
				}
			}
		}
		return r_sp;
	}
	catch(...) {
		return NULL;
	}
}

//---------------------------------------------------------------------------
//画像のサイズを取得
//---------------------------------------------------------------------------
bool SpiUnit::GetImgSize(UnicodeString fnam, unsigned int *w, unsigned int *h)
{
	if (!FileExists(fnam) || !w || !h) return false;

	try {
		spi_info *sp = FindPlugin(fnam);
		if (!sp) throw Exception(EmptyStr);

		char fstr[MAX_PATH];
		strcpy(fstr, AnsiString(fnam).c_str());
		pic_info pinf;
		if (sp->GetPictureInfo((LPSTR)fstr, 0, 0, &pinf)!=0) throw Exception(EmptyStr);
		*w = pinf.width;
		*h = pinf.height;
		return true;
	}
	catch(...) {
		return false;
	}
}

//---------------------------------------------------------------------------
//画像をビットマップに読み込む
//---------------------------------------------------------------------------
bool SpiUnit::LoadImage(UnicodeString fnam, Graphics::TBitmap *bmp, spi_info *sp)
{
	if (PlgList->Count==0) return false;

	try {
		//対応しているプラグインを探す
		if (!sp) sp = FindPlugin(fnam);
		if (!sp) throw Exception(EmptyStr);

		char fstr[MAX_PATH];
		strcpy(fstr, AnsiString(fnam).c_str());

		HANDLE bmp_inf, bmp_dat;
		if ((*sp->GetPicture)((LPSTR)fstr, 0, 0, &bmp_inf, &bmp_dat, NULL, 0)!=0) throw Exception(EmptyStr);

		BITMAPINFO *p_inf = (BITMAPINFO*)::LocalLock(bmp_inf);
		VOID       *p_dat = ::LocalLock(bmp_dat);
		bmp->SetSize(p_inf->bmiHeader.biWidth, p_inf->bmiHeader.biHeight);
		int res = ::SetDIBits(bmp->Canvas->Handle, bmp->Handle,
					0, p_inf->bmiHeader.biHeight, p_dat, p_inf, DIB_RGB_COLORS);

		::LocalUnlock(bmp_inf);
		::LocalUnlock(bmp_dat);
		::LocalFree(bmp_inf);
		::LocalFree(bmp_dat);
		return (res>0);
	}
	catch(...) {
		return false;
	}
}

//---------------------------------------------------------------------------
//書庫内のファイルを取得
//---------------------------------------------------------------------------
bool SpiUnit::UnPack(UnicodeString arc_file, UnicodeString fnam, TMemoryStream *ms)
{
	try {
		char astr[MAX_PATH];
		strcpy(astr, AnsiString(arc_file).c_str());

		spi_info *sp = FindPlugin(arc_file, true);	if (!sp) Abort();

		HANDLE lphInfo;
		fileInfo  *pinf  = NULL;
		fileInfoW *pinfW = NULL;
		if (sp->GetArchiveInfoW) {
			if (sp->GetArchiveInfoW(arc_file.c_str(), 0, 0, &lphInfo)!=0) Abort();
			pinfW = reinterpret_cast<fileInfoW *>(lphInfo);
		}
		else {
			if (sp->GetArchiveInfo((LPSTR)astr, 0, 0, &lphInfo)!=0) Abort();
			pinf = reinterpret_cast<fileInfo *>(lphInfo);
		}

		HANDLE hMem = NULL;
		for (int f_idx=0; ; f_idx++) {
			int ret;
			if (pinfW) {
				fileInfoW *ipW = &pinfW[f_idx];	if  (ipW->method[0]=='\0') break;
				if (!SameText(fnam, ipW->filename)) continue;
				ret = sp->GetFileW(arc_file.c_str(), ipW->position, (LPWSTR)&hMem, 0x100, NULL, 0);
			}
			else {
				fileInfo *ip = &pinf[f_idx];	if  (ip->method[0]=='\0') break;
				if (!SameText(fnam, ip->filename)) continue;
				ret = sp->GetFile((LPSTR)astr, ip->position, (LPSTR)&hMem, 0x100, NULL, 0);
			}
			if (ret!=0) Abort();

			if (hMem) {
				void *bp = ::LocalLock(hMem);
				int   sz = ::LocalSize(hMem);
				if (ms) {
					ms->WriteBuffer(bp, sz);
					ms->Seek(0, soFromBeginning);
				}
				::LocalUnlock(hMem);
				::LocalFree(hMem);
			}
			break;
		}
		return true;
	}
	catch(...) {
		return false;
	}
}
//---------------------------------------------------------------------------
bool SpiUnit::UnPack(UnicodeString arc_file, UnicodeString fnam, UnicodeString dst_dir)
{
	try {
		std::unique_ptr<TStringList> f_lst(new TStringList());
		if (remove_top_AT(fnam)) {
			f_lst->LoadFromFile(fnam);
			for (int i=0; i<f_lst->Count; i++)
				f_lst->Strings[i] = exclude_quot(f_lst->Strings[i]);
		}
		else {
			f_lst->Add(fnam);
		}

		for (int i=0; i<f_lst->Count; i++) {
			UnicodeString bnam = f_lst->Strings[i];
			std::unique_ptr<TMemoryStream> ms(new TMemoryStream());
			if (!UnPack(arc_file, bnam, ms.get())) Abort();
			ms->SaveToFile(IncludeTrailingPathDelimiter(dst_dir) + bnam);
		}

		ErrMsg = EmptyStr;
		return true;
	}
	catch(...) {
		ErrMsg = "展開に失敗しました";
		return false;
	}
}
//---------------------------------------------------------------------------
