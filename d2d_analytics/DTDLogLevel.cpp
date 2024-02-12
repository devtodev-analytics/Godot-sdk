#include "core/config/engine.h"

#include "DTDLogLevel.h"

void GDDTDLogLevel::_bind_methods() {
    BIND_ENUM_CONSTANT(Unknown);
	BIND_ENUM_CONSTANT(No);
	BIND_ENUM_CONSTANT(Error);
	BIND_ENUM_CONSTANT(Warning);
	BIND_ENUM_CONSTANT(Info);
    BIND_ENUM_CONSTANT(Debug);
}