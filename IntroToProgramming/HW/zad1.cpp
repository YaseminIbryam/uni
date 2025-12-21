#include <iostream>
using namespace std;

const int MAX_M = 6;
const int MAX_N = 1024;

void getInput()
{
	int M; //digitsCount
    int N;
    cin >> M >> N;
    
	char guess[MAX_N][MAX_M + 1]; 
    int bulls[MAX_N];
    int cows[MAX_N];
    for (int i = 0; i < N; i++)
    {

        cin >> guess[i] >> bulls[i] >> cows[i];

    }
}

bool isMValid(int M) 
{

    return (1 <= M && M <= MAX_M);
}

bool isNValid(int N)
{
	return (1 <= N);
}

unsigned strLen(const char* str)
{
	if (!str)
		return 0;

	unsigned result = 0;
	while (*str)
	{
		result++;
		str++;
	}
	return result;
}
//какво правим ако N e различно от подадените входове примерно 
//4 
//1(вместо 2)/3(вместо 2)
//1234 1 1 
//5314 2 1

bool isCharInStr(char c, const char* str) 
{
	while (*str)
    	{
        	if (c == *str)
            	return true;
        	str++;
    	}
    return false;
}

bool areAllDistinctCharsInStr(const char* str)
{
	while(*str)
	{
		if (isCharInStr(*str, str + 1))
		{
			return false;
		}
		str++;
	}
	return true;
}

bool isCharDigit(char c)
{
	return ('0' <= c && c <= '9');
}

bool isValidNumber(const char* str, unsigned lenStr, int M)
{
	if (lenStr != M || !areAllDistinctCharsInStr(str)) //грешка ??
	{
		return false;
	}
	while(*str)
	{
		if(!isCharDigit(*str))
		{
			return false;
		}
		str++;
	}
	return true;

}

bool areBullsAndCowsCountValid(int bulls, int cows, int M)
{
    return (0 <= bulls && 0 <= cows && cows <= M - bulls);
}

void validation(int M, int N, const char guess[][MAX_M + 1], const int* bulls, const int* cows )
{
	if (!isMValid(M))
	{
		cout << "M is not valid";
	}
	if (!isNValid(N))
	{
		cout << "N is not valid";
	}
	//оправи тези, трябва за всеки ред да е проверката
	for (i)
	else if (!(areAllDistinctCharsInStr() && isStrLenCorrect()))
	{
		cout << "The number is not valid";
	}
	else if (!(areBullsAndCowsCountValid()))
	{
		cout << "Count of bulls or cows is not valid";
	}
}


int main() 
{
	getInput();

}