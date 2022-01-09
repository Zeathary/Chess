#include "Board.h"

/**
 * Returns the board object
 * If there is no current board create a new one
 * @return
 */
Board &Board::getBoard() {
    if (!_the_board) {
        _the_board = new Board();
    }
    return *_the_board;
}

Square &Board::squareAt(int x, int y) const {
    return (Square &) _squares.at(x).at(y);
}

/**
 * Takes in a location in the form a1 and returns the square at that location
 * Converts the string input given from players into the coordinates of the square in the vector
 * @param location
 * @return
 */
Square &Board::squareAt(std::string location) const {

    // switch letter coordinates to numbers
    char xLetter = location.at(0);
    char yLetter = location.at(1);

    return squareAt(xLetter - 'a', yLetter - '1');
}

int Board::distanceBetween(Square &from, Square &to) const {
    int distance = 0;

    // if the squares are diagonally located from each other only count the difference between one set of coordinates
    if (abs(from.getX() - to.getX()) == abs(from.getY() - to.getY())) {
        distance += abs(from.getX() - to.getX());
    } else {
        // Count the difference between coordinates of the two squares
        distance += abs(from.getX() - to.getX());
        distance += abs(from.getY() - to.getY());
    }



    return distance;
}

/**
 * Takes 2 locations that are located vertically from each other
 * and checks if all squares between them are clear of pieces
 * @param from starting location
 * @param to ending location
 * @return True if all squares between these two are unoccupied
 */
bool Board::isClearVertical(Square &from, Square &to) const {
    bool clear = true;
    bool headingUp = false;

    // If y coordinate is increasing it is heading up the board
    if (from.getY() < to.getY()) {
        headingUp = true;
    }

    // Check every square between from and to and ensure it is unoccupied
    for (int offset = 1; offset < distanceBetween(from, to); offset++) {
        int yCoordinate;

        if (headingUp) {
            yCoordinate = from.getY() + offset;
        } else {
            yCoordinate = from.getY() - offset;
        }

        if (squareAt(from.getX(), yCoordinate).occupied()) {
            clear = false;
        }
    }

    return clear;
}

/**
 * Takes 2 locations that are located vertically from each other
 * and checks if all squares between them are clear of pieces
 * @param from starting location
 * @param to ending location
 * @return True if all squares between these two are unoccupied
 */
bool Board::isClearHorizontal(Square &from, Square &to) const {
    bool clear = true;
    bool headingRight = false;

    // If Piece is heading to the right (coordinates increasing)
    if (from.getX() < to.getX()) {
        headingRight = true;
    }

    // Check that every square between this square and the location are unoccupied
    for (int offset = 1; offset < distanceBetween(from, to); offset++) {
        int xCoordinate;

        if (headingRight) {
            xCoordinate = from.getX() + offset;
        } else {
            xCoordinate = from.getX() - offset;
        }

        if (squareAt(xCoordinate, from.getY()).occupied()) {
            clear = false;
        }
    }

    return clear;

}

bool Board::isClearDiagonal(Square &from, Square &to) const {
    bool clear = true;
    // Assess the direction that the piece intends to move
    bool headingRight;
    bool headingUp;
    // Right
    if (from.getX() < to.getX()) {
        headingRight = true;
    } else {
        //LEFT
        headingRight = false;
    }

    // Up
    if (from.getY() < to.getY()) {
        headingUp = true;
    } else {
        // down
        headingUp = false;
    }

    for (int offset = 1; offset < distanceBetween(from, to); offset++) {
        int xCoordinate;
        int yCoordinate;

        if (headingRight) {
            xCoordinate = from.getX() + offset;
        } else {
            xCoordinate = from.getX() - offset;
        }

        if (headingUp) {
            yCoordinate = from.getY() + offset;
        } else {
            yCoordinate = from.getY() - offset;
        }

        if (squareAt(xCoordinate, yCoordinate).occupied()) {
            clear = false;
        }

    }

    // Loop through every square between from and to and check if it is clear
    return clear;
}

/**
 * Displays the entire chessboard to output
 * Calls the display() method from all pieces currently on the board
 * @param outStream
 */
void Board::display(std::ostream &outStream) const {
    // Title each column
    outStream << "     a    b    c    d    e    f    g    h\n";
    outStream << "   _______________________________________\n";

    // loop through every square and either print a blank space or the piece
    for (int row = _squares.size() - 1; row >= 0; row--) {
        // Label each row
        outStream << row + 1 << " | ";
        for (std::size_t col = 0; col < _squares.size(); col ++) {
            // If square is occupied tell piece to display
            if (squareAt(col, row).occupied()) {
                squareAt(col, row).occupiedBy().display(outStream);
            } else {
                // Otherwise print empty characters to keep spacing consistent
                outStream << "  ";
            }
            outStream << " | ";
        }
        outStream << row + 1 << "\n";
        outStream << "   _______________________________________\n";
    }

    outStream << "     a    b    c    d    e    f    g    h\n";
}

Board::Board() {
    for (int i = 0; i < _DIMENSION; i++) {
        std::vector<Square> v;
        for (int j = 0; j < _DIMENSION; j++) {
            Square s(i,j);
            v.push_back(s);
        }
        _squares.push_back(v);
    }
}

Board* Board::_the_board;




