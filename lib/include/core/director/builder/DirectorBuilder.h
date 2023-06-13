// (c) Cheva's Game of Life
#pragma once

#include <memory>

#include "core/engine/Engine.h"
#include "core/director/Director.h"

using gol::lib::core::engine::Engine;
using gol::lib::core::director::Director;

namespace gol::lib::core::director::builder
{
    class DirectorBuilder
    {
    public:
        DirectorBuilder(std::unique_ptr<engine::Engine> engine);
        ~DirectorBuilder() = default;
    
        std::unique_ptr<Director> createDirector();
        std::unique_ptr<Engine> const& getEngine() { return mEngine; };

    private:
        std::unique_ptr<Engine> mEngine;
        std::unique_ptr<Director> mDirector;        
        //std::vector<std::unique_ptr<IAction>> mRules;

    };
} // namespace gol::lib::core::director::builder