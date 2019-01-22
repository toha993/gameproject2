#include "character.hpp"
#include "enemy.h"
#include "friend.h"
#include "heart.h"
#include "maingunda.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
int bx=500,baki=300,ck=1,cp=0;
View view;
int main()
{
    Texture gameover;
    gameover.loadFromFile("game_over.png");
    Sprite shesh;
    shesh.setTexture(gameover);
    shesh.setPosition(Vector2f(300,300));

    Texture tips;
    tips.loadFromFile("ins.png");
    Sprite maa;
    maa.setTexture(tips);
    maa.setPosition(Vector2f(0,300));
    maa.scale(1.75,1.75);


    RectangleShape heathbar;
    Texture hltborder;
    Sprite hltbordersp;

    hltborder.loadFromFile("healthbar.png");

    hltbordersp.setTexture(hltborder);
    hltbordersp.scale(0.3,0.25);
    hltbordersp.setPosition(Vector2f(707,-25));

    heathbar.setPosition(720,50);
    heathbar.setFillColor(Color(Color::Green));
    heathbar.setOutlineThickness(3.f);
    heathbar.setOutlineColor(Color::Black);
    double heath=(double)baki/1.5;
    heathbar.setSize(Vector2f(heath,30));
    int state = 0;
    int scene = 0;
    int sotru[10];
    int mortese=100;
    for(int i=0; i<=8; i++)
        sotru[i]=50;
    bool isdead[10];
    for(int i=0; i<=8; i++)
        isdead[i]=false;
    bool morse=false;
    bool Direction = false;
    Character NinjaGirl("Run__000.png");
    vai mukto("frndidle (1).png");
    life he;
    he.start_point=1800;
    he.init();
    mainenemy pola;
    enemy zombie[11];
    zombie[0].sp(800,500);
    zombie[1].sp(1570,500);
    zombie[2].sp(1870,500);
    zombie[3].sp(2010,500);
    zombie[4].sp(2280,500);
    zombie[5].sp(2580,500);
    zombie[6].sp(2780,500);
    zombie[7].sp(3080,500);
    zombie[8].sp(3280,500);
    //zombie[9].sp(3580,500);
    //enemy beshi();
    Music bgMusic;
    bgMusic.openFromFile("fade.ogg");
    bgMusic.setLoop(true);
    RenderWindow Window(VideoMode(1000,600), "Save The Existence");
    bgMusic.play();
    Window.setFramerateLimit(60);

    Texture textureBackground, menuBgTexture;
    textureBackground.loadFromFile("bg.png");
    menuBgTexture.loadFromFile("MenuBG.jpg");
    Sprite spriteBackground(textureBackground), menuBG(menuBgTexture);
    spriteBackground.scale(1.5,1.35);
    menuBG.scale(1.25,2.2);



    Font menuFont,mssgfont;
    menuFont.loadFromFile("gamefont.ttf");
    mssgfont.loadFromFile("DIEDIEDI.ttf");

    Text gameText("Save The Existence", menuFont, 70);
    Text startText("Start Game", menuFont, 50);
    Text txt("Welcome, to your DEATH", mssgfont, 28);
    Text insText("Instruction", menuFont, 50);
    Text exitText("Exit Game", menuFont, 50);

    gameText.setPosition(90,120);
    startText.setPosition(350,320);
    insText.setPosition(350,380);
    exitText.setPosition(350,440);

    gameText.setFillColor(Color::White);
    startText.setFillColor(Color::White);
    exitText.setFillColor(Color::White);
    int gtimer=180;

    int attackCount = 10;

    Event event;
    while(Window.isOpen())
    {

        while(Window.pollEvent(event))
        {
            switch(event.type)
            {
            case Event::Closed:
                Window.close();
                break;
            case Event::KeyPressed:
                switch(event.key.code)
                {
                case Keyboard::Enter:
                    //scene++;
                    break;
                }
            }
        }

        Window.clear();
        if(scene==0)
        {



            if(Mouse::getPosition(Window).x>=352 && Mouse::getPosition(Window).x<=696 && Mouse::getPosition(Window).y>=200 && Mouse::getPosition(Window).y<=219)
            {
                startText.setFillColor(Color::Black);
                if(Mouse::isButtonPressed(Mouse::Left))
                {
                    scene=1;
                }
            }
            else
            {
                startText.setFillColor(Color::White);
            }
            if(Mouse::getPosition(Window).x>=351 && Mouse::getPosition(Window).x<=704 && Mouse::getPosition(Window).y>=237 && Mouse::getPosition(Window).y<=258)
            {
                insText.setFillColor(Color::Black);
                if(Mouse::isButtonPressed(Mouse::Left))
                {
                    scene=10;
                }
            }
            else
            {
                insText.setFillColor(Color::White);
            }
            if(Mouse::getPosition(Window).x>=351 && Mouse::getPosition(Window).x<=652 && Mouse::getPosition(Window).y>=272 && Mouse::getPosition(Window).y<=291)
            {
                exitText.setFillColor(Color::Black);
                if(Mouse::isButtonPressed(Mouse::Left))
                {
                    Window.close();
                }
            }
            else
            {
                exitText.setFillColor(Color::White);
            }
            //cout<<Mouse::getPosition(Window).x<<' '<<Mouse::getPosition(Window).y<<endl;
            Window.draw(menuBG);
            Window.draw(gameText);
            Window.draw(startText);
            Window.draw(insText);
            Window.draw(exitText);

        }
        //view.setCenter(1000,500);
        cout<<scene<<endl;
        if(scene==1)
        {
            Window.draw(spriteBackground);
            Event event;
            while(Window.pollEvent(event))
            {
                switch(event.type)
                {
                case Event::Closed:
                    Window.close();
                }
            }
            he.movee();
            pola.Idle();
            state = 0;
            //pola.dead();
            //int pk=NinjaGirl.get() < zombie.get1();

            if(Keyboard::isKeyPressed(Keyboard::Right))
            {
                //for(int i=0;i<=4;i++)
                //{
                if(NinjaGirl.get() < zombie[0].get1() || isdead[0])
                {
                    NinjaGirl.direction = true;
                    state = 1;
                }
                //}
            }
            if(Keyboard::isKeyPressed(Keyboard::Left))
            {
                NinjaGirl.direction = false;
                state = 1;
            }
            //cout << mortese << endl;
            if(Keyboard::isKeyPressed(Keyboard::Space) && state == 0 && attackCount==10)
            {
                attackCount = 0;
                for(int i=0; i<=8; i++)
                {
                    if(zombie[i].get1() - NinjaGirl.get()<20)
                        sotru[i]=zombie[i].dying();
                }
                if(pola.get() - NinjaGirl.get()<20 && morse==false)
                {
                    mortese -=10;
                    //cout << mortese << endl;

                    //cout << mortese << endl;
                }

                //printf("\n %d \n ",sotru);
            }
            //pola.dead();
            /*else if(mortese<=0)
            {
                mortese=0;
                pola.dead();
                morse==true;
            }*/
            //if(sotru<=0)
            //zombie.dead();
            if(state == 0)
                NinjaGirl.Idle();
            if(state == 1)
                NinjaGirl.Run();
            NinjaGirl.setDirection();
            if(attackCount<10)
            {
                NinjaGirl.Attack(attackCount);
                attackCount++;

            }

            mukto.Idle();
            NinjaGirl.DrawCharacter(Window);
            for(int i=0; i<=8; i++)
            {
                zombie[i].Drawenemy(Window);
            }
            if(NinjaGirl.get() - mukto.get() >= 50)
                mukto.Run();


            for(int i=0; i<=8; i++)
            {
                if(sotru[i] >0 && zombie[i].get1() - NinjaGirl.get()<20 )
                {
                    zombie[i].Attack();
                    baki=NinjaGirl.dying();
                    if(baki <=0)
                    {
                        baki=0;
                        NinjaGirl.dead();
                        scene=9;
                        break;
                        //break;
                    }
                    //printf("\n %d \n",baki);
                }
                else if(sotru[i]<=0)
                {
                    zombie[i].dead();
                    isdead[i]=true;
                    //sotru[i]=0;
                }
                else
                    zombie[i].Run();
            }
            //he.movee();






            //pola.Idle();
            if(pola.get()-NinjaGirl.get() <= 350 && pola.get()-NinjaGirl.get() >=20 && morse==false)
            {
                pola.Run();
            }
            //pola.Run();
            if(pola.get()-NinjaGirl.get() <=20 && morse==false)
            {
                pola.Attack();
                baki=NinjaGirl.dying();
                if(baki<=0)
                {
                    baki=0;
                    NinjaGirl.dead();
                    scene=9;
                    //cout << gtimer << endl;
                }


            }

            //cout << baki << endl;
            if(NinjaGirl.get() == 1800 && cp==0)
            {
                ck=0;
                cp=1;
                NinjaGirl.reviving();
                //cout << baki << endl;
            }
            if(mortese<=0)
            {
                mortese=0;
                pola.dead();
                morse==true;
            }

            if(NinjaGirl.get()<=1800 && ck==1)
                he.draw(Window);


            //cout << mukto.get() << endl;
            //he.Idle();
            mukto.DrawCharacter(Window);
            heath=(double)baki/1.5;
            heathbar.setSize(Vector2f(heath,30));
            Window.draw(heathbar);
            Window.draw(hltbordersp);
            pola.DrawCharacter(Window);
            if(NinjaGirl.get() >=3600 && mukto.get() >=3550)
            {
                scene=9;
                //cout << gtimer << endl;
            }
            //mukto.Idle();
            //view
            if(NinjaGirl.get()> 500 && NinjaGirl.get() < 3400)
            {
                bx = NinjaGirl.get();
                heathbar.setPosition(Vector2f(bx+220,50));
                hltbordersp.setPosition(Vector2f(bx+207,-25));
            }
            view.setCenter(bx, 300);
            view.setSize(1000, 680);
            //Window.setView(view);
            //view.setview(view);
            //cout << scene << endl;
        }
        if(scene==9)
        {
            if(gtimer==0)
            {
                Window.close();
            }
            else
            {
                cout<<gtimer<<endl;
                gtimer--;
                Window.draw(shesh);
            }
        }

        if(scene==10)
        {
            Window.draw(maa);
        }
        /*if(scene==15)
        {

            Window.draw(shesh);
            //cout<<shesh.getPosition().x<<' '<<shesh.getPosition().y<<endl;
        }*/

        Window.setView(view);
        Window.display();
    }
    return 0;
}
