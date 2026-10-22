using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace game_store
{
    public class Buyer
    {
        private readonly string _name;
        private readonly Cart _cart;

        public string Name => _name;

        public Buyer(string name)
        {
            _name = name;
            _cart = new Cart(name);

            Console.WriteLine($"Создан покупатель: {_name}");
        }

        public bool AddGameToCart(VideoGame game)
        {
            return _cart.AddGame(game);
        }

        public bool RemoveGameFromCart(VideoGame game)
        {
            return _cart.RemoveGame(game);
        }

        public void PrintProfile()
        {
            Console.WriteLine($"Покупатель: {_name}");
            _cart.PrintContents();
        }

        public void Checkout()
        {
            if (_cart.GetItemCount() == 0)
            {
                Console.WriteLine("Ошибка: невозможно оформить пустую корзину.");
                return;
            }

            Console.WriteLine($"Заказ оформлен. Сумма: {_cart.CalculateTotal():F2}");
        }

        public override string ToString()
        {
            return $"Покупатель: {_name}";
        }
    }
}