#include "GameLoop.h"

GameLoop *GameLoop::instance = NULL;

GameLoop::GameLoop()
{
    running = true;
    ticking = true;

    initscr();
    raw();
    curs_set(0);
    keypad(stdscr, TRUE);
    noecho();
    start_color();
    halfdelay(1);

    colorPairId = 1;
}

GameLoop *GameLoop::getInstance()
{
    if (!instance)
        instance = new GameLoop();
    return instance;
}

void GameLoop::startGame()
{
	if (modules.size() < 1)
	{
		delete instance;
		return;
	}
    int ch;

    while (running)
    {
        ch = getch();

        if (ch == ERR)
        {
            if (ticking)
                modules[currentModuleIndex]->onInterval();
        }
        else if (ch == KEY_RESIZE)
        {
            modules[currentModuleIndex]->onResize();
        }
        else
        {
            modules[currentModuleIndex]->onInput(ch);
        }
    }

    delete instance;
}

void GameLoop::setModules(vector<Module *>& modules_)
{
    modules = modules_;
    if (modules.size() > 0)
        selectModule(0);
}

void GameLoop::selectModule(unsigned int moduleId)
{
    if (moduleId > modules.size())
        return;
    else
    {
        if (modulesStack.size() == 0 || modulesStack.top() != moduleId)
            modulesStack.push(currentModuleIndex);

        currentModuleIndex = moduleId;
        modules[currentModuleIndex]->onSelect();
    }
}

void GameLoop::selectLastModule()
{
    if (modulesStack.size() == 0)
        return;
    else
    {
        currentModuleIndex = modulesStack.top();
        modulesStack.pop();
        modules[currentModuleIndex]->onSelect();
    }
}

int GameLoop::registerColorPair(const int& background,
		const int& foreground)
{
    int result = colorPairId;
    init_pair(colorPairId, foreground, background);
    colorPairId++;

    return result;
}

GameLoop::~GameLoop()
{
    for (unsigned int i = 0; i < modules.size(); i++) {
        delete modules[i];
    }

    endwin();
}
