#pragma once
#include "common.h"

//��ʼ����
class StartScene
	: public Scene
{
public:
	StartScene();
	void Sound();
protected:
	// ��������
	Button* soundBtn;
	// ������Ϸ��ť
	Button* resumeBtn;

	bool g_SoundOpen = true;
};

