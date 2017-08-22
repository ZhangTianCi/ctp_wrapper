// CTPWrapper.h

#pragma once

using namespace System;
#include "ThostFtdcMdApi.h"

namespace CTPWrapper {

	public ref class CThostFtdcMdApiWrapper
	{
	public:
		static System::String^ GetApiVersion()
		{
			return gcnew System::String(CThostFtdcMdApi::GetApiVersion());
		}

	public:
		CThostFtdcMdApiWrapper()
		{

		}

	private:
		CThostFtdcMdApi *impl_;
	};
}
