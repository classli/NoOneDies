#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0,-1000));
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }

    gcs.insert(0,GameController::creat(this,30));
	
	//物理碰撞监听
	auto listener=EventListenerPhysicsContact::create();
	listener->onContactBegin=[this](PhysicsContact &contact){
		this->unscheduleUpdate();
		this->unschedule(schedule_selector(HelloWorld::addGameControaller));
		Director::getInstance()->replaceScene(GameOver::creatScene());
		return true;
	};
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener,this);

	//触摸监听
	auto touchListener=EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan=[this](Touch* t, Event* e){
		for(auto it:gcs){
			if((*it).hitTestPoint(t->getLocation())){
				(*it).onUserTouch();
				break;
			}
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener,this);
	
	//后退键监听
	auto OutListener=EventListenerKeyboard::create();
	OutListener->onKeyReleased=[this](EventKeyboard::KeyCode, Event*){
		menuCloseCallback();
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(OutListener,this);

	//启动帧定时器
	scheduleUpdate();
	//没30s添加一个主角
	schedule(schedule_selector(HelloWorld::addGameControaller),30.0f);
    //主角数量控制
	countGm=0;

	return true;
}


void HelloWorld::menuCloseCallback()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void HelloWorld::update(float delta){
	for(auto it:gcs){
		(*it).onUpdate();
	}
}


void HelloWorld::addGameControaller(float delta){
	if(countGm<5){
		countGm++;
		gcs.insert(0,GameController::creat(this,30+countGm*250));
	}
}
