

#include "PENTA.h"
#define IDI_CON1 101
#define IDI_CON2 102
	// プログラムは WinMain から始まります
	int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetWindowText("PENTA");
	SetBackgroundColor(0, 0, 0);
	SetWindowIconID(IDI_CON2);
	
	SetWindowSize(640, 480);
	if (DxLib_Init() == -1)		 // ＤＸライブラリ初期化処理
	{
		return -1;			     // エラーが起きたら直ちに終了
	}
	PENTA  pen;
	pen.Title();                 // 本編
	SetAlwaysRunFlag(true);
	//pen.CreateStageHintData(); //ヒントデータ作成
	//pen.CreateClearDataOfNotTurn(); //回転操作が禁止された盤面データの作成
	DxLib_End();				 // ＤＸライブラリ使用の終了処理
	
	return 0;				     // ソフトの終了 
}
