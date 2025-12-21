#include <iostream>
using namespace std;


bool checkCollumn(char arr[][5], size_t collumns, char* str) {
    for(int i = 0; i < collumns; i++) {
        int equalCount = 0;
        for (int j = 0; j < collumns; j++) {
            if (arr[j][i] == str[j]) {
                equalCount++;
            }

        }
        if (equalCount == 5){
            return true;
        }
    }
    return false;
}
bool checkRow(char arr[][5], size_t rows, char* str) {
    for(int i = 0; i < rows; i++) {
        int equalCount = 0;
        for (int j = 0; j < rows; j++) {
            if (arr[i][j] == str[j]) {
                equalCount++;
            }

        }
        if (equalCount == 5){
            return true;
        }
    }
    return false;
}

int main() {
    const int collumns = 5;
    const int rows = 5;
    char arr[rows][collumns] = 
    {
        {'1', '2', '3', '4', '5'},  
        {'6', '7', '8', '9', 'a'},  
        {'b', 'c', 'd', 'e', 'f'},
        {'g', 'h', 'i', 'j', 'k'},
        {'l', 'm', 'n', 'o', 'p'}
    };
    char str[] = "12345";
    cout << checkCollumn(arr, collumns, str);
    cout << checkRow(arr, rows, str);
}