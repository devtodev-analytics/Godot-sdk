#include "core/string/print_string.h"
#include "AndroidAnalytics.h"
#include "AndroidConverter.h"

const String pluginName = "Analytics";
const String message = pluginName + " plugin is not found";

    // common signals
const String signal_deviceId = "signal_deviceId";
const String signal_sdkVersion = "signal_sdkVersion";
const String signal_trackingAvailability = "signal_trackingAvailability";
const String signal_userId = "signal_userId";
const String signal_currentLevel = "signal_currentLevel";
const String signal_initializationComplete = "signal_initializationComplete";
const String signal_devToDevIds = "signal_devToDevIds";

    // abTest signals
const String signal_onReceived = "signal_onReceived";
const String signal_onPrepareToChange = "signal_onPrepareToChange";
const String signal_onChanged = "signal_onChanged";

    // logs signal
const String signal_logs = "signal_logs";

AndroidAnalytics::AndroidAnalytics()
{
    Engine *engane = Engine::get_singleton();
	if (engane->has_singleton(pluginName)) {
		analyticsRef = engane->get_singleton_object(pluginName);
        analyticsRef->call("setSDKVersion", SDKConstants::Version);
	} else {
		print_line("Analytics plugin not found");
	}
}

AndroidAnalytics::~AndroidAnalytics(){ }

void AndroidAnalytics::GetDeviceId(const Callable &onResult) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    if (analyticsRef->is_connected(signal_deviceId, onResult) == false) {
        analyticsRef->connect(signal_deviceId, onResult);
    }

    analyticsRef->call("getDeviceId");
}

void AndroidAnalytics::GetSdkVersion(const Callable &onResult) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    if (analyticsRef->is_connected(signal_sdkVersion, onResult) == false) {
        analyticsRef->connect(signal_sdkVersion, onResult);
    }

    analyticsRef->call("getSdkVersion");
}
    
    // Tracking
void AndroidAnalytics::SetTrackingAvailability(const bool value) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    analyticsRef->call("setTrackingAvailability", value);
}

void AndroidAnalytics::GetTrackingAvailability(const Callable &onResult) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    if (analyticsRef->is_connected(signal_trackingAvailability, onResult) == false) {
        analyticsRef->connect(signal_trackingAvailability, onResult);
    }

    analyticsRef->call("getTrackingAvailability");

}

    // User custom identifier
void AndroidAnalytics::GetUserId(const Callable &onResult) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    if (analyticsRef->is_connected(signal_userId, onResult) == false) {
        analyticsRef->connect(signal_userId, onResult);
    }

    analyticsRef->call("getUserId");
}

void AndroidAnalytics::SetUserId(const String &userId) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    analyticsRef->call("setUserId", userId);
}

void AndroidAnalytics::ReplaceUserId(const String &fromUserId, const String &toUserId) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    analyticsRef->call("replaceUserId", fromUserId, toUserId);
}

    // User level
void AndroidAnalytics::GetCurrentLevel(const Callable &onResult) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    if (analyticsRef->is_connected(signal_currentLevel, onResult) == false) {
        analyticsRef->connect(signal_currentLevel, onResult);
    }

    analyticsRef->call("getCurrentLevel");
}

void AndroidAnalytics::SetCurrentLevel(const int32_t &level) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    analyticsRef->call("setCurrentLevel", level);
}

    // Prepare initialization
void AndroidAnalytics::SetLogLevel(GDDTDLogLevel::LogLevel logLevel) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    analyticsRef->call("setLogLevel", logLevel);
}

void AndroidAnalytics::CoppaControlEnable() {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    analyticsRef->call("coppaControlEnable");
}

void AndroidAnalytics::SetInitializationCompleteCallback(const Callable &callback) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    if (analyticsRef->is_connected(signal_initializationComplete, callback) == false) {
        analyticsRef->connect(signal_initializationComplete, callback);
    }

    analyticsRef->call("setInitializationCompleteCallback");
}

void AndroidAnalytics::SetIdentifiersCallback(const Callable &callback) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    if (analyticsRef->is_connected(signal_devToDevIds, callback) == false) {
        analyticsRef->connect(signal_devToDevIds, callback);
    }

    analyticsRef->call("setIdentifiersCallback");
}

void AndroidAnalytics::Initialize(const String &appKey)
{
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

	analyticsRef->call("initialization", appKey);
}

void AndroidAnalytics::InitializeWithConfig(const String &appKey, const Ref<GDDTDAnalyticsConfiguration> &configuration) {
	    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    Dictionary dict = AndroidConverter::Convert(configuration);
	analyticsRef->call("initializationWithConfig", appKey, dict);
}


void AndroidAnalytics::InitializeWithAbTest(const String &appKey, 
                          const Callable &onRemoteConfigChange,
                          const Callable &onRemoteConfigPrepareToChange, 
                          const Callable &onRemoteConfigReceive) {

    if (analyticsRef->is_connected(signal_onChanged, onRemoteConfigChange) == false) {
        analyticsRef->connect(signal_onChanged, onRemoteConfigChange);
    }
                           
    if (analyticsRef->is_connected(signal_onPrepareToChange, onRemoteConfigPrepareToChange) == false) {
        analyticsRef->connect(signal_onPrepareToChange, onRemoteConfigPrepareToChange);
    }

    if (analyticsRef->is_connected(signal_onReceived, onRemoteConfigReceive) == false) {
        analyticsRef->connect(signal_onReceived, onRemoteConfigReceive);
    }

    analyticsRef->call("initializeWithAbTest", appKey);

}

void AndroidAnalytics::InitializeWithConfigWithAbTest(const String &appKey, 
                                    const Ref<GDDTDAnalyticsConfiguration> &configuration, 
                                    const Callable &onRemoteConfigChange, 
                                    const Callable &onRemoteConfigPrepareToChange, 
                                    const Callable &onRemoteConfigReceive) {

    if (analyticsRef->is_connected(signal_onChanged, onRemoteConfigChange) == false) {
        analyticsRef->connect(signal_onChanged, onRemoteConfigChange);
    }
                           
    if (analyticsRef->is_connected(signal_onPrepareToChange, onRemoteConfigPrepareToChange) == false) {
        analyticsRef->connect(signal_onPrepareToChange, onRemoteConfigPrepareToChange);
    }

    if (analyticsRef->is_connected(signal_onReceived, onRemoteConfigReceive) == false) {
        analyticsRef->connect(signal_onReceived, onRemoteConfigReceive);
    }

    Dictionary dict = AndroidConverter::Convert(configuration);
    analyticsRef->call("initializeWithConfigWithAbTest", appKey, dict);
}

    // Events
void AndroidAnalytics::CustomEvent(const String& eventName) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    analyticsRef->call("customEvent", eventName);
}


void AndroidAnalytics::CustomEventWithParams(const String& eventName, const Ref<GDDTDCustomEventParams>& params) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }
    
    String json = AndroidConverter::Convert(params);
    analyticsRef->call("customEventWithParams", eventName, json);
}

void AndroidAnalytics::CurrencyAccrual(const String& currencyName, int32_t currencyAmount, const String& source, GDDTDAccrualType::AccrualType accrualType) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

     analyticsRef->call("currencyAccrual", currencyName, currencyAmount, source, accrualType);
}

void AndroidAnalytics::LevelUp(const int32_t &level) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    analyticsRef->call("levelUp", level);
}

void AndroidAnalytics::LevelUpWithBalance(const int32_t &level, const Ref<GDDTDInt64Resources>& balance) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    String json = AndroidConverter::Convert(balance);
    analyticsRef->call("levelUpWithBalance", level, json);
}

void AndroidAnalytics::CurrentBalance(const Ref<GDDTDInt64Resources>& balance) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    String json = AndroidConverter::Convert(balance);
    analyticsRef->call("currentBalance", json);
}

void AndroidAnalytics::VirtualCurrencyPayment(const String& purchaseId, const String& purchaseType, int32_t purchaseAmount, int32_t purchasePrice, const String& purchaseCurrency) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    analyticsRef->call("virtualCurrencyPayment", purchaseId, purchaseType, purchaseAmount, purchasePrice, purchaseCurrency);
}

void AndroidAnalytics::VirtualCurrencyPaymentWithResources(const String& purchaseId, const String& purchaseType, int32_t purchaseAmount, const Ref<GDDTDInt32Resources>& resources) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    Dictionary dictionary = AndroidConverter::Convert(resources);
    analyticsRef->call("virtualCurrencyPaymentWithResources", purchaseId, purchaseType, purchaseAmount, dictionary);
}

void AndroidAnalytics::AdImpression(const String& socialNetwork, float revenue, const String& placement, const String& unit) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    analyticsRef->call("adImpression", socialNetwork, revenue, placement, unit);
}

void AndroidAnalytics::RealCurrencyPayment(const String& orderId, float price, const String& productId, const String& currencyCode) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    analyticsRef->call("realCurrencyPayment", orderId, price, productId, currencyCode);
}

void AndroidAnalytics::Tutorial(int32_t step) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    analyticsRef->call("tutorial", step);
}

void AndroidAnalytics::StartProgressionEvent(const String& eventName) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    analyticsRef->call("startProgressionEvent", eventName);
}

void AndroidAnalytics::StartProgressionEventWithParams(const String& eventName, const Ref<GDDTDStartProgressionEventParams>& params) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    Dictionary dictionary = AndroidConverter::Convert(params);
    analyticsRef->call("startProgressionEventWithParams", eventName, dictionary);
}

void AndroidAnalytics::FinishProgressionEvent(const String& eventName) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    analyticsRef->call("finishProgressionEvent", eventName);
}

void AndroidAnalytics::FinishProgressionEventWithParams(const String& eventName, const Ref<GDDTDFinishProgressionEventParams>& params) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }
    
    Dictionary dictionary = AndroidConverter::Convert(params);
    analyticsRef->call("finishProgressionEventWithParams", eventName, dictionary);
}

void AndroidAnalytics::SocialNetworkConnect(Ref<GDDTDSocialNetwork> socialNetwork) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    String name = socialNetwork->GetName();
    analyticsRef->call("socialNetworkConnect", name);
}

void AndroidAnalytics::SocialNetworkPost(Ref<GDDTDSocialNetwork> socialNetwork, const String& reason) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    String name = socialNetwork->GetName();
    analyticsRef->call("socialNetworkPost", name, reason);
}

void AndroidAnalytics::Referrer(Ref<GDDTDReferralProperty> utmData) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    Dictionary dictionary = AndroidConverter::Convert(utmData);
    analyticsRef->call("referrer", dictionary);
}

void AndroidAnalytics::SendBufferedEvents() {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    analyticsRef->call("sendBufferedEvents");
}

void AndroidAnalytics::SubscribeLogger(const Callable &callback) {
    if (analyticsRef == nullptr) {
        print_line(message);
        return;
    }

    if (analyticsRef->is_connected(signal_logs, callback) == false) {
        analyticsRef->connect(signal_logs, callback);
    }

    analyticsRef->call("subscribeLogger");
}

