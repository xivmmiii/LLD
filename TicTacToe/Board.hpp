#pragma once
#include <iostream>
#include <vector>
#include "Symbol.hpp"
using namespace std;

class Board
{
private:
    int size;
    Symbol emptyCell;
    vector<vector<Symbol>> grid;

public:
    Board(int size) : size(size), emptyCell(), grid(size, vector<Symbol>(size, emptyCell)) {}

    bool isCellEmpty(int row, int col)
    {
        if (row < 0 || col < 0 || row >= size || col >= size)
        {
            cout << "Invalid position" << endl;
            return false;
        }
        return grid[row][col].getSymbol() == emptyCell.getSymbol();
    }

    void placeSymbol(int row, int col, Symbol symbol)
    {
        if (row < 0 || col < 0 || row >= size || col >= size || !isCellEmpty(row, col))
            return;
        grid[row][col].setSymbol(symbol.getSymbol());
    }

    void displayBoard()
    {
        cout << "\n";
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << grid[i][j].getSymbol() << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    int getSize()
    {
        return size;
    }
    char getCellSymbol(int row, int col)
    {
        if (row < 0 || col < 0 || row >= size || col >= size)
        {
            cout << "Invalid position" << endl;
            return '\0';
        }
        return grid[row][col].getSymbol();
    }
};
