#ifndef CONTROLS_H
#define CONTROLS_H

#include "include.h"
#include "shape.h"

class KeyAction 
{
    public:
        KeyAction(SDL_Keycode k);
        KeyAction(Uint8 k,bool isMouse);

        SDL_Keycode key;
        bool isMouseOrKey;
        bool isPressed;

    private:
};

class Controls
{
    public:
        Controls();
        void event(bool &run);
        void event(bool &run,vector<KeyAction> &aKeyboard);
        Point getMousePos();
        bool isKeyPressed();

    private:
        SDL_Event ev;
        Point mouse;
        bool keyDown;


};
#endif
