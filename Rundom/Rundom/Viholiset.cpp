//#include "Viholiset.h"
//
//using namespace yam2d;
//
//
//Viholiset::Viholiset(void)
//{
//}
//
//
//Viholiset::~Viholiset(void)
//{
//}
//
//Viholiset::Viholiset(vec2 _position)
//{
//	texture = new Texture("kaarmes92x42kaannettu.png");
//	spriteSheet = SpriteSheet::generateSpriteSheet(texture,92,42,0,0);
//	vihu = new AnimatedSpriteGameObject(0, spriteSheet);
//	vihu->setSize(92,42);
//	vihu->setName("vihu");
//	count = 0;
//
//	int numClipsPerAnimation = 11;
//
//	float animationFrameRate = 10.0f;
//	for( int i=0; i<1; ++i )
//	{
//		std::vector<int> indices;
//		indices.resize(numClipsPerAnimation);
//		for( size_t j=0; j<indices.size(); ++j )
//		{
//			indices[j] = numClipsPerAnimation*i + j;
//		}
//
//		// Add looping animation.
//		vihu->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
//	}
//	// Set animation at index 0 to active
//	vihu->setActiveAnimation(0);
//
//}
//
//void Viholiset::update(float deltaTime)
//{
//
//}