/*
 * Hero.h
 *
 *  Created on: 2015��5��4��
 *      Author: sven
 */

#ifndef HERO_H_
#define HERO_H_
#include <cocos2d.h>
#include "FlashTool.h"
USING_NS_CC;
class Hero: public Sprite{
public:
	virtual bool init();
	CREATE_FUNC(Hero);

};

#endif /* HERO_H_ */
