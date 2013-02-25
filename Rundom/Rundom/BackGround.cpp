#include "BackGround.h"

using namespace yam2d;

BackGround::BackGround(void)
{
}


BackGround::~BackGround(void)
{
}

BackGround::BackGround(vec2 _position,yam2d::Map*map)
{
	texture = new Texture("maa.png");
	texture->setTransparentColor(0xff,0x00,0xff);
	maa = new SpriteGameObject(0, texture);
	maa->setSize(1280,736);
	maa->setName("maa");
	count = 0;

	maa2 = new SpriteGameObject(0, new Texture("maa.png"));
	maa2->setSize(1280,736);
	maa2->setName("maa2");
	maa2->setPosition(maa2->getPosition()+vec2(40,0));

	map->getLayer("ground")->addGameObject(maa);
	map->getLayer("ground")->addGameObject(maa2);

	texture = new Texture("sky.png");
	texture->setTransparentColor(0xff,0x00,0xff);
	sky = new SpriteGameObject(0, texture);
	sky->setSize(1280,736);
	sky->setName("sky");

	sky2 = new SpriteGameObject(0, new Texture("sky.png"));
	sky2->setSize(1280,736);
	sky2->setName("sky2");
	sky2->setPosition(sky2->getPosition()+vec2(40,0));

	map->getLayer("backgrounds")->addGameObject(sky);
	map->getLayer("backgrounds")->addGameObject(sky2);
	
}
void BackGround::update(float deltaTime)
{
	//maa1 positio ja looppaus
	maa->setPosition(maa->getPosition()+vec2(-deltaTime*10,0));
	if(maa->getPosition().x<-40)
	{
		maa->setPosition(maa->getPosition()+vec2(80,0));
	}

	//maa2:n positio ja looppaus
	maa2->setPosition(maa2->getPosition()+vec2(-deltaTime*10,0));
	if(maa2->getPosition().x<-40)
	{
		maa2->setPosition(maa2->getPosition()+vec2(80,0));
	}
	
	//sky1 positio ja looppaus
	sky->setPosition(sky->getPosition()+vec2(-deltaTime*5,0));
	if(sky->getPosition().x<-40)
	{
		sky->setPosition(sky->getPosition()+vec2(80,0));
	}

	//sky2:n positio ja looppaus
	sky2->setPosition(sky2->getPosition()+vec2(-deltaTime*5,0));
	if(sky2->getPosition().x<-40)
	{
		sky2->setPosition(sky2->getPosition()+vec2(80,0));
	}
}