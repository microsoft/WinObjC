#include "StringWriter.h"
#include "Utils.h"
#include <stdio.h>

using namespace ApplicationInsights::core;

/// <summary>
/// Initializes a new instance of the <see cref="StringWriter"/> class.
/// </summary>
/// <param name="builder">The builder.</param>
StringWriter::StringWriter(std::wstring* builder)
    : StreamWriter()
{
	if (builder == nullptr)
	{
		Utils::WriteDebugLine(L"ERROR: StringWriter:  Specified builder is NULL");
		return;
	}

	this->builder = builder;
}

/// <summary>
/// Finalizes an instance of the <see cref="StringWriter"/> class.
/// </summary>
StringWriter::~StringWriter()
{
	this->builder = nullptr;
}

/// <summary>
/// Writes the specified value.
/// </summary>
/// <param name="value">The value.</param>
void StringWriter::Write(wchar_t value)
{
	this->builder->append(1, value);
}

/// <summary>
/// Writes the specified value.
/// </summary>
/// <param name="value">The value.</param>
void StringWriter::Write(const wchar_t* value)
{
	this->builder->append(value);
}
