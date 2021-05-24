#pragma once
#include "common.h"
#include <map>

// ��Ƶ����
enum class MusicType
{
	//��������
	Click

};

//��Դ������
class ResLoader
{
public:
	//Ԥ����ͼƬ
	static void init();

	//��ȡͼƬ
	static Image* getImage(String imagename);

	//������Ƶ
	static void playMusic(MusicType musicType);

private:
	//ͼƬӳ��
	static std::map<String, Image*> imageMap;
	//��Ƶӳ��
	static std::map<MusicType, Music*> musicMap;
};

