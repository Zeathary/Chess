#include "Queen.h"
#include "Board.h"

Queen::Queen(std::string color) : Piece(color) {

}

bool Queen::canMoveTo(Square &location) const {
    bool canMove = false;

    // Is the location diagonal, horizontal, or vertical from the queen
    if (getLocation().getX() != location.getX() && getLocation().getY() != location.getY()
        && abs(getLocation().getX() - location.getX()) == abs(getLocation().getY() - location.getY())) {

        // Does the queen have a clear path diagonally
        if (Board::getBoard().isClearDiagonal(getLocation(), location)) {
            canMove = true;
        }
    } else if (getLocation().getX() != location.getX() && getLocation().getY() == location.getY()) {

        // Does the queen have a clear path horizontally
        if (Board::getBoard().isClearHorizontal(getLocation(), location)) {
            canMove = true;
        }
    } else if (getLocation().getY() != location.getY() && getLocation().getX() == location.getX()){

        // Does the queen have a clear path vertically
        if (Board::getBoard().isClearVertical(getLocation(), location)) {
            canMove = true;
        }
    }

    return canMove;
}

/**
 * All Queens have a value of 9
 * @return 9
 */
int Queen::value() const {
    return 9;
}

void Queen::display(std::ostream &outStream) const {
    outStream << color() + "Q";
}
