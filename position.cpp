#include "position.hpp"
#include "settings.hpp"
#include <string>
#include <stdexcept>
#include <iostream>


namespace
{
    using namespace std::string_literals;
    inline unsigned col_index(char ch)
    {
        const unsigned result{ch - 'a'};
        if (result > ChessboardWidth) {
            throw std::runtime_error{"Invalid column index"s + ch};
        }
        return result;
    }
} // namespace

Position::Position(char col, unsigned row)
    : row_{row-1}, col_{col_index(col)}
{
    if (row_ > ChessboardHeight) {
        throw std::runtime_error{"Invalid row index"s + std::to_string(row_)};
    }
    std::cerr << __FUNCTION__ << ": row = " << row_
        << ", col = " << col_ << "\n";
}

std::pair<int, int> Position::compare(Position other) const noexcept
{
    return {row_ - other.row_, col_ - other.col_};
}
