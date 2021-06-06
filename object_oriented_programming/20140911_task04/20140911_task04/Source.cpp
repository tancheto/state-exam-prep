#include <iostream>
#include <vector>
using namespace std;

const int N = 5;
const int GameBoard[N][N] = {
	{1,1,0,2,0},
	{0,2,1,0,2},
	{2,'S',2,2,1},
	{0,2,2,2,0},
	{'K',2,1,1,1}
};

struct Point {
	int x;
	int y;

	void printPoint() {
		cout << "(" << x << "," << y << ")";
	}
};

class GamePlayer {
protected:
	Point position;
public:

	GamePlayer(int x, int y) {
		position.x = x;
		position.y = y;
	}

	Point getPosition() {
		return this->position;
	}

	void setPosition(const Point & point) {
		this->position = point;
	}

	bool isNeighbour(Point p) {
		return abs(position.x - p.x) <= 1 && abs(position.y - p.y) <= 1;
	}

	virtual vector<Point> allowedMoves() = 0;

	virtual void iam() = 0;
};

class Knight : public GamePlayer {
public:

	Knight(int x, int y) : GamePlayer(x, y){
		
	}

	vector<Point> allowedMoves() {

		vector<Point> moves;

		for (short dx = -1; dx <= 1; dx++) {
			for (short dy = -1; dy <= 1; dy++) {
				if ((dx != 0 || dy != 0) && 
					(position.x + dx >= 0 && position.x + dx < N && position.y + dy >= 0 && position.y + dy < N) &&
					checkPos(this->position.x + dx, this->position.y + dy)) {
					Point newMove;
					newMove.x = this->position.x + dx;
					newMove.y = this->position.y + dy;

					moves.push_back(newMove);
				}
			}
		}

		return moves;
	}

	bool checkPos(int x, int y) {
		return GameBoard[x][y] == 0 && !isFireNeighbour(x, y);
	}

	bool isFireNeighbour(int x, int y) {
		for (short dx = -1; dx <= 1; dx++) {
			for (short dy = -1; dy <= 1; dy++) {
				if (x + dx >= 0 && x + dx < N && y + dy >= 0 && y + dy < N) {
					if (GameBoard[x + dx][y + dy] == 1) {
						return true;
					}
				}
			}
		}
		return false;
	}

	void iam() {
		cout << "Knight";
	}
};

class SeaMonster : public GamePlayer {
public:

	SeaMonster(int x, int y) : GamePlayer(x, y) {

	}

	vector<Point> allowedMoves() {

		vector<Point> moves;

		for (int dx = -1; dx > -N; dx--) {
			if (dx + position.x < 0	|| GameBoard[dx + position.x][position.y] != 2) {
				break;
			}

			Point newMove;
			newMove.x = dx + position.x;
			newMove.y = position.y;

			moves.push_back(newMove);
		}

		for (int dx = 1; dx < N; dx++) {
			if (dx + position.x >= N || GameBoard[dx + position.x][position.y] != 2) {
				break;
			}

			Point newMove;
			newMove.x = dx + position.x;
			newMove.y = position.y;

			moves.push_back(newMove);
		}

		for (int dy = -1; dy > -N; dy--) {
			if (dy + position.y < 0	|| GameBoard[position.x][dy + position.y] != 2) {
				break;
			}

			Point newMove;
			newMove.x = position.x;
			newMove.y = dy + position.y;

			moves.push_back(newMove);
		}

		for (int dy = 1; dy < N; dy++) {
			if (dy + position.y >= N || GameBoard[position.x][dy + position.y] != 2) {
				break;
			}

			Point newMove;
			newMove.x = position.x;
			newMove.y = dy + position.y;

			moves.push_back(newMove);
		}

		return moves;
	}

	void iam() {
		cout << "SeaMonster";
	}
};

void allMoves(GamePlayer** players, int numPlayers) {
	for (int i = 0; i < numPlayers; i++) {
		GamePlayer* curPlayer = players[i];
		vector<Point> curAllowedMoves = curPlayer->allowedMoves();

		for (int m = 0; m < curAllowedMoves.size(); m++) {
			for (int j = 0; j < numPlayers; j++) {
				if (i != j && players[j]->isNeighbour(curAllowedMoves[m])) {
					curPlayer->iam();
					cout << " ";
					curPlayer->getPosition().printPoint();
					cout << " -> ";
					curAllowedMoves[m].printPoint();
					cout << endl;
				}
			}
		}
	}
}

int main() {

	GamePlayer* knight = new Knight(4, 0);
	GamePlayer* seaMonster = new SeaMonster(2, 1);

	GamePlayer* players[2];
	players[0] = knight;
	players[1] = seaMonster;

	allMoves(players, 2);

	delete knight;
	delete seaMonster;

	return 0;
}