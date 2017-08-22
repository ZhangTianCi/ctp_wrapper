// CTPWrapper.h
// https://www.codeproject.com/articles/19354/quick-c-cli-learn-c-cli-in-less-than-minutes

#pragma once

using namespace System;
using namespace System::Runtime::InteropServices;

#include "ThostFtdcMdApi.h"
#include "MyCppMDSpi.h"

namespace CTPWrapper {

	public ref struct CThostFtdcReqUserLoginFieldWrapper
	{
		String^ TradingDay;           // 交易日
		String^ BrokerID;             // 经纪公司代码
		String^ UserID;               // 用户代码
		String^ Password;             // 密码
		String^ UserProductInfo;      // 用户端产品信息
		String^ InterfaceProductInfo; // 接口端产品信息
		String^ ProtocolInfo;         // 协议信息
		String^ MacAddress;           // Mac地址
		String^ OneTimePassword;      // 动态密码
		String^ ClientIPAddress;      // 终端IP地址
		String^ LoginRemark;          // 登录备注
	};

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
				(char*)Marshal::StringToHGlobalAnsi(flowPath).ToPointer(),
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
			char *addr = (char*)Marshal::StringToHGlobalAnsi(frontAddr).ToPointer();
			api_->RegisterFront(addr);
		}

		int ReqUserLogin(CThostFtdcReqUserLoginFieldWrapper^ pReqUserLoginField, int nRequestID)
		{
			CThostFtdcReqUserLoginField req;
			memset(&req, 0, sizeof(req));

			if (pReqUserLoginField->TradingDay) strcpy(req.TradingDay, (char*)Marshal::StringToHGlobalAnsi(pReqUserLoginField->TradingDay).ToPointer());
			if (pReqUserLoginField->BrokerID) strcpy(req.BrokerID, (char*)Marshal::StringToHGlobalAnsi(pReqUserLoginField->BrokerID).ToPointer());
			if (pReqUserLoginField->UserID) strcpy(req.UserID, (char*)Marshal::StringToHGlobalAnsi(pReqUserLoginField->UserID).ToPointer());
			if (pReqUserLoginField->Password) strcpy(req.Password, (char*)Marshal::StringToHGlobalAnsi(pReqUserLoginField->Password).ToPointer());
			if (pReqUserLoginField->UserProductInfo) strcpy(req.UserProductInfo, (char*)Marshal::StringToHGlobalAnsi(pReqUserLoginField->UserProductInfo).ToPointer());
			if (pReqUserLoginField->InterfaceProductInfo) strcpy(req.InterfaceProductInfo, (char*)Marshal::StringToHGlobalAnsi(pReqUserLoginField->InterfaceProductInfo).ToPointer());
			if (pReqUserLoginField->ProtocolInfo) strcpy(req.ProtocolInfo, (char*)Marshal::StringToHGlobalAnsi(pReqUserLoginField->ProtocolInfo).ToPointer());
			if (pReqUserLoginField->MacAddress) strcpy(req.MacAddress, (char*)Marshal::StringToHGlobalAnsi(pReqUserLoginField->MacAddress).ToPointer());
			if (pReqUserLoginField->OneTimePassword) strcpy(req.OneTimePassword, (char*)Marshal::StringToHGlobalAnsi(pReqUserLoginField->OneTimePassword).ToPointer());
			if (pReqUserLoginField->ClientIPAddress) strcpy(req.ClientIPAddress, (char*)Marshal::StringToHGlobalAnsi(pReqUserLoginField->ClientIPAddress).ToPointer());
			if (pReqUserLoginField->LoginRemark) strcpy(req.LoginRemark, (char*)Marshal::StringToHGlobalAnsi(pReqUserLoginField->LoginRemark).ToPointer());
			return api_->ReqUserLogin(&req, nRequestID);
		}

	private:
		MyCppMDSpi *spi_;
		CThostFtdcMdApi *api_;
	};


}
