#pragma once

#include <msclr\auto_gcroot.h>
#include "ThostFtdcMdApi.h"
#include "CThostFtdcMdSpiWrapper.h"
#include "MyUnmanagedString.h"

namespace CTPWrapper {

	class MyCppMDSpi : public CThostFtdcMdSpi
	{
	public:
		MyCppMDSpi(CThostFtdcMdSpiWrapper^ wrapper) : wrapper_(wrapper)
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

		virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override
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

			CThostFtdcRspInfoFieldWrapper^ rspInfo = gcnew CThostFtdcRspInfoFieldWrapper();
			rspInfo->ErrorID = pRspInfo->ErrorID;
			COPY_UNMANAGED_STRING(rspInfo->ErrorMsg, pRspInfo->ErrorMsg);

			wrapper_->OnRspUserLogin(rspUserLogin, rspInfo, nRequestID, bIsLast);
		}

		virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override
		{
			CThostFtdcUserLogoutFieldWrapper^ csharpUserLogout = gcnew CThostFtdcUserLogoutFieldWrapper();
			COPY_UNMANAGED_STRING(csharpUserLogout->BrokerID, pUserLogout->BrokerID);
			COPY_UNMANAGED_STRING(csharpUserLogout->UserID, pUserLogout->UserID);

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = pRspInfo->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, pRspInfo->ErrorMsg);

			wrapper_->OnRspUserLogout(csharpUserLogout, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) override
		{
			CThostFtdcSpecificInstrumentFieldWrapper^ csharpInstrument = gcnew CThostFtdcSpecificInstrumentFieldWrapper();
			COPY_UNMANAGED_STRING(csharpInstrument->InstrumentID, pSpecificInstrument->InstrumentID);

			CThostFtdcRspInfoFieldWrapper^ rspInfo = gcnew CThostFtdcRspInfoFieldWrapper();
			rspInfo->ErrorID = pRspInfo->ErrorID;
			COPY_UNMANAGED_STRING(rspInfo->ErrorMsg, pRspInfo->ErrorMsg);

			wrapper_->OnRspSubMarketData(csharpInstrument, rspInfo, nRequestID, bIsLast);
		}

	private:
		msclr::auto_gcroot<CThostFtdcMdSpiWrapper^> wrapper_;
	};
}