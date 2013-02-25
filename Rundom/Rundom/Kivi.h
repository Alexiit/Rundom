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

class Kivi
{
public:
	Kivi(yam2d::vec2 _position);
	Kivi(void);
	~Kivi();
	float count;
	yam2d::SpriteGameObject* kivi;
	yam2d::Texture* texture;
	yam2d::vec2 position;
	void update(float deltaTime);

};

