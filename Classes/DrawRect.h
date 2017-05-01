/*
 * DrawRect.h
 *
 *  Created on: 2015Äê5ÔÂ5ÈÕ
 *      Author: sven
 */

#ifndef DRAWRECT_H_
#define DRAWRECT_H_
#include "cocos2d.h"

USING_NS_CC;


class DrawRect:public Node{
public:
	virtual bool init();
	virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
	CREATE_FUNC(DrawRect);
	void onDraw();
	CustomCommand _customCommand;

};

#endif /* DRAWRECT_H_ */
