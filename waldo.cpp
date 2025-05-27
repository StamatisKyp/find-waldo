#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> b) {
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < b[i].size(); j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}


bool isBiggerAndSmaller(vector<vector<int>> &b, int row, int col) {
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

bool goThroughTheBoard(vector<vector<int>> &b) {
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
    int size;
    string input;
    vector <vector <int>> b;
    start: cout << "Tell me the size of the board: ";
    cin >> size;
    while (size >= 100 || size <= 0) {
        cout << "Error! Please enter a valid board range: ";
        cin >> size;
    }
    int arr[size][size];
    cout << "Give me the numbers: ";
    for (int i = 0; i < size; i++) {
        vector <int> row1;
        for (int j = 0; j < size; j++) {
            cin >> arr[i][j];
            row1.push_back(arr[i][j]);
        }
        b.push_back(row1);
    }
    print(b);
    if (!goThroughTheBoard(b)) {
        cout << "No solutions!" << endl;
    }
    cout << "Do you wish to try again? (y/n): ";
    cin >> input;
    if (input == "y" || input == "Y") {
        goto start;
    } else {
        cout << "Terminating...";
        return 0;
    }
    return 0;
}

