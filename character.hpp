#ifndef CHARACTER_HPP_INCLUDED
#define CHARACTER_HPP_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Character {
public:
    Texture CharacterTexture;
    Sprite CharacterSprite;
    float scaleSize = .25;
	char loc[14];
	bool direction=true;
	int lyf=300;
    //string location;

    Character (string location) {
        CharacterTexture.loadFromFile(location);
        CharacterSprite.setTexture(CharacterTexture);
        CharacterSprite.scale(scaleSize, scaleSize);
        CharacterSprite.setPosition(100, 500);
        CharacterSprite.setOrigin(CharacterSprite.getLocalBounds().width/2, CharacterSprite.getLocalBounds().height/2);
//        CharacterSprite.scale(-1,1);
    }

	void Idle() {
		static int x = 0;
		sprintf(loc, "Idle__00%d.png", x);
		this->CharacterTexture.loadFromFile(loc);
		this->CharacterSprite.setTexture(CharacterTexture);
		if (x < 9) x++;
		else x = 0;
	}

	void Run() {
		static int x = 0;
		sprintf(loc, "Run__00%d.png", x);
		this->CharacterTexture.loadFromFile(loc);
		this->CharacterSprite.setTexture(CharacterTexture);
		if(direction) this->CharacterSprite.move(10, 0);
		else this->CharacterSprite.move(-10, 0);
		if (x < 9) x++;
		else x = 0;
	}

	void Attack(int x) {
		sprintf(loc, "Attack__00%d.png", x);
		this->CharacterTexture.loadFromFile(loc);
		this->CharacterSprite.setTexture(CharacterTexture);
		 if(x==9)
            direction=true;

		 //CharacterSprite.setScale(-1, 1);
	}

	void setDirection() {
        if(this->direction && this->CharacterSprite.getScale().x == -.25)
            this->CharacterSprite.setScale(.25, .25);
        if(!this->direction && this->CharacterSprite.getScale().x == .25)
            this->CharacterSprite.setScale(-.25, .25);
	}
	void dead() {
		static int x = 0;
		sprintf(loc, "Dead__00%d.png", x);
		this->CharacterTexture.loadFromFile(loc);
		this->CharacterSprite.setTexture(CharacterTexture);
		if (x < 9) x++;
		else CharacterSprite.setPosition(-500,200);
	}

    float get()
    {
        return CharacterSprite.getPosition().x;
    }
    int dying()
    {
        return lyf=lyf-1;
    }
    float reviving()
    {
        return lyf=min(300,lyf+150);
    }


    void DrawCharacter(RenderWindow &app) {
        app.draw(CharacterSprite);
    }
};

#endif // CHARACTER_HPP_INCLUDED
