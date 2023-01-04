// (c) Cheva's Game of Life
#pragma once

namespace gol::app::core::engine
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
			~Cell() = default;

			void createCell();
			void killCell();
			CellState getState() const { return state; };

		private:
			CellState state;

		};
} // namespace gol::app::core::engine
