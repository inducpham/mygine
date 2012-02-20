#ifndef PAINTHOST_H
#define PAINTHOST_H

class PaintHost
{
	public:
		PaintHost();
		virtual ~PaintHost();

		//setting the properties of the host
		void setSize(unsigned int height_, unsigned int width_);
		unsigned int getWidth() { return width; }
		unsigned int getHeight() { return height; }

		//cursor settings methods
		void setCursor(unsigned int cy_, unsigned int cx_) {
			cx = cx_;
			cy = cy_;
		}
		void moveCursor(int y, int x);
		unsigned int getCursorX() { return cx; }
		unsigned int getCursorY() { return cy; }

		//data writing
		void writeCharAtCursor(int ch);
		int getCharAtCursor();
		//tile access
		void setChar(int ch, unsigned int y, unsigned int x);
		int getChar(unsigned int y, unsigned int x);

	private:
		//pallete size
		unsigned int width, height;
		//pallete grid
		int *grid;

		//cursor location
		unsigned int cx, cy;
};

#endif // PAINTHOST_H
