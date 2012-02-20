#include "AbstractModule.h"

AbstractModule::AbstractModule(GameLoop *game_)
{
	game = game_;
	backgroundColor = 0;
}

AbstractModule::~AbstractModule()
{
}

void AbstractModule::onInterval()
{
} //do nothing

void AbstractModule::onResize()
{
	paint(true);
}

void AbstractModule::onSelect()
{
	paint(true);
}

void AbstractModule::onInput(int ch)
{} //apparently do nothing.. again

void AbstractModule::setBackgroundColor(int color)
{
	backgroundColor = game->registerColorPair(color, color);
}

void AbstractModule::paint(bool repaint)
{
	//if repaint is true, then complete repaint of
	//the background, the component
	
	if (repaint)
	{
		int bufferSize = COLS * LINES;
		//clear the space
		attron(COLOR_PAIR(backgroundColor));
		move(0, 0);
		for (int i = 0; i < bufferSize; i++)
		{
			printw(" ");
		}
		attroff(COLOR_PAIR(backgroundColor));
	}

	refresh();
}
//Thats should be it!
