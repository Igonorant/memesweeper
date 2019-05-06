#pragma once
#include "SpriteCodex.h"
#include "Vei2.h"
#include "Graphics.h"
#include "MainWindow.h"

class MineField {

	//Enum for game states
	enum class GameState{Running,WinGameOver,LoseGameOver};

	//Tile class to build MineField grid
private:
	class Tile {

		enum class TileState{Hidden,Revealed,Flagged,Exploded};

	public:
		Tile() = default;
		void SetPosition(const Vei2& topLeftPos);
		bool AddBomb(); //return true if successful put bomb, false if already has a bomb
		void SetNeighbourBombs(const int bombCount);
		void Draw(Graphics& gfx);
		void Reveal();

	private:
		static constexpr int tileSize = SpriteCodex::tileSize;
		Vei2 topLeftPosition = { 0,0 };
		TileState state = TileState::Hidden;
		bool hasBomb = false;
		int neighbourBombs = 0;
	};

public:
	MineField() = default;
	MineField(const int minesNumbers, const Vei2& topLeftPos);
	void Draw(Graphics& gfx);
	void InsertMines(const int minesNumber);
	int Screen2Grid(const Vei2& screenPos);
	Vei2 Grid2Screen(const int gridPos);
	void TileClick(MainWindow& wnd);
	const int Map2D(const int x,const int y);

private:
	static constexpr int fieldWidth = 30;
	static constexpr int fieldHeight = 20;
	static constexpr int fieldSize = fieldWidth * fieldHeight;
	Tile tiles[fieldSize];
	Vei2 topLeftPosition;
	GameState gameState = GameState::Running;
};