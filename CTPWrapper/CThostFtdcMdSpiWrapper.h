#pragma once

namespace CTPWrapper {

	public ref class CThostFtdcMdSpiWrapper
	{
	public:
		virtual void OnFrontConnected() {}
		virtual void OnFrontDisconnected(int nReason) {}
	};
}
