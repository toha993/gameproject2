#ifndef HEART_H_INCLUDED
#define HEART_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;


class life
{
   Texture heart;
   int curr=0,j=0,n=+5;
   public:
   Sprite hea[10];
   int start_point=7;
   bool f=0;
   void init()
   {
       heart.loadFromFile("heart.png");
       heart.setSmooth(true);
       int i=0;
       hea[i].setPosition(start_point,530);
       hea[i].setTexture(heart);
       hea[i].setTextureRect(IntRect(0,0,252,217.5));
       hea[0].setOrigin(127.5,108);
       hea[i].scale(0.2,0.2);
       i++;
       hea[i].setPosition(start_point,530);
       hea[i].setTexture(heart);
       hea[i].setTextureRect(IntRect(276,0,492-276,217.5));
       hea[1].setOrigin(396-276,108);
       hea[i].scale(0.2,0.2);
       i++;
       hea[i].setPosition(start_point,530);
       hea[i].setTexture(heart);
       hea[i].setTextureRect(IntRect(516,0,694.5-516,217.5));
       hea[2].setOrigin(628.5-516,108);
       hea[i].scale(0.2,0.2);
       i++;
       hea[i].setPosition(start_point,530);
       hea[i].setTexture(heart);
       hea[i].setTextureRect(IntRect(696.5,0,836.5-696.5,217.5));
       hea[3].setOrigin(790.5-696.5,108);
       hea[i].scale(0.2,0.2);
       i++;
       hea[i].setPosition(start_point,530);
       hea[i].setTexture(heart);
       hea[i].setTextureRect(IntRect(862,0,938-862,217.5));
       hea[4].setOrigin(902-862,108);
       hea[i].scale(0.2,0.2);
       i++;
       hea[i].setPosition(start_point,530);
       hea[i].setTexture(heart);
       hea[i].setTextureRect(IntRect(82.5,217.5,168-82.5,239.5));
       hea[5].setOrigin(124.5-82.5,101);
       hea[i].scale(0.2,0.2);
       i++;
       hea[i].setPosition(start_point,530);
       hea[i].setTexture(heart);
       hea[i].setTextureRect(IntRect(192,217.5,334.4-192,239.5));
       hea[6].setOrigin(238.5-192,101);
       hea[i].scale(0.2,0.2);
       i++;
       hea[i].setPosition(start_point,530);
       hea[i].setTexture(heart);
       hea[i].setTextureRect(IntRect(333,217.5,516-333,239.5));
       hea[7].setOrigin(396-333,101);
       hea[i].scale(0.2,0.2);
       i++;
       hea[i].setPosition(start_point,530);
       hea[i].setTexture(heart);
       hea[i].setTextureRect(IntRect(516,217.5,763.5-516,239.5));
       hea[8].setOrigin(630-516,101);
       hea[i].scale(0.2,0.2);
       i++;
       hea[i].setPosition(start_point,530);
       hea[i].setTexture(heart);
       hea[i].setTextureRect(IntRect(763.5,217.5,1014-763.5,239.5));
       hea[9].setOrigin(897-763.5,101);
       hea[i].scale(0.2,0.2);
   }
   void movee()
   {
       j++;
       if(j==n-1)curr++;
       j%=n;
       curr%=10;
       // cout<<flag<<' '<<pa.getPosition().y<<' '<<curr_v<<endl;

   }

   void draw(RenderWindow &app)
   {
       app.draw(hea[curr]);
   }
};




#endif // HEART_H_INCLUDED
