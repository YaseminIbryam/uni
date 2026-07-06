#include <iostream>
#include <random>
#include <stdlib.h>
using namespace std;


const unsigned OPTION_MAX = 100; //11
const unsigned MAX_N = 20;
const unsigned ACTION_MAX = 30; //6

int strComp(const char* first, const char* second)
{
	if (!first || !second)
		return 0;

	while ((*first) && ((*first) == (*second)))
	{
		first++;
		second++;
	}
	return (*first - *second);
}

void menu(char* option)
{
	bool isOptionValid = false;
	cout << "Start Game" << endl;
	cout << "Settings" << endl;
	cout << "Quit" << endl;
	while (!isOptionValid)
	{
		cin.getline(option, OPTION_MAX);
		if (strComp(option, "Start Game") == 0 ||
			strComp(option, "Settings") == 0 ||
			strComp(option, "Quit") == 0)
		{
			isOptionValid = true;
		}
		else 
		{
			cout << "Enter an option from above: ";
		}
	}
}

bool isNValid(const int N)
{
	return (3 <= N && N <= MAX_N);
}

bool isKValid(const int K)
{
	return (4 <= K && K <= 31);
}

void settings(int& N, int& K)
{
	do
	{
		cout << "Enter N (3-20): ";
		cin >> N;
	} while (!isNValid(N));
	do
	{
		cout << "Enter K (4-31): ";
		cin >> K;
	} while (!isKValid(K));
	cin.ignore(); //for /n after getLine
}

void getClearBoard(const int N, unsigned board[][MAX_N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] = 0;
		}
	}
}

void startingBoard(const int N, unsigned board[][MAX_N])
{
	getClearBoard(N, board);
    int row = std::rand() % N;
    int col = std::rand() % N;
	board[row][col] = 2;
}

unsigned getDigitsCount(unsigned n)
{
	if (!n)
		return 1;
	unsigned count = 0;

	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return count;
}

unsigned maxNumInTheBoard(const int N, const unsigned board[][MAX_N])
{
	unsigned maxNum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] > maxNum)
			{
				maxNum = board[i][j];
			}
		}
	}
	return maxNum;
}

void printSpaces(const unsigned spaceCount)
{
	for (unsigned i = 0; i < spaceCount; i++)
	{
		cout << " ";
	}
}

void printNumber(const int num, const unsigned maxDigitCount)
{
	unsigned digitCount = getDigitsCount(num);
	unsigned spacesNeeded = maxDigitCount - digitCount + 2;
	unsigned lastSpaces = spacesNeeded / 2;
	unsigned firstSpaces = spacesNeeded - lastSpaces;
	cout << "|";
	printSpaces(firstSpaces);
	cout << num;
	printSpaces(lastSpaces);
}

void printBoard(const int N, const unsigned board[][MAX_N])
{
	unsigned maxDigitCount = getDigitsCount(maxNumInTheBoard(N, board));

	for (int i = 0; i < N; i++)
	{
		
		for (int j = 0; j < N; j++)
		{
			printNumber(board[i][j], maxDigitCount);
		}
		cout << "|" << endl;
	}
}

void getAction(char* action)
{
	bool isActionValid = false;
	do
	{
		cin.getline(action, ACTION_MAX);
		if (strComp(action, "left") == 0 ||
			strComp(action, "right") == 0 ||
			strComp(action, "up") == 0 ||
			strComp(action, "down") == 0)
		{
			isActionValid = true;
		}
	} while (!isActionValid);
	

}

//pointers only
//void slide(const int N, unsigned* row)
//{
//	if (!row)
//	{
//		return;
//	}
//	unsigned* scanner = row;
//	unsigned* place = row;
//	int count = 0;
//	
//	for (int i = 0; i < N; i++)
//	{
//		if (*scanner)
//		{
//			*place = *scanner;
//			place++;
//			count++;
//		}
//		scanner++;
//	}
//	for (int i = count; i < N; i++)
//	{
//		*place = 0;
//		place++;
//	}
//}

void slide(const int N, unsigned* row)
{
	if (!row)
	{
		return;
	}

	int count = 0;

	for (int i = 0; i < N; i++)
	{
		if (row[i])
		{
			row[count] = row[i];
			count++;
		}
	}
	for (int i = count; i < N; i++)
	{
		row[i] = 0;
	}
}



//pointers only
//void merge(const int N, unsigned* row)
//{
//	if (!row)
//	{
//		return;
//	}
//	for (int i = 0; i < N - 1; i++)
//	{
//		if (*row == *(row + 1) && *row)
//		{
//			*row *= 2;
//			row++;
//			*row= 0;
//			i++;
//		}
//		row++;
//	}
//}

void merge(const int N, unsigned* row)
{
	if (!row)
	{
		return;
	}
	for (int i = 0; i < N - 1; i++)
	{
		if (row[i] == row[i + 1] && row[i])
		{
			row[i] *= 2;
			row[i + 1] = 0;
			i++;
		}
	}
}

void swap(unsigned& a, unsigned& b)
{
	int temp = a;
	a = b;
	b = temp;
}


//pointers only
//void reverseArr(const int N, unsigned* arr)
//{
//	if (!arr)
//	{
//		return;
//	}
//	unsigned* right = arr + N - 1;
//	for (int i = 0; i < N / 2; i++)
//	{
//		swap(*arr, *right);
//		arr++;
//		right--;
//
//	}	
//}

void reverseArr(const int N, unsigned* arr)
{
	if (!arr)
	{
		return;
	}
	for (int i = 0; i < N / 2; i++)
	{
		swap(arr[i], arr[N - i - 1]);
	}
		
}

//void columnToArr(const int N, const unsigned board[][MAX_N], unsigned* arr,const int col)
//{
//	if (!arr)
//	{
//		return;
//	}
//	for (int i = 0; i < N; i++)
//	{
//		*arr = board[i][col];
//		arr++;
//	}
//}

void columnToArr(const int N, const unsigned board[][MAX_N], unsigned* arr, const int col)
{
	if (!arr)
	{
		return;
	}
	for (int i = 0; i < N; i++)
	{
		arr[i] = board[i][col];
	}
}

//void arrToColumn(const int N, unsigned board[][MAX_N],const unsigned* arr, const int col)
//{
//	if (!arr)
//	{
//		return;
//	}
//	for (int i = 0; i < N; i++)
//	{
//		board[i][col] = *arr;
//		arr++;
//	}
//}

void arrToColumn(const int N, unsigned board[][MAX_N], const unsigned* arr, const int col)
{
	if (!arr)
	{
		return;
	}
	for (int i = 0; i < N; i++)
	{
		board[i][col] = arr[i];
	}
}

void doRow(const int N, unsigned* row)
{
	slide(N, row);
	merge(N, row);
	slide(N, row);
}

void copyBoard(const int N, const unsigned board[][MAX_N], unsigned copyOfBoard[][MAX_N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			copyOfBoard[i][j] = board[i][j];
		}
	}
}

bool compMatrix(const int N, const unsigned mat1[][MAX_N], const unsigned mat2[][MAX_N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (mat1[i][j] != mat2[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

unsigned sumOfAllNumbersInTheBoard(const int N, const unsigned board[][MAX_N])
{
	unsigned sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			sum += board[i][j];
		}
	}
	return sum;
}

void printScore(const int N, const unsigned board[][MAX_N])
{
	cout << "Score: " << sumOfAllNumbersInTheBoard(N, board) << endl;
}

void moveLeft(const int N, unsigned board[][MAX_N])
{
	for (int i = 0; i < N; i++)
	{
		doRow(N, board[i]);
	}
}

void moveRight(const int N, unsigned board[][MAX_N])
{
	for (int i = 0; i < N; i++)
	{
		reverseArr(N, board[i]);
		doRow(N, board[i]);
		reverseArr(N, board[i]);
	}
}

void moveUp(const int N, unsigned board[][MAX_N])
{
	unsigned column[MAX_N];
	for (int i = 0; i < N; i++)
	{
		columnToArr(N, board, column, i);
		doRow(N, column);
		arrToColumn(N, board, column, i);
	}
}

void moveDown(const int N, unsigned board[][MAX_N])
{
	unsigned column[MAX_N];
	for (int i = 0; i < N; i++)
	{
		columnToArr(N, board, column, i);
		reverseArr(N, column);
		doRow(N, column);
		reverseArr(N, column);
		arrToColumn(N, board, column, i);
	}
}

int get2or4()
{
	if (std::rand() % 10 == 4) //or any other digit
	{
		return 4;
	}
	return 2;
}

//void add2or4OnARandomPlace(const int N, int board[][MAX_N]) random but can take time vecause it checks every place (even if full)
//{
//	int row, col;
//	do
//	{
//		int row = std::rand() % N;
//		int col = std::rand() % N;
//	} while ((board[row][col]));
//	board[row][col] = get2or4();
//}
void add2or4OnARandomPlace(const int N, unsigned board[][MAX_N])
{
	const unsigned maxIndex = MAX_N * MAX_N;
	int emptyRows[maxIndex];
	int emptyCols[maxIndex];
	int* ptr1 = emptyRows;
	int* ptr2 = emptyCols;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!board[i][j])
			{
				*ptr1 = i;
				*ptr2 = j;
				ptr1++;
				ptr2++;
				count++;

			}
		}
	}
	if (count > 0)
	{
		int randomIndex = std::rand() % count;
		int r = emptyRows[randomIndex];
		int c = emptyCols[randomIndex];
		board[r][c] = get2or4();
	}
}

bool isThereValidMove(const int N, unsigned board[][MAX_N])
{	
	unsigned copy[MAX_N][MAX_N];
	copyBoard(N, board, copy);
	moveLeft(N, copy);
	if (!(compMatrix(N, board, copy)))
	{
		return true;
	}
	copyBoard(N, board, copy);
	moveRight(N, copy);
	if (!(compMatrix(N, board, copy)))
	{
		return true;
	}
	copyBoard(N, board, copy);
	moveUp(N, copy);
	if (!(compMatrix(N, board, copy)))
	{
		return true;
	}
	copyBoard(N, board, copy);
	moveDown(N, copy);
	if (!(compMatrix(N, board, copy)))
	{
		return true;
	}
	return false;
}

unsigned getWinningNum(const int K)
{
	unsigned winningNumber = 16;
	for (int i = 5; i <= K; i++)
	{
		winningNumber *= 2;
	}
	return winningNumber;
}

void startGame(const int N, const int K, unsigned board[][MAX_N])
{	
	bool end = false;
	unsigned winningNum = getWinningNum(K);
	char action[ACTION_MAX];
	unsigned copyOfBoard[MAX_N][MAX_N];
	system("cls");
	startingBoard(N, board);
	printBoard(N, board);

	while (!end)
	{
		getAction(action);
		copyBoard(N, board, copyOfBoard);
		if (strComp(action, "left") == 0)
		{
			moveLeft(N, board);
		}
		else if (strComp(action, "right") == 0)
		{
			moveRight(N, board);
		}
		else if (strComp(action, "up") == 0)
		{
			moveUp(N, board);
		}
		else if (strComp(action, "down") == 0)
		{
			moveDown(N, board);
		}
		if (!compMatrix(N, board, copyOfBoard))
		{
			add2or4OnARandomPlace(N, board);
			system("cls");
			printBoard(N, board);
			if (maxNumInTheBoard(N, board) >= (winningNum))
			{
				cout << "You won!" << endl;
				printScore(N, board);
				end = true;
			}
			else if (!isThereValidMove(N, board))
			{
				cout << "You lost!" << endl;
				printScore(N, board);
				end = true;
			}
		}
		
	}
}




int main()
{
	char option[OPTION_MAX];
	int N = 4;
	int K = 11;
	unsigned board[MAX_N][MAX_N];

	
	bool quitted = false;

	while (!quitted)
	{
		menu(option);
		if (strComp(option, "Start Game") == 0)
		{
			startGame(N, K, board);
		}
		else if (strComp(option, "Settings") == 0)
		{
			settings(N, K);
		}
		else if (strComp(option, "Quit") == 0)
		{
			quitted = true;
		}
	}
}