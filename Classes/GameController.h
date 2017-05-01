/*
 * GameController.h
 *
 *  Created on: 2015年5月5日
 *      Author: sven
 */

#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_
#include "cocos2d.h"
#include "Block.h"
#include "Edge.h"
#include "Hero.h"
USING_NS_CC;


class GameController :public Ref{
public:
	virtual bool init(Layer *layer,float positionY);
	static GameController *creat(Layer *layer,float positionY);
	void onUpdate();
	bool hitTestPoint(Vec2 point);
	void onUserTouch();
private:
	Layer *_layer;
	float _positionY;
	Size visibleSize;
	int currIndex;
	int nextIndex;
	int count;//连跳
	//
	Edge *edge;
	Hero *hero;
	void resetFrameIndex();
	void addBlock();
};

#endif /* GAMECONTROLLER_H_ */
