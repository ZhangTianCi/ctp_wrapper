#pragma once

#include <msclr\auto_gcroot.h>
#include "ThostFtdcMdApi.h"
#include "MarketSpiWrapper.h"
#include "MyUnmanagedString.h"

namespace CTPWrapper {

#define COPY_ERROR_CODE \
	CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper(); \
	if (cppError) \
	{ \
		csharpError->ErrorID = cppError->ErrorID; \
		COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg); \
	} \
	else \
	{ \
		csharpError->ErrorID = 0; \
		COPY_UNMANAGED_STRING(csharpError->ErrorMsg, ""); \
	}

	class MarketSpi : public CThostFtdcMdSpi
	{
	public:
		MarketSpi(MarketSpiWrapper^ wrapper) : wrapper_(wrapper)
		{
		}

		virtual void OnFrontConnected() override
		{
			wrapper_->OnFrontConnected();
		}

		virtual void OnFrontDisconnected(int nReason) override
		{
			wrapper_->OnFrontDisconnected(nReason);
		}

		virtual void OnHeartBeatWarning(int nTimeLapse) override
		{
			wrapper_->OnHeartBeatWarning(nTimeLapse);
		}

		virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcRspUserLoginFieldWrapper^ rspUserLogin = gcnew CThostFtdcRspUserLoginFieldWrapper();
			
			COPY_UNMANAGED_STRING(rspUserLogin->TradingDay, pRspUserLogin->TradingDay);
			COPY_UNMANAGED_STRING(rspUserLogin->LoginTime, pRspUserLogin->LoginTime);
			COPY_UNMANAGED_STRING(rspUserLogin->BrokerID, pRspUserLogin->BrokerID);
			COPY_UNMANAGED_STRING(rspUserLogin->UserID, pRspUserLogin->UserID);
			COPY_UNMANAGED_STRING(rspUserLogin->SystemName, pRspUserLogin->SystemName);
			rspUserLogin->FrontID = pRspUserLogin->FrontID;
			rspUserLogin->SessionID = pRspUserLogin->SessionID;
			COPY_UNMANAGED_STRING(rspUserLogin->MaxOrderRef, pRspUserLogin->MaxOrderRef);
			COPY_UNMANAGED_STRING(rspUserLogin->SHFETime, pRspUserLogin->SHFETime);
			COPY_UNMANAGED_STRING(rspUserLogin->DCETime, pRspUserLogin->DCETime);
			COPY_UNMANAGED_STRING(rspUserLogin->CZCETime, pRspUserLogin->CZCETime);
			COPY_UNMANAGED_STRING(rspUserLogin->FFEXTime, pRspUserLogin->FFEXTime);
			COPY_UNMANAGED_STRING(rspUserLogin->INETime, pRspUserLogin->INETime);

			COPY_ERROR_CODE;

			wrapper_->OnRspUserLogin(rspUserLogin, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcUserLogoutFieldWrapper^ csharpUserLogout = gcnew CThostFtdcUserLogoutFieldWrapper();
			COPY_UNMANAGED_STRING(csharpUserLogout->BrokerID, pUserLogout->BrokerID);
			COPY_UNMANAGED_STRING(csharpUserLogout->UserID, pUserLogout->UserID);

			COPY_ERROR_CODE;

			wrapper_->OnRspUserLogout(csharpUserLogout, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspError(CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast)
		{
			COPY_ERROR_CODE;

			wrapper_->OnRspError(csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcSpecificInstrumentFieldWrapper^ csharpInstrument = gcnew CThostFtdcSpecificInstrumentFieldWrapper();
			COPY_UNMANAGED_STRING(csharpInstrument->InstrumentID, pSpecificInstrument->InstrumentID);

			COPY_ERROR_CODE;

			wrapper_->OnRspSubMarketData(csharpInstrument, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcSpecificInstrumentFieldWrapper^ csharpInstrument = gcnew CThostFtdcSpecificInstrumentFieldWrapper();
			COPY_UNMANAGED_STRING(csharpInstrument->InstrumentID, pSpecificInstrument->InstrumentID);

			COPY_ERROR_CODE;

			wrapper_->OnRspUnSubMarketData(csharpInstrument, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcSpecificInstrumentFieldWrapper^ csharpInstrument = gcnew CThostFtdcSpecificInstrumentFieldWrapper();
			COPY_UNMANAGED_STRING(csharpInstrument->InstrumentID, pSpecificInstrument->InstrumentID);

			COPY_ERROR_CODE;

			wrapper_->OnRspSubForQuoteRsp(csharpInstrument, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcSpecificInstrumentFieldWrapper^ csharpInstrument = gcnew CThostFtdcSpecificInstrumentFieldWrapper();
			COPY_UNMANAGED_STRING(csharpInstrument->InstrumentID, pSpecificInstrument->InstrumentID);

			COPY_ERROR_CODE;

			wrapper_->OnRspUnSubForQuoteRsp(csharpInstrument, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
		{
			CThostFtdcDepthMarketDataFieldWrapper^ csharpData = gcnew CThostFtdcDepthMarketDataFieldWrapper();
			COPY_UNMANAGED_STRING(csharpData->TradingDay, pDepthMarketData->TradingDay);
			COPY_UNMANAGED_STRING(csharpData->InstrumentID, pDepthMarketData->InstrumentID);
			COPY_UNMANAGED_STRING(csharpData->ExchangeID, pDepthMarketData->ExchangeID);
			COPY_UNMANAGED_STRING(csharpData->ExchangeInstID, pDepthMarketData->ExchangeInstID);
			csharpData->LastPrice = pDepthMarketData->LastPrice;
			csharpData->PreSettlementPrice = pDepthMarketData->PreSettlementPrice;
			csharpData->PreClosePrice = pDepthMarketData->PreClosePrice;
			csharpData->PreOpenInterest = pDepthMarketData->PreOpenInterest;
			csharpData->OpenPrice = pDepthMarketData->OpenPrice;
			csharpData->HighestPrice = pDepthMarketData->HighestPrice;
			csharpData->LowestPrice = pDepthMarketData->LowestPrice;
			csharpData->Volume = pDepthMarketData->Volume;
			csharpData->Turnover = pDepthMarketData->Turnover;
			csharpData->OpenInterest = pDepthMarketData->OpenInterest;
			csharpData->ClosePrice = pDepthMarketData->ClosePrice;
			csharpData->SettlementPrice = pDepthMarketData->SettlementPrice;
			csharpData->UpperLimitPrice = pDepthMarketData->UpperLimitPrice;
			csharpData->LowerLimitPrice = pDepthMarketData->LowerLimitPrice;
			csharpData->PreDelta = pDepthMarketData->PreDelta;
			csharpData->CurrDelta = pDepthMarketData->CurrDelta;
			COPY_UNMANAGED_STRING(csharpData->UpdateTime, pDepthMarketData->UpdateTime);
			csharpData->UpdateMillisec = pDepthMarketData->UpdateMillisec;

			csharpData->BidPrice1 = pDepthMarketData->BidPrice1;
			csharpData->BidVolume1 = pDepthMarketData->BidVolume1;
			csharpData->AskPrice1 = pDepthMarketData->AskPrice1;
			csharpData->AskVolume1 = pDepthMarketData->AskVolume1;

			csharpData->BidPrice2 = pDepthMarketData->BidPrice2;
			csharpData->BidVolume2 = pDepthMarketData->BidVolume2;
			csharpData->AskPrice2 = pDepthMarketData->AskPrice2;
			csharpData->AskVolume2 = pDepthMarketData->AskVolume2;

			csharpData->BidPrice3 = pDepthMarketData->BidPrice3;
			csharpData->BidVolume3 = pDepthMarketData->BidVolume3;
			csharpData->AskPrice3 = pDepthMarketData->AskPrice3;
			csharpData->AskVolume3 = pDepthMarketData->AskVolume3;

			csharpData->BidPrice4 = pDepthMarketData->BidPrice4;
			csharpData->BidVolume4 = pDepthMarketData->BidVolume4;
			csharpData->AskPrice4 = pDepthMarketData->AskPrice4;
			csharpData->AskVolume4 = pDepthMarketData->AskVolume4;

			csharpData->BidPrice5 = pDepthMarketData->BidPrice5;
			csharpData->BidVolume5 = pDepthMarketData->BidVolume5;
			csharpData->AskPrice5 = pDepthMarketData->AskPrice5;
			csharpData->AskVolume5 = pDepthMarketData->AskVolume5;

			csharpData->AveragePrice = pDepthMarketData->AveragePrice;
			COPY_UNMANAGED_STRING(csharpData->ActionDay, pDepthMarketData->ActionDay);

			wrapper_->OnRtnDepthMarketData(csharpData);
		}

		virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp)
		{
			CThostFtdcForQuoteRspFieldWrapper^ csharpData = gcnew CThostFtdcForQuoteRspFieldWrapper();
			COPY_UNMANAGED_STRING(csharpData->TradingDay, pForQuoteRsp->TradingDay);
			COPY_UNMANAGED_STRING(csharpData->InstrumentID, pForQuoteRsp->InstrumentID);
			COPY_UNMANAGED_STRING(csharpData->ForQuoteSysID, pForQuoteRsp->ForQuoteSysID);
			COPY_UNMANAGED_STRING(csharpData->ForQuoteTime, pForQuoteRsp->ForQuoteTime);
			COPY_UNMANAGED_STRING(csharpData->ActionDay, pForQuoteRsp->ActionDay);
			COPY_UNMANAGED_STRING(csharpData->ExchangeID, pForQuoteRsp->ExchangeID);

			wrapper_->OnRtnForQuoteRsp(csharpData);
		}

	private:
		msclr::auto_gcroot<MarketSpiWrapper^> wrapper_;
	};
}