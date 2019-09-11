#pragma once

#include <array>
#include <memory>
#include "piece.hpp"
#include "settings.hpp"

class Piece;
class ConsoleVisitor;

class Chessboard {
public:
    using container_t = std::array<std::array<std::unique_ptr<Piece>, ChessboardWidth>, ChessboardHeight>;

    Chessboard();

    void accept(ConsoleVisitor& visitor) const;

private:
    container_t fields;
};
