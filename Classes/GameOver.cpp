/*
 * GameOver.cpp
 *
 *  Created on: 2015Äê5ÔÂ5ÈÕ
 *      Author: sven
 */

#include "GameOver.h"

Scene *GameOver::creatScene(){
	Scene* scene=Scene::create();
	auto l=GameOver::create();
	scene->addChild(l);
	return scene;
}

bool GameOver::init(){
	if(!LayerColor::initWithColor(Color4B::RED)){
		return false;
	}
	Size size=Director::getInstance()->getVisibleSize();
	auto lab=Label::create();
	addChild(lab);
	lab->setString("Game Over!");
	lab->setSystemFontSize(80);
	lab->setColor(Color3B::BLACK);
	lab->setPosition(size/2);

	auto R_lab=Label::create();
	addChild(R_lab);
	R_lab->setString("RETRY");
	R_lab->setSystemFontSize(50);
	R_lab->setColor(Color3B::BLACK);
	R_lab->setPosition(lab->getPositionX()+100,lab->getPositionY()-200);

	auto Q_lab=Label::create();
	addChild(Q_lab);
	Q_lab->setString("QUIT");
	Q_lab->setSystemFontSize(50);
	Q_lab->setColor(Color3B::BLACK);
	Q_lab->setPosition(lab->getPositionX()-100,lab->getPositionY()-200);

	auto RetryListener=EventListenerTouchOneByOne::create();
	RetryListener->onTouchBegan=[this,R_lab](Touch*t, Event*e){
		if(R_lab->getBoundingBox().containsPoint(t->getLocation())){
			Director::getInstance()->replaceScene(HelloWorld::createScene());
		}
		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(RetryListener,this);

	auto QuitListener=EventListenerTouchOneByOne::create();
	QuitListener->onTouchBegan=[this,Q_lab](Touch*t, Event*e){
		if(Q_lab->getBoundingBox().containsPoint(t->getLocation())){
			menuCloseCallback();
		}
		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(QuitListener,this);

	auto keyListener=EventListenerKeyboard::create();
	keyListener->onKeyReleased=[this](EventKeyboard::KeyCode keycode, Event*e){
		menuCloseCallback();
	};
	return true;
}

void GameOver::menuCloseCallback()
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
