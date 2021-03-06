/******************************************************************************
 * SYSTEM       :   音声放送LIB
 * PROGRAM      :   放送を行うライブラリ
 * MODULE       :   sound_lib.h 
 * VERSION      : 	1.00.00 
 * REMARKS      :
 * HISTORY      :
 * ID-----------DATE--------NAME----------NOTE --------------------------------
 * [V01.00.00]  2015.2.2   晏       初期作成
 * [V01.00.01]  2015.2.6   晏       初期作成
 *****************************************************************************/

#ifndef SOUND_LIB
#define SOUND_LIB

#define DEFAULT_PLAY_TIMES 1														//デフォルト再生回数：1回

//#define play_wave_default(filename) play_wave(filename, DEFAULT_PLAY_TIMES)		//デフォルト再生回数の関数
#define FILENAME_SIZE		32														//ファイル名バッファサイズ
#define STOP_PLAY			1														//再生を中止する
#define IS_RUNNING			1														//再生中
//エラーコード
enum ERROR_CODE
{
	ERR_ZERO,
	ERR_FILE_OPEN,
	ERR_FILE_READ,
	ERR_FILE_WRITE,
	ERR_DEVICE_OPEN,
	ERR_DEVICE_READ,
	ERR_DEVICE_WRITE,
	ERR_DEVICE_SET,
	ERR_DEVICE_DESCRIPTOR,
	ERR_BROADCAST,
	ERR_SIZE,
	ERR_NOT_RIFF,
	ERR_NOT_WAVE,
	ERR_NOT_FIND_FMT_CHUNK,
	ERR_NOT_FIND_DATA_CHUNK,
	ERR_NOT_FIND_DATA,
	ERR_NOT_PCM,
	ERR_BITS_PER_SAMPLE,
	ERR_SET_FMT,
	ERR_WRITE_RATE,
	ERR_WRITE_CHANNEL		
};

typedef struct
{
	int stop_cmd;
	int status;
}play_stat;

extern int start_play_wave(int *dsp,  
						   const char *filename, 
						   int refresh_times,
						   play_stat *play_status);									//wavファイルを再生する関数
extern void stop_play_wave(play_stat *play_status);									//再生をストップ
extern int open_voice_device(int *dsp);												//デバイスを開く
extern int close_voice_device(int *dsp);											//デバイスをクロス

#endif
