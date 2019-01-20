//----------------------------------------------------------------------//
// Susie 32bit Plug-in 操作クラス										//
//																		//
//----------------------------------------------------------------------//
#ifndef SpiUnitH
#define SpiUnitH

//---------------------------------------------------------------------------
#include <time.h>

//---------------------------------------------------------------------------
#define SPI_CHECKSIZE 2048

//---------------------------------------------------------------------------
#pragma pack(push, 1)
//---------------------------------------------------------------------------
typedef struct pic_info {
	long   left, top;
	long   width;
	long   height;
	WORD   x_density;
	WORD   y_density;
	short  color;
	HLOCAL info;
} pic_info;

//---------------------------------------------------------------------------
typedef struct fileInfo
{
	unsigned char method[8];	//圧縮法
	unsigned long position; 	//ファイル上での位置
	unsigned long compsize;		//圧縮されたサイズ
	unsigned long filesize;		//元のファイルサイズ
	time_t timestamp;			//更新日時
	char path[200];				//相対パス
	char filename[200];			//ファイルネーム
	unsigned long crc;			//CRC
} fileInfo;
//---------------------------------------------------------------------------
typedef struct fileInfoW
{
	unsigned char method[8];	//圧縮法
	unsigned long position; 	//ファイル上での位置
	unsigned long compsize;		//圧縮されたサイズ
	unsigned long filesize;		//元のファイルサイズ
	time_t timestamp;			//更新日時
	wchar_t path[200];			//相対パス
	wchar_t filename[200];		//ファイルネーム
	unsigned long crc;			//CRC
} fileInfoW;
//---------------------------------------------------------------------------
#pragma pack(pop)

//---------------------------------------------------------------------------
typedef int (CALLBACK *SPI_PROGRESS)(int, int, long);
typedef int (__stdcall *SPI_GetPluginInfo)(int infono, LPSTR buf, int buflen);
typedef int (__stdcall *SPI_IsSupported)(LPSTR filename, DWORD dw);
typedef int (__stdcall *SPI_GetPictureInfo)(LPSTR buf, long len,
					unsigned int flag, struct pic_info *lpInfo);
typedef int (__stdcall *SPI_GetPicture)(LPSTR buf, long len, unsigned int flag,
					HANDLE *pHBInfo, HANDLE *pHBm, SPI_PROGRESS lpPrgressCallback, long lData);

typedef int (__stdcall *SPI_ConfigurationDlg)(HWND hWnd, int function);

typedef int (__stdcall *SPI_GetArchiveInfo)(LPSTR buf, long len, unsigned int flag, HLOCAL *lphInf);
typedef int (__stdcall *SPI_GetArchiveInfoW)(LPCWSTR buf, long len, unsigned int flag, HLOCAL *lphInf);
typedef int (__stdcall *SPI_GetArchiveInfo)(LPSTR buf, long len, unsigned int flag, HLOCAL *lphInf);
typedef int (__stdcall *SPI_GetFileInfo)(LPSTR buf, long len, LPSTR filename, unsigned int flag, fileInfo *lpInfo);
typedef int (__stdcall *SPI_GetFileInfoW)(LPCWSTR buf, long len, LPCWSTR filename, unsigned int flag, fileInfoW *lpInfo);
typedef int (__stdcall *SPI_GetFile)(LPSTR src, long len, LPSTR dest, unsigned int flag, FARPROC prgressCallback, long lData);
typedef int (__stdcall *SPI_GetFileW)(LPCWSTR src, long len, LPWSTR dest, unsigned int flag, FARPROC prgressCallback, long lData);

//---------------------------------------------------------------------------
struct spi_info {
	HMODULE hDLL;
	SPI_GetPluginInfo		GetPluginInfo;
	SPI_IsSupported			IsSupported;
	SPI_GetPictureInfo		GetPictureInfo;
	SPI_GetPicture	 		GetPicture;
	SPI_ConfigurationDlg	ConfigurationDlg;

	SPI_GetArchiveInfo		GetArchiveInfo;
	SPI_GetArchiveInfoW		GetArchiveInfoW;
	SPI_GetFileInfo			GetFileInfo;
	SPI_GetFileInfoW		GetFileInfoW;
	SPI_GetFile				GetFile;
	SPI_GetFileW			GetFileW;

	bool is_Arc;
	UnicodeString VerType;	//"00IN" or "00AM"
	UnicodeString FileName;
	UnicodeString FileInfo;
	UnicodeString FileExt;
	UnicodeString FileType;
};

//---------------------------------------------------------------------------
//SPIリスト (TList から継承)
//---------------------------------------------------------------------------
class TSpiList : public TList
{
private:
	spi_info * __fastcall Get(int Index)
	{
		return (spi_info*)(TList::Get(Index));
	}
	void __fastcall Put(int Index, spi_info *Item)
	{
		TList::Put(Index, Item);
	}

public:
	__fastcall TSpiList();
	__property spi_info * Items[int Index] = {read=Get, write=Put};
};

//---------------------------------------------------------------------------
class SpiUnit
{
public:
	UnicodeString SpiDir;
	TSpiList *PlgList;
	UnicodeString ErrMsg;

	SpiUnit(UnicodeString spidir);
	~SpiUnit();

	bool TestFExt(UnicodeString fext, bool is_arc = false);
	UnicodeString GetImgFExt();
	bool GetImgSize(UnicodeString fnam, unsigned int *w, unsigned int *h);
	spi_info* FindPlugin(UnicodeString fnam, bool is_arc = false);
	bool LoadImage(UnicodeString fnam, Graphics::TBitmap *bmp, spi_info *sp = NULL);

	bool UnPack(UnicodeString arc_file, UnicodeString fnam, TMemoryStream *ms);
	bool UnPack(UnicodeString arc_file, UnicodeString fnam, UnicodeString dst_dir);
};
//---------------------------------------------------------------------------
#endif
