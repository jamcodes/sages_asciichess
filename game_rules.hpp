#pragma once

// #include "position.hpp"

class Piece;
class Position;

class GameRules {
public:

    bool isValid(Piece const&, Position from, Position to) const;
private:
};