#include <SpriteBatch.h>
#include <SpriteSheet.h>
#include <Text.h>
#include <Texture.h>
#include <sstream>
#include <string>
#include <stdio.h>
#include <es_util.h>
#include <Map.h>
#include <Camera.h>
#include <Tile.h>
#include <Layer.h>
#include <Input.h>
#include <iostream>
#include "Kivi.h"
#include<AnimatedSpriteGameObject.h>
#include<TextGameObject.h>
#include"HahmoJuttu.h"
#include"BackGround.h"
//#include"Viholiset.h"

using namespace yam2d;


float count;
namespace
{
	TmxMap* map = 0;
	Texture* texture;
	SpriteSheet* spriteSheet;
	Kivi* kivi;
	HahmoJuttu* hahmo;
	//Viholiset*vihu;
	BackGround* maa = 0;
	BackGround* sky = 0;
	
		

TextGameObject* createTextGameObject(const std::string& t)
	{
		// Load font texture. Made with font creation tool like bitmap font builder.
		Texture* fontTexture = new Texture("Fixedsys_24_Bold.png");

		// Create font clip areas (sprite sheet), from dat file and texture. Dat-file is made with bitmap font builder.
		SpriteSheet* font = SpriteSheet::autoFindFontFromTexture(fontTexture,"Fixedsys_24_Bold.dat");

		
		Text* text = new Text(font);
		TextGameObject* textGameObject = new TextGameObject(0,text);
		textGameObject->getText()->setText(t);
		textGameObject->getText()->setColor(60,0,190);
		
		return textGameObject;
	}
}

bool init ( ESContext *esContext )
{	
	// Create new TmxMap object
	map = new TmxMap();
	
	
	// Load map file
	if( !map->loadMapFile("tyhjyys.tmx"))
		return false;
	

	// Move gameobject to middle of map.
	vec2 cameraPos = vec2(map->getWidth()/2.0f - 0.5f, map->getHeight()/2.0f - 0.5f);
	map->getCamera()->setPosition(vec2(0,0));
	
	maa = new BackGround(vec2(0,0),map);
	sky = new BackGround(vec2(0,0),map);


	hahmo = new HahmoJuttu( vec2( 50,20) );
	map->getLayer("GameObjects")->addGameObject(hahmo->hahmo);

	kivi = new Kivi( vec2(40,15.3) );
	map->getLayer("GameObjects")->addGameObject(kivi->kivi);

	/*vihu = new Viholiset( vec2( 55,20) );
	map->getLayer("GameObjects")->addGameObject(vihu->vihu);*/

	hahmo->hahmo->setPosition(vec2(map->getCamera()->getPosition().x, 7));
	kivi->kivi->setPosition(vec2(map->getCamera()->getPosition().x-10, 1.5));
	//vihu->vihu->setPosition(vec2(map->getCamera()->getPosition().x, 8));
	return true;
}

void deinit ( ESContext *esContext )
{
	delete map;
}


// Update game
void update( ESContext* ctx, float deltaTime )
{
	//sulkee ohjelman esciä painamalla
	if(getKeyState(KEY_ESCAPE))
	{
		exit(0);
	}
	
	sky->update(deltaTime);
	maa->update(deltaTime);

	kivi->update(deltaTime);
	//vihu->update(deltaTime);
	hahmo->update(deltaTime);
	map->update(deltaTime);
	
}

void draw ( ESContext *esContext )
{
	// Set OpenGL clear color (dark gray)
	glClearColor( 0.1f, 0.1f, 0.1f, 0.0f );

	// Clear the color buffer
	glClear ( GL_COLOR_BUFFER_BIT );


	map->getCamera()->setScreenSize(esContext->width,esContext->height); 

	// Render map and all of its layers containing GameObjects to screen.
	map->render();

}


int main ( int argc, char *argv[] )
{
	ESContext esContext;
	esInitContext ( &esContext );
	esCreateWindow( &esContext, "Indy", 1280, 720, ES_WINDOW_DEFAULT );

	if ( !init ( &esContext ) )
		return 0;

	esRegisterDrawFunc( &esContext, draw );
	esRegisterUpdateFunc( &esContext, update );
	esRegisterDeinitFunc( &esContext, deinit);

	esMainLoop ( &esContext );
	return 0;
}
