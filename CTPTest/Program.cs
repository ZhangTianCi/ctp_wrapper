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

            int n = api_.SubscribeMarketData(new String[] { "rb1801", });
            Console.WriteLine("尝试订阅： {0}", n);

            /*
            CThostFtdcUserLogoutFieldWrapper logoutInfo = new CThostFtdcUserLogoutFieldWrapper();
            logoutInfo.BrokerID = "9999";
            logoutInfo.UserID = "100753";
            requestId_++;
            int ok = api_.ReqUserLogout(logoutInfo, requestId_);

            Console.WriteLine("尝试退出：{0}", ok == 0 ? "成功" : "失败");
            */
        }

		public override void OnRspUserLogout(CThostFtdcUserLogoutFieldWrapper pUserLogout, CThostFtdcRspInfoFieldWrapper pRspInfo, int nRequestID, bool bIsLast)
        {
            Console.WriteLine("OnRspUserLogout: BrokerId/UserId:{0}/{1}, nRequestID: {2}, last: {3}, error: {4}", pUserLogout.BrokerID, pUserLogout.UserID, nRequestID, bIsLast, pRspInfo.ErrorID);
        }

        public override void OnRspError(CThostFtdcRspInfoFieldWrapper pRspInfo, int nRequestID, bool bIsLast)
        {
            Console.WriteLine("[OnRspError] ErrorID:{0}, ErrorMsg:{1}, nRequestID:{2}, bIsLast:{3}", pRspInfo.ErrorID, pRspInfo.ErrorMsg, nRequestID, bIsLast);
        }

        public override void OnRspSubMarketData(CThostFtdcSpecificInstrumentFieldWrapper pSpecificInstrument, CThostFtdcRspInfoFieldWrapper pRspInfo, int nRequestID, bool bIsLast)
        {
            Console.WriteLine("OnRspSubMarketData: {0}, nRequestID: {1}, last: {2}", pSpecificInstrument.InstrumentID, nRequestID, bIsLast);
        }

        public override void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentFieldWrapper pSpecificInstrument, CThostFtdcRspInfoFieldWrapper pRspInfo, int nRequestID, bool bIsLast)
        {
            Console.WriteLine("[OnRspUnSubMarketData] {0}, nRequestID: {1}, last: {2}", pSpecificInstrument.InstrumentID, nRequestID, bIsLast);
        }
    }

    class Program
    {
        const string FRONT_ADDR = "tcp://180.168.146.187:10010";

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
