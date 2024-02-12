#pragma once

#include "core/config/engine.h"
#include "DTDAnalytics/DTDAnalytics-Swift.h"

@interface IOSIdentifiersListener : NSObject<DTDIdentifiersListener> {
    const Callable *onResult;    
}

-(id) initWithDelegate:(const Callable *) delegate;

@end