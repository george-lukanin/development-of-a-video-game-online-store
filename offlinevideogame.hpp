#pragma once

#include "basevideogame.hpp"

namespace game_store
{
    class OfflineVideoGame : public BaseVideoGame
    {
    public:
        OfflineVideoGame(std::string_view title, std::string_view genre, double price);

        OfflineVideoGame();

        OfflineVideoGame(const OfflineVideoGame& other);

        OfflineVideoGame(OfflineVideoGame&& other) noexcept;

        OfflineVideoGame& operator=(const OfflineVideoGame& other);

        OfflineVideoGame& operator=(OfflineVideoGame&& other) noexcept;

        ~OfflineVideoGame() override;

        void Describe() const override;

        [[nodiscard]] std::string GetPlatform() const override;

        [[nodiscard]] std::unique_ptr<BaseVideoGame> Clone() const override;

        void PrintInfo() const;
    };
}