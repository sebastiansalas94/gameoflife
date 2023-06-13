// (c) Cheva's Game of Life
#pragma once
#include "core/director/builder/DirectorBuilder.h"
#include "core/engine/builder/EngineBuilder.h"
#include "core/engine/factory/RulesFactory.h"
#include "core/engine/RuleProximity.h"
#include "core/engine/Engine.h"
#include <memory>

using gol::lib::core::director::builder::DirectorBuilder;
using gol::lib::core::engine::builder::EngineBuilder;
using gol::lib::core::engine::factory::RulesFactory;

namespace gol::lib::core
{
    class Facade
    {
    public:
        Facade();
        ~Facade() = default;

        void createEngineBuilder();
        void createEngine();
        void createRules();
        void createDirectorBuilder();

        std::vector<std::unique_ptr<IRule>> const& getRules() const { return mRules; };

    private:
        //TODO: Encontrar un mejor lugar para este readConfig
        void readConfig();

        int mWidth;
        int mHeight;
        std::unique_ptr<DirectorBuilder> mDirectorBuilder;
        std::unique_ptr<EngineBuilder> mEngineBuilder;
        std::unique_ptr<Engine> mEngine;
        RulesFactory mRulesFactory;
        std::vector<std::unique_ptr<IRule>> mRules;
    };
} // namespace gol::lib::core
