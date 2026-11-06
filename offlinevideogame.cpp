#include "offlinevideogame.hpp"

namespace game_store
{
    OfflineVideoGame::OfflineVideoGame(std::string_view title, std::string_view genre, double price) : BaseVideoGame(title, genre, price, "Видеоигра")
    {
        std::cout << "Создана оффлайн-видеоигра: " << m_title << '\n';
    }

    OfflineVideoGame::OfflineVideoGame() : OfflineVideoGame("Unknown", "Unknown", 0.0)
    {
    }

    OfflineVideoGame::OfflineVideoGame(const OfflineVideoGame& other) : BaseVideoGame(other)
    {
        std::cout << "Копирование OfflineVideoGame: " << m_title << '\n';
    }

    OfflineVideoGame::OfflineVideoGame(OfflineVideoGame&& other) noexcept : BaseVideoGame(std::move(other))
    {
        std::cout << "Перемещение OfflineVideoGame\n";
    }

    OfflineVideoGame& OfflineVideoGame::operator=(const OfflineVideoGame& other)
    {
        if (this == &other)
        {
            return *this;
        }

        BaseVideoGame::operator=(other);

        return *this;
    }

    OfflineVideoGame& OfflineVideoGame::operator=(OfflineVideoGame&& other) noexcept
    {
        if (this == &other)
        {
            return *this;
        }

        BaseVideoGame::operator=(std::move(other));

        return *this;
    }

    OfflineVideoGame::~OfflineVideoGame()
    {
        std::cout << "Уничтожается видеоигра: " << m_title << '\n';
    }

    void OfflineVideoGame::Describe() const
    {
        BaseVideoGame::Describe();

        std::cout << "Тип: оффлайн видеоигра\n";
    }

    std::string OfflineVideoGame::GetPlatform() const
    {
        return "PC / Console";
    }

    std::unique_ptr<BaseVideoGame> OfflineVideoGame::Clone() const
    {
        return std::make_unique<OfflineVideoGame>(*this);
    }

    void OfflineVideoGame::PrintInfo() const
    {
        BaseVideoGame::PrintInfo();
    }
}