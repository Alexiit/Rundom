#include "Kivi.h"

using namespace yam2d;


Kivi::Kivi(void)
{

}

Kivi::~Kivi(void)
{
}

Kivi::Kivi(vec2 _position)
{
	texture = new Texture("kivi.png");
	texture->setTransparentColor(0xff,0x00,0xff);
	kivi = new SpriteGameObject(0, texture);
	kivi->setSize(400,400);
	kivi->setName("kivi");
	count = 0;


}

void Kivi::update(float deltaTime)
{
	count++;
	kivi->setRotation(count/50);
	
}
