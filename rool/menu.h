#ifndef MENU_H
#define MENU_H

#include "display.h"
#include "core/controls.h"

class Menu
{
    public:
    Menu(Window &win_,Controls &ctrls_,bool &run_);
    ~Menu();

    bool menuInit(Window &win);
    void menuUpdate();
    void menuDisplay(Display &disp);

    private:
    Window &win;
    Controls &ctrls;
    bool& run;

    vector<KeyAction> mKeyboard;
};

#endif