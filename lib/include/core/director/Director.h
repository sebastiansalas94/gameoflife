// (c) Cheva's Game of Life
#pragma once
#include "core/engine/Engine.h"

namespace gol::lib::core::director
{
    class Director
    {
    public:
        //Definir bien el constructor para que reciba acciones y engine
        Director(std::unique_ptr<engine::Engine> engine);
        ~Director() = default;

        std::unique_ptr<engine::Engine> const& getEngine() { return mEngine; };

    private:
        std::unique_ptr<engine::Engine> mEngine;
        bool isRunning;
        //std::vector<std::unique_ptr<IAction>> mRules;

    };
} // namespace gol::lib::core::director
