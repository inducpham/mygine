#include "GameLoop.h"
#include "SimpleModule.h"
#include <vector>
using namespace std;

int main()
{
    GameLoop *i = GameLoop::getInstance();

    //set modules here
    vector<Module *> modules;
	modules.push_back(new SimpleModule(i));

	//add the modules and start the game
    i->setModules(modules);
    i->startGame();
	//the gameloop would destroy its instance and all the created module
	//when it stop the game. So no delete is nessesary

	return 0;
}
