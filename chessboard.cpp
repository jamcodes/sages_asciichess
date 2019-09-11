#include "chessboard.hpp"
#include "piece.hpp"
#include "position.hpp"
#include "console_visitor.hpp"
#include "game_rules.hpp"

namespace {

void makeRow(Chessboard::container_t::value_type& row, PieceColor color) {
    auto index = 0U;
    for(auto pieceType: {PieceType::Rook, PieceType::Knight,
                         PieceType::Bishop, PieceType::Queen,
                         PieceType::King, PieceType::Bishop,
                         PieceType::Knight, PieceType::Rook})
    {
        row[index++] = std::make_unique<Piece>(color, pieceType);
    }
}

} // anonymous namespace

Chessboard::Chessboard()
    : fields{} {
    for(auto colNumber = 0U; colNumber < ChessboardWidth; ++colNumber) {
        fields[1][colNumber] = std::make_unique<Piece>(PieceColor::White, PieceType::Pawn);
        fields[6][colNumber] = std::make_unique<Piece>(PieceColor::Black, PieceType::Pawn);
    }
    makeRow(fields[0], PieceColor::White);
    makeRow(fields[7], PieceColor::Black);
}

Chessboard::~Chessboard() = default;

void Chessboard::accept(ConsoleVisitor& visitor) const {
    auto rowNumber = ChessboardHeight;
    int table[ChessboardHeight][ChessboardWidth];
    while(rowNumber--) {
        for(auto colNumber = 0U; colNumber < ChessboardWidth; ++colNumber) {
            auto& field = fields[rowNumber][colNumber];
            if(field == nullptr) {
                table[rowNumber][colNumber] = 0;
            } else {
                int value = static_cast<int>(field->getPieceType());
                if(field->getPieceColor() == PieceColor::White) {
                    value += 100;
                }
                table[rowNumber][colNumber] = value;
            }
        }
    }
    visitor.visit(table);
}

Piece const& Chessboard::getPiece(Position position) const
{
    auto const& piece{fields[position.getRowIndex()][position.getColIndex()]};
    if (nullptr == piece) {
        throw std::runtime_error{"Invalid piece position"};
    }
    return *piece;
}

bool Chessboard::move(Position from, Position to)
{
    auto& from_field{fields[from.getRowIndex()][from.getColIndex()]};
    auto& to_field{fields[to.getRowIndex()][to.getColIndex()]};
    if (from_field == nullptr || to_field != nullptr) {
        return false;
    }
    std::swap(from_field, to_field);
    return true;
}
