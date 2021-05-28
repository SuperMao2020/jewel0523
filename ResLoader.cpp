#pragma once
#include "ResLoader.h"
#include "resource.h"

std::map<String, Image*> ResLoader::imageMap;
std::map<MusicType, Music*> ResLoader::musicMap;

void ResLoader::init()
{
	// Ԥ����ͼƬ
	//1.��ʼ����ͼƬ
	Image::preload(L"res\\StartScene.png");
	Image* startScene = new Image(L"res\\StartScene.png");
	//2.��Ϸ����
	Image::preload(L"res\\MainTopic.png");
	Image* mainTopic = new Image(L"res\\MainTopic.png");
	//3.��ʼ��ť����״̬
	Image::preload(L"res\\StartGame.png");
	Image* startGame = new Image(L"res\\StartGame.png");
	//4. ģʽѡ�����ͼƬ
	Image::preload(L"res\\PatternScene.png");
	Image* patternScene = new Image(L"res\\PatternScene.png");
	////5.ֹͣ�������ְ�ť����״̬
	//Image::preload(L"res\\soundoff.png");
	//Image* stopMusic = new Image(L"res\\soundoff.png");
	//6.���ر�������
	// ѭ�����ű������֣�-1 ��ʾѭ������
	MusicPlayer::preload(L"res\\background.wav");
	MusicPlayer::play(L"res\\background.wav", -1);
	//7.������һ�����水ť
	Image::preload(L"res\\ReturnScene.png");
	Image* returnScene = new Image(L"res\\ReturnScene.png");
	//8. ����ģʽ����
	Image::preload(L"res\\BG03.png");
	Image* classicScene = new Image(L"res\\BG03.png");

	// ���浽ӳ��
	imageMap.insert(std::make_pair(L"StartScene", startScene));
	imageMap.insert(std::make_pair(L"MainTopic", mainTopic));
	imageMap.insert(std::make_pair(L"StartGame", startGame));
	imageMap.insert(std::make_pair(L"Pattern", patternScene));
	/*imageMap.insert(std::make_pair(L"StopMusic", stopMusic));*/
	imageMap.insert(std::make_pair(L"ReturnScene", returnScene));
	imageMap.insert(std::make_pair(L"ClassicScene", classicScene));

}

Image* ResLoader::getImage(String imageName)
{
	auto iter = imageMap.find(imageName);
	if (iter == imageMap.end())
	{
		return nullptr;
	}
	return iter->second;
}

void ResLoader::playMusic(MusicType musicType)
{
	Music* music = musicMap[musicType];
	if (music)
	{
		music->play();
	}
}
