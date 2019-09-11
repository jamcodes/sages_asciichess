#include "chessboard.hpp"
#include "piece.hpp"
#include "console_visitor.hpp"

namespace {

void makeRow(Chessboard::container_t::value_type& row, PieceColor color) {
    auto index = 0U;
    for(auto pieceType: {PieceType::Rook, PieceType::Knight,
                         PieceType::Bishop, PieceType::Queen,
                         PieceType::King, PieceType::Bishop,
                         PieceType::Knight, PieceType::Rook})
    {
        row[index++] = new Piece(color, pieceType);
    }
}

} // anonymous namespace

Chessboard::Chessboard()
    : fields{} {
    for(auto colNumber = 0U; colNumber < ChessboardWidth; ++colNumber) {
        fields[1][colNumber] = new Piece(PieceColor::White, PieceType::Pawn);
        fields[6][colNumber] = new Piece(PieceColor::Black, PieceType::Pawn);
    }
    makeRow(fields[0], PieceColor::White);
    makeRow(fields[7], PieceColor::Black);
}

Chessboard::~Chessboard() {
    for(auto &row: fields) {
        for(auto& field: row) {
            delete field;
        }
    }
}

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
