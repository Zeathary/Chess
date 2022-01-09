#include "Square.h"

Square::Square(int x, int y):
    _x(x), _y(y), _piece(nullptr) {}

void Square::setOccupier(Piece *piece) {
    _piece = piece;
    if (_piece) {
        _piece->setLocation(this);
    }

}

int Square::getX() const {
    return _x;
}

int Square::getY() const {
    return _y;
}

bool Square::occupied() const {
    return _piece != nullptr;
}

Piece &Square::occupiedBy() const {
    return *_piece;
}
