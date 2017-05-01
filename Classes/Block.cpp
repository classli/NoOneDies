/*
 * Block.cpp
 *
 *  Created on: 2015Äê5ÔÂ5ÈÕ
 *      Author: sven
 */

#include "Block.h"

bool Block::init(){
	Sprite::init();
	Size size=Size(rand()%20+5,rand()%50+10);
	Size visibleSize=Director::getInstance()->getVisibleSize();
	setPhysicsBody(PhysicsBody::createBox(size));

	setTextureRect(Rect(0,0,size.width,size.height));
	setContentSize(size);
	setColor(Color3B::BLACK);
	setPositionX(visibleSize.width);
	getPhysicsBody()->setDynamic(false);
	scheduleUpdate();
	getPhysicsBody()->setContactTestBitmask(1);
	return true;
}

void Block::update(float delta){
	this->setPositionX(getPositionX()-4);
	if(getPositionX()<0){
		unscheduleUpdate();
		removeFromParent();
	}
}
