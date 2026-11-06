#include "onlinevideogame.hpp"

namespace game_store
{
    OnlineVideoGame::OnlineVideoGame(std::string_view title, std::string_view genre, double price) : BaseVideoGame(title, genre, price, "Онлайн-видеоигра с сетевым режимом")
    {
        std::cout << "Создана онлайн-видеоигра: " << m_title << '\n';
    }

    OnlineVideoGame::OnlineVideoGame() : OnlineVideoGame("Unknown Online", "Online", 0.0)
    {
    }

    OnlineVideoGame::~OnlineVideoGame()
    {
        std::cout << "Уничтожается онлайн-видеоигра: " << m_title << '\n';
    }

    void OnlineVideoGame::Describe() const
    {
        std::cout << "Онлайн-игра: " << m_title << ", жанр: " << m_genre << ", стоимость: " << m_price << '\n';
    }

    std::string OnlineVideoGame::GetPlatform() const
    {
        return "Online / Multiplayer";
    }

    std::unique_ptr<BaseVideoGame> OnlineVideoGame::Clone() const
    {
        return std::make_unique<OnlineVideoGame>(*this);
    }
}