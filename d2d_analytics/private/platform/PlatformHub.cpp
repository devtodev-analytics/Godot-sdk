#include "PlatformHub.h"

#ifdef ANDROID_ENABLED
#include "android/AndroidAnalytics.h"
#include "android/AndroidUserCard.h"
#include "android/AndroidRemoteConfig.h"
#elif defined(MACOS_ENABLED)
#include "mac/MacAnalytics.h"
#include "mac/MacUserCard.h"
#include "mac/MacRemoteConfig.h"
#elif defined(IOS_ENABLED)
#include "ios/IOSAnalytics.h"
#include "ios/IOSUserCard.h"
#include "ios/IOSRemoteConfig.h"
#endif

PlatformHub& PlatformHub::GetInstance()
{
	static PlatformHub instance;
	return instance;
}

PlatformAnalytics* PlatformHub::GetAnalytics()
{
	return analytics;
}

PlatformUserCard* PlatformHub::GetUserCard()
{
	return userCard;
}

PlatformRemoteConfig* PlatformHub::GetRemoteConfig()
{
	return remoteConfig;
}

PlatformHub::PlatformHub()
{	
	print_line("PlatformHub");
#if ANDROID_ENABLED
	analytics = new AndroidAnalytics();
	userCard = new AndroidUserCard();
	remoteConfig = new AndroidRemoteConfig();
	return;
#elif defined(MACOS_ENABLED)
	analytics = new MacAnalytics();
	userCard = new MacUserCard();
	remoteConfig = new MacRemoteConfig();
	return;
#elif defined(IOS_ENABLED)
	analytics = new IOSAnalytics();
	userCard = new IOSUserCard();
	remoteConfig = new IOSRemoteConfig();
	return;
#endif
}

PlatformHub::~PlatformHub()
{
	delete analytics;
	delete userCard;
}