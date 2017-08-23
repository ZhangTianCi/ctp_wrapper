#pragma once

using namespace System;

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

	public ref struct CThostFtdcUserLogoutFieldWrapper
	{
		String^ BrokerID;             //经纪公司代码
		String^ UserID;               //用户代码
	};

	public ref struct CThostFtdcRspUserLoginFieldWrapper
	{
		String^ TradingDay;      // 交易日
		String^ LoginTime;       // 登录成功时间
		String^ BrokerID;        // 经纪公司代码
		String^ UserID;          // 用户代码
		String^ SystemName;      // 交易系统名称
		int FrontID;            // 前置编号
		int SessionID;          // 会话编号
		String^ MaxOrderRef;     // 最大报单引用
		String^ SHFETime;        // 上期所时间
		String^ DCETime;         // 大商所时间
		String^ CZCETime;        // 郑商所时间
		String^ FFEXTime;        // 中金所时间
		String^ INETime;         // 能源中心时间
	};

	public ref struct CThostFtdcRspInfoFieldWrapper
	{
		int	ErrorID;
		String^ ErrorMsg;
	};

	public ref struct CThostFtdcSpecificInstrumentFieldWrapper
	{
		String^ InstrumentID;
	};

}