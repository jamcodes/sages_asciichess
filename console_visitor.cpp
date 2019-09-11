#include "console_visitor.hpp"
#include "piece.hpp"
#include <cctype>
#include <unordered_map>
#include <iostream>

namespace {

// It's heavy solution :/
std::unordered_map<PieceType, char> pieceToChar = {
    {PieceType::Pawn,   'p'},
    {PieceType::Rook,   'r'},
    {PieceType::Knight, 'n'},
    {PieceType::Bishop, 'b'},
    {PieceType::King,   'k'},
    {PieceType::Queen,  'q'}
};

void showColumnName() {
    std::cout << "  ";
    for(auto col = 0U; col < ChessboardWidth; ++col) {
        std::cout << ' ' << static_cast<char>(col + 'a');
    }
    std::cout << '\n';
}

void showRowSeparator() {
    std::cout << "  ";
    auto row = ChessboardHeight;
    while(row--) {
        std::cout << "+-";
    }
    std::cout << "\n";
}

void showRow(const int * row, unsigned rowNumber) {
        std::cout << rowNumber + 1 << ' ';
        for(auto colNumber = 0U; colNumber < ChessboardWidth; ++colNumber) {
            auto field = row[colNumber];
            std::cout << '|';
            if(field == 0) {
                std::cout << ' ';
            } else {
                if(field > 100) {
                    std::cout << static_cast<char>(
                        std::toupper(pieceToChar[static_cast<PieceType>(field - 100)])
                        );
                } else {
                    std::cout << pieceToChar[static_cast<PieceType>(field)];
                }
            }
        }
        std::cout << "| " << rowNumber + 1 << '\n';
}

} // anonymous namespace

int ConsoleVisitor::fields[ChessboardHeight][ChessboardWidth];

void ConsoleVisitor::visit(const int tab[ChessboardHeight][ChessboardWidth]) {
    for(auto row = 0U; row < ChessboardHeight; ++row) {
        for(auto col = 0U; col < ChessboardWidth; ++col) {
            ConsoleVisitor::fields[row][col] = tab[row][col];
        }
    }
}

void ConsoleVisitor::show() {
    auto rowNumber = ChessboardHeight;
    showColumnName();
    while(rowNumber--) {
        showRowSeparator();
        showRow(ConsoleVisitor::fields[rowNumber], rowNumber);
    }
    showRowSeparator();
    showColumnName();
}
