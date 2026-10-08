#include "videogame.hpp"

#include <iostream>

namespace game_store
{

    VideoGame::VideoGame(
        std::string_view title,
        std::string_view genre, double price)
        : m_title{ title }
        , m_genre{ genre }
        , m_price{ price }
    {
        if (price < 0.0)
        {
            std::cout << "Ошибка: цена игры не может быть отрицательной.\n";
            m_price = 0.0;
        }

        std::cout << "Создана видеоигра: " << m_title << '\n';
    }

    VideoGame::VideoGame()
        : m_title{ "Unknown" }
        , m_genre{ "Unknown" }
        , m_price{}
    {
        std::cout << "Создана видеоигра: " << m_title << '\n';
    }

    VideoGame::~VideoGame()
    {
        std::cout << "Уничтожается видеоигра: " << m_title << '\n';
    }

    std::string_view VideoGame::GetTitle() const
    {
        return m_title;
    }

    std::string_view VideoGame::GetGenre() const
    {
        return m_genre;
    }

    double VideoGame::GetPrice() const
    {
        return m_price;
    }

    void VideoGame::ChangePrice(double newPrice)
    {
        if (newPrice < 0.0)
        {
            std::cout << "Ошибка: новая цена не может быть отрицательной.\n";
            return;
        }

        m_price = newPrice;

        std::cout << "Цена игры \"" << m_title << "\" изменена на " << m_price << '\n';
    }

    void VideoGame::PrintInfo() const
    {
        std::cout << "Игра: " << m_title << ", жанр: " << m_genre << ", цена: " << m_price << '\n';
    }

} // namespace game_store
