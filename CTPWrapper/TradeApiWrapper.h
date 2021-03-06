#pragma once

using namespace System;

#include "ThostFtdcTraderApi.h"
#include "MyUnmanagedString.h"
#include "CtpStructWrapper.h"
#include "TradeSpi.h"
#include <vector>

namespace CTPWrapper {

	public ref class TradeApiWrapper
	{
	public:
		static String^ GetApiVersion()
		{
			return MyUnmanagedString::ToManaged(CThostFtdcTraderApi::GetApiVersion());
		}

	public:
		TradeApiWrapper(String^ flowPath)
		{
			MyUnmanagedString cppFlowPath(flowPath);

			spi_ = NULL;
			api_ = CThostFtdcTraderApi::CreateFtdcTraderApi(
				cppFlowPath.c_str()
			);
		}

		~TradeApiWrapper()
		{
		}

		void Release()
		{
			api_->Release();
		}

		void Init()
		{
			api_->Init();
		}

		void Join()
		{
			api_->Join();
		}

		String^ GetTradingDay()
		{
			return MyUnmanagedString::ToManaged(api_->GetTradingDay());
		}

		void RegisterFront(String^ frontAddr)
		{
			MyUnmanagedString addr(frontAddr);
			api_->RegisterFront(addr.c_str());
		}

		void RegisterNameServer(String^ nameServerAddr)
		{
			MyUnmanagedString addr(nameServerAddr);
			api_->RegisterNameServer(addr.c_str());
		}

		void RegisterFensUserInfo(CThostFtdcFensUserInfoFieldWrapper^ pFensUserInfo)
		{
			CThostFtdcFensUserInfoField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, pFensUserInfo->BrokerID);
			COPY_MANAGED_STRING(req.UserID, pFensUserInfo->UserID);
			req.LoginMode = pFensUserInfo->LoginMode;

			api_->RegisterFensUserInfo(&req);
		}

		void RegisterSpi(TradeSpiWrapper^ spiCSharp)
		{
			spi_ = new TradeSpi(spiCSharp);
			api_->RegisterSpi(spi_);
		}

		void SubscribePrivateTopic(int nResumeType)
		{
			api_->SubscribePrivateTopic((THOST_TE_RESUME_TYPE)nResumeType);
		}

		void SubscribePublicTopic(int nResumeType)
		{
			api_->SubscribePrivateTopic((THOST_TE_RESUME_TYPE)nResumeType);
		}

		int ReqAuthenticate(CThostFtdcReqAuthenticateFieldWrapper^ csharpAuth, int nRequestID)
		{
			CThostFtdcReqAuthenticateField cppAuth;
			memset(&cppAuth, 0, sizeof(cppAuth));

			COPY_MANAGED_STRING(cppAuth.BrokerID, csharpAuth->BrokerID);
			COPY_MANAGED_STRING(cppAuth.UserID, csharpAuth->UserID);
			COPY_MANAGED_STRING(cppAuth.UserProductInfo, csharpAuth->UserProductInfo);
			COPY_MANAGED_STRING(cppAuth.AuthCode, csharpAuth->AuthCode);

			return api_->ReqAuthenticate(&cppAuth, nRequestID);
		}

		int ReqUserLogin(CThostFtdcReqUserLoginFieldWrapper^ pReqUserLoginField, int nRequestID)
		{
			CThostFtdcReqUserLoginField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.TradingDay, pReqUserLoginField->TradingDay);
			COPY_MANAGED_STRING(req.BrokerID, pReqUserLoginField->BrokerID);
			COPY_MANAGED_STRING(req.UserID, pReqUserLoginField->UserID);
			COPY_MANAGED_STRING(req.Password, pReqUserLoginField->Password);
			COPY_MANAGED_STRING(req.UserProductInfo, pReqUserLoginField->UserProductInfo);
			COPY_MANAGED_STRING(req.InterfaceProductInfo, pReqUserLoginField->InterfaceProductInfo);
			COPY_MANAGED_STRING(req.ProtocolInfo, pReqUserLoginField->ProtocolInfo);
			COPY_MANAGED_STRING(req.MacAddress, pReqUserLoginField->MacAddress);
			COPY_MANAGED_STRING(req.OneTimePassword, pReqUserLoginField->OneTimePassword);
			COPY_MANAGED_STRING(req.ClientIPAddress, pReqUserLoginField->ClientIPAddress);
			COPY_MANAGED_STRING(req.LoginRemark, pReqUserLoginField->LoginRemark);

			return api_->ReqUserLogin(&req, nRequestID);
		}

		int ReqUserLogout(CThostFtdcUserLogoutFieldWrapper^ pUserLogout, int nRequestID)
		{
			CThostFtdcUserLogoutField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, pUserLogout->BrokerID);
			COPY_MANAGED_STRING(req.UserID, pUserLogout->UserID);

			return api_->ReqUserLogout(&req, nRequestID);
		}

		int ReqUserPasswordUpdate(CThostFtdcUserPasswordUpdateFieldWrapper^ pUserPasswordUpdate, int nRequestID)
		{
			CThostFtdcUserPasswordUpdateField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, pUserPasswordUpdate->BrokerID);
			COPY_MANAGED_STRING(req.UserID, pUserPasswordUpdate->UserID);
			COPY_MANAGED_STRING(req.OldPassword, pUserPasswordUpdate->OldPassword);
			COPY_MANAGED_STRING(req.NewPassword, pUserPasswordUpdate->NewPassword);

			return api_->ReqUserPasswordUpdate(&req, nRequestID);
		}

		int ReqTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateFieldWrapper^ pTradingAccountPasswordUpdate, int nRequestID)
		{
			CThostFtdcTradingAccountPasswordUpdateField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, pTradingAccountPasswordUpdate->BrokerID);
			COPY_MANAGED_STRING(req.AccountID, pTradingAccountPasswordUpdate->AccountID);
			COPY_MANAGED_STRING(req.OldPassword, pTradingAccountPasswordUpdate->OldPassword);
			COPY_MANAGED_STRING(req.NewPassword, pTradingAccountPasswordUpdate->NewPassword);
			COPY_MANAGED_STRING(req.CurrencyID, pTradingAccountPasswordUpdate->CurrencyID);

			return api_->ReqTradingAccountPasswordUpdate(&req, nRequestID);
		}

		int ReqOrderInsert(CThostFtdcInputOrderFieldWrapper^ pInputOrder, int nRequestID)
		{
			CThostFtdcInputOrderField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, pInputOrder->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, pInputOrder->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, pInputOrder->InstrumentID);
			COPY_MANAGED_STRING(req.OrderRef, pInputOrder->OrderRef);
			COPY_MANAGED_STRING(req.UserID, pInputOrder->UserID);
			req.OrderPriceType = pInputOrder->OrderPriceType;
			req.Direction = pInputOrder->Direction;
			COPY_MANAGED_STRING(req.CombOffsetFlag, pInputOrder->CombOffsetFlag);
			COPY_MANAGED_STRING(req.CombHedgeFlag, pInputOrder->CombHedgeFlag);
			req.LimitPrice = pInputOrder->LimitPrice;
			req.VolumeTotalOriginal = pInputOrder->VolumeTotalOriginal;
			req.TimeCondition = pInputOrder->TimeCondition;
			COPY_MANAGED_STRING(req.GTDDate, pInputOrder->GTDDate);
			req.VolumeCondition = pInputOrder->VolumeCondition;
			req.MinVolume = pInputOrder->MinVolume;
			req.ContingentCondition = pInputOrder->ContingentCondition;
			req.StopPrice = pInputOrder->StopPrice;
			req.ForceCloseReason = pInputOrder->ForceCloseReason;
			req.IsAutoSuspend = pInputOrder->IsAutoSuspend;
			COPY_MANAGED_STRING(req.BusinessUnit, pInputOrder->BusinessUnit);
			req.RequestID = pInputOrder->RequestID;
			req.UserForceClose = pInputOrder->UserForceClose;
			req.IsSwapOrder = pInputOrder->IsSwapOrder;
			COPY_MANAGED_STRING(req.ExchangeID, pInputOrder->ExchangeID);
			COPY_MANAGED_STRING(req.InvestUnitID, pInputOrder->InvestUnitID);
			COPY_MANAGED_STRING(req.AccountID, pInputOrder->AccountID);
			COPY_MANAGED_STRING(req.CurrencyID, pInputOrder->CurrencyID);
			COPY_MANAGED_STRING(req.ClientID, pInputOrder->ClientID);
			COPY_MANAGED_STRING(req.IPAddress, pInputOrder->IPAddress);
			COPY_MANAGED_STRING(req.MacAddress, pInputOrder->MacAddress);

			return api_->ReqOrderInsert(&req, nRequestID);
		}

		int ReqParkedOrderInsert(CThostFtdcParkedOrderFieldWrapper^ pParkedOrder, int nRequestID)
		{
			CThostFtdcParkedOrderField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, pParkedOrder->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, pParkedOrder->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, pParkedOrder->InstrumentID);
			COPY_MANAGED_STRING(req.OrderRef, pParkedOrder->OrderRef);
			COPY_MANAGED_STRING(req.UserID, pParkedOrder->UserID);
			req.OrderPriceType = pParkedOrder->OrderPriceType;
			req.Direction = pParkedOrder->Direction;
			COPY_MANAGED_STRING(req.CombOffsetFlag, pParkedOrder->CombOffsetFlag);
			COPY_MANAGED_STRING(req.CombHedgeFlag, pParkedOrder->CombHedgeFlag);
			req.LimitPrice = pParkedOrder->LimitPrice;
			req.VolumeTotalOriginal = pParkedOrder->VolumeTotalOriginal;
			req.TimeCondition = pParkedOrder->TimeCondition;
			COPY_MANAGED_STRING(req.GTDDate, pParkedOrder->GTDDate);
			req.VolumeCondition = pParkedOrder->VolumeCondition;
			req.MinVolume = pParkedOrder->MinVolume;
			req.ContingentCondition = pParkedOrder->ContingentCondition;
			req.StopPrice = pParkedOrder->StopPrice;
			req.ForceCloseReason = pParkedOrder->ForceCloseReason;
			req.IsAutoSuspend = pParkedOrder->IsAutoSuspend;
			COPY_MANAGED_STRING(req.BusinessUnit, pParkedOrder->BusinessUnit);
			req.RequestID = pParkedOrder->RequestID;
			req.UserForceClose = pParkedOrder->UserForceClose;
			COPY_MANAGED_STRING(req.ExchangeID, pParkedOrder->ExchangeID);
			COPY_MANAGED_STRING(req.ParkedOrderID, pParkedOrder->ParkedOrderID);
			req.UserType = pParkedOrder->UserType;
			req.Status = pParkedOrder->Status;
			req.ErrorID = pParkedOrder->ErrorID;
			COPY_MANAGED_STRING(req.ErrorMsg, pParkedOrder->ErrorMsg);
			req.IsSwapOrder = pParkedOrder->IsSwapOrder;
			COPY_MANAGED_STRING(req.AccountID, pParkedOrder->AccountID);
			COPY_MANAGED_STRING(req.CurrencyID, pParkedOrder->CurrencyID);
			COPY_MANAGED_STRING(req.ClientID, pParkedOrder->ClientID);
			COPY_MANAGED_STRING(req.InvestUnitID, pParkedOrder->InvestUnitID);
			COPY_MANAGED_STRING(req.IPAddress, pParkedOrder->IPAddress);
			COPY_MANAGED_STRING(req.MacAddress, pParkedOrder->MacAddress);

			return api_->ReqParkedOrderInsert(&req, nRequestID);
		}

		int ReqParkedOrderAction(CThostFtdcParkedOrderActionFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcParkedOrderActionField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			req.OrderActionRef = csharpData->OrderActionRef;
			COPY_MANAGED_STRING(req.OrderRef, csharpData->OrderRef);
			req.RequestID = csharpData->RequestID;
			req.FrontID = csharpData->FrontID;
			req.SessionID = csharpData->SessionID;
			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);
			COPY_MANAGED_STRING(req.OrderSysID, csharpData->OrderSysID);
			req.ActionFlag = csharpData->ActionFlag;
			req.LimitPrice = csharpData->LimitPrice;
			req.VolumeChange = csharpData->VolumeChange;
			COPY_MANAGED_STRING(req.UserID, csharpData->UserID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);
			COPY_MANAGED_STRING(req.ParkedOrderActionID, csharpData->ParkedOrderActionID);
			req.UserType = csharpData->UserType;
			req.Status = csharpData->Status;
			req.ErrorID = csharpData->ErrorID;
			COPY_MANAGED_STRING(req.ErrorMsg, csharpData->ErrorMsg);
			COPY_MANAGED_STRING(req.InvestUnitID, csharpData->InvestUnitID);
			COPY_MANAGED_STRING(req.IPAddress, csharpData->IPAddress);
			COPY_MANAGED_STRING(req.MacAddress, csharpData->MacAddress);

			return api_->ReqParkedOrderAction(&req, nRequestID);
		}

		int ReqOrderAction(CThostFtdcInputOrderActionFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcInputOrderActionField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			req.OrderActionRef = csharpData->OrderActionRef;
			COPY_MANAGED_STRING(req.OrderRef, csharpData->OrderRef);
			req.RequestID = csharpData->RequestID;
			req.FrontID = csharpData->FrontID;
			req.SessionID = csharpData->SessionID;
			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);
			COPY_MANAGED_STRING(req.OrderSysID, csharpData->OrderSysID);
			req.ActionFlag = csharpData->ActionFlag;
			req.LimitPrice = csharpData->LimitPrice;
			req.VolumeChange = csharpData->VolumeChange;
			COPY_MANAGED_STRING(req.UserID, csharpData->UserID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);
			COPY_MANAGED_STRING(req.InvestUnitID, csharpData->InvestUnitID);
			COPY_MANAGED_STRING(req.IPAddress, csharpData->IPAddress);
			COPY_MANAGED_STRING(req.MacAddress, csharpData->MacAddress);

			return api_->ReqOrderAction(&req, nRequestID);
		}

		int ReqQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQueryMaxOrderVolumeField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);
			req.Direction = csharpData->Direction;
			req.OffsetFlag = csharpData->OffsetFlag;
			req.HedgeFlag = csharpData->HedgeFlag;
			req.MaxVolume = csharpData->MaxVolume;

			return api_->ReqQueryMaxOrderVolume(&req, nRequestID);
		}

		int ReqSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcSettlementInfoConfirmField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.ConfirmDate, csharpData->ConfirmDate);
			COPY_MANAGED_STRING(req.ConfirmTime, csharpData->ConfirmTime);

			return api_->ReqSettlementInfoConfirm(&req, nRequestID);
		}

		int ReqRemoveParkedOrder(CThostFtdcRemoveParkedOrderFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcRemoveParkedOrderField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.ParkedOrderID, csharpData->ParkedOrderID);

			return api_->ReqRemoveParkedOrder(&req, nRequestID);
		}

		int ReqRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcRemoveParkedOrderActionField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.ParkedOrderActionID, csharpData->ParkedOrderActionID);

			return api_->ReqRemoveParkedOrderAction(&req, nRequestID);
		}

		int ReqExecOrderInsert(CThostFtdcInputExecOrderFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcInputExecOrderField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);
			COPY_MANAGED_STRING(req.ExecOrderRef, csharpData->ExecOrderRef);
			COPY_MANAGED_STRING(req.UserID, csharpData->UserID);
			req.Volume = csharpData->Volume;
			req.RequestID = csharpData->RequestID;
			COPY_MANAGED_STRING(req.BusinessUnit, csharpData->BusinessUnit);
			req.OffsetFlag = csharpData->OffsetFlag;
			req.HedgeFlag = csharpData->HedgeFlag;
			req.ActionType = csharpData->ActionType;
			req.PosiDirection = csharpData->PosiDirection;
			req.ReservePositionFlag = csharpData->ReservePositionFlag;
			req.CloseFlag = csharpData->CloseFlag;
			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);
			COPY_MANAGED_STRING(req.InvestUnitID, csharpData->InvestUnitID);
			COPY_MANAGED_STRING(req.AccountID, csharpData->AccountID);
			COPY_MANAGED_STRING(req.CurrencyID, csharpData->CurrencyID);
			COPY_MANAGED_STRING(req.ClientID, csharpData->ClientID);
			COPY_MANAGED_STRING(req.IPAddress, csharpData->IPAddress);
			COPY_MANAGED_STRING(req.MacAddress, csharpData->MacAddress);

			return api_->ReqExecOrderInsert(&req, nRequestID);
		}

		int ReqExecOrderAction(CThostFtdcInputExecOrderActionFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcInputExecOrderActionField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			req.ExecOrderActionRef = csharpData->ExecOrderActionRef;
			COPY_MANAGED_STRING(req.ExecOrderRef, csharpData->ExecOrderRef);
			req.RequestID = csharpData->RequestID;
			req.FrontID = csharpData->FrontID;
			req.SessionID = csharpData->SessionID;
			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);
			COPY_MANAGED_STRING(req.ExecOrderSysID, csharpData->ExecOrderSysID);
			req.ActionFlag = csharpData->ActionFlag;
			COPY_MANAGED_STRING(req.UserID, csharpData->UserID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);
			COPY_MANAGED_STRING(req.InvestUnitID, csharpData->InvestUnitID);
			COPY_MANAGED_STRING(req.IPAddress, csharpData->IPAddress);
			COPY_MANAGED_STRING(req.MacAddress, csharpData->MacAddress);

			return api_->ReqExecOrderAction(&req, nRequestID);
		}

		int ReqForQuoteInsert(CThostFtdcInputForQuoteFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcInputForQuoteField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);
			COPY_MANAGED_STRING(req.ForQuoteRef, csharpData->ForQuoteRef);
			COPY_MANAGED_STRING(req.UserID, csharpData->UserID);
			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);
			COPY_MANAGED_STRING(req.InvestUnitID, csharpData->InvestUnitID);
			COPY_MANAGED_STRING(req.IPAddress, csharpData->IPAddress);
			COPY_MANAGED_STRING(req.MacAddress, csharpData->MacAddress);

			return api_->ReqForQuoteInsert(&req, nRequestID);
		}

		int ReqQuoteInsert(CThostFtdcInputQuoteFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcInputQuoteField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);
			COPY_MANAGED_STRING(req.QuoteRef, csharpData->QuoteRef);
			COPY_MANAGED_STRING(req.UserID, csharpData->UserID);
			req.AskPrice = csharpData->AskPrice;
			req.BidPrice = csharpData->BidPrice;
			req.AskVolume = csharpData->AskVolume;
			req.BidVolume = csharpData->BidVolume;
			req.RequestID = csharpData->RequestID;
			COPY_MANAGED_STRING(req.BusinessUnit, csharpData->BusinessUnit);
			req.AskOffsetFlag = csharpData->AskOffsetFlag;
			req.BidOffsetFlag = csharpData->BidOffsetFlag;
			req.AskHedgeFlag = csharpData->AskHedgeFlag;
			req.BidHedgeFlag = csharpData->BidHedgeFlag;
			COPY_MANAGED_STRING(req.AskOrderRef, csharpData->AskOrderRef);
			COPY_MANAGED_STRING(req.BidOrderRef, csharpData->BidOrderRef);
			COPY_MANAGED_STRING(req.ForQuoteSysID, csharpData->ForQuoteSysID);
			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);
			COPY_MANAGED_STRING(req.InvestUnitID, csharpData->InvestUnitID);
			COPY_MANAGED_STRING(req.ClientID, csharpData->ClientID);
			COPY_MANAGED_STRING(req.IPAddress, csharpData->IPAddress);
			COPY_MANAGED_STRING(req.MacAddress, csharpData->MacAddress);

			return api_->ReqQuoteInsert(&req, nRequestID);
		}

		int ReqQuoteAction(CThostFtdcInputQuoteActionFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcInputQuoteActionField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			req.QuoteActionRef = csharpData->QuoteActionRef;
			COPY_MANAGED_STRING(req.QuoteRef, csharpData->QuoteRef);
			req.RequestID = csharpData->RequestID;
			req.FrontID = csharpData->FrontID;
			req.SessionID = csharpData->SessionID;
			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);
			COPY_MANAGED_STRING(req.QuoteSysID, csharpData->QuoteSysID);
			req.ActionFlag = csharpData->ActionFlag;
			COPY_MANAGED_STRING(req.UserID, csharpData->UserID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);
			COPY_MANAGED_STRING(req.InvestUnitID, csharpData->InvestUnitID);
			COPY_MANAGED_STRING(req.ClientID, csharpData->ClientID);
			COPY_MANAGED_STRING(req.IPAddress, csharpData->IPAddress);
			COPY_MANAGED_STRING(req.MacAddress, csharpData->MacAddress);


			return api_->ReqQuoteAction(&req, nRequestID);
		}

		int ReqBatchOrderAction(CThostFtdcInputBatchOrderActionFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcInputBatchOrderActionField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			req.OrderActionRef = csharpData->OrderActionRef;
			req.RequestID = csharpData->RequestID;
			req.FrontID = csharpData->FrontID;
			req.SessionID = csharpData->SessionID;
			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);
			COPY_MANAGED_STRING(req.UserID, csharpData->UserID);
			COPY_MANAGED_STRING(req.InvestUnitID, csharpData->InvestUnitID);
			COPY_MANAGED_STRING(req.IPAddress, csharpData->IPAddress);
			COPY_MANAGED_STRING(req.MacAddress, csharpData->MacAddress);

			return api_->ReqBatchOrderAction(&req, nRequestID);
		}

		int ReqCombActionInsert(CThostFtdcInputCombActionFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcInputCombActionField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);
			COPY_MANAGED_STRING(req.CombActionRef, csharpData->CombActionRef);
			COPY_MANAGED_STRING(req.UserID, csharpData->UserID);
			req.Direction = csharpData->Direction;
			req.Volume = csharpData->Volume;
			req.CombDirection = csharpData->CombDirection;
			req.HedgeFlag = csharpData->HedgeFlag;
			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);
			COPY_MANAGED_STRING(req.IPAddress, csharpData->IPAddress);
			COPY_MANAGED_STRING(req.MacAddress, csharpData->MacAddress);

			return api_->ReqCombActionInsert(&req, nRequestID);
		}

		int ReqQryOrder(CThostFtdcQryOrderFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryOrderField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);
			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);
			COPY_MANAGED_STRING(req.OrderSysID, csharpData->OrderSysID);
			COPY_MANAGED_STRING(req.InsertTimeStart, csharpData->InsertTimeStart);
			COPY_MANAGED_STRING(req.InsertTimeEnd, csharpData->InsertTimeEnd);


			return api_->ReqQryOrder(&req, nRequestID);
		}

		int ReqQryTrade(CThostFtdcQryTradeFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryTradeField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);
			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);
			COPY_MANAGED_STRING(req.TradeID, csharpData->TradeID);
			COPY_MANAGED_STRING(req.TradeTimeStart, csharpData->TradeTimeStart);
			COPY_MANAGED_STRING(req.TradeTimeEnd, csharpData->TradeTimeEnd);


			return api_->ReqQryTrade(&req, nRequestID);
		}

		int ReqQryInvestorPosition(CThostFtdcQryInvestorPositionFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryInvestorPositionField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);


			return api_->ReqQryInvestorPosition(&req, nRequestID);
		}

		int ReqQryTradingAccount(CThostFtdcQryTradingAccountFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryTradingAccountField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.CurrencyID, csharpData->CurrencyID);


			return api_->ReqQryTradingAccount(&req, nRequestID);
		}

		int ReqQryInvestor(CThostFtdcQryInvestorFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryInvestorField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);


			return api_->ReqQryInvestor(&req, nRequestID);
		}

		int ReqQryTradingCode(CThostFtdcQryTradingCodeFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryTradingCodeField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);
			COPY_MANAGED_STRING(req.ClientID, csharpData->ClientID);
			req.ClientIDType = csharpData->ClientIDType;


			return api_->ReqQryTradingCode(&req, nRequestID);
		}

		int ReqQryInstrumentMarginRate(CThostFtdcQryInstrumentMarginRateFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryInstrumentMarginRateField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);
			req.HedgeFlag = csharpData->HedgeFlag;


			return api_->ReqQryInstrumentMarginRate(&req, nRequestID);
		}

		int ReqQryInstrumentCommissionRate(CThostFtdcQryInstrumentCommissionRateFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryInstrumentCommissionRateField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);


			return api_->ReqQryInstrumentCommissionRate(&req, nRequestID);
		}

		int ReqQryExchange(CThostFtdcQryExchangeFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryExchangeField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);


			return api_->ReqQryExchange(&req, nRequestID);
		}

		int ReqQryProduct(CThostFtdcQryProductFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryProductField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.ProductID, csharpData->ProductID);
			req.ProductClass = csharpData->ProductClass;


			return api_->ReqQryProduct(&req, nRequestID);
		}

		int ReqQryInstrument(CThostFtdcQryInstrumentFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryInstrumentField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);
			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);
			COPY_MANAGED_STRING(req.ExchangeInstID, csharpData->ExchangeInstID);
			COPY_MANAGED_STRING(req.ProductID, csharpData->ProductID);


			return api_->ReqQryInstrument(&req, nRequestID);
		}

		int ReqQryDepthMarketData(CThostFtdcQryDepthMarketDataFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryDepthMarketDataField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);


			return api_->ReqQryDepthMarketData(&req, nRequestID);
		}

		int ReqQrySettlementInfo(CThostFtdcQrySettlementInfoFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQrySettlementInfoField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.TradingDay, csharpData->TradingDay);


			return api_->ReqQrySettlementInfo(&req, nRequestID);
		}

		int ReqQryTransferBank(CThostFtdcQryTransferBankFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryTransferBankField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BankID, csharpData->BankID);
			COPY_MANAGED_STRING(req.BankBrchID, csharpData->BankBrchID);


			return api_->ReqQryTransferBank(&req, nRequestID);
		}

		int ReqQryInvestorPositionDetail(CThostFtdcQryInvestorPositionDetailFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryInvestorPositionDetailField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);


			return api_->ReqQryInvestorPositionDetail(&req, nRequestID);
		}

		int ReqQryNotice(CThostFtdcQryNoticeFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryNoticeField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);


			return api_->ReqQryNotice(&req, nRequestID);
		}

		int ReqQrySettlementInfoConfirm(CThostFtdcQrySettlementInfoConfirmFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQrySettlementInfoConfirmField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);


			return api_->ReqQrySettlementInfoConfirm(&req, nRequestID);
		}

		int ReqQryInvestorPositionCombineDetail(CThostFtdcQryInvestorPositionCombineDetailFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryInvestorPositionCombineDetailField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.CombInstrumentID, csharpData->CombInstrumentID);


			return api_->ReqQryInvestorPositionCombineDetail(&req, nRequestID);
		}

		int ReqQryCFMMCTradingAccountKey(CThostFtdcQryCFMMCTradingAccountKeyFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryCFMMCTradingAccountKeyField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);


			return api_->ReqQryCFMMCTradingAccountKey(&req, nRequestID);
		}

		int ReqQryEWarrantOffset(CThostFtdcQryEWarrantOffsetFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryEWarrantOffsetField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);


			return api_->ReqQryEWarrantOffset(&req, nRequestID);
		}

		int ReqQryInvestorProductGroupMargin(CThostFtdcQryInvestorProductGroupMarginFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryInvestorProductGroupMarginField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.ProductGroupID, csharpData->ProductGroupID);
			req.HedgeFlag = csharpData->HedgeFlag;


			return api_->ReqQryInvestorProductGroupMargin(&req, nRequestID);
		}

		int ReqQryExchangeMarginRate(CThostFtdcQryExchangeMarginRateFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryExchangeMarginRateField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);
			req.HedgeFlag = csharpData->HedgeFlag;


			return api_->ReqQryExchangeMarginRate(&req, nRequestID);
		}

		int ReqQryExchangeMarginRateAdjust(CThostFtdcQryExchangeMarginRateAdjustFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryExchangeMarginRateAdjustField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);
			req.HedgeFlag = csharpData->HedgeFlag;


			return api_->ReqQryExchangeMarginRateAdjust(&req, nRequestID);
		}

		int ReqQryExchangeRate(CThostFtdcQryExchangeRateFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryExchangeRateField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.FromCurrencyID, csharpData->FromCurrencyID);
			COPY_MANAGED_STRING(req.ToCurrencyID, csharpData->ToCurrencyID);


			return api_->ReqQryExchangeRate(&req, nRequestID);
		}

		int ReqQrySecAgentACIDMap(CThostFtdcQrySecAgentACIDMapFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQrySecAgentACIDMapField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.UserID, csharpData->UserID);
			COPY_MANAGED_STRING(req.AccountID, csharpData->AccountID);
			COPY_MANAGED_STRING(req.CurrencyID, csharpData->CurrencyID);


			return api_->ReqQrySecAgentACIDMap(&req, nRequestID);
		}

		int ReqQryProductExchRate(CThostFtdcQryProductExchRateFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryProductExchRateField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.ProductID, csharpData->ProductID);


			return api_->ReqQryProductExchRate(&req, nRequestID);
		}

		int ReqQryProductGroup(CThostFtdcQryProductGroupFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryProductGroupField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.ProductID, csharpData->ProductID);
			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);


			return api_->ReqQryProductGroup(&req, nRequestID);
		}

		int ReqQryMMInstrumentCommissionRate(CThostFtdcQryMMInstrumentCommissionRateFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryMMInstrumentCommissionRateField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);


			return api_->ReqQryMMInstrumentCommissionRate(&req, nRequestID);
		}

		int ReqQryMMOptionInstrCommRate(CThostFtdcQryMMOptionInstrCommRateFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryMMOptionInstrCommRateField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);


			return api_->ReqQryMMOptionInstrCommRate(&req, nRequestID);
		}

		int ReqQryInstrumentOrderCommRate(CThostFtdcQryInstrumentOrderCommRateFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryInstrumentOrderCommRateField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);


			return api_->ReqQryInstrumentOrderCommRate(&req, nRequestID);
		}

		int ReqQryOptionInstrTradeCost(CThostFtdcQryOptionInstrTradeCostFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryOptionInstrTradeCostField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);
			req.HedgeFlag = csharpData->HedgeFlag;
			req.InputPrice = csharpData->InputPrice;
			req.UnderlyingPrice = csharpData->UnderlyingPrice;


			return api_->ReqQryOptionInstrTradeCost(&req, nRequestID);
		}

		int ReqQryOptionInstrCommRate(CThostFtdcQryOptionInstrCommRateFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryOptionInstrCommRateField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);


			return api_->ReqQryOptionInstrCommRate(&req, nRequestID);
		}

		int ReqQryExecOrder(CThostFtdcQryExecOrderFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryExecOrderField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);
			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);
			COPY_MANAGED_STRING(req.ExecOrderSysID, csharpData->ExecOrderSysID);
			COPY_MANAGED_STRING(req.InsertTimeStart, csharpData->InsertTimeStart);
			COPY_MANAGED_STRING(req.InsertTimeEnd, csharpData->InsertTimeEnd);


			return api_->ReqQryExecOrder(&req, nRequestID);
		}

		int ReqQryForQuote(CThostFtdcQryForQuoteFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryForQuoteField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);
			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);
			COPY_MANAGED_STRING(req.InsertTimeStart, csharpData->InsertTimeStart);
			COPY_MANAGED_STRING(req.InsertTimeEnd, csharpData->InsertTimeEnd);


			return api_->ReqQryForQuote(&req, nRequestID);
		}

		int ReqQryQuote(CThostFtdcQryQuoteFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryQuoteField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);
			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);
			COPY_MANAGED_STRING(req.QuoteSysID, csharpData->QuoteSysID);
			COPY_MANAGED_STRING(req.InsertTimeStart, csharpData->InsertTimeStart);
			COPY_MANAGED_STRING(req.InsertTimeEnd, csharpData->InsertTimeEnd);


			return api_->ReqQryQuote(&req, nRequestID);
		}

		int ReqQryCombInstrumentGuard(CThostFtdcQryCombInstrumentGuardFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryCombInstrumentGuardField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);


			return api_->ReqQryCombInstrumentGuard(&req, nRequestID);
		}

		int ReqQryCombAction(CThostFtdcQryCombActionFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryCombActionField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);
			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);


			return api_->ReqQryCombAction(&req, nRequestID);
		}

		int ReqQryTransferSerial(CThostFtdcQryTransferSerialFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryTransferSerialField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.AccountID, csharpData->AccountID);
			COPY_MANAGED_STRING(req.BankID, csharpData->BankID);
			COPY_MANAGED_STRING(req.CurrencyID, csharpData->CurrencyID);


			return api_->ReqQryTransferSerial(&req, nRequestID);
		}

		int ReqQryAccountregister(CThostFtdcQryAccountregisterFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryAccountregisterField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.AccountID, csharpData->AccountID);
			COPY_MANAGED_STRING(req.BankID, csharpData->BankID);
			COPY_MANAGED_STRING(req.BankBranchID, csharpData->BankBranchID);
			COPY_MANAGED_STRING(req.CurrencyID, csharpData->CurrencyID);


			return api_->ReqQryAccountregister(&req, nRequestID);
		}

		int ReqQryContractBank(CThostFtdcQryContractBankFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryContractBankField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.BankID, csharpData->BankID);
			COPY_MANAGED_STRING(req.BankBrchID, csharpData->BankBrchID);


			return api_->ReqQryContractBank(&req, nRequestID);
		}

		int ReqQryParkedOrder(CThostFtdcQryParkedOrderFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryParkedOrderField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);
			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);


			return api_->ReqQryParkedOrder(&req, nRequestID);
		}

		int ReqQryParkedOrderAction(CThostFtdcQryParkedOrderActionFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryParkedOrderActionField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);
			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);


			return api_->ReqQryParkedOrderAction(&req, nRequestID);
		}

		int ReqQryTradingNotice(CThostFtdcQryTradingNoticeFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryTradingNoticeField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);


			return api_->ReqQryTradingNotice(&req, nRequestID);
		}

		int ReqQryBrokerTradingParams(CThostFtdcQryBrokerTradingParamsFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryBrokerTradingParamsField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);
			COPY_MANAGED_STRING(req.CurrencyID, csharpData->CurrencyID);


			return api_->ReqQryBrokerTradingParams(&req, nRequestID);
		}

		int ReqQryBrokerTradingAlgos(CThostFtdcQryBrokerTradingAlgosFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQryBrokerTradingAlgosField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.ExchangeID, csharpData->ExchangeID);
			COPY_MANAGED_STRING(req.InstrumentID, csharpData->InstrumentID);


			return api_->ReqQryBrokerTradingAlgos(&req, nRequestID);
		}

		int ReqQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcQueryCFMMCTradingAccountTokenField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.InvestorID, csharpData->InvestorID);


			return api_->ReqQueryCFMMCTradingAccountToken(&req, nRequestID);
		}

		int ReqFromBankToFutureByFuture(CThostFtdcReqTransferFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcReqTransferField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.TradeCode, csharpData->TradeCode);
			COPY_MANAGED_STRING(req.BankID, csharpData->BankID);
			COPY_MANAGED_STRING(req.BankBranchID, csharpData->BankBranchID);
			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.BrokerBranchID, csharpData->BrokerBranchID);
			COPY_MANAGED_STRING(req.TradeDate, csharpData->TradeDate);
			COPY_MANAGED_STRING(req.TradeTime, csharpData->TradeTime);
			COPY_MANAGED_STRING(req.BankSerial, csharpData->BankSerial);
			COPY_MANAGED_STRING(req.TradingDay, csharpData->TradingDay);
			req.PlateSerial = csharpData->PlateSerial;
			req.LastFragment = csharpData->LastFragment;
			req.SessionID = csharpData->SessionID;
			COPY_MANAGED_STRING(req.CustomerName, csharpData->CustomerName);
			req.IdCardType = csharpData->IdCardType;
			COPY_MANAGED_STRING(req.IdentifiedCardNo, csharpData->IdentifiedCardNo);
			req.CustType = csharpData->CustType;
			COPY_MANAGED_STRING(req.BankAccount, csharpData->BankAccount);
			COPY_MANAGED_STRING(req.BankPassWord, csharpData->BankPassWord);
			COPY_MANAGED_STRING(req.AccountID, csharpData->AccountID);
			COPY_MANAGED_STRING(req.Password, csharpData->Password);
			req.InstallID = csharpData->InstallID;
			req.FutureSerial = csharpData->FutureSerial;
			COPY_MANAGED_STRING(req.UserID, csharpData->UserID);
			req.VerifyCertNoFlag = csharpData->VerifyCertNoFlag;
			COPY_MANAGED_STRING(req.CurrencyID, csharpData->CurrencyID);
			req.TradeAmount = csharpData->TradeAmount;
			req.FutureFetchAmount = csharpData->FutureFetchAmount;
			req.FeePayFlag = csharpData->FeePayFlag;
			req.CustFee = csharpData->CustFee;
			req.BrokerFee = csharpData->BrokerFee;
			COPY_MANAGED_STRING(req.Message, csharpData->Message);
			COPY_MANAGED_STRING(req.Digest, csharpData->Digest);
			req.BankAccType = csharpData->BankAccType;
			COPY_MANAGED_STRING(req.DeviceID, csharpData->DeviceID);
			req.BankSecuAccType = csharpData->BankSecuAccType;
			COPY_MANAGED_STRING(req.BrokerIDByBank, csharpData->BrokerIDByBank);
			COPY_MANAGED_STRING(req.BankSecuAcc, csharpData->BankSecuAcc);
			req.BankPwdFlag = csharpData->BankPwdFlag;
			req.SecuPwdFlag = csharpData->SecuPwdFlag;
			COPY_MANAGED_STRING(req.OperNo, csharpData->OperNo);
			req.RequestID = csharpData->RequestID;
			req.TID = csharpData->TID;
			req.TransferStatus = csharpData->TransferStatus;
			COPY_MANAGED_STRING(req.LongCustomerName, csharpData->LongCustomerName);


			return api_->ReqFromBankToFutureByFuture(&req, nRequestID);
		}

		int ReqFromFutureToBankByFuture(CThostFtdcReqTransferFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcReqTransferField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.TradeCode, csharpData->TradeCode);
			COPY_MANAGED_STRING(req.BankID, csharpData->BankID);
			COPY_MANAGED_STRING(req.BankBranchID, csharpData->BankBranchID);
			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.BrokerBranchID, csharpData->BrokerBranchID);
			COPY_MANAGED_STRING(req.TradeDate, csharpData->TradeDate);
			COPY_MANAGED_STRING(req.TradeTime, csharpData->TradeTime);
			COPY_MANAGED_STRING(req.BankSerial, csharpData->BankSerial);
			COPY_MANAGED_STRING(req.TradingDay, csharpData->TradingDay);
			req.PlateSerial = csharpData->PlateSerial;
			req.LastFragment = csharpData->LastFragment;
			req.SessionID = csharpData->SessionID;
			COPY_MANAGED_STRING(req.CustomerName, csharpData->CustomerName);
			req.IdCardType = csharpData->IdCardType;
			COPY_MANAGED_STRING(req.IdentifiedCardNo, csharpData->IdentifiedCardNo);
			req.CustType = csharpData->CustType;
			COPY_MANAGED_STRING(req.BankAccount, csharpData->BankAccount);
			COPY_MANAGED_STRING(req.BankPassWord, csharpData->BankPassWord);
			COPY_MANAGED_STRING(req.AccountID, csharpData->AccountID);
			COPY_MANAGED_STRING(req.Password, csharpData->Password);
			req.InstallID = csharpData->InstallID;
			req.FutureSerial = csharpData->FutureSerial;
			COPY_MANAGED_STRING(req.UserID, csharpData->UserID);
			req.VerifyCertNoFlag = csharpData->VerifyCertNoFlag;
			COPY_MANAGED_STRING(req.CurrencyID, csharpData->CurrencyID);
			req.TradeAmount = csharpData->TradeAmount;
			req.FutureFetchAmount = csharpData->FutureFetchAmount;
			req.FeePayFlag = csharpData->FeePayFlag;
			req.CustFee = csharpData->CustFee;
			req.BrokerFee = csharpData->BrokerFee;
			COPY_MANAGED_STRING(req.Message, csharpData->Message);
			COPY_MANAGED_STRING(req.Digest, csharpData->Digest);
			req.BankAccType = csharpData->BankAccType;
			COPY_MANAGED_STRING(req.DeviceID, csharpData->DeviceID);
			req.BankSecuAccType = csharpData->BankSecuAccType;
			COPY_MANAGED_STRING(req.BrokerIDByBank, csharpData->BrokerIDByBank);
			COPY_MANAGED_STRING(req.BankSecuAcc, csharpData->BankSecuAcc);
			req.BankPwdFlag = csharpData->BankPwdFlag;
			req.SecuPwdFlag = csharpData->SecuPwdFlag;
			COPY_MANAGED_STRING(req.OperNo, csharpData->OperNo);
			req.RequestID = csharpData->RequestID;
			req.TID = csharpData->TID;
			req.TransferStatus = csharpData->TransferStatus;
			COPY_MANAGED_STRING(req.LongCustomerName, csharpData->LongCustomerName);


			return api_->ReqFromFutureToBankByFuture(&req, nRequestID);
		}

		int ReqQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountFieldWrapper^ csharpData, int nRequestID)
		{
			CThostFtdcReqQueryAccountField req;
			memset(&req, 0, sizeof(req));

			COPY_MANAGED_STRING(req.TradeCode, csharpData->TradeCode);
			COPY_MANAGED_STRING(req.BankID, csharpData->BankID);
			COPY_MANAGED_STRING(req.BankBranchID, csharpData->BankBranchID);
			COPY_MANAGED_STRING(req.BrokerID, csharpData->BrokerID);
			COPY_MANAGED_STRING(req.BrokerBranchID, csharpData->BrokerBranchID);
			COPY_MANAGED_STRING(req.TradeDate, csharpData->TradeDate);
			COPY_MANAGED_STRING(req.TradeTime, csharpData->TradeTime);
			COPY_MANAGED_STRING(req.BankSerial, csharpData->BankSerial);
			COPY_MANAGED_STRING(req.TradingDay, csharpData->TradingDay);
			req.PlateSerial = csharpData->PlateSerial;
			req.LastFragment = csharpData->LastFragment;
			req.SessionID = csharpData->SessionID;
			COPY_MANAGED_STRING(req.CustomerName, csharpData->CustomerName);
			req.IdCardType = csharpData->IdCardType;
			COPY_MANAGED_STRING(req.IdentifiedCardNo, csharpData->IdentifiedCardNo);
			req.CustType = csharpData->CustType;
			COPY_MANAGED_STRING(req.BankAccount, csharpData->BankAccount);
			COPY_MANAGED_STRING(req.BankPassWord, csharpData->BankPassWord);
			COPY_MANAGED_STRING(req.AccountID, csharpData->AccountID);
			COPY_MANAGED_STRING(req.Password, csharpData->Password);
			req.FutureSerial = csharpData->FutureSerial;
			req.InstallID = csharpData->InstallID;
			COPY_MANAGED_STRING(req.UserID, csharpData->UserID);
			req.VerifyCertNoFlag = csharpData->VerifyCertNoFlag;
			COPY_MANAGED_STRING(req.CurrencyID, csharpData->CurrencyID);
			COPY_MANAGED_STRING(req.Digest, csharpData->Digest);
			req.BankAccType = csharpData->BankAccType;
			COPY_MANAGED_STRING(req.DeviceID, csharpData->DeviceID);
			req.BankSecuAccType = csharpData->BankSecuAccType;
			COPY_MANAGED_STRING(req.BrokerIDByBank, csharpData->BrokerIDByBank);
			COPY_MANAGED_STRING(req.BankSecuAcc, csharpData->BankSecuAcc);
			req.BankPwdFlag = csharpData->BankPwdFlag;
			req.SecuPwdFlag = csharpData->SecuPwdFlag;
			COPY_MANAGED_STRING(req.OperNo, csharpData->OperNo);
			req.RequestID = csharpData->RequestID;
			req.TID = csharpData->TID;
			COPY_MANAGED_STRING(req.LongCustomerName, csharpData->LongCustomerName);


			return api_->ReqQueryBankAccountMoneyByFuture(&req, nRequestID);
		}



	private:
		TradeSpi* spi_;
		CThostFtdcTraderApi* api_;
	};

}