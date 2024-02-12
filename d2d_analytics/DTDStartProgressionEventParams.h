#pragma once

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"

class GDDTDStartProgressionEventParams: public RefCounted {
    GDCLASS(GDDTDStartProgressionEventParams, RefCounted);

private:
    bool sourceChanged;
    bool difficultyChanged;
	int32_t difficulty;
    String source;

protected:
    static void _bind_methods();

public:
    void SetDifficulty(const int32_t &difficulty);
    int32_t GetDifficulty() const;
    void SetSource(const String &source);
    String GetSource() const;
    bool IsSourceChanged() const;
    bool IsDifficultyChanged() const;
};