#pragma once

#include "../PlatformAnalytics.h"
#include "core/string/ustring.h"

class IOSAnalytics: public PlatformAnalytics
{
private:
    void InvokeCallback(const Variant **p_arguments, const int &argCount, const Callable &callback);
public:
    IOSAnalytics();
    ~IOSAnalytics();

    void GetDeviceId(const Callable &onResult);
    void GetSdkVersion(const Callable &onResult);
    
    // Tracking
    void SetTrackingAvailability(const bool value);
    void GetTrackingAvailability(const Callable &onResult);

    // User custom identifier
    void GetUserId(const Callable &onResult);
    void SetUserId(const String &userId);
    void ReplaceUserId(const String &fromUserId, const String &toUserId);

    // User level
    void GetCurrentLevel(const Callable &onResult);
    void SetCurrentLevel(const int32_t &level);

    // Prepare initialization
    void SetLogLevel(GDDTDLogLevel::LogLevel logLevel);
    void CoppaControlEnable();
    void SetInitializationCompleteCallback(const Callable &callback);
    void SetIdentifiersCallback(const Callable &callback);

    void Initialize(const String &appKey);
    void InitializeWithConfig(const String &appKey, const Ref<GDDTDAnalyticsConfiguration> &configuration);
    void InitializeWithAbTest(const String &appKey, 
                            const Callable &onRemoteConfigChange, 
                            const Callable &onRemoteConfigPrepareToChange, 
                            const Callable &onRemoteConfigReceive);
    void InitializeWithConfigWithAbTest(const String &appKey, 
                                    const Ref<GDDTDAnalyticsConfiguration> &configuration, 
                                    const Callable &onRemoteConfigChange, 
                                    const Callable &onRemoteConfigPrepareToChange, 
                                    const Callable &onRemoteConfigReceive);

    // Events
    void CustomEvent(const String& eventName);
	void CustomEventWithParams(const String& eventName, const Ref<GDDTDCustomEventParams>& params);
    void CurrencyAccrual(const String& currencyName, int32_t currencyAmount, const String& source, GDDTDAccrualType::AccrualType accrualType);
    void LevelUp(const int32_t &level);
    void LevelUpWithBalance(const int32_t &level, const Ref<GDDTDInt64Resources>& balance);
    void CurrentBalance(const Ref<GDDTDInt64Resources>& balance);
    void VirtualCurrencyPayment(const String& purchaseId, const String& purchaseType, int32_t purchaseAmount, int32_t purchasePrice, const String& purchaseCurrency);
	void VirtualCurrencyPaymentWithResources(const String& purchaseId, const String& purchaseType, int32_t purchaseAmount, const Ref<GDDTDInt32Resources>& resources);
    void AdImpression(const String& socialNetwork, float revenue, const String& placement, const String& unit);
    void RealCurrencyPayment(const String& orderId, float price, const String& productId, const String& currencyCode);
    void Tutorial(int32_t step);
    void StartProgressionEvent(const String& eventName);
    void StartProgressionEventWithParams(const String& eventName, const Ref<GDDTDStartProgressionEventParams>& params);
    void FinishProgressionEvent(const String& eventName);
    void FinishProgressionEventWithParams(const String& eventName, const Ref<GDDTDFinishProgressionEventParams>& params);
    void SocialNetworkConnect(Ref<GDDTDSocialNetwork> socialNetwork);
	void SocialNetworkPost(Ref<GDDTDSocialNetwork> socialNetwork, const String& reason);
    void Referrer(Ref<GDDTDReferralProperty> utmData);
    void SendBufferedEvents();
};
