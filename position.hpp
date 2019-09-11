#pragma once

#include <utility>

class Position {
public:
    Position(char col, unsigned row);
    ~Position() = default;
    Position(Position const&) = default;
    Position(Position&& ) = default;
    Position& operator=(Position const&) = default;
    Position& operator=(Position&&) = default;

    inline unsigned getRowIndex() const noexcept { return row_; }
    inline unsigned getColIndex() const noexcept { return col_; }
    std::pair<int, int> compare(Position other) const noexcept;
private:
    unsigned row_;
    unsigned col_;
};
