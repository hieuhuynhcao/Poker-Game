#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

//I.1 Card shuffling & Dealing

//1.

void shuffleCards(int deck[][13]);

//2.

void printCardsShuffling(int deck[][13]);

//I.2 Card game: Five-card Poker
//1.
// a)

int **dealingForHand(int deck[][13]);

// b)

void printHand(int **hand, const char *suits[], const char *faces[]);

// c)

int **CreateHandTest(int deck[4][13], int a[]);
// d)

int isFourOfAKind(int **hand);

// e)

int isFullHouse(int **hand);

// f)

int isFlush(int **hand);

//g)

int isStraight(int **hand);

//h)

int isStraightFlush(int **hand);

//i)

int isThreeOfAKind(int **hand);

//j

int isTwoPairs(int **hand);

//k

int isPair(int **hand);

//l

void getHighestCard(int **hand, const char *suits[], const char *faces[]);

//2.

//a)

int ***dealingForHands(int deck[4][13], int n);
void PrintHands(int ***a, int n, const char *suits[], const char *faces[]);

//b)

int getStatusOfHand(int **hand);
void PrintgetStatusOfHand1(int **hand);

//c)

int *rankingHands(int ***hands, int n);
void PrintRankingHands(int *rankingHands, int player);

//d

int *evaluateHands(int *TotalScore, int player);

////////////////////////

int *ScorePerGame(int ***hands, int n);
void PrintTotalScore(int *rankingHands, int n, int s);
int *ZeroPoints(int n);
void Sort(int *a, int n);
void delete2DMatrix(int **a, int n);
void delete3DMatrix(int ***a, int n, int m);
int *TotalRanking(int *hands, int n);
