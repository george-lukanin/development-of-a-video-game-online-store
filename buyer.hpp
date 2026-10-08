#pragma once

#include "cart.hpp"

#include <string>
#include <string_view>

namespace game_store
{

    class Buyer
    {
    private:
        std::string m_name{};
        Cart m_cart;

    public:
        explicit Buyer(std::string_view name);

        ~Buyer();

        bool AddGameToCart(VideoGame& game);
        bool RemoveGameFromCart(VideoGame& game);

        void PrintProfile() const;
        void Checkout() const;

        [[nodiscard]] Cart& GetCart();
        [[nodiscard]] std::string_view GetName() const;
    };

} // namespace game_store
