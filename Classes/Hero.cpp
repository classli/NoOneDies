/*
 * Hero.cpp
 *
 *  Created on: 2015Äê5ÔÂ4ÈÕ
 *      Author: sven
 */

#include "Hero.h"

bool Hero::init(){
	Sprite::init();
	runAction(RepeatForever::create(FlashTool::readJsonSpriteSheet("Hero.json",0.2f)));
	setScale(1.5f);
	Size s=Size(44,52*1.5f);
	setPhysicsBody(PhysicsBody::createBox(s));
	getPhysicsBody()->setRotationEnable(false);
	getPhysicsBody()->setContactTestBitmask(1);
	getPhysicsBody()->getShape(0)->setRestitution(0);
	return true;
}
