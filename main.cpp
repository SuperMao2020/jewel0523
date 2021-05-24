#include "resource.h"
#include "ResLoader.h"
#include "StartScene.h"

int main()
{
	if (Game::init(L"HappyPop", 1024, 640))
	{
		//���ô���ͼ��
		Window::setIcon(IDI_ICON1);
		//����ͼƬ��������Դ
		ResLoader::init();
		// �޸Ľڵ�Ĭ�����ĵ㣬������ͼƬ������ʾ
		Node::setDefaultAnchor(0.5f, 0.5f);
		//���� StartScene
		auto scene = gcnew StartScene();
		// �������뵭��ʽ�л�����
		auto transition = gcnew FadeTransition(1);
		// ���� StartScene�����Ĳ��� false ��ʾ���ٷ��ص�ǰ����
		SceneManager::enter(scene, transition, false);
		Game::start();
	}
	Game::destroy();
	return 0;
}