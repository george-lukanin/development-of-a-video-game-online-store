#pragma once

#include "videogame.hpp"

#include <array>
#include <cstddef>
#include <string>
#include <string_view>

namespace game_store
{
    class Cart
    {
    private:
        static const std::size_t MAX_ITEMS = 10;

        std::string m_ownerName{};
        std::array<VideoGame*, MAX_ITEMS> m_items{};
        std::size_t m_itemCount{};

    public:
        Cart(std::string_view ownerName);
        ~Cart();

        Cart(const Cart&) = delete;
        Cart& operator=(const Cart&) = delete;

        bool AddGame(VideoGame& game);
        bool RemoveGame(VideoGame& game);

        void PrintContents() const;
        [[nodiscard]] double CalculateTotal() const;
        [[nodiscard]] std::size_t GetItemCount() const;
    };
}