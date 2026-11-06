#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

namespace game_store
{
    class BaseVideoGame
    {
    protected:
        std::string m_title{};
        std::string m_genre{};
        double m_price{};

        std::shared_ptr<std::string> m_description{};

    private:
        inline static int s_objectCount = 0;

    public:
        BaseVideoGame(std::string_view title, std::string_view genre, double price, std::string_view description);

        BaseVideoGame();

        BaseVideoGame(const BaseVideoGame& other);

        BaseVideoGame(BaseVideoGame&& other) noexcept;

        BaseVideoGame& operator=(const BaseVideoGame& other);

        BaseVideoGame& operator=(BaseVideoGame&& other) noexcept;

        virtual ~BaseVideoGame();

        [[nodiscard]] std::string_view GetTitle() const;
        [[nodiscard]] std::string_view GetGenre() const;
        [[nodiscard]] double GetPrice() const;

        [[nodiscard]] std::string GetDescription() const;

        void ChangePrice(double newPrice);

        virtual void Describe() const;

        [[nodiscard]] virtual std::unique_ptr<BaseVideoGame> Clone() const = 0;

        [[nodiscard]] virtual std::string GetPlatform() const = 0;

        void PrintInfo() const;

        void AddToCollection(std::vector<const BaseVideoGame*>& collection) const;

        static int GetObjectCount();

        void ShareDescriptionWith(BaseVideoGame& other);

        void ProcessTitle() const;
    };
}