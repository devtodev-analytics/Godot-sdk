#include "core/string/print_string.h"

#include "MacAnalytics.h"
#include "DTDAnalytics/DTDAnalytics-Swift.h"
#include "MacConverter.h"
#include "MacIdentifiersListener.h"
#include "MacRemoteConfigDelegate.h"


MacAnalytics::MacAnalytics() {

    #ifdef TOOLS_ENABLED
    [::DTDEngineWrapper enableEditorMode];
    #endif

    [::DTDEngineWrapper setSDKVersionWithVersion:MacConverter::Convert(SDKConstants::Version)];
	[::DTDEngineWrapper setEngineLoggerMessageClosure:^(DTDLogLevel logLevel, NSString* message) {
		const auto gd_message = MacConverter::Convert(message); 
		print_line(gd_message);
	}];
}

MacAnalytics::~MacAnalytics() { }

void MacAnalytics::InvokeCallback(const Variant **p_arguments, const int &argCount, const Callable &callback) {
	Variant returnValue;
    Callable::CallError error;
    callback.callp(p_arguments, argCount, returnValue, error);
    if (error.error != Callable::CallError::CALL_OK) {
       	print_line("Call inposible");
    }
}

void MacAnalytics::GetDeviceId(const Callable &onResult) {
	[::DTDAnalytics deviceIdHandler:^(NSString* value) {
		String result = MacConverter::Convert(value);
		Variant responce = Variant(result);
		const Variant *args[1] = { &responce };
        InvokeCallback(args, 1, onResult);
    }];
}

void MacAnalytics::GetSdkVersion(const Callable &onResult) {
	[::DTDAnalytics sdkVersionHandler:^(NSString* value) {
        String result = MacConverter::Convert(value);
		Variant responce = Variant(result);
		const Variant *args[1] = { &responce };
        InvokeCallback(args, 1, onResult);
    }];
}

// Tracking
void MacAnalytics::SetTrackingAvailability(const bool value) {
    [::DTDAnalytics trackingAvailability:MacConverter::ConvertToObjC(value)];
}

void MacAnalytics::GetTrackingAvailability(const Callable &onResult) {
    [::DTDAnalytics trackingAvailabilityHandler:^(BOOL value) {
        bool result = MacConverter::ConvertToCpp(value);
		Variant responce = Variant(result);
		const Variant *args[1] = { &responce };
        InvokeCallback(args, 1, onResult);
    }];
}


// User custom identifier
void MacAnalytics::GetUserId(const Callable &onResult) {
    [::DTDAnalytics userIdHandler:^(NSString* value) {
        String result = MacConverter::Convert(value);
		Variant responce = Variant(result);
		const Variant *args[1] = { &responce };
        InvokeCallback(args, 1, onResult);
    }];
}

void MacAnalytics::SetUserId(const String &userId) {
    [::DTDAnalytics userId:MacConverter::Convert(userId)];
}

void MacAnalytics::ReplaceUserId(const String &fromUserId, const String &toUserId) {
    [::DTDAnalytics replaceFromUserId:MacConverter::Convert(fromUserId) toUserId:MacConverter::Convert(toUserId)];
}


// User level
void MacAnalytics::GetCurrentLevel(const Callable &onResult) {
    [::DTDAnalytics currentLevelHandler:^(NSInteger value) {
        int64_t result = MacConverter::ConvertToInt64(value);
		Variant responce = Variant(result);
		const Variant *args[1] = { &responce };
        InvokeCallback(args, 1, onResult);
    }];
}

void MacAnalytics::SetCurrentLevel(const int32_t &level) {
    [::DTDAnalytics currentLevel:MacConverter::ConvertInt32(level)];
}


// Prepare initialization
void MacAnalytics::SetLogLevel(GDDTDLogLevel::LogLevel logLevel) {
    [::DTDAnalytics setLogLevel:MacConverter::Convert(logLevel)];
}

void MacAnalytics::CoppaControlEnable() {
    [::DTDAnalytics coppaControlEnable];
}

void MacAnalytics::SetInitializationCompleteCallback(const Callable &callback) {
    [::DTDAnalytics setInitializationCompleteCallback:^{
		InvokeCallback(nullptr, 0, callback);
	}];
}

void MacAnalytics::SetIdentifiersCallback(const Callable &callback) {
    [::DTDAnalytics setIdentifiersListenerWithListener:[[MacIdentifiersListener alloc] initWithDelegate:&callback]];
}

void MacAnalytics::Initialize(const String &appKey)
{
	const auto ocs_appKey = MacConverter::Convert(appKey);
	[::DTDAnalytics applicationKey:ocs_appKey];
}

void MacAnalytics::InitializeWithConfig(const String &appKey, const Ref<GDDTDAnalyticsConfiguration> &configuration) {
	const auto oco_config = MacConverter::Convert(configuration);
	const auto ocs_appKey = MacConverter::Convert(appKey);
	[::DTDAnalytics applicationKey:ocs_appKey configuration:oco_config];
}

void MacAnalytics::InitializeWithAbTest(const String &appKey, 
                                        const Callable &onRemoteConfigChange, 
                                        const Callable &onRemoteConfigPrepareToChange, 
                                        const Callable &onRemoteConfigReceive) {
    MacRemoteConfigDelegate *listener = [MacRemoteConfigDelegate shared];
	[listener subscribeConfigChange: &onRemoteConfigChange
		  withConfigPrepareToChange: &onRemoteConfigPrepareToChange
		  	      withConfigReceive: &onRemoteConfigReceive];
	[::DTDAnalytics applicationKey:MacConverter::Convert(appKey) abConfigListener:listener];
}

void MacAnalytics::InitializeWithConfigWithAbTest(const String &appKey, 
                                                const Ref<GDDTDAnalyticsConfiguration> &configuration, 
                                                const Callable &onRemoteConfigChange, 
                                                const Callable &onRemoteConfigPrepareToChange, 
                                                const Callable &onRemoteConfigReceive) {
    const auto oco_config = MacConverter::Convert(configuration);
    MacRemoteConfigDelegate *listener = [MacRemoteConfigDelegate shared];
	[listener subscribeConfigChange: &onRemoteConfigChange 
		  withConfigPrepareToChange: &onRemoteConfigPrepareToChange 
		  	      withConfigReceive: &onRemoteConfigReceive];
	[::DTDAnalytics applicationKey:MacConverter::Convert(appKey) configuration:oco_config abConfigListener: listener];
}

// Events

void MacAnalytics::CustomEvent(const String& eventName) {
    [::DTDAnalytics customEvent:MacConverter::Convert(eventName)];
}

void MacAnalytics::CustomEventWithParams(const String& eventName, const Ref<GDDTDCustomEventParams>& params) {
    const auto ocs_eventName = MacConverter::Convert(eventName);
	const auto oco_params = MacConverter::Convert(params);
	[::DTDAnalytics customEvent:ocs_eventName withParameters:oco_params];
}

void MacAnalytics::CurrencyAccrual(const String& currencyName, int32_t currencyAmount, const String& source, GDDTDAccrualType::AccrualType accrualType) {
    [::DTDAnalytics currencyName:MacConverter::Convert(currencyName) 
                    currencyAmount:MacConverter::ConvertInt32(currencyAmount) 
                    source:MacConverter::Convert(source) 
                    accrualType:MacConverter::Convert(accrualType)];
}

void MacAnalytics::LevelUp(const int32_t &level)
{
    [::DTDAnalytics levelUp:MacConverter::ConvertInt32(level)];
}

void MacAnalytics::LevelUpWithBalance(const int32_t &level, const Ref<GDDTDInt64Resources>& balance)
{
    const auto ocp_level = MacConverter::ConvertInt32(level);
	const auto oco_balance = MacConverter::Convert(balance);
	[::DTDAnalytics levelUp:ocp_level withBalances:oco_balance];
}

void MacAnalytics::CurrentBalance(const Ref<GDDTDInt64Resources>& balance) {
    const auto oco_balance = MacConverter::Convert(balance);
	[::DTDAnalytics currentBalanceWithBalance:oco_balance];
}

void MacAnalytics::VirtualCurrencyPayment(const String& purchaseId, const String& purchaseType, int32_t purchaseAmount, int32_t purchasePrice, const String& purchaseCurrency) {
    const auto ocs_purchaseId = MacConverter::Convert(purchaseId);
	const auto ocs_purchaseType = MacConverter::Convert(purchaseType);
	const auto ocp_purchaseAmount = MacConverter::ConvertInt32(purchaseAmount);
    const auto ocs_purchasePrice = MacConverter::ConvertInt32(purchasePrice);
	const auto ocs_purchaseCurrency = MacConverter::Convert(purchaseCurrency);
    [::DTDAnalytics virtualCurrencyPaymentWithPurchaseId:ocs_purchaseId 
                                            purchaseType:ocs_purchaseType 
                                            purchaseAmount:ocp_purchaseAmount 
                                            purchasePrice:ocs_purchasePrice
                                            purchaseCurrency:ocs_purchaseCurrency];
}

void MacAnalytics::VirtualCurrencyPaymentWithResources(const String& purchaseId, const String& purchaseType, int32_t purchaseAmount, const Ref<GDDTDInt32Resources>& resources) {
    const auto ocs_purchaseId = MacConverter::Convert(purchaseId);
	const auto ocs_purchaseType = MacConverter::Convert(purchaseType);
	const auto ocp_purchaseAmount = MacConverter::ConvertInt32(purchaseAmount);
	const auto oco_resources = MacConverter::Convert(resources);
	[::DTDAnalytics virtualCurrencyPaymentWithPurchaseId:ocs_purchaseId 
                    purchaseType:ocs_purchaseType 
                    purchaseAmount:ocp_purchaseAmount 
                    resources:oco_resources];
}

void MacAnalytics::AdImpression(const String& socialNetwork, float revenue, const String& placement, const String& unit) {
    const auto ocs_socialNetwork = MacConverter::Convert(socialNetwork);
	const auto ocp_revenue = (double)revenue;
	const auto ocs_placement = MacConverter::Convert(placement);
	const auto ocs_unit = MacConverter::Convert(unit);
	[::DTDAnalytics adImpressionWithNetwork:ocs_socialNetwork 
                    revenue:ocp_revenue 
                    placement:ocs_placement
                     unit:ocs_unit];
}

void MacAnalytics::RealCurrencyPayment(const String& orderId, float price, const String& productId, const String& currencyCode) {
    [::DTDAnalytics realCurrencyPaymentWithOrderId:MacConverter::Convert(orderId) 
                    price:(double)price 
                    productId:MacConverter::Convert(productId) 
                    currencyCode:MacConverter::Convert(currencyCode)];
}

void MacAnalytics::Tutorial(int32_t step) {
    [::DTDAnalytics tutorialStep:MacConverter::ConvertInt32(step)];
}

void MacAnalytics::StartProgressionEvent(const String& eventName) {
    [::DTDAnalytics startProgressionEvent:MacConverter::Convert(eventName)];
}

void MacAnalytics::StartProgressionEventWithParams(const String& eventName, const Ref<GDDTDStartProgressionEventParams>& params) {
    const auto ocs_eventName = MacConverter::Convert(eventName);
	const auto oco_params = MacConverter::Convert(params);
	[::DTDAnalytics startProgressionEvent:ocs_eventName withParameters:oco_params];
}

void MacAnalytics::FinishProgressionEvent(const String& eventName) {
	[::DTDAnalytics finishProgressionEvent:MacConverter::Convert(eventName)];
}

void MacAnalytics::FinishProgressionEventWithParams(const String& eventName, const Ref<GDDTDFinishProgressionEventParams>& params) {
	const auto ocs_eventName = MacConverter::Convert(eventName);
	const auto oco_params = MacConverter::Convert(params);
	[::DTDAnalytics finishProgressionEvent:ocs_eventName withParameters:oco_params];
}

void MacAnalytics::SocialNetworkConnect(Ref<GDDTDSocialNetwork> socialNetwork) {
    DTDSocialNetwork *network = [[DTDSocialNetwork alloc] initWithName:MacConverter::Convert(socialNetwork->GetName())];
	[::DTDAnalytics socialNetworkConnect:network];
}

void MacAnalytics::SocialNetworkPost(Ref<GDDTDSocialNetwork> socialNetwork, const String& reason) {
    DTDSocialNetwork *network = [[DTDSocialNetwork alloc] initWithName:MacConverter::Convert(socialNetwork->GetName())];
	const auto ocs_reason = MacConverter::Convert(reason);
	[::DTDAnalytics socialNetworkPost:network withReason:ocs_reason];
}

void MacAnalytics::Referrer(Ref<GDDTDReferralProperty> utmData) {
    const auto oco_utmData = MacConverter::Convert(utmData);
	[::DTDAnalytics referrer:oco_utmData];
}

void MacAnalytics::SendBufferedEvents() {
    [::DTDAnalytics sendBufferedEvents];
}

void MacAnalytics::SubscribeLogger(const Callable &callback) {
    [::DTDEngineWrapper setEngineLoggerMessageClosure:^(DTDLogLevel logLevel, NSString* message) {
		const auto gd_message = MacConverter::Convert(message); 
	    Variant responce = Variant(gd_message);
	    const Variant *args[1] = { &responce };
        InvokeCallback(args, 1, callback);
	}];
}