#include "Bishop.h"
#include "Board.h"

Bishop::Bishop(std::string color) : Piece(color) {

}

bool Bishop::canMoveTo(Square &location) const {
    bool canMove = false;
    // Is the location diagonal from the bishop
    if (getLocation().getX() != location.getX() && getLocation().getY() != location.getY()
        && abs(getLocation().getX() - location.getX()) == abs(getLocation().getY() - location.getY())) {
        // Does the bishop have a clear path to the location
        if (Board::getBoard().isClearDiagonal(getLocation(), location)) {
            canMove = true;
        }
    }

    return canMove;
}

/**
 * All bishops have a value of 3
 * @return 3
 */
int Bishop::value() const {
    return 3;
}

/**
 * Prints a 2 character representation of this piece
 * White is Represented by W and black by B
 * Bishops are represented by B
 * @param outStream
 */
void Bishop::display(std::ostream &outStream) const {
    outStream << color() + "B";
}
