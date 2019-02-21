#include <iostream>
#include <vector>

class Screen {
	friend class Window_mgr;
public:
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) {}
	char get() const
		{ return contents[cursor]; }
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
	Screen &set(char);
	Screen &set(pos, pos, char);
	Screen &display(std::ostream &os)
		{ do_display(os); return *this;}
	const Screen &display(std::ostream &os) const
		{ do_display(os); return *this;}
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	void do_display(std::ostream &os) const {os << contents;}
};

class Window_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
	ScreenIndex addScreen(const Screen&);
private:
	std::vector<Screen> screens{Screen(24, 80, ' ')};
};

void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.contents = string(s.height * s.width, ' ');
}

class Link_screen {
	Screen window;
	Link_screen *next;
	Link_screen *prev;
};
