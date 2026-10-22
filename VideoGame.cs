using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace game_store
{
    public class VideoGame
    {
        public string Title { get; }
        public string Genre { get; }
        public double Price { get; private set; }

        public VideoGame(string title, string genre, double price)
        {
            Title = title;
            Genre = genre;

            if (price < 0)
            {
                Console.WriteLine("Ошибка: цена игры не может быть отрицательной.");
                Price = 0;
            }

            else
            {
                Price = price;
            }

            Console.WriteLine($"Создана видеоигра: {Title}");
        }

        public VideoGame() : this("Unknown", "Unknown", 0)
        {
        }

        public void ChangePrice(double newPrice)
        {
            if (newPrice < 0)
            {
                Console.WriteLine("Ошибка: новая цена не может быть отрицательной.");
                return;
            }

            Price = newPrice;
            Console.WriteLine($"Цена игры \"{Title}\" изменена на {Price:F2}");
        }

        public void PrintInfo()
        {
            Console.WriteLine(ToString());
        }

        public override string ToString()
        {
            return $"Игра: {Title}, жанр: {Genre}, цена: {Price:F2}";
        }

        public void Release()
        {
            Console.WriteLine($"Объект игры \"{Title}\" собран GC.");
        }

        ~VideoGame()
        {
            Console.WriteLine($"Финализатор игры \"{Title}\" вызван.");
        }
    }
}