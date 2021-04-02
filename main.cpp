#include "Game.h"


int main()
{
	Game game;
	
	cout << "You once heard rumors about the hidden treasures at the end of the maze." << endl;
	cout << "These rumors fill you with determination and you set your mind on getting through the maze" << endl;
	cout << "Also you lost your pet cat and you heard he was at the end of the maze. So good luck finding him :)" << endl;
	cout << "On approaching the door to the maze a strange riddle asks for your name." << endl << "Name: ";
	string name;
	getline(cin, name);
	game.setName(name);
	cout << endl << endl << "Hello there " << game.getName() << ". I think the maze you're supposed to go through is below you." << endl;
	cout << "How did you get this map to the maze no one has ever come out alive of? I don't know, but consider yourself lucky." << endl;
	while (game.getPlaying())
	{
		game.mainMenu();
	}
	cout << endl << endl << "THANKS FOR PLAYING!" << endl << endl;
	return 0;
}