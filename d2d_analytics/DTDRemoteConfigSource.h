#pragma once

#include "core/object/ref_counted.h"

class GDDTDRemoteConfigSource: public RefCounted 
{ 
    GDCLASS(GDDTDRemoteConfigSource, RefCounted);

    public:
        enum Source
            {   
                Empty = 0, 
                Remote = 1, 
                Default = 2
            };

    protected:        
        static void _bind_methods();
};

VARIANT_ENUM_CAST(GDDTDRemoteConfigSource::Source);