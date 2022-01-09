#include "Player.h"
#include "Board.h"
#include "Piece.h"

Player::Player(std::string name):
    _name(name), _opponent(nullptr), _my_pieces(nullptr),
    _captured(std::set<Piece*>()), _my_king(nullptr) {
}

void Player::setPieces(std::set<Piece *> &pieces) {
    _my_pieces = &pieces;
}

void Player::setOpponent(Player &opponent) {
    _opponent = &opponent;
}

void Player::setKing(King &king) {
    _my_king = &king;
}

bool Player::makeMove() {

    bool moveCompleted = false;
    // Use strings White  and Black to prompt for input
    std::string color;
    if (this->getKing().color() == "W") {
        color = "White";
    } else {
        color = "Black";
    }

    // Take input until a valid input is given and a move can be completed.
    do {
        std::cout << color << " enter move: ";
        std::string move;
        std::getline(std::cin, move);

        std::string start = move.substr(0, 2);
        std::string end = move.substr(3, 2);

        // Test input for legitimacy, should be between a1 - h8
        if (validLocation(start) && validLocation(end)) {
            // There should be a piece located on starting square
            Board& currentBoard = Board::getBoard();
            if (currentBoard.squareAt(start).occupied()) {
                // Attempt to move piece
                moveCompleted = currentBoard.squareAt(start).occupiedBy().moveTo(*this, currentBoard.squareAt(end));
            }
        }

        // Notify the player of invalid moves
        if (!moveCompleted) {
            std::cout << "Invalid Move\n";
        }

        // if piece successfully completes move given, exit loop and return true
    } while (!moveCompleted);

    // If opponents king is placed in check by this move announce it
    if (getOpponent().getKing().inCheck(*this)) {
        std::cout << "Check\n";
    }

    return moveCompleted;
}

void Player::capture(Piece &piece) {
    _captured.insert(&piece);
}

std::string &Player::getName() const {
    return (std::string &) _name;
}

int Player::score() const {
    int score = 0;

    for (auto piece : _captured) {
        score += piece->value();
    }
    return score;
}

std::set<Piece *> &Player::getPieces() const {
    return *_my_pieces;
}

Player &Player::getOpponent() const {
    return *_opponent;
}

King &Player::getKing() const {
    return *_my_king;
}

bool Player::validLocation(std::string location) const {
    bool validX = false;
    bool validY = false;

    // Locations should be given in the form a1
    if (location.length() == 2) {
        // switch letter coordinates to numbers
        char xCoordinate = location.at(0);

        switch (xCoordinate) {
            case 'a':
                validX = true;
                break;
            case 'b':
                validX = true;
                break;
            case 'c':
                validX = true;
                break;
            case 'd':
                validX = true;
                break;
            case 'e':
                validX = true;
                break;
            case 'f':
                validX = true;
                break;
            case 'g':
                validX = true;
                break;
            case 'h':
                validX = true;
                break;
        }

        char yCoordinate = location.at(1);

        // Check that the yCoordinate given is a number less than or equal to 8
        if (std::isdigit(yCoordinate)) {
            int y = yCoordinate - '0';
            if (y <= 8) {
                validY = true;
            }

        }
    }
    return validX && validY;
}




