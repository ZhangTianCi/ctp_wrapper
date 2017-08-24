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

	private:
		TradeSpi* spi_;
		CThostFtdcTraderApi* api_;
	};

}