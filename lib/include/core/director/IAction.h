// (c) Cheva's Game of Life
#pragma once

namespace gol::lib::core::director
{
    class IAction
    {
    public:
        IAction() = default;
        virtual ~IAction() = default;

        virtual void execute() = 0;
    };
} // gol::lib::core::director
