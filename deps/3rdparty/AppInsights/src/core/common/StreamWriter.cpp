#include <wchar.h>
#include "StreamWriter.h"
#include "string.h"

using namespace ApplicationInsights::core;

/// <summary>
/// Initializes a new instance of the <see cref="StreamWriter"/> class.
/// </summary>
StreamWriter::StreamWriter()
{
}

/// <summary>
/// Finalizes an instance of the <see cref="StreamWriter"/> class.
/// </summary>
StreamWriter::~StreamWriter()
{
}

/// <summary>
/// Writes the bool value.
/// </summary>
/// <param name="value">if set to <c>true</c> [value].</param>
void StreamWriter::Write(bool value)
{
	if (value)
	{
		return this->Write(L"True");
	}

	return this->Write(L"False");
}

/// <summary>
/// Writes the int value.
/// </summary>
/// <param name="value">The value.</param>
void StreamWriter::Write(int value)
{
	wchar_t buffer[128];
#if WIN32
	swprintf_s(buffer, 128, L"%d", value);
#else
    swprintf(buffer, 128, L"%d", value);
#endif
	return this->Write(buffer);
}

/// <summary>
/// Writes the float value.
/// </summary>
/// <param name="value">The value.</param>
void StreamWriter::Write(float value)
{
	wchar_t buffer[128];
#if WIN32
	swprintf_s(buffer, 128, L"%f", value);
#else
    swprintf(buffer, 128, L"%f", value);
#endif
	return this->Write(buffer);
}

/// <summary>
/// Writes the specified value.
/// </summary>
/// <param name="value">The value.</param>
void StreamWriter::Write(double value)
{
	wchar_t buffer[128];
#if WIN32
	swprintf_s(buffer, 128, L"%ld", value);
#else
    swprintf(buffer, 128, L"%ld", value);
#endif
	return this->Write(buffer);
}