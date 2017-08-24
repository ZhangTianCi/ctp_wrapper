#pragma once

using namespace System;

#include "ThostFtdcTraderApi.h"
#include "MyUnmanagedString.h"

namespace CTPWrapper {

	public ref class TradeApiWrapper
	{
	public:
		static String^ GetApiVersion()
		{
			return MyUnmanagedString::ToManaged(CThostFtdcTraderApi::GetApiVersion());
		}

	};

}