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
		virtual void OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateFieldWrapper^ pInstrumentOrderCommRate, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostFieldWrapper^ pOptionInstrTradeCost, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateFieldWrapper^ pOptionInstrCommRate, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryExecOrder(CThostFtdcExecOrderFieldWrapper^ pExecOrder, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryForQuote(CThostFtdcForQuoteFieldWrapper^ pForQuote, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryQuote(CThostFtdcQuoteFieldWrapper^ pQuote, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardFieldWrapper^ pCombInstrumentGuard, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryCombAction(CThostFtdcCombActionFieldWrapper^ pCombAction, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryTransferSerial(CThostFtdcTransferSerialFieldWrapper^ pTransferSerial, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryAccountregister(CThostFtdcAccountregisterFieldWrapper^ pAccountregister, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		
		virtual void OnRspError(CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}

		virtual void OnRtnOrder(CThostFtdcOrderFieldWrapper^ pOrder) {};
		virtual void OnRtnTrade(CThostFtdcTradeFieldWrapper^ pTrade) {};
		virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderFieldWrapper^ pInputOrder, CThostFtdcRspInfoFieldWrapper^ pRspInfo) {};
		virtual void OnErrRtnOrderAction(CThostFtdcOrderActionFieldWrapper^ pOrderAction, CThostFtdcRspInfoFieldWrapper^ pRspInfo) {};
		virtual void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusFieldWrapper^ pInstrumentStatus) {};
		virtual void OnRtnBulletin(CThostFtdcBulletinFieldWrapper^ pBulletin) {};
		virtual void OnRtnTradingNotice(CThostFtdcTradingNoticeInfoFieldWrapper^ pTradingNoticeInfo) {};
		virtual void OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderFieldWrapper^ pErrorConditionalOrder) {};
		virtual void OnRtnExecOrder(CThostFtdcExecOrderFieldWrapper^ pExecOrder) {};
		virtual void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderFieldWrapper^ pInputExecOrder, CThostFtdcRspInfoFieldWrapper^ pRspInfo) {};
		virtual void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionFieldWrapper^ pExecOrderAction, CThostFtdcRspInfoFieldWrapper^ pRspInfo) {};
		virtual void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteFieldWrapper^ pInputForQuote, CThostFtdcRspInfoFieldWrapper^ pRspInfo) {};
		virtual void OnRtnQuote(CThostFtdcQuoteFieldWrapper^ pQuote) {};
		virtual void OnErrRtnQuoteInsert(CThostFtdcInputQuoteFieldWrapper^ pInputQuote, CThostFtdcRspInfoFieldWrapper^ pRspInfo) {};
		virtual void OnErrRtnQuoteAction(CThostFtdcQuoteActionFieldWrapper^ pQuoteAction, CThostFtdcRspInfoFieldWrapper^ pRspInfo) {};
		virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspFieldWrapper^ pForQuoteRsp) {};
		virtual void OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenFieldWrapper^ pCFMMCTradingAccountToken) {};
		virtual void OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionFieldWrapper^ pBatchOrderAction, CThostFtdcRspInfoFieldWrapper^ pRspInfo) {};
		virtual void OnRtnCombAction(CThostFtdcCombActionFieldWrapper^ pCombAction) {};
		virtual void OnErrRtnCombActionInsert(CThostFtdcInputCombActionFieldWrapper^ pInputCombAction, CThostFtdcRspInfoFieldWrapper^ pRspInfo) {};
		virtual void OnRspQryContractBank(CThostFtdcContractBankFieldWrapper^ pContractBank, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryParkedOrder(CThostFtdcParkedOrderFieldWrapper^ pParkedOrder, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionFieldWrapper^ pParkedOrderAction, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryTradingNotice(CThostFtdcTradingNoticeFieldWrapper^ pTradingNotice, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsFieldWrapper^ pBrokerTradingParams, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosFieldWrapper^ pBrokerTradingAlgos, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenFieldWrapper^ pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRtnFromBankToFutureByBank(CThostFtdcRspTransferFieldWrapper^ pRspTransfer) {};
		virtual void OnRtnFromFutureToBankByBank(CThostFtdcRspTransferFieldWrapper^ pRspTransfer) {};
		virtual void OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealFieldWrapper^ pRspRepeal) {};
		virtual void OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealFieldWrapper^ pRspRepeal) {};
		virtual void OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferFieldWrapper^ pRspTransfer) {};
		virtual void OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferFieldWrapper^ pRspTransfer) {};
		virtual void OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealFieldWrapper^ pRspRepeal) {};
		virtual void OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealFieldWrapper^ pRspRepeal) {};
		virtual void OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountFieldWrapper^ pNotifyQueryAccount) {};
		virtual void OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferFieldWrapper^ pReqTransfer, CThostFtdcRspInfoFieldWrapper^ pRspInfo) {};
		virtual void OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferFieldWrapper^ pReqTransfer, CThostFtdcRspInfoFieldWrapper^ pRspInfo) {};
		virtual void OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealFieldWrapper^ pReqRepeal, CThostFtdcRspInfoFieldWrapper^ pRspInfo) {};
		virtual void OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealFieldWrapper^ pReqRepeal, CThostFtdcRspInfoFieldWrapper^ pRspInfo) {};
		virtual void OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountFieldWrapper^ pReqQueryAccount, CThostFtdcRspInfoFieldWrapper^ pRspInfo) {};
		virtual void OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealFieldWrapper^ pRspRepeal) {};
		virtual void OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealFieldWrapper^ pRspRepeal) {};
		virtual void OnRspFromBankToFutureByFuture(CThostFtdcReqTransferFieldWrapper^ pReqTransfer, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspFromFutureToBankByFuture(CThostFtdcReqTransferFieldWrapper^ pReqTransfer, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};
		virtual void OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountFieldWrapper^ pReqQueryAccount, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {};


	};

}
