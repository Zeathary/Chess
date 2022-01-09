#include "Rook.h"
#include "Board.h"

Rook::Rook(std::string color) : RestrictedPiece(color) {

}

bool Rook::canMoveTo(Square &location) const {
    bool canMove = false;

    // Assess whether the rook is moving horizontally or vertically
    if (getLocation().getX() != location.getX() && getLocation().getY() == location.getY()) {

        // Does the rook have a clear path horizontally
        if (Board::getBoard().isClearHorizontal(getLocation(), location)) {
            canMove = true;
        }
    } else if (getLocation().getY() != location.getY() && getLocation().getX() == location.getX()){

        // Does the rook have a clear path vertically
        if (Board::getBoard().isClearVertical(getLocation(), location)) {
            canMove = true;
        }
    }

    return canMove;
}

/**
 * All Rooks have a value of 5
 * @return 5
 */
int Rook::value() const {
    return 5;
}

void Rook::display(std::ostream &outStream) const {
    outStream << color() + "R";
}
