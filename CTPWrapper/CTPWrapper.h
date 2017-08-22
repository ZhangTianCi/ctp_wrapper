// CTPWrapper.h
// https://www.codeproject.com/articles/19354/quick-c-cli-learn-c-cli-in-less-than-minutes

#pragma once

using namespace System;
#include "ThostFtdcMdApi.h"

namespace CTPWrapper {

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
			impl_ = CThostFtdcMdApi::CreateFtdcMdApi(
				(char*)Runtime::InteropServices::Marshal::StringToHGlobalAnsi(flowPath).ToPointer(),
				bIsUsingUdp,
				bIsMulticast);
		}

		~CThostFtdcMdApiWrapper()
		{
		}

		void Release()
		{
			impl_->Release();
		}

		void Init()
		{
			impl_->Init();
		}

		void Join()
		{
			impl_->Join();
		}

		String^ GetTradingDay()
		{
			return gcnew String(impl_->GetTradingDay());
		}

	private:
		CThostFtdcMdApi *impl_;
	};
}
