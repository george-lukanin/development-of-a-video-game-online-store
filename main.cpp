#include "buyer.hpp"
#include "cart.hpp"
#include "videogame.hpp"

#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    using namespace game_store;

    std::cout << "===== Композиция =====\n";

    {
        Buyer buyer{ "Иван" };

        VideoGame game{ "Half-Life 2", "FPS", 399.0 };

        std::cout << "\nДобавление игры в корзину:\n";
        buyer.AddGameToCart(game);

        std::cout << "\nСостояние покупателя:\n";
        buyer.PrintProfile();

        std::cout << "\nОформление заказа:\n";
        buyer.Checkout();

        std::cout << "\nВыход из блока...\n";
    }

    std::cout << "\nПокупатель и его корзина уничтожены.\n";

    std::cout << "\n===== Агрегация =====\n";

    VideoGame externalGame{ "The Witcher 3", "RPG", 1499.0 };

    {
        Cart cart{ "Внешний покупатель" };

        cart.AddGame(externalGame);

        std::cout << "\nСостояние корзины:\n";
        cart.PrintContents();

        std::cout << "\nВыход из блока. Корзина будет уничтожена.\n";
    }

    std::cout << "\nКорзина уничтожена, но видеоигра продолжает существовать:\n";

    externalGame.PrintInfo();

    std::cout << "\n===== Проверка правил =====\n";

    Cart ruleCart{ "Покупатель проверки" };

    VideoGame ruleGame{ "Doom", "Shooter", 999.0 };

    std::cout << "\nПервое добавление:\n";
    ruleCart.AddGame(ruleGame);

    std::cout << "\nПопытка добавить ту же игру повторно:\n";
    ruleCart.AddGame(ruleGame);

    std::cout << "\nПопытка изменить цену на отрицательную:\n";
    ruleGame.ChangePrice(-100.0);

    std::cout << "\nКорректное изменение цены:\n";
    ruleGame.ChangePrice(999.0);

    std::cout << "\n===== Статический объект =====\n";

    static VideoGame staticGame{ "Portal", "Puzzle", 199.0 };

    staticGame.PrintInfo();

    std::cout << "\n===== Динамический объект new/delete =====\n";

    VideoGame* dynamicGame = new VideoGame{ "Cyberpunk 2077", "RPG", 1499.0 };

    dynamicGame->PrintInfo();

    delete dynamicGame;
    dynamicGame = nullptr;

    std::cout << "\n===== Работа по ссылке и указателю =====\n";

    VideoGame referenceGame{ "Terraria", "Sandbox", 399.0 };

    VideoGame& gameReference = referenceGame;
    gameReference.PrintInfo();

    VideoGame* gamePointer = &referenceGame;
    gamePointer->ChangePrice(799.0);
    gamePointer->PrintInfo();

    std::cout << "\n===== Динамический массив объектов =====\n";

    VideoGame* gameArray = new VideoGame[2];

    gameArray[0].ChangePrice(699.0);
    gameArray[1].ChangePrice(499.0);

    gameArray[0].PrintInfo();
    gameArray[1].PrintInfo();

    delete[] gameArray;
    gameArray = nullptr;

    std::cout << "\n===== Массив динамических объектов =====\n";

    VideoGame* dynamicGames[2]{};

    dynamicGames[0] = new VideoGame{ "Stardew Valley", "Simulator", 799.0 };
    dynamicGames[1] = new VideoGame{ "Portal 2", "Puzzle", 399.0 };

    for (VideoGame* game : dynamicGames)
    {
        game->PrintInfo();
    }

    delete dynamicGames[0];
    delete dynamicGames[1];

    dynamicGames[0] = nullptr;
    dynamicGames[1] = nullptr;

    std::cout << "\n===== Проверка статического объекта =====\n";

    staticGame.PrintInfo();

    return 0;
}
