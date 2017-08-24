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

	private:
		TradeSpi* spi_;
		CThostFtdcTraderApi* api_;
	};

}