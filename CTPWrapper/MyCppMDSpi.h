#pragma once

#include <msclr\auto_gcroot.h>
#include "ThostFtdcMdApi.h"
#include "CThostFtdcMdSpiWrapper.h"

namespace CTPWrapper {

	class MyCppMDSpi : public CThostFtdcMdSpi
	{
	public:
		MyCppMDSpi(CThostFtdcMdSpiWrapper^ wrapper) : wrapper_(wrapper)
		{
		}

		virtual void OnFrontConnected()
		{
			wrapper_->OnFrontConnected();
		}

		virtual void OnFrontDisconnected(int nReason)
		{
			wrapper_->OnFrontDisconnected(nReason);
		}

	private:
		msclr::auto_gcroot<CThostFtdcMdSpiWrapper^> wrapper_;
	};
}