#include "PalleteModule.h"

PalleteModule::PalleteModule(GameLoop *game_, PaintHost *host_): AbstractModule(game_)
{
	host = host_;

	delayCount = 0;
	DELAY_TIME = 6;

	TEXT_COLOR = game->registerColorPair(COLOR_BLACK, COLOR_WHITE);

	//constructor of the simple module

	//Set the color such as background color or registering cursor
	//color here
	//
	//the set background automatically make the panel green
	AbstractModule::setBackgroundColor(COLOR_BLACK);
	//register the colorpair for displaying from GameLoop
	//textColor = game->registerColorPair(COLOR_BLACK + 8, COLOR_WHITE + 8);

	//set the default size for the panel, otherwise it would just take
	//the full screen! height, width, starty and startx
	//setDefaultSize(host->getHeight(), host->getWidth(), 1, 1);
	//make the panel take on full screen up resizing or selecting
	//setFullscreen();
}

PalleteModule::~PalleteModule()
{
	//the destructor for the module
}

void PalleteModule::onInterval()
{
	AbstractModule::onInterval();
	//the interval occurs every 1/10. On the case of keyboard input
	//the interval could be delayed
	
	if (delayCount == DELAY_TIME)
	{
		delayCount = 0;
		isCursorFlashing = !isCursorFlashing;
		paint();
	} else
		delayCount++;
}

/*
void SimpleModule::onResize()
{
	AbstractModule::onResize();
	//normally the superclass would do all the resizing based on whether
	//the application is fullscreened or has default size.
}
*/

void PalleteModule::onSelect()
{
	AbstractModule::onSelect();
	//the onselect function is called when the GameLoop changes its state
	//to this module.
	//The superclass would then call the resizing and repaint function
}

void PalleteModule::onInput(int ch)
{
	AbstractModule::onInput(ch);
	//systematic
	switch (ch)
	{
		case 'q':
			game->setRunning(false);
			return;
			//the game then exit the loop and finish the application
			break;
	}

	switch (ch)
	{
		//cursor movement
		case KEY_UP:
			host->moveCursor(-1, 0);
			break;
		case KEY_DOWN:
			host->moveCursor(1, 0);
			break;
		case KEY_LEFT:
			host->moveCursor(0, -1);
			break;
		case KEY_RIGHT:
			host->moveCursor(0, 1);
			break;
		case '1':
			game->selectModule(0);
			break;
		//input action
		//case ' ':
			//host->writeCharAtCursor('#');
			//break;
		default:
			host->writeCharAtCursor(ch);
			host->moveCursor(0, 1);
	}

	//movement detected
	isCursorFlashing = true;
	paint();
}

void PalleteModule::paint(bool repaint)
{
	AbstractModule::paint(repaint);
	//Do the painting decoration here; The superclass would clear the
	//panel using the default background color
	
	attron(COLOR_PAIR(TEXT_COLOR));
	
	for (unsigned y = 0; y < host->getHeight(); y++)
		for (unsigned x = 0; x < host->getWidth(); x++)
		{
			mvprintw(y, x, "%c", host->getChar(y, x));
		}

	if (isCursorFlashing) attron(A_REVERSE);
		mvprintw(host->getCursorY(), host->getCursorX(),
				"%c", host->getCharAtCursor());
	if (isCursorFlashing) attroff(A_REVERSE);
	
	attroff(COLOR_PAIR(TEXT_COLOR));

	//refresh the window
	refresh();
}
