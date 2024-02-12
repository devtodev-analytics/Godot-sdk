#include "core/config/engine.h"
#include "DTDRemoteConfigValue.h"

void GDDTDRemoteConfigSource::_bind_methods() {
    BIND_ENUM_CONSTANT(Empty);
	BIND_ENUM_CONSTANT(Remote);
	BIND_ENUM_CONSTANT(Default);
}