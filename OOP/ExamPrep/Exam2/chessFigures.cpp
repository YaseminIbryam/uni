#include <iostream>
#include <vector>
using namespace std;


struct ChessPosition {
    char col;
    int row;
};


class ChessPiece {
public:
    ChessPiece(ChessPosition position) : position(position){}

    virtual ~ChessPiece() {}

    ChessPosition getPosition(){
        return position;
    }

    virtual vector<ChessPosition> allowedMoves() = 0;

    bool wins(ChessPosition p) {
        vector<ChessPosition> moves = allowedMoves();
        for (ChessPosition i: moves)
        {
            if (i.col == p.col && i.row == p.row) {
                return true;
            }
        }
        return false;
    }

    
private:
    ChessPosition position;
};


class Rook: public ChessPiece {
public:
    Rook(ChessPosition position) : ChessPiece(position){}
    virtual vector<ChessPosition>   allowedMoves() final{
        ChessPosition pos = getPosition();
        vector<ChessPosition> moves;
        ChessPosition allowedMove;
        allowedMove.col = pos.col;
        for(int i = 1; i <= 8; i++) {
            if (i == pos.row) {
                continue;
            }
            allowedMove.row = i;
            moves.push_back(allowedMove);
        }
        allowedMove.row = pos.row;
        for(char i = 'A'; i <= 'H'; i++) {
            if (i == pos.col) {
                continue;
            }
            allowedMove.col = i;
            moves.push_back(allowedMove);
        }
        return moves;
    }
private:
};

main() {
    ChessPosition pos;
    pos.col = 'E';
    pos.row = 5;

    ChessPiece* figure = new Rook(pos);

    vector<ChessPosition> moves = figure->allowedMoves();

    for (ChessPosition move : moves)
    {
        cout << move.col << move.row << "  ";
    }
    cout << "\n";
    delete[] figure;
}