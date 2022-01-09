/**
 * Player.h
 * Handles the functionality of a chess player
 */
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <set>
#include "Piece.h"
#include "King.h"

class Player {
public:

    /**
     * Creates a new Player object with the specified name
     * @param name String name of the player
     */
    Player(std::string name);

    /**
     * Places the chess pieces into the correct starting position
     * @param pieces All Pieces this player owns
     */
    void setPieces(std::set<Piece*> &pieces);

    /**
     * Sets this players opponent
     * @param opponent Other player
     */
    void setOpponent(Player& opponent);

    /**
     * Sets the given King piece as this players King
     * @param king King for this player
     */
    void setKing(King& king);

    /**
     * Lets this player take their turn and move a piece
     * @return True if the move was completed successfully, false if not
     */
    bool makeMove();

    /**
     * Takes the piece of the board and adds it to this players captured pieces
     * @param piece Piece to capture
     */
    void capture(Piece& piece);

    /**
     * Returns this player's name
     * @return Name
     */
    std::string& getName() const;

    /**
     * Creates a score by totally all the values of the pieces this player has captured
     * @return This Player's score
     */
    int score() const;

    /**
     * Returns the pieces that this player controls
     * @return This player's pieces
     */
    std::set<Piece*>& getPieces() const;

    /**
     * Returns this player's opponent in the current chess match
     * @return The opponent
     */
    Player& getOpponent() const;

    /**
     * Returns this Player's king piece
     * @return The king
     */
    King& getKing() const;


private:
    std::string _name;
    Player* _opponent;
    std::set<Piece*> *_my_pieces;
    std::set<Piece*> _captured;
    King* _my_king;

    /**
     * Takes in String coordinates from user input and checks if they are on the chess board
     * @param location ex:"a1"
     * @return True if within a1-h8
     */
    bool validLocation(std::string location) const;

};
#endif
