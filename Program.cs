using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace game_store
{
    internal class Program
    {
        static void Main()
        {
            Console.WriteLine("===== Композиция =====");

            {
                Buyer buyer = new Buyer("Иван");
                VideoGame game = new VideoGame("Half-Life 2", "FPS", 399.0);

                Console.WriteLine("\nДобавление игры в корзину:");
                buyer.AddGameToCart(game);

                Console.WriteLine("\nСостояние покупателя:");
                buyer.PrintProfile();

                Console.WriteLine("\nОформление заказа:");
                buyer.Checkout();

                Console.WriteLine("\nВыход из блока.");
            }

            Console.WriteLine("\nЛокальные переменные блока больше не используются.");

            Console.WriteLine("\n===== Агрегация =====");

            VideoGame externalGame = new VideoGame("The Witcher 3", "RPG", 1499.0);

            {
                Cart cart = new Cart("Внешний покупатель");
                cart.AddGame(externalGame);

                Console.WriteLine("\nСостояние корзины:");
                cart.PrintContents();

                Console.WriteLine("\nВыход из блока с корзиной.");
            }

            Console.WriteLine("\nИгра продолжает существовать после выхода из блока:");
            externalGame.PrintInfo();

            Console.WriteLine("\n===== Проверка правил =====");

            Cart ruleCart = new Cart("Покупатель проверки");
            VideoGame ruleGame = new VideoGame("Doom", "Shooter", 999.0);

            Console.WriteLine("\nПервое добавление:");
            ruleCart.AddGame(ruleGame);

            Console.WriteLine("\nПовторное добавление той же игры:");
            ruleCart.AddGame(ruleGame);

            Console.WriteLine("\nПопытка установить отрицательную цену:");
            ruleGame.ChangePrice(-100.0);

            Console.WriteLine("\nКорректное изменение цены:");
            ruleGame.ChangePrice(799.0);
            ruleGame.PrintInfo();

            Console.WriteLine("\n===== Ссылки и копии объектов =====");

            VideoGame first = new VideoGame("Terraria", "Sandbox", 399.0);
            VideoGame second = first;

            Console.WriteLine("До изменения:");
            Console.WriteLine($"first:  {first}");
            Console.WriteLine($"second: {second}");

            second.ChangePrice(799.0);

            Console.WriteLine("После изменения через second:");
            Console.WriteLine($"first:  {first}");
            Console.WriteLine($"second: {second}");

            Console.WriteLine("Обе переменные ссылаются на один объект.");

            Console.WriteLine("\n===== Копирование структуры =====");

            GameSnapshot snapshot1 = new GameSnapshot("Portal", 199.0);

            GameSnapshot snapshot2 = snapshot1;
            snapshot2.Price = 399.0;

            Console.WriteLine($"snapshot1: {snapshot1}");
            Console.WriteLine($"snapshot2: {snapshot2}");

            Console.WriteLine("Изменение копии структуры не изменило исходную.");

            Console.WriteLine("\n===== Освобождение ресурса через using =====");

            using (ResourceJournal journal = new ResourceJournal())
            {
                journal.Write("Покупатель получил игру.");
                Console.WriteLine("Внутри блока using.");
            }

            Console.WriteLine("После блока using.");

            Console.WriteLine("\n===== Сборщик мусора =====");

            WeakReference<VideoGame> weakGame = CreateUnreferencedGame();

            Console.WriteLine($"До GC объект доступен: {weakGame.TryGetTarget(out _)}");

            Console.WriteLine("Вызывается сборщик мусора. Финализатор может выполниться позже.");

            GC.Collect();
            GC.WaitForPendingFinalizers();
            GC.Collect();

            Console.WriteLine($"После GC объект доступен: {weakGame.TryGetTarget(out _)}");

            Console.WriteLine("Сборка мусора не привязана к выходу из блока.");

            Console.WriteLine("\n===== Завершение программы =====");
        }

        [MethodImpl(MethodImplOptions.NoInlining)]
        private static WeakReference<VideoGame> CreateUnreferencedGame()
        {
            VideoGame game = new VideoGame("Временная игра", "Test", 100.0);

            return new WeakReference<VideoGame>(game);
        }
    }
}