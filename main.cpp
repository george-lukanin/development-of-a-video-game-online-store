#include "buyer.hpp"
#include "cart.hpp"
#include "videogame.hpp"

#include <iostream>
#include <windows.h>

using namespace game_store;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::cout << "===== Композиция =====\n";

    {
        Buyer buyer{ "Иван" };
        VideoGame game{ "Half-Life 2", "FPS", 399.0 };

        buyer.AddGameToCart(game);
        buyer.PrintProfile();
        buyer.Checkout();

        std::cout << "Выход из блока композиции.\n";
    }

    std::cout << "\n===== Агрегация =====\n";

    VideoGame externalGame{ "The Witcher 3", "RPG", 1499.0 };

    {
        Cart cart{ "Внешний покупатель" };
        cart.AddGame(externalGame);
        cart.PrintContents();

        std::cout << "Выход из блока агрегации.\n";
    }

    externalGame.PrintInfo();

    std::cout << "\n===== Проверка правил =====\n";

    Cart ruleCart{ "Покупатель проверки" };
    VideoGame ruleGame{ "Doom", "Shooter", 999.0 };

    ruleCart.AddGame(ruleGame);
    ruleCart.AddGame(ruleGame);
    ruleGame.ChangePrice(-100.0);
    ruleGame.ChangePrice(799.0);

    std::cout << "\n===== unique_ptr: единственный владелец =====\n";

    {
        auto game = std::make_unique<VideoGame>("Cyberpunk 2077", "RPG", 1499.0);

        game->PrintInfo();
        std::cout << "Выход из блока: unique_ptr удалит игру.\n";
    }

    std::cout << "Блок завершён.\n";

    std::cout << "\n===== unique_ptr: передача владения =====\n";

    auto original = std::make_unique<VideoGame>("Terraria", "Sandbox", 399.0);

    auto recipient = std::move(original);

    std::cout << "Исходный указатель пуст: " << std::boolalpha << (original == nullptr) << '\n';

    recipient->PrintInfo();

    std::cout << "\n===== shared_ptr: совместное владение =====\n";

    std::shared_ptr<VideoGame> sharedGame;

    {
        auto owner1 = std::make_shared<VideoGame>("Stardew Valley", "Simulator", 799.0);

        std::cout << "После создания: " << owner1.use_count() << '\n';

        {
            auto owner2 = owner1;

            std::cout << "После копирования: " << owner1.use_count() << '\n';

            owner2->ChangePrice(899.0);
            owner2->PrintInfo();

            sharedGame = owner2;

            std::cout << "После создания ещё одного владельца: " << owner1.use_count() << '\n';
        }

        std::cout << "После уничтожения owner2: " << owner1.use_count() << '\n';
    }

    std::cout << "После выхода owner1: " << sharedGame.use_count() << '\n';

    sharedGame.reset();
    std::cout << "Последний владелец уничтожен.\n";

    std::cout << "\n===== weak_ptr: наблюдение без владения =====\n";

    std::weak_ptr<VideoGame> weakGame;

    {
        auto owner = std::make_shared<VideoGame>("Portal 2", "Puzzle", 399.0);

        weakGame = owner;

        if (auto locked = weakGame.lock())
        {
            std::cout << "Объект доступен через lock():\n";
            locked->PrintInfo();
        }
    }

    if (auto locked = weakGame.lock())
    {
        locked->PrintInfo();
    }

    else
    {
        std::cout << "lock() вернул пустой указатель: объект уничтожен.\n";
    }

    std::cout << "\n===== Динамический массив объектов =====\n";

    auto gameArray = std::make_unique<VideoGame[]>(2);

    gameArray[0].ChangePrice(699.0);
    gameArray[1].ChangePrice(499.0);

    gameArray[0].PrintInfo();
    gameArray[1].PrintInfo();

    std::cout << "Выход из блока массива освободит оба объекта.\n";

    std::cout << "\n===== Массив динамических объектов =====\n";

    std::array<std::unique_ptr<VideoGame>, 2> dynamicGames{std::make_unique<VideoGame>("Stardew Valley", "Simulator", 799.0), std::make_unique<VideoGame>("Portal 2", "Puzzle", 399.0)};

    for (const auto& game : dynamicGames)
    {
        game->PrintInfo();
    }

    std::cout << "При выходе из main элементы unique_ptr освободят игры.\n";

    std::cout << "\n===== Конец программы =====\n";

    return 0;
}