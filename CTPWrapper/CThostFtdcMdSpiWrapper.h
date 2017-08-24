#pragma once

#include "CThostFtdcMdStructWrapper.h"

using namespace System;

namespace CTPWrapper {

	public ref class CThostFtdcMdSpiWrapper
	{
	public:
		virtual void OnFrontConnected() {}
		virtual void OnFrontDisconnected(int nReason) {}
		virtual void OnHeartBeatWarning(int nTimeLapse) {}

		virtual void OnRspUserLogin(CThostFtdcRspUserLoginFieldWrapper^ pRspUserLogin, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspUserLogout(CThostFtdcUserLogoutFieldWrapper^ pUserLogout, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}

		virtual void OnRspError(CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}

		virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentFieldWrapper^ pSpecificInstrument, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentFieldWrapper^ pSpecificInstrument, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentFieldWrapper^ pSpecificInstrument, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentFieldWrapper^ pSpecificInstrument, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}

		virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataFieldWrapper^ pDepthMarketData) {}
		virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspFieldWrapper^ pForQuoteRsp) {}
	};
}
