#include <iostream>
#include <vector>
using namespace std;

// Algorithm that goes through an n*n board, and finds the biggest number in the column and the smallest in the row.

void print(vector<vector<int>> b) { // print the board
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < b[i].size(); j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}


bool isBiggerAndSmaller(vector<vector<int>> &b, int row, int col) { // boolean function that is trying find the biggest in column and smallest in row
    int num = b[row][col];
    int size = b.size();
    for (int i = 0; i < size; i++) {
        if (b[i][col] > num) { // if the loop number in the col is bigger than waldo return false
            return false;
        }
    }
    for (int j = 0; j < size; j++) {
        if (b[row][j] < num) { // if the loop number in the row is smaller than waldo return false
            return false;
        }
    }
    return true;
}

bool goThroughTheBoard(vector<vector<int>> &b) { // this function goes through the board, implements the above function, and if found, returns the result
    bool found = false;
    int size = b.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (isBiggerAndSmaller(b, i, j)){
                cout << "Waldo (" << b[i][j] << ") is at row " << i + 1 << " and column " << j + 1 << endl;
                found = true;
            }
        }
    }
    return found;
}

int main() {
    int size; // size of board
    string input; // Y/N input for later
    do {
        vector<vector<int>> b; // board

        cout << "Tell me the size of the board: ";
        cin >> size;
        while (size >= 100 || size <= 0) { // checks for valid range
            cout << "Error! Please enter a valid board range: ";
            cin >> size;
        }

        cout << "Give me the numbers: "; 
        for (int i = 0; i < size; i++) { // initializes the matrix
            vector<int> row1;
            for (int j = 0; j < size; j++) {
                int num;
                cin >> num;
                row1.push_back(num);
            }
            b.push_back(row1);
        }

        print(b); // prints the board
        if (!goThroughTheBoard(b)) { // if it doesn't find any number that the biggest in C and smalliest in R
            cout << "No solutions!" << endl;
        }

        cout << "Do you wish to try again? (y/n): ";
        cin >> input;
    } while (input == "y" || input == "Y");

    cout << "Terminating..." << endl;
    return 0;
}

