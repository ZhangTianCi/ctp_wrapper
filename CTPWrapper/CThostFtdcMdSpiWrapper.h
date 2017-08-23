#pragma once

using namespace System;

namespace CTPWrapper {

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

	public ref class CThostFtdcMdSpiWrapper
	{
	public:
		virtual void OnFrontConnected() {}
		virtual void OnFrontDisconnected(int nReason) {}
		virtual void OnHeartBeatWarning(int nTimeLapse) {}

		virtual void OnRspUserLogin(CThostFtdcRspUserLoginFieldWrapper^ pRspUserLogin, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}

		virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentFieldWrapper^ pSpecificInstrument, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
	};
}
