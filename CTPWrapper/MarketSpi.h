#pragma once

#include <msclr\auto_gcroot.h>
#include "ThostFtdcMdApi.h"
#include "MarketSpiWrapper.h"
#include "MyUnmanagedString.h"

namespace CTPWrapper {

#define COPY_ERROR_CODE \
	CThostFtdcRspInfoFieldWrapper^ csharpError = nullptr; \
	if (cppError) \
	{ \
		csharpError = gcnew CThostFtdcRspInfoFieldWrapper(); \
		csharpError->ErrorID = cppError->ErrorID; \
		COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg); \
	}

	class MarketSpi : public CThostFtdcMdSpi
	{
	public:
		MarketSpi(MarketSpiWrapper^ wrapper) : wrapper_(wrapper)
		{
		}

		void OnFrontConnected()
		{
			return wrapper_->OnFrontConnected();
		}

		virtual void OnFrontDisconnected(int nReason) override
		{
			return wrapper_->OnFrontDisconnected(nReason);
		}
		virtual void OnHeartBeatWarning(int nTimeLapse) override
		{
			return wrapper_->OnHeartBeatWarning(nTimeLapse);
		}
		void OnRspUserLogin(CThostFtdcRspUserLoginField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcRspUserLoginFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcRspUserLoginFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				COPY_UNMANAGED_STRING(csharpData->LoginTime, cppData->LoginTime);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				COPY_UNMANAGED_STRING(csharpData->SystemName, cppData->SystemName);
				csharpData->FrontID = cppData->FrontID;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->MaxOrderRef, cppData->MaxOrderRef);
				COPY_UNMANAGED_STRING(csharpData->SHFETime, cppData->SHFETime);
				COPY_UNMANAGED_STRING(csharpData->DCETime, cppData->DCETime);
				COPY_UNMANAGED_STRING(csharpData->CZCETime, cppData->CZCETime);
				COPY_UNMANAGED_STRING(csharpData->FFEXTime, cppData->FFEXTime);
				COPY_UNMANAGED_STRING(csharpData->INETime, cppData->INETime);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspUserLogin(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspUserLogout(CThostFtdcUserLogoutField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcUserLogoutFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcUserLogoutFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspUserLogout(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspSubMarketData(CThostFtdcSpecificInstrumentField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcSpecificInstrumentFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcSpecificInstrumentFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspSubMarketData(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcSpecificInstrumentFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcSpecificInstrumentFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspUnSubMarketData(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcSpecificInstrumentFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcSpecificInstrumentFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspSubForQuoteRsp(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcSpecificInstrumentFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcSpecificInstrumentFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspUnSubForQuoteRsp(csharpData, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField* cppData) override
		{
			CThostFtdcDepthMarketDataFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcDepthMarketDataFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeInstID, cppData->ExchangeInstID);
				csharpData->LastPrice = cppData->LastPrice;
				csharpData->PreSettlementPrice = cppData->PreSettlementPrice;
				csharpData->PreClosePrice = cppData->PreClosePrice;
				csharpData->PreOpenInterest = cppData->PreOpenInterest;
				csharpData->OpenPrice = cppData->OpenPrice;
				csharpData->HighestPrice = cppData->HighestPrice;
				csharpData->LowestPrice = cppData->LowestPrice;
				csharpData->Volume = cppData->Volume;
				csharpData->Turnover = cppData->Turnover;
				csharpData->OpenInterest = cppData->OpenInterest;
				csharpData->ClosePrice = cppData->ClosePrice;
				csharpData->SettlementPrice = cppData->SettlementPrice;
				csharpData->UpperLimitPrice = cppData->UpperLimitPrice;
				csharpData->LowerLimitPrice = cppData->LowerLimitPrice;
				csharpData->PreDelta = cppData->PreDelta;
				csharpData->CurrDelta = cppData->CurrDelta;
				COPY_UNMANAGED_STRING(csharpData->UpdateTime, cppData->UpdateTime);
				csharpData->UpdateMillisec = cppData->UpdateMillisec;
				csharpData->BidPrice1 = cppData->BidPrice1;
				csharpData->BidVolume1 = cppData->BidVolume1;
				csharpData->AskPrice1 = cppData->AskPrice1;
				csharpData->AskVolume1 = cppData->AskVolume1;
				csharpData->BidPrice2 = cppData->BidPrice2;
				csharpData->BidVolume2 = cppData->BidVolume2;
				csharpData->AskPrice2 = cppData->AskPrice2;
				csharpData->AskVolume2 = cppData->AskVolume2;
				csharpData->BidPrice3 = cppData->BidPrice3;
				csharpData->BidVolume3 = cppData->BidVolume3;
				csharpData->AskPrice3 = cppData->AskPrice3;
				csharpData->AskVolume3 = cppData->AskVolume3;
				csharpData->BidPrice4 = cppData->BidPrice4;
				csharpData->BidVolume4 = cppData->BidVolume4;
				csharpData->AskPrice4 = cppData->AskPrice4;
				csharpData->AskVolume4 = cppData->AskVolume4;
				csharpData->BidPrice5 = cppData->BidPrice5;
				csharpData->BidVolume5 = cppData->BidVolume5;
				csharpData->AskPrice5 = cppData->AskPrice5;
				csharpData->AskVolume5 = cppData->AskVolume5;
				csharpData->AveragePrice = cppData->AveragePrice;
				COPY_UNMANAGED_STRING(csharpData->ActionDay, cppData->ActionDay);
			}

			return wrapper_->OnRtnDepthMarketData(csharpData);
		}
		virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* cppData) override
		{
			CThostFtdcForQuoteRspFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcForQuoteRspFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->ForQuoteSysID, cppData->ForQuoteSysID);
				COPY_UNMANAGED_STRING(csharpData->ForQuoteTime, cppData->ForQuoteTime);
				COPY_UNMANAGED_STRING(csharpData->ActionDay, cppData->ActionDay);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
			}

			return wrapper_->OnRtnForQuoteRsp(csharpData);
		}


	private:
		msclr::auto_gcroot<MarketSpiWrapper^> wrapper_;
	};
}