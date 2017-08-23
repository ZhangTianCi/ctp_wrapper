#pragma once

using namespace System;

namespace CTPWrapper {

	public ref struct CThostFtdcFensUserInfoFieldWrapper
	{
		String^ BrokerID;             //���͹�˾����
		String^ UserID;               //�û�����
		char LoginMode;               //��¼ģʽ
	};

	public ref struct CThostFtdcReqUserLoginFieldWrapper
	{
		String^ TradingDay;           // ������
		String^ BrokerID;             // ���͹�˾����
		String^ UserID;               // �û�����
		String^ Password;             // ����
		String^ UserProductInfo;      // �û��˲�Ʒ��Ϣ
		String^ InterfaceProductInfo; // �ӿڶ˲�Ʒ��Ϣ
		String^ ProtocolInfo;         // Э����Ϣ
		String^ MacAddress;           // Mac��ַ
		String^ OneTimePassword;      // ��̬����
		String^ ClientIPAddress;      // �ն�IP��ַ
		String^ LoginRemark;          // ��¼��ע
	};

	public ref struct CThostFtdcUserLogoutFieldWrapper
	{
		String^ BrokerID;             //���͹�˾����
		String^ UserID;               //�û�����
	};

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

}