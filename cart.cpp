#include "cart.hpp"

#include <iostream>

namespace game_store
{

    Cart::Cart(std::string_view ownerName)
        : m_ownerName{ ownerName }
    {
        std::cout << "Создана корзина покупателя: " << m_ownerName << '\n';
    }

    Cart::~Cart()
    {
        std::cout << "Уничтожается корзина покупателя: " << m_ownerName << ". Игры остаются существовать.\n";
    }

    bool Cart::AddGame(VideoGame& game)
    {
        if (m_itemCount >= MAX_ITEMS)
        {
            std::cout << "Ошибка: корзина заполнена.\n";
            return false;
        }

        for (std::size_t i = 0; i < m_itemCount; ++i)
        {
            if (m_items[i] == &game)
            {
                std::cout << "Ошибка: игра уже находится в корзине.\n";
                return false;
            }
        }

        m_items[m_itemCount] = &game;
        ++m_itemCount;

        std::cout << "Игра \"" << game.GetTitle() << "\" добавлена в корзину.\n";

        return true;
    }

    bool Cart::RemoveGame(VideoGame& game)
    {
        for (std::size_t i = 0; i < m_itemCount; ++i)
        {
            if (m_items[i] == &game)
            {
                for (std::size_t j = i; j + 1 < m_itemCount; ++j)
                {
                    m_items[j] = m_items[j + 1];
                }

                m_items[m_itemCount - 1] = nullptr;
                --m_itemCount;

                std::cout << "Игра \"" << game.GetTitle() << "\" удалена из корзины.\n";

                return true;
            }
        }

        std::cout << "Ошибка: такой игры нет в корзине.\n";
        return false;
    }

    void Cart::PrintContents() const
    {
        std::cout << "Содержимое корзины покупателя " << m_ownerName << ":\n";

        if (m_itemCount == 0)
        {
            std::cout << "  Корзина пуста.\n";
            return;
        }

        for (std::size_t i = 0; i < m_itemCount; ++i)
        {
            std::cout << "  " << i + 1 << ". " << m_items[i]->GetTitle() << " - " << m_items[i]->GetPrice() << '\n';
        }
    }

    double Cart::CalculateTotal() const
    {
        double total = 0.0;

        for (std::size_t i = 0; i < m_itemCount; ++i)
        {
            total += m_items[i]->GetPrice();
        }

        return total;
    }

    std::size_t Cart::GetItemCount() const
    {
        return m_itemCount;
    }

} // namespace game_store
