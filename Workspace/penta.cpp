

#include "PENTA.h"
#define IDI_CON1 101
#define IDI_CON2 102
	// �v���O������ WinMain ����n�܂�܂�
	int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetWindowText("PENTA");
	SetBackgroundColor(0, 0, 0);
	SetWindowIconID(IDI_CON2);
	
	SetWindowSize(640, 480);
	if (DxLib_Init() == -1)		 // �c�w���C�u��������������
	{
		return -1;			     // �G���[���N�����璼���ɏI��
	}
	PENTA  pen;
	pen.Title();                 // �{��
	SetAlwaysRunFlag(true);
	//pen.CreateStageHintData(); //�q���g�f�[�^�쐬
	//pen.CreateClearDataOfNotTurn(); //��]���삪�֎~���ꂽ�Ֆʃf�[�^�̍쐬
	DxLib_End();				 // �c�w���C�u�����g�p�̏I������
	
	return 0;				     // �\�t�g�̏I�� 
}
