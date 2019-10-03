using System;
using System.IO;

namespace ConsoleApp30
{
    class Program
    {
        static void Main(string[] args)
        {
            string filePath = "test2.txt";
            if (!File.Exists(filePath))
            {
                var handler = File.Create(filePath);
                handler.Close();
            }

            using (StreamWriter writer = new StreamWriter(filePath))
            {
                writer.WriteLine(2);
                writer.WriteLine("100000 99999 0");

                for (int i = 0; i != 99999; i++)
                {
                    writer.WriteLine($"0 {i + 1}");
                }

                writer.WriteLine("100000 99999 0");

                for (int i = 0; i != 99999; i++)
                {
                    writer.WriteLine($"0 {i + 1}");
                }
            }
        }
    }
}
