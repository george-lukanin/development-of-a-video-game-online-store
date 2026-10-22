using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace game_store
{
    public sealed class ResourceJournal : IDisposable
    {
        private bool _disposed;

        public ResourceJournal()
        {
            Console.WriteLine("Журнал выдачи создан: ресурс открыт.");
        }

        public void Write(string message)
        {
            Console.WriteLine($"Запись в журнал: {message}");
        }

        public void Dispose()
        {
            if (_disposed)
                return;

            _disposed = true;
            Console.WriteLine("Журнал выдачи закрыт: ресурс освобождён.");
        }
    }
}