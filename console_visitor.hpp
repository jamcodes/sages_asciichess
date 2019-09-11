#pragma once

#include "settings.hpp"

class ConsoleVisitor {
public:
    static void visit(const int tab[ChessboardHeight][ChessboardWidth]);
    static void show();
private:
    static int fields[ChessboardHeight][ChessboardWidth];
};
