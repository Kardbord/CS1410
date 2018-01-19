#include "PerfectPlayer.h"
#include<vector>
#include<algorithm>

PerfectPlayer::PerfectPlayer(Board::Player player):
Player(player)
{
}

std::vector<Board> makeBoards(Board board, Board::Player p) {
	std::vector<Board> boards;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (board(i, j) == Board::EMPTY)
			{
				boards.push_back(board.move(i, j, p));
			}
		}
	}
	return boards;
}

int getScore(Board board, Board::Player p, int depth) {
	Board::Player o;
	if (p == Board::PLAYER_X) {
		o = Board::PLAYER_O;
	}
	else {
		o = Board::PLAYER_X;
	}
	if (board.winner() == p) return 10 - depth;
	if (board.winner() == o) return -10 + depth;
	else return 0;
}

int minmax(Board & board, Board & b2, Board::Player p, bool pTurn, int depth) {
	if (!board.movesRemain()) return getScore(board, p, depth);
	Board::Player a;
	if ((p == Board::PLAYER_X && pTurn) || (p == Board::PLAYER_O && !pTurn)) a = Board::PLAYER_X;
	else a = Board::PLAYER_O;
	auto possBoards = makeBoards(board, a);
	std::vector<int> scores;
	for (auto&& b : possBoards) {
		scores.push_back(minmax(b, b2, p, !pTurn, depth+1));
	}
	if (pTurn) {
		auto i = std::max_element(scores.begin(), scores.end());
		int d = std::distance(scores.begin(), i);
		b2 = possBoards[d];
		return scores[d];
	}
	else {
		auto i = std::min_element(scores.begin(), scores.end());
		int d = std::distance(scores.begin(), i);
		b2 = possBoards[d];
		return scores[d];
	}
}

Board PerfectPlayer::move(Board board)
{
	Board temp;
	minmax(board, temp, mPlayer, true, 0);
	return temp;
}