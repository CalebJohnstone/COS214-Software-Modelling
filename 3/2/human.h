#ifndef HUMAN_H
#define HUMAN_H

class Human
{

	public:

		Human(char value, int x, int y);
		
		void setValue(char value);
		void setX(int x);
		void setY(int y);

		char getValue();
		int getX();
		int getY();

	private:

		char mValue;
		int mX;
		int mY;

};

#endif