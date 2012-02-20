#include "PaintHost.h"

PaintHost::PaintHost()
{
	grid = 0;
}

PaintHost::~PaintHost()
{
	if (grid != 0)
		delete[] grid;
}

void PaintHost::setSize(unsigned int height_, unsigned int width_) {
	height = height_;
	width = width_;

	grid = new int[(height + 1) * (width + 1)];
	for (unsigned int i = 0; i < ((height + 1) * (width + 1)); i++)
		grid[i] = ' ';
}

void PaintHost::moveCursor(int y, int x) {
	cy += y; cx += x;

	if (cy < height && cx < width)
		return;

	cy -= y; cx -= x;
}

void PaintHost::writeCharAtCursor(int ch) {
	setChar(ch, cy, cx);
}

int PaintHost::getCharAtCursor() {
	return getChar(cy, cx);
}

void PaintHost::setChar(int ch, unsigned y, unsigned x) {
	if (y >= height || x >= width)
		return;
	grid [y*width + x] = ch;
}

int PaintHost::getChar(unsigned y, unsigned x) {
	return grid[y * width + x];
}
