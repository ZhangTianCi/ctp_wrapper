#pragma once

#include <msclr\auto_gcroot.h>
#include "ThostFtdcTraderApi.h"
#include "TradeSpiWrapper.h"
#include "MyUnmanagedString.h"
#include <assert.h>

namespace CTPWrapper {

#define COPY_ERROR_CODE \
	CThostFtdcRspInfoFieldWrapper^ csharpError = nullptr; \
	if (cppError) \
	{ \
		csharpError = gcnew CThostFtdcRspInfoFieldWrapper(); \
		csharpError->ErrorID = cppError->ErrorID; \
		COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg); \
	}

	class TradeSpi : public CThostFtdcTraderSpi
	{
	public:
		TradeSpi(TradeSpiWrapper^ wrapper) : wrapper_(wrapper)
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
		void OnRspAuthenticate(CThostFtdcRspAuthenticateField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcRspAuthenticateFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcRspAuthenticateFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				COPY_UNMANAGED_STRING(csharpData->UserProductInfo, cppData->UserProductInfo);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspAuthenticate(csharpData, csharpError, nRequestID, bIsLast);
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

		void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcUserPasswordUpdateFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcUserPasswordUpdateFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				COPY_UNMANAGED_STRING(csharpData->OldPassword, cppData->OldPassword);
				COPY_UNMANAGED_STRING(csharpData->NewPassword, cppData->NewPassword);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspUserPasswordUpdate(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcTradingAccountPasswordUpdateFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcTradingAccountPasswordUpdateFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->OldPassword, cppData->OldPassword);
				COPY_UNMANAGED_STRING(csharpData->NewPassword, cppData->NewPassword);
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspTradingAccountPasswordUpdate(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspOrderInsert(CThostFtdcInputOrderField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcInputOrderFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInputOrderFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->OrderRef, cppData->OrderRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->OrderPriceType = cppData->OrderPriceType;
				csharpData->Direction = cppData->Direction;
				COPY_UNMANAGED_STRING(csharpData->CombOffsetFlag, cppData->CombOffsetFlag);
				COPY_UNMANAGED_STRING(csharpData->CombHedgeFlag, cppData->CombHedgeFlag);
				csharpData->LimitPrice = cppData->LimitPrice;
				csharpData->VolumeTotalOriginal = cppData->VolumeTotalOriginal;
				csharpData->TimeCondition = cppData->TimeCondition;
				COPY_UNMANAGED_STRING(csharpData->GTDDate, cppData->GTDDate);
				csharpData->VolumeCondition = cppData->VolumeCondition;
				csharpData->MinVolume = cppData->MinVolume;
				csharpData->ContingentCondition = cppData->ContingentCondition;
				csharpData->StopPrice = cppData->StopPrice;
				csharpData->ForceCloseReason = cppData->ForceCloseReason;
				csharpData->IsAutoSuspend = cppData->IsAutoSuspend;
				COPY_UNMANAGED_STRING(csharpData->BusinessUnit, cppData->BusinessUnit);
				csharpData->RequestID = cppData->RequestID;
				csharpData->UserForceClose = cppData->UserForceClose;
				csharpData->IsSwapOrder = cppData->IsSwapOrder;
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspOrderInsert(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspParkedOrderInsert(CThostFtdcParkedOrderField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcParkedOrderFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcParkedOrderFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->OrderRef, cppData->OrderRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->OrderPriceType = cppData->OrderPriceType;
				csharpData->Direction = cppData->Direction;
				COPY_UNMANAGED_STRING(csharpData->CombOffsetFlag, cppData->CombOffsetFlag);
				COPY_UNMANAGED_STRING(csharpData->CombHedgeFlag, cppData->CombHedgeFlag);
				csharpData->LimitPrice = cppData->LimitPrice;
				csharpData->VolumeTotalOriginal = cppData->VolumeTotalOriginal;
				csharpData->TimeCondition = cppData->TimeCondition;
				COPY_UNMANAGED_STRING(csharpData->GTDDate, cppData->GTDDate);
				csharpData->VolumeCondition = cppData->VolumeCondition;
				csharpData->MinVolume = cppData->MinVolume;
				csharpData->ContingentCondition = cppData->ContingentCondition;
				csharpData->StopPrice = cppData->StopPrice;
				csharpData->ForceCloseReason = cppData->ForceCloseReason;
				csharpData->IsAutoSuspend = cppData->IsAutoSuspend;
				COPY_UNMANAGED_STRING(csharpData->BusinessUnit, cppData->BusinessUnit);
				csharpData->RequestID = cppData->RequestID;
				csharpData->UserForceClose = cppData->UserForceClose;
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->ParkedOrderID, cppData->ParkedOrderID);
				csharpData->UserType = cppData->UserType;
				csharpData->Status = cppData->Status;
				csharpData->ErrorID = cppData->ErrorID;
				COPY_UNMANAGED_STRING(csharpData->ErrorMsg, cppData->ErrorMsg);
				csharpData->IsSwapOrder = cppData->IsSwapOrder;
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspParkedOrderInsert(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspParkedOrderAction(CThostFtdcParkedOrderActionField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcParkedOrderActionFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcParkedOrderActionFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				csharpData->OrderActionRef = cppData->OrderActionRef;
				COPY_UNMANAGED_STRING(csharpData->OrderRef, cppData->OrderRef);
				csharpData->RequestID = cppData->RequestID;
				csharpData->FrontID = cppData->FrontID;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->OrderSysID, cppData->OrderSysID);
				csharpData->ActionFlag = cppData->ActionFlag;
				csharpData->LimitPrice = cppData->LimitPrice;
				csharpData->VolumeChange = cppData->VolumeChange;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->ParkedOrderActionID, cppData->ParkedOrderActionID);
				csharpData->UserType = cppData->UserType;
				csharpData->Status = cppData->Status;
				csharpData->ErrorID = cppData->ErrorID;
				COPY_UNMANAGED_STRING(csharpData->ErrorMsg, cppData->ErrorMsg);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspParkedOrderAction(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspOrderAction(CThostFtdcInputOrderActionField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcInputOrderActionFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInputOrderActionFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				csharpData->OrderActionRef = cppData->OrderActionRef;
				COPY_UNMANAGED_STRING(csharpData->OrderRef, cppData->OrderRef);
				csharpData->RequestID = cppData->RequestID;
				csharpData->FrontID = cppData->FrontID;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->OrderSysID, cppData->OrderSysID);
				csharpData->ActionFlag = cppData->ActionFlag;
				csharpData->LimitPrice = cppData->LimitPrice;
				csharpData->VolumeChange = cppData->VolumeChange;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspOrderAction(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcQueryMaxOrderVolumeFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcQueryMaxOrderVolumeFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				csharpData->Direction = cppData->Direction;
				csharpData->OffsetFlag = cppData->OffsetFlag;
				csharpData->HedgeFlag = cppData->HedgeFlag;
				csharpData->MaxVolume = cppData->MaxVolume;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQueryMaxOrderVolume(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcSettlementInfoConfirmFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcSettlementInfoConfirmFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->ConfirmDate, cppData->ConfirmDate);
				COPY_UNMANAGED_STRING(csharpData->ConfirmTime, cppData->ConfirmTime);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspSettlementInfoConfirm(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcRemoveParkedOrderFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcRemoveParkedOrderFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->ParkedOrderID, cppData->ParkedOrderID);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspRemoveParkedOrder(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcRemoveParkedOrderActionFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcRemoveParkedOrderActionFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->ParkedOrderActionID, cppData->ParkedOrderActionID);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspRemoveParkedOrderAction(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspExecOrderInsert(CThostFtdcInputExecOrderField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcInputExecOrderFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInputExecOrderFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->ExecOrderRef, cppData->ExecOrderRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->Volume = cppData->Volume;
				csharpData->RequestID = cppData->RequestID;
				COPY_UNMANAGED_STRING(csharpData->BusinessUnit, cppData->BusinessUnit);
				csharpData->OffsetFlag = cppData->OffsetFlag;
				csharpData->HedgeFlag = cppData->HedgeFlag;
				csharpData->ActionType = cppData->ActionType;
				csharpData->PosiDirection = cppData->PosiDirection;
				csharpData->ReservePositionFlag = cppData->ReservePositionFlag;
				csharpData->CloseFlag = cppData->CloseFlag;
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspExecOrderInsert(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcInputExecOrderActionFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInputExecOrderActionFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				csharpData->ExecOrderActionRef = cppData->ExecOrderActionRef;
				COPY_UNMANAGED_STRING(csharpData->ExecOrderRef, cppData->ExecOrderRef);
				csharpData->RequestID = cppData->RequestID;
				csharpData->FrontID = cppData->FrontID;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->ExecOrderSysID, cppData->ExecOrderSysID);
				csharpData->ActionFlag = cppData->ActionFlag;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspExecOrderAction(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspForQuoteInsert(CThostFtdcInputForQuoteField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcInputForQuoteFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInputForQuoteFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->ForQuoteRef, cppData->ForQuoteRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspForQuoteInsert(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQuoteInsert(CThostFtdcInputQuoteField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcInputQuoteFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInputQuoteFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->QuoteRef, cppData->QuoteRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->AskPrice = cppData->AskPrice;
				csharpData->BidPrice = cppData->BidPrice;
				csharpData->AskVolume = cppData->AskVolume;
				csharpData->BidVolume = cppData->BidVolume;
				csharpData->RequestID = cppData->RequestID;
				COPY_UNMANAGED_STRING(csharpData->BusinessUnit, cppData->BusinessUnit);
				csharpData->AskOffsetFlag = cppData->AskOffsetFlag;
				csharpData->BidOffsetFlag = cppData->BidOffsetFlag;
				csharpData->AskHedgeFlag = cppData->AskHedgeFlag;
				csharpData->BidHedgeFlag = cppData->BidHedgeFlag;
				COPY_UNMANAGED_STRING(csharpData->AskOrderRef, cppData->AskOrderRef);
				COPY_UNMANAGED_STRING(csharpData->BidOrderRef, cppData->BidOrderRef);
				COPY_UNMANAGED_STRING(csharpData->ForQuoteSysID, cppData->ForQuoteSysID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQuoteInsert(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQuoteAction(CThostFtdcInputQuoteActionField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcInputQuoteActionFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInputQuoteActionFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				csharpData->QuoteActionRef = cppData->QuoteActionRef;
				COPY_UNMANAGED_STRING(csharpData->QuoteRef, cppData->QuoteRef);
				csharpData->RequestID = cppData->RequestID;
				csharpData->FrontID = cppData->FrontID;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->QuoteSysID, cppData->QuoteSysID);
				csharpData->ActionFlag = cppData->ActionFlag;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQuoteAction(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcInputBatchOrderActionFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInputBatchOrderActionFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				csharpData->OrderActionRef = cppData->OrderActionRef;
				csharpData->RequestID = cppData->RequestID;
				csharpData->FrontID = cppData->FrontID;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspBatchOrderAction(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspCombActionInsert(CThostFtdcInputCombActionField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcInputCombActionFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInputCombActionFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->CombActionRef, cppData->CombActionRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->Direction = cppData->Direction;
				csharpData->Volume = cppData->Volume;
				csharpData->CombDirection = cppData->CombDirection;
				csharpData->HedgeFlag = cppData->HedgeFlag;
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspCombActionInsert(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryOrder(CThostFtdcOrderField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcOrderFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcOrderFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->OrderRef, cppData->OrderRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->OrderPriceType = cppData->OrderPriceType;
				csharpData->Direction = cppData->Direction;
				COPY_UNMANAGED_STRING(csharpData->CombOffsetFlag, cppData->CombOffsetFlag);
				COPY_UNMANAGED_STRING(csharpData->CombHedgeFlag, cppData->CombHedgeFlag);
				csharpData->LimitPrice = cppData->LimitPrice;
				csharpData->VolumeTotalOriginal = cppData->VolumeTotalOriginal;
				csharpData->TimeCondition = cppData->TimeCondition;
				COPY_UNMANAGED_STRING(csharpData->GTDDate, cppData->GTDDate);
				csharpData->VolumeCondition = cppData->VolumeCondition;
				csharpData->MinVolume = cppData->MinVolume;
				csharpData->ContingentCondition = cppData->ContingentCondition;
				csharpData->StopPrice = cppData->StopPrice;
				csharpData->ForceCloseReason = cppData->ForceCloseReason;
				csharpData->IsAutoSuspend = cppData->IsAutoSuspend;
				COPY_UNMANAGED_STRING(csharpData->BusinessUnit, cppData->BusinessUnit);
				csharpData->RequestID = cppData->RequestID;
				COPY_UNMANAGED_STRING(csharpData->OrderLocalID, cppData->OrderLocalID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->ParticipantID, cppData->ParticipantID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeInstID, cppData->ExchangeInstID);
				COPY_UNMANAGED_STRING(csharpData->TraderID, cppData->TraderID);
				csharpData->InstallID = cppData->InstallID;
				csharpData->OrderSubmitStatus = cppData->OrderSubmitStatus;
				csharpData->NotifySequence = cppData->NotifySequence;
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->SettlementID = cppData->SettlementID;
				COPY_UNMANAGED_STRING(csharpData->OrderSysID, cppData->OrderSysID);
				csharpData->OrderSource = cppData->OrderSource;
				csharpData->OrderStatus = cppData->OrderStatus;
				csharpData->OrderType = cppData->OrderType;
				csharpData->VolumeTraded = cppData->VolumeTraded;
				csharpData->VolumeTotal = cppData->VolumeTotal;
				COPY_UNMANAGED_STRING(csharpData->InsertDate, cppData->InsertDate);
				COPY_UNMANAGED_STRING(csharpData->InsertTime, cppData->InsertTime);
				COPY_UNMANAGED_STRING(csharpData->ActiveTime, cppData->ActiveTime);
				COPY_UNMANAGED_STRING(csharpData->SuspendTime, cppData->SuspendTime);
				COPY_UNMANAGED_STRING(csharpData->UpdateTime, cppData->UpdateTime);
				COPY_UNMANAGED_STRING(csharpData->CancelTime, cppData->CancelTime);
				COPY_UNMANAGED_STRING(csharpData->ActiveTraderID, cppData->ActiveTraderID);
				COPY_UNMANAGED_STRING(csharpData->ClearingPartID, cppData->ClearingPartID);
				csharpData->SequenceNo = cppData->SequenceNo;
				csharpData->FrontID = cppData->FrontID;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->UserProductInfo, cppData->UserProductInfo);
				COPY_UNMANAGED_STRING(csharpData->StatusMsg, cppData->StatusMsg);
				csharpData->UserForceClose = cppData->UserForceClose;
				COPY_UNMANAGED_STRING(csharpData->ActiveUserID, cppData->ActiveUserID);
				csharpData->BrokerOrderSeq = cppData->BrokerOrderSeq;
				COPY_UNMANAGED_STRING(csharpData->RelativeOrderSysID, cppData->RelativeOrderSysID);
				csharpData->ZCETotalTradedVolume = cppData->ZCETotalTradedVolume;
				csharpData->IsSwapOrder = cppData->IsSwapOrder;
				COPY_UNMANAGED_STRING(csharpData->BranchID, cppData->BranchID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryOrder(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryTrade(CThostFtdcTradeField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcTradeFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcTradeFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->OrderRef, cppData->OrderRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->TradeID, cppData->TradeID);
				csharpData->Direction = cppData->Direction;
				COPY_UNMANAGED_STRING(csharpData->OrderSysID, cppData->OrderSysID);
				COPY_UNMANAGED_STRING(csharpData->ParticipantID, cppData->ParticipantID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				csharpData->TradingRole = cppData->TradingRole;
				COPY_UNMANAGED_STRING(csharpData->ExchangeInstID, cppData->ExchangeInstID);
				csharpData->OffsetFlag = cppData->OffsetFlag;
				csharpData->HedgeFlag = cppData->HedgeFlag;
				csharpData->Price = cppData->Price;
				csharpData->Volume = cppData->Volume;
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				csharpData->TradeType = cppData->TradeType;
				csharpData->PriceSource = cppData->PriceSource;
				COPY_UNMANAGED_STRING(csharpData->TraderID, cppData->TraderID);
				COPY_UNMANAGED_STRING(csharpData->OrderLocalID, cppData->OrderLocalID);
				COPY_UNMANAGED_STRING(csharpData->ClearingPartID, cppData->ClearingPartID);
				COPY_UNMANAGED_STRING(csharpData->BusinessUnit, cppData->BusinessUnit);
				csharpData->SequenceNo = cppData->SequenceNo;
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->SettlementID = cppData->SettlementID;
				csharpData->BrokerOrderSeq = cppData->BrokerOrderSeq;
				csharpData->TradeSource = cppData->TradeSource;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryTrade(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcInvestorPositionFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInvestorPositionFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				csharpData->PosiDirection = cppData->PosiDirection;
				csharpData->HedgeFlag = cppData->HedgeFlag;
				csharpData->PositionDate = cppData->PositionDate;
				csharpData->YdPosition = cppData->YdPosition;
				csharpData->Position = cppData->Position;
				csharpData->LongFrozen = cppData->LongFrozen;
				csharpData->ShortFrozen = cppData->ShortFrozen;
				csharpData->LongFrozenAmount = cppData->LongFrozenAmount;
				csharpData->ShortFrozenAmount = cppData->ShortFrozenAmount;
				csharpData->OpenVolume = cppData->OpenVolume;
				csharpData->CloseVolume = cppData->CloseVolume;
				csharpData->OpenAmount = cppData->OpenAmount;
				csharpData->CloseAmount = cppData->CloseAmount;
				csharpData->PositionCost = cppData->PositionCost;
				csharpData->PreMargin = cppData->PreMargin;
				csharpData->UseMargin = cppData->UseMargin;
				csharpData->FrozenMargin = cppData->FrozenMargin;
				csharpData->FrozenCash = cppData->FrozenCash;
				csharpData->FrozenCommission = cppData->FrozenCommission;
				csharpData->CashIn = cppData->CashIn;
				csharpData->Commission = cppData->Commission;
				csharpData->CloseProfit = cppData->CloseProfit;
				csharpData->PositionProfit = cppData->PositionProfit;
				csharpData->PreSettlementPrice = cppData->PreSettlementPrice;
				csharpData->SettlementPrice = cppData->SettlementPrice;
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->SettlementID = cppData->SettlementID;
				csharpData->OpenCost = cppData->OpenCost;
				csharpData->ExchangeMargin = cppData->ExchangeMargin;
				csharpData->CombPosition = cppData->CombPosition;
				csharpData->CombLongFrozen = cppData->CombLongFrozen;
				csharpData->CombShortFrozen = cppData->CombShortFrozen;
				csharpData->CloseProfitByDate = cppData->CloseProfitByDate;
				csharpData->CloseProfitByTrade = cppData->CloseProfitByTrade;
				csharpData->TodayPosition = cppData->TodayPosition;
				csharpData->MarginRateByMoney = cppData->MarginRateByMoney;
				csharpData->MarginRateByVolume = cppData->MarginRateByVolume;
				csharpData->StrikeFrozen = cppData->StrikeFrozen;
				csharpData->StrikeFrozenAmount = cppData->StrikeFrozenAmount;
				csharpData->AbandonFrozen = cppData->AbandonFrozen;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryInvestorPosition(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryTradingAccount(CThostFtdcTradingAccountField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcTradingAccountFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcTradingAccountFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				csharpData->PreMortgage = cppData->PreMortgage;
				csharpData->PreCredit = cppData->PreCredit;
				csharpData->PreDeposit = cppData->PreDeposit;
				csharpData->PreBalance = cppData->PreBalance;
				csharpData->PreMargin = cppData->PreMargin;
				csharpData->InterestBase = cppData->InterestBase;
				csharpData->Interest = cppData->Interest;
				csharpData->Deposit = cppData->Deposit;
				csharpData->Withdraw = cppData->Withdraw;
				csharpData->FrozenMargin = cppData->FrozenMargin;
				csharpData->FrozenCash = cppData->FrozenCash;
				csharpData->FrozenCommission = cppData->FrozenCommission;
				csharpData->CurrMargin = cppData->CurrMargin;
				csharpData->CashIn = cppData->CashIn;
				csharpData->Commission = cppData->Commission;
				csharpData->CloseProfit = cppData->CloseProfit;
				csharpData->PositionProfit = cppData->PositionProfit;
				csharpData->Balance = cppData->Balance;
				csharpData->Available = cppData->Available;
				csharpData->WithdrawQuota = cppData->WithdrawQuota;
				csharpData->Reserve = cppData->Reserve;
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->SettlementID = cppData->SettlementID;
				csharpData->Credit = cppData->Credit;
				csharpData->Mortgage = cppData->Mortgage;
				csharpData->ExchangeMargin = cppData->ExchangeMargin;
				csharpData->DeliveryMargin = cppData->DeliveryMargin;
				csharpData->ExchangeDeliveryMargin = cppData->ExchangeDeliveryMargin;
				csharpData->ReserveBalance = cppData->ReserveBalance;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				csharpData->PreFundMortgageIn = cppData->PreFundMortgageIn;
				csharpData->PreFundMortgageOut = cppData->PreFundMortgageOut;
				csharpData->FundMortgageIn = cppData->FundMortgageIn;
				csharpData->FundMortgageOut = cppData->FundMortgageOut;
				csharpData->FundMortgageAvailable = cppData->FundMortgageAvailable;
				csharpData->MortgageableFund = cppData->MortgageableFund;
				csharpData->SpecProductMargin = cppData->SpecProductMargin;
				csharpData->SpecProductFrozenMargin = cppData->SpecProductFrozenMargin;
				csharpData->SpecProductCommission = cppData->SpecProductCommission;
				csharpData->SpecProductFrozenCommission = cppData->SpecProductFrozenCommission;
				csharpData->SpecProductPositionProfit = cppData->SpecProductPositionProfit;
				csharpData->SpecProductCloseProfit = cppData->SpecProductCloseProfit;
				csharpData->SpecProductPositionProfitByAlg = cppData->SpecProductPositionProfitByAlg;
				csharpData->SpecProductExchangeMargin = cppData->SpecProductExchangeMargin;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryTradingAccount(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryInvestor(CThostFtdcInvestorField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcInvestorFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInvestorFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorGroupID, cppData->InvestorGroupID);
				COPY_UNMANAGED_STRING(csharpData->InvestorName, cppData->InvestorName);
				csharpData->IdentifiedCardType = cppData->IdentifiedCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->IsActive = cppData->IsActive;
				COPY_UNMANAGED_STRING(csharpData->Telephone, cppData->Telephone);
				COPY_UNMANAGED_STRING(csharpData->Address, cppData->Address);
				COPY_UNMANAGED_STRING(csharpData->OpenDate, cppData->OpenDate);
				COPY_UNMANAGED_STRING(csharpData->Mobile, cppData->Mobile);
				COPY_UNMANAGED_STRING(csharpData->CommModelID, cppData->CommModelID);
				COPY_UNMANAGED_STRING(csharpData->MarginModelID, cppData->MarginModelID);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryInvestor(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryTradingCode(CThostFtdcTradingCodeField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcTradingCodeFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcTradingCodeFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				csharpData->IsActive = cppData->IsActive;
				csharpData->ClientIDType = cppData->ClientIDType;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryTradingCode(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcInstrumentMarginRateFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInstrumentMarginRateFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				csharpData->InvestorRange = cppData->InvestorRange;
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				csharpData->HedgeFlag = cppData->HedgeFlag;
				csharpData->LongMarginRatioByMoney = cppData->LongMarginRatioByMoney;
				csharpData->LongMarginRatioByVolume = cppData->LongMarginRatioByVolume;
				csharpData->ShortMarginRatioByMoney = cppData->ShortMarginRatioByMoney;
				csharpData->ShortMarginRatioByVolume = cppData->ShortMarginRatioByVolume;
				csharpData->IsRelative = cppData->IsRelative;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryInstrumentMarginRate(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcInstrumentCommissionRateFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInstrumentCommissionRateFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				csharpData->InvestorRange = cppData->InvestorRange;
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				csharpData->OpenRatioByMoney = cppData->OpenRatioByMoney;
				csharpData->OpenRatioByVolume = cppData->OpenRatioByVolume;
				csharpData->CloseRatioByMoney = cppData->CloseRatioByMoney;
				csharpData->CloseRatioByVolume = cppData->CloseRatioByVolume;
				csharpData->CloseTodayRatioByMoney = cppData->CloseTodayRatioByMoney;
				csharpData->CloseTodayRatioByVolume = cppData->CloseTodayRatioByVolume;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryInstrumentCommissionRate(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryExchange(CThostFtdcExchangeField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcExchangeFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcExchangeFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeName, cppData->ExchangeName);
				csharpData->ExchangeProperty = cppData->ExchangeProperty;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryExchange(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryProduct(CThostFtdcProductField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcProductFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcProductFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->ProductID, cppData->ProductID);
				COPY_UNMANAGED_STRING(csharpData->ProductName, cppData->ProductName);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				csharpData->ProductClass = cppData->ProductClass;
				csharpData->VolumeMultiple = cppData->VolumeMultiple;
				csharpData->PriceTick = cppData->PriceTick;
				csharpData->MaxMarketOrderVolume = cppData->MaxMarketOrderVolume;
				csharpData->MinMarketOrderVolume = cppData->MinMarketOrderVolume;
				csharpData->MaxLimitOrderVolume = cppData->MaxLimitOrderVolume;
				csharpData->MinLimitOrderVolume = cppData->MinLimitOrderVolume;
				csharpData->PositionType = cppData->PositionType;
				csharpData->PositionDateType = cppData->PositionDateType;
				csharpData->CloseDealType = cppData->CloseDealType;
				COPY_UNMANAGED_STRING(csharpData->TradeCurrencyID, cppData->TradeCurrencyID);
				csharpData->MortgageFundUseRange = cppData->MortgageFundUseRange;
				COPY_UNMANAGED_STRING(csharpData->ExchangeProductID, cppData->ExchangeProductID);
				csharpData->UnderlyingMultiple = cppData->UnderlyingMultiple;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryProduct(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryInstrument(CThostFtdcInstrumentField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcInstrumentFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInstrumentFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentName, cppData->InstrumentName);
				COPY_UNMANAGED_STRING(csharpData->ExchangeInstID, cppData->ExchangeInstID);
				COPY_UNMANAGED_STRING(csharpData->ProductID, cppData->ProductID);
				csharpData->ProductClass = cppData->ProductClass;
				csharpData->DeliveryYear = cppData->DeliveryYear;
				csharpData->DeliveryMonth = cppData->DeliveryMonth;
				csharpData->MaxMarketOrderVolume = cppData->MaxMarketOrderVolume;
				csharpData->MinMarketOrderVolume = cppData->MinMarketOrderVolume;
				csharpData->MaxLimitOrderVolume = cppData->MaxLimitOrderVolume;
				csharpData->MinLimitOrderVolume = cppData->MinLimitOrderVolume;
				csharpData->VolumeMultiple = cppData->VolumeMultiple;
				csharpData->PriceTick = cppData->PriceTick;
				COPY_UNMANAGED_STRING(csharpData->CreateDate, cppData->CreateDate);
				COPY_UNMANAGED_STRING(csharpData->OpenDate, cppData->OpenDate);
				COPY_UNMANAGED_STRING(csharpData->ExpireDate, cppData->ExpireDate);
				COPY_UNMANAGED_STRING(csharpData->StartDelivDate, cppData->StartDelivDate);
				COPY_UNMANAGED_STRING(csharpData->EndDelivDate, cppData->EndDelivDate);
				csharpData->InstLifePhase = cppData->InstLifePhase;
				csharpData->IsTrading = cppData->IsTrading;
				csharpData->PositionType = cppData->PositionType;
				csharpData->PositionDateType = cppData->PositionDateType;
				csharpData->LongMarginRatio = cppData->LongMarginRatio;
				csharpData->ShortMarginRatio = cppData->ShortMarginRatio;
				csharpData->MaxMarginSideAlgorithm = cppData->MaxMarginSideAlgorithm;
				COPY_UNMANAGED_STRING(csharpData->UnderlyingInstrID, cppData->UnderlyingInstrID);
				csharpData->StrikePrice = cppData->StrikePrice;
				csharpData->OptionsType = cppData->OptionsType;
				csharpData->UnderlyingMultiple = cppData->UnderlyingMultiple;
				csharpData->CombinationType = cppData->CombinationType;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryInstrument(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
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


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryDepthMarketData(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQrySettlementInfo(CThostFtdcSettlementInfoField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcSettlementInfoFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcSettlementInfoFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->SettlementID = cppData->SettlementID;
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				csharpData->SequenceNo = cppData->SequenceNo;
				COPY_UNMANAGED_STRING(csharpData->Content, cppData->Content);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQrySettlementInfo(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryTransferBank(CThostFtdcTransferBankField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcTransferBankFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcTransferBankFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBrchID, cppData->BankBrchID);
				COPY_UNMANAGED_STRING(csharpData->BankName, cppData->BankName);
				csharpData->IsActive = cppData->IsActive;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryTransferBank(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcInvestorPositionDetailFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInvestorPositionDetailFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				csharpData->HedgeFlag = cppData->HedgeFlag;
				csharpData->Direction = cppData->Direction;
				COPY_UNMANAGED_STRING(csharpData->OpenDate, cppData->OpenDate);
				COPY_UNMANAGED_STRING(csharpData->TradeID, cppData->TradeID);
				csharpData->Volume = cppData->Volume;
				csharpData->OpenPrice = cppData->OpenPrice;
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->SettlementID = cppData->SettlementID;
				csharpData->TradeType = cppData->TradeType;
				COPY_UNMANAGED_STRING(csharpData->CombInstrumentID, cppData->CombInstrumentID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				csharpData->CloseProfitByDate = cppData->CloseProfitByDate;
				csharpData->CloseProfitByTrade = cppData->CloseProfitByTrade;
				csharpData->PositionProfitByDate = cppData->PositionProfitByDate;
				csharpData->PositionProfitByTrade = cppData->PositionProfitByTrade;
				csharpData->Margin = cppData->Margin;
				csharpData->ExchMargin = cppData->ExchMargin;
				csharpData->MarginRateByMoney = cppData->MarginRateByMoney;
				csharpData->MarginRateByVolume = cppData->MarginRateByVolume;
				csharpData->LastSettlementPrice = cppData->LastSettlementPrice;
				csharpData->SettlementPrice = cppData->SettlementPrice;
				csharpData->CloseVolume = cppData->CloseVolume;
				csharpData->CloseAmount = cppData->CloseAmount;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryInvestorPositionDetail(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryNotice(CThostFtdcNoticeField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcNoticeFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcNoticeFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->Content, cppData->Content);
				COPY_UNMANAGED_STRING(csharpData->SequenceLabel, cppData->SequenceLabel);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryNotice(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcSettlementInfoConfirmFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcSettlementInfoConfirmFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->ConfirmDate, cppData->ConfirmDate);
				COPY_UNMANAGED_STRING(csharpData->ConfirmTime, cppData->ConfirmTime);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQrySettlementInfoConfirm(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcInvestorPositionCombineDetailFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInvestorPositionCombineDetailFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				COPY_UNMANAGED_STRING(csharpData->OpenDate, cppData->OpenDate);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				csharpData->SettlementID = cppData->SettlementID;
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->ComTradeID, cppData->ComTradeID);
				COPY_UNMANAGED_STRING(csharpData->TradeID, cppData->TradeID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				csharpData->HedgeFlag = cppData->HedgeFlag;
				csharpData->Direction = cppData->Direction;
				csharpData->TotalAmt = cppData->TotalAmt;
				csharpData->Margin = cppData->Margin;
				csharpData->ExchMargin = cppData->ExchMargin;
				csharpData->MarginRateByMoney = cppData->MarginRateByMoney;
				csharpData->MarginRateByVolume = cppData->MarginRateByVolume;
				csharpData->LegID = cppData->LegID;
				csharpData->LegMultiple = cppData->LegMultiple;
				COPY_UNMANAGED_STRING(csharpData->CombInstrumentID, cppData->CombInstrumentID);
				csharpData->TradeGroupID = cppData->TradeGroupID;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryInvestorPositionCombineDetail(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcCFMMCTradingAccountKeyFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcCFMMCTradingAccountKeyFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->ParticipantID, cppData->ParticipantID);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				csharpData->KeyID = cppData->KeyID;
				COPY_UNMANAGED_STRING(csharpData->CurrentKey, cppData->CurrentKey);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryCFMMCTradingAccountKey(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcEWarrantOffsetFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcEWarrantOffsetFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				csharpData->Direction = cppData->Direction;
				csharpData->HedgeFlag = cppData->HedgeFlag;
				csharpData->Volume = cppData->Volume;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryEWarrantOffset(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcInvestorProductGroupMarginFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInvestorProductGroupMarginFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->ProductGroupID, cppData->ProductGroupID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->SettlementID = cppData->SettlementID;
				csharpData->FrozenMargin = cppData->FrozenMargin;
				csharpData->LongFrozenMargin = cppData->LongFrozenMargin;
				csharpData->ShortFrozenMargin = cppData->ShortFrozenMargin;
				csharpData->UseMargin = cppData->UseMargin;
				csharpData->LongUseMargin = cppData->LongUseMargin;
				csharpData->ShortUseMargin = cppData->ShortUseMargin;
				csharpData->ExchMargin = cppData->ExchMargin;
				csharpData->LongExchMargin = cppData->LongExchMargin;
				csharpData->ShortExchMargin = cppData->ShortExchMargin;
				csharpData->CloseProfit = cppData->CloseProfit;
				csharpData->FrozenCommission = cppData->FrozenCommission;
				csharpData->Commission = cppData->Commission;
				csharpData->FrozenCash = cppData->FrozenCash;
				csharpData->CashIn = cppData->CashIn;
				csharpData->PositionProfit = cppData->PositionProfit;
				csharpData->OffsetAmount = cppData->OffsetAmount;
				csharpData->LongOffsetAmount = cppData->LongOffsetAmount;
				csharpData->ShortOffsetAmount = cppData->ShortOffsetAmount;
				csharpData->ExchOffsetAmount = cppData->ExchOffsetAmount;
				csharpData->LongExchOffsetAmount = cppData->LongExchOffsetAmount;
				csharpData->ShortExchOffsetAmount = cppData->ShortExchOffsetAmount;
				csharpData->HedgeFlag = cppData->HedgeFlag;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryInvestorProductGroupMargin(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcExchangeMarginRateFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcExchangeMarginRateFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				csharpData->HedgeFlag = cppData->HedgeFlag;
				csharpData->LongMarginRatioByMoney = cppData->LongMarginRatioByMoney;
				csharpData->LongMarginRatioByVolume = cppData->LongMarginRatioByVolume;
				csharpData->ShortMarginRatioByMoney = cppData->ShortMarginRatioByMoney;
				csharpData->ShortMarginRatioByVolume = cppData->ShortMarginRatioByVolume;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryExchangeMarginRate(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcExchangeMarginRateAdjustFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcExchangeMarginRateAdjustFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				csharpData->HedgeFlag = cppData->HedgeFlag;
				csharpData->LongMarginRatioByMoney = cppData->LongMarginRatioByMoney;
				csharpData->LongMarginRatioByVolume = cppData->LongMarginRatioByVolume;
				csharpData->ShortMarginRatioByMoney = cppData->ShortMarginRatioByMoney;
				csharpData->ShortMarginRatioByVolume = cppData->ShortMarginRatioByVolume;
				csharpData->ExchLongMarginRatioByMoney = cppData->ExchLongMarginRatioByMoney;
				csharpData->ExchLongMarginRatioByVolume = cppData->ExchLongMarginRatioByVolume;
				csharpData->ExchShortMarginRatioByMoney = cppData->ExchShortMarginRatioByMoney;
				csharpData->ExchShortMarginRatioByVolume = cppData->ExchShortMarginRatioByVolume;
				csharpData->NoLongMarginRatioByMoney = cppData->NoLongMarginRatioByMoney;
				csharpData->NoLongMarginRatioByVolume = cppData->NoLongMarginRatioByVolume;
				csharpData->NoShortMarginRatioByMoney = cppData->NoShortMarginRatioByMoney;
				csharpData->NoShortMarginRatioByVolume = cppData->NoShortMarginRatioByVolume;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryExchangeMarginRateAdjust(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryExchangeRate(CThostFtdcExchangeRateField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcExchangeRateFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcExchangeRateFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->FromCurrencyID, cppData->FromCurrencyID);
				csharpData->FromCurrencyUnit = cppData->FromCurrencyUnit;
				COPY_UNMANAGED_STRING(csharpData->ToCurrencyID, cppData->ToCurrencyID);
				csharpData->ExchangeRate = cppData->ExchangeRate;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryExchangeRate(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcSecAgentACIDMapFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcSecAgentACIDMapFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				COPY_UNMANAGED_STRING(csharpData->BrokerSecAgentID, cppData->BrokerSecAgentID);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQrySecAgentACIDMap(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryProductExchRate(CThostFtdcProductExchRateField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcProductExchRateFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcProductExchRateFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->ProductID, cppData->ProductID);
				COPY_UNMANAGED_STRING(csharpData->QuoteCurrencyID, cppData->QuoteCurrencyID);
				csharpData->ExchangeRate = cppData->ExchangeRate;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryProductExchRate(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryProductGroup(CThostFtdcProductGroupField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcProductGroupFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcProductGroupFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->ProductID, cppData->ProductID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->ProductGroupID, cppData->ProductGroupID);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryProductGroup(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcMMInstrumentCommissionRateFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcMMInstrumentCommissionRateFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				csharpData->InvestorRange = cppData->InvestorRange;
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				csharpData->OpenRatioByMoney = cppData->OpenRatioByMoney;
				csharpData->OpenRatioByVolume = cppData->OpenRatioByVolume;
				csharpData->CloseRatioByMoney = cppData->CloseRatioByMoney;
				csharpData->CloseRatioByVolume = cppData->CloseRatioByVolume;
				csharpData->CloseTodayRatioByMoney = cppData->CloseTodayRatioByMoney;
				csharpData->CloseTodayRatioByVolume = cppData->CloseTodayRatioByVolume;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryMMInstrumentCommissionRate(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcMMOptionInstrCommRateFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcMMOptionInstrCommRateFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				csharpData->InvestorRange = cppData->InvestorRange;
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				csharpData->OpenRatioByMoney = cppData->OpenRatioByMoney;
				csharpData->OpenRatioByVolume = cppData->OpenRatioByVolume;
				csharpData->CloseRatioByMoney = cppData->CloseRatioByMoney;
				csharpData->CloseRatioByVolume = cppData->CloseRatioByVolume;
				csharpData->CloseTodayRatioByMoney = cppData->CloseTodayRatioByMoney;
				csharpData->CloseTodayRatioByVolume = cppData->CloseTodayRatioByVolume;
				csharpData->StrikeRatioByMoney = cppData->StrikeRatioByMoney;
				csharpData->StrikeRatioByVolume = cppData->StrikeRatioByVolume;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryMMOptionInstrCommRate(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcInstrumentOrderCommRateFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInstrumentOrderCommRateFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				csharpData->InvestorRange = cppData->InvestorRange;
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				csharpData->HedgeFlag = cppData->HedgeFlag;
				csharpData->OrderCommByVolume = cppData->OrderCommByVolume;
				csharpData->OrderActionCommByVolume = cppData->OrderActionCommByVolume;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryInstrumentOrderCommRate(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcOptionInstrTradeCostFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcOptionInstrTradeCostFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				csharpData->HedgeFlag = cppData->HedgeFlag;
				csharpData->FixedMargin = cppData->FixedMargin;
				csharpData->MiniMargin = cppData->MiniMargin;
				csharpData->Royalty = cppData->Royalty;
				csharpData->ExchFixedMargin = cppData->ExchFixedMargin;
				csharpData->ExchMiniMargin = cppData->ExchMiniMargin;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryOptionInstrTradeCost(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcOptionInstrCommRateFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcOptionInstrCommRateFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				csharpData->InvestorRange = cppData->InvestorRange;
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				csharpData->OpenRatioByMoney = cppData->OpenRatioByMoney;
				csharpData->OpenRatioByVolume = cppData->OpenRatioByVolume;
				csharpData->CloseRatioByMoney = cppData->CloseRatioByMoney;
				csharpData->CloseRatioByVolume = cppData->CloseRatioByVolume;
				csharpData->CloseTodayRatioByMoney = cppData->CloseTodayRatioByMoney;
				csharpData->CloseTodayRatioByVolume = cppData->CloseTodayRatioByVolume;
				csharpData->StrikeRatioByMoney = cppData->StrikeRatioByMoney;
				csharpData->StrikeRatioByVolume = cppData->StrikeRatioByVolume;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryOptionInstrCommRate(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryExecOrder(CThostFtdcExecOrderField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcExecOrderFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcExecOrderFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->ExecOrderRef, cppData->ExecOrderRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->Volume = cppData->Volume;
				csharpData->RequestID = cppData->RequestID;
				COPY_UNMANAGED_STRING(csharpData->BusinessUnit, cppData->BusinessUnit);
				csharpData->OffsetFlag = cppData->OffsetFlag;
				csharpData->HedgeFlag = cppData->HedgeFlag;
				csharpData->ActionType = cppData->ActionType;
				csharpData->PosiDirection = cppData->PosiDirection;
				csharpData->ReservePositionFlag = cppData->ReservePositionFlag;
				csharpData->CloseFlag = cppData->CloseFlag;
				COPY_UNMANAGED_STRING(csharpData->ExecOrderLocalID, cppData->ExecOrderLocalID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->ParticipantID, cppData->ParticipantID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeInstID, cppData->ExchangeInstID);
				COPY_UNMANAGED_STRING(csharpData->TraderID, cppData->TraderID);
				csharpData->InstallID = cppData->InstallID;
				csharpData->OrderSubmitStatus = cppData->OrderSubmitStatus;
				csharpData->NotifySequence = cppData->NotifySequence;
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->SettlementID = cppData->SettlementID;
				COPY_UNMANAGED_STRING(csharpData->ExecOrderSysID, cppData->ExecOrderSysID);
				COPY_UNMANAGED_STRING(csharpData->InsertDate, cppData->InsertDate);
				COPY_UNMANAGED_STRING(csharpData->InsertTime, cppData->InsertTime);
				COPY_UNMANAGED_STRING(csharpData->CancelTime, cppData->CancelTime);
				csharpData->ExecResult = cppData->ExecResult;
				COPY_UNMANAGED_STRING(csharpData->ClearingPartID, cppData->ClearingPartID);
				csharpData->SequenceNo = cppData->SequenceNo;
				csharpData->FrontID = cppData->FrontID;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->UserProductInfo, cppData->UserProductInfo);
				COPY_UNMANAGED_STRING(csharpData->StatusMsg, cppData->StatusMsg);
				COPY_UNMANAGED_STRING(csharpData->ActiveUserID, cppData->ActiveUserID);
				csharpData->BrokerExecOrderSeq = cppData->BrokerExecOrderSeq;
				COPY_UNMANAGED_STRING(csharpData->BranchID, cppData->BranchID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryExecOrder(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryForQuote(CThostFtdcForQuoteField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcForQuoteFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcForQuoteFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->ForQuoteRef, cppData->ForQuoteRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				COPY_UNMANAGED_STRING(csharpData->ForQuoteLocalID, cppData->ForQuoteLocalID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->ParticipantID, cppData->ParticipantID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeInstID, cppData->ExchangeInstID);
				COPY_UNMANAGED_STRING(csharpData->TraderID, cppData->TraderID);
				csharpData->InstallID = cppData->InstallID;
				COPY_UNMANAGED_STRING(csharpData->InsertDate, cppData->InsertDate);
				COPY_UNMANAGED_STRING(csharpData->InsertTime, cppData->InsertTime);
				csharpData->ForQuoteStatus = cppData->ForQuoteStatus;
				csharpData->FrontID = cppData->FrontID;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->StatusMsg, cppData->StatusMsg);
				COPY_UNMANAGED_STRING(csharpData->ActiveUserID, cppData->ActiveUserID);
				csharpData->BrokerForQutoSeq = cppData->BrokerForQutoSeq;
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryForQuote(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryQuote(CThostFtdcQuoteField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcQuoteFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcQuoteFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->QuoteRef, cppData->QuoteRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->AskPrice = cppData->AskPrice;
				csharpData->BidPrice = cppData->BidPrice;
				csharpData->AskVolume = cppData->AskVolume;
				csharpData->BidVolume = cppData->BidVolume;
				csharpData->RequestID = cppData->RequestID;
				COPY_UNMANAGED_STRING(csharpData->BusinessUnit, cppData->BusinessUnit);
				csharpData->AskOffsetFlag = cppData->AskOffsetFlag;
				csharpData->BidOffsetFlag = cppData->BidOffsetFlag;
				csharpData->AskHedgeFlag = cppData->AskHedgeFlag;
				csharpData->BidHedgeFlag = cppData->BidHedgeFlag;
				COPY_UNMANAGED_STRING(csharpData->QuoteLocalID, cppData->QuoteLocalID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->ParticipantID, cppData->ParticipantID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeInstID, cppData->ExchangeInstID);
				COPY_UNMANAGED_STRING(csharpData->TraderID, cppData->TraderID);
				csharpData->InstallID = cppData->InstallID;
				csharpData->NotifySequence = cppData->NotifySequence;
				csharpData->OrderSubmitStatus = cppData->OrderSubmitStatus;
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->SettlementID = cppData->SettlementID;
				COPY_UNMANAGED_STRING(csharpData->QuoteSysID, cppData->QuoteSysID);
				COPY_UNMANAGED_STRING(csharpData->InsertDate, cppData->InsertDate);
				COPY_UNMANAGED_STRING(csharpData->InsertTime, cppData->InsertTime);
				COPY_UNMANAGED_STRING(csharpData->CancelTime, cppData->CancelTime);
				csharpData->QuoteStatus = cppData->QuoteStatus;
				COPY_UNMANAGED_STRING(csharpData->ClearingPartID, cppData->ClearingPartID);
				csharpData->SequenceNo = cppData->SequenceNo;
				COPY_UNMANAGED_STRING(csharpData->AskOrderSysID, cppData->AskOrderSysID);
				COPY_UNMANAGED_STRING(csharpData->BidOrderSysID, cppData->BidOrderSysID);
				csharpData->FrontID = cppData->FrontID;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->UserProductInfo, cppData->UserProductInfo);
				COPY_UNMANAGED_STRING(csharpData->StatusMsg, cppData->StatusMsg);
				COPY_UNMANAGED_STRING(csharpData->ActiveUserID, cppData->ActiveUserID);
				csharpData->BrokerQuoteSeq = cppData->BrokerQuoteSeq;
				COPY_UNMANAGED_STRING(csharpData->AskOrderRef, cppData->AskOrderRef);
				COPY_UNMANAGED_STRING(csharpData->BidOrderRef, cppData->BidOrderRef);
				COPY_UNMANAGED_STRING(csharpData->ForQuoteSysID, cppData->ForQuoteSysID);
				COPY_UNMANAGED_STRING(csharpData->BranchID, cppData->BranchID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryQuote(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcCombInstrumentGuardFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcCombInstrumentGuardFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				csharpData->GuarantRatio = cppData->GuarantRatio;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryCombInstrumentGuard(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryCombAction(CThostFtdcCombActionField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcCombActionFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcCombActionFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->CombActionRef, cppData->CombActionRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->Direction = cppData->Direction;
				csharpData->Volume = cppData->Volume;
				csharpData->CombDirection = cppData->CombDirection;
				csharpData->HedgeFlag = cppData->HedgeFlag;
				COPY_UNMANAGED_STRING(csharpData->ActionLocalID, cppData->ActionLocalID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->ParticipantID, cppData->ParticipantID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeInstID, cppData->ExchangeInstID);
				COPY_UNMANAGED_STRING(csharpData->TraderID, cppData->TraderID);
				csharpData->InstallID = cppData->InstallID;
				csharpData->ActionStatus = cppData->ActionStatus;
				csharpData->NotifySequence = cppData->NotifySequence;
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->SettlementID = cppData->SettlementID;
				csharpData->SequenceNo = cppData->SequenceNo;
				csharpData->FrontID = cppData->FrontID;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->UserProductInfo, cppData->UserProductInfo);
				COPY_UNMANAGED_STRING(csharpData->StatusMsg, cppData->StatusMsg);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryCombAction(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryTransferSerial(CThostFtdcTransferSerialField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcTransferSerialFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcTransferSerialFieldWrapper();
				csharpData->PlateSerial = cppData->PlateSerial;
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				csharpData->FutureAccType = cppData->FutureAccType;
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				csharpData->FutureSerial = cppData->FutureSerial;
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				csharpData->TradeAmount = cppData->TradeAmount;
				csharpData->CustFee = cppData->CustFee;
				csharpData->BrokerFee = cppData->BrokerFee;
				csharpData->AvailabilityFlag = cppData->AvailabilityFlag;
				COPY_UNMANAGED_STRING(csharpData->OperatorCode, cppData->OperatorCode);
				COPY_UNMANAGED_STRING(csharpData->BankNewAccount, cppData->BankNewAccount);
				csharpData->ErrorID = cppData->ErrorID;
				COPY_UNMANAGED_STRING(csharpData->ErrorMsg, cppData->ErrorMsg);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryTransferSerial(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryAccountregister(CThostFtdcAccountregisterField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcAccountregisterFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcAccountregisterFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->TradeDay, cppData->TradeDay);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				csharpData->OpenOrDestroy = cppData->OpenOrDestroy;
				COPY_UNMANAGED_STRING(csharpData->RegDate, cppData->RegDate);
				COPY_UNMANAGED_STRING(csharpData->OutDate, cppData->OutDate);
				csharpData->TID = cppData->TID;
				csharpData->CustType = cppData->CustType;
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryAccountregister(csharpData, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRtnOrder(CThostFtdcOrderField* cppData) override
		{
			CThostFtdcOrderFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcOrderFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->OrderRef, cppData->OrderRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->OrderPriceType = cppData->OrderPriceType;
				csharpData->Direction = cppData->Direction;
				COPY_UNMANAGED_STRING(csharpData->CombOffsetFlag, cppData->CombOffsetFlag);
				COPY_UNMANAGED_STRING(csharpData->CombHedgeFlag, cppData->CombHedgeFlag);
				csharpData->LimitPrice = cppData->LimitPrice;
				csharpData->VolumeTotalOriginal = cppData->VolumeTotalOriginal;
				csharpData->TimeCondition = cppData->TimeCondition;
				COPY_UNMANAGED_STRING(csharpData->GTDDate, cppData->GTDDate);
				csharpData->VolumeCondition = cppData->VolumeCondition;
				csharpData->MinVolume = cppData->MinVolume;
				csharpData->ContingentCondition = cppData->ContingentCondition;
				csharpData->StopPrice = cppData->StopPrice;
				csharpData->ForceCloseReason = cppData->ForceCloseReason;
				csharpData->IsAutoSuspend = cppData->IsAutoSuspend;
				COPY_UNMANAGED_STRING(csharpData->BusinessUnit, cppData->BusinessUnit);
				csharpData->RequestID = cppData->RequestID;
				COPY_UNMANAGED_STRING(csharpData->OrderLocalID, cppData->OrderLocalID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->ParticipantID, cppData->ParticipantID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeInstID, cppData->ExchangeInstID);
				COPY_UNMANAGED_STRING(csharpData->TraderID, cppData->TraderID);
				csharpData->InstallID = cppData->InstallID;
				csharpData->OrderSubmitStatus = cppData->OrderSubmitStatus;
				csharpData->NotifySequence = cppData->NotifySequence;
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->SettlementID = cppData->SettlementID;
				COPY_UNMANAGED_STRING(csharpData->OrderSysID, cppData->OrderSysID);
				csharpData->OrderSource = cppData->OrderSource;
				csharpData->OrderStatus = cppData->OrderStatus;
				csharpData->OrderType = cppData->OrderType;
				csharpData->VolumeTraded = cppData->VolumeTraded;
				csharpData->VolumeTotal = cppData->VolumeTotal;
				COPY_UNMANAGED_STRING(csharpData->InsertDate, cppData->InsertDate);
				COPY_UNMANAGED_STRING(csharpData->InsertTime, cppData->InsertTime);
				COPY_UNMANAGED_STRING(csharpData->ActiveTime, cppData->ActiveTime);
				COPY_UNMANAGED_STRING(csharpData->SuspendTime, cppData->SuspendTime);
				COPY_UNMANAGED_STRING(csharpData->UpdateTime, cppData->UpdateTime);
				COPY_UNMANAGED_STRING(csharpData->CancelTime, cppData->CancelTime);
				COPY_UNMANAGED_STRING(csharpData->ActiveTraderID, cppData->ActiveTraderID);
				COPY_UNMANAGED_STRING(csharpData->ClearingPartID, cppData->ClearingPartID);
				csharpData->SequenceNo = cppData->SequenceNo;
				csharpData->FrontID = cppData->FrontID;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->UserProductInfo, cppData->UserProductInfo);
				COPY_UNMANAGED_STRING(csharpData->StatusMsg, cppData->StatusMsg);
				csharpData->UserForceClose = cppData->UserForceClose;
				COPY_UNMANAGED_STRING(csharpData->ActiveUserID, cppData->ActiveUserID);
				csharpData->BrokerOrderSeq = cppData->BrokerOrderSeq;
				COPY_UNMANAGED_STRING(csharpData->RelativeOrderSysID, cppData->RelativeOrderSysID);
				csharpData->ZCETotalTradedVolume = cppData->ZCETotalTradedVolume;
				csharpData->IsSwapOrder = cppData->IsSwapOrder;
				COPY_UNMANAGED_STRING(csharpData->BranchID, cppData->BranchID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}

			return wrapper_->OnRtnOrder(csharpData);
		}
		virtual void OnRtnTrade(CThostFtdcTradeField* cppData) override
		{
			CThostFtdcTradeFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcTradeFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->OrderRef, cppData->OrderRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->TradeID, cppData->TradeID);
				csharpData->Direction = cppData->Direction;
				COPY_UNMANAGED_STRING(csharpData->OrderSysID, cppData->OrderSysID);
				COPY_UNMANAGED_STRING(csharpData->ParticipantID, cppData->ParticipantID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				csharpData->TradingRole = cppData->TradingRole;
				COPY_UNMANAGED_STRING(csharpData->ExchangeInstID, cppData->ExchangeInstID);
				csharpData->OffsetFlag = cppData->OffsetFlag;
				csharpData->HedgeFlag = cppData->HedgeFlag;
				csharpData->Price = cppData->Price;
				csharpData->Volume = cppData->Volume;
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				csharpData->TradeType = cppData->TradeType;
				csharpData->PriceSource = cppData->PriceSource;
				COPY_UNMANAGED_STRING(csharpData->TraderID, cppData->TraderID);
				COPY_UNMANAGED_STRING(csharpData->OrderLocalID, cppData->OrderLocalID);
				COPY_UNMANAGED_STRING(csharpData->ClearingPartID, cppData->ClearingPartID);
				COPY_UNMANAGED_STRING(csharpData->BusinessUnit, cppData->BusinessUnit);
				csharpData->SequenceNo = cppData->SequenceNo;
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->SettlementID = cppData->SettlementID;
				csharpData->BrokerOrderSeq = cppData->BrokerOrderSeq;
				csharpData->TradeSource = cppData->TradeSource;
			}

			return wrapper_->OnRtnTrade(csharpData);
		}
		virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField* cppData, CThostFtdcRspInfoField* cppError) override
		{
			CThostFtdcInputOrderFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInputOrderFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->OrderRef, cppData->OrderRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->OrderPriceType = cppData->OrderPriceType;
				csharpData->Direction = cppData->Direction;
				COPY_UNMANAGED_STRING(csharpData->CombOffsetFlag, cppData->CombOffsetFlag);
				COPY_UNMANAGED_STRING(csharpData->CombHedgeFlag, cppData->CombHedgeFlag);
				csharpData->LimitPrice = cppData->LimitPrice;
				csharpData->VolumeTotalOriginal = cppData->VolumeTotalOriginal;
				csharpData->TimeCondition = cppData->TimeCondition;
				COPY_UNMANAGED_STRING(csharpData->GTDDate, cppData->GTDDate);
				csharpData->VolumeCondition = cppData->VolumeCondition;
				csharpData->MinVolume = cppData->MinVolume;
				csharpData->ContingentCondition = cppData->ContingentCondition;
				csharpData->StopPrice = cppData->StopPrice;
				csharpData->ForceCloseReason = cppData->ForceCloseReason;
				csharpData->IsAutoSuspend = cppData->IsAutoSuspend;
				COPY_UNMANAGED_STRING(csharpData->BusinessUnit, cppData->BusinessUnit);
				csharpData->RequestID = cppData->RequestID;
				csharpData->UserForceClose = cppData->UserForceClose;
				csharpData->IsSwapOrder = cppData->IsSwapOrder;
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnErrRtnOrderInsert(csharpData, csharpError);
		}

		virtual void OnErrRtnOrderAction(CThostFtdcOrderActionField* cppData, CThostFtdcRspInfoField* cppError) override
		{
			CThostFtdcOrderActionFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcOrderActionFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				csharpData->OrderActionRef = cppData->OrderActionRef;
				COPY_UNMANAGED_STRING(csharpData->OrderRef, cppData->OrderRef);
				csharpData->RequestID = cppData->RequestID;
				csharpData->FrontID = cppData->FrontID;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->OrderSysID, cppData->OrderSysID);
				csharpData->ActionFlag = cppData->ActionFlag;
				csharpData->LimitPrice = cppData->LimitPrice;
				csharpData->VolumeChange = cppData->VolumeChange;
				COPY_UNMANAGED_STRING(csharpData->ActionDate, cppData->ActionDate);
				COPY_UNMANAGED_STRING(csharpData->ActionTime, cppData->ActionTime);
				COPY_UNMANAGED_STRING(csharpData->TraderID, cppData->TraderID);
				csharpData->InstallID = cppData->InstallID;
				COPY_UNMANAGED_STRING(csharpData->OrderLocalID, cppData->OrderLocalID);
				COPY_UNMANAGED_STRING(csharpData->ActionLocalID, cppData->ActionLocalID);
				COPY_UNMANAGED_STRING(csharpData->ParticipantID, cppData->ParticipantID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->BusinessUnit, cppData->BusinessUnit);
				csharpData->OrderActionStatus = cppData->OrderActionStatus;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				COPY_UNMANAGED_STRING(csharpData->StatusMsg, cppData->StatusMsg);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->BranchID, cppData->BranchID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnErrRtnOrderAction(csharpData, csharpError);
		}

		virtual void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField* cppData) override
		{
			CThostFtdcInstrumentStatusFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInstrumentStatusFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeInstID, cppData->ExchangeInstID);
				COPY_UNMANAGED_STRING(csharpData->SettlementGroupID, cppData->SettlementGroupID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				csharpData->InstrumentStatus = cppData->InstrumentStatus;
				csharpData->TradingSegmentSN = cppData->TradingSegmentSN;
				COPY_UNMANAGED_STRING(csharpData->EnterTime, cppData->EnterTime);
				csharpData->EnterReason = cppData->EnterReason;
			}

			return wrapper_->OnRtnInstrumentStatus(csharpData);
		}
		virtual void OnRtnBulletin(CThostFtdcBulletinField* cppData) override
		{
			CThostFtdcBulletinFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcBulletinFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->BulletinID = cppData->BulletinID;
				csharpData->SequenceNo = cppData->SequenceNo;
				COPY_UNMANAGED_STRING(csharpData->NewsType, cppData->NewsType);
				csharpData->NewsUrgency = cppData->NewsUrgency;
				COPY_UNMANAGED_STRING(csharpData->SendTime, cppData->SendTime);
				COPY_UNMANAGED_STRING(csharpData->Abstract, cppData->Abstract);
				COPY_UNMANAGED_STRING(csharpData->ComeFrom, cppData->ComeFrom);
				COPY_UNMANAGED_STRING(csharpData->Content, cppData->Content);
				COPY_UNMANAGED_STRING(csharpData->URLLink, cppData->URLLink);
				COPY_UNMANAGED_STRING(csharpData->MarketID, cppData->MarketID);
			}

			return wrapper_->OnRtnBulletin(csharpData);
		}
		virtual void OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField* cppData) override
		{
			CThostFtdcTradingNoticeInfoFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcTradingNoticeInfoFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->SendTime, cppData->SendTime);
				COPY_UNMANAGED_STRING(csharpData->FieldContent, cppData->FieldContent);
				csharpData->SequenceSeries = cppData->SequenceSeries;
				csharpData->SequenceNo = cppData->SequenceNo;
			}

			return wrapper_->OnRtnTradingNotice(csharpData);
		}
		virtual void OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField* cppData) override
		{
			CThostFtdcErrorConditionalOrderFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcErrorConditionalOrderFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->OrderRef, cppData->OrderRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->OrderPriceType = cppData->OrderPriceType;
				csharpData->Direction = cppData->Direction;
				COPY_UNMANAGED_STRING(csharpData->CombOffsetFlag, cppData->CombOffsetFlag);
				COPY_UNMANAGED_STRING(csharpData->CombHedgeFlag, cppData->CombHedgeFlag);
				csharpData->LimitPrice = cppData->LimitPrice;
				csharpData->VolumeTotalOriginal = cppData->VolumeTotalOriginal;
				csharpData->TimeCondition = cppData->TimeCondition;
				COPY_UNMANAGED_STRING(csharpData->GTDDate, cppData->GTDDate);
				csharpData->VolumeCondition = cppData->VolumeCondition;
				csharpData->MinVolume = cppData->MinVolume;
				csharpData->ContingentCondition = cppData->ContingentCondition;
				csharpData->StopPrice = cppData->StopPrice;
				csharpData->ForceCloseReason = cppData->ForceCloseReason;
				csharpData->IsAutoSuspend = cppData->IsAutoSuspend;
				COPY_UNMANAGED_STRING(csharpData->BusinessUnit, cppData->BusinessUnit);
				csharpData->RequestID = cppData->RequestID;
				COPY_UNMANAGED_STRING(csharpData->OrderLocalID, cppData->OrderLocalID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->ParticipantID, cppData->ParticipantID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeInstID, cppData->ExchangeInstID);
				COPY_UNMANAGED_STRING(csharpData->TraderID, cppData->TraderID);
				csharpData->InstallID = cppData->InstallID;
				csharpData->OrderSubmitStatus = cppData->OrderSubmitStatus;
				csharpData->NotifySequence = cppData->NotifySequence;
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->SettlementID = cppData->SettlementID;
				COPY_UNMANAGED_STRING(csharpData->OrderSysID, cppData->OrderSysID);
				csharpData->OrderSource = cppData->OrderSource;
				csharpData->OrderStatus = cppData->OrderStatus;
				csharpData->OrderType = cppData->OrderType;
				csharpData->VolumeTraded = cppData->VolumeTraded;
				csharpData->VolumeTotal = cppData->VolumeTotal;
				COPY_UNMANAGED_STRING(csharpData->InsertDate, cppData->InsertDate);
				COPY_UNMANAGED_STRING(csharpData->InsertTime, cppData->InsertTime);
				COPY_UNMANAGED_STRING(csharpData->ActiveTime, cppData->ActiveTime);
				COPY_UNMANAGED_STRING(csharpData->SuspendTime, cppData->SuspendTime);
				COPY_UNMANAGED_STRING(csharpData->UpdateTime, cppData->UpdateTime);
				COPY_UNMANAGED_STRING(csharpData->CancelTime, cppData->CancelTime);
				COPY_UNMANAGED_STRING(csharpData->ActiveTraderID, cppData->ActiveTraderID);
				COPY_UNMANAGED_STRING(csharpData->ClearingPartID, cppData->ClearingPartID);
				csharpData->SequenceNo = cppData->SequenceNo;
				csharpData->FrontID = cppData->FrontID;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->UserProductInfo, cppData->UserProductInfo);
				COPY_UNMANAGED_STRING(csharpData->StatusMsg, cppData->StatusMsg);
				csharpData->UserForceClose = cppData->UserForceClose;
				COPY_UNMANAGED_STRING(csharpData->ActiveUserID, cppData->ActiveUserID);
				csharpData->BrokerOrderSeq = cppData->BrokerOrderSeq;
				COPY_UNMANAGED_STRING(csharpData->RelativeOrderSysID, cppData->RelativeOrderSysID);
				csharpData->ZCETotalTradedVolume = cppData->ZCETotalTradedVolume;
				csharpData->ErrorID = cppData->ErrorID;
				COPY_UNMANAGED_STRING(csharpData->ErrorMsg, cppData->ErrorMsg);
				csharpData->IsSwapOrder = cppData->IsSwapOrder;
				COPY_UNMANAGED_STRING(csharpData->BranchID, cppData->BranchID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}

			return wrapper_->OnRtnErrorConditionalOrder(csharpData);
		}
		virtual void OnRtnExecOrder(CThostFtdcExecOrderField* cppData) override
		{
			CThostFtdcExecOrderFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcExecOrderFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->ExecOrderRef, cppData->ExecOrderRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->Volume = cppData->Volume;
				csharpData->RequestID = cppData->RequestID;
				COPY_UNMANAGED_STRING(csharpData->BusinessUnit, cppData->BusinessUnit);
				csharpData->OffsetFlag = cppData->OffsetFlag;
				csharpData->HedgeFlag = cppData->HedgeFlag;
				csharpData->ActionType = cppData->ActionType;
				csharpData->PosiDirection = cppData->PosiDirection;
				csharpData->ReservePositionFlag = cppData->ReservePositionFlag;
				csharpData->CloseFlag = cppData->CloseFlag;
				COPY_UNMANAGED_STRING(csharpData->ExecOrderLocalID, cppData->ExecOrderLocalID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->ParticipantID, cppData->ParticipantID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeInstID, cppData->ExchangeInstID);
				COPY_UNMANAGED_STRING(csharpData->TraderID, cppData->TraderID);
				csharpData->InstallID = cppData->InstallID;
				csharpData->OrderSubmitStatus = cppData->OrderSubmitStatus;
				csharpData->NotifySequence = cppData->NotifySequence;
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->SettlementID = cppData->SettlementID;
				COPY_UNMANAGED_STRING(csharpData->ExecOrderSysID, cppData->ExecOrderSysID);
				COPY_UNMANAGED_STRING(csharpData->InsertDate, cppData->InsertDate);
				COPY_UNMANAGED_STRING(csharpData->InsertTime, cppData->InsertTime);
				COPY_UNMANAGED_STRING(csharpData->CancelTime, cppData->CancelTime);
				csharpData->ExecResult = cppData->ExecResult;
				COPY_UNMANAGED_STRING(csharpData->ClearingPartID, cppData->ClearingPartID);
				csharpData->SequenceNo = cppData->SequenceNo;
				csharpData->FrontID = cppData->FrontID;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->UserProductInfo, cppData->UserProductInfo);
				COPY_UNMANAGED_STRING(csharpData->StatusMsg, cppData->StatusMsg);
				COPY_UNMANAGED_STRING(csharpData->ActiveUserID, cppData->ActiveUserID);
				csharpData->BrokerExecOrderSeq = cppData->BrokerExecOrderSeq;
				COPY_UNMANAGED_STRING(csharpData->BranchID, cppData->BranchID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}

			return wrapper_->OnRtnExecOrder(csharpData);
		}
		virtual void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField* cppData, CThostFtdcRspInfoField* cppError) override
		{
			CThostFtdcInputExecOrderFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInputExecOrderFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->ExecOrderRef, cppData->ExecOrderRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->Volume = cppData->Volume;
				csharpData->RequestID = cppData->RequestID;
				COPY_UNMANAGED_STRING(csharpData->BusinessUnit, cppData->BusinessUnit);
				csharpData->OffsetFlag = cppData->OffsetFlag;
				csharpData->HedgeFlag = cppData->HedgeFlag;
				csharpData->ActionType = cppData->ActionType;
				csharpData->PosiDirection = cppData->PosiDirection;
				csharpData->ReservePositionFlag = cppData->ReservePositionFlag;
				csharpData->CloseFlag = cppData->CloseFlag;
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnErrRtnExecOrderInsert(csharpData, csharpError);
		}

		virtual void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField* cppData, CThostFtdcRspInfoField* cppError) override
		{
			CThostFtdcExecOrderActionFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcExecOrderActionFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				csharpData->ExecOrderActionRef = cppData->ExecOrderActionRef;
				COPY_UNMANAGED_STRING(csharpData->ExecOrderRef, cppData->ExecOrderRef);
				csharpData->RequestID = cppData->RequestID;
				csharpData->FrontID = cppData->FrontID;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->ExecOrderSysID, cppData->ExecOrderSysID);
				csharpData->ActionFlag = cppData->ActionFlag;
				COPY_UNMANAGED_STRING(csharpData->ActionDate, cppData->ActionDate);
				COPY_UNMANAGED_STRING(csharpData->ActionTime, cppData->ActionTime);
				COPY_UNMANAGED_STRING(csharpData->TraderID, cppData->TraderID);
				csharpData->InstallID = cppData->InstallID;
				COPY_UNMANAGED_STRING(csharpData->ExecOrderLocalID, cppData->ExecOrderLocalID);
				COPY_UNMANAGED_STRING(csharpData->ActionLocalID, cppData->ActionLocalID);
				COPY_UNMANAGED_STRING(csharpData->ParticipantID, cppData->ParticipantID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->BusinessUnit, cppData->BusinessUnit);
				csharpData->OrderActionStatus = cppData->OrderActionStatus;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->ActionType = cppData->ActionType;
				COPY_UNMANAGED_STRING(csharpData->StatusMsg, cppData->StatusMsg);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->BranchID, cppData->BranchID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnErrRtnExecOrderAction(csharpData, csharpError);
		}

		virtual void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField* cppData, CThostFtdcRspInfoField* cppError) override
		{
			CThostFtdcInputForQuoteFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInputForQuoteFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->ForQuoteRef, cppData->ForQuoteRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnErrRtnForQuoteInsert(csharpData, csharpError);
		}

		virtual void OnRtnQuote(CThostFtdcQuoteField* cppData) override
		{
			CThostFtdcQuoteFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcQuoteFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->QuoteRef, cppData->QuoteRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->AskPrice = cppData->AskPrice;
				csharpData->BidPrice = cppData->BidPrice;
				csharpData->AskVolume = cppData->AskVolume;
				csharpData->BidVolume = cppData->BidVolume;
				csharpData->RequestID = cppData->RequestID;
				COPY_UNMANAGED_STRING(csharpData->BusinessUnit, cppData->BusinessUnit);
				csharpData->AskOffsetFlag = cppData->AskOffsetFlag;
				csharpData->BidOffsetFlag = cppData->BidOffsetFlag;
				csharpData->AskHedgeFlag = cppData->AskHedgeFlag;
				csharpData->BidHedgeFlag = cppData->BidHedgeFlag;
				COPY_UNMANAGED_STRING(csharpData->QuoteLocalID, cppData->QuoteLocalID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->ParticipantID, cppData->ParticipantID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeInstID, cppData->ExchangeInstID);
				COPY_UNMANAGED_STRING(csharpData->TraderID, cppData->TraderID);
				csharpData->InstallID = cppData->InstallID;
				csharpData->NotifySequence = cppData->NotifySequence;
				csharpData->OrderSubmitStatus = cppData->OrderSubmitStatus;
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->SettlementID = cppData->SettlementID;
				COPY_UNMANAGED_STRING(csharpData->QuoteSysID, cppData->QuoteSysID);
				COPY_UNMANAGED_STRING(csharpData->InsertDate, cppData->InsertDate);
				COPY_UNMANAGED_STRING(csharpData->InsertTime, cppData->InsertTime);
				COPY_UNMANAGED_STRING(csharpData->CancelTime, cppData->CancelTime);
				csharpData->QuoteStatus = cppData->QuoteStatus;
				COPY_UNMANAGED_STRING(csharpData->ClearingPartID, cppData->ClearingPartID);
				csharpData->SequenceNo = cppData->SequenceNo;
				COPY_UNMANAGED_STRING(csharpData->AskOrderSysID, cppData->AskOrderSysID);
				COPY_UNMANAGED_STRING(csharpData->BidOrderSysID, cppData->BidOrderSysID);
				csharpData->FrontID = cppData->FrontID;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->UserProductInfo, cppData->UserProductInfo);
				COPY_UNMANAGED_STRING(csharpData->StatusMsg, cppData->StatusMsg);
				COPY_UNMANAGED_STRING(csharpData->ActiveUserID, cppData->ActiveUserID);
				csharpData->BrokerQuoteSeq = cppData->BrokerQuoteSeq;
				COPY_UNMANAGED_STRING(csharpData->AskOrderRef, cppData->AskOrderRef);
				COPY_UNMANAGED_STRING(csharpData->BidOrderRef, cppData->BidOrderRef);
				COPY_UNMANAGED_STRING(csharpData->ForQuoteSysID, cppData->ForQuoteSysID);
				COPY_UNMANAGED_STRING(csharpData->BranchID, cppData->BranchID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}

			return wrapper_->OnRtnQuote(csharpData);
		}
		virtual void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField* cppData, CThostFtdcRspInfoField* cppError) override
		{
			CThostFtdcInputQuoteFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInputQuoteFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->QuoteRef, cppData->QuoteRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->AskPrice = cppData->AskPrice;
				csharpData->BidPrice = cppData->BidPrice;
				csharpData->AskVolume = cppData->AskVolume;
				csharpData->BidVolume = cppData->BidVolume;
				csharpData->RequestID = cppData->RequestID;
				COPY_UNMANAGED_STRING(csharpData->BusinessUnit, cppData->BusinessUnit);
				csharpData->AskOffsetFlag = cppData->AskOffsetFlag;
				csharpData->BidOffsetFlag = cppData->BidOffsetFlag;
				csharpData->AskHedgeFlag = cppData->AskHedgeFlag;
				csharpData->BidHedgeFlag = cppData->BidHedgeFlag;
				COPY_UNMANAGED_STRING(csharpData->AskOrderRef, cppData->AskOrderRef);
				COPY_UNMANAGED_STRING(csharpData->BidOrderRef, cppData->BidOrderRef);
				COPY_UNMANAGED_STRING(csharpData->ForQuoteSysID, cppData->ForQuoteSysID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnErrRtnQuoteInsert(csharpData, csharpError);
		}

		virtual void OnErrRtnQuoteAction(CThostFtdcQuoteActionField* cppData, CThostFtdcRspInfoField* cppError) override
		{
			CThostFtdcQuoteActionFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcQuoteActionFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				csharpData->QuoteActionRef = cppData->QuoteActionRef;
				COPY_UNMANAGED_STRING(csharpData->QuoteRef, cppData->QuoteRef);
				csharpData->RequestID = cppData->RequestID;
				csharpData->FrontID = cppData->FrontID;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->QuoteSysID, cppData->QuoteSysID);
				csharpData->ActionFlag = cppData->ActionFlag;
				COPY_UNMANAGED_STRING(csharpData->ActionDate, cppData->ActionDate);
				COPY_UNMANAGED_STRING(csharpData->ActionTime, cppData->ActionTime);
				COPY_UNMANAGED_STRING(csharpData->TraderID, cppData->TraderID);
				csharpData->InstallID = cppData->InstallID;
				COPY_UNMANAGED_STRING(csharpData->QuoteLocalID, cppData->QuoteLocalID);
				COPY_UNMANAGED_STRING(csharpData->ActionLocalID, cppData->ActionLocalID);
				COPY_UNMANAGED_STRING(csharpData->ParticipantID, cppData->ParticipantID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->BusinessUnit, cppData->BusinessUnit);
				csharpData->OrderActionStatus = cppData->OrderActionStatus;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				COPY_UNMANAGED_STRING(csharpData->StatusMsg, cppData->StatusMsg);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->BranchID, cppData->BranchID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnErrRtnQuoteAction(csharpData, csharpError);
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
		virtual void OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField* cppData) override
		{
			CThostFtdcCFMMCTradingAccountTokenFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcCFMMCTradingAccountTokenFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->ParticipantID, cppData->ParticipantID);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				csharpData->KeyID = cppData->KeyID;
				COPY_UNMANAGED_STRING(csharpData->Token, cppData->Token);
			}

			return wrapper_->OnRtnCFMMCTradingAccountToken(csharpData);
		}
		virtual void OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField* cppData, CThostFtdcRspInfoField* cppError) override
		{
			CThostFtdcBatchOrderActionFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcBatchOrderActionFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				csharpData->OrderActionRef = cppData->OrderActionRef;
				csharpData->RequestID = cppData->RequestID;
				csharpData->FrontID = cppData->FrontID;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->ActionDate, cppData->ActionDate);
				COPY_UNMANAGED_STRING(csharpData->ActionTime, cppData->ActionTime);
				COPY_UNMANAGED_STRING(csharpData->TraderID, cppData->TraderID);
				csharpData->InstallID = cppData->InstallID;
				COPY_UNMANAGED_STRING(csharpData->ActionLocalID, cppData->ActionLocalID);
				COPY_UNMANAGED_STRING(csharpData->ParticipantID, cppData->ParticipantID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->BusinessUnit, cppData->BusinessUnit);
				csharpData->OrderActionStatus = cppData->OrderActionStatus;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				COPY_UNMANAGED_STRING(csharpData->StatusMsg, cppData->StatusMsg);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnErrRtnBatchOrderAction(csharpData, csharpError);
		}

		virtual void OnRtnCombAction(CThostFtdcCombActionField* cppData) override
		{
			CThostFtdcCombActionFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcCombActionFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->CombActionRef, cppData->CombActionRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->Direction = cppData->Direction;
				csharpData->Volume = cppData->Volume;
				csharpData->CombDirection = cppData->CombDirection;
				csharpData->HedgeFlag = cppData->HedgeFlag;
				COPY_UNMANAGED_STRING(csharpData->ActionLocalID, cppData->ActionLocalID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->ParticipantID, cppData->ParticipantID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeInstID, cppData->ExchangeInstID);
				COPY_UNMANAGED_STRING(csharpData->TraderID, cppData->TraderID);
				csharpData->InstallID = cppData->InstallID;
				csharpData->ActionStatus = cppData->ActionStatus;
				csharpData->NotifySequence = cppData->NotifySequence;
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->SettlementID = cppData->SettlementID;
				csharpData->SequenceNo = cppData->SequenceNo;
				csharpData->FrontID = cppData->FrontID;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->UserProductInfo, cppData->UserProductInfo);
				COPY_UNMANAGED_STRING(csharpData->StatusMsg, cppData->StatusMsg);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}

			return wrapper_->OnRtnCombAction(csharpData);
		}
		virtual void OnErrRtnCombActionInsert(CThostFtdcInputCombActionField* cppData, CThostFtdcRspInfoField* cppError) override
		{
			CThostFtdcInputCombActionFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcInputCombActionFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->CombActionRef, cppData->CombActionRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->Direction = cppData->Direction;
				csharpData->Volume = cppData->Volume;
				csharpData->CombDirection = cppData->CombDirection;
				csharpData->HedgeFlag = cppData->HedgeFlag;
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnErrRtnCombActionInsert(csharpData, csharpError);
		}

		void OnRspQryContractBank(CThostFtdcContractBankField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcContractBankFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcContractBankFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBrchID, cppData->BankBrchID);
				COPY_UNMANAGED_STRING(csharpData->BankName, cppData->BankName);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryContractBank(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryParkedOrder(CThostFtdcParkedOrderField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcParkedOrderFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcParkedOrderFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->OrderRef, cppData->OrderRef);
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->OrderPriceType = cppData->OrderPriceType;
				csharpData->Direction = cppData->Direction;
				COPY_UNMANAGED_STRING(csharpData->CombOffsetFlag, cppData->CombOffsetFlag);
				COPY_UNMANAGED_STRING(csharpData->CombHedgeFlag, cppData->CombHedgeFlag);
				csharpData->LimitPrice = cppData->LimitPrice;
				csharpData->VolumeTotalOriginal = cppData->VolumeTotalOriginal;
				csharpData->TimeCondition = cppData->TimeCondition;
				COPY_UNMANAGED_STRING(csharpData->GTDDate, cppData->GTDDate);
				csharpData->VolumeCondition = cppData->VolumeCondition;
				csharpData->MinVolume = cppData->MinVolume;
				csharpData->ContingentCondition = cppData->ContingentCondition;
				csharpData->StopPrice = cppData->StopPrice;
				csharpData->ForceCloseReason = cppData->ForceCloseReason;
				csharpData->IsAutoSuspend = cppData->IsAutoSuspend;
				COPY_UNMANAGED_STRING(csharpData->BusinessUnit, cppData->BusinessUnit);
				csharpData->RequestID = cppData->RequestID;
				csharpData->UserForceClose = cppData->UserForceClose;
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->ParkedOrderID, cppData->ParkedOrderID);
				csharpData->UserType = cppData->UserType;
				csharpData->Status = cppData->Status;
				csharpData->ErrorID = cppData->ErrorID;
				COPY_UNMANAGED_STRING(csharpData->ErrorMsg, cppData->ErrorMsg);
				csharpData->IsSwapOrder = cppData->IsSwapOrder;
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryParkedOrder(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcParkedOrderActionFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcParkedOrderActionFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				csharpData->OrderActionRef = cppData->OrderActionRef;
				COPY_UNMANAGED_STRING(csharpData->OrderRef, cppData->OrderRef);
				csharpData->RequestID = cppData->RequestID;
				csharpData->FrontID = cppData->FrontID;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->OrderSysID, cppData->OrderSysID);
				csharpData->ActionFlag = cppData->ActionFlag;
				csharpData->LimitPrice = cppData->LimitPrice;
				csharpData->VolumeChange = cppData->VolumeChange;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				COPY_UNMANAGED_STRING(csharpData->ParkedOrderActionID, cppData->ParkedOrderActionID);
				csharpData->UserType = cppData->UserType;
				csharpData->Status = cppData->Status;
				csharpData->ErrorID = cppData->ErrorID;
				COPY_UNMANAGED_STRING(csharpData->ErrorMsg, cppData->ErrorMsg);
				COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
				COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
				COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryParkedOrderAction(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryTradingNotice(CThostFtdcTradingNoticeField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcTradingNoticeFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcTradingNoticeFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				csharpData->InvestorRange = cppData->InvestorRange;
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				csharpData->SequenceSeries = cppData->SequenceSeries;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				COPY_UNMANAGED_STRING(csharpData->SendTime, cppData->SendTime);
				csharpData->SequenceNo = cppData->SequenceNo;
				COPY_UNMANAGED_STRING(csharpData->FieldContent, cppData->FieldContent);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryTradingNotice(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcBrokerTradingParamsFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcBrokerTradingParamsFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
				csharpData->MarginPriceType = cppData->MarginPriceType;
				csharpData->Algorithm = cppData->Algorithm;
				csharpData->AvailIncludeCloseProfit = cppData->AvailIncludeCloseProfit;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				csharpData->OptionRoyaltyPriceType = cppData->OptionRoyaltyPriceType;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryBrokerTradingParams(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcBrokerTradingAlgosFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcBrokerTradingAlgosFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
				COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
				csharpData->HandlePositionAlgoID = cppData->HandlePositionAlgoID;
				csharpData->FindMarginRateAlgoID = cppData->FindMarginRateAlgoID;
				csharpData->HandleTradingAccountAlgoID = cppData->HandleTradingAccountAlgoID;
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQryBrokerTradingAlgos(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcQueryCFMMCTradingAccountTokenFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcQueryCFMMCTradingAccountTokenFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQueryCFMMCTradingAccountToken(csharpData, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField* cppData) override
		{
			CThostFtdcRspTransferFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcRspTransferFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->PlateSerial = cppData->PlateSerial;
				csharpData->LastFragment = cppData->LastFragment;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->CustType = cppData->CustType;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankPassWord, cppData->BankPassWord);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->Password, cppData->Password);
				csharpData->InstallID = cppData->InstallID;
				csharpData->FutureSerial = cppData->FutureSerial;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->VerifyCertNoFlag = cppData->VerifyCertNoFlag;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				csharpData->TradeAmount = cppData->TradeAmount;
				csharpData->FutureFetchAmount = cppData->FutureFetchAmount;
				csharpData->FeePayFlag = cppData->FeePayFlag;
				csharpData->CustFee = cppData->CustFee;
				csharpData->BrokerFee = cppData->BrokerFee;
				COPY_UNMANAGED_STRING(csharpData->Message, cppData->Message);
				COPY_UNMANAGED_STRING(csharpData->Digest, cppData->Digest);
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->DeviceID, cppData->DeviceID);
				csharpData->BankSecuAccType = cppData->BankSecuAccType;
				COPY_UNMANAGED_STRING(csharpData->BrokerIDByBank, cppData->BrokerIDByBank);
				COPY_UNMANAGED_STRING(csharpData->BankSecuAcc, cppData->BankSecuAcc);
				csharpData->BankPwdFlag = cppData->BankPwdFlag;
				csharpData->SecuPwdFlag = cppData->SecuPwdFlag;
				COPY_UNMANAGED_STRING(csharpData->OperNo, cppData->OperNo);
				csharpData->RequestID = cppData->RequestID;
				csharpData->TID = cppData->TID;
				csharpData->TransferStatus = cppData->TransferStatus;
				csharpData->ErrorID = cppData->ErrorID;
				COPY_UNMANAGED_STRING(csharpData->ErrorMsg, cppData->ErrorMsg);
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}

			return wrapper_->OnRtnFromBankToFutureByBank(csharpData);
		}
		virtual void OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField* cppData) override
		{
			CThostFtdcRspTransferFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcRspTransferFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->PlateSerial = cppData->PlateSerial;
				csharpData->LastFragment = cppData->LastFragment;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->CustType = cppData->CustType;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankPassWord, cppData->BankPassWord);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->Password, cppData->Password);
				csharpData->InstallID = cppData->InstallID;
				csharpData->FutureSerial = cppData->FutureSerial;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->VerifyCertNoFlag = cppData->VerifyCertNoFlag;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				csharpData->TradeAmount = cppData->TradeAmount;
				csharpData->FutureFetchAmount = cppData->FutureFetchAmount;
				csharpData->FeePayFlag = cppData->FeePayFlag;
				csharpData->CustFee = cppData->CustFee;
				csharpData->BrokerFee = cppData->BrokerFee;
				COPY_UNMANAGED_STRING(csharpData->Message, cppData->Message);
				COPY_UNMANAGED_STRING(csharpData->Digest, cppData->Digest);
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->DeviceID, cppData->DeviceID);
				csharpData->BankSecuAccType = cppData->BankSecuAccType;
				COPY_UNMANAGED_STRING(csharpData->BrokerIDByBank, cppData->BrokerIDByBank);
				COPY_UNMANAGED_STRING(csharpData->BankSecuAcc, cppData->BankSecuAcc);
				csharpData->BankPwdFlag = cppData->BankPwdFlag;
				csharpData->SecuPwdFlag = cppData->SecuPwdFlag;
				COPY_UNMANAGED_STRING(csharpData->OperNo, cppData->OperNo);
				csharpData->RequestID = cppData->RequestID;
				csharpData->TID = cppData->TID;
				csharpData->TransferStatus = cppData->TransferStatus;
				csharpData->ErrorID = cppData->ErrorID;
				COPY_UNMANAGED_STRING(csharpData->ErrorMsg, cppData->ErrorMsg);
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}

			return wrapper_->OnRtnFromFutureToBankByBank(csharpData);
		}
		virtual void OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField* cppData) override
		{
			CThostFtdcRspRepealFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcRspRepealFieldWrapper();
				csharpData->RepealTimeInterval = cppData->RepealTimeInterval;
				csharpData->RepealedTimes = cppData->RepealedTimes;
				csharpData->BankRepealFlag = cppData->BankRepealFlag;
				csharpData->BrokerRepealFlag = cppData->BrokerRepealFlag;
				csharpData->PlateRepealSerial = cppData->PlateRepealSerial;
				COPY_UNMANAGED_STRING(csharpData->BankRepealSerial, cppData->BankRepealSerial);
				csharpData->FutureRepealSerial = cppData->FutureRepealSerial;
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->PlateSerial = cppData->PlateSerial;
				csharpData->LastFragment = cppData->LastFragment;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->CustType = cppData->CustType;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankPassWord, cppData->BankPassWord);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->Password, cppData->Password);
				csharpData->InstallID = cppData->InstallID;
				csharpData->FutureSerial = cppData->FutureSerial;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->VerifyCertNoFlag = cppData->VerifyCertNoFlag;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				csharpData->TradeAmount = cppData->TradeAmount;
				csharpData->FutureFetchAmount = cppData->FutureFetchAmount;
				csharpData->FeePayFlag = cppData->FeePayFlag;
				csharpData->CustFee = cppData->CustFee;
				csharpData->BrokerFee = cppData->BrokerFee;
				COPY_UNMANAGED_STRING(csharpData->Message, cppData->Message);
				COPY_UNMANAGED_STRING(csharpData->Digest, cppData->Digest);
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->DeviceID, cppData->DeviceID);
				csharpData->BankSecuAccType = cppData->BankSecuAccType;
				COPY_UNMANAGED_STRING(csharpData->BrokerIDByBank, cppData->BrokerIDByBank);
				COPY_UNMANAGED_STRING(csharpData->BankSecuAcc, cppData->BankSecuAcc);
				csharpData->BankPwdFlag = cppData->BankPwdFlag;
				csharpData->SecuPwdFlag = cppData->SecuPwdFlag;
				COPY_UNMANAGED_STRING(csharpData->OperNo, cppData->OperNo);
				csharpData->RequestID = cppData->RequestID;
				csharpData->TID = cppData->TID;
				csharpData->TransferStatus = cppData->TransferStatus;
				csharpData->ErrorID = cppData->ErrorID;
				COPY_UNMANAGED_STRING(csharpData->ErrorMsg, cppData->ErrorMsg);
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}

			return wrapper_->OnRtnRepealFromBankToFutureByBank(csharpData);
		}
		virtual void OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField* cppData) override
		{
			CThostFtdcRspRepealFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcRspRepealFieldWrapper();
				csharpData->RepealTimeInterval = cppData->RepealTimeInterval;
				csharpData->RepealedTimes = cppData->RepealedTimes;
				csharpData->BankRepealFlag = cppData->BankRepealFlag;
				csharpData->BrokerRepealFlag = cppData->BrokerRepealFlag;
				csharpData->PlateRepealSerial = cppData->PlateRepealSerial;
				COPY_UNMANAGED_STRING(csharpData->BankRepealSerial, cppData->BankRepealSerial);
				csharpData->FutureRepealSerial = cppData->FutureRepealSerial;
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->PlateSerial = cppData->PlateSerial;
				csharpData->LastFragment = cppData->LastFragment;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->CustType = cppData->CustType;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankPassWord, cppData->BankPassWord);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->Password, cppData->Password);
				csharpData->InstallID = cppData->InstallID;
				csharpData->FutureSerial = cppData->FutureSerial;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->VerifyCertNoFlag = cppData->VerifyCertNoFlag;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				csharpData->TradeAmount = cppData->TradeAmount;
				csharpData->FutureFetchAmount = cppData->FutureFetchAmount;
				csharpData->FeePayFlag = cppData->FeePayFlag;
				csharpData->CustFee = cppData->CustFee;
				csharpData->BrokerFee = cppData->BrokerFee;
				COPY_UNMANAGED_STRING(csharpData->Message, cppData->Message);
				COPY_UNMANAGED_STRING(csharpData->Digest, cppData->Digest);
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->DeviceID, cppData->DeviceID);
				csharpData->BankSecuAccType = cppData->BankSecuAccType;
				COPY_UNMANAGED_STRING(csharpData->BrokerIDByBank, cppData->BrokerIDByBank);
				COPY_UNMANAGED_STRING(csharpData->BankSecuAcc, cppData->BankSecuAcc);
				csharpData->BankPwdFlag = cppData->BankPwdFlag;
				csharpData->SecuPwdFlag = cppData->SecuPwdFlag;
				COPY_UNMANAGED_STRING(csharpData->OperNo, cppData->OperNo);
				csharpData->RequestID = cppData->RequestID;
				csharpData->TID = cppData->TID;
				csharpData->TransferStatus = cppData->TransferStatus;
				csharpData->ErrorID = cppData->ErrorID;
				COPY_UNMANAGED_STRING(csharpData->ErrorMsg, cppData->ErrorMsg);
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}

			return wrapper_->OnRtnRepealFromFutureToBankByBank(csharpData);
		}
		virtual void OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField* cppData) override
		{
			CThostFtdcRspTransferFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcRspTransferFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->PlateSerial = cppData->PlateSerial;
				csharpData->LastFragment = cppData->LastFragment;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->CustType = cppData->CustType;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankPassWord, cppData->BankPassWord);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->Password, cppData->Password);
				csharpData->InstallID = cppData->InstallID;
				csharpData->FutureSerial = cppData->FutureSerial;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->VerifyCertNoFlag = cppData->VerifyCertNoFlag;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				csharpData->TradeAmount = cppData->TradeAmount;
				csharpData->FutureFetchAmount = cppData->FutureFetchAmount;
				csharpData->FeePayFlag = cppData->FeePayFlag;
				csharpData->CustFee = cppData->CustFee;
				csharpData->BrokerFee = cppData->BrokerFee;
				COPY_UNMANAGED_STRING(csharpData->Message, cppData->Message);
				COPY_UNMANAGED_STRING(csharpData->Digest, cppData->Digest);
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->DeviceID, cppData->DeviceID);
				csharpData->BankSecuAccType = cppData->BankSecuAccType;
				COPY_UNMANAGED_STRING(csharpData->BrokerIDByBank, cppData->BrokerIDByBank);
				COPY_UNMANAGED_STRING(csharpData->BankSecuAcc, cppData->BankSecuAcc);
				csharpData->BankPwdFlag = cppData->BankPwdFlag;
				csharpData->SecuPwdFlag = cppData->SecuPwdFlag;
				COPY_UNMANAGED_STRING(csharpData->OperNo, cppData->OperNo);
				csharpData->RequestID = cppData->RequestID;
				csharpData->TID = cppData->TID;
				csharpData->TransferStatus = cppData->TransferStatus;
				csharpData->ErrorID = cppData->ErrorID;
				COPY_UNMANAGED_STRING(csharpData->ErrorMsg, cppData->ErrorMsg);
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}

			return wrapper_->OnRtnFromBankToFutureByFuture(csharpData);
		}
		virtual void OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField* cppData) override
		{
			CThostFtdcRspTransferFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcRspTransferFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->PlateSerial = cppData->PlateSerial;
				csharpData->LastFragment = cppData->LastFragment;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->CustType = cppData->CustType;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankPassWord, cppData->BankPassWord);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->Password, cppData->Password);
				csharpData->InstallID = cppData->InstallID;
				csharpData->FutureSerial = cppData->FutureSerial;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->VerifyCertNoFlag = cppData->VerifyCertNoFlag;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				csharpData->TradeAmount = cppData->TradeAmount;
				csharpData->FutureFetchAmount = cppData->FutureFetchAmount;
				csharpData->FeePayFlag = cppData->FeePayFlag;
				csharpData->CustFee = cppData->CustFee;
				csharpData->BrokerFee = cppData->BrokerFee;
				COPY_UNMANAGED_STRING(csharpData->Message, cppData->Message);
				COPY_UNMANAGED_STRING(csharpData->Digest, cppData->Digest);
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->DeviceID, cppData->DeviceID);
				csharpData->BankSecuAccType = cppData->BankSecuAccType;
				COPY_UNMANAGED_STRING(csharpData->BrokerIDByBank, cppData->BrokerIDByBank);
				COPY_UNMANAGED_STRING(csharpData->BankSecuAcc, cppData->BankSecuAcc);
				csharpData->BankPwdFlag = cppData->BankPwdFlag;
				csharpData->SecuPwdFlag = cppData->SecuPwdFlag;
				COPY_UNMANAGED_STRING(csharpData->OperNo, cppData->OperNo);
				csharpData->RequestID = cppData->RequestID;
				csharpData->TID = cppData->TID;
				csharpData->TransferStatus = cppData->TransferStatus;
				csharpData->ErrorID = cppData->ErrorID;
				COPY_UNMANAGED_STRING(csharpData->ErrorMsg, cppData->ErrorMsg);
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}

			return wrapper_->OnRtnFromFutureToBankByFuture(csharpData);
		}
		virtual void OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField* cppData) override
		{
			CThostFtdcRspRepealFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcRspRepealFieldWrapper();
				csharpData->RepealTimeInterval = cppData->RepealTimeInterval;
				csharpData->RepealedTimes = cppData->RepealedTimes;
				csharpData->BankRepealFlag = cppData->BankRepealFlag;
				csharpData->BrokerRepealFlag = cppData->BrokerRepealFlag;
				csharpData->PlateRepealSerial = cppData->PlateRepealSerial;
				COPY_UNMANAGED_STRING(csharpData->BankRepealSerial, cppData->BankRepealSerial);
				csharpData->FutureRepealSerial = cppData->FutureRepealSerial;
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->PlateSerial = cppData->PlateSerial;
				csharpData->LastFragment = cppData->LastFragment;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->CustType = cppData->CustType;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankPassWord, cppData->BankPassWord);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->Password, cppData->Password);
				csharpData->InstallID = cppData->InstallID;
				csharpData->FutureSerial = cppData->FutureSerial;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->VerifyCertNoFlag = cppData->VerifyCertNoFlag;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				csharpData->TradeAmount = cppData->TradeAmount;
				csharpData->FutureFetchAmount = cppData->FutureFetchAmount;
				csharpData->FeePayFlag = cppData->FeePayFlag;
				csharpData->CustFee = cppData->CustFee;
				csharpData->BrokerFee = cppData->BrokerFee;
				COPY_UNMANAGED_STRING(csharpData->Message, cppData->Message);
				COPY_UNMANAGED_STRING(csharpData->Digest, cppData->Digest);
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->DeviceID, cppData->DeviceID);
				csharpData->BankSecuAccType = cppData->BankSecuAccType;
				COPY_UNMANAGED_STRING(csharpData->BrokerIDByBank, cppData->BrokerIDByBank);
				COPY_UNMANAGED_STRING(csharpData->BankSecuAcc, cppData->BankSecuAcc);
				csharpData->BankPwdFlag = cppData->BankPwdFlag;
				csharpData->SecuPwdFlag = cppData->SecuPwdFlag;
				COPY_UNMANAGED_STRING(csharpData->OperNo, cppData->OperNo);
				csharpData->RequestID = cppData->RequestID;
				csharpData->TID = cppData->TID;
				csharpData->TransferStatus = cppData->TransferStatus;
				csharpData->ErrorID = cppData->ErrorID;
				COPY_UNMANAGED_STRING(csharpData->ErrorMsg, cppData->ErrorMsg);
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}

			return wrapper_->OnRtnRepealFromBankToFutureByFutureManual(csharpData);
		}
		virtual void OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField* cppData) override
		{
			CThostFtdcRspRepealFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcRspRepealFieldWrapper();
				csharpData->RepealTimeInterval = cppData->RepealTimeInterval;
				csharpData->RepealedTimes = cppData->RepealedTimes;
				csharpData->BankRepealFlag = cppData->BankRepealFlag;
				csharpData->BrokerRepealFlag = cppData->BrokerRepealFlag;
				csharpData->PlateRepealSerial = cppData->PlateRepealSerial;
				COPY_UNMANAGED_STRING(csharpData->BankRepealSerial, cppData->BankRepealSerial);
				csharpData->FutureRepealSerial = cppData->FutureRepealSerial;
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->PlateSerial = cppData->PlateSerial;
				csharpData->LastFragment = cppData->LastFragment;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->CustType = cppData->CustType;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankPassWord, cppData->BankPassWord);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->Password, cppData->Password);
				csharpData->InstallID = cppData->InstallID;
				csharpData->FutureSerial = cppData->FutureSerial;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->VerifyCertNoFlag = cppData->VerifyCertNoFlag;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				csharpData->TradeAmount = cppData->TradeAmount;
				csharpData->FutureFetchAmount = cppData->FutureFetchAmount;
				csharpData->FeePayFlag = cppData->FeePayFlag;
				csharpData->CustFee = cppData->CustFee;
				csharpData->BrokerFee = cppData->BrokerFee;
				COPY_UNMANAGED_STRING(csharpData->Message, cppData->Message);
				COPY_UNMANAGED_STRING(csharpData->Digest, cppData->Digest);
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->DeviceID, cppData->DeviceID);
				csharpData->BankSecuAccType = cppData->BankSecuAccType;
				COPY_UNMANAGED_STRING(csharpData->BrokerIDByBank, cppData->BrokerIDByBank);
				COPY_UNMANAGED_STRING(csharpData->BankSecuAcc, cppData->BankSecuAcc);
				csharpData->BankPwdFlag = cppData->BankPwdFlag;
				csharpData->SecuPwdFlag = cppData->SecuPwdFlag;
				COPY_UNMANAGED_STRING(csharpData->OperNo, cppData->OperNo);
				csharpData->RequestID = cppData->RequestID;
				csharpData->TID = cppData->TID;
				csharpData->TransferStatus = cppData->TransferStatus;
				csharpData->ErrorID = cppData->ErrorID;
				COPY_UNMANAGED_STRING(csharpData->ErrorMsg, cppData->ErrorMsg);
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}

			return wrapper_->OnRtnRepealFromFutureToBankByFutureManual(csharpData);
		}
		virtual void OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField* cppData) override
		{
			CThostFtdcNotifyQueryAccountFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcNotifyQueryAccountFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->PlateSerial = cppData->PlateSerial;
				csharpData->LastFragment = cppData->LastFragment;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->CustType = cppData->CustType;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankPassWord, cppData->BankPassWord);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->Password, cppData->Password);
				csharpData->FutureSerial = cppData->FutureSerial;
				csharpData->InstallID = cppData->InstallID;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->VerifyCertNoFlag = cppData->VerifyCertNoFlag;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				COPY_UNMANAGED_STRING(csharpData->Digest, cppData->Digest);
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->DeviceID, cppData->DeviceID);
				csharpData->BankSecuAccType = cppData->BankSecuAccType;
				COPY_UNMANAGED_STRING(csharpData->BrokerIDByBank, cppData->BrokerIDByBank);
				COPY_UNMANAGED_STRING(csharpData->BankSecuAcc, cppData->BankSecuAcc);
				csharpData->BankPwdFlag = cppData->BankPwdFlag;
				csharpData->SecuPwdFlag = cppData->SecuPwdFlag;
				COPY_UNMANAGED_STRING(csharpData->OperNo, cppData->OperNo);
				csharpData->RequestID = cppData->RequestID;
				csharpData->TID = cppData->TID;
				csharpData->BankUseAmount = cppData->BankUseAmount;
				csharpData->BankFetchAmount = cppData->BankFetchAmount;
				csharpData->ErrorID = cppData->ErrorID;
				COPY_UNMANAGED_STRING(csharpData->ErrorMsg, cppData->ErrorMsg);
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}

			return wrapper_->OnRtnQueryBankBalanceByFuture(csharpData);
		}
		virtual void OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField* cppData, CThostFtdcRspInfoField* cppError) override
		{
			CThostFtdcReqTransferFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcReqTransferFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->PlateSerial = cppData->PlateSerial;
				csharpData->LastFragment = cppData->LastFragment;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->CustType = cppData->CustType;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankPassWord, cppData->BankPassWord);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->Password, cppData->Password);
				csharpData->InstallID = cppData->InstallID;
				csharpData->FutureSerial = cppData->FutureSerial;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->VerifyCertNoFlag = cppData->VerifyCertNoFlag;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				csharpData->TradeAmount = cppData->TradeAmount;
				csharpData->FutureFetchAmount = cppData->FutureFetchAmount;
				csharpData->FeePayFlag = cppData->FeePayFlag;
				csharpData->CustFee = cppData->CustFee;
				csharpData->BrokerFee = cppData->BrokerFee;
				COPY_UNMANAGED_STRING(csharpData->Message, cppData->Message);
				COPY_UNMANAGED_STRING(csharpData->Digest, cppData->Digest);
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->DeviceID, cppData->DeviceID);
				csharpData->BankSecuAccType = cppData->BankSecuAccType;
				COPY_UNMANAGED_STRING(csharpData->BrokerIDByBank, cppData->BrokerIDByBank);
				COPY_UNMANAGED_STRING(csharpData->BankSecuAcc, cppData->BankSecuAcc);
				csharpData->BankPwdFlag = cppData->BankPwdFlag;
				csharpData->SecuPwdFlag = cppData->SecuPwdFlag;
				COPY_UNMANAGED_STRING(csharpData->OperNo, cppData->OperNo);
				csharpData->RequestID = cppData->RequestID;
				csharpData->TID = cppData->TID;
				csharpData->TransferStatus = cppData->TransferStatus;
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnErrRtnBankToFutureByFuture(csharpData, csharpError);
		}

		virtual void OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField* cppData, CThostFtdcRspInfoField* cppError) override
		{
			CThostFtdcReqTransferFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcReqTransferFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->PlateSerial = cppData->PlateSerial;
				csharpData->LastFragment = cppData->LastFragment;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->CustType = cppData->CustType;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankPassWord, cppData->BankPassWord);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->Password, cppData->Password);
				csharpData->InstallID = cppData->InstallID;
				csharpData->FutureSerial = cppData->FutureSerial;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->VerifyCertNoFlag = cppData->VerifyCertNoFlag;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				csharpData->TradeAmount = cppData->TradeAmount;
				csharpData->FutureFetchAmount = cppData->FutureFetchAmount;
				csharpData->FeePayFlag = cppData->FeePayFlag;
				csharpData->CustFee = cppData->CustFee;
				csharpData->BrokerFee = cppData->BrokerFee;
				COPY_UNMANAGED_STRING(csharpData->Message, cppData->Message);
				COPY_UNMANAGED_STRING(csharpData->Digest, cppData->Digest);
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->DeviceID, cppData->DeviceID);
				csharpData->BankSecuAccType = cppData->BankSecuAccType;
				COPY_UNMANAGED_STRING(csharpData->BrokerIDByBank, cppData->BrokerIDByBank);
				COPY_UNMANAGED_STRING(csharpData->BankSecuAcc, cppData->BankSecuAcc);
				csharpData->BankPwdFlag = cppData->BankPwdFlag;
				csharpData->SecuPwdFlag = cppData->SecuPwdFlag;
				COPY_UNMANAGED_STRING(csharpData->OperNo, cppData->OperNo);
				csharpData->RequestID = cppData->RequestID;
				csharpData->TID = cppData->TID;
				csharpData->TransferStatus = cppData->TransferStatus;
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnErrRtnFutureToBankByFuture(csharpData, csharpError);
		}

		virtual void OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField* cppData, CThostFtdcRspInfoField* cppError) override
		{
			CThostFtdcReqRepealFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcReqRepealFieldWrapper();
				csharpData->RepealTimeInterval = cppData->RepealTimeInterval;
				csharpData->RepealedTimes = cppData->RepealedTimes;
				csharpData->BankRepealFlag = cppData->BankRepealFlag;
				csharpData->BrokerRepealFlag = cppData->BrokerRepealFlag;
				csharpData->PlateRepealSerial = cppData->PlateRepealSerial;
				COPY_UNMANAGED_STRING(csharpData->BankRepealSerial, cppData->BankRepealSerial);
				csharpData->FutureRepealSerial = cppData->FutureRepealSerial;
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->PlateSerial = cppData->PlateSerial;
				csharpData->LastFragment = cppData->LastFragment;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->CustType = cppData->CustType;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankPassWord, cppData->BankPassWord);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->Password, cppData->Password);
				csharpData->InstallID = cppData->InstallID;
				csharpData->FutureSerial = cppData->FutureSerial;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->VerifyCertNoFlag = cppData->VerifyCertNoFlag;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				csharpData->TradeAmount = cppData->TradeAmount;
				csharpData->FutureFetchAmount = cppData->FutureFetchAmount;
				csharpData->FeePayFlag = cppData->FeePayFlag;
				csharpData->CustFee = cppData->CustFee;
				csharpData->BrokerFee = cppData->BrokerFee;
				COPY_UNMANAGED_STRING(csharpData->Message, cppData->Message);
				COPY_UNMANAGED_STRING(csharpData->Digest, cppData->Digest);
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->DeviceID, cppData->DeviceID);
				csharpData->BankSecuAccType = cppData->BankSecuAccType;
				COPY_UNMANAGED_STRING(csharpData->BrokerIDByBank, cppData->BrokerIDByBank);
				COPY_UNMANAGED_STRING(csharpData->BankSecuAcc, cppData->BankSecuAcc);
				csharpData->BankPwdFlag = cppData->BankPwdFlag;
				csharpData->SecuPwdFlag = cppData->SecuPwdFlag;
				COPY_UNMANAGED_STRING(csharpData->OperNo, cppData->OperNo);
				csharpData->RequestID = cppData->RequestID;
				csharpData->TID = cppData->TID;
				csharpData->TransferStatus = cppData->TransferStatus;
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnErrRtnRepealBankToFutureByFutureManual(csharpData, csharpError);
		}

		virtual void OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField* cppData, CThostFtdcRspInfoField* cppError) override
		{
			CThostFtdcReqRepealFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcReqRepealFieldWrapper();
				csharpData->RepealTimeInterval = cppData->RepealTimeInterval;
				csharpData->RepealedTimes = cppData->RepealedTimes;
				csharpData->BankRepealFlag = cppData->BankRepealFlag;
				csharpData->BrokerRepealFlag = cppData->BrokerRepealFlag;
				csharpData->PlateRepealSerial = cppData->PlateRepealSerial;
				COPY_UNMANAGED_STRING(csharpData->BankRepealSerial, cppData->BankRepealSerial);
				csharpData->FutureRepealSerial = cppData->FutureRepealSerial;
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->PlateSerial = cppData->PlateSerial;
				csharpData->LastFragment = cppData->LastFragment;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->CustType = cppData->CustType;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankPassWord, cppData->BankPassWord);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->Password, cppData->Password);
				csharpData->InstallID = cppData->InstallID;
				csharpData->FutureSerial = cppData->FutureSerial;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->VerifyCertNoFlag = cppData->VerifyCertNoFlag;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				csharpData->TradeAmount = cppData->TradeAmount;
				csharpData->FutureFetchAmount = cppData->FutureFetchAmount;
				csharpData->FeePayFlag = cppData->FeePayFlag;
				csharpData->CustFee = cppData->CustFee;
				csharpData->BrokerFee = cppData->BrokerFee;
				COPY_UNMANAGED_STRING(csharpData->Message, cppData->Message);
				COPY_UNMANAGED_STRING(csharpData->Digest, cppData->Digest);
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->DeviceID, cppData->DeviceID);
				csharpData->BankSecuAccType = cppData->BankSecuAccType;
				COPY_UNMANAGED_STRING(csharpData->BrokerIDByBank, cppData->BrokerIDByBank);
				COPY_UNMANAGED_STRING(csharpData->BankSecuAcc, cppData->BankSecuAcc);
				csharpData->BankPwdFlag = cppData->BankPwdFlag;
				csharpData->SecuPwdFlag = cppData->SecuPwdFlag;
				COPY_UNMANAGED_STRING(csharpData->OperNo, cppData->OperNo);
				csharpData->RequestID = cppData->RequestID;
				csharpData->TID = cppData->TID;
				csharpData->TransferStatus = cppData->TransferStatus;
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnErrRtnRepealFutureToBankByFutureManual(csharpData, csharpError);
		}

		virtual void OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField* cppData, CThostFtdcRspInfoField* cppError) override
		{
			CThostFtdcReqQueryAccountFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcReqQueryAccountFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->PlateSerial = cppData->PlateSerial;
				csharpData->LastFragment = cppData->LastFragment;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->CustType = cppData->CustType;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankPassWord, cppData->BankPassWord);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->Password, cppData->Password);
				csharpData->FutureSerial = cppData->FutureSerial;
				csharpData->InstallID = cppData->InstallID;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->VerifyCertNoFlag = cppData->VerifyCertNoFlag;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				COPY_UNMANAGED_STRING(csharpData->Digest, cppData->Digest);
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->DeviceID, cppData->DeviceID);
				csharpData->BankSecuAccType = cppData->BankSecuAccType;
				COPY_UNMANAGED_STRING(csharpData->BrokerIDByBank, cppData->BrokerIDByBank);
				COPY_UNMANAGED_STRING(csharpData->BankSecuAcc, cppData->BankSecuAcc);
				csharpData->BankPwdFlag = cppData->BankPwdFlag;
				csharpData->SecuPwdFlag = cppData->SecuPwdFlag;
				COPY_UNMANAGED_STRING(csharpData->OperNo, cppData->OperNo);
				csharpData->RequestID = cppData->RequestID;
				csharpData->TID = cppData->TID;
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnErrRtnQueryBankBalanceByFuture(csharpData, csharpError);
		}

		virtual void OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField* cppData) override
		{
			CThostFtdcRspRepealFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcRspRepealFieldWrapper();
				csharpData->RepealTimeInterval = cppData->RepealTimeInterval;
				csharpData->RepealedTimes = cppData->RepealedTimes;
				csharpData->BankRepealFlag = cppData->BankRepealFlag;
				csharpData->BrokerRepealFlag = cppData->BrokerRepealFlag;
				csharpData->PlateRepealSerial = cppData->PlateRepealSerial;
				COPY_UNMANAGED_STRING(csharpData->BankRepealSerial, cppData->BankRepealSerial);
				csharpData->FutureRepealSerial = cppData->FutureRepealSerial;
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->PlateSerial = cppData->PlateSerial;
				csharpData->LastFragment = cppData->LastFragment;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->CustType = cppData->CustType;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankPassWord, cppData->BankPassWord);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->Password, cppData->Password);
				csharpData->InstallID = cppData->InstallID;
				csharpData->FutureSerial = cppData->FutureSerial;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->VerifyCertNoFlag = cppData->VerifyCertNoFlag;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				csharpData->TradeAmount = cppData->TradeAmount;
				csharpData->FutureFetchAmount = cppData->FutureFetchAmount;
				csharpData->FeePayFlag = cppData->FeePayFlag;
				csharpData->CustFee = cppData->CustFee;
				csharpData->BrokerFee = cppData->BrokerFee;
				COPY_UNMANAGED_STRING(csharpData->Message, cppData->Message);
				COPY_UNMANAGED_STRING(csharpData->Digest, cppData->Digest);
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->DeviceID, cppData->DeviceID);
				csharpData->BankSecuAccType = cppData->BankSecuAccType;
				COPY_UNMANAGED_STRING(csharpData->BrokerIDByBank, cppData->BrokerIDByBank);
				COPY_UNMANAGED_STRING(csharpData->BankSecuAcc, cppData->BankSecuAcc);
				csharpData->BankPwdFlag = cppData->BankPwdFlag;
				csharpData->SecuPwdFlag = cppData->SecuPwdFlag;
				COPY_UNMANAGED_STRING(csharpData->OperNo, cppData->OperNo);
				csharpData->RequestID = cppData->RequestID;
				csharpData->TID = cppData->TID;
				csharpData->TransferStatus = cppData->TransferStatus;
				csharpData->ErrorID = cppData->ErrorID;
				COPY_UNMANAGED_STRING(csharpData->ErrorMsg, cppData->ErrorMsg);
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}

			return wrapper_->OnRtnRepealFromBankToFutureByFuture(csharpData);
		}
		virtual void OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField* cppData) override
		{
			CThostFtdcRspRepealFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcRspRepealFieldWrapper();
				csharpData->RepealTimeInterval = cppData->RepealTimeInterval;
				csharpData->RepealedTimes = cppData->RepealedTimes;
				csharpData->BankRepealFlag = cppData->BankRepealFlag;
				csharpData->BrokerRepealFlag = cppData->BrokerRepealFlag;
				csharpData->PlateRepealSerial = cppData->PlateRepealSerial;
				COPY_UNMANAGED_STRING(csharpData->BankRepealSerial, cppData->BankRepealSerial);
				csharpData->FutureRepealSerial = cppData->FutureRepealSerial;
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->PlateSerial = cppData->PlateSerial;
				csharpData->LastFragment = cppData->LastFragment;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->CustType = cppData->CustType;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankPassWord, cppData->BankPassWord);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->Password, cppData->Password);
				csharpData->InstallID = cppData->InstallID;
				csharpData->FutureSerial = cppData->FutureSerial;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->VerifyCertNoFlag = cppData->VerifyCertNoFlag;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				csharpData->TradeAmount = cppData->TradeAmount;
				csharpData->FutureFetchAmount = cppData->FutureFetchAmount;
				csharpData->FeePayFlag = cppData->FeePayFlag;
				csharpData->CustFee = cppData->CustFee;
				csharpData->BrokerFee = cppData->BrokerFee;
				COPY_UNMANAGED_STRING(csharpData->Message, cppData->Message);
				COPY_UNMANAGED_STRING(csharpData->Digest, cppData->Digest);
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->DeviceID, cppData->DeviceID);
				csharpData->BankSecuAccType = cppData->BankSecuAccType;
				COPY_UNMANAGED_STRING(csharpData->BrokerIDByBank, cppData->BrokerIDByBank);
				COPY_UNMANAGED_STRING(csharpData->BankSecuAcc, cppData->BankSecuAcc);
				csharpData->BankPwdFlag = cppData->BankPwdFlag;
				csharpData->SecuPwdFlag = cppData->SecuPwdFlag;
				COPY_UNMANAGED_STRING(csharpData->OperNo, cppData->OperNo);
				csharpData->RequestID = cppData->RequestID;
				csharpData->TID = cppData->TID;
				csharpData->TransferStatus = cppData->TransferStatus;
				csharpData->ErrorID = cppData->ErrorID;
				COPY_UNMANAGED_STRING(csharpData->ErrorMsg, cppData->ErrorMsg);
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}

			return wrapper_->OnRtnRepealFromFutureToBankByFuture(csharpData);
		}
		void OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcReqTransferFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcReqTransferFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->PlateSerial = cppData->PlateSerial;
				csharpData->LastFragment = cppData->LastFragment;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->CustType = cppData->CustType;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankPassWord, cppData->BankPassWord);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->Password, cppData->Password);
				csharpData->InstallID = cppData->InstallID;
				csharpData->FutureSerial = cppData->FutureSerial;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->VerifyCertNoFlag = cppData->VerifyCertNoFlag;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				csharpData->TradeAmount = cppData->TradeAmount;
				csharpData->FutureFetchAmount = cppData->FutureFetchAmount;
				csharpData->FeePayFlag = cppData->FeePayFlag;
				csharpData->CustFee = cppData->CustFee;
				csharpData->BrokerFee = cppData->BrokerFee;
				COPY_UNMANAGED_STRING(csharpData->Message, cppData->Message);
				COPY_UNMANAGED_STRING(csharpData->Digest, cppData->Digest);
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->DeviceID, cppData->DeviceID);
				csharpData->BankSecuAccType = cppData->BankSecuAccType;
				COPY_UNMANAGED_STRING(csharpData->BrokerIDByBank, cppData->BrokerIDByBank);
				COPY_UNMANAGED_STRING(csharpData->BankSecuAcc, cppData->BankSecuAcc);
				csharpData->BankPwdFlag = cppData->BankPwdFlag;
				csharpData->SecuPwdFlag = cppData->SecuPwdFlag;
				COPY_UNMANAGED_STRING(csharpData->OperNo, cppData->OperNo);
				csharpData->RequestID = cppData->RequestID;
				csharpData->TID = cppData->TID;
				csharpData->TransferStatus = cppData->TransferStatus;
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspFromBankToFutureByFuture(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcReqTransferFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcReqTransferFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->PlateSerial = cppData->PlateSerial;
				csharpData->LastFragment = cppData->LastFragment;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->CustType = cppData->CustType;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankPassWord, cppData->BankPassWord);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->Password, cppData->Password);
				csharpData->InstallID = cppData->InstallID;
				csharpData->FutureSerial = cppData->FutureSerial;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->VerifyCertNoFlag = cppData->VerifyCertNoFlag;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				csharpData->TradeAmount = cppData->TradeAmount;
				csharpData->FutureFetchAmount = cppData->FutureFetchAmount;
				csharpData->FeePayFlag = cppData->FeePayFlag;
				csharpData->CustFee = cppData->CustFee;
				csharpData->BrokerFee = cppData->BrokerFee;
				COPY_UNMANAGED_STRING(csharpData->Message, cppData->Message);
				COPY_UNMANAGED_STRING(csharpData->Digest, cppData->Digest);
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->DeviceID, cppData->DeviceID);
				csharpData->BankSecuAccType = cppData->BankSecuAccType;
				COPY_UNMANAGED_STRING(csharpData->BrokerIDByBank, cppData->BrokerIDByBank);
				COPY_UNMANAGED_STRING(csharpData->BankSecuAcc, cppData->BankSecuAcc);
				csharpData->BankPwdFlag = cppData->BankPwdFlag;
				csharpData->SecuPwdFlag = cppData->SecuPwdFlag;
				COPY_UNMANAGED_STRING(csharpData->OperNo, cppData->OperNo);
				csharpData->RequestID = cppData->RequestID;
				csharpData->TID = cppData->TID;
				csharpData->TransferStatus = cppData->TransferStatus;
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspFromFutureToBankByFuture(csharpData, csharpError, nRequestID, bIsLast);
		}

		void OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField* cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcReqQueryAccountFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcReqQueryAccountFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->PlateSerial = cppData->PlateSerial;
				csharpData->LastFragment = cppData->LastFragment;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->CustType = cppData->CustType;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankPassWord, cppData->BankPassWord);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->Password, cppData->Password);
				csharpData->FutureSerial = cppData->FutureSerial;
				csharpData->InstallID = cppData->InstallID;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->VerifyCertNoFlag = cppData->VerifyCertNoFlag;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				COPY_UNMANAGED_STRING(csharpData->Digest, cppData->Digest);
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->DeviceID, cppData->DeviceID);
				csharpData->BankSecuAccType = cppData->BankSecuAccType;
				COPY_UNMANAGED_STRING(csharpData->BrokerIDByBank, cppData->BrokerIDByBank);
				COPY_UNMANAGED_STRING(csharpData->BankSecuAcc, cppData->BankSecuAcc);
				csharpData->BankPwdFlag = cppData->BankPwdFlag;
				csharpData->SecuPwdFlag = cppData->SecuPwdFlag;
				COPY_UNMANAGED_STRING(csharpData->OperNo, cppData->OperNo);
				csharpData->RequestID = cppData->RequestID;
				csharpData->TID = cppData->TID;
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}


			COPY_ERROR_CODE;
			return wrapper_->OnRspQueryBankAccountMoneyByFuture(csharpData, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRtnOpenAccountByBank(CThostFtdcOpenAccountField* cppData) override
		{
			CThostFtdcOpenAccountFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcOpenAccountFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->PlateSerial = cppData->PlateSerial;
				csharpData->LastFragment = cppData->LastFragment;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->Gender = cppData->Gender;
				COPY_UNMANAGED_STRING(csharpData->CountryCode, cppData->CountryCode);
				csharpData->CustType = cppData->CustType;
				COPY_UNMANAGED_STRING(csharpData->Address, cppData->Address);
				COPY_UNMANAGED_STRING(csharpData->ZipCode, cppData->ZipCode);
				COPY_UNMANAGED_STRING(csharpData->Telephone, cppData->Telephone);
				COPY_UNMANAGED_STRING(csharpData->MobilePhone, cppData->MobilePhone);
				COPY_UNMANAGED_STRING(csharpData->Fax, cppData->Fax);
				COPY_UNMANAGED_STRING(csharpData->EMail, cppData->EMail);
				csharpData->MoneyAccountStatus = cppData->MoneyAccountStatus;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankPassWord, cppData->BankPassWord);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->Password, cppData->Password);
				csharpData->InstallID = cppData->InstallID;
				csharpData->VerifyCertNoFlag = cppData->VerifyCertNoFlag;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				csharpData->CashExchangeCode = cppData->CashExchangeCode;
				COPY_UNMANAGED_STRING(csharpData->Digest, cppData->Digest);
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->DeviceID, cppData->DeviceID);
				csharpData->BankSecuAccType = cppData->BankSecuAccType;
				COPY_UNMANAGED_STRING(csharpData->BrokerIDByBank, cppData->BrokerIDByBank);
				COPY_UNMANAGED_STRING(csharpData->BankSecuAcc, cppData->BankSecuAcc);
				csharpData->BankPwdFlag = cppData->BankPwdFlag;
				csharpData->SecuPwdFlag = cppData->SecuPwdFlag;
				COPY_UNMANAGED_STRING(csharpData->OperNo, cppData->OperNo);
				csharpData->TID = cppData->TID;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->ErrorID = cppData->ErrorID;
				COPY_UNMANAGED_STRING(csharpData->ErrorMsg, cppData->ErrorMsg);
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}

			return wrapper_->OnRtnOpenAccountByBank(csharpData);
		}
		virtual void OnRtnCancelAccountByBank(CThostFtdcCancelAccountField* cppData) override
		{
			CThostFtdcCancelAccountFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcCancelAccountFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->PlateSerial = cppData->PlateSerial;
				csharpData->LastFragment = cppData->LastFragment;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->Gender = cppData->Gender;
				COPY_UNMANAGED_STRING(csharpData->CountryCode, cppData->CountryCode);
				csharpData->CustType = cppData->CustType;
				COPY_UNMANAGED_STRING(csharpData->Address, cppData->Address);
				COPY_UNMANAGED_STRING(csharpData->ZipCode, cppData->ZipCode);
				COPY_UNMANAGED_STRING(csharpData->Telephone, cppData->Telephone);
				COPY_UNMANAGED_STRING(csharpData->MobilePhone, cppData->MobilePhone);
				COPY_UNMANAGED_STRING(csharpData->Fax, cppData->Fax);
				COPY_UNMANAGED_STRING(csharpData->EMail, cppData->EMail);
				csharpData->MoneyAccountStatus = cppData->MoneyAccountStatus;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankPassWord, cppData->BankPassWord);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->Password, cppData->Password);
				csharpData->InstallID = cppData->InstallID;
				csharpData->VerifyCertNoFlag = cppData->VerifyCertNoFlag;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				csharpData->CashExchangeCode = cppData->CashExchangeCode;
				COPY_UNMANAGED_STRING(csharpData->Digest, cppData->Digest);
				csharpData->BankAccType = cppData->BankAccType;
				COPY_UNMANAGED_STRING(csharpData->DeviceID, cppData->DeviceID);
				csharpData->BankSecuAccType = cppData->BankSecuAccType;
				COPY_UNMANAGED_STRING(csharpData->BrokerIDByBank, cppData->BrokerIDByBank);
				COPY_UNMANAGED_STRING(csharpData->BankSecuAcc, cppData->BankSecuAcc);
				csharpData->BankPwdFlag = cppData->BankPwdFlag;
				csharpData->SecuPwdFlag = cppData->SecuPwdFlag;
				COPY_UNMANAGED_STRING(csharpData->OperNo, cppData->OperNo);
				csharpData->TID = cppData->TID;
				COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
				csharpData->ErrorID = cppData->ErrorID;
				COPY_UNMANAGED_STRING(csharpData->ErrorMsg, cppData->ErrorMsg);
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}

			return wrapper_->OnRtnCancelAccountByBank(csharpData);
		}
		virtual void OnRtnChangeAccountByBank(CThostFtdcChangeAccountField* cppData) override
		{
			CThostFtdcChangeAccountFieldWrapper^ csharpData = nullptr;
			if (cppData) {
				csharpData = gcnew CThostFtdcChangeAccountFieldWrapper();
				COPY_UNMANAGED_STRING(csharpData->TradeCode, cppData->TradeCode);
				COPY_UNMANAGED_STRING(csharpData->BankID, cppData->BankID);
				COPY_UNMANAGED_STRING(csharpData->BankBranchID, cppData->BankBranchID);
				COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
				COPY_UNMANAGED_STRING(csharpData->BrokerBranchID, cppData->BrokerBranchID);
				COPY_UNMANAGED_STRING(csharpData->TradeDate, cppData->TradeDate);
				COPY_UNMANAGED_STRING(csharpData->TradeTime, cppData->TradeTime);
				COPY_UNMANAGED_STRING(csharpData->BankSerial, cppData->BankSerial);
				COPY_UNMANAGED_STRING(csharpData->TradingDay, cppData->TradingDay);
				csharpData->PlateSerial = cppData->PlateSerial;
				csharpData->LastFragment = cppData->LastFragment;
				csharpData->SessionID = cppData->SessionID;
				COPY_UNMANAGED_STRING(csharpData->CustomerName, cppData->CustomerName);
				csharpData->IdCardType = cppData->IdCardType;
				COPY_UNMANAGED_STRING(csharpData->IdentifiedCardNo, cppData->IdentifiedCardNo);
				csharpData->Gender = cppData->Gender;
				COPY_UNMANAGED_STRING(csharpData->CountryCode, cppData->CountryCode);
				csharpData->CustType = cppData->CustType;
				COPY_UNMANAGED_STRING(csharpData->Address, cppData->Address);
				COPY_UNMANAGED_STRING(csharpData->ZipCode, cppData->ZipCode);
				COPY_UNMANAGED_STRING(csharpData->Telephone, cppData->Telephone);
				COPY_UNMANAGED_STRING(csharpData->MobilePhone, cppData->MobilePhone);
				COPY_UNMANAGED_STRING(csharpData->Fax, cppData->Fax);
				COPY_UNMANAGED_STRING(csharpData->EMail, cppData->EMail);
				csharpData->MoneyAccountStatus = cppData->MoneyAccountStatus;
				COPY_UNMANAGED_STRING(csharpData->BankAccount, cppData->BankAccount);
				COPY_UNMANAGED_STRING(csharpData->BankPassWord, cppData->BankPassWord);
				COPY_UNMANAGED_STRING(csharpData->NewBankAccount, cppData->NewBankAccount);
				COPY_UNMANAGED_STRING(csharpData->NewBankPassWord, cppData->NewBankPassWord);
				COPY_UNMANAGED_STRING(csharpData->AccountID, cppData->AccountID);
				COPY_UNMANAGED_STRING(csharpData->Password, cppData->Password);
				csharpData->BankAccType = cppData->BankAccType;
				csharpData->InstallID = cppData->InstallID;
				csharpData->VerifyCertNoFlag = cppData->VerifyCertNoFlag;
				COPY_UNMANAGED_STRING(csharpData->CurrencyID, cppData->CurrencyID);
				COPY_UNMANAGED_STRING(csharpData->BrokerIDByBank, cppData->BrokerIDByBank);
				csharpData->BankPwdFlag = cppData->BankPwdFlag;
				csharpData->SecuPwdFlag = cppData->SecuPwdFlag;
				csharpData->TID = cppData->TID;
				COPY_UNMANAGED_STRING(csharpData->Digest, cppData->Digest);
				csharpData->ErrorID = cppData->ErrorID;
				COPY_UNMANAGED_STRING(csharpData->ErrorMsg, cppData->ErrorMsg);
				COPY_UNMANAGED_STRING(csharpData->LongCustomerName, cppData->LongCustomerName);
			}

			return wrapper_->OnRtnChangeAccountByBank(csharpData);
		}



	private:
		msclr::auto_gcroot<TradeSpiWrapper^> wrapper_;
	};

}
