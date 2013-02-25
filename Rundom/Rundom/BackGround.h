#pragma once
#include <SpriteBatch.h>
#include <Texture.h>
#include <sstream>
#include <stdio.h>
#include <es_util.h>
#include <Tile.h>
#include <Layer.h>
#include <Input.h>
#include <iostream>
#include <SpriteGameObject.h>

class BackGround
{
public:
	BackGround(yam2d::vec2 _position,yam2d::Map*map);
	
	BackGround(void);
	~BackGround();
	float count;
	yam2d::SpriteGameObject* maa;
	yam2d::SpriteGameObject* maa2;
	yam2d::SpriteGameObject* sky;
	yam2d::SpriteGameObject* sky2;
	yam2d::Texture*texture;
	void update(float deltaTime);


};

