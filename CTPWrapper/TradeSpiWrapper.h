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
		virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountFieldWrapper^ pTradingAccount, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspQryInvestor(CThostFtdcInvestorFieldWrapper^ pInvestor, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspQryTradingCode(CThostFtdcTradingCodeFieldWrapper^ pTradingCode, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
		virtual void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateFieldWrapper^ pInstrumentMarginRate, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateFieldWrapper^ pInstrumentCommissionRate, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryExchange(CThostFtdcExchangeFieldWrapper^ pExchange, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryProduct(CThostFtdcProductFieldWrapper^ pProduct, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryInstrument(CThostFtdcInstrumentFieldWrapper^ pInstrument, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataFieldWrapper^ pDepthMarketData, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQrySettlementInfo(CThostFtdcSettlementInfoFieldWrapper^ pSettlementInfo, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryTransferBank(CThostFtdcTransferBankFieldWrapper^ pTransferBank, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailFieldWrapper^ pInvestorPositionDetail, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryNotice(CThostFtdcNoticeFieldWrapper^ pNotice, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmFieldWrapper^ pSettlementInfoConfirm, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailFieldWrapper^ pInvestorPositionCombineDetail, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyFieldWrapper^ pCFMMCTradingAccountKey, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetFieldWrapper^ pEWarrantOffset, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginFieldWrapper^ pInvestorProductGroupMargin, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateFieldWrapper^ pExchangeMarginRate, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustFieldWrapper^ pExchangeMarginRateAdjust, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryExchangeRate(CThostFtdcExchangeRateFieldWrapper^ pExchangeRate, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapFieldWrapper^ pSecAgentACIDMap, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryProductExchRate(CThostFtdcProductExchRateFieldWrapper^ pProductExchRate, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryProductGroup(CThostFtdcProductGroupFieldWrapper^ pProductGroup, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateFieldWrapper^ pMMInstrumentCommissionRate, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateFieldWrapper^ pMMOptionInstrCommRate, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};




		virtual void OnRspError(CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
	};

}
