#include<iostream>
using namespace std;

struct stGameInfo
{
	int playerWinTimes = 0;
	int computerWinTimes = 0;
	int drowTimes = 0;
	int roundCounter = 0;
};
enum  enChoice
{
	rock = 1, paper = 2, scissors = 3
};


int randomNumber(int from, int to)
{
	int RandNum = rand() % (to - from + 1) + from;

	return RandNum;
}

stGameInfo theWinnerInRound(int player, int computer)
{

	stGameInfo gameInfo;

	if (player == computer)
	{
		gameInfo.drowTimes += 1;
	}

	else if (player == enChoice::rock)
	{
		if (computer == enChoice::paper)
		{
			gameInfo.computerWinTimes += 1;
		}

		else
		{
			gameInfo.playerWinTimes += 1;
		}
	}

	else if (player == enChoice::paper)
	{
		if (computer == enChoice::scissors)
		{
			gameInfo.computerWinTimes += 1;
		}

		else
		{
			gameInfo.playerWinTimes += 1;
		}
	}

	else if (player == enChoice::scissors)
	{
		if (computer == enChoice::rock)
		{
			gameInfo.computerWinTimes += 1;
		}

		else
		{
			gameInfo.playerWinTimes += 1;
		}
	}

	return gameInfo;

}

void printWinnerName_InRound(stGameInfo roundResult)
{
	if (roundResult.playerWinTimes)
	{
		cout << "\n[You win]\n\n";
	}

	else if (roundResult.computerWinTimes)
	{
		cout << "\n[You lose]\n\n";
	}

	else
	{
		cout << "\n{Drow}\n\n";
	}
}

void printWinner(stGameInfo gameInfo)
{

	if (gameInfo.playerWinTimes == gameInfo.computerWinTimes)
	{
		cout << "\a-----{It's Drow :|}-----" << endl;
	}

	else if (gameInfo.playerWinTimes > gameInfo.computerWinTimes)
	{
		system("color 2");
		cout << "\a+++[You are the winner!!]+++" << endl;
	}

	else if (gameInfo.computerWinTimes > gameInfo.playerWinTimes)
	{
		system("color 4");
		cout << "\a***[You lost :(]***" << endl;
	}
}

void resetScreen()
{
	system("cls");
	system("color 0F");
}


void gameOver(stGameInfo gameInfo)
{

	resetScreen();

	cout << "\n************************************\n";
	cout << "*|---------GAME ** OVER-----------|*\n";
	cout << "************************************\n";
	cout << "-----------{" << gameInfo.roundCounter << " Rounds}-------------" << endl;
	printWinner(gameInfo);

	cout << "Your score :" << gameInfo.playerWinTimes << endl;
	cout << "Computer score :" << gameInfo.computerWinTimes << endl;
	cout << "Drow times :" << gameInfo.drowTimes << endl;


}



short playerChoice()
{
	short choice;
	do {
		cout << "\n\nPlayer 1\n";
		cout << "Enter your choic \n1_rock\n2_paper\n3_scissors" << endl;
		cout << "Your choice: ";
		cin >> choice;
	} while (choice != 1 && choice != 2 && choice != 3);

	return choice;
}

short player2Choice()
{
	short choice;
	do {
		cout << "\n\nPlayer 2\n";
		cout << "Enter your choic \n1_rock\n2_paper\n3_scissors" << endl;
		cout << "Your choice: ";
		cin >> choice;
	} while (choice != 1 && choice != 2 && choice != 3);

	return choice;
}



void saveInfo(stGameInfo& gameInfo, short player,short computer)
{
	stGameInfo roundResult;
	roundResult = theWinnerInRound(player, computer);

	printWinnerName_InRound(roundResult);


	gameInfo.playerWinTimes += roundResult.playerWinTimes;
	gameInfo.computerWinTimes += roundResult.computerWinTimes;
	gameInfo.drowTimes += roundResult.drowTimes;
	gameInfo.roundCounter++;
}

void roundByRoundMood(stGameInfo& gameInfo, bool secondPlayer = true)
{

	resetScreen();

	char yn;
	short player, computer;

	do {

		player = playerChoice();
		static_cast<enChoice>(player);


		if (secondPlayer)
		{
			computer = player2Choice();
			static_cast<enChoice>(computer);
		}

		else
		{
			computer = randomNumber(1, 3);
			static_cast<enChoice>(computer);
		}


		saveInfo(gameInfo, player, computer);


		cout << "Do you want play more ??.. Y/N" << endl;
		cin >> yn;

	} while (yn == 'Y' || yn == 'y');
}

void numberOfRoundsMood(stGameInfo& gameInfo, bool secondPlayer = true)
{

	resetScreen();

	short player, computer;
	short  num;
	cout << "Enter the number of round you want play" << endl;
	cin >> num;


	for (int i = 0; i < num; i++)
	{
		player = playerChoice();
		static_cast<enChoice>(player);


		if (secondPlayer)
		{
			computer = player2Choice();
			static_cast<enChoice>(computer);
		}

		else
		{
			computer = randomNumber(1, 3);
			static_cast<enChoice>(computer);
		}

		saveInfo(gameInfo, player, computer);
	}
}

void playGame(stGameInfo& gameInfo)
{


	short opponent;
	cout << "\nPress [1] to play with your friend\nPress [0] to play with computer" << endl;
	cin >> opponent;

	short mood;
	cout << "Enter the mood \n1_Press {1} to 'Round by round mood' \n2_Press {2} to 'Enter the number of rounds' mood" << endl;
	cin >> mood;

	cout << "\n";


	if (mood == 1)
	{
		roundByRoundMood(gameInfo, opponent);
	}

	else if (mood == 2)
	{
		numberOfRoundsMood(gameInfo, opponent);
	}

	else
	{
		resetScreen();

		cout << "Error" << endl;
	}



	gameOver(gameInfo);


	cout << "\n\n";
	playGame(gameInfo);

}




int main()
{

	srand((unsigned)time(NULL));

	stGameInfo gameInfo;

	playGame(gameInfo);


	return 0;

}