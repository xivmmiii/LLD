#pragma once
#include <iostream>
using namespace std;

class Symbol
{
private:
    char symbol;

public:
    Symbol()
    {
        this->symbol = '-';        
    }
    Symbol(char symbol)
    {
        this->symbol = symbol;
    }
    char getSymbol()
    {
        return symbol;
    }
    void setSymbol(char symbol){
        this->symbol = symbol;
    }


};