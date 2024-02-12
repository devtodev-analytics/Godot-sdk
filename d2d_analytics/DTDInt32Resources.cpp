#include "core/config/engine.h"
#include "DTDInt32Resources.h"

void GDDTDInt32Resources::AddValue(const String &key, const int32_t &value) {
    values[key] = value;
}

HashMap<String, int32_t> GDDTDInt32Resources::getIntegerValues() const {
    return values;
}

void GDDTDInt32Resources::_bind_methods() {
    ClassDB::bind_method(D_METHOD("AddValue", "key", "value"), &GDDTDInt32Resources::AddValue);
}