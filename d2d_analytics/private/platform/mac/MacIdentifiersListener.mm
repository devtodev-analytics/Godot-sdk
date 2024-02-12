#include "MacIdentifiersListener.h"
#include "MacConverter.h"

@implementation MacIdentifiersListener

-(id) initWithDelegate:(const Callable *) delegate {
	onResult = delegate;
    return self;
}

- (void) didReceiveDevtodevIdWith:(int64_t) devtodevId {
	Variant responce = Variant(devtodevId);
	const Variant *args[1] = { &responce };

    Variant returnValue;
    Callable::CallError error;
    onResult->callp(args, 1, returnValue, error);
    if (error.error != Callable::CallError::CALL_OK) {
       	print_line("Call inposible");
    }
}

@end