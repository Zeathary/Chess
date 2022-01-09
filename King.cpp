#include "King.h"
#include "Player.h"
#include "Board.h"

King::King(std::string color) : RestrictedPiece(color) {

}

bool King::canMoveTo(Square &location) const {
    // Return true if the King is only trying to move one square
    return Board::getBoard().distanceBetween(getLocation(), location) == 1;
}

int King::value() const {
    return 0;
}

void King::display(std::ostream &outStream) const {
    outStream << color() + "K";
}

bool King::inCheck(Player &opponent) const {
    bool check = false;

    // Loop through all opponents pieces and if any can move to the king he is in check
    for (Piece* piece : opponent.getPieces()) {
        if (!check && piece->canMoveTo(getLocation())) {
            check = true;
        }
    }

    return check;
}
