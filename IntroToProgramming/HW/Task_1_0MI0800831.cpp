#include <iostream>
using namespace std;

const int MAX_M = 6;
const int MAX_N = 1024;


bool isMValid(const int M)
{

	return (1 <= M && M <= MAX_M);
}

bool isNValid(const int N)
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

bool isCharInStr(const char c, const char* str)
{
	if (!str)
	{
		return false;
	}
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
	if (!str)
	{
		return true;
	}
		
	while (*str)
	{
		if (isCharInStr(*str, str + 1))
		{
			return false;
		}
		str++;
	}
	return true;
}

bool isCharDigit(const char c)
{
	return ('0' <= c && c <= '9');
}

bool isValidNumber(const char* str,const int M)
{
	if (!str)
	{
		return false;
	}
	unsigned lenStr = strLen(str);
	if (lenStr != M || !areAllDistinctCharsInStr(str))
	{
		return false;
	}
	while (*str)
	{
		if (!isCharDigit(*str))
		{
			return false;
		}
		str++;
	}
	return true;

}

bool areBullsAndCowsCountValid(const int bulls,const int cows,const int M)
{
	return (0 <= bulls && 0 <= cows && cows <= M - bulls);
}

bool getInput(int& M, int& N, char guesses[][MAX_M + 1], int* bulls, int* cows)
{
	cin >> M;
	if (!isMValid(M))
	{
		cout << "M is not valid";
		return false;
	}

	cin >> N;
	if (!isNValid(N))
	{
		cout << "N is not valid";
		return false;
	}

	for (int i = 0; i < N; i++)
	{
		if (!(cin >> guesses[i] >> bulls[i] >> cows[i]))
		{
			cout << "There are not enough lines";
			return false;
		}
		if (!isValidNumber(guesses[i], M))
		{
			cout << "Number in row " << i + 1 << " is not valid";
			return false;
		}
		if (!areBullsAndCowsCountValid(bulls[i], cows[i], M))
		{
			cout << "Bulls or cows count in row " << i + 1 << " is not valid";
			return false;
		}

	}
	return true;

}

int powOfTen(const int M) //10^M; 1 <= M
{
	int limit = 10;
	for (int i = 1; i < M; i++)
	{
		limit *= 10;
	}
	return limit;
}

void numToStrWithLeading0(const int M, int n, char* str)
{
	if (!str)
	{
		return;
	}

	str[M] = '\0';
	for (int i = M - 1; i >= 0; i--)
	{
		int lastDigit = n % 10;
		str[i] = lastDigit + '0';
		n /= 10;
		
	}
}

unsigned getBulls(const char* strNum1, const char* strNum2)
{
	if (!strNum1 || !strNum2)
	{
		return 0;
	}
	unsigned bulls = 0;
	while (*strNum1)
	{
		if (*strNum1 == *strNum2)
		{
			bulls++;
		}
		strNum1++;
		strNum2++;
	}
	return bulls;
}

unsigned getBullsAndCowsSum(const char* strNum1, const char* strNum2)
{
	if (!strNum1 || !strNum2)
	{
		return 0;
	}
	unsigned sum = 0;
	while (*strNum1)
	{
		if (isCharInStr(*strNum1, strNum2))
		{
			sum++;
		}
		strNum1++;
	}
	return sum;
}

void getBullsAndCows(const char* strNum1, const char* strNum2, unsigned& bulls, unsigned& cows)
{
	bulls = getBulls(strNum1, strNum2);
	cows = getBullsAndCowsSum(strNum1, strNum2) - bulls;

}


bool isSolution(const int N, const int* bulls, const int* cows, const char guesses[][MAX_M + 1], const char* candidate, size_t M)
{
	for (int i = 0; i < N; i++)
	{
		unsigned bulls_count = 0;
		unsigned cows_count = 0;
		getBullsAndCows(guesses[i], candidate, bulls_count, cows_count);
		if (!(bulls_count == bulls[i] && cows_count == bulls[i]))
		{
			return false;
		}
	}
	return true;
}

void solver(const int M, const int N, const int* bulls, const int* cows, const char guesses[][MAX_M + 1])
{
	int limit = powOfTen(M);
	for (int candidateNum = 0; candidateNum < limit; candidateNum++)
	{
		char candidate[MAX_M + 1] = "";
		numToStrWithLeading0(M, candidateNum, candidate);
		if (!isValidNumber(candidate, M))
		{
			continue;
		}
		if (isSolution(N, bulls, cows, guesses, candidate, M))
		{
			cout << candidate << " ";
		}
	}

}


int main()
{
	int M, N;
	char guesses[MAX_N][MAX_M + 1];
	int bulls[MAX_N];
	int cows[MAX_N];

	if (!getInput(M, N, guesses, bulls, cows))
	{
		return 1;
	}
	solver(M, N, bulls, cows, guesses);
}