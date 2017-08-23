using System;
using CTPWrapper;

namespace CTPTest
{
    class MyDataController : CThostFtdcMdSpiWrapper
    {
        private CThostFtdcMdApiWrapper api_ = null;
        private int requestId_ = 0;

        public MyDataController(CThostFtdcMdApiWrapper api)
        {
            api_ = api;
        }

        public override void OnFrontConnected()
        {
            Console.WriteLine("OnFrontConnected");

            CThostFtdcReqUserLoginFieldWrapper loginInfo = new CThostFtdcReqUserLoginFieldWrapper();
            loginInfo.BrokerID = "9999";
            loginInfo.UserID   = "100753";
            loginInfo.Password = "666009";
            requestId_++;
            int ok = api_.ReqUserLogin(loginInfo, requestId_);

            Console.WriteLine("尝试登录：{0}", ok == 0 ? "成功" : "失败");
        }

        public override void OnFrontDisconnected(int nReason)
        {
            Console.WriteLine("OnFrontDisconnected: {0}", nReason);
        }

        public override void OnRspUserLogin(CThostFtdcRspUserLoginFieldWrapper pRspUserLogin, CThostFtdcRspInfoFieldWrapper pRspInfo, int nRequestID, bool bIsLast)
        {
            Console.WriteLine("OnRspUserLogin: {0}, nRequestID: {1}, last: {2}, error: {3}", pRspUserLogin.TradingDay, nRequestID, bIsLast, pRspInfo.ErrorID);
            int n = api_.SubscribeMarketData(new String[] { "ni1701", "rb1701" });
            Console.WriteLine("OnRspUserLogin: sub: {0}", n);
        }

        public override void OnRspSubMarketData(CThostFtdcSpecificInstrumentFieldWrapper pSpecificInstrument, CThostFtdcRspInfoFieldWrapper pRspInfo, int nRequestID, bool bIsLast)
        {
            Console.WriteLine("OnRspSubMarketData: {0}, nRequestID: {1}, last: {2}", pSpecificInstrument.InstrumentID, nRequestID, bIsLast);
        }
    }

    class Program
    {
        const string FRONT_ADDR = "tcp://180.168.146.187:10000";

        static void Main(string[] args)
        {
            Console.WriteLine("version: {0}", CThostFtdcMdApiWrapper.GetApiVersion());

            CThostFtdcMdApiWrapper mdapi = new CThostFtdcMdApiWrapper("", false, false);
            mdapi.RegisterSpi(new MyDataController(mdapi));
            mdapi.RegisterFront(FRONT_ADDR);

            mdapi.Init();
            mdapi.Join();
        }
    }
}
