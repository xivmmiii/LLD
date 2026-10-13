#pragma once
#include <iostream>
#include "Symbol.hpp"

using namespace std;

class Player
{
private:
    int id;
    string name;
    Symbol symbol;
    int score;
    static int idCounter;

public:
    Player(string name, Symbol mark) : id(idCounter++), name(name), symbol(mark), score(0) {}
    string getName()
    {
        return name;
    }
    Symbol getSymbol()
    {
        return symbol;
    }
    int getScore()
    {
        return score;
    }
    void incrementScore()
    {
        score++;
    }
    pair<int, int> makeMove()
    {
        int row, col;
        cin >> row >> col;
        return {row, col};
    }
};