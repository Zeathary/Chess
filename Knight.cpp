#include "Knight.h"

Knight::Knight(std::string color) : Piece(color) {

}

bool Knight::canMoveTo(Square &location) const {
    bool canMove = false;

    // A knight can only move either 2 spaces horizontally followed by 1 vertically
    // or 1 space horizontally followed by 2 vertically
    if (abs(getLocation().getX() - location.getX()) == 2
        && abs(getLocation().getY() - location.getY()) == 1) {

        canMove = true;

    } else if (abs(getLocation().getX() - location.getX()) == 1
               && abs(getLocation().getY() - location.getY()) == 2) {

        canMove = true;
    }

    return canMove;
}

/**
 * All Knights have a value of 3
 * @return 3
 */
int Knight::value() const {
    return 3;
}

void Knight::display(std::ostream &outStream) const {
    outStream << color() + "N";
}
