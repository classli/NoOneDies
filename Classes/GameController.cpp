/*
 * GameController.cpp
 *
 *  Created on: 2015年5月5日
 *      Author: sven
 */

#include "GameController.h"

bool GameController::init(Layer *layer,float positionY){
	_layer=layer;
	_positionY=positionY;
	visibleSize=Director::getInstance()->getVisibleSize();

	edge=Edge::create();
	edge->setPosition(visibleSize.width/2,visibleSize.height/2+positionY);
	//edge->setContentSize();
	layer->addChild(edge);

	hero=Hero::create();
	layer->addChild(hero);
	hero->setPosition(150,hero->getContentSize().height/2+positionY+50);

	auto ground=Sprite::create();
	layer->addChild(ground);
	ground->setColor(Color3B::BLACK);
	ground->setTextureRect(Rect(0,0,visibleSize.width,3));
	ground->setPosition(visibleSize.width/2,1.5+positionY);

	resetFrameIndex();
	srand(time(NULL));
	count=0;
	return true;
}

GameController *GameController::creat(Layer *layer,float positionY){
	auto _cr=new GameController();
	_cr->init(layer,positionY);
	_cr->autorelease();
	return _cr;
}

void GameController::onUpdate(){
	currIndex++;
	if(currIndex>=nextIndex){
		resetFrameIndex();
		addBlock();
	}
}

//间隔时间
void GameController::resetFrameIndex(){
	currIndex=0;
	nextIndex=rand()%180+120;
}

//添加节点
void GameController::addBlock(){
	auto b=Block::create();
	_layer->addChild(b);
	b->setPositionY(b->getContentSize().height/2+_positionY);
}

//触点是否在框内
bool GameController::hitTestPoint(Vec2 point){
	return edge->getBoundingBox().containsPoint(point);
}

//向上跳
void GameController::onUserTouch(){

	/*if(hero->getPositionY()>=hero->getContentSize().height/2+_positionY+30){
		count++;
	}
	if(count<2){
		hero->getPhysicsBody()->setVelocity(Vec2(0,500));
	}else if(hero->getPositionY()<=hero->getContentSize().height/2+_positionY+30){
		count=0;
	}*/

	if(hero->getPositionY()<=hero->getContentSize().height/2+_positionY+30){
		hero->getPhysicsBody()->setVelocity(Vec2(0,500));
	}
}
