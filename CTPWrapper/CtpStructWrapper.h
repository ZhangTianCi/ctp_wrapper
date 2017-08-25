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

	public ref struct CThostFtdcDepthMarketDataFieldWrapper
	{
		String^ TradingDay;          //交易日
		String^ InstrumentID;        //合约代码
		String^ ExchangeID;          //交易所代码
		String^ ExchangeInstID;      //合约在交易所的代码
		double LastPrice;            //最新价
		double PreSettlementPrice;   //上次结算价
		double PreClosePrice;        //昨收盘
		double PreOpenInterest;      //昨持仓量
		double OpenPrice;            //今开盘
		double HighestPrice;         //最高价
		double LowestPrice;          //最低价
		int Volume;                  //数量
		double Turnover;             //成交金额
		double OpenInterest;         //持仓量
		double ClosePrice;           //今收盘
		double SettlementPrice;      //本次结算价
		double UpperLimitPrice;      //涨停板价
		double LowerLimitPrice;      //跌停板价
		double PreDelta;             //昨虚实度
		double CurrDelta;            //今虚实度
		String^ UpdateTime;          //最后修改时间
		int UpdateMillisec;          //最后修改毫秒
		double BidPrice1;            //申买价1
		int BidVolume1;              //申买量1
		double AskPrice1;            //申卖价1
		int AskVolume1;              //申卖量1
		double BidPrice2;            //申买价2
		int BidVolume2;              //申买量2
		double AskPrice2;            //申卖价2
		int AskVolume2;              //申卖量2
		double BidPrice3;            //申买价3
		int BidVolume3;              //申买量3
		double AskPrice3;            //申卖价3
		int AskVolume3;              //申卖量3
		double BidPrice4;            //申买价4
		int BidVolume4;              //申买量4
		double AskPrice4;            //申卖价4
		int AskVolume4;              //申卖量4
		double BidPrice5;            //申买价5
		int BidVolume5;              //申买量5
		double AskPrice5;            //申卖价5
		int AskVolume5;              //申卖量5
		double AveragePrice;         //当日均价
		String^ ActionDay;           //业务日期
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