#include "chessboard.hpp"
#include "console_visitor.hpp"

int main() {
    // US 1
    Chessboard chessboard;
    ConsoleVisitor visitor;
    chessboard.accept(visitor);
    visitor.show();
}
