#include "StreamWriter.h"
#include "Serializer.h"

using namespace ApplicationInsights::core;

/// <summary>
/// Initializes a new instance of the <see cref="Serializer"/> class.
/// </summary>
/// <param name="writer_">The writer_.</param>
Serializer::Serializer(StreamWriter &writer_) :
    writer(writer_), seenElement(false), seenKey(false), elementStack()
{
}

/// <summary>
/// Copy constructor for <see cref="Serializer"/> class.
/// </summary>
/// <param name="other">the serializer to copy.</param>
Serializer::Serializer(Serializer& other) :
writer(other.writer), seenElement(other.seenElement), seenKey(other.seenKey), elementStack(other.elementStack)
{
}

/// <summary>
/// Assignment operator for <see cref="Serializer"/> class.
/// </summary>
/// <param name="other">The serializer to copy values from.</param>
Serializer& Serializer::operator= (const Serializer& other)
{
	writer = other.writer;
	seenElement = other.seenElement;
	seenKey = other.seenKey;
	elementStack = other.elementStack;

	return *this;
}


/// <summary>
/// Finalizes an instance of the <see cref="Serializer"/> class.
/// </summary>
Serializer::~Serializer()
{
}

/// <summary>
/// Prepares the value by validating the state.
/// </summary>
/// <param name="kind">The kind.</param>
void Serializer::PrepareValue(StackEntry kind)
{
    ValidateStateFor(kind);
}

/// <summary>
/// Validates the state for.
/// </summary>
/// <param name="entry">The entry.</param>
void Serializer::ValidateStateFor(StackEntry entry)
{
    // The stack must either be empty, or not a value type.
    if (elementStack.size() != 0 && elementStack.top() == ValueEntry) {
        throw "SERIALIZER - There can only be one top-level value.";
    }

    switch (entry) {
        case ArrayEndEntry:
            // An array must be open.
            if (elementStack.size() == 0 || elementStack.top() != ArrayStartEntry) {
                throw "SERIALIZER - Can not end a nonexistent array.";
            }
            break;
        case ArrayStartEntry:
        case DictionaryStartEntry:
		case ValueEntry:
            // If a dictionary is open, a key must already be seen.
            if (elementStack.size() != 0 && elementStack.top() == DictionaryStartEntry && !seenKey) {
                throw "SERIALIZER - Can not start value inside dictionary without a key.";
            }
            break;
        case DictionaryEndEntry:
		case KeyEntry:
            // A dictionary must be open and a key must not be seen.
            if (elementStack.size() == 0 || elementStack.top() != DictionaryStartEntry) {  // || seenKey) {
                throw "SERIALIZER - Can not end nonexistent dictionary or provide key for a dictionary waiting for a value.";
            }
            break;
    }
}

/// <summary>
/// Begins the dictionary value.
/// </summary>
void Serializer::BeginDictionaryValue()
{
    PrepareValue(DictionaryStartEntry);
    elementStack.push(DictionaryStartEntry);
    seenElement = false;
}

/// <summary>
/// Writes the name of the property.
/// </summary>
/// <param name="name">The name.</param>
void Serializer::WritePropertyName(const std::wstring &name)
{
	PrepareValue(KeyEntry);
    ValidateStateFor(KeyEntry);
	seenElement = false;
    seenKey = true;
}

/// <summary>
/// Ends the dictionary value.
/// </summary>
void Serializer::EndDictionaryValue()
{
    ValidateStateFor(DictionaryEndEntry);
    elementStack.pop();
    seenElement = true;
    seenKey = false;
}

/// <summary>
/// Begins the array value.
/// </summary>
void Serializer::BeginArrayValue()
{
    PrepareValue(ArrayStartEntry);
    elementStack.push(ArrayStartEntry);
    seenElement = false;
}

/// <summary>
/// Ends the array value.
/// </summary>
void Serializer::EndArrayValue()
{
    ValidateStateFor(ArrayEndEntry);
    elementStack.pop();
    seenElement = true;
}
    
/// <summary>
/// Writes the bool value.
/// </summary>
/// <param name="value">if set to <c>true</c> [value].</param>
void Serializer::WriteBoolValue(bool value)
{
    PrepareValue(ValueEntry);
    seenElement = true;
}

/// <summary>
/// Writes the integer value.
/// </summary>
/// <param name="value">The value.</param>
void Serializer::WriteIntegerValue(int value)
{
    PrepareValue(ValueEntry);
    seenElement = true;
}

/// <summary>
/// Writes the double value.
/// </summary>
/// <param name="value">The value.</param>
void Serializer::WriteDoubleValue(double value)
{
    PrepareValue(ValueEntry);
    seenElement = true;

}

/// <summary>
/// Writes the string value.
/// </summary>
/// <param name="value">The value.</param>
void Serializer::WriteStringValue(const std::wstring &value)
{
    PrepareValue(ValueEntry);
    seenElement = true;
}
    
/// <summary>
/// Writes the object value.
/// </summary>
/// <param name="obj">The object.</param>
void Serializer::WriteObjectValue(const ISerializable *obj)
{
    BeginDictionaryValue();
	obj->Serialize(*this);
    EndDictionaryValue();
}
