#ifndef MODULE_H
#define MODULE_H

#include <ncurses.h>
#include <panel.h>

//the module interface follows state pattern and such
class Module
{

public:
    virtual void onInterval() = 0;
    virtual void onResize() = 0;
    virtual void onSelect() = 0;
    virtual void onInput(int ch) = 0;
    virtual ~Module() {
    }

};

#endif // MODULE_H
