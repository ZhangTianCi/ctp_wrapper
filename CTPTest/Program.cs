using System;
using CTPWrapper;

namespace CTPTest
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("version: {0}", CThostFtdcMdApiWrapper.GetApiVersion());
        }
    }
}
