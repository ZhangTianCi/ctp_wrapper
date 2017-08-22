#pragma once

#include <msclr\auto_gcroot.h>
#include "ThostFtdcMdApi.h"
#include "CThostFtdcMdSpiWrapper.h"

namespace CTPWrapper {

	class MyCppMDSpi : public CThostFtdcMdSpi
	{
	public:
		MyCppMDSpi(CThostFtdcMdSpiWrapper^ wrapper) : wrapper_(wrapper)
		{
		}

		virtual void OnFrontConnected()
		{
			wrapper_->OnFrontConnected();
		}

		virtual void OnFrontDisconnected(int nReason)
		{
			wrapper_->OnFrontDisconnected(nReason);
		}

		virtual void OnHeartBeatWarning(int nTimeLapse)
		{
			wrapper_->OnHeartBeatWarning(nTimeLapse);
		}

		virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CThostFtdcRspUserLoginFieldWrapper^ rspUserLogin = gcnew CThostFtdcRspUserLoginFieldWrapper();
			rspUserLogin->TradingDay = gcnew String(pRspUserLogin->TradingDay);
			rspUserLogin->LoginTime = gcnew String(pRspUserLogin->LoginTime);
			rspUserLogin->BrokerID = gcnew String(pRspUserLogin->BrokerID);
			rspUserLogin->UserID = gcnew String(pRspUserLogin->UserID);
			rspUserLogin->SystemName = gcnew String(pRspUserLogin->SystemName);
			rspUserLogin->FrontID = pRspUserLogin->FrontID;
			rspUserLogin->SessionID = pRspUserLogin->SessionID;
			rspUserLogin->MaxOrderRef = gcnew String(pRspUserLogin->MaxOrderRef);
			rspUserLogin->SHFETime = gcnew String(pRspUserLogin->SHFETime);
			rspUserLogin->DCETime = gcnew String(pRspUserLogin->DCETime);
			rspUserLogin->CZCETime = gcnew String(pRspUserLogin->CZCETime);
			rspUserLogin->FFEXTime = gcnew String(pRspUserLogin->FFEXTime);
			rspUserLogin->INETime = gcnew String(pRspUserLogin->INETime);
			
			CThostFtdcRspInfoFieldWrapper^ rspInfo = gcnew CThostFtdcRspInfoFieldWrapper();
			rspInfo->ErrorID = pRspInfo->ErrorID;
			rspInfo->ErrorMsg = gcnew String(pRspInfo->ErrorMsg);

			wrapper_->OnRspUserLogin(rspUserLogin, rspInfo, nRequestID, bIsLast);
		}

	private:
		msclr::auto_gcroot<CThostFtdcMdSpiWrapper^> wrapper_;
	};
}