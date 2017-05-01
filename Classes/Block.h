/*
 * Block.h
 *
 *  Created on: 2015Äê5ÔÂ5ÈÕ
 *      Author: sven
 */

#ifndef BLOCK_H_
#define BLOCK_H_
#include "cocos2d.h"
USING_NS_CC;

class Block :public Sprite{
public:
	virtual bool init();
	CREATE_FUNC(Block);
	virtual void update(float delta);
};

#endif /* BLOCK_H_ */
