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

	public ref struct CThostFtdcInstrumentMarginRateFieldWrapper
	{
		String^ InstrumentID;
		char InvestorRange;
		String^ BrokerID;
		String^ InvestorID;
		char HedgeFlag;
		double LongMarginRatioByMoney;
		double LongMarginRatioByVolume;
		double ShortMarginRatioByMoney;
		double ShortMarginRatioByVolume;
		int IsRelative;
	};

	public ref struct CThostFtdcInstrumentCommissionRateFieldWrapper
	{
		String^ InstrumentID;
		char InvestorRange;
		String^ BrokerID;
		String^ InvestorID;
		double OpenRatioByMoney;
		double OpenRatioByVolume;
		double CloseRatioByMoney;
		double CloseRatioByVolume;
		double CloseTodayRatioByMoney;
		double CloseTodayRatioByVolume;
	};

	public ref struct CThostFtdcExchangeFieldWrapper
	{
		String^ ExchangeID;
		String^ ExchangeName;
		char ExchangeProperty;
	};

	public ref struct CThostFtdcProductFieldWrapper
	{
		String^ ProductID;
		String^ ProductName;
		String^ ExchangeID;
		char ProductClass;
		int VolumeMultiple;
		double PriceTick;
		int MaxMarketOrderVolume;
		int MinMarketOrderVolume;
		int MaxLimitOrderVolume;
		int MinLimitOrderVolume;
		char PositionType;
		char PositionDateType;
		char CloseDealType;
		String^ TradeCurrencyID;
		char MortgageFundUseRange;
		String^ ExchangeProductID;
		double UnderlyingMultiple;
	};

	public ref struct CThostFtdcInstrumentFieldWrapper
	{
		String^ InstrumentID;
		String^ ExchangeID;
		String^ InstrumentName;
		String^ ExchangeInstID;
		String^ ProductID;
		char ProductClass;
		int DeliveryYear;
		int DeliveryMonth;
		int MaxMarketOrderVolume;
		int MinMarketOrderVolume;
		int MaxLimitOrderVolume;
		int MinLimitOrderVolume;
		int VolumeMultiple;
		double PriceTick;
		String^ CreateDate;
		String^ OpenDate;
		String^ ExpireDate;
		String^ StartDelivDate;
		String^ EndDelivDate;
		char InstLifePhase;
		int IsTrading;
		char PositionType;
		char PositionDateType;
		double LongMarginRatio;
		double ShortMarginRatio;
		char MaxMarginSideAlgorithm;
		String^ UnderlyingInstrID;
		double StrikePrice;
		char OptionsType;
		double UnderlyingMultiple;
		char CombinationType;
	};

	public ref struct CThostFtdcDepthMarketDataFieldWrapper
	{
		String^ TradingDay;
		String^ InstrumentID;
		String^ ExchangeID;
		String^ ExchangeInstID;
		double LastPrice;
		double PreSettlementPrice;
		double PreClosePrice;
		double PreOpenInterest;
		double OpenPrice;
		double HighestPrice;
		double LowestPrice;
		int Volume;
		double Turnover;
		double OpenInterest;
		double ClosePrice;
		double SettlementPrice;
		double UpperLimitPrice;
		double LowerLimitPrice;
		double PreDelta;
		double CurrDelta;
		String^ UpdateTime;
		int UpdateMillisec;
		double BidPrice1;
		int BidVolume1;
		double AskPrice1;
		int AskVolume1;
		double BidPrice2;
		int BidVolume2;
		double AskPrice2;
		int AskVolume2;
		double BidPrice3;
		int BidVolume3;
		double AskPrice3;
		int AskVolume3;
		double BidPrice4;
		int BidVolume4;
		double AskPrice4;
		int AskVolume4;
		double BidPrice5;
		int BidVolume5;
		double AskPrice5;
		int AskVolume5;
		double AveragePrice;
		String^ ActionDay;
	};

	public ref struct CThostFtdcSettlementInfoFieldWrapper
	{
		String^ TradingDay;
		int SettlementID;
		String^ BrokerID;
		String^ InvestorID;
		int SequenceNo;
		String^ Content;
	};

	public ref struct CThostFtdcTransferBankFieldWrapper
	{
		String^ BankID;
		String^ BankBrchID;
		String^ BankName;
		int IsActive;
	};

	public ref struct CThostFtdcInvestorPositionDetailFieldWrapper
	{
		String^ InstrumentID;
		String^ BrokerID;
		String^ InvestorID;
		char HedgeFlag;
		char Direction;
		String^ OpenDate;
		String^ TradeID;
		int Volume;
		double OpenPrice;
		String^ TradingDay;
		int SettlementID;
		char TradeType;
		String^ CombInstrumentID;
		String^ ExchangeID;
		double CloseProfitByDate;
		double CloseProfitByTrade;
		double PositionProfitByDate;
		double PositionProfitByTrade;
		double Margin;
		double ExchMargin;
		double MarginRateByMoney;
		double MarginRateByVolume;
		double LastSettlementPrice;
		double SettlementPrice;
		int CloseVolume;
		double CloseAmount;
	};

	public ref struct CThostFtdcNoticeFieldWrapper
	{
		String^ BrokerID;
		String^ Content;
		String^ SequenceLabel;
	};

	public ref struct CThostFtdcInvestorPositionCombineDetailFieldWrapper
	{
		String^ TradingDay;
		String^ OpenDate;
		String^ ExchangeID;
		int SettlementID;
		String^ BrokerID;
		String^ InvestorID;
		String^ ComTradeID;
		String^ TradeID;
		String^ InstrumentID;
		char HedgeFlag;
		char Direction;
		int TotalAmt;
		double Margin;
		double ExchMargin;
		double MarginRateByMoney;
		double MarginRateByVolume;
		int LegID;
		int LegMultiple;
		String^ CombInstrumentID;
		int TradeGroupID;
	};

	public ref struct CThostFtdcCFMMCTradingAccountKeyFieldWrapper
	{
		String^ BrokerID;
		String^ ParticipantID;
		String^ AccountID;
		int KeyID;
		String^ CurrentKey;
	};

	public ref struct CThostFtdcEWarrantOffsetFieldWrapper
	{
		String^ TradingDay;
		String^ BrokerID;
		String^ InvestorID;
		String^ ExchangeID;
		String^ InstrumentID;
		char Direction;
		char HedgeFlag;
		int Volume;
	};

	public ref struct CThostFtdcInvestorProductGroupMarginFieldWrapper
	{
		String^ ProductGroupID;
		String^ BrokerID;
		String^ InvestorID;
		String^ TradingDay;
		int SettlementID;
		double FrozenMargin;
		double LongFrozenMargin;
		double ShortFrozenMargin;
		double UseMargin;
		double LongUseMargin;
		double ShortUseMargin;
		double ExchMargin;
		double LongExchMargin;
		double ShortExchMargin;
		double CloseProfit;
		double FrozenCommission;
		double Commission;
		double FrozenCash;
		double CashIn;
		double PositionProfit;
		double OffsetAmount;
		double LongOffsetAmount;
		double ShortOffsetAmount;
		double ExchOffsetAmount;
		double LongExchOffsetAmount;
		double ShortExchOffsetAmount;
		char HedgeFlag;
	};

	public ref struct CThostFtdcExchangeMarginRateFieldWrapper
	{
		String^ BrokerID;
		String^ InstrumentID;
		char HedgeFlag;
		double LongMarginRatioByMoney;
		double LongMarginRatioByVolume;
		double ShortMarginRatioByMoney;
		double ShortMarginRatioByVolume;
	};

	public ref struct CThostFtdcExchangeMarginRateAdjustFieldWrapper
	{
		String^ BrokerID;
		String^ InstrumentID;
		char HedgeFlag;
		double LongMarginRatioByMoney;
		double LongMarginRatioByVolume;
		double ShortMarginRatioByMoney;
		double ShortMarginRatioByVolume;
		double ExchLongMarginRatioByMoney;
		double ExchLongMarginRatioByVolume;
		double ExchShortMarginRatioByMoney;
		double ExchShortMarginRatioByVolume;
		double NoLongMarginRatioByMoney;
		double NoLongMarginRatioByVolume;
		double NoShortMarginRatioByMoney;
		double NoShortMarginRatioByVolume;
	};

	public ref struct CThostFtdcExchangeRateFieldWrapper
	{
		String^ BrokerID;
		String^ FromCurrencyID;
		double FromCurrencyUnit;
		String^ ToCurrencyID;
		double ExchangeRate;
	};

	public ref struct CThostFtdcSecAgentACIDMapFieldWrapper
	{
		String^ BrokerID;
		String^ UserID;
		String^ AccountID;
		String^ CurrencyID;
		String^ BrokerSecAgentID;
	};

	public ref struct CThostFtdcProductExchRateFieldWrapper
	{
		String^ ProductID;
		String^ QuoteCurrencyID;
		double ExchangeRate;
	};

	public ref struct CThostFtdcProductGroupFieldWrapper
	{
		String^ ProductID;
		String^ ExchangeID;
		String^ ProductGroupID;
	};

	public ref struct CThostFtdcMMInstrumentCommissionRateFieldWrapper
	{
		String^ InstrumentID;
		char InvestorRange;
		String^ BrokerID;
		String^ InvestorID;
		double OpenRatioByMoney;
		double OpenRatioByVolume;
		double CloseRatioByMoney;
		double CloseRatioByVolume;
		double CloseTodayRatioByMoney;
		double CloseTodayRatioByVolume;
	};

	public ref struct CThostFtdcMMOptionInstrCommRateFieldWrapper
	{
		String^ InstrumentID;
		char InvestorRange;
		String^ BrokerID;
		String^ InvestorID;
		double OpenRatioByMoney;
		double OpenRatioByVolume;
		double CloseRatioByMoney;
		double CloseRatioByVolume;
		double CloseTodayRatioByMoney;
		double CloseTodayRatioByVolume;
		double StrikeRatioByMoney;
		double StrikeRatioByVolume;
	};

	public ref struct CThostFtdcInstrumentOrderCommRateFieldWrapper
	{
		String^ InstrumentID;
		char InvestorRange;
		String^ BrokerID;
		String^ InvestorID;
		char HedgeFlag;
		double OrderCommByVolume;
		double OrderActionCommByVolume;
	};

	public ref struct CThostFtdcOptionInstrTradeCostFieldWrapper
	{
		String^ BrokerID;
		String^ InvestorID;
		String^ InstrumentID;
		char HedgeFlag;
		double FixedMargin;
		double MiniMargin;
		double Royalty;
		double ExchFixedMargin;
		double ExchMiniMargin;
	};

	public ref struct CThostFtdcOptionInstrCommRateFieldWrapper
	{
		String^ InstrumentID;
		char InvestorRange;
		String^ BrokerID;
		String^ InvestorID;
		double OpenRatioByMoney;
		double OpenRatioByVolume;
		double CloseRatioByMoney;
		double CloseRatioByVolume;
		double CloseTodayRatioByMoney;
		double CloseTodayRatioByVolume;
		double StrikeRatioByMoney;
		double StrikeRatioByVolume;
	};

	public ref struct CThostFtdcExecOrderFieldWrapper
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
		String^ ExecOrderLocalID;
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
		String^ ExecOrderSysID;
		String^ InsertDate;
		String^ InsertTime;
		String^ CancelTime;
		char ExecResult;
		String^ ClearingPartID;
		int SequenceNo;
		int FrontID;
		int SessionID;
		String^ UserProductInfo;
		String^ StatusMsg;
		String^ ActiveUserID;
		int BrokerExecOrderSeq;
		String^ BranchID;
		String^ InvestUnitID;
		String^ AccountID;
		String^ CurrencyID;
		String^ IPAddress;
		String^ MacAddress;
	};
	public ref struct CThostFtdcForQuoteFieldWrapper
	{
		String^ BrokerID;
		String^ InvestorID;
		String^ InstrumentID;
		String^ ForQuoteRef;
		String^ UserID;
		String^ ForQuoteLocalID;
		String^ ExchangeID;
		String^ ParticipantID;
		String^ ClientID;
		String^ ExchangeInstID;
		String^ TraderID;
		int InstallID;
		String^ InsertDate;
		String^ InsertTime;
		char ForQuoteStatus;
		int FrontID;
		int SessionID;
		String^ StatusMsg;
		String^ ActiveUserID;
		int BrokerForQutoSeq;
		String^ InvestUnitID;
		String^ IPAddress;
		String^ MacAddress;
	};

	public ref struct CThostFtdcQuoteFieldWrapper
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
		String^ QuoteLocalID;
		String^ ExchangeID;
		String^ ParticipantID;
		String^ ClientID;
		String^ ExchangeInstID;
		String^ TraderID;
		int InstallID;
		int NotifySequence;
		char OrderSubmitStatus;
		String^ TradingDay;
		int SettlementID;
		String^ QuoteSysID;
		String^ InsertDate;
		String^ InsertTime;
		String^ CancelTime;
		char QuoteStatus;
		String^ ClearingPartID;
		int SequenceNo;
		String^ AskOrderSysID;
		String^ BidOrderSysID;
		int FrontID;
		int SessionID;
		String^ UserProductInfo;
		String^ StatusMsg;
		String^ ActiveUserID;
		int BrokerQuoteSeq;
		String^ AskOrderRef;
		String^ BidOrderRef;
		String^ ForQuoteSysID;
		String^ BranchID;
		String^ InvestUnitID;
		String^ AccountID;
		String^ CurrencyID;
		String^ IPAddress;
		String^ MacAddress;
	};

	public ref struct CThostFtdcCombInstrumentGuardFieldWrapper
	{
		String^ BrokerID;
		String^ InstrumentID;
		double GuarantRatio;
	};

	public ref struct CThostFtdcCombActionFieldWrapper
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
		String^ ActionLocalID;
		String^ ExchangeID;
		String^ ParticipantID;
		String^ ClientID;
		String^ ExchangeInstID;
		String^ TraderID;
		int InstallID;
		char ActionStatus;
		int NotifySequence;
		String^ TradingDay;
		int SettlementID;
		int SequenceNo;
		int FrontID;
		int SessionID;
		String^ UserProductInfo;
		String^ StatusMsg;
		String^ IPAddress;
		String^ MacAddress;
	};

	public ref struct CThostFtdcTransferSerialFieldWrapper
	{
		int PlateSerial;
		String^ TradeDate;
		String^ TradingDay;
		String^ TradeTime;
		String^ TradeCode;
		int SessionID;
		String^ BankID;
		String^ BankBranchID;
		char BankAccType;
		String^ BankAccount;
		String^ BankSerial;
		String^ BrokerID;
		String^ BrokerBranchID;
		char FutureAccType;
		String^ AccountID;
		String^ InvestorID;
		int FutureSerial;
		char IdCardType;
		String^ IdentifiedCardNo;
		String^ CurrencyID;
		double TradeAmount;
		double CustFee;
		double BrokerFee;
		char AvailabilityFlag;
		String^ OperatorCode;
		String^ BankNewAccount;
		int ErrorID;
		String^ ErrorMsg;
	};

	public ref struct CThostFtdcAccountregisterFieldWrapper
	{
		String^ TradeDay;
		String^ BankID;
		String^ BankBranchID;
		String^ BankAccount;
		String^ BrokerID;
		String^ BrokerBranchID;
		String^ AccountID;
		char IdCardType;
		String^ IdentifiedCardNo;
		String^ CustomerName;
		String^ CurrencyID;
		char OpenOrDestroy;
		String^ RegDate;
		String^ OutDate;
		int TID;
		char CustType;
		char BankAccType;
		String^ LongCustomerName;
	};

	public ref struct CThostFtdcOrderActionFieldWrapper
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
		String^ ActionDate;
		String^ ActionTime;
		String^ TraderID;
		int InstallID;
		String^ OrderLocalID;
		String^ ActionLocalID;
		String^ ParticipantID;
		String^ ClientID;
		String^ BusinessUnit;
		char OrderActionStatus;
		String^ UserID;
		String^ StatusMsg;
		String^ InstrumentID;
		String^ BranchID;
		String^ InvestUnitID;
		String^ IPAddress;
		String^ MacAddress;
	};

	public ref struct CThostFtdcInstrumentStatusFieldWrapper
	{
		String^ ExchangeID;
		String^ ExchangeInstID;
		String^ SettlementGroupID;
		String^ InstrumentID;
		char InstrumentStatus;
		int TradingSegmentSN;
		String^ EnterTime;
		char EnterReason;
	};

	public ref struct CThostFtdcBulletinFieldWrapper
	{
		String^ ExchangeID;
		String^ TradingDay;
		int BulletinID;
		int SequenceNo;
		String^ NewsType;
		char NewsUrgency;
		String^ SendTime;
		String^ Abstract;
		String^ ComeFrom;
		String^ Content;
		String^ URLLink;
		String^ MarketID;
	};

	public ref struct CThostFtdcTradingNoticeInfoFieldWrapper
	{
		String^ BrokerID;
		String^ InvestorID;
		String^ SendTime;
		String^ FieldContent;
		short SequenceSeries;
		int SequenceNo;
	};

	public ref struct CThostFtdcErrorConditionalOrderFieldWrapper
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
		int ErrorID;
		String^ ErrorMsg;
		int IsSwapOrder;
		String^ BranchID;
		String^ InvestUnitID;
		String^ AccountID;
		String^ CurrencyID;
		String^ IPAddress;
		String^ MacAddress;
	};

	public ref struct CThostFtdcExecOrderActionFieldWrapper
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
		String^ ActionDate;
		String^ ActionTime;
		String^ TraderID;
		int InstallID;
		String^ ExecOrderLocalID;
		String^ ActionLocalID;
		String^ ParticipantID;
		String^ ClientID;
		String^ BusinessUnit;
		char OrderActionStatus;
		String^ UserID;
		char ActionType;
		String^ StatusMsg;
		String^ InstrumentID;
		String^ BranchID;
		String^ InvestUnitID;
		String^ IPAddress;
		String^ MacAddress;
	};

	public ref struct CThostFtdcQuoteActionFieldWrapper
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
		String^ ActionDate;
		String^ ActionTime;
		String^ TraderID;
		int InstallID;
		String^ QuoteLocalID;
		String^ ActionLocalID;
		String^ ParticipantID;
		String^ ClientID;
		String^ BusinessUnit;
		char OrderActionStatus;
		String^ UserID;
		String^ StatusMsg;
		String^ InstrumentID;
		String^ BranchID;
		String^ InvestUnitID;
		String^ IPAddress;
		String^ MacAddress;
	};

	public ref struct CThostFtdcCFMMCTradingAccountTokenFieldWrapper
	{
		String^ BrokerID;
		String^ ParticipantID;
		String^ AccountID;
		int KeyID;
		String^ Token;
	};

	public ref struct CThostFtdcBatchOrderActionFieldWrapper
	{
		String^ BrokerID;
		String^ InvestorID;
		int OrderActionRef;
		int RequestID;
		int FrontID;
		int SessionID;
		String^ ExchangeID;
		String^ ActionDate;
		String^ ActionTime;
		String^ TraderID;
		int InstallID;
		String^ ActionLocalID;
		String^ ParticipantID;
		String^ ClientID;
		String^ BusinessUnit;
		char OrderActionStatus;
		String^ UserID;
		String^ StatusMsg;
		String^ InvestUnitID;
		String^ IPAddress;
		String^ MacAddress;
	};

	public ref struct CThostFtdcContractBankFieldWrapper
	{
		String^ BrokerID;
		String^ BankID;
		String^ BankBrchID;
		String^ BankName;
	};

}