#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <ncurses.h>
#include <vector>
using std::vector;
#include <stack>
using std::stack;

#include "Module.h"

class GameLoop
{

public:
    void startGame();
    virtual ~GameLoop();
    static GameLoop *getInstance();
    void selectModule(unsigned int moduleId);
    void setModules(vector<Module *>& modules_);
    void selectLastModule();
    int registerColorPair(const int& color1, const int& color2);

    void setRunning(bool running_)
    {
        running = running_;
    }
    void setTicking(bool ticking_)
    {
        ticking = ticking_;
    }
protected:
private:
    vector<Module *> modules;
    stack<unsigned int> modulesStack;
    int currentModuleIndex;
    int colorPairId;
    //order stack i guess

    static GameLoop *instance;
    bool running;
    bool ticking;

    GameLoop();
};

#endif // GAMELOOP_H
