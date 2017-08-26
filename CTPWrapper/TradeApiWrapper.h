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

		virtual int ReqParkedOrderAction(CThostFtdcParkedOrderActionFieldWrapper^ csharpData, int nRequestID)
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

		virtual int ReqOrderAction(CThostFtdcInputOrderActionFieldWrapper^ csharpData, int nRequestID)
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



	private:
		TradeSpi* spi_;
		CThostFtdcTraderApi* api_;
	};

}