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

	public ref struct CThostFtdcSettlementInfoConfirmFieldWrapper
	{
		String^ BrokerID;
		String^ InvestorID;
		String^ ConfirmDate;
		String^ ConfirmTime;
	};

	public ref struct CThostFtdcRemoveParkedOrderFieldWrapper
	{
		String^ BrokerID;
		String^ InvestorID;
		String^ ParkedOrderID;
	};

	public ref struct CThostFtdcRemoveParkedOrderActionFieldWrapper
	{
		String^ BrokerID;
		String^ InvestorID;
		String^ ParkedOrderActionID;
	};

	public ref struct CThostFtdcInputExecOrderFieldWrapper
	{
		String^ BrokerID;
		String^ InvestorID;
		String^ InstrumentID;
		String^ ExecOrderRef;
		String^ UserID;
		int Volume;
		int RequestID;
		String^ BusinessUnit;
		char OffsetFlag;
		char HedgeFlag;
		char ActionType;
		char PosiDirection;
		char ReservePositionFlag;
		char CloseFlag;
		String^ ExchangeID;
		String^ InvestUnitID;
		String^ AccountID;
		String^ CurrencyID;
		String^ ClientID;
		String^ IPAddress;
		String^ MacAddress;
	};

	public ref struct CThostFtdcInputExecOrderActionFieldWrapper
	{
		String^ BrokerID;
		String^ InvestorID;
		int ExecOrderActionRef;
		String^ ExecOrderRef;
		int RequestID;
		int FrontID;
		int SessionID;
		String^ ExchangeID;
		String^ ExecOrderSysID;
		char ActionFlag;
		String^ UserID;
		String^ InstrumentID;
		String^ InvestUnitID;
		String^ IPAddress;
		String^ MacAddress;
	};

	public ref struct CThostFtdcInputForQuoteFieldWrapper
	{
		String^ BrokerID;
		String^ InvestorID;
		String^ InstrumentID;
		String^ ForQuoteRef;
		String^ UserID;
		String^ ExchangeID;
		String^ InvestUnitID;
		String^ IPAddress;
		String^ MacAddress;
	};

	public ref struct CThostFtdcInputQuoteFieldWrapper
	{
		String^ BrokerID;
		String^ InvestorID;
		String^ InstrumentID;
		String^ QuoteRef;
		String^ UserID;
		double AskPrice;
		double BidPrice;
		int AskVolume;
		int BidVolume;
		int RequestID;
		String^ BusinessUnit;
		char AskOffsetFlag;
		char BidOffsetFlag;
		char AskHedgeFlag;
		char BidHedgeFlag;
		String^ AskOrderRef;
		String^ BidOrderRef;
		String^ ForQuoteSysID;
		String^ ExchangeID;
		String^ InvestUnitID;
		String^ ClientID;
		String^ IPAddress;
		String^ MacAddress;
	};

	public ref struct CThostFtdcInputQuoteActionFieldWrapper
	{
		String^ BrokerID;
		String^ InvestorID;
		int QuoteActionRef;
		String^ QuoteRef;
		int RequestID;
		int FrontID;
		int SessionID;
		String^ ExchangeID;
		String^ QuoteSysID;
		char ActionFlag;
		String^ UserID;
		String^ InstrumentID;
		String^ InvestUnitID;
		String^ ClientID;
		String^ IPAddress;
		String^ MacAddress;
	};

	public ref struct CThostFtdcInputBatchOrderActionFieldWrapper
	{
		String^ BrokerID;
		String^ InvestorID;
		int OrderActionRef;
		int RequestID;
		int FrontID;
		int SessionID;
		String^ ExchangeID;
		String^ UserID;
		String^ InvestUnitID;
		String^ IPAddress;
		String^ MacAddress;
	};

	public ref struct CThostFtdcInputCombActionFieldWrapper
	{
		String^ BrokerID;
		String^ InvestorID;
		String^ InstrumentID;
		String^ CombActionRef;
		String^ UserID;
		char Direction;
		int Volume;
		char CombDirection;
		char HedgeFlag;
		String^ ExchangeID;
		String^ IPAddress;
		String^ MacAddress;
	};

	public ref struct CThostFtdcOrderFieldWrapper
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
		String^ OrderLocalID;
		String^ ExchangeID;
		String^ ParticipantID;
		String^ ClientID;
		String^ ExchangeInstID;
		String^ TraderID;
		int InstallID;
		char OrderSubmitStatus;
		int NotifySequence;
		String^ TradingDay;
		int SettlementID;
		String^ OrderSysID;
		char OrderSource;
		char OrderStatus;
		char OrderType;
		int VolumeTraded;
		int VolumeTotal;
		String^ InsertDate;
		String^ InsertTime;
		String^ ActiveTime;
		String^ SuspendTime;
		String^ UpdateTime;
		String^ CancelTime;
		String^ ActiveTraderID;
		String^ ClearingPartID;
		int SequenceNo;
		int FrontID;
		int SessionID;
		String^ UserProductInfo;
		String^ StatusMsg;
		int UserForceClose;
		String^ ActiveUserID;
		int BrokerOrderSeq;
		String^ RelativeOrderSysID;
		int ZCETotalTradedVolume;
		int IsSwapOrder;
		String^ BranchID;
		String^ InvestUnitID;
		String^ AccountID;
		String^ CurrencyID;
		String^ IPAddress;
		String^ MacAddress;
	};

	public ref struct CThostFtdcReqAuthenticateFieldWrapper
	{
		String^ BrokerID;
		String^ UserID;
		String^ UserProductInfo;
		String^ AuthCode;
	};

	public ref struct CThostFtdcTradeFieldWrapper
	{
		String^ BrokerID;
		String^ InvestorID;
		String^ InstrumentID;
		String^ OrderRef;
		String^ UserID;
		String^ ExchangeID;
		String^ TradeID;
		char Direction;
		String^ OrderSysID;
		String^ ParticipantID;
		String^ ClientID;
		char TradingRole;
		String^ ExchangeInstID;
		char OffsetFlag;
		char HedgeFlag;
		double Price;
		int Volume;
		String^ TradeDate;
		String^ TradeTime;
		char TradeType;
		char PriceSource;
		String^ TraderID;
		String^ OrderLocalID;
		String^ ClearingPartID;
		String^ BusinessUnit;
		int SequenceNo;
		String^ TradingDay;
		int SettlementID;
		int BrokerOrderSeq;
		char TradeSource;
	};

	public ref struct CThostFtdcInvestorPositionFieldWrapper
	{
		String^ InstrumentID;
		String^ BrokerID;
		String^ InvestorID;
		char PosiDirection;
		char HedgeFlag;
		char PositionDate;
		int YdPosition;
		int Position;
		int LongFrozen;
		int ShortFrozen;
		double LongFrozenAmount;
		double ShortFrozenAmount;
		int OpenVolume;
		int CloseVolume;
		double OpenAmount;
		double CloseAmount;
		double PositionCost;
		double PreMargin;
		double UseMargin;
		double FrozenMargin;
		double FrozenCash;
		double FrozenCommission;
		double CashIn;
		double Commission;
		double CloseProfit;
		double PositionProfit;
		double PreSettlementPrice;
		double SettlementPrice;
		String^ TradingDay;
		int SettlementID;
		double OpenCost;
		double ExchangeMargin;
		int CombPosition;
		int CombLongFrozen;
		int CombShortFrozen;
		double CloseProfitByDate;
		double CloseProfitByTrade;
		int TodayPosition;
		double MarginRateByMoney;
		double MarginRateByVolume;
		int StrikeFrozen;
		double StrikeFrozenAmount;
		int AbandonFrozen;
	};


	public ref struct CThostFtdcTradingAccountFieldWrapper
	{
		String^ BrokerID;
		String^ AccountID;
		double PreMortgage;
		double PreCredit;
		double PreDeposit;
		double PreBalance;
		double PreMargin;
		double InterestBase;
		double Interest;
		double Deposit;
		double Withdraw;
		double FrozenMargin;
		double FrozenCash;
		double FrozenCommission;
		double CurrMargin;
		double CashIn;
		double Commission;
		double CloseProfit;
		double PositionProfit;
		double Balance;
		double Available;
		double WithdrawQuota;
		double Reserve;
		String^ TradingDay;
		int SettlementID;
		double Credit;
		double Mortgage;
		double ExchangeMargin;
		double DeliveryMargin;
		double ExchangeDeliveryMargin;
		double ReserveBalance;
		String^ CurrencyID;
		double PreFundMortgageIn;
		double PreFundMortgageOut;
		double FundMortgageIn;
		double FundMortgageOut;
		double FundMortgageAvailable;
		double MortgageableFund;
		double SpecProductMargin;
		double SpecProductFrozenMargin;
		double SpecProductCommission;
		double SpecProductFrozenCommission;
		double SpecProductPositionProfit;
		double SpecProductCloseProfit;
		double SpecProductPositionProfitByAlg;
		double SpecProductExchangeMargin;
	};

	public ref struct CThostFtdcInvestorFieldWrapper
	{
		String^ InvestorID;
		String^ BrokerID;
		String^ InvestorGroupID;
		String^ InvestorName;
		char IdentifiedCardType;
		String^ IdentifiedCardNo;
		int IsActive;
		String^ Telephone;
		String^ Address;
		String^ OpenDate;
		String^ Mobile;
		String^ CommModelID;
		String^ MarginModelID;
	};

	public ref struct CThostFtdcTradingCodeFieldWrapper
	{
		String^ InvestorID;
		String^ BrokerID;
		String^ ExchangeID;
		String^ ClientID;
		int IsActive;
		char ClientIDType;
	};
}