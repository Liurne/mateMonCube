#include "controls.h"

KeyAction::KeyAction(SDL_Keycode k) : key(k) , isMouseOrKey(false) , isPressed(false)
{

}
KeyAction::KeyAction(Uint8 k, bool isMouse) : key(k) , isMouseOrKey(isMouse) , isPressed(false)
{
//
}
Controls::Controls() : mouse(0,0) , keyDown(false)
{

}
void Controls::event(bool &run)
{
    while(SDL_PollEvent(&ev))
    {
        switch(ev.type)
        {
            case SDL_QUIT:
                run=false;
                break;

            case SDL_KEYDOWN:
                keyDown=true;
                break;
            case SDL_KEYUP:
                keyDown=false;
                break;
            case SDL_MOUSEMOTION:
                mouse.x=ev.motion.x;
                mouse.y=ev.motion.y;
                break;
            case SDL_MOUSEBUTTONDOWN:
                keyDown=true;
                break;
            case SDL_MOUSEBUTTONUP:
                keyDown=false;
                break;
        }
    }
}
void Controls::event(bool &run,vector<KeyAction> &aKeyboard)
{
    while(SDL_PollEvent(&ev))
    {
        switch(ev.type)
        {
            case SDL_QUIT:
                run=false;
                break;

            case SDL_KEYDOWN:
                keyDown=true;
                for(int i=0;i<(int)aKeyboard.size();i++)
                    if(ev.key.keysym.sym == aKeyboard[i].key && !aKeyboard[i].isMouseOrKey)
                        aKeyboard[i].isPressed=true;
                break;
            case SDL_KEYUP:
                keyDown=false;
                for(int i=0;i<(int)aKeyboard.size();i++)
                    if(ev.key.keysym.sym == aKeyboard[i].key && !aKeyboard[i].isMouseOrKey)
                        aKeyboard[i].isPressed=false;
                break;
            case SDL_MOUSEMOTION:
                mouse.x=ev.motion.x;
                mouse.y=ev.motion.y;
                break;
            case SDL_MOUSEBUTTONDOWN:
                for(int i=0;i<(int)aKeyboard.size();i++)
                    if(ev.button.button == aKeyboard[i].key && aKeyboard[i].isMouseOrKey)
                        aKeyboard[i].isPressed=true;
                break;
            case SDL_MOUSEBUTTONUP:
                for(int i=0;i<(int)aKeyboard.size();i++)
                    if(ev.button.button == aKeyboard[i].key && aKeyboard[i].isMouseOrKey)
                        aKeyboard[i].isPressed=false;
                break;
        }
    }
}

Point Controls::getMousePos()
{
    return mouse;
}

bool Controls::isKeyPressed()
{
    return keyDown;
}
