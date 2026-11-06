using System;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace game_store
{
    internal class Program
    {
        static void Main()
        {
            Console.WriteLine("===== Создание объектов =====");

            OfflineVideoGame game1 = new OfflineVideoGame("Half-Life 2", "FPS", 399.0);

            OnlineVideoGame game2 = new OnlineVideoGame("Team Fortress 2", "FPS", 0.0);

            OnlineVideoGame game3 = new OnlineVideoGame();

            Console.WriteLine("\n===== Работа через базовый класс =====");

            List<BaseVideoGame> games = new List<BaseVideoGame> { game1, game2 };

            foreach (BaseVideoGame game in games)
            {
                game.PrintInfo();
                Console.WriteLine();
            }

            Console.WriteLine("\n===== Глубокое копирование =====");

            OfflineVideoGame copiedGame = new OfflineVideoGame(game1);

            copiedGame.ChangePrice(50);

            Console.WriteLine("Оригинал: " + game1);
            Console.WriteLine("Копия: " + copiedGame);

            Console.WriteLine("\n===== Поверхностное копирование =====");

            BaseVideoGame shallowCopy = game1.ShallowCopy();

            shallowCopy.ChangeDescription("Изменённое общее описание");

            Console.WriteLine("Оригинал: ");

            game1.PrintInfo();

            Console.WriteLine("Поверхностная копия: ");

            shallowCopy.PrintInfo();

            Console.WriteLine("\n===== Глубокое копирование =====");

            BaseVideoGame deepCopy = game1.Clone();

            deepCopy.ChangePrice(100);

            Console.WriteLine("Оригинал: " + game1);
            Console.WriteLine("Клон: " + deepCopy);

            Console.WriteLine("\n===== Работа со строками =====");

            game1.ProcessTitle();

            Console.WriteLine("\n===== Сравнение объектов =====");

            OfflineVideoGame anotherGame = new OfflineVideoGame("Minecraft", "Sandbox", 29.99);

            Console.WriteLine($"Объекты равны: {game1.Equals(anotherGame)}");

            Console.WriteLine($"HashCode оригинала: {game1.GetHashCode()}");

            Console.WriteLine($"HashCode копии: {anotherGame.GetHashCode()}");

            Console.WriteLine("\n===== This и передача объекта =====");

            List<BaseVideoGame> collection = new List<BaseVideoGame>();

            game1.AddToCollection(collection);

            Console.WriteLine($"Количество игр: {collection.Count}");

            Console.WriteLine("\n===== Статическое поле =====");

            Console.WriteLine($"Количество объектов: {BaseVideoGame.GetObjectCount()}");

            Console.WriteLine("\n===== using var =====");

            using var writer = new StringWriter();

            writer.WriteLine(game1.ToString());

            Console.WriteLine(writer.ToString());

            Console.WriteLine("\n===== Конец программы =====");
        }
    }
}