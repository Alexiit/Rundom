#include "HahmoJuttu.h"

using namespace yam2d;

float hyppyvoima = 0;


HahmoJuttu::HahmoJuttu(void)
{
}


HahmoJuttu::~HahmoJuttu(void)
{
}

HahmoJuttu::HahmoJuttu(vec2 _position)
{
	texture = new Texture("glasses.png");
	texture->setTransparentColor(0xff,0x00,0xff);
	spriteSheet = SpriteSheet::generateSpriteSheet(texture,28,43,0,0);
	hahmo = new AnimatedSpriteGameObject(0, spriteSheet);
	hahmo->setSize(28,43);
	hahmo->setName("hahmo");
	count = 0;
	jumped = false;
	


	int numClipsPerAnimation = 6;

	float animationFrameRate = 10.0f;
	for( int i=0; i<1; ++i )
	{
		std::vector<int> indices;
		indices.resize(numClipsPerAnimation);
		for( size_t j=0; j<indices.size(); ++j )
		{
			indices[j] = numClipsPerAnimation*i + j;
		}

		// Add looping animation.
		hahmo->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
	}
	// Set animation at index 0 to active
	hahmo->setActiveAnimation(0);

}


void HahmoJuttu::update(float deltaTime)
{


	hyppyvoima -= 0.05f;
	count++;
	//Jump with space
	
	if (hahmo->getPosition().y >= 7)
		{
			hyppyvoima = 0;
			hahmo->setRotation(0);
			hahmo->setPosition(vec2(hahmo->getPosition().x,7));
		}
	
	if(getKeyState(KeyCodes::KEY_UP))
	{
		if (hahmo->getPosition().y >= 7)
		{
			hyppyvoima = 0.9f;
		}
	}
	
		if (hyppyvoima > 0)
		{
			hahmo->setRotation(count/2.5f);
			hahmo->setPosition(hahmo->getPosition() - vec2(0.0f,hyppyvoima/2));
		}
			
		if (hyppyvoima < 0 )
		{
			hahmo->setRotation(count/2.5f);
			hahmo->setPosition(hahmo->getPosition() - vec2(0.0f,hyppyvoima/4));
		}
	if(getKeyState(KeyCodes::KEY_LEFT))
	{
		hahmo->setPosition(hahmo->getPosition()-vec2(0.1f,0.0f));

	}
	if(getKeyState(KeyCodes::KEY_RIGHT))
	{
		hahmo->setPosition(hahmo->getPosition()+vec2(0.1f,0.0f));
	}
		
}
		
