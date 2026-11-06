#include "basevideogame.hpp"

namespace game_store
{
    BaseVideoGame::BaseVideoGame(std::string_view title, std::string_view genre, double price, std::string_view description) : m_title{ title }, m_genre{ genre }, m_price{ price >= 0.0 ? price : 0.0 }, m_description{ std::make_shared<std::string>(description) }
    {
        if (price < 0.0)
        {
            std::cout << "Ошибка: цена игры не может быть отрицательной.\n";
        }

        ++s_objectCount;

        std::cout << "Конструктор BaseVideoGame: " << m_title << '\n';
    }

    BaseVideoGame::BaseVideoGame() : BaseVideoGame("Unknown", "Unknown", 0.0, "Описание отсутствует")
    {
    }

    BaseVideoGame::BaseVideoGame(const BaseVideoGame& other) : m_title{ other.m_title }, m_genre{ other.m_genre }, m_price{ other.m_price }, m_description {std::make_shared<std::string>(*other.m_description)}
    {
        ++s_objectCount;

        std::cout << "Конструктор копирования BaseVideoGame: " << m_title << '\n';
    }

    BaseVideoGame::BaseVideoGame(BaseVideoGame&& other) noexcept : m_title{ std::move(other.m_title) }, m_genre{ std::move(other.m_genre) }, m_price{ other.m_price }, m_description{ std::move(other.m_description) }
    {
        ++s_objectCount;

        std::cout << "Конструктор перемещения BaseVideoGame\n";
    }

    BaseVideoGame& BaseVideoGame::operator=(const BaseVideoGame& other)
    {
        if (this == &other)
        {
            return *this;
        }

        m_title = other.m_title;
        m_genre = other.m_genre;
        m_price = other.m_price;

        m_description = std::make_shared<std::string>(*other.m_description);

        return *this;
    }

    BaseVideoGame& BaseVideoGame::operator=(BaseVideoGame&& other) noexcept
    {
        if (this == &other)
        {
            return *this;
        }

        m_title = std::move(other.m_title);
        m_genre = std::move(other.m_genre);
        m_price = other.m_price;
        m_description = std::move(other.m_description);

        return *this;
    }

    BaseVideoGame::~BaseVideoGame()
    {
        std::cout << "Деструктор BaseVideoGame: " << m_title << '\n';

        --s_objectCount;
    }

    std::string_view BaseVideoGame::GetTitle() const
    {
        return m_title;
    }

    std::string_view BaseVideoGame::GetGenre() const
    {
        return m_genre;
    }

    double BaseVideoGame::GetPrice() const
    {
        return m_price;
    }

    std::string BaseVideoGame::GetDescription() const
    {
        return *m_description;
    }

    void BaseVideoGame::ChangePrice(double newPrice)
    {
        if (newPrice < 0.0)
        {
            std::cout << "Ошибка: новая цена не может быть отрицательной.\n";
            return;
        }

        m_price = newPrice;

        std::cout << "Цена игры \"" << m_title << "\" изменена на " << m_price << '\n';
    }

    void BaseVideoGame::Describe() const
    {
        std::cout << "Видеоигра: " << m_title << ", жанр: " << m_genre << ", цена: " << m_price << '\n';
    }

    void BaseVideoGame::PrintInfo() const
    {
        Describe();

        std::cout << "Платформа: " << GetPlatform() << '\n';
        std::cout << "Описание: " << *m_description << '\n';
    }

    void BaseVideoGame::AddToCollection(std::vector<const BaseVideoGame*>& collection) const
    {
        collection.push_back(this);
    }

    int BaseVideoGame::GetObjectCount()
    {
        return s_objectCount;
    }

    void BaseVideoGame::ShareDescriptionWith(BaseVideoGame& other)
    {
        other.m_description = m_description;
    }

    void BaseVideoGame::ProcessTitle() const
    {
        std::string fullTitle = m_title + " - " + m_genre;

        std::cout << "Полное название: " << fullTitle << '\n';

        std::size_t position = fullTitle.find(m_genre);

        if (position != std::string::npos)
        {
            std::cout << "Жанр найден в позиции: " << position << '\n';
        }

        std::cout << "Первые символы названия: " << m_title.substr(0, 3) << '\n';
    }
}