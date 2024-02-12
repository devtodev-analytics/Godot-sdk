#pragma once

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"

class GDDTDInt32Resources: public RefCounted 
{
    GDCLASS(GDDTDInt32Resources, RefCounted);

private:
    HashMap<String, int32_t> values;
    
protected:
    static void _bind_methods();

public:
    void AddValue(const String &key, const int32_t &value);
    HashMap<String, int32_t> getIntegerValues() const;
};