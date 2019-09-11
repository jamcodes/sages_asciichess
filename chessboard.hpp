#pragma once

#include <array>
#include "settings.hpp"

class Piece;
class ConsoleVisitor;

class Chessboard {
public:
    using container_t = std::array<std::array<Piece *, ChessboardWidth>, ChessboardHeight>;

    Chessboard();
    ~Chessboard();

    void accept(ConsoleVisitor& visitor) const;

private:
    container_t fields;
};
