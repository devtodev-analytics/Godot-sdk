#include "core/string/print_string.h"

#include "IOSAnalytics.h"
#include "DTDAnalytics/DTDAnalytics-Swift.h"
#include "IOSConverter.h"
#include "IOSIdentifiersListener.h"
#include "IOSRemoteConfigDelegate.h"


IOSAnalytics::IOSAnalytics() { }

IOSAnalytics::~IOSAnalytics() { }

void IOSAnalytics::InvokeCallback(const Variant **p_arguments, const int &argCount, const Callable &callback) {
	Variant returnValue;
    Callable::CallError error;
    callback.callp(p_arguments, argCount, returnValue, error);
    if (error.error != Callable::CallError::CALL_OK) {
       	print_line("Call inposible");
    }
}

void IOSAnalytics::GetDeviceId(const Callable &onResult) {
	[::DTDAnalytics deviceIdHandler:^(NSString* value) {
		String result = IOSConverter::Convert(value);
		Variant responce = Variant(result);
		const Variant *args[1] = { &responce };
        InvokeCallback(args, 1, onResult);
    }];
}

void IOSAnalytics::GetSdkVersion(const Callable &onResult) {
	[::DTDAnalytics sdkVersionHandler:^(NSString* value) {
        String result = IOSConverter::Convert(value);
		Variant responce = Variant(result);
		const Variant *args[1] = { &responce };
        InvokeCallback(args, 1, onResult);
    }];
}

// Tracking
void IOSAnalytics::SetTrackingAvailability(const bool value) {
    [::DTDAnalytics trackingAvailability:IOSConverter::ConvertToObjC(value)];
}

void IOSAnalytics::GetTrackingAvailability(const Callable &onResult) {
    [::DTDAnalytics trackingAvailabilityHandler:^(BOOL value) {
        bool result = IOSConverter::ConvertToCpp(value);
		Variant responce = Variant(result);
		const Variant *args[1] = { &responce };
        InvokeCallback(args, 1, onResult);
    }];
}


// User custom identifier
void IOSAnalytics::GetUserId(const Callable &onResult) {
    [::DTDAnalytics userIdHandler:^(NSString* value) {
        String result = IOSConverter::Convert(value);
		Variant responce = Variant(result);
		const Variant *args[1] = { &responce };
        InvokeCallback(args, 1, onResult);
    }];
}

void IOSAnalytics::SetUserId(const String &userId) {
    [::DTDAnalytics userId:IOSConverter::Convert(userId)];
}

void IOSAnalytics::ReplaceUserId(const String &fromUserId, const String &toUserId) {
    [::DTDAnalytics replaceFromUserId:IOSConverter::Convert(fromUserId) toUserId:IOSConverter::Convert(toUserId)];
}


// User level
void IOSAnalytics::GetCurrentLevel(const Callable &onResult) {
    [::DTDAnalytics currentLevelHandler:^(NSInteger value) {
        int64_t result = IOSConverter::ConvertToInt64(value);
		Variant responce = Variant(result);
		const Variant *args[1] = { &responce };
        InvokeCallback(args, 1, onResult);
    }];
}

void IOSAnalytics::SetCurrentLevel(const int32_t &level) {
    [::DTDAnalytics currentLevel:IOSConverter::ConvertInt32(level)];
}


// Prepare initialization
void IOSAnalytics::SetLogLevel(GDDTDLogLevel::LogLevel logLevel) {
    [::DTDAnalytics setLogLevel:IOSConverter::Convert(logLevel)];
}

void IOSAnalytics::CoppaControlEnable() {
    [::DTDAnalytics coppaControlEnable];
}

void IOSAnalytics::SetInitializationCompleteCallback(const Callable &callback) {
    [::DTDAnalytics setInitializationCompleteCallback:^{
		InvokeCallback(nullptr, 0, callback);
	}];
}

void IOSAnalytics::SetIdentifiersCallback(const Callable &callback) {
    [::DTDAnalytics setIdentifiersListenerWithListener:[[IOSIdentifiersListener alloc] initWithDelegate:&callback]];
}

void IOSAnalytics::Initialize(const String &appKey)
{
	const auto ocs_appKey = IOSConverter::Convert(appKey);
	[::DTDAnalytics applicationKey:ocs_appKey];
}

void IOSAnalytics::InitializeWithConfig(const String &appKey, const Ref<GDDTDAnalyticsConfiguration> &configuration) {
	const auto oco_config = IOSConverter::Convert(configuration);
	const auto ocs_appKey = IOSConverter::Convert(appKey);
	[::DTDAnalytics applicationKey:ocs_appKey configuration:oco_config];
}

void IOSAnalytics::InitializeWithAbTest(const String &appKey, 
                                        const Callable &onRemoteConfigChange, 
                                        const Callable &onRemoteConfigPrepareToChange, 
                                        const Callable &onRemoteConfigReceive) {
    IOSRemoteConfigDelegate *listener = [IOSRemoteConfigDelegate shared];
	[listener subscribeConfigChange: &onRemoteConfigChange
		  withConfigPrepareToChange: &onRemoteConfigPrepareToChange
		  	      withConfigReceive: &onRemoteConfigReceive];
	[::DTDAnalytics applicationKey:IOSConverter::Convert(appKey) abConfigListener:listener];
}

void IOSAnalytics::InitializeWithConfigWithAbTest(const String &appKey, 
                                                const Ref<GDDTDAnalyticsConfiguration> &configuration, 
                                                const Callable &onRemoteConfigChange, 
                                                const Callable &onRemoteConfigPrepareToChange, 
                                                const Callable &onRemoteConfigReceive) {
    const auto oco_config = IOSConverter::Convert(configuration);
    IOSRemoteConfigDelegate *listener = [IOSRemoteConfigDelegate shared];
	[listener subscribeConfigChange: &onRemoteConfigChange 
		  withConfigPrepareToChange: &onRemoteConfigPrepareToChange 
		  	      withConfigReceive: &onRemoteConfigReceive];
	[::DTDAnalytics applicationKey:IOSConverter::Convert(appKey) configuration:oco_config abConfigListener: listener];
}

// Events

void IOSAnalytics::CustomEvent(const String& eventName) {
    [::DTDAnalytics customEvent:IOSConverter::Convert(eventName)];
}

void IOSAnalytics::CustomEventWithParams(const String& eventName, const Ref<GDDTDCustomEventParams>& params) {
    const auto ocs_eventName = IOSConverter::Convert(eventName);
	const auto oco_params = IOSConverter::Convert(params);
	[::DTDAnalytics customEvent:ocs_eventName withParameters:oco_params];
}

void IOSAnalytics::CurrencyAccrual(const String& currencyName, int32_t currencyAmount, const String& source, GDDTDAccrualType::AccrualType accrualType) {
    [::DTDAnalytics currencyName:IOSConverter::Convert(currencyName) 
                    currencyAmount:IOSConverter::ConvertInt32(currencyAmount) 
                    source:IOSConverter::Convert(source) 
                    accrualType:IOSConverter::Convert(accrualType)];
}

void IOSAnalytics::LevelUp(const int32_t &level)
{
    [::DTDAnalytics levelUp:IOSConverter::ConvertInt32(level)];
}

void IOSAnalytics::LevelUpWithBalance(const int32_t &level, const Ref<GDDTDInt64Resources>& balance)
{
    const auto ocp_level = IOSConverter::ConvertInt32(level);
	const auto oco_balance = IOSConverter::Convert(balance);
	[::DTDAnalytics levelUp:ocp_level withBalances:oco_balance];
}

void IOSAnalytics::CurrentBalance(const Ref<GDDTDInt64Resources>& balance) {
    const auto oco_balance = IOSConverter::Convert(balance);
	[::DTDAnalytics currentBalanceWithBalance:oco_balance];
}

void IOSAnalytics::VirtualCurrencyPayment(const String& purchaseId, const String& purchaseType, int32_t purchaseAmount, int32_t purchasePrice, const String& purchaseCurrency) {
    const auto ocs_purchaseId = IOSConverter::Convert(purchaseId);
	const auto ocs_purchaseType = IOSConverter::Convert(purchaseType);
	const auto ocp_purchaseAmount = IOSConverter::ConvertInt32(purchaseAmount);
    const auto ocs_purchasePrice = IOSConverter::ConvertInt32(purchasePrice);
	const auto ocs_purchaseCurrency = IOSConverter::Convert(purchaseCurrency);
    [::DTDAnalytics virtualCurrencyPaymentWithPurchaseId:ocs_purchaseId 
                                            purchaseType:ocs_purchaseType 
                                            purchaseAmount:ocp_purchaseAmount 
                                            purchasePrice:ocs_purchasePrice
                                            purchaseCurrency:ocs_purchaseCurrency];
}

void IOSAnalytics::VirtualCurrencyPaymentWithResources(const String& purchaseId, const String& purchaseType, int32_t purchaseAmount, const Ref<GDDTDInt32Resources>& resources) {
    const auto ocs_purchaseId = IOSConverter::Convert(purchaseId);
	const auto ocs_purchaseType = IOSConverter::Convert(purchaseType);
	const auto ocp_purchaseAmount = IOSConverter::ConvertInt32(purchaseAmount);
	const auto oco_resources = IOSConverter::Convert(resources);
	[::DTDAnalytics virtualCurrencyPaymentWithPurchaseId:ocs_purchaseId 
                    purchaseType:ocs_purchaseType 
                    purchaseAmount:ocp_purchaseAmount 
                    resources:oco_resources];
}

void IOSAnalytics::AdImpression(const String& socialNetwork, float revenue, const String& placement, const String& unit) {
    const auto ocs_socialNetwork = IOSConverter::Convert(socialNetwork);
	const auto ocp_revenue = (double)revenue;
	const auto ocs_placement = IOSConverter::Convert(placement);
	const auto ocs_unit = IOSConverter::Convert(unit);
	[::DTDAnalytics adImpressionWithNetwork:ocs_socialNetwork 
                    revenue:ocp_revenue 
                    placement:ocs_placement
                     unit:ocs_unit];
}

void IOSAnalytics::RealCurrencyPayment(const String& orderId, float price, const String& productId, const String& currencyCode) {
    [::DTDAnalytics realCurrencyPaymentWithOrderId:IOSConverter::Convert(orderId) 
                    price:(double)price 
                    productId:IOSConverter::Convert(productId) 
                    currencyCode:IOSConverter::Convert(currencyCode)];
}

void IOSAnalytics::Tutorial(int32_t step) {
    [::DTDAnalytics tutorialStep:IOSConverter::ConvertInt32(step)];
}

void IOSAnalytics::StartProgressionEvent(const String& eventName) {
    [::DTDAnalytics startProgressionEvent:IOSConverter::Convert(eventName)];
}

void IOSAnalytics::StartProgressionEventWithParams(const String& eventName, const Ref<GDDTDStartProgressionEventParams>& params) {
    const auto ocs_eventName = IOSConverter::Convert(eventName);
	const auto oco_params = IOSConverter::Convert(params);
	[::DTDAnalytics startProgressionEvent:ocs_eventName withParameters:oco_params];
}

void IOSAnalytics::FinishProgressionEvent(const String& eventName) {
	[::DTDAnalytics finishProgressionEvent:IOSConverter::Convert(eventName)];
}

void IOSAnalytics::FinishProgressionEventWithParams(const String& eventName, const Ref<GDDTDFinishProgressionEventParams>& params) {
	const auto ocs_eventName = IOSConverter::Convert(eventName);
	const auto oco_params = IOSConverter::Convert(params);
	[::DTDAnalytics finishProgressionEvent:ocs_eventName withParameters:oco_params];
}

void IOSAnalytics::SocialNetworkConnect(Ref<GDDTDSocialNetwork> socialNetwork) {
    DTDSocialNetwork *network = [[DTDSocialNetwork alloc] initWithName:IOSConverter::Convert(socialNetwork->GetName())];
	[::DTDAnalytics socialNetworkConnect:network];
}

void IOSAnalytics::SocialNetworkPost(Ref<GDDTDSocialNetwork> socialNetwork, const String& reason) {
    DTDSocialNetwork *network = [[DTDSocialNetwork alloc] initWithName:IOSConverter::Convert(socialNetwork->GetName())];
	const auto ocs_reason = IOSConverter::Convert(reason);
	[::DTDAnalytics socialNetworkPost:network withReason:ocs_reason];
}

void IOSAnalytics::Referrer(Ref<GDDTDReferralProperty> utmData) {
    const auto oco_utmData = IOSConverter::Convert(utmData);
	[::DTDAnalytics referrer:oco_utmData];
}

void IOSAnalytics::SendBufferedEvents() {
    [::DTDAnalytics sendBufferedEvents];
}