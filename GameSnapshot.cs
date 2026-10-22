using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace game_store
{
    public struct GameSnapshot
    {
        public string Title { get; set; }
        public double Price { get; set; }

        public GameSnapshot(string title, double price)
        {
            Title = title;
            Price = price;
        }

        public override string ToString()
        {
            return $"Снимок игры: {Title}, цена: {Price:F2}";
        }
    }
}