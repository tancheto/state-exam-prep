#include <iostream>
#include <vector>
using namespace std;

struct ChessPosition {
	char letter;
	short digit;

	ChessPosition() {
		this->letter = 0;
		this->digit = 0;
	}

	ChessPosition(char l, short d) {
		this->letter = l;
		this->digit = d;
	}

	void print() {
		cout << letter << digit;
	}
};

class ChessPiece {
protected:
	ChessPosition position;

public:
	ChessPosition getPosition() {
		return this->position;
	}

	void setPosition(const ChessPosition &position) {
		this->position = position;
	}

	bool captures(ChessPosition pos) {
		vector<ChessPosition> moves = allowedMoves();

		for (int i = 0; i < moves.size(); i++) {
			if (moves[i].digit == pos.digit && moves[i].letter == pos.letter) {
				return true;
			}
		}

		return false;
	}

	virtual vector<ChessPosition> allowedMoves() = 0;

	virtual void iam() = 0;
};

class Rook : public ChessPiece {
public:
	vector<ChessPosition> allowedMoves() {
		vector<ChessPosition> moves;

		for (char xi = 'A'; xi <= 'H'; xi++) {
			if (xi != position.letter) {
				ChessPosition pos(xi, position.digit);
				moves.push_back(pos);
			}
		}

		for (short yi = 1; yi <= 8; yi++) {
			if (yi != position.digit) {
				ChessPosition pos(position.letter, yi);
				moves.push_back(pos);
			}
		}

		return moves;
	}
	void iam() {
		cout << "Rook";
	}
};

class Knight : public ChessPiece {
public:
	vector<ChessPosition> allowedMoves() {
		vector<ChessPosition> moves;

		for (char xi = 'A'; xi <= 'H'; xi++) {
			for (short yi = 1; yi <= 8; yi++) {
				if (abs(xi - position.letter) + abs (yi - position.digit) == 3
					&& xi != position.letter && yi != position.digit) {
					ChessPosition pos(xi, yi);
					moves.push_back(pos);
				}
			}
		}	

		return moves;
	}
	void iam() {
		cout << "Knight";
	}
};

void allMoves(ChessPiece* pieces, int count) {

	for (int i = 0; i < count; i++) {

		vector<ChessPosition> moves = pieces[i].allowedMoves();

		for (int p = 0; p < moves.size(); p++) {
			ChessPosition move = moves[p];
			if (move.digit >= 1 && move.digit <= 8 && move.letter >= 'A' && move.letter <= 'H') {

				for (int j = 0; j < count; j++) {
					if (j != i  && (move.digit != pieces[j].getPosition().digit || move.letter != pieces[j].getPosition().letter)) {

						pieces[i].iam();
						cout << " ";
						pieces[i].getPosition().print();
						cout << " -> ";
						move.print();
						cout << endl;
					}
				}
			}
		}
	}
}

int main() {

	Knight allPieces[2];

	ChessPosition pos1('A', 1);
	Knight r1;
	r1.setPosition(pos1);

	ChessPosition pos2('B', 3);
	Knight k1;
	k1.setPosition(pos2);

	allPieces[0] = r1;
	allPieces[1] = k1;

	allMoves(allPieces, 2);

/*	Rook allPieces[2];

	ChessPosition pos1('A', 1);
	Rook r1;
	r1.setPosition(pos1);

	ChessPosition pos2('B', 3);
	Rook k1;
	k1.setPosition(pos2);

	allPieces[0] = r1;
	allPieces[1] = k1;

	allMoves(allPieces, 2);
*/

	return 0;
}