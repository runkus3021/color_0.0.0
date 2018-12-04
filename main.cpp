#include "DxLib.h"
#include "math.h"
#include "stage.h" //�w�b�_�[�t�@�C����stagedata���ړ�
#include "color_0.0.0\key.h"




//�v���g�^�C�v
void init();//���[�ނ��̂��̂�������
void action();//����
void draw();//�摜

//�֐��̊O�ŕϐ���錾����
//�O���[�o���ϐ��Ƃ���
//�摜�n���h���i�摜�̃�������̏ꏊ�������Ă���


//�}�b�v�d�l
//6�~6
//64�~64�h�b�g


//��1
int hanaImage_1[5];
#define F1_TANE 0
#define F1_HATUGA 1
#define F1_TUBOMI 2
#define F1_KAIKA 3
#define F1_KARE 4
//��1�A�j���[�V����
int hana_1_Anim = 0;
//�A�j���[�V�����^�C�}�[
int aniTimer = 0;

//��1�A�j���[�V����
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




//��2
int hanaImage_2[5];
#define F2_TANE 0
#define F2_HATUGA 1
#define F2_TUBOMI 2
#define F2_KAIKA 3
#define F2_KARE 4


int info = 0;

//�^�C�g����ʃC���[�W�p
int title_Image = 0;

//���j���[��ʗp
int menu_Image = 0;
//���j���[��ʃ^�C�g���I��p
int menu_stage1 = 0;
//���j���[��ʃ^�C�g���߂�悤
int menu_Title = 0;
//�I��p
int sentaku = 0;
bool chengeFlg = false;


//�^�C�g���X�^�[�g�̂��
//�g��k����������
int startImage = 0;

int sean = 0;
#define SEAN_TITLE 0
#define SEAN_MENU 1
#define SEAN_GAME 2
#define SEAN_CLEAR 3



//�z�񏀔�
int blockImage[4];




//����������֐�
void init()
{
	//��1
	hanaImage_1[F1_TANE] = LoadGraph("data/gameimage/1_1_tane.jpg");
	hanaImage_1[F1_HATUGA] = LoadGraph("data/gameimage/1_2_hatuga.jpg");
	hanaImage_1[F1_TUBOMI] = LoadGraph("data/gameimage/1_3_tubomi.jpg");
	hanaImage_1[F1_KAIKA] = LoadGraph("data/gameimage/1_4_kaika.jpg");
	hanaImage_1[F1_KARE] = LoadGraph("data/gameimage/1_5_kare.jpg");

	//��2
	hanaImage_1[F2_TANE] = LoadGraph("data/gameimage/2_1_tane.jpg");
	hanaImage_1[F2_HATUGA] = LoadGraph("data/gameimage/2_2_hatuga.jpg");
	hanaImage_1[F2_TUBOMI] = LoadGraph("data/gameimage/2_3_tubomi.jpg");
	hanaImage_1[F2_KAIKA] = LoadGraph("data/gameimage/2_4_kaika.jpg");
	hanaImage_1[F2_KARE] = LoadGraph("data/gameimage/2_5_kare.jpg");




	//64�~64
	blockImage[COLOR1] = LoadGraph("data/hana_tuti.jpg");
	blockImage[COLOR2] = LoadGraph("data/hana.jpg");
	blockImage[COLOR3] = LoadGraph("data/color3.png");
	blockImage[COLOR4] = LoadGraph("data/color4.png");

	//���Ӗ�
	info = LoadGraph("data/info.png");

	//�X�^�[�g
	startImage = LoadGraph("data/gameImage/start_.jpg");

	
	//�X�^�[�g���(1920�~1080)
	title_Image = LoadGraph("data/gameImage/start_image.jpg");

	//���j���[���
	menu_Image = LoadGraph("data/test_title.jpg");
	//�X�e�[�W�I��p
	menu_stage1 = LoadGraph("data/test_stage1.jpg");
	//�X�e�[�W�I���E�^�C�g���߂�悤
	menu_Title = LoadGraph("data/menu_chengeTitle.jpg");
	//�I��y
	sentaku = LoadGraph("data/sentaku.png");

	sean = SEAN_TITLE;

	keyUpdate();

	//�����i�K�i��j
	hana_1_Anim = F1_TANE;

	
}


//�Q�[�����̓���
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

//�Q�[�����̕`��
void draw()
{
	//�A�j���[�V��������
	//�܂�int�^�Ŕ������
	//�����ɍ�����A�j���[�V����������()
	//void�ō�����������



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



// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//��ʃT�C�Y��ݒ�
	SetGraphMode(1920,1080,32);
	//�E�C���h�E�̃^�C�g���ύX
	SetMainWindowText("����[");
	//�E�C���h�E���[�h�ύX
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	//�\���������_�u���o�b�t�@�����ɐ؂�ւ�
	SetDrawScreen(DX_SCREEN_BACK);
	//dxlib�̏�������ɃQ�[�������̏�����
	init();
	//�Q�[�����[�v�̎���
	while (ProcessMessage() == 0)
	{
		action();
		keyUpdate();
		
		//��ʂ̏�����
		ClearDrawScreen();
		draw();
		//�Ō�ɉ�ʓ]��
		ScreenFlip();

		//1�b�ԂɂU�O�񂱂̌J��Ԃ��������s���Ă���B
		//�Q�[�����I��������Ƃ��́A�K���A����while�𔲂���悤�ɑg��
		//�G�X�P�[�v�{�^���������ƏI������
		if ( CheckHitKey( KEY_INPUT_ESCAPE ) == 1 )
		{
			break;//�Q�[�����[�v���甲����
		}
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}