//Joseph Coleman
//COP2000.0M1
//This program will play a game of chance with dice

#include<iostream>
#include<string>
using namespace std;




class Game
{
private: 
	int die1;
	int die2;
	int totalPoints;
	int totalRolls;

	void updatePoints();
	void updateRolls();
	int rng();
	void outcome();

public:
	Game();
	void roll();
	void quit();


};

/************Method Definitions********************/
int Game::rng()
{
	int n;
	n = (rand() % 6) + 1;

	return n;
}
Game::Game()
{
	//initialize variables
	die1 = 1;
	die2 = 1;
	totalPoints = 0;
	totalRolls = 0;
}
void Game::roll()
{
	char choice;

	cout << "Do you want to roll? (y=yes, n=no): ";
	cin >> choice;

	if (choice != 'n' && choice != 'y')
	{
		cout << "invalid response: y=yes, n=no:";
		cin >> choice;
	}

	while (choice == 'y')
	{
			outcome();

			cout << "Do you want to roll? (y=yes, n=no): ";
			cin >> choice;

	}
	

	if (choice == 'n')
	{
		quit();
	}

}
 void Game::outcome()
{
	 cout << "\n\nrolling the dice...";

	die1 = rng();
	die2 = rng();
	
	cout << "\n\nYou rolled a " << die1 + die2 << "! ";
	if (die1 + die2 == 7 || die1 + die2 == 11)
	{
		cout << "You win! ";
		totalPoints++;
	}
	if (die1 + die2 == 2 || die1 + die2 == 3 || die1 + die2 == 12)
	{
		cout << "You lost.";
		totalPoints--;
	}
	if (die1 + die2 != 2 && die1 + die2 != 3 && die1 + die2 != 12 && die1 + die2 != 7 && die1 + die2 != 11)
	{
		cout << "No points.";
	}

	totalRolls++;

	cout << " Points: " << totalPoints << ".\n\n";
}
 void Game::updateRolls()
 {
	 totalRolls ++;
 }
 void Game::updatePoints()
 {
	 totalPoints ++;
 }
 void Game::quit()
 {
	 cout << "\n\nYou rolled the dice " << totalRolls << " times." << endl;
	 cout << "You won " << totalPoints << " points." << endl << endl << "Better luck next time!\n\n";
 }

/******************Driver**********************/
int main()
{
//variables
	Game input;


	cout << "Your Game of Chance!\n\n";


	input.roll();
}




