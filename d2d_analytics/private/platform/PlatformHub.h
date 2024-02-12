#pragma once

#include "core/config/engine.h"
#include "PlatformAnalytics.h"
#include "PlatformUserCard.h"
#include "PlatformRemoteConfig.h"

class PlatformHub
{
public:
	static PlatformHub& GetInstance();
	PlatformAnalytics* GetAnalytics();
	PlatformUserCard* GetUserCard();
	PlatformRemoteConfig* GetRemoteConfig();
	
private:
	PlatformHub();
	~PlatformHub();

	PlatformAnalytics* analytics;
	PlatformUserCard* userCard;
	PlatformRemoteConfig* remoteConfig;
};
