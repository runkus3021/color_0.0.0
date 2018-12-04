#include "DxLib.h"
#include "math.h"
#include "stage.h" //ヘッダーファイルへstagedataを移動
#include "color_0.0.0\key.h"




//プロトタイプ
void init();//げーむそのものを初期化
void action();//動き
void draw();//画像

//関数の外で変数を宣言する
//グローバル変数という
//画像ハンドル（画像のメモリ上の場所が入っている


//マップ仕様
//6×6
//64×64ドット


//花1
int hanaImage_1[5];
#define F1_TANE 0
#define F1_HATUGA 1
#define F1_TUBOMI 2
#define F1_KAIKA 3
#define F1_KARE 4
//花1アニメーション
int hana_1_Anim = 0;
//アニメーションタイマー
int aniTimer = 0;

//花1アニメーション
void anim()
{
	if (aniTimer < 180)
	{
		hana_1_Anim = F1_TANE;
	}
	else if (aniTimer < 360)
	{
		hana_1_Anim = F1_HATUGA;
	}
	else if (aniTimer < 540)
	{
		hana_1_Anim = F1_TUBOMI;
	}
	else if (aniTimer < 720)
	{
		hana_1_Anim = F1_KAIKA;
	}
	else
	{
		hana_1_Anim = F1_KARE;
		if (CheckHitKey(KEY_INPUT_P))
		{
			aniTimer = 0;
		}
	}
}




//花2
int hanaImage_2[5];
#define F2_TANE 0
#define F2_HATUGA 1
#define F2_TUBOMI 2
#define F2_KAIKA 3
#define F2_KARE 4


int info = 0;

//タイトル画面イメージ用
int title_Image = 0;

//メニュー画面用
int menu_Image = 0;
//メニュー画面タイトル選択用
int menu_stage1 = 0;
//メニュー画面タイトル戻りよう
int menu_Title = 0;
//選択用
int sentaku = 0;
bool chengeFlg = false;


//タイトルスタートのやつ
//拡大縮小させたい
int startImage = 0;

int sean = 0;
#define SEAN_TITLE 0
#define SEAN_MENU 1
#define SEAN_GAME 2
#define SEAN_CLEAR 3



//配列準備
int blockImage[4];




//初期化する関数
void init()
{
	//花1
	hanaImage_1[F1_TANE] = LoadGraph("data/gameimage/1_1_tane.jpg");
	hanaImage_1[F1_HATUGA] = LoadGraph("data/gameimage/1_2_hatuga.jpg");
	hanaImage_1[F1_TUBOMI] = LoadGraph("data/gameimage/1_3_tubomi.jpg");
	hanaImage_1[F1_KAIKA] = LoadGraph("data/gameimage/1_4_kaika.jpg");
	hanaImage_1[F1_KARE] = LoadGraph("data/gameimage/1_5_kare.jpg");

	//花2
	hanaImage_1[F2_TANE] = LoadGraph("data/gameimage/2_1_tane.jpg");
	hanaImage_1[F2_HATUGA] = LoadGraph("data/gameimage/2_2_hatuga.jpg");
	hanaImage_1[F2_TUBOMI] = LoadGraph("data/gameimage/2_3_tubomi.jpg");
	hanaImage_1[F2_KAIKA] = LoadGraph("data/gameimage/2_4_kaika.jpg");
	hanaImage_1[F2_KARE] = LoadGraph("data/gameimage/2_5_kare.jpg");




	//64×64
	blockImage[COLOR1] = LoadGraph("data/hana_tuti.jpg");
	blockImage[COLOR2] = LoadGraph("data/hana.jpg");
	blockImage[COLOR3] = LoadGraph("data/color3.png");
	blockImage[COLOR4] = LoadGraph("data/color4.png");

	//無意味
	info = LoadGraph("data/info.png");

	//スタート
	startImage = LoadGraph("data/gameImage/start_.jpg");

	
	//スタート画面(1920×1080)
	title_Image = LoadGraph("data/gameImage/start_image.jpg");

	//メニュー画面
	menu_Image = LoadGraph("data/test_title.jpg");
	//ステージ選択用
	menu_stage1 = LoadGraph("data/test_stage1.jpg");
	//ステージ選択・タイトル戻りよう
	menu_Title = LoadGraph("data/menu_chengeTitle.jpg");
	//選択世y
	sentaku = LoadGraph("data/sentaku.png");

	sean = SEAN_TITLE;

	keyUpdate();

	//初期段階（種）
	hana_1_Anim = F1_TANE;

	
}


//ゲーム中の動作
void action() 
{
	switch (sean)
	{
	case SEAN_TITLE:
		if (onePushKey(KEY_INPUT_SPACE))
		{
			sean = SEAN_MENU;
		}
		break;
	case SEAN_MENU:

		//WaitTimer(1200);

		if (chengeFlg)
		{
			if (onePushKey(KEY_INPUT_SPACE))
			{
				chengeFlg = false;
			}

			if (onePushKey(KEY_INPUT_Z))
			{
				sean = SEAN_GAME;
			}
		}
		else
		{
			if (onePushKey(KEY_INPUT_SPACE))
			{
				chengeFlg = true;
			}
			if (onePushKey(KEY_INPUT_Z))
			{
				sean = SEAN_TITLE;
			}
		}
		
			break;
	case SEAN_GAME:

		aniTimer++;
		if (onePushKey(KEY_INPUT_Q))
		{
			hana_1_Anim = F1_TANE;
		}
		if (CheckHitKey(KEY_INPUT_W))
		{
			hana_1_Anim = F1_HATUGA;
		}
		if (CheckHitKey(KEY_INPUT_E))
		{
			hana_1_Anim = F1_TUBOMI;
		}
		if (CheckHitKey(KEY_INPUT_R))
		{
			hana_1_Anim = F1_KAIKA;
		}
		if (CheckHitKey(KEY_INPUT_T))
		{
			hana_1_Anim = F1_KARE;
		}

		break;
	case SEAN_CLEAR:
		break;
		

	}
}

//ゲーム中の描画
void draw()
{
	//アニメーションあん
	//まずint型で箱を作る
	//そこに作ったアニメーションを入れる()
	//voidで作ったやつを入れる



	switch (sean)
	{
	case SEAN_TITLE:
		DrawGraph(0, 0, title_Image, FALSE);
		break;
	case SEAN_MENU:
		DrawGraph(0, 0, menu_Image, FALSE);
		DrawGraph((1920 / 2) - (350 / 2), (1080 / 2) + 50, menu_stage1, FALSE);
		DrawGraph((1920 / 2) - (350 / 2), (1080 / 2) + 200, menu_Title, FALSE);
		
		if (chengeFlg)
		{
			
			DrawGraph((1920 / 2) - (350 / 2), (1080 / 2) + 50, sentaku, TRUE);
		
		}
		else
		{
			DrawGraph((1920 / 2) - (350 / 2), (1080 / 2) + 200, sentaku, TRUE);
		}
			
		

		
		break;
	case SEAN_GAME:
		anim();
		SetBackgroundColor(150,255,255);
		for (int y = 0; y < MAP_H; y++)
		{
			for (int x = 0; x < MAP_W; x++)
			{
				
				
				DrawGraph(x * 64 + (1920/2 - 64*3), y * 64 + (1080/2 - 64*3),hanaImage_1[hana_1_Anim], false);

			}
		}
	}


	
}



// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//画面サイズを設定
	SetGraphMode(1920,1080,32);
	//ウインドウのタイトル変更
	SetMainWindowText("からー");
	//ウインドウモード変更
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	//表示方式をダブルバッファ方式に切り替え
	SetDrawScreen(DX_SCREEN_BACK);
	//dxlibの初期化後にゲーム部分の初期化
	init();
	//ゲームループの実装
	while (ProcessMessage() == 0)
	{
		action();
		keyUpdate();
		
		//画面の初期化
		ClearDrawScreen();
		draw();
		//最後に画面転写
		ScreenFlip();

		//1秒間に６０回この繰り返し文を実行している。
		//ゲームを終了させるときは、必ず、このwhileを抜けるように組む
		//エスケープボタンを押すと終了する
		if ( CheckHitKey( KEY_INPUT_ESCAPE ) == 1 )
		{
			break;//ゲームループから抜ける
		}
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}