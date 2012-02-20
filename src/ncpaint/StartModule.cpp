#include "StartModule.h"

StartModule::StartModule(GameLoop *game_, PaintHost *host_):
	AbstractModule(game_)
{
	//constructor of the simple module
	host = host_;

	//Set the color such as background color or registering cursor
	//color here
	//
	//the set background automatically make the panel green
	AbstractModule::setBackgroundColor(COLOR_BLACK);
	//register the colorpair for displaying from GameLoop
	//textColor = game->registerColorPair(COLOR_BLACK + 8, COLOR_WHITE + 8);

	//set the default size for the panel, otherwise it would just take
	//the full screen! height, width, starty and startx
	//setDefaultSize(10, 40, 5, 5);
	//make the panel take on full screen up resizing or selecting
	//setFullscreen();
	
	dimension.push_back(0);
	dimension.push_back(0);
	currentChoice = 0;
}

StartModule::~StartModule()
{
	//the destructor for the module
}

void StartModule::onInterval()
{
	AbstractModule::onInterval();
	//the interval occurs every 1/10. On the case of keyboard input
	//the interval could be delayed

}

void StartModule::onResize()
{
	AbstractModule::onResize();
	//normally the superclass would do all the resizing based on whether
	//the application is fullscreened or has default size.
}

void StartModule::onSelect()
{
	AbstractModule::onSelect();
	//the onselect function is called when the GameLoop changes its state
	//to this module.
	//The superclass would then call the resizing and repaint function
}

void StartModule::onInput(int ch)
{
	AbstractModule::onInput(ch);
	//
	if (ch == 'q') {
		game->setRunning(false);
		//the game then exit the loop and finish the application
	}
	else if ((ch == '\n' || ch == KEY_ENTER) && valid)
	{
		host->setSize(dimension[1], dimension[0]);
		game->selectModule(1);
	}
	else if (ch == KEY_BACKSPACE)
	{
		dimension[currentChoice] /= 10;
		paint(false);
	}
	else if (ch == KEY_UP)
	{
		if (currentChoice == 0)
			currentChoice = dimension.size() - 1;
		else
			currentChoice--;
		paint(false);
	}
	else if (ch == KEY_DOWN)
	{
		if (currentChoice == dimension.size() - 1)
			currentChoice = 0;
		else
			currentChoice++;
		paint(false);
	}
	else if (ch >= '0' && ch <= '9' && dimension[currentChoice] < 1000)
	{
		dimension[currentChoice] = dimension[currentChoice] * 10 + ch - '0';
		paint(false);
	}
}

void StartModule::paint(bool repaint)
{
	AbstractModule::paint(repaint);
	//Do the painting decoration here; The superclass would clear the
	//panel using the default background color
	mvprintw(0, 0, "Crsp alpha . v0.1");
	
	mvprintw(2, 0, "  Width : ");
	paintChoice(0);
	mvprintw(3, 0, "  Height: ");
	paintChoice(1);

	if (dimension[0] != 0 && dimension[1] != 0)
		valid = true;
	else
		valid = false;

	if (valid)
		mvprintw(5, 0, "%s\n%s",
				"Press enter to create new canvas",
				"using entered dimension.");

	//refresh the window
	refresh();
}

void StartModule::paintChoice(unsigned int choice) {
	if (choice == currentChoice)
		attron(A_REVERSE);
	printw("%4.d", dimension[choice]);
	if (choice == currentChoice)
		attroff(A_REVERSE);
}
