#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Game
{
public:
	Game();

	//operators

	//Functions
	void mainMenu();
	void displayMaze(pair<int, int> pos);
	void isThereItemHere(pair<int, int> currPos);

	//Accessors
	bool getPlaying() const { return this->playing; }
	string getName() const { return this->name; }

	//Modifiers
	void setName(string name) { this->name = name; }
	void addItem(string nameOfItem);
	void printInventory();
	void promptUserToMove();
	pair<int,int> GetPos();
	void progressStory(pair<int,int> currPos);
	void printHelp();
	void isAtEnd(pair <int, int> pos);
	

private:
	pair <int, int> charPos;
	int choice;
	bool playing;
	string name;
	vector<string> items;
	vector<string> availableItems;
	vector<bool> haveItem;
};

