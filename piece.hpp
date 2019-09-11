#pragma once

enum class PieceColor {
    Black,
    White
};

enum class PieceType {
    Pawn = 1,
    Rook,
    Knight,
    Bishop,
    King,
    Queen
};

class Piece {
public:
    Piece(PieceColor color, PieceType);
    PieceType getPieceType() const;
    PieceColor getPieceColor() const;
protected:
    const PieceColor color;
    const PieceType pieceType;
};
