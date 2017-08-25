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

		virtual void OnRspCombActionInsert(CThostFtdcInputCombActionField *cppData, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcInputCombActionFieldWrapper^ csharpData = gcnew CThostFtdcInputCombActionFieldWrapper();
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

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspCombActionInsert(csharpData, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspQryOrder(CThostFtdcOrderField *cppData, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcOrderFieldWrapper^ csharpData = gcnew CThostFtdcOrderFieldWrapper();
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

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspQryOrder(csharpData, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspQryTrade(CThostFtdcTradeField *cppData, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcTradeFieldWrapper^ csharpData = gcnew CThostFtdcTradeFieldWrapper();
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

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspQryTrade(csharpData, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *cppData, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcInvestorPositionFieldWrapper^ csharpData = gcnew CThostFtdcInvestorPositionFieldWrapper();
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

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspQryInvestorPosition(csharpData, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *cppData, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcTradingAccountFieldWrapper^ csharpData = gcnew CThostFtdcTradingAccountFieldWrapper();
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

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspQryTradingAccount(csharpData, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspQryInvestor(CThostFtdcInvestorField *cppData, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcInvestorFieldWrapper^ csharpData = gcnew CThostFtdcInvestorFieldWrapper();
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

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspQryInvestor(csharpData, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspQryTradingCode(CThostFtdcTradingCodeField *cppData, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcTradingCodeFieldWrapper^ csharpData = gcnew CThostFtdcTradingCodeFieldWrapper();
			COPY_UNMANAGED_STRING(csharpData->InvestorID, cppData->InvestorID);
			COPY_UNMANAGED_STRING(csharpData->BrokerID, cppData->BrokerID);
			COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
			COPY_UNMANAGED_STRING(csharpData->ClientID, cppData->ClientID);
			csharpData->IsActive = cppData->IsActive;
			csharpData->ClientIDType = cppData->ClientIDType;

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspQryTradingCode(csharpData, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *cppData, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcInstrumentMarginRateFieldWrapper^ csharpData = gcnew CThostFtdcInstrumentMarginRateFieldWrapper();
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

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspQryInstrumentMarginRate(csharpData, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *cppData, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcInstrumentCommissionRateFieldWrapper^ csharpData = gcnew CThostFtdcInstrumentCommissionRateFieldWrapper();
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


			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspQryInstrumentCommissionRate(csharpData, csharpError, nRequestID, bIsLast);
		}

		virtual void OnRspQryExchange(CThostFtdcExchangeField *cppData, CThostFtdcRspInfoField *cppError, int nRequestID, bool bIsLast) override
		{
			CThostFtdcExchangeFieldWrapper^ csharpData = gcnew CThostFtdcExchangeFieldWrapper();
			COPY_UNMANAGED_STRING(csharpData->ExchangeID, cppData->ExchangeID);
			COPY_UNMANAGED_STRING(csharpData->ExchangeName, cppData->ExchangeName);
			csharpData->ExchangeProperty = cppData->ExchangeProperty;

			CThostFtdcRspInfoFieldWrapper^ csharpError = gcnew CThostFtdcRspInfoFieldWrapper();
			csharpError->ErrorID = cppError->ErrorID;
			COPY_UNMANAGED_STRING(csharpError->ErrorMsg, cppError->ErrorMsg);

			wrapper_->OnRspQryExchange(csharpData, csharpError, nRequestID, bIsLast);
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
