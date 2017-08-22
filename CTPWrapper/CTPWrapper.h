// CTPWrapper.h
// https://www.codeproject.com/articles/19354/quick-c-cli-learn-c-cli-in-less-than-minutes

#pragma once

using namespace System;
#include "ThostFtdcMdApi.h"
#include "MyCppMDSpi.h"

namespace CTPWrapper {

	class MyMarkDataController;

	public ref class CThostFtdcMdApiWrapper
	{
	public:
		static String^ GetApiVersion()
		{
			return gcnew String(CThostFtdcMdApi::GetApiVersion());
		}

	public:
		CThostFtdcMdApiWrapper(String^ flowPath, bool bIsUsingUdp, bool bIsMulticast)
		{
			spi_ = NULL;
			api_ = CThostFtdcMdApi::CreateFtdcMdApi(
				(char*)Runtime::InteropServices::Marshal::StringToHGlobalAnsi(flowPath).ToPointer(),
				bIsUsingUdp,
				bIsMulticast);
		}

		~CThostFtdcMdApiWrapper()
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
			return gcnew String(api_->GetTradingDay());
		}

		void RegisterSpi(CThostFtdcMdSpiWrapper^ spiCSharp)
		{
			spi_ = new MyCppMDSpi(spiCSharp);
			api_->RegisterSpi(spi_);
		}

		void RegisterFront(String^ frontAddr)
		{
			char *addr = (char*) Runtime::InteropServices::Marshal::StringToHGlobalAnsi(frontAddr).ToPointer();
			api_->RegisterFront(addr);
		}

	private:
		MyCppMDSpi *spi_;
		CThostFtdcMdApi *api_;
	};


}
