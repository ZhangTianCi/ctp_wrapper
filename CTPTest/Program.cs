using System;
using CTPWrapper;

namespace CTPTest
{
    class MyDataController : CThostFtdcMdSpiWrapper
    {
        public override void OnFrontConnected()
        {
            Console.WriteLine("OnFrontConnected");
        }

        public override void OnFrontDisconnected(int nReason)
        {
            Console.WriteLine("OnFrontDisconnected: {0}", nReason);
        }
    }

    class Program
    {
        const string FRONT_ADDR = "tcp://180.168.146.187:10000";

        static void Main(string[] args)
        {
            Console.WriteLine("version: {0}", CThostFtdcMdApiWrapper.GetApiVersion());

            CThostFtdcMdApiWrapper mdapi = new CThostFtdcMdApiWrapper("", false, false);
            mdapi.RegisterSpi(new MyDataController());
            mdapi.RegisterFront(FRONT_ADDR);

            mdapi.Init();
            mdapi.Join();
        }
    }
}
