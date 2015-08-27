using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AssetCatalogBuilder
{
     enum LogSeverity
     {
         Debug = 0,
         Info = 1,
         Warning = 2,
         Error = 3
     };

    class SimpleLogger
    {
        public LogSeverity Severity { get; set; }

        public SimpleLogger(LogSeverity s)
        {
            Severity = s;
        }

        public void Log(LogSeverity s, String msg, params object[] args)
        {
            if ((int)s < (int)Severity)
                return;

            if (args.Length > 0)
                Console.WriteLine(msg, args);
            else
                Console.WriteLine(msg);

            if (s == LogSeverity.Error)
                Environment.Exit(1);
        }

        public void Debug(String msg, params object[] args)
        {
            Log(LogSeverity.Debug, msg, args);
        }

        public void Info(String msg, params object[] args)
        {
            Log(LogSeverity.Info, msg, args);
        }

        public void Warning(String msg, params object[] args)
        {
            Log(LogSeverity.Warning, msg, args);
        }

        public void Error(String msg, params object[] args)
        {
            Log(LogSeverity.Error, msg, args);
        }
    }
}
