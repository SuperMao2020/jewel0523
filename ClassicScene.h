#pragma once
#include "common.h"

//��ʼ����
class ClassicScene
	: public Scene
{
public:
	ClassicScene();
	void Sound();
protected:
	// ��������
	Button* soundBtn;
	// ������Ϸ��ť
	Button* resumeBtn;

	bool g_SoundOpen = true;
};

