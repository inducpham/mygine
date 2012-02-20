#ifndef ABSTRACTMODULE_H
#define ABSTRACTMODULE_H

#include "GameLoop.h"

#include <vector>
using std::vector;

//Intent: provide an abstract class for the popup menu,
//which focuses on the backtracking. Also elegantly
//handles the resizing.
//Implementing modules
class AbstractModule : public Module
{
	public:
		AbstractModule(GameLoop *game_);
		virtual ~AbstractModule();
		virtual void onInterval();
		virtual void onResize();
		virtual void onSelect();
		virtual void onInput(int ch);
		virtual void paint(bool repaint = false);

		void setBackgroundColor(int color);
	protected:
		GameLoop *game;
	private:
		int backgroundColor;
};

#endif // ABSTRACTMODULE_H
