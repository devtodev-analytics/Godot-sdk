#include "DTDStartProgressionEventParams.h"

void GDDTDStartProgressionEventParams::SetDifficulty(const int32_t &difficulty) {
    difficultyChanged = true;
    this->difficulty = difficulty;
}

int32_t GDDTDStartProgressionEventParams::GetDifficulty() const {
    return difficulty;
}

void GDDTDStartProgressionEventParams::SetSource(const String &source) {
    sourceChanged = true;
    this->source = source;
}

String GDDTDStartProgressionEventParams::GetSource() const {
    return source;
}

bool GDDTDStartProgressionEventParams::IsSourceChanged() const
{
    return sourceChanged;
}

bool GDDTDStartProgressionEventParams::IsDifficultyChanged() const
{
    return difficultyChanged;
}

void GDDTDStartProgressionEventParams::_bind_methods() {
    ClassDB::bind_method(D_METHOD("SetDifficulty", "difficulty"), &GDDTDStartProgressionEventParams::SetDifficulty);
    ClassDB::bind_method(D_METHOD("SetSource", "source"), &GDDTDStartProgressionEventParams::SetSource);
}
