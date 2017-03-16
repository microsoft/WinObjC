#ifndef __SERIALIZER_H__
#define __SERIALIZER_H__

#include <stack>
#include <string>
#include "../Common/Common.h"

namespace ApplicationInsights
{
	namespace core
	{
		// Throws exceptions on error
		class Serializer;

		/**
		* this is the interface for all the data contract objects.
		*/
		class TELEMETRYCLIENT_API ISerializable {

		public:
			/// <summary>
			/// Serialize the contract objects with writer
			/// </summary>
			/// <param name="writer_"> the writer to serialize data</param>
			/// <throws> IOException will be thrown if something wrong with the output stream </throws>
			/// <throws> JSONException will be thrown if the data format is not correct JSON format.  </throws>
			virtual void Serialize(Serializer& writer) const = 0;
		};

		class StreamWriter;
		class TELEMETRYCLIENT_API Serializer
		{
		public:
			/// <summary>
			/// Initializes a new instance of the <see cref="Serializer"/> class.
			/// </summary>
			/// <param name="writer_">The writer_.</param>
			Serializer(StreamWriter &writer_);

			/// <summary>
			/// Copy constructor for <see cref="Serializer"/> class.
			/// </summary>
			/// <param name="other">the serializer to copy.</param>
			Serializer(Serializer& other);

			/// <summary>
			/// Assignment operator for <see cref="Serializer"/> class.
			/// </summary>
			/// <param name="other">The serializer to copy values from.</param>
			Serializer& operator= (const Serializer& other);

			/// <summary>
			/// Finalizes an instance of the <see cref="Serializer"/> class.
			/// </summary>
			virtual ~Serializer();

			// All calls rely on internal state. A stack is maintained to keep track
			//  of the currently open dictionaries and arrays. It is an error to
			//  have more than one top-level object. An "object" is also a
			//  dictionary. Output is always in the order of the calls made; this is
			//  a strong API guarantee and must be respected by subclasses.

			/// <summary>
			/// Begins the dictionary value.
			/// </summary>
			virtual void BeginDictionaryValue();

			/// <summary>
			/// Writes the name of the property.
			/// This call is only valid while a dictionary is open. Additionally, it
			///  must be alternated with calls to value writers, or an error results.
			///  Beginning a dictionary or array counts as a written value for the
			///  purposes of this call.
			/// </summary>
			/// <param name="name">The name.</param>
			virtual void WritePropertyName(const std::wstring &name);

			/// <summary>
			/// Ends the dictionary value.
			/// </summary>
			virtual void EndDictionaryValue();

			/// <summary>
			/// Begins the array value.
			/// </summary>
			virtual void BeginArrayValue();

			/// <summary>
			/// Ends the array value.
			/// </summary>
			virtual void EndArrayValue();

			/// <summary>
			/// Writes the bool value.
			/// </summary>
			/// <param name="value">if set to <c>true</c> [value].</param>
			virtual void WriteBoolValue(bool value);

			/// <summary>
			/// Writes the integer value.
			/// </summary>
			/// <param name="value">The value.</param>
			virtual void WriteIntegerValue(int value);

			/// <summary>
			/// Writes the double value.
			/// </summary>
			/// <param name="value">The value.</param>
			virtual void WriteDoubleValue(double value); 

			/// <summary>
			/// Writes the string value.
			/// </summary>
			/// <param name="value">The value.</param>
			virtual void WriteStringValue(const std::wstring &value);

			/// <summary>
			/// Writes the object value.
			/// calls BeginDictionaryValue(), obj.Serialize(), EndDictionaryValue()
			/// </summary>
			/// <param name="obj">The object.</param>
			virtual void WriteObjectValue(const ISerializable *obj); 

		protected:
			enum StackEntry {
				ArrayStartEntry, ArrayEndEntry,
				DictionaryStartEntry, DictionaryEndEntry, KeyEntry,
				ValueEntry
			};

			StreamWriter &writer;
			bool seenElement;
			bool seenKey;

			/// <summary>
			/// Prepares the value by validating the state.
			/// </summary>
			/// <param name="kind">The kind.</param>
			virtual void PrepareValue(StackEntry kind);

		private:
			/// <summary>
			/// Validates the state for.
			/// </summary>
			/// <param name="entry">The entry.</param>
			void ValidateStateFor(StackEntry entry);

			std::stack<StackEntry> elementStack;
		};
	}
}
#endif
