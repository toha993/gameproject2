#include "character.hpp"
#include <SFML/Audio.hpp>
using namespace sf;
int main()
{
    int state = 0;
    bool menu=true;
    bool Direction;
    Character NinjaGirl("Run__000.png");
    Music bgMusic;
    bgMusic.openFromFile("fade.ogg");
    bgMusic.setLoop(true);
    RenderWindow Window(VideoMode(1000,600), "Save The Existence");
    bgMusic.play();
	Window.setFramerateLimit(15);

	Texture textureBackground, menuBgTexture;
	textureBackground.loadFromFile("bg.png");
	menuBgTexture.loadFromFile("menuBG.png");
	Sprite spriteBackground(textureBackground), menuBG(menuBgTexture);
	spriteBackground.scale(1.7,1.7);
	menuBG.scale(1.25,1.3);


    while(Window.isOpen()) {
        Window.clear();
        if(menu) {
            Event event;
            while(Window.pollEvent(event)) {
                switch(event.type){
                    case Event::Closed:
                        Window.close();
                        break;
                    case Event::KeyPressed:
                        switch(event.key.code){
                            case Keyboard::Enter:
                                menu=false;
                                break;
                        }
                }
            }
            Window.draw(menuBG);

        }
        else {
            Window.draw(spriteBackground);
            Event event;
            while(Window.pollEvent(event)) {
                switch(event.type){
                    case Event::Closed:
                        Window.close();
                    case Event::KeyPressed:
                        switch(event.key.code){
                            case Keyboard::Right:
                                NinjaGirl.direction = true;
                                state = 1;
                                break;
                            case Keyboard::Left:
                                NinjaGirl.direction = false;
                                state =1;
                                break;
                        }
                        break;
                    case Event::KeyReleased:
                        state = 0;
                        break;
                }
            }
            if(state == 0) NinjaGirl.Idle();
            if(state == 1) NinjaGirl.Run();
            NinjaGirl.setDirection();
            NinjaGirl.DrawCharacter(Window);
        }
            Window.display();
    }
    return 0;
}
