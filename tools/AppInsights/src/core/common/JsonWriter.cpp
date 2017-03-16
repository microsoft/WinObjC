#include "StreamWriter.h"
#include "JsonWriter.h"

using namespace ApplicationInsights::core;

/// <summary>
/// Initializes a new instance of the <see cref="JsonWriter"/> class.
/// </summary>
/// <param name="writer">The writer.</param>
JsonWriter::JsonWriter(StreamWriter &writer) :
    Serializer(writer)
{
}

/// <summary>
/// Finalizes an instance of the <see cref="JsonWriter"/> class.
/// </summary>
JsonWriter::~JsonWriter()
{
}

/// <summary>
/// Adds a comma if needed
/// </summary>
/// <param name="kind">The kind.</param>
void JsonWriter::PrepareValue(StackEntry kind)
{
    if (seenElement) {
        writer.Write(L",");
    }
}

/// <summary>
/// Begins the dictionary value.
/// </summary>
void JsonWriter::BeginDictionaryValue()
{
    Serializer::BeginDictionaryValue();
    writer.Write(L"{");
}

/// <summary>
/// Writes the name of the property.
/// </summary>
/// <param name="name">The name.</param>
void JsonWriter::WritePropertyName(const std::wstring &name)
{
    Serializer::WritePropertyName(name);
    writer.Write((L"\"" + name + L"\":").c_str());
}

/// <summary>
/// Ends the dictionary value.
/// </summary>
void JsonWriter::EndDictionaryValue()
{
    Serializer::EndDictionaryValue();
    writer.Write(L"}");
}

/// <summary>
/// Begins the array value.
/// </summary>
void JsonWriter::BeginArrayValue()
{
    Serializer::BeginArrayValue();
    writer.Write(L"[");
}

/// <summary>
/// Ends the array value.
/// </summary>
void JsonWriter::EndArrayValue()
{
    Serializer::EndArrayValue();
    writer.Write(L"]");
}

/// <summary>
/// Writes the bool value.
/// </summary>
/// <param name="value">if set to <c>true</c> [value].</param>
void JsonWriter::WriteBoolValue(bool value)
{
    Serializer::WriteBoolValue(value);
    writer.Write(value ? L"true" : L"false");
}

/// <summary>
/// Writes the integer value.
/// </summary>
/// <param name="value">The value.</param>
void JsonWriter::WriteIntegerValue(int value)
{
    Serializer::WriteIntegerValue(value);
    writer.Write(std::to_wstring(value).c_str());
}

/// <summary>
/// Writes the double value.
/// </summary>
/// <param name="value">The value.</param>
void JsonWriter::WriteDoubleValue(double value)
{
    Serializer::WriteDoubleValue(value);
    writer.Write(std::to_wstring(value).c_str());
}

/// <summary>
/// Writes the string value.
/// </summary>
/// <param name="value">The value.</param>
void JsonWriter::WriteStringValue(const std::wstring &value)
{
    Serializer::WriteStringValue(value);
    writer.Write((L"\"" + value + L"\"").c_str());
}
