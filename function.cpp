#include "Function.h"

//I.1 Card shuffling & Dealing

//1.

void shuffleCards(int deck[][13])
{
	int row, col;

	for (int row = 0; row <= 3; row++)
	{
		for (int col = 0; col <= 12; col++)
		{
			deck[row][col] = 0;
		}
	}

	for (int card = 1; card <= 52; card++)
	{
		do
		{
			row = rand() % 4;
			col = rand() % 13;
		} while (deck[row][col] != 0);
		deck[row][col] = card;
	}
}

//2.

void printCardsShuffling(int deck[][13])
{
	const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	const char *rank[13] = {"Ace", "Deuce", "Three", "Four",
							"Five", "Six", "Seven", "Eight",
							"Nine", "Ten", "Jack", "Queen", "King"};

	for (int card = 1; card <= 52; card++)
	{
		for (int row = 0; row <= 3; row++)
		{
			for (int col = 0; col <= 12; col++)
			{
				if (deck[row][col] == card)
				{
					cout << "(" << suit[row] << ", " << rank[col] << ")" << endl;
				}
			}
		}
	}
}

//I.2 Card game: Five-card Poker
//1.
// a)

int **dealingForHand(int deck[][13])
{
	int **result = new int *[5];

	for (int i = 0; i < 5; i++)
		result[i] = new int[2];

	for (int i = 0, card = 1; i < 5 && card <= 17; i++, card += 4)
		for (int j = 0; j < 2; j++)
			for (int row = 0; row <= 3; row++)
				for (int col = 0; col <= 12; col++)
					if (deck[row][col] == card)
					{
						if (j)
							result[i][j] = col;
						else
							result[i][j] = row;
					}
	return result;
}

// b)

void printHand(int **hand, const char *suits[], const char *faces[])
{
	for (int i = 0; i < 5; i++)
	{
		cout << "(" << suits[hand[i][0]] << ", " << faces[hand[i][1]] << ")" << endl;
	}
}

//c)

int **CreateHandTest(int deck[4][13], int a[5])
{
	int **result = new int *[5];

	for (int i = 0; i < 5; i++)
		result[i] = new int[2];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 2; j++)
			for (int row = 0; row <= 3; row++)
				for (int col = 0; col <= 12; col++)
					if (deck[row][col] == a[i])
					{
						if (j)
							result[i][j] = col;
						else
							result[i][j] = row;
					}
	return result;
}

//d)

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void RankSorting(int **a)
{
	for (int i = 0; i < 5 - 1; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (a[i][1] > a[j][1])
			{
				swap(a[i][1], a[j][1]);
			}
		}
	}
}

int isFourOfAKind(int **hand)
{
	RankSorting(hand);

	if ((hand[0][1] == hand[1][1] && hand[1][1] == hand[2][1] && hand[2][1] == hand[3][1] && hand[3][1] != hand[4][1]) || (hand[1][1] == hand[2][1] && hand[2][1] == hand[3][1] && hand[3][1] == hand[4][1] && hand[4][1] != hand[0][1]))
		return 1;

	return 0;
}

//e)

int isFullHouse(int **hand)
{
	int count = 0;
	RankSorting(hand);
	for (int i = 0; i < 4; i++)
	{
		if (hand[i][1] == hand[i + 1][1])
			count++;
	}

	if (count == 3 && isFourOfAKind(hand) == 0)
		return 1;
	return 0;
}

//f)

int isFlush(int **hand)
{
	int count = 0;
	for (int i = 0; i < 5 - 1; i++)
	{
		if (hand[i][0] == hand[i + 1][0])
		{
			count++;
		}
	}
	if (count == 4)
		return 1;
	else
		return 0;
}

//g)

int isStraight(int **hand)
{
	int count = 0;
	RankSorting(hand);
	for (int i = 0; i < 5 - 1; i++)
	{

		if (abs(hand[i][1] - hand[i + 1][1]) == 1)
			count++;
	}
	if ((count == 4) && !isFlush(hand))
		return 1;
	else
		return 0;
}

//h)

int isStraightFlush(int **hand)
{
	if (isFlush(hand) && isStraight(hand))
	{
		return 1;
	}
	return 0;
}

//i)

int isThreeOfAKind(int **hand)
{
	int count = 0;
	RankSorting(hand);
	for (int i = 0; i < 5 - 1; i++)
	{
		if (hand[i][1] == hand[i + 1][1])
		{
			count++;
		}
	}
	if ((count == 2) && isTwoPairs(hand) == 0)
		return 1;
	return 0;
}

//j

int isTwoPairs(int **hand)
{
	int count = 0;
	for (int i = 0; i < 5 - 1; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (hand[i][1] == hand[j][1])
				count++;
		}
	}

	if (count == 2)
		return true;
	return false;
}

//k

int isPair(int **hand)
{
	int count = 0;
	for (int i = 0; i < 5 - 1; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (hand[i][1] == hand[j][1])
				count++;
		}
	}

	if (count == 1)
		return 1;
	return 0;
}

//l

void getHighestCard(int **hand, const char *suits[], const char *faces[])
{
	if ((isPair(hand) && isTwoPairs(hand) && isThreeOfAKind(hand) && isFlush(hand) && isStraight(hand) && isFullHouse(hand) && isFourOfAKind(hand)) == 0)
	{
		RankSorting(hand);
		cout << "Highest card: ";
		cout << faces[hand[4][1]] << endl;
	}
}

//2.

//a)

int ***dealingForHands(int deck[4][13], int n)
{
	int ***a = new int **[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new int *[5];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			a[i][j] = new int[2];
		}
	}

	for (int i = 0, card = 1; i < n; i++, card++)
	{
		for (int j = 0, Card_per_hand = card; j < 5; j++, Card_per_hand += n)
		{
			for (int k = 0; k < 2; k++)
			{
				for (int row = 0; row <= 3; row++)
				{
					for (int col = 0; col <= 12; col++)
					{
						if (deck[row][col] == Card_per_hand)
						{
							if (k)
								a[i][j][k] = col;
							else
								a[i][j][k] = row;
						}
					}
				}
			}
		}
	}
	return a;
}

void PrintHands(int ***a, int n, const char *suits[], const char *faces[])
{
	for (int i = 0; i < n; i++)
	{
		cout << "Player " << i + 1 << " :" << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "(" << suits[a[i][j][0]] << ", " << faces[a[i][j][1]] << ")" << endl;
		}
		cout << endl;
	}
}

//b)

int getStatusOfHand(int **hand)
{
	if (isStraightFlush(hand))
		return 8;
	else if (isFourOfAKind(hand))
		return 7;
	else if (isFullHouse(hand))
		return 6;
	else if (isFlush(hand))
		return 5;
	else if (isStraight(hand))
		return 4;
	else if (isThreeOfAKind(hand))
		return 3;
	else if (isTwoPairs(hand))
		return 2;
	else if (isPair(hand))
		return 1;
	else
		return 0;
}
void PrintgetStatusOfHand1(int **hand)
{
	if (isStraightFlush(hand))
		cout << "You got straight flush. 8 points" << endl;
	else if (isFourOfAKind(hand))
		cout << "You got four of a kind. 7 points" << endl;
	else if (isFullHouse(hand))
		cout << "You got full house. 6 points" << endl;
	else if (isFlush(hand))
		cout << "You got flush. 5 points" << endl;
	else if (isStraight(hand))
		cout << "You got straight. 4 points" << endl;
	else if (isThreeOfAKind(hand))
		cout << "You got three of a kind. 3 points" << endl;
	else if (isTwoPairs(hand))
		cout << "You got two pairs. 2 points" << endl;
	else if (isPair(hand))
		cout << "You got a pair. 1 points" << endl;
	else
		cout << "You got none of the above categories. 0 points" << endl;
}

//c)

int *rankingHands(int ***hands, int n)
{
	int *a = new int[n];
	int *b = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = getStatusOfHand(hands[i]);
		b[i] = i;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{
				swap(a[i], a[j]);
				swap(b[i], b[j]);
			}
		}
	}
	return b;
}

void PrintRankingHands(int *rankingHands, int player)
{
	for (int i = 0; i < player; i++)
	{
		cout << "Player "
			 << "\t" << rankingHands[i] + 1;
		cout << endl;
	}
}

//d)
int *evaluateHands(int *TotalScore, int player)
{
	int max = TotalScore[0];
	int index = 0, k = 0, count = 0;
	int *a = new int[player];
	for (int i = 1; i < player; i++)
	{
		if (max <= TotalScore[i])
		{
			max = TotalScore[i];
		}
	}
	for (int i = 0; i < player; i++)
	{
		if (TotalScore[i] == max)
		{
			index = i;
			a[k] = index;
			k++;
			count++;
		}
	}
	Sort(a, count);
	cout << "Congratulation player ";
	for (int i = 0; i < count; i++)
	{
		cout << a[i] + 1 << "  ";
	}
	cout << "Win the game /(>0<)/" << endl;
	return a;
}

/////////////////////////////////////////////////////

int *ScorePerGame(int ***hands, int n)
{
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = getStatusOfHand(hands[i]);
	}
	return a;
}

void PrintTotalScore(int *rankingHands, int n, int s)
{
	cout << "Round " << s << " : " << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "Player " << i + 1 << ": " << rankingHands[i] << "\t";
	}
}

int *ZeroPoints(int n)
{
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = 0;
	}
	return a;
}

void Sort(int *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}

int *TotalRanking(int *hands, int n)
{
	int *a = new int[n];
	int *b = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = hands[i];
		b[i] = i;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{
				swap(a[i], a[j]);
				swap(b[i], b[j]);
			}
		}
	}
	return b;
}

void delete2DMatrix(int **a, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;
}

void delete3DMatrix(int ***a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			delete[] a[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;
}

