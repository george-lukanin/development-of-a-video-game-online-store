#include "offlinevideogame.hpp"
#include "onlinevideogame.hpp"

#include <iostream>
#include <windows.h>
#include <vector>

using namespace game_store;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::cout << "===== Создание объектов =====\n";

    OfflineVideoGame game1("Half-Life 2", "FPS", 399.0);

    OnlineVideoGame game2("Team Fortress 2", "FPS", 0.0);

    OnlineVideoGame game3;

    std::cout << "\n===== Работа через базовый класс =====\n";

    std::unique_ptr<BaseVideoGame> games[] = { std::make_unique<OfflineVideoGame>(game1), std::make_unique<OnlineVideoGame>(game2) };

    for (const auto& game : games)
    {
        game->PrintInfo();
        std::cout << '\n';
    }

    std::cout << "\n===== Конструктор копирования =====\n";

    OfflineVideoGame copiedGame(game1);

    copiedGame.ChangePrice(299.0);

    std::cout << "Оригинал: ";
    game1.PrintInfo();

    std::cout << "Копия: ";
    copiedGame.PrintInfo();

    std::cout << "\n===== Поверхностное копирование =====\n";

    OfflineVideoGame shallowCopy("Doom", "Shooter", 999.0);

    game1.ShareDescriptionWith(shallowCopy);

    std::cout << "Описание оригинала: " << game1.GetDescription() << '\n';

    shallowCopy.ShareDescriptionWith(game1);

    std::cout << "Общее описание: " << shallowCopy.GetDescription() << '\n';

    std::cout << "\n===== Глубокое копирование =====\n";

    auto deepCopy = game1.Clone();

    deepCopy->ChangePrice(899.0);

    std::cout << "Оригинал: ";
    game1.PrintInfo();

    std::cout << "Глубокая копия: ";
    deepCopy->PrintInfo();

    std::cout << "\n===== Перемещение =====\n";

    OfflineVideoGame moveSource("Cyberpunk 2077", "RPG", 1499.0);

    OfflineVideoGame movedGame(std::move(moveSource));

    movedGame.PrintInfo();

    std::cout << "\n===== Работа со строками =====\n";

    game1.ProcessTitle();

    std::cout << "\n===== This и передача объекта =====\n";

    std::vector<const BaseVideoGame*> collection;

    game1.AddToCollection(collection);

    std::cout << "Количество игр в коллекции: " << collection.size() << '\n';

    std::cout << "\n===== Статическое поле =====\n";

    std::cout << "Количество объектов: " << BaseVideoGame::GetObjectCount() << '\n';

    std::cout << "\n===== Уничтожение через указатель =====\n";

    std::unique_ptr<BaseVideoGame> polymorphicGame = std::make_unique<OnlineVideoGame>("Terraria", "Sandbox", 399.0);

    polymorphicGame->PrintInfo();

    polymorphicGame.reset();

    std::cout << "\n===== Конец программы =====\n";

    return 0;
}