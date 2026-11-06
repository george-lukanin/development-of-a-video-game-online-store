#pragma once

#include "basevideogame.hpp"

namespace game_store
{
    class OnlineVideoGame final : public BaseVideoGame
    {
    public:
        OnlineVideoGame(std::string_view title, std::string_view genre, double price);

        OnlineVideoGame();

        ~OnlineVideoGame() override;

        void Describe() const override;

        [[nodiscard]] std::string GetPlatform() const override;

        [[nodiscard]] std::unique_ptr<BaseVideoGame> Clone() const override;
    };
}