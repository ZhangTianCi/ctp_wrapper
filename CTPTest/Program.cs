using System;
using CTPWrapper;

namespace CTPTest
{
    class MyMarketSpi : MarketSpiWrapper
    {
        private MarketApiWrapper api_ = null;
        private int requestId_ = 0;

        public MyMarketSpi(MarketApiWrapper api)
        {
            api_ = api;
        }

        public override void OnFrontConnected()
        {
            Console.WriteLine("OnFrontConnected");

            CThostFtdcReqUserLoginFieldWrapper loginInfo = new CThostFtdcReqUserLoginFieldWrapper();
            loginInfo.BrokerID = "9999";
            loginInfo.UserID   = "100753";
            loginInfo.Password = "a1202b";
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
            Console.WriteLine("[OnRspSubMarketData] {0}, nRequestID: {1}, last: {2}", pSpecificInstrument.InstrumentID, nRequestID, bIsLast);
        }

        public override void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentFieldWrapper pSpecificInstrument, CThostFtdcRspInfoFieldWrapper pRspInfo, int nRequestID, bool bIsLast)
        {
            Console.WriteLine("[OnRspUnSubMarketData] {0}, nRequestID: {1}, last: {2}", pSpecificInstrument.InstrumentID, nRequestID, bIsLast);
        }

        public override void OnRtnDepthMarketData(CThostFtdcDepthMarketDataFieldWrapper pDepthMarketData)
        {
            Console.WriteLine("[OnRtnDepthMarketData] {0}, 最新价：{1}", pDepthMarketData.InstrumentID, pDepthMarketData.LastPrice);
        }

        public override void OnRtnForQuoteRsp(CThostFtdcForQuoteRspFieldWrapper pForQuoteRsp)
        {
            Console.WriteLine("[OnRtnDepthMarketData] {0}", pForQuoteRsp.InstrumentID);
        }
    }


    class MyTradeSpi : TradeSpiWrapper
    {
        private TradeApiWrapper api_ = null;
        private int requestId_ = 0;

        public MyTradeSpi(TradeApiWrapper api)
        {
            api_ = api;
        }

        public int GetNextRequestId()
        {
            ++requestId_;
            return requestId_;
        }

        public override void OnRspError(CThostFtdcRspInfoFieldWrapper pRspInfo, int nRequestID, bool bIsLast)
        {
            Console.WriteLine("[Trade][OnRspError] ErrorID:{0}, ErrorMsg:{1}, nRequestID:{2}, bIsLast:{3}", pRspInfo.ErrorID, pRspInfo.ErrorMsg, nRequestID, bIsLast);
        }

        public override void OnFrontConnected()
        {
            Console.WriteLine("[Trade][OnFrontConnected]");


            CThostFtdcReqUserLoginFieldWrapper loginInfo = new CThostFtdcReqUserLoginFieldWrapper();
            loginInfo.BrokerID = "9999";
            loginInfo.UserID = "100753";
            loginInfo.Password = "a1202b";
            int requestId = GetNextRequestId();
            int ok = api_.ReqUserLogin(loginInfo, requestId);
            Console.WriteLine("尝试登录：{0}, requestId：{1}", ok, requestId);


            CThostFtdcReqAuthenticateFieldWrapper auth = new CThostFtdcReqAuthenticateFieldWrapper();
            auth.BrokerID = "9999";
            auth.UserID = "100753";
            requestId = GetNextRequestId();
            ok = api_.ReqAuthenticate(auth, requestId);
            Console.WriteLine("尝试认证：{0}, requestId：{1}", ok, requestId);
        }

        public override void OnFrontDisconnected(int nReason)
        {
            Console.WriteLine("[Trade][OnFrontConnected] nReason:{0}", nReason);
        }

        public override void OnRspUserLogin(CThostFtdcRspUserLoginFieldWrapper pRspUserLogin, CThostFtdcRspInfoFieldWrapper pRspInfo, int nRequestID, bool bIsLast)
        {
            Console.WriteLine("[Trade][OnRspUserLogin] nRequestID:{0}, bIsLast:{1}", nRequestID, bIsLast);
            Console.WriteLine("  TradingDay: {0}", pRspUserLogin.TradingDay);
            // Console.WriteLine("  LoginTime: {0}", pRspUserLogin.LoginTime);
            // Console.WriteLine("  SystemName: {0}", pRspUserLogin.SystemName);
            Console.WriteLine("  ErrorID: {0}", pRspInfo.ErrorID);
            Console.WriteLine("  ErrorMsg: {0}", pRspInfo.ErrorMsg);

            /*
            if (pRspInfo.ErrorID == 0)
            {
                CThostFtdcUserPasswordUpdateFieldWrapper req = new CThostFtdcUserPasswordUpdateFieldWrapper();
                req.BrokerID = "9999";
                req.UserID = "100753";
                req.OldPassword = "666009";
                req.NewPassword = "a1202b";
                int ok = api_.ReqUserPasswordUpdate(req, GetNextRequestId());
                Console.WriteLine("  尝试修改密码: {0}", ok);
            }
            */
        }

        public override void OnRspAuthenticate(CThostFtdcRspAuthenticateFieldWrapper pRspAuthenticateField, CThostFtdcRspInfoFieldWrapper pRspInfo, int nRequestID, bool bIsLast)
        {
            Console.WriteLine("[Trade][OnRspAuthenticate] nRequestID:{0}, bIsLast:{1}", nRequestID, bIsLast);
            Console.WriteLine("  BrokerID: {0}", pRspAuthenticateField.BrokerID);
            Console.WriteLine("  UserID: {0}", pRspAuthenticateField.UserID);
            Console.WriteLine("  ErrorID: {0}", pRspInfo.ErrorID);
            Console.WriteLine("  ErrorMsg: {0}", pRspInfo.ErrorMsg);
        }

        public override void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateFieldWrapper pUserPasswordUpdate, CThostFtdcRspInfoFieldWrapper pRspInfo, int nRequestID, bool bIsLast)
        {
            Console.WriteLine("[Trade][OnRspUserPasswordUpdate] nRequestID:{0}, bIsLast:{1}", nRequestID, bIsLast);
            Console.WriteLine("  ErrorID: {0}", pRspInfo.ErrorID);
            Console.WriteLine("  ErrorMsg: {0}", pRspInfo.ErrorMsg);
        }
    }

    class Program
    {
        const string TRADE_FRONT_ADDR  = "tcp://180.168.146.187:10000";
        const string MARKET_FRONT_ADDR = "tcp://180.168.146.187:10010";

        static void TradeApiTest()
        {
            Console.WriteLine("trade api version: {0}", TradeApiWrapper.GetApiVersion());


            TradeApiWrapper api = new TradeApiWrapper("");
            api.RegisterSpi(new MyTradeSpi(api));
            api.RegisterFront(TRADE_FRONT_ADDR);

            api.Init();
            api.Join();
        }

        static void MarketApiTest()
        {
            Console.WriteLine("market api version: {0}", MarketApiWrapper.GetApiVersion());

            MarketApiWrapper mdapi = new MarketApiWrapper("", false, false);
            mdapi.RegisterSpi(new MyMarketSpi(mdapi));
            mdapi.RegisterFront(MARKET_FRONT_ADDR);

            mdapi.Init();
            mdapi.Join();
        }

        static void Main(string[] args)
        {
            TradeApiTest();
            // MarketApiTest();
        }
    }
}
