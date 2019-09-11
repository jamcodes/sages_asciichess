#pragma once

#include <array>
#include <memory>
#include "settings.hpp"

class Piece;
class ConsoleVisitor;

class Chessboard {
public:
    using container_t = std::array<std::array<std::unique_ptr<Piece>, ChessboardWidth>, ChessboardHeight>;

    Chessboard();
    ~Chessboard();  // defaulted in .cpp -> sizeof(Piece) isn't known here, but is known 
                    // in the implementation file, which includes piece.hpp

    void accept(ConsoleVisitor& visitor) const;

private:
    container_t fields;
};
