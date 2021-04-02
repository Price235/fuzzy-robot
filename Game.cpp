#include "Game.h"
// initialize all variables 
Game::Game()
{
	charPos.first = 0;
	charPos.second = 0;
	choice = 0;
	playing = true;
	name = "NoName";
	items;
	availableItems = { "Red Key", "Sword", "Rope", "a silver coin" };
	haveItem = { false, false , false, false };
}
// function that will loop to keep the game running
void Game::mainMenu()
{
	displayMaze(charPos);
	cout << endl;
	cout << "MAIN MENU" << endl << endl;
	cout << "0: Quit" << endl;
	cout << "1: Help" << endl;
	cout << "2: Show Inventory" << endl;
	cout << "3: Travel" << endl;

	cout << endl << "Choice: ";
	cin >> choice;

	switch (choice)
	{
		case 0:
			playing = false;
			break;
		case 1:
			printHelp();
			break;
		case 2:
			printInventory();
			break;
		case 3:
			promptUserToMove();
			isThereItemHere(charPos);
			progressStory(charPos);
			//displayMaze(charPos);
			// cout << endl << charPos.first << " " << charPos.second << endl;
			break;
	}
}
// displays the maze according to the pair<int,int> position of character
void Game::displayMaze(pair<int,int> pos)
{
	cout << endl;
	cout << "+----------+----------+----------+----------+----------+" << endl;
	cout << "|   START             |                     |          |" << endl;
	cout << "|                     |                     |          |" << endl;

	if (pos.first == 0)
	{
		switch (pos.second)
		{
			case 0:
				cout << "|   YOU                                     |          |" << endl;
				break;
			case 1:
				cout << "|              YOU                          |          |" << endl;
				break;
			case 2:
				cout << "|                          YOU              |          |" << endl;
				break;
			case 3:
				cout << "|                                     YOU   |          |" << endl;
				break;
			case 4:
				cout << "|                                           |    YOU   |" << endl;
				break;
		}
	}
	else
	{
		cout << "|                                           |          |" << endl;
	}
	cout << "|                     |                     |          |" << endl;
	cout << "|                     |                     |          |" << endl;
	cout << "+----------+          +          +          +---    ---+" << endl;
	cout << "|                     |          |                     |" << endl;
	cout << "|                     |          |                     |" << endl;
	

	if (pos.first == 1)
	{
		switch (pos.second)
		{
		case 0:
			cout << "|   YOU               |          |                     |" << endl;
			break;
		case 1:
			cout << "|              YOU    |          |                     |" << endl;
			break;
		case 2:
			cout << "|                     |    YOU   |                     |" << endl;
			break;
		case 3:
			cout << "|                     |          |   YOU               |" << endl;
			break;
		case 4:
			cout << "|                     |          |               YOU   |" << endl;
			break;
		}
	}
	else
	{
		cout << "|                     |          |                     |" << endl;
	}
	cout << "|                     |          |                     |" << endl;
	cout << "|                     |          |                     |" << endl;
	cout << "+----------+----------+---    ---+----------+----------+" << endl;
	cout << "|                                                      |" << endl;
	cout << "|                                                      |" << endl;

	if (pos.first == 2)
	{
		switch (pos.second)
		{
		case 0:
			cout << "|  YOU                                                 |" << endl;
			break;
		case 1:
			cout << "|            YOU                                       |" << endl;
			break;
		case 2:
			cout << "|                        YOU                           |" << endl;
			break;
		case 3:
			cout << "|                                     YOU              |" << endl;
			break;
		case 4:
			cout << "|                                                 YOU  |" << endl;
			break;
		}
	}
	else
	{
		cout << "|                                                      |" << endl;
	}

	cout << "|                                                      |" << endl;
	cout << "|                                                      |" << endl;
	cout << "+----------+          +----------+----------+---    ---+" << endl;
	cout << "|          |          |                                |" << endl;
	cout << "|          |          |                                |" << endl;

	if (pos.first == 3)
	{
		switch (pos.second)
		{
		case 0:
			cout << "|  YOU     |          |                                |" << endl;
			break;
		case 1:
			cout << "|          |   YOU    |                                |" << endl;
			break;
		case 2:
			cout << "|          |          |    YOU                         |" << endl;
			break;
		case 3:
			cout << "|          |          |                YOU             |" << endl;
			break;
		case 4:
			cout << "|          |          |                           YOU  |" << endl;
			break;
		}
	}
	else
	{
		cout << "|          |          |                                |" << endl;
	}

	cout << "|          |          |                                |" << endl;
	cout << "|          |          |                                |" << endl;
	cout << "+---    ---+          +          +----------+----------+" << endl;
	cout << "|                     |                     |          |" << endl;
	cout << "|                     |                     |          |" << endl;

	if (pos.first == 4)
	{
		switch (pos.second)
		{
		case 0:
			cout << "|   YOU               |                                |" << endl;
			break;
		case 1:
			cout << "|               YOU   |                                |" << endl;
			break;
		case 2:
			cout << "|                     |     YOU                        |" << endl;
			break;
		case 3:
			cout << "|                     |               YOU              |" << endl;
			break;
		case 4:
			cout << "|                     |                          YOU   |" << endl;
			break;
		}
	}
	else
	{
		cout << "|                     |                                |" << endl;
	}

	cout << "|                     |                     |          |" << endl;
	cout << "|                     |                     |    END   |" << endl;
	cout << "+----------+----------+----------+----------+----------+" << endl;
}
// function that adds item according to name 
void Game::addItem(string nameOfItem)
{
	for (int i = 0; i < availableItems.size(); ++i)
	{
		if (availableItems.at(i) == nameOfItem)
		{
			items.push_back(availableItems.at(i));
		}
	}
}
// print character inventory
void Game::printInventory()
{
	if (items.size() == 0)
	{
		cout << "+----------+----------+----------+----------+----------+" << endl;
		cout << "|                                                      |" << endl;
		cout << "|                                                      |" << endl;
		cout << "|             You have no items right now.             |" << endl;
		cout << "|                                                      |" << endl;
		cout << "|                                                      |" << endl;
		cout << "+----------+----------+----------+----------+----------+" << endl;
	}
	else
	{
		cout << endl << endl;
		for (int i = 0; i < items.size(); ++i)
		{
			cout << "- " << items.at(i) << endl;
		}
		cout << endl << endl;
	}
}
// function to move character and restricts movement to not move over walls with if statements 
void Game::promptUserToMove()
{
	cout << endl;
	cout << "Where would you like to travel?" << endl;
	cout << "0: North" << endl << "1: South" << endl << "2: West" << endl << "3: East" << endl;
	cout << endl << endl;
	cin >> choice;
	switch (choice)
	{
		case 0:
			if (charPos.first == 0 || (charPos.first == 1 && charPos.second == 0) || (charPos.first == 2 && charPos.second != 2 ) || (charPos.first == 3 && (charPos.second == 0 || charPos.second == 2 || charPos.second == 3)) || (charPos.first == 4 && (charPos.second == 3 || charPos.second == 4)))
			{
				cout << endl << "Cannot move north. Wall is in the way" << endl;
				break;
			}
			else
			{
				charPos.first -= 1;
				break;
			}
		case 1:
			if (charPos.first == 4 || (charPos.second != 2 && charPos.first == 1) || (charPos.first == 0 && charPos.second == 0) || (charPos.first == 2 && (charPos.second == 0 || charPos.second == 2 || charPos.second == 3)) || (charPos.first == 3 && (charPos.second == 3 || charPos.second == 4)) || (charPos.first == 1 && charPos.second == 2 && !haveItem.at(1)) || (charPos.first == 2 && charPos.second == 4 && !haveItem.at(2)))
			{
				cout << endl << "Cannot move south. Wall is in the way" << endl;
				break;
			}
			else
			{
				charPos.first += 1;
				break;
			}
		case 2:
			if (charPos.second == 0 || (charPos.first == 1 && (charPos.second == 2 || charPos.second == 3)) || (charPos.first == 3 && (charPos.second == 1 || charPos.second == 2)) || (charPos.first == 4 && charPos.second == 2))
			{
				cout << endl << "Cannot move west. Wall is in the way" << endl;
				break;
			}
			else
			{
				charPos.second -= 1;
				break;
			}
		case 3:
			if (charPos.second == 4 || (charPos.first == 0 && charPos.second == 3) || (charPos.first == 1 && (charPos.second == 1 || charPos.second == 2)) || (charPos.first == 3 && (charPos.second == 0 || charPos.second == 1)) || (charPos.first == 4 && charPos.second == 1) || (charPos.first == 0 && charPos.second == 1 && !haveItem.at(0)) || (charPos.first == 4 && charPos.second == 3 && !haveItem.at(3)))
			{
				cout << endl << "Cannot move east. Wall is in the way" << endl;
				break;
			}
			else
			{
				charPos.second += 1;
				break;
			}
		default:
			break;
	}
}
// return charPos
pair<int,int> Game::GetPos()
{
	return charPos;
}
// if the character is at current position he/she will obtain an item
void Game::isThereItemHere(pair <int, int> currPos)
{
	if (currPos.first == 1 && currPos.second == 0)
	{
		addItem(availableItems.at(0));
		haveItem.at(0) = true;
	}
	if (currPos.first == 0 && currPos.second == 4)
	{
		addItem(availableItems.at(1));
		haveItem.at(1) = true;
	}
	if (currPos.first == 3 && currPos.second == 0)
	{
		addItem(availableItems.at(2));
		haveItem.at(2) = true;
	}
	if (currPos.first == 2 && currPos.second == 0)
	{
		addItem(availableItems.at(3));
		haveItem.at(3) = true;
	}
}
// main dialogue of story that is linked to charPos
void Game::progressStory(pair<int, int> currPos)
{
	switch (currPos.first)
	{
		case 0:
			switch (currPos.second)
			{
				case 0:
					// already did intro
					break;
				case 1:
					if (!haveItem.at(0))
					{
						cout << endl << endl << "You enter a strange darkly lit room that has a hallway going south" << endl;
						cout << "There seems to be a strange door that looks like it could be opened by something" << endl;
					}
					else
					{
						cout << endl << endl << "You return to the strange darkly lit room to find the same door" << endl;
						cout << "You inspect the door and notice a small key hole" << endl;
					}
					break;
				case 2:
					if (!haveItem.at(1))
					{
						cout << endl << endl << "You unlock the door and enter a colorful room full of roses and flowers." << endl;
						cout << "The room feels alive and is full of vines and grass everywhere." << endl;
						cout << "Through the thick vegetation you see a passage that leads east and another that leads south." << endl;
					}
					else
					{
						cout << endl << endl;
						cout << "You enter the thick vegetation again" << endl;
					}
					break;
				case 3:
					if (!haveItem.at(1))
					{
						cout << endl << endl << "You pass the vegetation and come across a room flowing with water from all sides" << endl;
						cout << "The water seems to be dropping down into a large lake full of alligators" << endl;
						cout << "I think you have to go down there" << endl;
					}
					else
					{
						cout << endl << endl << "You carefully come across this room again" << endl;
					}
					
					break;
				case 4:
					cout << endl << endl << "You enter the secret compartment and find a nice sword wedged inside a rock" << endl;
					cout << "You try to take the sword out but fail and after trying to take the sword out of the rock for the last 30 minutes" << endl;
					cout << "you realize there is a button next to the rock to release the sword" << endl;
					cout << "How convenient" << endl;
					cout << "You take the sword" << endl;
					break; 
				default:
					break;
			}
			break;
		case 1:
			switch (currPos.second)
			{
				case 0:
					cout << endl << endl << "You meet a dead end and stumble upon a skeleton with a red key on his necklace" << endl;
					cout << "You take the red key" << endl;
					break;
				case 1:
					if (!haveItem.at(0))
					{
						cout << endl << endl << "You enter the hallway and find nothing but broken bones and spiders" << endl;
						cout << "There seems to be a path west to this hall and there is fur all over the floor towards that path." << endl;
					}
					else
					{
						cout << endl << endl << "You return to the hallway to find the same  broken bones and spiders." << endl;
						cout << "But now you can probably do something about that door" << endl;
					}
					break;
				case 2:
					if (!haveItem.at(1))
					{
						cout << endl << endl << "You pass the mass of plants and grass to stumble upon a curtain of vines that seem to be blocking a path south from here." << endl;
						cout << "You try to get through the vines but the vines are too thick and won't budge" << endl;
					}
					else
					{
						cout << endl << endl;
						cout << "You come across the same curtain of vines" << endl;
						cout << "Maybe this sword can help you cut the vines" << endl;
						cout << "You use your sword and a couple minutes later after wacking the vines with the sword you finally create a path through" << endl;
					}
					break;
				case 3:
					if (!haveItem.at(1))
					{
						cout << endl << endl << "You dive into the lake and realize that they were not alligators but giant friendly lizards who help you find the exit" << endl;
						cout << "Awesome" << endl;
					}
					else
					{
						cout << endl << endl << "You see the lizards having a pool party and pass by" << endl;
					}
					break;
				case 4:
					if (!haveItem.at(1))
					{
						cout << endl << endl << "This room appears to have a secret compartment north of it" << endl;
						cout << "I wonder what's in there" << endl;
					}
					else
					{
						cout << endl << endl << "Now with this trusty sword you can probaly do something" << endl;
					}
					break;
				default:
					break;
			}
			break;
		case 2:
			switch (currPos.second)
			{
				case 0:
					cout << endl << endl << "This is a dead end but you see a shiny silver coin on the ground and decide to pick it up" << endl;
					cout << "maybe it can be useful" << endl;
					cout << "Obtained a silver coin" << endl;
					break;
				case 1:
					if (!haveItem.at(2))
					{
						cout << endl << endl << "This room is just empty but it at least leads west and south" << endl;
					}
					else
					{
						cout << endl << endl << "Same empty room" << endl;
					}
					break;
				case 2:
					if (!haveItem.at(2))
					{
						cout << endl << endl << "You enter a strange pink room that appears to be made of cotton candy." << endl;
						cout << "the room appears to have two paths one heading east and another heading west" << endl;
					}
					else
					{
						cout << endl << endl << "Cotton Candy :D" << endl;
					}
					break;
				case 3:
					if (!haveItem.at(2))
					{
						cout << endl << endl << "You enter a cold frozen room full of penguins" << endl;
						cout << "The penguins don't seem to care for your presence" << endl;
					}
					else
					{
						cout << "Penguins are sleeping" << endl;
					}
					break;
				case 4:
					if (!haveItem.at(2))
					{
						cout << endl << endl << "You enter a cavern and you see a large cliff south that maybe you can reach with some help" << endl;
						cout << "What could you need?" << endl;
					}
					else
					{
						cout << endl << endl << "Ah yes a rope can help you climb this" << endl;
						cout << "you throw the rope towards the top of the cliff and conveniently a rock is there to hold up the rope :D" << endl;
					}
					break;
				default:
					break;
			}
			break;
		case 3:
			switch (currPos.second)
			{
				case 0:
					cout << endl << endl;
					cout << "Where is this light coming from?" << endl;
					cout << "You can't figure out why the room is so bright but in it you find a rope" << endl;
					cout << "You take the rope" << endl;
					break;
				case 1:
					if (!haveItem.at(2))
					{
						cout << endl << endl << "You go south and enter this room full of small puppies." << endl;
						cout << "Inside the room you also find their owner and he greets you" << endl;
						cout << "The owner warns you of a dangerous animal towards the end of the maze" << endl;
					}
					else
					{
						cout << endl << endl << "You pet the puppies and say your goodbye's to everyone" << endl;
					}
					break;
				case 2:
					cout << endl << endl << "Yet another room full of hot sand" << endl;
					cout << "What is up with all these rooms full of sand?" << endl;
					break;
				case 3:
					cout << endl << endl << "Another hot room full of sand" << endl;
					break;
				case 4:
					cout << endl << endl << "A hot room full of sand" << endl;
					break;
				default:
					break;
			}
			break;
		case 4:
			switch (currPos.second)
			{
				case 0:
					if (!haveItem.at(2))
					{
						cout << endl << endl << "Empty room" << endl;
					}
					else
					{
						cout << "Same boring room" << endl;
					}
					break;
				case 1:
					if (!haveItem.at(2))
					{
						cout << endl << endl << "This room seems to be covered with mushrooms" << endl;
						cout << "I think it's best not to eat any of them" << endl;
					}
					else
					{
						cout << endl << endl << "Mushrooms" << endl;
					}
					break;
				case 2:
					cout << endl << endl << "At least this room has no more sand, but there isn't much to see" << endl;
					break;
				case 3:
					if (!haveItem.at(3))
					{
						cout << endl << endl << "A large troll stands before a giant door" << endl;
						cout << "He stops you and says you will not pass without paying him. What does he want?" << endl;
					}
					else
					{
						cout << endl << endl << "Ah yes this coin will be enough to pass" << endl;
					}
					break;
				case 4:
					cout << endl << endl << "You pass the ogre and find a large mountain of gold and treasure waiting for you" << endl;
					cout << "Your cat chester seems to be atop the pile" << endl;
					cout << "You run forward climbing the massive mountain of gold and give your cat chester a hug" << endl;
					cout << "You then proceed to leave the maze through the door behind the mountain of gold that says Exit" << endl;
					cout << "You go home and get a goodnight's rest knowing you saved your cat chester" << endl;
					cout << "Oh and you leave all the gold behind because who care about gold am I right" << endl;
					cout << endl << "YOU HAVE COMPLETED THE GAME CONGRATULATIONS!" << endl;
					break;
				default:
					break;
			}
			break;
	}
}
// help menu
void Game::printHelp()
{
	cout << endl << endl << "Hi I heard you need help with something" << endl;
	cout << "Your objective is to get through the maze. To do this you can input the number 3 and press enter to confirm" << endl;
	cout << "This will in return open the travel menu where you can choose another number to move where you desire." << endl;
	cout << "Some doors may be locked so explore other areas to find something to help you open these doors." << endl;
	cout << "Good Luck!" << endl;
}
// check if character is at end of game
void Game::isAtEnd(pair<int, int> pos)
{
	if (pos.first == 4 && pos.second == 4)
	{
		cout << endl << endl << "Do You Want To Play Again?" << endl;
		int choice;
		cin >> choice;
		cout << endl << "0: No" << endl;
		cout << endl << "1: Yes" << endl;
		if (choice == 0)
		{
			playing = false;
		}
		else if (choice == 1)
		{
			playing = true;
		}
		else
		{
			cout << endl << "Enter valid number" << endl; 
			cout << endl << "0: No" << endl;
			cout << endl << "1: Yes" << endl;
			cin >> choice;
		}
	}
}