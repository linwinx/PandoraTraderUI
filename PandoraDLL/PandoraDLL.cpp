// PandoraDLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "cwFtdMdSpi.h"
#include "cwFtdTradeSpi.h"
#include "cwPandoraUIStrategy.h"
#include "cwPandoraUIApp.h"

#if defined(ISLIB) && defined(WIN32)
#ifdef CW_DLL_EXPORTS
#define CW_DLL_API extern "C" __declspec(dllexport)
#else
#define CW_DLL_API __declspec(dllimport)
#endif
#else
#define CW_DLL_API 
#endif

#ifdef _MSC_VER
#pragma region InitialPandoraApp
#endif

CW_DLL_API cwPandoraUIApp* __cdecl CreatecwPandoraUIApp()
{
	return new cwPandoraUIApp();
}

CW_DLL_API void __cdecl ReleasePandoraUIApp(cwPandoraUIApp* pApp)
{
	if (pApp != NULL)
	{
		delete pApp;
		pApp = NULL;
	}
}

CW_DLL_API void __cdecl SetMdLoginField(cwPandoraUIApp * pApp, const char* szBrokerID, const char* szUserID, const char* szPassword)
{
	if (pApp != NULL)
	{
		pApp->m_mdCollector.SetUserLoginField(szBrokerID, szUserID, szPassword);
	}
}

CW_DLL_API void __cdecl SetTradeLoginField(cwPandoraUIApp* pApp, const char* szBrokerID, const char* szUserID, const char* szPassword)
{
	if (pApp != NULL)
	{
		pApp->m_TradeChannel.SetUserLoginField(szBrokerID, szUserID, szPassword, "Pandora");
	}
}

CW_DLL_API void __cdecl SetAuthenticateInfo(cwPandoraUIApp* pApp, const char* szAppID, const char* szAuthCode)
{
	if (pApp != NULL)
	{
		pApp->m_TradeChannel.SetAuthenticateInfo(szAppID, szAuthCode);
	}
}

CW_DLL_API void __cdecl PandoraAppRun(cwPandoraUIApp* pApp, const char* pszMdFront, const char* pszTradeFront)
{
	if (pApp != NULL)
	{
		pApp->Run(pszMdFront, pszTradeFront);
	}
}

#ifdef _MSC_VER
#pragma endregion
#endif


#ifdef _MSC_VER
#pragma region SetCallBack
#endif

CW_DLL_API void __cdecl SetPriceUpdateCallBack(cwPandoraUIApp* pApp, void* func)
{
	if (pApp != NULL)
	{
		pApp->m_cwPandoraUIStategy.m_fpPriceUpdateCallBackUI = func;
	}
}

CW_DLL_API void _cdecl SetOnRtnTradeCallBack(cwPandoraUIApp* pApp, void* func)
{
	if(pApp != NULL)
	{ 
		pApp->m_cwPandoraUIStategy.m_fpRtnTradeCallBackUI = func;
	}
}

CW_DLL_API void _cdecl SetOnRtnOrderCallBack(cwPandoraUIApp* pApp, void* func)
{
	if (pApp != NULL)
	{
		pApp->m_cwPandoraUIStategy.m_fpRtnOrderCallBackUI = func;
	}
}

#ifdef _MSC_VER
#pragma endregion
#endif

#ifdef _MSC_VER
#pragma region UIInterface
#endif

CW_DLL_API cwFtdcACCOUNTFIELD * __cdecl GetAccount(cwPandoraUIApp* pApp)
{
	if (pApp != NULL)
	{
		pApp->GetUIAccount();

		return pApp->m_pUIAccount.get();
	}
	return NULL;
}

#ifdef _MSC_VER
#pragma endregion
#endif