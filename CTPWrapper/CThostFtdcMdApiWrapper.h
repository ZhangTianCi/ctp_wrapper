// CTPWrapper.h
// https://www.codeproject.com/articles/19354/quick-c-cli-learn-c-cli-in-less-than-minutes

#pragma once

using namespace System;

#include "ThostFtdcMdApi.h"
#include "MyCppMDSpi.h"
#include "MyUnmanagedString.h"
#include <vector>
#include <string>

namespace CTPWrapper {

	public ref struct CThostFtdcFensUserInfoFieldWrapper
	{
		String^ BrokerID;             //经纪公司代码
		String^ UserID;               //用户代码
		char LoginMode;               //登录模式
	};

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
			MyUnmanagedString cppFlowPath(flowPath);

			spi_ = NULL;
			api_ = CThostFtdcMdApi::CreateFtdcMdApi(
				cppFlowPath.c_str(),
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

		void RegisterSpi(CThostFtdcMdSpiWrapper^ spiCSharp)
		{
			spi_ = new MyCppMDSpi(spiCSharp);
			api_->RegisterSpi(spi_);
		}

		int SubscribeMarketData(cli::array<String^>^ instrumentIDs)
		{
			std::vector<char*> cppInstrumentIDs;
			for (int i = 0; i < instrumentIDs->Length; ++i)
			{
				cppInstrumentIDs.push_back((char*)Marshal::StringToHGlobalAnsi(instrumentIDs[i]).ToPointer());
			}
			int n = api_->SubscribeMarketData(&cppInstrumentIDs[0], cppInstrumentIDs.size());
			for (size_t i = 0; i < cppInstrumentIDs.size(); ++i)
			{
				Marshal::FreeHGlobal((IntPtr)(char*)cppInstrumentIDs[i]);
			}
			return n;
		}

		int UnSubscribeMarketData(cli::array<String^>^ instrumentIDs)
		{
			std::vector<char*> cppInstrumentIDs;
			for (int i = 0; i < instrumentIDs->Length; ++i)
			{
				cppInstrumentIDs.push_back((char*)Marshal::StringToHGlobalAnsi(instrumentIDs[i]).ToPointer());
			}
			int n = api_->UnSubscribeMarketData(&cppInstrumentIDs[0], cppInstrumentIDs.size());
			for (size_t i = 0; i < cppInstrumentIDs.size(); ++i)
			{
				Marshal::FreeHGlobal((IntPtr)(char*)cppInstrumentIDs[i]);
			}
			return n;
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

	private:
		MyCppMDSpi *spi_;
		CThostFtdcMdApi *api_;
	};


}
