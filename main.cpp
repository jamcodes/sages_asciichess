#include "chessboard.hpp"
#include "console_visitor.hpp"
#include "position.hpp"
#include "game_rules.hpp"
#include "piece.hpp"
#include <iostream>

int main() {
    // US 1
    Chessboard chessboard;
    ConsoleVisitor visitor;
    GameRules rules{};
    chessboard.accept(visitor);
    visitor.show();
    Position const from{'c', 2};
    Position const to{'c', 4};
    auto const& piece{chessboard.getPiece(from)};
    if (rules.isValid(piece, from, to) && chessboard.move(from, to)) {
        chessboard.accept(visitor);
        visitor.show();
    }
    else {
        std::cerr << "Dupa\n";
    }
}
