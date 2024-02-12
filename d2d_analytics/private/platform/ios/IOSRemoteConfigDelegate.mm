// Copyright (c) devtodev. All rights reserved.

#include "IOSRemoteConfigDelegate.h"
#include "IOSConverter.h"
#include "../../../DTDRemoteConfigReceiveResult.h"
#include "../../../DTDRemoteConfigChangeResult.h"

@implementation IOSRemoteConfigDelegate

+ (IOSRemoteConfigDelegate *) shared {
    static IOSRemoteConfigDelegate *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[IOSRemoteConfigDelegate alloc] init];
    });

    return sharedInstance;
}

- (void)subscribeConfigChange:(const Callable*) onRemoteConfigChangeCallback
	withConfigPrepareToChange:(const Callable *) onRemoteConfigPrepareToChangeCallback
	withConfigReceive:(const Callable *) onRemoteConfigReceiveCallback
{
	onRemoteConfigChange = onRemoteConfigChangeCallback;
	onRemoteConfigPrepareToChange = onRemoteConfigPrepareToChangeCallback;
	onRemoteConfigReceive = onRemoteConfigReceiveCallback;
}

- (void)onChangedResult:(enum DTDRemoteConfigChangeResult)result error:(NSError * _Nullable)error {
	NSString *exception = [error localizedDescription];
    String gd_Error = IOSConverter::Convert(exception);

	int32_t gd_Result = 0;
    switch (result) {
        case DTDRemoteConfigChangeResultFailure:
			gd_Result = 0;
            break;

        case DTDRemoteConfigChangeResultSuccess:
			gd_Result = 1;
            break;
    }

    Variant responceError = Variant(gd_Error);
    Variant responce = Variant(gd_Result);
	const Variant *args[2] = { &responce, &responceError };
    Variant returnValue;
    Callable::CallError callableError;
    onRemoteConfigChange->callp(args, 2, returnValue, callableError);
    if (callableError.error != Callable::CallError::CALL_OK) {
       	print_line("Call inposible");
    }
}

- (void)onPrepareToChange {
    Variant returnValue;
    Callable::CallError error;
    onRemoteConfigPrepareToChange->callp(nullptr, 0, returnValue, error);
    if (error.error != Callable::CallError::CALL_OK) {
       	print_line("Call inposible");
    }
}

- (void)onReceivedResult:(DTDRemoteConfigReceiveResult) result {
	int32_t gd_Result = 0;
    switch (result) {
        case DTDRemoteConfigReceiveResultFailure:
			gd_Result = 0;
            break;

        case DTDRemoteConfigReceiveResultSuccess:
			gd_Result = 1;
            break;

        case DTDRemoteConfigReceiveResultEmpty:
			gd_Result = 2;
            break;
    }

    Variant responce = Variant(gd_Result);
	const Variant *args[1] = { &responce };

    Variant returnValue;
    Callable::CallError error;
    onRemoteConfigReceive->callp(args, 1, returnValue, error);
    if (error.error != Callable::CallError::CALL_OK) {
       	print_line("Call inposible");
    }
}

@end