#include "buyer.hpp"

#include <iostream>

namespace game_store
{

    Buyer::Buyer(std::string_view name)
        : m_name{ name }
        , m_cart{ name }
    {
        std::cout << "Создан покупатель: " << m_name << '\n';
    }

    Buyer::~Buyer()
    {
        std::cout << "Уничтожается покупатель: " << m_name << '\n';
    }

    bool Buyer::AddGameToCart(VideoGame& game)
    {
        return m_cart.AddGame(game);
    }

    bool Buyer::RemoveGameFromCart(VideoGame& game)
    {
        return m_cart.RemoveGame(game);
    }

    void Buyer::PrintProfile() const
    {
        std::cout << "Покупатель: " << m_name << '\n';
        m_cart.PrintContents();
    }

    void Buyer::Checkout() const
    {
        if (m_cart.GetItemCount() == 0)
        {
            std::cout << "Ошибка: невозможно оформить пустую корзину.\n";
            return;
        }

        std::cout << "Заказ оформлен. Сумма: " << m_cart.CalculateTotal() << '\n';
    }

    Cart& Buyer::GetCart()
    {
        return m_cart;
    }

    std::string_view Buyer::GetName() const
    {
        return m_name;
    }

} // namespace game_store
