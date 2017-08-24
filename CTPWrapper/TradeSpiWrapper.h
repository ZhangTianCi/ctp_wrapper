#pragma once

#include "CtpStructWrapper.h"

using namespace System;

namespace CTPWrapper {

	public ref class TradeSpiWrapper
	{
	public:
		virtual void OnFrontConnected() {}
		virtual void OnFrontDisconnected(int nReason) {}
		virtual void OnHeartBeatWarning(int nTimeLapse) {}

		virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateFieldWrapper^ pRspAuthenticateField, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}

		virtual void OnRspUserLogin(CThostFtdcRspUserLoginFieldWrapper^ pRspUserLogin, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspUserLogout(CThostFtdcUserLogoutFieldWrapper^ pUserLogout, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}




		virtual void OnRspError(CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
	};

}
