// (c) Cheva's Game of Life
#pragma once

#include "core/engine/Engine.h"
#include "core/engine/IRule.h"

using gol::lib::core::engine::Engine;
using gol::lib::core::engine::factory::IRule;

namespace gol::lib::core::engine::builder
{
    class EngineBuilder
    {
    public:
        EngineBuilder() = default;
        EngineBuilder(int width, int height, std::vector<std::unique_ptr<IRule>> rules);
        ~EngineBuilder() = default;

        //Move Assign
        EngineBuilder& operator=(EngineBuilder&& engineBuilderRValue) {
            this->mWidth = engineBuilderRValue.mWidth;
            this->mHeight = engineBuilderRValue.mHeight;
            this->mRules = std::move(engineBuilderRValue.mRules);
            return *this;
        };

        std::unique_ptr<Engine> createEngine();
        int getWidth() { return mWidth; };
        int getHeight() { return mHeight; };
        std::vector<std::unique_ptr<IRule>> const & getRules() { return mRules; };

    private:
        int mWidth;
        int mHeight;
        std::vector<std::unique_ptr<IRule>> mRules;
    };

} // namespace gol::lib::core::engine::builder