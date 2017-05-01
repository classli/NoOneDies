/*
 * GameOver.h
 *
 *  Created on: 2015Äê5ÔÂ5ÈÕ
 *      Author: sven
 */

#ifndef GAMEOVER_H_
#define GAMEOVER_H_
#include "cocos2d.h"
#include "DrawRect.h"
#include "HelloWorldScene.h"
USING_NS_CC;

class GameOver :public LayerColor{
public:
	virtual bool init();
	CREATE_FUNC(GameOver);
	static Scene*  creatScene();
	void menuCloseCallback();
};

#endif /* GAMEOVER_H_ */
