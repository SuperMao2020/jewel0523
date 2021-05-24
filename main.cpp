#include "resource.h"
#include "ResLoader.h"
#include "StartScene.h"

int main()
{
	if (Game::init(L"HappyPop", 1024, 640))
	{
		//设置窗口图标
		Window::setIcon(IDI_ICON1);
		//加载图片和音乐资源
		ResLoader::init();
		// 修改节点默认中心点，便于让图片居中显示
		Node::setDefaultAnchor(0.5f, 0.5f);
		//创建 StartScene
		auto scene = gcnew StartScene();
		// 创建淡入淡出式切换动画
		auto transition = gcnew FadeTransition(1);
		// 进入 StartScene，最后的参数 false 表示不再返回当前场景
		SceneManager::enter(scene, transition, false);
		Game::start();
	}
	Game::destroy();
	return 0;
}