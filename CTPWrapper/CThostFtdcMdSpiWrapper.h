#pragma once

using namespace System;

namespace CTPWrapper {

	public ref struct CThostFtdcRspUserLoginFieldWrapper
	{
		String^ TradingDay;      // ������
		String^ LoginTime;       // ��¼�ɹ�ʱ��
		String^ BrokerID;        // ���͹�˾����
		String^ UserID;          // �û�����
		String^ SystemName;      // ����ϵͳ����
		int FrontID;            // ǰ�ñ��
		int SessionID;          // �Ự���
		String^ MaxOrderRef;     // ��󱨵�����
		String^ SHFETime;        // ������ʱ��
		String^ DCETime;         // ������ʱ��
		String^ CZCETime;        // ֣����ʱ��
		String^ FFEXTime;        // �н���ʱ��
		String^ INETime;         // ��Դ����ʱ��
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

	public ref class CThostFtdcMdSpiWrapper
	{
	public:
		virtual void OnFrontConnected() {}
		virtual void OnFrontDisconnected(int nReason) {}
		virtual void OnHeartBeatWarning(int nTimeLapse) {}

		virtual void OnRspUserLogin(CThostFtdcRspUserLoginFieldWrapper^ pRspUserLogin, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}

		virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentFieldWrapper^ pSpecificInstrument, CThostFtdcRspInfoFieldWrapper^ pRspInfo, int nRequestID, bool bIsLast) {}
	};
}
