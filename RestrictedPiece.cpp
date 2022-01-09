#include "RestrictedPiece.h"

RestrictedPiece::RestrictedPiece(std::string color) : Piece(color), _moved(false) {

}

bool RestrictedPiece::hasMoved() const {
    return _moved;
}

bool RestrictedPiece::moveTo(Player &byPlayer, Square &to) {
    bool successfulMove = Piece::moveTo(byPlayer, to);
    // Only record status if this piece has not moved before
    if (!_moved) {
        _moved = successfulMove;
    }

    return successfulMove;
}
