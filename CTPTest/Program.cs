using System;
using CTPWrapper;

namespace CTPTest
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("version: {0}", CThostFtdcMdApiWrapper.GetApiVersion());

            CThostFtdcMdApiWrapper mdapi = new CThostFtdcMdApiWrapper("", false, false);
            mdapi.Init();
            Console.WriteLine("trading day: {0}", mdapi.GetTradingDay());
            mdapi.Join();
            mdapi.Release();
        }
    }
}
