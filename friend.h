#ifndef FRIEND_H_INCLUDED
#define FRIEND_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class vai{
public:
    Texture CharacterTexture;
    Sprite CharacterSprite;
    float scaleSize = .25;
	char loc[14];
	bool direction=true;


	vai (string location) {
        CharacterTexture.loadFromFile(location);
        CharacterSprite.setTexture(CharacterTexture);
        CharacterSprite.scale(scaleSize, scaleSize);
        CharacterSprite.setPosition(3000, 500);
        CharacterSprite.setOrigin(CharacterSprite.getLocalBounds().width/2, CharacterSprite.getLocalBounds().height/2);
//        CharacterSprite.scale(-1,1);
    }
    void Idle() {
		static int x = 1;
		sprintf(loc, "frndidle (%d).png", x);
		this->CharacterTexture.loadFromFile(loc);
		this->CharacterSprite.setTexture(CharacterTexture);
		if (x < 10) x++;
		else x = 1;
	}
	void Run() {
		static int x = 1;
		sprintf(loc, "frndr (%d).png", x);
		this->CharacterTexture.loadFromFile(loc);
		this->CharacterSprite.setTexture(CharacterTexture);
		 this->CharacterSprite.move(10, 0);
		//else this->CharacterSprite.move(-10, 0);
		if (x < 8) x++;
		else x = 1;
	}
	float get()
    {
        return CharacterSprite.getPosition().x;
    }
	 void DrawCharacter(RenderWindow &app) {
        app.draw(CharacterSprite);
    }
};

#endif // FRIEND_H_INCLUDED
