/*
 * DrawRect.cpp
 *
 *  Created on: 2015Äê5ÔÂ5ÈÕ
 *      Author: sven
 */

#include "DrawRect.h"

bool DrawRect::init(){
	Node::init();
	return true;
}

void DrawRect::draw(Renderer *renderer, const Mat4& transform, uint32_t flags){
	 _customCommand.init(_globalZOrder);
	 _customCommand.func =CC_CALLBACK_0(DrawRect::onDraw,this);
	 renderer->addCommand(&_customCommand);
}

void DrawRect::onDraw(){
	DrawPrimitives::drawRect(Vec2(200,200),Vec2(400,400));
}