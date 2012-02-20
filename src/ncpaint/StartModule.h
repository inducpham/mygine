#ifndef STARTMODULE_H
#define STARTMODULE_H

#include "../AbstractModule.h"
#include "PaintHost.h"
#include <ncurses.h>
#include <panel.h>
#include <vector>
using std::vector;

class StartModule : public AbstractModule
{
	public:
		StartModule(GameLoop *game_, PaintHost *host_);
		virtual ~StartModule();
		virtual void onInterval();
		virtual void onResize();
		virtual void onSelect();
		virtual void onInput(int ch);
		virtual void paint(bool repaint = false);
	private:
		void paintChoice(unsigned int currentChoice);

		PaintHost *host;

		vector<unsigned> dimension;
		unsigned currentChoice;
		bool valid;
};

#endif // STARTMODULE_H
