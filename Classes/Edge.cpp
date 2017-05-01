/*
 * Edge.cpp
 *
 *  Created on: 2015��5��4��
 *      Author: sven
 */

#include "Edge.h"

bool Edge::init(){
	if(!Node::init()){
		return false;
	}
	Size visibleSize=Director::getInstance()->getVisibleSize();
	setPhysicsBody(PhysicsBody::createEdgeBox(visibleSize));

	setContentSize(visibleSize);

	return true;
}


