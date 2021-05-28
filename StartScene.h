#pragma once
#include "common.h"

//开始界面
class StartScene
	: public Scene
{
public:
	StartScene();
	void Sound();
protected:
	// 声音开关
	Button* soundBtn;
	// 继续游戏按钮
	Button* resumeBtn;

	bool g_SoundOpen = true;
};

