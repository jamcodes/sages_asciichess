#include "game_rules.hpp"
#include "piece.hpp"
#include "position.hpp"

namespace
{
bool check_pawn_move(PieceColor color, Position from, Position to) noexcept
{
    auto const delta{from.compare(to)};
    if((color == PieceColor::White) && (from.getRowIndex() == 1) && (delta.second == 2))  {
        return true;
    } else if((color == PieceColor::Black) && (from.getRowIndex() == 6) && (delta.second == -2)) {
        return true;
    } // Move Pawn, one row
    else if((color == PieceColor::White) && (delta.second == 1)) {
        return true;
    } else if((color == PieceColor::Black) && (delta.second == -1)) {
        return true;
    }
    return false;
}
} // namespace


bool GameRules::isValid(Piece const& piece, Position from, Position to) const
{
    switch (piece.getPieceType())
    {
    case PieceType::Pawn:
        return check_pawn_move(piece.getPieceColor(), from, to);
    case PieceType::Rook:
        break;
    case PieceType::Knight:
        break;
    case PieceType::Bishop:
        break;
    case PieceType::King:
        break;
    case PieceType::Queen:
        break;
    default:
        break;
    }
    return true;
}
