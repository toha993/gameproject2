#ifndef MAINGUNDA_H_INCLUDED
#define MAINGUNDA_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class mainenemy {
public:
    Texture CharacterTexture;
    Sprite CharacterSprite;
    float scaleSize = .3;
	char loc[14];
	//bool direction=true;
	//int lyf=0;
    //string location;

    mainenemy()  {
        CharacterTexture.loadFromFile("maindead (2).png");
        CharacterSprite.setTexture(CharacterTexture);
        CharacterSprite.scale(-1*scaleSize, scaleSize);
        CharacterSprite.setPosition(2800, 500);
        CharacterSprite.setOrigin(CharacterSprite.getLocalBounds().width/2, CharacterSprite.getLocalBounds().height/2);
//        CharacterSprite.scale(-1,1);
    }
    void Idle() {
		static int x = 1;
		sprintf(loc, "mainenemy (%d).png", x);
		this->CharacterTexture.loadFromFile(loc);
		this->CharacterSprite.setTexture(CharacterTexture);
		if (x < 15) x++;
		else x = 1;
	}
	void Run() {
		static int x = 1;
		sprintf(loc, "mainwalk (%d).png", x);
		this->CharacterTexture.loadFromFile(loc);
		this->CharacterSprite.setTexture(CharacterTexture);
		this->CharacterSprite.move(-10, 0);
		//else this->CharacterSprite.move(-10, 0);
		if (x < 10) x++;
		else x = 1;
	}
	void Attack() {
	    static int x=1;
		sprintf(loc, "mainattack (%d).png", x);
		this->CharacterTexture.loadFromFile(loc);
		this->CharacterSprite.setTexture(CharacterTexture);
        if (x < 8) x++;
		else x = 1;
	}
	void dead() {
		static int x = 1;
		sprintf(loc, "maindead (%d).png", x);
		this->CharacterTexture.loadFromFile(loc);
		this->CharacterSprite.setTexture(CharacterTexture);
		if (x < 12) x++;
		else
            CharacterSprite.setPosition(122500,200);
	}
	float get()
    {
        return CharacterSprite.getPosition().x;
    }
    /*float dying()
    {
        return lyf=lyf-10;
    }*/
	void DrawCharacter(RenderWindow &app) {
            app.draw(CharacterSprite);
        }
};

#endif // MAINGUNDA_H_INCLUDED
