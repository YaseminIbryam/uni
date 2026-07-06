#include <iostream>
using namespace std;

const int MAX_N = 100;
const int MAX_M = 1024;

bool isNValid(const int N)
{
	return (1 <= N && N <= 100);
}

bool isMValid(const int M)
{
	return (50 <= M && M <= 1024);
}

int convertCharToDigit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	return -1;
}

unsigned convertStrToUnsigned(const char* str)
{
	if (!str)
		return 0;

	unsigned result = 0;
	while (*str)
	{
		int digit = convertCharToDigit(*str);
		if (digit == -1)
			return 0;
		(result *= 10) += digit;
		str++;
	}
	return result;
}

int convertStrToSigned(const char* str)
{
	if (!str)
		return 0;

	if (*str == '-')
		return -1 * convertStrToUnsigned(str + 1);
	else
		return convertStrToUnsigned(str);
}

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

void strCopy(const char* source, char* dest)
{
	if (!source || !dest)
		return;
	while (*source)
	{
		*dest = *source;
		dest++;
		source++;
	}
	*dest = '\0';
}

void strCat(char* first, const char* second)
{
	if (!first || !second)
		return;

	size_t firstLen = strLen(first);
	first += firstLen;
	strCopy(second, first);
}

int getInput(int& N, int& M, char text[][MAX_M])
{
	char NText[MAX_M];
	cin >> NText;
	N = convertStrToSigned(NText);
	if (!isNValid(N))
	{
		cout << "N is not valid";
		return -1;
	}

	char MText[MAX_M];
	cin >> MText;
	M = convertStrToSigned(MText);
	if (!isMValid(M))
	{
		cout << "M is not valid";
		return -1;
	}
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		cin.getline(text[i], MAX_M);
		if (strComp(text[i], "$end$") == 0) // does $end$ count as a word ??
		{
			return i;
		}
		if (strLen(text[i]) > M)
		{
			cout << "Line " << i + 1 << " is too long.";
			return -1;
		}
	}
	return N;
}

//is <n> valid
bool isLineCountValid(const int lineNum, const int linesCount, const int N)
{
	if (lineNum == 0)
	{
		cout << "Invalid input." << endl;
		return false;
	}
	if (0 >= lineNum || lineNum > N)
	{
		cout << "Line " << lineNum << " is not valid.";
		return false;
	}
	if (lineNum > linesCount)
	{
		cout << "Line " << lineNum << " doesn't exist.";
		return false;
	}
	return true;
}

bool nInput(int& n, const int linesCount, const int N)
{
	if (!linesCount)
	{
		cout << "No lines available" << endl;
		n = -1;
		return false;
	}
	char n_text[MAX_M];
	do
	{
		cin >> n_text;
		n = convertStrToSigned(n_text);
	} while (!(isLineCountValid(n, linesCount, N)));
	return true;
}

//is <word> valid
bool isLineLenValid(const int lineLen, const int M)
{
	if (0 > lineLen || lineLen > M)
	{
		cout << "Length of the word/line is not valid" << endl;
		return false;
	}
	return true;
}

//deletes chars from the  start to (start + count)
void deleteChars(char* start, const int count)
{
	if (!start)
	{
		return;
	}
	int len = strLen(start);
	if (len > count)
	{
		char* end = start + count;
		while (*end)
		{
			*start = *end;
			start++;
			end++;
		}
	}
	*start = '\0';
}

//adds chars starting from start 
void addChars(char* start, const char* word, int lineLen, const int M, int lineNum)
{
	if (!start || !word)
	{
		return;
	}
	int wordLen = strLen(word);
	if (!isLineLenValid(lineLen + wordLen, M))
	{
		cout << "Not enough space in line " << lineNum << endl;
		return;
	}
	char copy[MAX_M];
	strCopy(start, copy);
	while (*word)
	{
		*start = *word;
		start++;
		word++;
	}
	char* copyPtr = copy;
	while (*copyPtr)
	{
		*start = *copyPtr;
		start++;
		copyPtr++;
	}
	*start = '\0';

}

bool isNewWord(const char* start, const char* current)
{
	if (*current == ' ' || !*current)
	{
		return false;
	}
	if (current == start)
	{
		return true;
	}
	const char* ptr = current - 1;
	if (*ptr == ' ')
	{
		return true;
	}
	return false;
}

bool isSameWord(const char* text, const char* target)
{
	while (*target && *target == *text)
	{
		target++;
		text++;
	}
	if (*target)
	{
		return false;
	}
	if (*text == ' ' || !*text)
	{
		return true;
	}
	return false;
}

//removes all target words from the line
void removeWordFromLine(char* textLine, const char* word)
{
	if (!textLine || !word)
	{
		return;
	}
	int wordLen = strLen(word);
	const char* start = textLine;
	char* current = textLine;
	while (*current)
	{
		if (isNewWord(start, current) && isSameWord(current, word))
		{
			char* charAfter = current + wordLen;
			if (*charAfter == ' ')
			{
				deleteChars(current, wordLen + 1);
			}
			else if (*charAfter == '\0' && current > start && *(current - 1) == ' ')
			{
				
				deleteChars(current - 1, wordLen + 1);
			}
			else
			{
				deleteChars(current, wordLen);
			}
			continue;
		}
		current++;
	}
}

void removeWord(const char* word, char text[][MAX_M], const int N, size_t M)
{
	for (int i = 0; i < N; i++)
	{
		removeWordFromLine(text[i], word);
	}
}

void overwriteWord(const char* source, char* dest)
{
	if (!source || !dest)
		return;
	while (*source)
	{
		*dest = *source;
		dest++;
		source++;
	}
}

void replaceWordInLIne(const char* word, const char* toReplace, char* textLine, const int M, const int lineNum)
{
	if (!word || !toReplace || !textLine)
	{
		return;
	}
	int lenWord = strLen(word);
	int lenToReplace = strLen(toReplace);
	char* start = textLine;
	char* current = textLine;
	while (*current)
	{
		if (isNewWord(start, current) && isSameWord(current, word))
		{
			int LineLen = strLen(textLine);
			if (!isLineLenValid(LineLen - lenWord + lenToReplace, M))
			{
				return;
			}
			if (lenWord < lenToReplace)
			{

				deleteChars(current, lenWord);
				addChars(current, toReplace, strLen(textLine), M, lineNum);
				
			}
			else
			{
				overwriteWord(toReplace, current);
				if (lenWord > lenToReplace)
				{
					deleteChars(current + lenToReplace, lenWord - lenToReplace);
				}
			}
			current += lenToReplace;
			continue;
		}

		current++;
	}

}


//replaces all occurances of the word wiht another word
void replaceWord(const char* word, const char* toReplace, char text[][MAX_M], const int M, const int linesCount, const size_t N)
{
	for (int i = 0; i < linesCount; i++)
	{
		replaceWordInLIne(word, toReplace, text[i], M, i + 1);
	}
}

//wordsCount in a line
int countLineWords(const char* lineText)
{
	if (!lineText)
	{
		return 0;
	}
	int count = 0;
	const char* start = lineText;
	while (*lineText)
	{
		if (isNewWord(start, lineText))
		{
			count++;
		}
		lineText++;
	}
	return count;
}

//wordsCount
int count(const char text[][MAX_M],const int linesCount, const size_t N, const size_t M)
{
	int count = 0;
	for (int i = 0; i < linesCount; i++)
	{
		count += countLineWords(text[i]);
	}
	return count;
}

//returns the count of the word in the line
int countWordInLine(const char* TextLine,const char* word)
{
	if (!TextLine || !word)
	{
		return 0;
	}
	const char* start = TextLine;
	const char* current = TextLine;
	int count = 0;
	while (*current)
	{
		if (isNewWord(start, current))
		{
			if (isSameWord(current, word))
			{
				count++;
			}
		}
		current++;
	}
	return count;
}

// how many times the word is written in the text
int countWord(const char text[][MAX_M], const int linesCount, const char* word, const size_t N, const size_t M)
{
	if (!word)
	{
		return 0;
	}
	int count = 0;
	for (int i = 0; i < linesCount; i++)
	{
		count += countWordInLine(text[i], word);
	}
	return count;
}

void getWord(const int M, char* word)
{
	//cin >> word; - ???
	char temp[MAX_M];
	cin >> temp;
	int len = strLen(temp);
	if (len > M)
	{
		cout << "Word is too long" << endl;
		temp[M] = '\0';
	}
	strCopy(temp, word);
}

//is first <i> valid
bool isTargetWordCountValid(const char text[][MAX_M], const int linesCount, const char* word, int ithTime, const size_t N, const size_t M)
{
	return (countWord(text, linesCount, word, M, N) >= ithTime && ithTime > 0);
}

void getFirstI(int& i, const char text[][MAX_M], const int linesCount, const char* word, const size_t N, const size_t M)
{
	if (!word)
	{
		return;
	}
	char iText[MAX_M];
	do
	{
		cin >> iText;
		i = convertStrToSigned(iText);
	} while (!(isTargetWordCountValid(text, linesCount, word, i, N, M)));
}

//prints the row in which the word is used for the i-th time
void lineByWord(const char text[][MAX_M], const char* word, const int linesCount, int ithTime, const size_t N, const size_t M)
{
	if (!word)
	{
		return;
	}
	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < linesCount; i++)
	{
		count1 = count2 + countWordInLine(text[i], word);
		if (count2 < ithTime && ithTime <= count1)
		{
			cout << text[i] << endl;
			return;
		}
		count2 = count1;
		
	}
}

//prints the line in which the word has most occurances
void lineByMostOccurances(const char* word, const char text[][MAX_M], const int linesCount, const size_t N, const size_t M)
{
	if (!word || !linesCount)
	{
		return;
	}
	int maxCount = -1;
	int maxCountIndex;
	for (int i = 0; i < linesCount; i++)
	{
		int countInLine = countWordInLine(text[i], word);
		if (maxCount < countInLine)
		{
			maxCount = countInLine;
			maxCountIndex = i;
		}
		
	}
	cout << text[maxCountIndex] << endl;
}

//prints the n line (starting from 1)
void printLine(const int n, const char text[][MAX_M], const size_t N, const size_t M)
{
	int i = n - 1;
	cout << text[i] << endl;
}

void getNewLine(char* newLine, const int M)
{
	int lenLine = -1;
	do
	{
		cin.getline(newLine, M);
		lenLine = strLen(newLine);
	} while (!isLineLenValid(lenLine, M));
}

void addLine(char text[][MAX_M], const int n, const char* newLine, int& linesCount, const int N, const size_t M)
{
	if (!newLine)
	{
		return;
	}
	if (linesCount >= N)
	{
		cout << "Too much lines";
		return;
	}
	for (int i = linesCount; i > n - 1; i--)
	{

		strCopy(text[i - 1], text[i]);
	}
	strCopy(newLine, text[n - 1]);
	linesCount++;
}


void changeLine(char text[][MAX_M], const int n, const char* newLine, const size_t N, const size_t M)
{
	strCopy(newLine, text[n - 1]);
}



void removeLine(char text[][MAX_M], const int n, int& linesCount, const size_t N, const size_t M)
{
	if (!linesCount)
	{
		return;
	}
	int index = n - 1;
	linesCount--;
	for (int i = index; i < linesCount; i++)
	{
		strCopy(text[i + 1], text[i]);
	}
	text[linesCount][0] = '\0';

}

void swapLines(char text[][MAX_M], const int a, const int b, const size_t N, const size_t M)
{
	int indexA = a - 1;
	int indexB = b - 1;
	char temp[MAX_M];
	strCopy(text[indexA], temp);
	strCopy(text[indexB], text[indexA]);
	strCopy(temp, text[indexB]);
}


void concatLines(char text[][MAX_M], int n, int count, int& linesCount, const int M, const size_t N)
{
	while (count)
	{
		if (n >= linesCount)
		{
			break;
		}
		char* first = text[n - 1];
		char* second = text[n];

		int lenFirst = strLen(first);
		int lenSecond = strLen(second);
		bool needSpace = false;
		if (lenFirst > 0 && first[lenFirst - 1] != ' ' && lenSecond > 0 && second[0] != ' ')
		{
			needSpace = true;
		}
		if (lenFirst + lenSecond + (needSpace ? 1 : 0) > M)
		{
			break;
		}
		if (needSpace)
		{
			first[lenFirst] = ' ';
			first[lenFirst + 1] = '\0';
		}

		strCat(first, second);
		removeLine(text, n + 1, linesCount, N, M);
		count--;
	}
}

int wordLen(const char* start)
{
	if (!start)
	{
		return 0;
	}
	int count = 0;
	while (*start && *start != ' ')
	{
		count++;
		start++;
	}
	return count;
}
void splitAt(char text[][MAX_M], int n, int i, int& linesCount, const int N, const size_t M)
{
	if (linesCount >= N)
	{
		cout << "Too much lines" << endl;
		return;
	}
	char* textLine = text[n - 1];
	const char* start = textLine;
	int wordCount = 0;
	while (*textLine)
	{
		if (isNewWord(start, textLine))
		{
			wordCount++;
			if (wordCount == i)
			{
				textLine += wordLen(textLine);
				if (!*textLine)
				{
					break;
				}
				bool skipSpace = false;
				if (*textLine == ' ')
				{
					textLine++;
					skipSpace = true;
				}
				addLine(text, n + 1, textLine, linesCount, N, M);
				if (skipSpace)
				{
					*(textLine - 1) = '\0';
				}
				else
				{
					*textLine = '\0';
				}
				break;
			}

		}
		textLine++;
	}
}

void doCommand(const char* command, char text[][MAX_M], int& linesCount, const int N, const int M)
{
	if (strComp(command, "count") == 0)
	{
		cout << count(text, linesCount, N, M) << endl;
	}
	else if (strComp(command, "countLines") == 0)
	{
		cout << linesCount << endl;
	}
	else if (strComp(command, "countLineWords") == 0)
	{
		int n = -1;
		if (nInput(n, linesCount, N))
		{
			cout << countLineWords(text[n - 1]) << endl;
		}
	}
	else if (strComp(command, "countWord") == 0)
	{
		char word[MAX_M];
		getWord(M, word);
		cout << countWord(text, linesCount, word, N, M) << endl;
	}
	else if (strComp(command, "lineByWord") == 0)
	{
		int i = 0;
		char word[MAX_M];
		getWord(M, word);
		getFirstI(i, text, linesCount, word, N, M);
		lineByWord(text, word, N, i, N, M);

	}
	else if (strComp(command, "lineByMostOccurances") == 0)
	{

		char word[MAX_M];
		getWord(M, word);
		lineByMostOccurances(word, text, linesCount, N, M);
	}
	else if (strComp(command, "printLine") == 0)
	{
		int n = -1;
		if (nInput(n, linesCount, N))
		{
			printLine(n, text, N, M);
		}
		
	}
	else if (strComp(command, "print") == 0)
	{
		for (int i = 1; i <= linesCount; i++)
		{
			printLine(i, text, N, M);
		}
	}
	else if (strComp(command, "removeWord") == 0)
	{
		char word[MAX_M];
		getWord(M, word);
		removeWord(word, text, linesCount, M);
	}
	else if (strComp(command, "replaceWord") == 0)
	{
		char word[MAX_M];
		char toReplace[MAX_M];
		getWord(M, word);
		getWord(M, toReplace);
		replaceWord(word, toReplace, text, M, linesCount, N);
		
	}
	else if (strComp(command, "addLine") == 0)
	{
		
		int n = 0;
		char nText[MAX_M];
		do
		{
			cin >> nText;
			n = convertStrToSigned(nText);
		} while (n <= 0);
		if (n > linesCount)
		{
			n = linesCount + 1;
		}
		cin.ignore();
		char newLine[MAX_M];
		getNewLine(newLine, M);
		addLine(text, n, newLine, linesCount, N, M);
	}
	else if (strComp(command, "changeLine") == 0)
	{
		int n = 0;
		if (nInput(n, linesCount, N))
		{
			cin.ignore();
			char newLine[MAX_M];
			getNewLine(newLine, M);
			changeLine(text, n, newLine, N, M);
		}
		
	}
	else if (strComp(command, "removeLine") == 0)
	{
		int n = 0;
		if (nInput(n, linesCount, N))
		{
			removeLine(text, n, linesCount, N, M);
		}
		

	}
	else if (strComp(command, "swapLines") == 0)
	{
		int a = 0;
		int b = 0;
		if (nInput(a, linesCount, N) && nInput(b, linesCount, N))
		{
			swapLines(text, a, b, N, M);
		}
		
	}
	else if (strComp(command, "concatLines") == 0)
	{
		int n = 0;
		int count = 0;
		char countText[MAX_M];
		if (nInput(n, linesCount, N))
		{
			do
			{
				cin >> countText;
				count = convertStrToSigned(countText);
			} while (count <= 0);
			concatLines(text, n, count, linesCount, M, N);
		}

	}
	else if (strComp(command, "splitAt") == 0)
	{
		int n = 0;
		int i = 0;
		char iText[MAX_M];
		if (nInput(n, linesCount, N))
		{
			do
			{
				cin >> iText;
				i = convertStrToSigned(iText);
			} while (i <= 0);
			splitAt(text, n, i, linesCount, N, M);
		}

	}
	else
	{
		cout << "Not a valid command" << endl;
	}
}

int main() {
	int N; //max lines
	int M; //max chars in a line
	char text[MAX_N][MAX_M];
	int lines = getInput(N, M, text);
	if (lines == -1)
	{
		return 1;
	}
	char command[MAX_M + 50];
	while (cin >> command)
	{
		doCommand(command, text, lines, N, M);
	}
}

