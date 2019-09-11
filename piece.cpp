#include "piece.hpp"
#include <unordered_map>
#include <cctype>

namespace {

} // anonymous namespace

Piece::Piece(PieceColor color_, PieceType pieceType_)
    : color{color_}, pieceType{pieceType_} {}

PieceType Piece::getPieceType() const {
    return pieceType;
}

PieceColor Piece::getPieceColor() const {
    return color;
}
