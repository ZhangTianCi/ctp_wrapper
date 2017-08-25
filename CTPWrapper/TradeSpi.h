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

		virtual void OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *cppAction, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcParkedOrderActionFieldWrapper^ csharpAction = gcnew CThostFtdcParkedOrderActionFieldWrapper();
			COPY_UNMANAGED_STRING(csharpAction->BrokerID, cppAction->BrokerID);
			COPY_UNMANAGED_STRING(csharpAction->InvestorID, cppAction->InvestorID);
			csharpAction->OrderActionRef = cppAction->OrderActionRef;
			COPY_UNMANAGED_STRING(csharpAction->OrderRef, cppAction->OrderRef);
			csharpAction->RequestID = cppAction->RequestID;
			csharpAction->FrontID = cppAction->FrontID;
			csharpAction->SessionID = cppAction->SessionID;
			COPY_UNMANAGED_STRING(csharpAction->ExchangeID, cppAction->ExchangeID);
			COPY_UNMANAGED_STRING(csharpAction->OrderSysID, cppAction->OrderSysID);
			csharpAction->ActionFlag = cppAction->ActionFlag;
			csharpAction->LimitPrice = cppAction->LimitPrice;
			csharpAction->VolumeChange = cppAction->VolumeChange;
			COPY_UNMANAGED_STRING(csharpAction->UserID, cppAction->UserID);
			COPY_UNMANAGED_STRING(csharpAction->InstrumentID, cppAction->InstrumentID);
			COPY_UNMANAGED_STRING(csharpAction->ParkedOrderActionID, cppAction->ParkedOrderActionID);
			csharpAction->UserType = cppAction->UserType;
			csharpAction->Status = cppAction->Status;
			csharpAction->ErrorID = cppAction->ErrorID;
			COPY_UNMANAGED_STRING(csharpAction->ErrorMsg, cppAction->ErrorMsg);
			COPY_UNMANAGED_STRING(csharpAction->InvestUnitID, cppAction->InvestUnitID);
			COPY_UNMANAGED_STRING(csharpAction->IPAddress, cppAction->IPAddress);
			COPY_UNMANAGED_STRING(csharpAction->MacAddress, cppAction->MacAddress);

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspParkedOrderAction(csharpAction, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *cppAction, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcInputOrderActionFieldWrapper^ csharpAction = gcnew CThostFtdcInputOrderActionFieldWrapper();
			COPY_UNMANAGED_STRING(csharpAction->BrokerID, cppAction->BrokerID);
			COPY_UNMANAGED_STRING(csharpAction->InvestorID, cppAction->InvestorID);
			csharpAction->OrderActionRef = cppAction->OrderActionRef;
			COPY_UNMANAGED_STRING(csharpAction->OrderRef, cppAction->OrderRef);
			csharpAction->RequestID = cppAction->RequestID;
			csharpAction->FrontID = cppAction->FrontID;
			csharpAction->SessionID = cppAction->SessionID;
			COPY_UNMANAGED_STRING(csharpAction->ExchangeID, cppAction->ExchangeID);
			COPY_UNMANAGED_STRING(csharpAction->OrderSysID, cppAction->OrderSysID);
			csharpAction->ActionFlag = cppAction->ActionFlag;
			csharpAction->LimitPrice = cppAction->LimitPrice;
			csharpAction->VolumeChange = cppAction->VolumeChange;
			COPY_UNMANAGED_STRING(csharpAction->UserID, cppAction->UserID);
			COPY_UNMANAGED_STRING(csharpAction->InstrumentID, cppAction->InstrumentID);
			COPY_UNMANAGED_STRING(csharpAction->InvestUnitID, cppAction->InvestUnitID);
			COPY_UNMANAGED_STRING(csharpAction->IPAddress, cppAction->IPAddress);
			COPY_UNMANAGED_STRING(csharpAction->MacAddress, cppAction->MacAddress);

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspOrderAction(csharpAction, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *cppData, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcQueryMaxOrderVolumeFieldWrapper^ csharpData = gcnew CThostFtdcQueryMaxOrderVolumeFieldWrapper();
			COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
			COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
			COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
			csharpData->Direction = cppData->Direction;
			csharpData->OffsetFlag = cppData->OffsetFlag;
			csharpData->HedgeFlag = cppData->HedgeFlag;
			csharpData->MaxVolume = cppData->MaxVolume;

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspQueryMaxOrderVolume(csharpData, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *cppData, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcSettlementInfoConfirmFieldWrapper^ csharpData = gcnew CThostFtdcSettlementInfoConfirmFieldWrapper();
			COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
			COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
			COPY_UNMANAGED_STRING(csharpData->ConfirmDate, cppData->ConfirmDate);
			COPY_UNMANAGED_STRING(csharpData->ConfirmTime, cppData->ConfirmTime);

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspSettlementInfoConfirm(csharpData, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *cppData, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcRemoveParkedOrderFieldWrapper^ csharpData = gcnew CThostFtdcRemoveParkedOrderFieldWrapper();
			COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
			COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
			COPY_UNMANAGED_STRING(csharpData->ParkedOrderID, cppData->ParkedOrderID);

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspRemoveParkedOrder(csharpData, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *cppData, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcRemoveParkedOrderActionFieldWrapper^ csharpData = gcnew CThostFtdcRemoveParkedOrderActionFieldWrapper();
			COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
			COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
			COPY_UNMANAGED_STRING(csharpData->ParkedOrderActionID, cppData->ParkedOrderActionID);

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspRemoveParkedOrderAction(csharpData, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspExecOrderInsert(CThostFtdcInputExecOrderField *cppData, CThostFtdcRspInfoField* cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcInputExecOrderFieldWrapper^ csharpData = gcnew CThostFtdcInputExecOrderFieldWrapper();
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

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspExecOrderInsert(csharpData, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *cppData, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcInputExecOrderActionFieldWrapper^ csharpData = gcnew CThostFtdcInputExecOrderActionFieldWrapper();
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

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspExecOrderAction(csharpData, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspForQuoteInsert(CThostFtdcInputForQuoteField *cppData, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcInputForQuoteFieldWrapper^ csharpData = gcnew CThostFtdcInputForQuoteFieldWrapper();
			COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
			COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
			COPY_UNMANAGED_STRING(csharpData->InstrumentID, cppData->InstrumentID);
			COPY_UNMANAGED_STRING(csharpData->ForQuoteRef, cppData->ForQuoteRef);
			COPY_UNMANAGED_STRING(csharpData->UserID, cppData->UserID);
			COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
			COPY_UNMANAGED_STRING(csharpData->InvestUnitID, cppData->InvestUnitID);
			COPY_UNMANAGED_STRING(csharpData->IPAddress, cppData->IPAddress);
			COPY_UNMANAGED_STRING(csharpData->MacAddress, cppData->MacAddress);

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspForQuoteInsert(csharpData, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspQuoteInsert(CThostFtdcInputQuoteField *cppData, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcInputQuoteFieldWrapper^ csharpData = gcnew CThostFtdcInputQuoteFieldWrapper();
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

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspQuoteInsert(csharpData, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspQuoteAction(CThostFtdcInputQuoteActionField *cppData, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcInputQuoteActionFieldWrapper^ csharpData = gcnew CThostFtdcInputQuoteActionFieldWrapper();
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

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspQuoteAction(csharpData, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField *cppData, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast)
		{
			CThostFtdcInputBatchOrderActionFieldWrapper^ csharpData = gcnew CThostFtdcInputBatchOrderActionFieldWrapper();
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

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspBatchOrderAction(csharpData, csharpError, nRequestID, bIsLast);
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
