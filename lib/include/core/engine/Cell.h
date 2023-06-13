// (c) Cheva's Game of Life
#pragma once
#include <utility>

namespace gol::lib::core::engine
{
		enum class CellState
		{
			STATE_DEAD,
			STATE_ALIVE
		};

		class Cell
		{
		public:
			Cell();
			//Move Constructor
			Cell(Cell&& cellRValue)
				: mState(std::move(cellRValue.mState)) {};


			Cell(Cell const& other) {
				mState = other.mState;
			}

			~Cell() = default;

			void createCell();
			void killCell();
			CellState const& getState() const { return mState; };

		private:
			CellState mState;

		};
} // namespace gol::lib::core::engine
