using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace game_store
{
    public abstract class BaseVideoGame : IEquatable<BaseVideoGame>
    {
        protected String title;
        protected String genre;
        protected double price;
        protected List<String> description;

        private static int objectCount = 0;

        public String Title => title;
        public String Genre => genre;
        public double Price { get; private set; }

        protected BaseVideoGame(String title, String genre, double price, String description)
        {
            this.title = title;
            this.genre = genre;

            if (price < 0)
            {
                Console.WriteLine("Ошибка: цена игры не может быть отрицательной.");

                Price = 0;
            }

            else
            {
                Price = price;
            }

            this.price = Price;
            this.description = new List<String> { description };

            objectCount++;

            Console.WriteLine($"Конструктор BaseVideoGame: {this.title}");
        }

        protected BaseVideoGame() : this("Unknown", "Unknown", 0, "Описание отсутствует")
        {
        }

        protected BaseVideoGame(BaseVideoGame other)
        {
            title = other.title;
            genre = other.genre;
            price = other.price;
            Price = other.Price;

            description = new List<String>(other.description);

            objectCount++;

            Console.WriteLine($"Копирование BaseVideoGame: {title}");
        }

        public void ChangePrice(double newPrice)
        {
            if (newPrice < 0)
            {
                Console.WriteLine("Ошибка: новая цена не может быть отрицательной.");

                return;
            }

            Price = newPrice;
            price = newPrice;

            Console.WriteLine($"Цена игры \"{Title}\" изменена на {Price:F2}");
        }

        public virtual void Describe()
        {
            Console.WriteLine($"Игра: {Title}, жанр: {Genre}, цена: {Price:F2}");
        }

        public abstract String GetPlatform();

        public abstract BaseVideoGame Clone();

        public void PrintInfo()
        {
            Describe();

            Console.WriteLine($"Платформа: {GetPlatform()}");

            Console.WriteLine($"Описание: {string.Join(", ", description)}");
        }

        public BaseVideoGame ShallowCopy()
        {
            objectCount++;

            return (BaseVideoGame)MemberwiseClone();
        }

        public void ChangeDescription(String newDescription)
        {
            description[0] = newDescription;
        }

        public void AddToCollection(
            List<BaseVideoGame> collection)
        {
            collection.Add(this);
        }

        public static int GetObjectCount()
        {
            return objectCount;
        }

        public void ProcessTitle()
        {
            String fullTitle = Title + " - " + Genre;

            Console.WriteLine($"Полное название: {fullTitle}");

            int position = fullTitle.IndexOf(Genre);

            if (position >= 0)
            {
                Console.WriteLine($"Жанр найден в позиции: {position}");
            }

            Console.WriteLine($"Первые символы: {Title.Substring(0, Math.Min(3, Title.Length))}");

            if (Title == "Minecraft")
            {
                Console.WriteLine("Найдена игра Minecraft.");
            }
        }

        public bool Equals(BaseVideoGame other)
        {
            if (other is null)
            {
                return false;
            }

            return Title == other.Title && Genre == other.Genre && Price == other.Price;
        }

        public override bool Equals(object obj)
        {
            return obj is BaseVideoGame other && Equals(other);
        }

        public override string ToString()
        {
            return $"Игра: {Title}, жанр: {Genre}, цена: {Price:F2}";
        }

        ~BaseVideoGame()
        {
            Console.WriteLine($"Финализатор BaseVideoGame: {title}");

            objectCount--;
        }
    }

    public class OfflineVideoGame : BaseVideoGame
    {
        public OfflineVideoGame(String title, String genre, double price) : base(title, genre, price, "Обычная видеоигра")
        {
            Console.WriteLine($"Создана видеоигра: {Title}");
        }

        public OfflineVideoGame() : this("Unknown", "Unknown", 0)
        {
        }

        public OfflineVideoGame(OfflineVideoGame other) : base(other)
        {
            Console.WriteLine($"Копирование VideoGame: {Title}");
        }

        public override void Describe()
        {
            base.Describe();

            Console.WriteLine("Тип: обычная видеоигра");
        }

        public override String GetPlatform()
        {
            return "PC / Console";
        }

        public override BaseVideoGame Clone()
        {
            return new OfflineVideoGame(this);
        }
    }

    public sealed class OnlineVideoGame : BaseVideoGame
    {
        public OnlineVideoGame(String title, String genre, double price) : base(title, genre, price, "Онлайн-видеоигра с сетевым режимом")
        {
            Console.WriteLine($"Создана онлайн-видеоигра: {Title}");
        }

        public OnlineVideoGame() : this("Unknown Online", "Online", 0)
        {
        }

        public override void Describe()
        {
            Console.WriteLine($"Онлайн-игра: {Title}, жанр: {Genre}, цена: {Price:F2}");
        }

        public override String GetPlatform()
        {
            return "Online / Multiplayer";
        }

        public override BaseVideoGame Clone()
        {
            return new OnlineVideoGame(Title, Genre, Price);
        }
    }
}