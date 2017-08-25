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

	public ref struct CThostFtdcDepthMarketDataFieldWrapper
	{
		String^ TradingDay;          //������
		String^ InstrumentID;        //��Լ����
		String^ ExchangeID;          //����������
		String^ ExchangeInstID;      //��Լ�ڽ������Ĵ���
		double LastPrice;            //���¼�
		double PreSettlementPrice;   //�ϴν����
		double PreClosePrice;        //������
		double PreOpenInterest;      //��ֲ���
		double OpenPrice;            //����
		double HighestPrice;         //��߼�
		double LowestPrice;          //��ͼ�
		int Volume;                  //����
		double Turnover;             //�ɽ����
		double OpenInterest;         //�ֲ���
		double ClosePrice;           //������
		double SettlementPrice;      //���ν����
		double UpperLimitPrice;      //��ͣ���
		double LowerLimitPrice;      //��ͣ���
		double PreDelta;             //����ʵ��
		double CurrDelta;            //����ʵ��
		String^ UpdateTime;          //����޸�ʱ��
		int UpdateMillisec;          //����޸ĺ���
		double BidPrice1;            //�����1
		int BidVolume1;              //������1
		double AskPrice1;            //������1
		int AskVolume1;              //������1
		double BidPrice2;            //�����2
		int BidVolume2;              //������2
		double AskPrice2;            //������2
		int AskVolume2;              //������2
		double BidPrice3;            //�����3
		int BidVolume3;              //������3
		double AskPrice3;            //������3
		int AskVolume3;              //������3
		double BidPrice4;            //�����4
		int BidVolume4;              //������4
		double AskPrice4;            //������4
		int AskVolume4;              //������4
		double BidPrice5;            //�����5
		int BidVolume5;              //������5
		double AskPrice5;            //������5
		int AskVolume5;              //������5
		double AveragePrice;         //���վ���
		String^ ActionDay;           //ҵ������
	};

	public ref struct CThostFtdcForQuoteRspFieldWrapper
	{
		String^ TradingDay;
		String^ InstrumentID;
		String^ ForQuoteSysID;
		String^ ForQuoteTime;
		String^ ActionDay;
		String^ ExchangeID;
	};

	public ref struct CThostFtdcRspAuthenticateFieldWrapper
	{
		String^ BrokerID;
		String^ UserID;
		String^ UserProductInfo;
	};

	public ref struct CThostFtdcUserPasswordUpdateFieldWrapper
	{
		String^ BrokerID;
		String^ UserID;
		String^ OldPassword;
		String^ NewPassword;
	};

	public ref struct CThostFtdcTradingAccountPasswordUpdateFieldWrapper
	{
		String^ BrokerID;
		String^ AccountID;
		String^ OldPassword;
		String^ NewPassword;
		String^ CurrencyID;
	};

	public ref struct CThostFtdcInputOrderFieldWrapper
	{
		String^ BrokerID;
		String^ InvestorID;
		String^ InstrumentID;
		String^ OrderRef;
		String^ UserID;
		char OrderPriceType;
		char Direction;
		String^ CombOffsetFlag;
		String^ CombHedgeFlag;
		double LimitPrice;
		int VolumeTotalOriginal;
		char TimeCondition;
		String^ GTDDate;
		char VolumeCondition;
		int MinVolume;
		char ContingentCondition;
		double StopPrice;
		char ForceCloseReason;
		int IsAutoSuspend;
		String^ BusinessUnit;
		int RequestID;
		int UserForceClose;
		int IsSwapOrder;
		String^ ExchangeID;
		String^ InvestUnitID;
		String^ AccountID;
		String^ CurrencyID;
		String^ ClientID;
		String^ IPAddress;
		String^ MacAddress;
	};

	public ref struct CThostFtdcParkedOrderFieldWrapper
	{
		String^ BrokerID;
		String^ InvestorID;
		String^ InstrumentID;
		String^ OrderRef;
		String^ UserID;
		char OrderPriceType;
		char Direction;
		String^ CombOffsetFlag;
		String^ CombHedgeFlag;
		double LimitPrice;
		int VolumeTotalOriginal;
		char TimeCondition;
		String^ GTDDate;
		char VolumeCondition;
		int MinVolume;
		char ContingentCondition;
		double StopPrice;
		char ForceCloseReason;
		int IsAutoSuspend;
		String^ BusinessUnit;
		int RequestID;
		int UserForceClose;
		String^ ExchangeID;
		String^ ParkedOrderID;
		char UserType;
		char Status;
		int ErrorID;
		String^ ErrorMsg;
		int IsSwapOrder;
		String^ AccountID;
		String^ CurrencyID;
		String^ ClientID;
		String^ InvestUnitID;
		String^ IPAddress;
		String^ MacAddress;
	};

	public ref struct CThostFtdcParkedOrderActionFieldWrapper
	{
		String^ BrokerID;
		String^ InvestorID;
		int OrderActionRef;
		String^ OrderRef;
		int RequestID;
		int FrontID;
		int SessionID;
		String^ ExchangeID;
		String^ OrderSysID;
		char ActionFlag;
		double LimitPrice;
		int VolumeChange;
		String^ UserID;
		String^ InstrumentID;
		String^ ParkedOrderActionID;
		char UserType;
		char Status;
		int ErrorID;
		String^ ErrorMsg;
		String^ InvestUnitID;
		String^ IPAddress;
		String^ MacAddress;
	};

	public ref struct CThostFtdcInputOrderActionFieldWrapper
	{
		String^ BrokerID;
		String^ InvestorID;
		int OrderActionRef;
		String^ OrderRef;
		int RequestID;
		int FrontID;
		int SessionID;
		String^ ExchangeID;
		String^ OrderSysID;
		char ActionFlag;
		double LimitPrice;
		int VolumeChange;
		String^ UserID;
		String^ InstrumentID;
		String^ InvestUnitID;
		String^ IPAddress;
		String^ MacAddress;
	};

	public ref struct CThostFtdcQueryMaxOrderVolumeFieldWrapper
	{
		String^ BrokerID;
		String^ InvestorID;
		String^ InstrumentID;
		char Direction;
		char OffsetFlag;
		char HedgeFlag;
		int MaxVolume;
	};

}