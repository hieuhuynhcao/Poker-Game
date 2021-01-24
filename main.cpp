#include "Function.h"

void displaymenu()
{
	cout << "=========================="
		 << "\n";
	cout << " MENU "
		 << "\n";
	cout << "=========================="
		 << "\n";
	cout << " 1. 1 player.            *"
		 << "\n";
	cout << " 2. n players.           *"
		 << "\n";
	cout << " 3. Handtest             *"
		 << "\n";
	cout << " 0. Exit.                *"
		 << "\n";
	cout << "=========================="
		 << "\n";
}

int main()
{
	const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	const char *rank[13] = {"Ace", "Deuce", "Three", "Four",
							"Five", "Six", "Seven", "Eight",
							"Nine", "Ten", "Jack", "Queen", "King"};

	srand(time(0));
	int deck[4][13];

	displaymenu();
	int luachon;
	char confirm;
	do
	{
		cout << "\nEnter your choice (0 - 3): ";
		cin >> luachon;
		cout << endl;
		switch (luachon)
		{
		case 1:
		{
			shuffleCards(deck);
			printCardsShuffling(deck);

			cout << endl;

			int **result;
			result = dealingForHand(deck);
			printHand(result, suit, rank);
			cout << endl;

			if (isPair(result))
				cout << "a pair" << endl;
			else
				cout << "No one pair." << endl;

			if (isTwoPairs(result))
				cout << "Two pair" << endl;
			else
				cout << "No 2 pair." << endl;

			if (isThreeOfAKind(result))
				cout << "Three of a kind" << endl;
			else
				cout << "No three of a kind." << endl;

			if (isStraight(result))
				cout << "Straight" << endl;
			else
				cout << "No Straight." << endl;

			if (isFlush(result))
				cout << "Flush" << endl;
			else
				cout << "No Flush." << endl;

			if (isStraightFlush(result))
				cout << "Straight Flush" << endl;
			else
				cout << "No Straight Flush." << endl;

			if (isFourOfAKind(result))
				cout << "Four of a kind" << endl;
			else
				cout << "No Four of a kind." << endl;

			if (isFullHouse(result))
				cout << "Full House" << endl;
			else
				cout << "No Full House." << endl;

			getHighestCard(result, suit, rank);

			delete2DMatrix(result, 5);
		}
		break;
		case 2:
		{
			int ***Hands, *score_per_game, *Total_Score, *temp;
			int player, k = 1, time = 1;

			cout << "Enter the number of players: ";
			cin >> player;
			cout << endl;

			Total_Score = ZeroPoints(player);
			do
			{
				shuffleCards(deck);
				cout << "======Round " << time << "==============" << endl;
				Hands = dealingForHands(deck, player);
				PrintHands(Hands, player, suit, rank);
				cout << endl;

				cout << "Point of each player: " << endl;
				for (int i = 0; i < player; i++)
				{
					cout << "Player " << i + 1 << "\t";
					PrintgetStatusOfHand1(Hands[i]);
				}
				cout << endl;
				cout << "Ranking per round: " << endl;
				PrintRankingHands(rankingHands(Hands, player), player);
				cout << endl;

				score_per_game = ScorePerGame(Hands, player);

				for (int i = 0; i < player; i++)
				{
					Total_Score[i] += score_per_game[i];
				}
				cout << endl;

				cout << "Scoreboard after ";
				PrintTotalScore(Total_Score, player, time);
				cout << "\n\n\n";
				temp = Total_Score;
				cout << "Total Ranking: " << endl;
				PrintRankingHands(TotalRanking(temp, player), player);

				cout << "Press 1 to continue or 0 to end game ";
				cin >> k;
				cout << endl;
				if (k)
					time++;
			} while (k != 0);
			evaluateHands(Total_Score, player);

			delete[] score_per_game;
			delete[] Total_Score;
			delete3DMatrix(Hands, player, 5);
		}
		break;
		case 3:
		{
			int Card[5];
			shuffleCards(deck);
			cout << "Enter five card: ";
			for (int i = 0; i < 5; i++)
			{
				cin >> Card[i];
			}
			int **HandTest = CreateHandTest(deck, Card);
			printHand(HandTest, suit, rank);
		}
		break;
		case 0:
			return 0;
		default:
			cout << "Invalid.";
		}
		cout << endl;
		cout << "Enter y or Y to continue: ";
		cin >> confirm;
	} while (confirm == 'y' || confirm == 'Y');
}