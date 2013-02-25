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
#include <AnimatedSpriteGameObject.h>
#include <SpriteSheet.h>

class HahmoJuttu
{
public:
	HahmoJuttu(yam2d::vec2 _position);
	HahmoJuttu(void);
	~HahmoJuttu(void);

	yam2d::SpriteSheet* spriteSheet;
	float count;
	yam2d::AnimatedSpriteGameObject* hahmo;
	yam2d::Texture* texture;
	yam2d::vec2 position;
	void update(float deltaTime);
	bool jumped;
	bool nappain;

};

