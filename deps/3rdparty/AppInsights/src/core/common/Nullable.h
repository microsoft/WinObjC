#ifndef NULLABLE_H
#define NULLABLE_H

namespace ApplicationInsights
{
	namespace core
	{
		template <class T>
		class TELEMETRYCLIENT_API Nullable
		{
		public:
			static_assert(std::is_default_constructible<T>::value, "T must be default-constructible");
			static_assert(std::is_copy_constructible<T>::value, "T must be copy-constructible");
			static_assert(std::is_move_constructible<T>::value, "T must be move-constructible");
			static_assert(std::is_copy_assignable<T>::value, "T must be copy-assignable");
			static_assert(std::is_move_assignable<T>::value, "T must be move-assignable");

			/// <summary>
			/// Initializes a new instance of the <see cref="Nullable{T}"/> class.
			/// </summary>
			Nullable()
				: m_Value(),
				m_fHasValue(false)
			{
			}

			/// <summary>
			/// Initializes a new instance of the <see cref="Nullable{T}"/> class.
			/// </summary>
			/// <param name="value">The value.</param>
			Nullable(T value)
				: m_Value(value),
				m_fHasValue(true)
			{
			}

			/// <summary>
			/// Initializes a new instance of the <see cref="Nullable{T}"/> class.
			/// </summary>
			/// <param name="obj">The object.</param>
			Nullable(Nullable&& obj)
				: m_Value(std::move(obj.m_Value)),
				m_fHasValue(obj.m_fHasValue)
			{
			}

			/// <summary>
			/// Initializes a new instance of the <see cref="Nullable{T}"/> class.
			/// </summary>
			/// <param name="obj">The object.</param>
			Nullable(const Nullable& obj)
				: m_Value(obj.m_Value),
				m_fHasValue(obj.m_fHasValue)
			{
			}

			/// <summary>
			/// Copy constructor.
			/// </summary>
			/// <param name="obj">The object.</param>
			/// <returns></returns>
			Nullable &operator=(const Nullable &obj)
			{
				m_Value = obj.m_Value;
				m_fHasValue = obj.m_fHasValue;
				return *this;
			}

			/// <summary>
			/// Copy constructor.
			/// </summary>
			/// <param name="obj">The object.</param>
			/// <returns></returns>
			Nullable &operator=(Nullable &&obj)
			{
				std::swap(m_Value, obj.m_Value);
				std::swap(m_fHasValue, obj.m_fHasValue);
				return *this;
			}

			/// <summary>
			/// Determines whether this instance has value.
			/// </summary>
			/// <returns>true if it contains a value</returns>
			bool HasValue() const {
				return m_fHasValue;
			}

			/// <summary>
			/// Gets the value.
			/// </summary>
			/// <returns>the value</returns>
			T GetValue() const {
				return m_Value;
			}

			/// <summary>
			/// Sets the value.
			/// </summary>
			/// <param name="value">The value.</param>
			void SetValue(const T value) {
				m_Value = value;
				m_fHasValue = true;
			}

			/// <summary>
			/// Clears the value.
			/// </summary>
			void ClearValue() {
				m_fHasValue = false;
			}

			/// <summary>
			/// Equality check
			/// </summary>
			/// <param name="right">The right.</param>
			/// <returns>True if the objects contain the same values</returns>
			bool operator==(const Nullable<T>& right) const
			{
				if (this->m_fHasValue == false)
				{
					return this->m_fHasValue == right.m_fHasValue;
				}

				if (right.m_fHasValue == false)
				{
					return false;
				}

				return this->m_Value == right.m_Value;
			}

			/// <summary>
			/// Inequality check
			/// </summary>
			/// <param name="left">The left.</param>
			/// <returns>True if teh values are not the same</returns>
			bool operator!=(const Nullable<T>& left) const
			{
				return !operator==(this, left);
			}

		private:
			T m_Value;
			bool m_fHasValue;
		};
	}
}
#endif
