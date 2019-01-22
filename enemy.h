#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
class enemy {
public:
    Texture CharacterTexture;
    Sprite CharacterSprite;
    float scaleSize = .25;
	char loc[14];
	bool direction=true;
	int lyf=30;
    //string location;

    enemy()  {
        CharacterTexture.loadFromFile("Dead (7).png");
        CharacterSprite.setTexture(CharacterTexture);
        CharacterSprite.scale(-1*scaleSize, scaleSize);
        CharacterSprite.setPosition(800, 500);
        CharacterSprite.setOrigin(CharacterSprite.getLocalBounds().width/2, CharacterSprite.getLocalBounds().height/2);
//        CharacterSprite.scale(-1,1);
    }

    	void Run() {
		static int x = 1;
		sprintf(loc, "Walk (%d).png", x);
		this->CharacterTexture.loadFromFile(loc);
		this->CharacterSprite.setTexture(CharacterTexture);
		//this->CharacterSprite.scale(1,1);
        this->CharacterSprite.move(-3, 0);
		if (x < 10) x++;
		else x = 1;
	}
	void sp(float x, float y){
        CharacterSprite.setPosition(x, y);
	}
	void Attack() {
	    static int x=1;
		sprintf(loc, "Attack (%d).png", x);
		this->CharacterTexture.loadFromFile(loc);
		this->CharacterSprite.setTexture(CharacterTexture);
        if (x < 8) x++;
		else x = 1;
	}
        float get1()
        {
            return CharacterSprite.getPosition().x;
        }
    void dead() {
		static int x = 1;
		sprintf(loc, "Dead (%d).png", x);
		this->CharacterTexture.loadFromFile(loc);
		this->CharacterSprite.setTexture(CharacterTexture);
		if (x < 12) x++;
		else
            CharacterSprite.setPosition(-500,200);
	}
	float dying()
    {
        return lyf=lyf-10;
    }
	void Drawenemy(RenderWindow &app) {
        app.draw(CharacterSprite);
    }
};
#endif // ENEMY_H_INCLUDED
