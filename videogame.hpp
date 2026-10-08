#pragma once

#include <string>
#include <string_view>

namespace game_store
{

    class VideoGame
    {
    private:
        std::string m_title{};
        std::string m_genre{};
        double m_price{};

    public:
        VideoGame(std::string_view title, std::string_view genre, double price);
        VideoGame();

        ~VideoGame();

        [[nodiscard]] std::string_view GetTitle() const;
        [[nodiscard]] std::string_view GetGenre() const;
        [[nodiscard]] double GetPrice() const;

        void ChangePrice(double newPrice);
        void PrintInfo() const;
    };

} // namespace game_store
