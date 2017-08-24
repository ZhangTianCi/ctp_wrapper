#pragma once

using namespace System;

namespace CTPWrapper {

	public ref struct CThostFtdcFensUserInfoFieldWrapper
	{
		String^ BrokerID;             //经纪公司代码
		String^ UserID;               //用户代码
		char LoginMode;               //登录模式
	};

	public ref struct CThostFtdcReqUserLoginFieldWrapper
	{
		String^ TradingDay;           // 交易日
		String^ BrokerID;             // 经纪公司代码
		String^ UserID;               // 用户代码
		String^ Password;             // 密码
		String^ UserProductInfo;      // 用户端产品信息
		String^ InterfaceProductInfo; // 接口端产品信息
		String^ ProtocolInfo;         // 协议信息
		String^ MacAddress;           // Mac地址
		String^ OneTimePassword;      // 动态密码
		String^ ClientIPAddress;      // 终端IP地址
		String^ LoginRemark;          // 登录备注
	};

	public ref struct CThostFtdcUserLogoutFieldWrapper
	{
		String^ BrokerID;             //经纪公司代码
		String^ UserID;               //用户代码
	};

	public ref struct CThostFtdcRspUserLoginFieldWrapper
	{
		String^ TradingDay;      // 交易日
		String^ LoginTime;       // 登录成功时间
		String^ BrokerID;        // 经纪公司代码
		String^ UserID;          // 用户代码
		String^ SystemName;      // 交易系统名称
		int FrontID;            // 前置编号
		int SessionID;          // 会话编号
		String^ MaxOrderRef;     // 最大报单引用
		String^ SHFETime;        // 上期所时间
		String^ DCETime;         // 大商所时间
		String^ CZCETime;        // 郑商所时间
		String^ FFEXTime;        // 中金所时间
		String^ INETime;         // 能源中心时间
	};

	public ref struct CThostFtdcRspInfoFieldWrapper
	{
		int	ErrorID;
		String^ ErrorMsg;
	};

	public ref struct CThostFtdcSpecificInstrumentFieldWrapper
	{
		String^ InstrumentID;
	};

	public ref struct CThostFtdcDepthMarketDataFieldWrapper
	{
		String^ TradingDay;          //交易日
		String^ InstrumentID;        //合约代码
		String^ ExchangeID;          //交易所代码
		String^ ExchangeInstID;      //合约在交易所的代码
		double LastPrice;            //最新价
		double PreSettlementPrice;   //上次结算价
		double PreClosePrice;        //昨收盘
		double PreOpenInterest;      //昨持仓量
		double OpenPrice;            //今开盘
		double HighestPrice;         //最高价
		double LowestPrice;          //最低价
		int Volume;                  //数量
		double Turnover;             //成交金额
		double OpenInterest;         //持仓量
		double ClosePrice;           //今收盘
		double SettlementPrice;      //本次结算价
		double UpperLimitPrice;      //涨停板价
		double LowerLimitPrice;      //跌停板价
		double PreDelta;             //昨虚实度
		double CurrDelta;            //今虚实度
		String^ UpdateTime;          //最后修改时间
		int UpdateMillisec;          //最后修改毫秒
		double BidPrice1;            //申买价1
		int BidVolume1;              //申买量1
		double AskPrice1;            //申卖价1
		int AskVolume1;              //申卖量1
		double BidPrice2;            //申买价2
		int BidVolume2;              //申买量2
		double AskPrice2;            //申卖价2
		int AskVolume2;              //申卖量2
		double BidPrice3;            //申买价3
		int BidVolume3;              //申买量3
		double AskPrice3;            //申卖价3
		int AskVolume3;              //申卖量3
		double BidPrice4;            //申买价4
		int BidVolume4;              //申买量4
		double AskPrice4;            //申卖价4
		int AskVolume4;              //申卖量4
		double BidPrice5;            //申买价5
		int BidVolume5;              //申买量5
		double AskPrice5;            //申卖价5
		int AskVolume5;              //申卖量5
		double AveragePrice;         //当日均价
		String^ ActionDay;           //业务日期
	};

	public ref struct CThostFtdcForQuoteRspFieldWrapper
	{
		String^ TradingDay;
		String^ InstrumentID;
		String^ ForQuoteSysID;
		String^ ForQuoteTime;
		String^ ActionDay;
		String^ ExchangeID;
	};

	public ref struct CThostFtdcRspAuthenticateFieldWrapper
	{
		String^ BrokerID;
		String^ UserID;
		String^ UserProductInfo;
	};

	public ref struct CThostFtdcUserPasswordUpdateFieldWrapper
	{
		String^ BrokerID;
		String^ UserID;
		String^ OldPassword;
		String^ NewPassword;
	};

	public ref struct CThostFtdcTradingAccountPasswordUpdateFieldWrapper
	{
		String^ BrokerID;
		String^ AccountID;
		String^ OldPassword;
		String^ NewPassword;
		String^ CurrencyID;
	};

}