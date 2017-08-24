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

	private:
		msclr::auto_gcroot<TradeSpiWrapper^> wrapper_;
	};

}
