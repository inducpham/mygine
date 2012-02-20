#include "../GameLoop.h"
#include "PalleteModule.h"
#include "StartModule.h"
#include "PaintHost.h"
#include <vector>
using namespace std;

int main()
{

    GameLoop *i = GameLoop::getInstance();
	PaintHost *h = new PaintHost();

    //set modules here
    vector<Module *> modules;
	modules.push_back(new StartModule(i, h));
	modules.push_back(new PalleteModule(i, h));

	//add the modules and start the game
    i->setModules(modules);
    i->startGame();
	//the gameloop would destroy its instance and all the created module
	//when it stop the game. So no delete is nessesary
	delete h;

	return 0;
}
