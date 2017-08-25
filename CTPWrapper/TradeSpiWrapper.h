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

		virtual void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateFieldWrapper^ pUserPasswordUpdate, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateFieldWrapper^ pTradingAccountPasswordUpdate, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}

		virtual void OnRspOrderInsert(CThostFtdcInputOrderFieldWrapper^ pInputOrder, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspParkedOrderInsert(CThostFtdcParkedOrderFieldWrapper^ pParkedOrder, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspParkedOrderAction(CThostFtdcParkedOrderActionFieldWrapper^ pParkedOrderAction, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspOrderAction(CThostFtdcInputOrderActionFieldWrapper^ pInputOrderAction, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeFieldWrapper^ pQueryMaxOrderVolume, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmFieldWrapper^ pSettlementInfoConfirm, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderFieldWrapper^ pRemoveParkedOrder, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionFieldWrapper^ pRemoveParkedOrderAction, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspExecOrderInsert(CThostFtdcInputExecOrderFieldWrapper^ pInputExecOrder, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspExecOrderAction(CThostFtdcInputExecOrderActionFieldWrapper^ pInputExecOrderAction, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspForQuoteInsert(CThostFtdcInputForQuoteFieldWrapper^ pInputForQuote, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspQuoteInsert(CThostFtdcInputQuoteFieldWrapper^ pInputQuote, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspQuoteAction(CThostFtdcInputQuoteActionFieldWrapper^ pInputQuoteAction, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionFieldWrapper^ pInputBatchOrderAction, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspCombActionInsert(CThostFtdcInputCombActionFieldWrapper^ pInputCombAction, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspQryOrder(CThostFtdcOrderFieldWrapper^ pOrder, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspQryTrade(CThostFtdcTradeFieldWrapper^ pTrade, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionFieldWrapper^ pInvestorPosition, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}


		virtual void OnRspError(CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
	};

}
