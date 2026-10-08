#pragma once

#include "videogame.hpp"

#include <cstddef>
#include <string>
#include <string_view>

namespace game_store
{

    class Cart
    {
    private:
        static constexpr std::size_t MAX_ITEMS = 10;

        std::string m_ownerName{};
        VideoGame* m_items[MAX_ITEMS]{};
        std::size_t m_itemCount{};

    public:
        explicit Cart(std::string_view ownerName);

        ~Cart();

        Cart(const Cart&) = delete;
        Cart& operator=(const Cart&) = delete;

        bool AddGame(VideoGame& game);
        bool RemoveGame(VideoGame& game);

        void PrintContents() const;
        [[nodiscard]] double CalculateTotal() const;
        [[nodiscard]] std::size_t GetItemCount() const;
    };

} // namespace game_store
