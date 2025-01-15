#include <iostream>
#include "life.h"
using namespace std;

Life::Life(int rows, int cols) : maxrow(rows), maxcol(cols) {
    grid.resize(maxrow + 2, std::vector<int>(maxcol + 2));
}

void Life::set_dimensions(int rows, int cols) {
    maxrow = rows;
    maxcol = cols;
    grid.resize(maxrow + 2, std::vector<int>(maxcol + 2));
}

int Life::neighbor_count(int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++)
        for (int j = col - 1; j <= col + 1; j++)
            count += grid[i][j];
    count -= grid[row][col];
    return count;
}

void Life::update() {
    std::vector<std::vector<int>> new_grid(maxrow + 2, std::vector<int>(maxcol + 2));

    for (int row = 1; row <= maxrow; row++)
        for (int col = 1; col <= maxcol; col++)
            switch (neighbor_count(row, col)) {
            case 2:
                new_grid[row][col] = grid[row][col];
                break;
            case 3:
                new_grid[row][col] = 1;
                break;
            default:
                new_grid[row][col] = 0;
            }

    grid = new_grid;
}

void Life::initialize() {
    for (int row = 0; row <= maxrow + 1; row++)
        for (int col = 0; col <= maxcol + 1; col++)
            grid[row][col] = 0;
    cout << "List the coordinates for living cells." << endl;
    cout << "Terminate the list with the special pair -1 -1" << endl;
    int row, col;
    cin >> row >> col;

    while (row != -1 || col != -1) {
        if (row >= 1 && row <= maxrow)
            if (col >= 1 && col <= maxcol)
                grid[row][col] = 1;
            else
                cout << "Column " << col << " is out of range." << endl;
        else
            cout << "Row " << row << " is out of range." << endl;
        cin >> row >> col;
    }
}

void Life::print() {
    cout << "\nThe current Life configuration is:" << endl;
    for (int row = 1; row <= maxrow; row++) {
        for (int col = 1; col <= maxcol; col++)
            if (grid[row][col] == 1) cout << '*';
            else cout << ' ';
        cout << endl;
    }
    cout << endl;
}