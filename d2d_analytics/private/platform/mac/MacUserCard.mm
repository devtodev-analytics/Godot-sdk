#include "core/string/print_string.h"

#include "MacUserCard.h"
#include "DTDAnalytics/DTDAnalytics-Swift.h"
#include "MacConverter.h"

MacUserCard::MacUserCard() { }

MacUserCard::~MacUserCard() { }

void MacUserCard::SetCheater(const bool &value) {
	[::DTDUserCard setCheater:MacConverter::ConvertToObjC(value)];
}

void MacUserCard::SetTester(const bool &value) {
	[::DTDUserCard setTester:MacConverter::ConvertToObjC(value)];
}

void MacUserCard::SetString(const String &key, const String &value) {
    [::DTDUserCard setString:MacConverter::Convert(key) value:MacConverter::Convert(value)];
}

void MacUserCard::TryGetString(const String &key, const Callable &callback) {
	[::DTDUserCard getValueWithKey:MacConverter::Convert(key) :^(id value) {
		bool isValid;
		String result;
		if ([value isKindOfClass:[NSString class]]) { 
			isValid = true;
			result = String([value UTF8String]);
		} else if (value && [value respondsToSelector:@selector(stringValue)]) {
			isValid = true;
			result = String([[value stringValue] UTF8String]);
        } else {
			isValid = false;
			result = String("");
		}
		
		const Variant isValidLocal = Variant(isValid);
		const Variant resultLocal = Variant(result);
		const Variant *args[2] = { &isValidLocal, &resultLocal };
		Variant returnValue;

    	Callable::CallError error;
    	callback.callp(args, 2, returnValue, error);
    	if (error.error != Callable::CallError::CALL_OK) {
       		print_line("Call inposible");
    	}
    }];
}

void MacUserCard::SetFloat(const String &key, const float &value) {
    [::DTDUserCard setDouble:MacConverter::Convert(key) value:(double)value];
}

void MacUserCard::TryGetFloat(const String &key, const Callable &callback) {
	[::DTDUserCard getValueWithKey:MacConverter::Convert(key) :^(id value) {
		bool isValid;
		float result;
		if (value && [value respondsToSelector:@selector(doubleValue)]) {
			isValid = true;
			result = [value doubleValue];
        } else {
			isValid = false;
			result = 0.0;
		}
		
		const Variant isValidLocal = Variant(isValid);
		const Variant resultLocal = Variant(result);
		const Variant *args[2] = { &isValidLocal, &resultLocal };
		Variant returnValue;

    	Callable::CallError error;
    	callback.callp(args, 2, returnValue, error);
    	if (error.error != Callable::CallError::CALL_OK) {
       		print_line("Call inposible");
    	}
    }];
}

void MacUserCard::SetInt(const String &key, const int64_t &value) {
    [::DTDUserCard setInt:MacConverter::Convert(key) value:MacConverter::ConvertInt64(value)];
}

void MacUserCard::TryGetInt(const String &key, const Callable &callback) {
	[::DTDUserCard getValueWithKey:MacConverter::Convert(key) :^(id value) {
		bool isValid;
		int64_t result;
		if (value && [value respondsToSelector:@selector(longLongValue)]) {
			isValid = true;
			result = [value longLongValue];
        } else {
			isValid = false;
			result = 0;
		}
		
		const Variant isValidLocal = Variant(isValid);
		const Variant resultLocal = Variant(result);
		const Variant *args[2] = { &isValidLocal, &resultLocal };
		Variant returnValue;

    	Callable::CallError error;
    	callback.callp(args, 2, returnValue, error);
    	if (error.error != Callable::CallError::CALL_OK) {
       		print_line("Call inposible");
    	}
    }];
}

void MacUserCard::SetBool(const String &key, const bool &value) {
    [::DTDUserCard setBool:MacConverter::Convert(key) value:MacConverter::ConvertToObjC(value)];
}

void MacUserCard::TryGetBool(const String &key, const Callable &callback) {
	[::DTDUserCard getValueWithKey:MacConverter::Convert(key) :^(id value) {
		bool isValid;
		bool result;
		if (value && [value respondsToSelector:@selector(boolValue)]) {
			isValid = true;
			result = MacConverter::ConvertToCpp([value boolValue]);
        } else {
			isValid = false;
			result = false;
		}
		
		const Variant isValidLocal = Variant(isValid);
		const Variant resultLocal = Variant(result);
		const Variant *args[2] = { &isValidLocal, &resultLocal };
		Variant returnValue;

    	Callable::CallError error;
    	callback.callp(args, 2, returnValue, error);
    	if (error.error != Callable::CallError::CALL_OK) {
       		print_line("Call inposible");
    	}
    }];
}

void MacUserCard::Unset(const String &property) {
	[::DTDUserCard unsetProperty:MacConverter::Convert(property)];
}

void MacUserCard::UnsetArray(const PackedStringArray &properties) {
    const auto oco_keys = MacConverter::Convert(properties);
	[::DTDUserCard unset:oco_keys];
}

void MacUserCard::IncrementInteger(const String &key, const int64_t &value) {
	[::DTDUserCard increment:MacConverter::Convert(key) byInt:MacConverter::ConvertInt64(value)];
}

void MacUserCard::IncrementFloat(const String &key, const float &value) {
	[::DTDUserCard increment:MacConverter::Convert(key) byDouble:(double)value];
}

void MacUserCard::ClearUser() {
	[::DTDUserCard clearUser];
}