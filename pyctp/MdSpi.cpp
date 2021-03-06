#include "MdSpi.h"

#include "Windows.h"

///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
void MdSpi::OnFrontConnected(){
	OnStaticFrontConnected();
}

///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
///@param nReason 错误原因
///        0x1001 网络读失败
///        0x1002 网络写失败
///        0x2001 接收心跳超时
///        0x2002 发送心跳失败
///        0x2003 收到错误报文 On_MdSpiResponse(
void MdSpi::OnFrontDisconnected(int nReason){
	OutputDebugString("OnFrontDisconnected");
	OnStaticFrontDisconnected(nReason);
}
    
///心跳超时警告。当长时间未收到报文时，该方法被调用。
///@param nTimeLapse 距离上次接收报文的时间
void MdSpi::OnHeartBeatWarning(int nTimeLapse){
	OutputDebugString("OnHeartBeatWarning");
	OnStaticHeartBeatWarning(nTimeLapse);
}


///登录请求响应
void MdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
	OutputDebugString("OnRspUserLogin");
	OnStaticRspUserLogin(pRspUserLogin, pRspInfo, nRequestID, bIsLast);
}

///登出请求响应
void MdSpi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
	OutputDebugString("OnRspUserLogout");
	OnStaticRspUserLogout(pUserLogout, pRspInfo, nRequestID, bIsLast);
}

///错误应答
void MdSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
	OutputDebugString("OnRspError");
	OnStaticRspError(pRspInfo, nRequestID, bIsLast);
}

///订阅行情应答
void MdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
	OutputDebugString("OnRspSubMarketData");
	OnStaticRspSubMarketData(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
}

///取消订阅行情应答
void MdSpi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
	OutputDebugString("OnRspUnSubMarketData");
	OnStaticRspUnSubMarketData(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
}

///订阅询价应答
void MdSpi::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
	OutputDebugString("OnRspSubForQuoteRsp");
	OnStaticRspSubForQuoteRsp(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
}

///取消订阅询价应答
void MdSpi::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast){
	OutputDebugString("OnRspUnSubForQuoteRsp");
	OnStaticRspUnSubForQuoteRsp(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
}

///深度行情通知
void MdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData){
	OutputDebugString("OnRtnDepthMarketData");
	OnStaticRtnDepthMarketData(pDepthMarketData);
}

///询价通知
void MdSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp){
	OutputDebugString("OnRtnForQuoteRsp");
	OnStaticRtnForQuoteRsp(pForQuoteRsp);
}