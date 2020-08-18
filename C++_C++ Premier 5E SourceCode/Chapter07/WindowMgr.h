#ifndef WINDOW_MGR
#define WINDOW_MGR

#include <vector>
#include <string>
#include <iostream>
#include "newscreen.h"

//P243-266

class BitMap;
// overloaded storeOn functions
extern std::ostream& storeOn(std::ostream &, Screen &);
extern BitMap& storeOn(BitMap &, Screen &);

class Window_mgr 
{
public:
	// location ID for each screen on the window
	using ScreenIndex = std::vector<Screen>::size_type;
	// add a Screen to the window and returns its index

	ScreenIndex addScreen(const Screen&);
	
	// reset the Screen at the given position to all blanks
	void clear(ScreenIndex);

	// change dimensions of a given Screen
	void resize(Screen::pos r, Screen::pos c, ScreenIndex i);
private:
	// Screens this Window_mgr is tracking
	// by default, a Window_mgr has one standard sized blank Screen 
	std::vector<Screen> screens{Screen(24, 80, ' ')};
};

// return type is seen before we're in the scope of Window_mgr
inline
Window_mgr::ScreenIndex
Window_mgr::addScreen(const Screen &s)
{
	screens.push_back(s);
	return screens.size() - 1;
}   

inline
void Window_mgr::clear(ScreenIndex i)
{
	// s is a reference to the Screen we want to clear
	Screen &s = screens[i];
	// reset the contents of that Screen to all blanks
	s.contents = std::string(s.height * s.width, ' ');
}

inline
void
Window_mgr::resize(Screen::pos r, Screen::pos c, ScreenIndex i)
{
    screens[i].height = r;  // Window_mgr is a friend of Screen
    screens[i].width = c;   // so it is ok to use Screen's private members
	// resize and clear the contents member
	screens[i].contents = std::string(r * c, ' '); 
}

#endif
