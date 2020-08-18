#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include "Screen.h"

int main()
{
	//P248
	Screen myScreen(5,3);
	// move the cursor to a given position, and set that character 
	myScreen.move(4,0).set('#');

	//P249
	Screen nextScreen(5, 5, 'X');
	nextScreen.move(4,0).set('#').display(cout);
	cout << "\n";
	nextScreen.display(cout);
	cout << endl;

	const Screen blank(5, 3);
	myScreen.set('#').display(cout);  // calls nonconst version
	cout << endl;
	blank.display(cout);              // calls const version
	cout << endl;

	myScreen.clear('Z').display(cout); cout << endl;
	myScreen.move(4,0);
	myScreen.set('#');
	myScreen.display(cout); cout << endl;
	myScreen.clear('Z').display(cout); cout << endl;

	// if move returns Screen not Screen&
	Screen temp = myScreen.move(4,0); // the return value would be copied
	temp.set('#'); // the contents inside myScreen would be unchanged
	myScreen.display(cout);
	cout << endl;
}
