#include "StartScene.h"
#include "ResLoader.h"
#include "PatternScene.h"

bool g_SoundOpen = true;

StartScene::StartScene()
{
	auto delay = gcnew Delay(1.0f);
	auto opacityBy = gcnew OpacityBy(2.0f, 1.0f);
	auto sequence = gcnew Sequence({ delay, opacityBy });
	// ��ӱ���
	auto background = gcnew Sprite(ResLoader::getImage(L"StartScene"));
	background->setPos(Window::getWidth() / 2, Window::getHeight() / 2);
	this->addChild(background);
	//�����Ϸ����
	auto topic = gcnew Sprite(ResLoader::getImage(L"MainTopic"));
	topic->setPos(Window::getWidth() / 2, Window::getHeight() / 2 - 170);
	this->addChild(topic);
	topic->setOpacity(0.0f);
	topic->runAction(sequence->clone());
	//������ť��ʾ����
	auto start = gcnew Sprite(ResLoader::getImage(L"StartGame"));
	auto start_selected = gcnew Sprite(ResLoader::getImage(L"StartGame"));
	start->setScale(2.0f);
	start_selected->setScale(1.7f);
	start_selected->movePosY((start->getHeight() - start_selected->getHeight())/2);
	start_selected->movePosX((start->getWidth() - start_selected->getWidth())/2);
	//��ӿ�ʼ��ť
	auto start_btn = gcnew Button(start, start_selected);
	start_btn->setOpacity(0.0f);
	auto sequence_2 = gcnew Sequence({delay->clone(), sequence->clone()});
	start_btn->runAction(sequence_2->clone());
	// ���¿�ʼ��ť������ Game ����
	start_btn->setClickFunc([]
		{
			SceneManager::enter(gcnew PatternScene(), gcnew FadeTransition(0.6f));
		});
	start_btn->setPos(Window::getWidth() / 2, Window::getHeight() / 2 + 70);
	this->addChild(start_btn);


	// �����������ذ�ť
	soundBtn = gcnew Button(gcnew Sprite(g_SoundOpen ? L"res/soundon.png" : L"res/soundoff.png"));
	// �����������ذ�ťλ��
	soundBtn->setPos(Window::getWidth()-30, 50);
	// �����������ذ�ť�ص�����
	soundBtn->setClickFunc(std::bind(&StartScene::Sound, this));
	this->addChild(soundBtn);

}

void StartScene::Sound()
{
	// ��ȡ��ť״̬
	if (!g_SoundOpen)
	{
		// ������������
		MusicPlayer::resume(L"res\\background.wav");
		soundBtn->setNormal(gcnew Sprite(L"res\\soundon.png"));
		g_SoundOpen = true;
	}
	else
	{
		// ��ͣ��������
		MusicPlayer::pause(L"res\\background.wav");
		soundBtn->setNormal(gcnew Sprite(L"res\\soundoff.png"));
		g_SoundOpen = false;
	}
	// ������Ϣ���ļ�
	Data::saveBool(L"sound", g_SoundOpen);
}