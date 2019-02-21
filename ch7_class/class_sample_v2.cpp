#include "class_sample_v2.h"
using namespace std;

inline
Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}
char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	return contents[row + c];
}
inline Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}
inline Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;
	return *this;
}
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
	screens.push_back(s);
	return screens.size() - 1;
}

int main()
{
	Screen myscreen(5, 5, 'c');
	const Screen blank(5, 3, ' ');
	char ch = myscreen.get();
	ch = myscreen.get(0, 0);
	myscreen.move(4, 0).set('#').display(cout);
	cout << endl;
	blank.display(cout);
	cout << endl;
	Link_screen ls;
	return 0;
}
