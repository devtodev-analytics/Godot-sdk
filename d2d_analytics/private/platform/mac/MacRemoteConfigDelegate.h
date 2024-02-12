#pragma once

#include "core/config/engine.h"
#include "DTDAnalytics/DTDAnalytics-Swift.h"

@interface MacRemoteConfigDelegate : NSObject <DTDRemoteConfigListener>
{
	const Callable *onRemoteConfigChange;
	const Callable *onRemoteConfigPrepareToChange;
	const Callable *onRemoteConfigReceive;
}

+ (MacRemoteConfigDelegate *) shared;
- (void) subscribeConfigChange:(const Callable*) onRemoteConfigChangeCallback
	withConfigPrepareToChange:(const Callable*) onRemoteConfigPrepareToChangeCallback
	withConfigReceive:(const Callable*) onRemoteConfigReceiveCallback;
@end