using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace game_store
{
    public class Cart
    {
        private const int MaxItems = 10;

        private readonly string _ownerName;
        private readonly List<VideoGame> _items = new List<VideoGame>();

        public Cart(string ownerName)
        {
            _ownerName = ownerName;
            Console.WriteLine($"Создана корзина покупателя: {_ownerName}");
        }

        public bool AddGame(VideoGame game)
        {
            if (_items.Count >= MaxItems)
            {
                Console.WriteLine("Ошибка: корзина заполнена.");
                return false;
            }

            if (_items.Contains(game))
            {
                Console.WriteLine("Ошибка: игра уже находится в корзине.");
                return false;
            }

            _items.Add(game);
            Console.WriteLine($"Игра \"{game.Title}\" добавлена в корзину.");
            return true;
        }

        public bool RemoveGame(VideoGame game)
        {
            if (!_items.Remove(game))
            {
                Console.WriteLine("Ошибка: такой игры нет в корзине.");
                return false;
            }

            Console.WriteLine($"Игра \"{game.Title}\" удалена из корзины.");
            return true;
        }

        public void PrintContents()
        {
            Console.WriteLine($"Содержимое корзины {_ownerName}:");

            if (_items.Count == 0)
            {
                Console.WriteLine("Корзина пуста.");
                return;
            }

            for (int i = 0; i < _items.Count; i++)
            {
                Console.WriteLine($"{i + 1}. {_items[i]}");
            }
        }

        public double CalculateTotal()
        {
            return _items.Sum(game => game.Price);
        }

        public int GetItemCount()
        {
            return _items.Count;
        }

        public override string ToString()
        {
            return $"Корзина: владелец {_ownerName}, " + $"количество игр: {_items.Count}, " + $"сумма: {CalculateTotal():F2}";
        }
    }
}