#ifndef SIMPLEMODULE_H
#define SIMPLEMODULE_H

#include "AbstractModule.h"
#include <ncurses.h>
#include <panel.h>

class SimpleModule : public AbstractModule
{
	public:
		SimpleModule(GameLoop *game_);
		virtual ~SimpleModule();
		virtual void onInterval();
		virtual void onResize();
		virtual void onSelect();
		virtual void onInput(int ch);
		virtual void paint(bool repaint = false);
	private:
		int textColor;
};

#endif // SIMPLEMODULE_H
