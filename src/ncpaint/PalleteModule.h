#ifndef PALLETEMODULE_H
#define PALLETEMODULE_H

#include "../AbstractModule.h"
#include "PaintHost.h"
#include <ncurses.h>
#include <panel.h>

class PalleteModule : public AbstractModule
{
	public:
		PalleteModule(GameLoop *game_, PaintHost *host);
		virtual ~PalleteModule();
		virtual void onInterval();
		virtual void onSelect();
		virtual void onInput(int ch);
		virtual void paint(bool repaint = false);
	private:
		//host
		PaintHost *host;

		//eye candies
		int TEXT_COLOR;

		//variable for cursor notification
		int delayCount;
		int DELAY_TIME;
		bool isCursorFlashing;
};

#endif // PALLETEMODULE_H
