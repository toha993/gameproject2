#ifndef HEART_H_INCLUDED
#define HEART_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class heart{
public:
    Texture CharacterTexture;
    Sprite CharacterSprite;
    float scaleSize = .015;
	char loc[14];
	//bool direction=true;


    heart () {
        CharacterTexture.loadFromFile("hrt (5).png");
        CharacterSprite.setTexture(CharacterTexture);
        CharacterSprite.scale(scaleSize, scaleSize);
        CharacterSprite.setPosition(1300, 480);
        CharacterSprite.setOrigin(CharacterSprite.getLocalBounds().width/2, CharacterSprite.getLocalBounds().height/2);
//        CharacterSprite.scale(-1,1);
    }
    void Idle() {
		static int x = 1;
		sprintf(loc, "hrt (%d).png", x);
		this->CharacterTexture.loadFromFile(loc);
		this->CharacterSprite.setTexture(CharacterTexture);
		if (x < 6) x++;
		else x = 1;
	}
	float get()
    {
        return CharacterSprite.getPosition().x;
    }
    void udhao()
    {
        CharacterSprite.setPosition(-300, 480);
    }
    void DrawCharacter(RenderWindow &app) {
            app.draw(CharacterSprite);
        }
};


#endif // HEART_H_INCLUDED
