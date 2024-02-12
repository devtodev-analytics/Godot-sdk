#pragma once

#include "core/config/engine.h"
#include "DTDAnalytics/DTDAnalytics-Swift.h"

@interface IOSRemoteConfigDelegate : NSObject <DTDRemoteConfigListener>
{
	const Callable *onRemoteConfigChange;
	const Callable *onRemoteConfigPrepareToChange;
	const Callable *onRemoteConfigReceive;
}

+ (IOSRemoteConfigDelegate *) shared;
- (void) subscribeConfigChange:(const Callable*) onRemoteConfigChangeCallback
	withConfigPrepareToChange:(const Callable*) onRemoteConfigPrepareToChangeCallback
	withConfigReceive:(const Callable*) onRemoteConfigReceiveCallback;
@end