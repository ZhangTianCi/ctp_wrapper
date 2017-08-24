#pragma once

#include <msclr\auto_gcroot.h>
#include "ThostFtdcTraderApi.h"
#include "TradeSpiWrapper.h"
#include "MyUnmanagedString.h"

namespace CTPWrapper {

	class TradeSpi : public CThostFtdcTraderSpi
	{
	public:
		TradeSpi(TradeSpiWrapper^ wrapper) : wrapper_(wrapper)
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

		virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField *cppAuth, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcRspAuthenticateFieldWrapper^ csharpAuth = gcnew CThostFtdcRspAuthenticateFieldWrapper();
			COPY_UNMANAGED_STRING(csharpAuth->BrokerID, cppAuth->BrokerID);
			COPY_UNMANAGED_STRING(csharpAuth->UserID, cppAuth->UserID);
			COPY_UNMANAGED_STRING(csharpAuth->UserProductInfo, cppAuth->UserProductInfo);

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspAuthenticate(csharpAuth, csharpError, nRequestID, bIsLast);
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

		virtual void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *cppPassword, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcUserPasswordUpdateFieldWrapper^ csharpPassword = gcnew CThostFtdcUserPasswordUpdateFieldWrapper();
			COPY_UNMANAGED_STRING(csharpPassword->BrokerID, cppPassword->BrokerID);
			COPY_UNMANAGED_STRING(csharpPassword->UserID, cppPassword->UserID);
			COPY_UNMANAGED_STRING(csharpPassword->OldPassword, cppPassword->OldPassword);
			COPY_UNMANAGED_STRING(csharpPassword->NewPassword, cppPassword->NewPassword);

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspUserPasswordUpdate(csharpPassword, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *cppPassword, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcTradingAccountPasswordUpdateFieldWrapper^ csharpPassword = gcnew CThostFtdcTradingAccountPasswordUpdateFieldWrapper();
			COPY_UNMANAGED_STRING(csharpPassword->BrokerID, cppPassword->BrokerID);
			COPY_UNMANAGED_STRING(csharpPassword->AccountID, cppPassword->AccountID);
			COPY_UNMANAGED_STRING(csharpPassword->OldPassword, cppPassword->OldPassword);
			COPY_UNMANAGED_STRING(csharpPassword->NewPassword, cppPassword->NewPassword);
			COPY_UNMANAGED_STRING(csharpPassword->CurrencyID, cppPassword->CurrencyID);

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspTradingAccountPasswordUpdate(csharpPassword, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspOrderInsert(CThostFtdcInputOrderField *cppOrder, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcInputOrderFieldWrapper^ csharpOrder = gcnew CThostFtdcInputOrderFieldWrapper();
			COPY_UNMANAGED_STRING(csharpOrder->BrokerID, cppOrder->BrokerID);
			COPY_UNMANAGED_STRING(csharpOrder->InvestorID, cppOrder->InvestorID);
			COPY_UNMANAGED_STRING(csharpOrder->InstrumentID, cppOrder->InstrumentID);
			COPY_UNMANAGED_STRING(csharpOrder->OrderRef, cppOrder->OrderRef);
			COPY_UNMANAGED_STRING(csharpOrder->UserID, cppOrder->UserID);
			csharpOrder->OrderPriceType = cppOrder->OrderPriceType;
			csharpOrder->Direction = cppOrder->Direction;
			COPY_UNMANAGED_STRING(csharpOrder->CombOffsetFlag, cppOrder->CombOffsetFlag);
			COPY_UNMANAGED_STRING(csharpOrder->CombHedgeFlag, cppOrder->CombHedgeFlag);
			csharpOrder->LimitPrice = cppOrder->LimitPrice;
			csharpOrder->VolumeTotalOriginal = cppOrder->VolumeTotalOriginal;
			csharpOrder->TimeCondition = cppOrder->TimeCondition;
			COPY_UNMANAGED_STRING(csharpOrder->GTDDate, cppOrder->GTDDate);
			csharpOrder->VolumeCondition = cppOrder->VolumeCondition;
			csharpOrder->MinVolume = cppOrder->MinVolume;
			csharpOrder->ContingentCondition = cppOrder->ContingentCondition;
			csharpOrder->StopPrice = cppOrder->StopPrice;
			csharpOrder->ForceCloseReason = cppOrder->ForceCloseReason;
			csharpOrder->IsAutoSuspend = cppOrder->IsAutoSuspend;
			COPY_UNMANAGED_STRING(csharpOrder->BusinessUnit, cppOrder->BusinessUnit);
			csharpOrder->RequestID = cppOrder->RequestID;
			csharpOrder->UserForceClose = cppOrder->UserForceClose;
			csharpOrder->IsSwapOrder = cppOrder->IsSwapOrder;
			COPY_UNMANAGED_STRING(csharpOrder->ExchangeID, cppOrder->ExchangeID);
			COPY_UNMANAGED_STRING(csharpOrder->InvestUnitID, cppOrder->InvestUnitID);
			COPY_UNMANAGED_STRING(csharpOrder->AccountID, cppOrder->AccountID);
			COPY_UNMANAGED_STRING(csharpOrder->CurrencyID, cppOrder->CurrencyID);
			COPY_UNMANAGED_STRING(csharpOrder->ClientID, cppOrder->ClientID);
			COPY_UNMANAGED_STRING(csharpOrder->IPAddress, cppOrder->IPAddress);
			COPY_UNMANAGED_STRING(csharpOrder->MacAddress, cppOrder->MacAddress);

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspOrderInsert(csharpOrder, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspParkedOrderInsert(CThostFtdcParkedOrderField *cppOrder, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcParkedOrderFieldWrapper^ csharpOrder = gcnew CThostFtdcParkedOrderFieldWrapper();
			COPY_UNMANAGED_STRING(csharpOrder->BrokerID, cppOrder->BrokerID);
			COPY_UNMANAGED_STRING(csharpOrder->InvestorID, cppOrder->InvestorID);
			COPY_UNMANAGED_STRING(csharpOrder->InstrumentID, cppOrder->InstrumentID);
			COPY_UNMANAGED_STRING(csharpOrder->OrderRef, cppOrder->OrderRef);
			COPY_UNMANAGED_STRING(csharpOrder->UserID, cppOrder->UserID);
			csharpOrder->OrderPriceType = cppOrder->OrderPriceType;
			csharpOrder->Direction = cppOrder->Direction;
			COPY_UNMANAGED_STRING(csharpOrder->CombOffsetFlag, cppOrder->CombOffsetFlag);
			COPY_UNMANAGED_STRING(csharpOrder->CombHedgeFlag, cppOrder->CombHedgeFlag);
			csharpOrder->LimitPrice = cppOrder->LimitPrice;
			csharpOrder->VolumeTotalOriginal = cppOrder->VolumeTotalOriginal;
			csharpOrder->TimeCondition = cppOrder->TimeCondition;
			COPY_UNMANAGED_STRING(csharpOrder->GTDDate, cppOrder->GTDDate);
			csharpOrder->VolumeCondition = cppOrder->VolumeCondition;
			csharpOrder->MinVolume = cppOrder->MinVolume;
			csharpOrder->ContingentCondition = cppOrder->ContingentCondition;
			csharpOrder->StopPrice = cppOrder->StopPrice;
			csharpOrder->ForceCloseReason = cppOrder->ForceCloseReason;
			csharpOrder->IsAutoSuspend = cppOrder->IsAutoSuspend;
			COPY_UNMANAGED_STRING(csharpOrder->BusinessUnit, cppOrder->BusinessUnit);
			csharpOrder->RequestID = cppOrder->RequestID;
			csharpOrder->UserForceClose = cppOrder->UserForceClose;
			COPY_UNMANAGED_STRING(csharpOrder->ExchangeID, cppOrder->ExchangeID);
			COPY_UNMANAGED_STRING(csharpOrder->ParkedOrderID, cppOrder->ParkedOrderID);
			csharpOrder->UserType = cppOrder->UserType;
			csharpOrder->Status = cppOrder->Status;
			csharpOrder->ErrorID = cppOrder->ErrorID;
			COPY_UNMANAGED_STRING(csharpOrder->ErrorMsg, cppOrder->ErrorMsg);
			csharpOrder->IsSwapOrder = cppOrder->IsSwapOrder;
			COPY_UNMANAGED_STRING(csharpOrder->AccountID, cppOrder->AccountID);
			COPY_UNMANAGED_STRING(csharpOrder->CurrencyID, cppOrder->CurrencyID);
			COPY_UNMANAGED_STRING(csharpOrder->ClientID, cppOrder->ClientID);
			COPY_UNMANAGED_STRING(csharpOrder->InvestUnitID, cppOrder->InvestUnitID);
			COPY_UNMANAGED_STRING(csharpOrder->IPAddress, cppOrder->IPAddress);
			COPY_UNMANAGED_STRING(csharpOrder->MacAddress, cppOrder->MacAddress);

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspParkedOrderInsert(csharpOrder, csharpError, nRequestID, bIsLast);
		}




		virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = pRspInfo->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, pRspInfo->ErrorMsg);

			wrapper_->OnRspError(csharpError, nRequestID, bIsLast);
		}

	private:
		msclr::auto_gcroot<TradeSpiWrapper^> wrapper_;
	};

}
