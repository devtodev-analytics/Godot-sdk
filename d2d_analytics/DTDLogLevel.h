#pragma once

#include "core/object/ref_counted.h"

class GDDTDLogLevel: public RefCounted 
{ 
    GDCLASS(GDDTDLogLevel, RefCounted);

    public:
        enum LogLevel
            {   
                Unknown = 0, 
                No = 1, 
                Error = 2,
                Warning = 3,
                Info = 4,
                Debug = 5
            };

    protected:        
        static void _bind_methods();
};

VARIANT_ENUM_CAST(GDDTDLogLevel::LogLevel);