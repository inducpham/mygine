#include "SimpleModule.h"

SimpleModule::SimpleModule(GameLoop *game_): AbstractModule(game_)
{
	//constructor of the simple module

	//Set the color such as background color or registering cursor
	//color here
	//
	//the set background automatically make the panel green
	AbstractModule::setBackgroundColor(COLOR_BLACK + 8);
	//register the colorpair for displaying from GameLoop
	textColor = game->registerColorPair(COLOR_BLACK + 8, COLOR_WHITE + 8);

	//set the default size for the panel, otherwise it would just take
	//the full screen! height, width, starty and startx
	//make the panel take on full screen up resizing or selecting
	//setFullscreen();
}

SimpleModule::~SimpleModule()
{
	//the destructor for the module
}

void SimpleModule::onInterval()
{
	AbstractModule::onInterval();
	//the interval occurs every 1/10. On the case of keyboard input
	//the interval could be delayed

}

void SimpleModule::onResize()
{
	AbstractModule::onResize();
	//normally the superclass would do all the resizing based on whether
	//the application is fullscreened or has default size.
}

void SimpleModule::onSelect()
{
	AbstractModule::onSelect();
	//the onselect function is called when the GameLoop changes its state
	//to this module.
	//The superclass would then call the resizing and repaint function
}

void SimpleModule::onInput(int ch)
{
	AbstractModule::onInput(ch);
	//
	switch (ch)
	{
		case 'q':
			game->setRunning(false);
			//the game then exit the loop and finish the application
			break;
	}
}

void SimpleModule::paint(bool repaint)
{
	AbstractModule::paint(repaint);

	if (!repaint)
		return;
	//Do the painting decoration here; The superclass would clear the
	//panel using the default background color
	attron(COLOR_PAIR(textColor));
	mvprintw(1, 1, "Press q to quit the application and also all the fizzle");
	attroff(COLOR_PAIR(textColor));


	//refresh the window
	refresh();
}
