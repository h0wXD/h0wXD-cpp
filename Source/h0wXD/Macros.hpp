
#ifndef H0WXD_MACROS_HPP
#define H0WXD_MACROS_HPP

#include <type_traits>
#include "h0wXD/HasOperator.hpp"

#if !defined(h0wXD_NO_SHORT_MACRO_NAMES)
#define ACCESSOR				h0wXD_ACCESSOR
#define ACCESSOR_GET			h0wXD_ACCESSOR_GET
#define ACCESSOR_SET			h0wXD_ACCESSOR_SET

#define PROPERTY				h0wXD_PROPERTY
#define PROPERTY_GET			h0wXD_PROPERTY_GET
#define PROPERTY_SET			h0wXD_PROPERTY_SET

#define SAFE_DELETE				h0wXD_SAFE_DELETE
#define SAFE_DELETE_ARRAY		h0wXD_SAFE_DELETE_ARRAY
#define SAFE_DELETE_THREAD		h0wXD_SAFE_DELETE_THREAD
#endif

#define h0wXD_ACCESSOR(_TYPE, _METHOD, _VARIABLE) \
	inline _TYPE Get##_METHOD() { return _VARIABLE; } \
	inline void Set##_METHOD(_TYPE _value) { _VARIABLE = _value; }

#define h0wXD_ACCESSOR_GET(_TYPE, _METHOD, _VARIABLE) \
	inline _TYPE Get##_METHOD() { return _VARIABLE; }

#define h0wXD_ACCESSOR_SET(_TYPE, _METHOD, _VARIABLE) \
	inline void Set##_METHOD(_TYPE _value) { _VARIABLE = _value; }

#define h0wXD_PROPERTY(_PARENT, _TYPE, _NAME) \
	private: \
		template<typename T> \
		class _PARENT##_NAME \
		{ \
			friend class _PARENT; \
			T value; \
		public: \
			inline T &operator = (T value) \
			{ \
				return this->value = value; \
			} \
			inline operator T() \
			{ \
				return value; \
			} \
			template <class Y = T> \
			inline friend bool operator == (const _PARENT##_NAME<Y> &lhs, const typename std::enable_if<HasOperator::Equality<Y>::value, T>::type &rhs) \
			{ \
				return lhs.value == rhs; \
			} \
			template <class Y = T> \
			inline friend std::ostream &operator << (std::ostream &lhs, const _PARENT##_NAME<Y> &rhs) \
			{ \
				lhs << rhs.value; \
				return lhs; \
			} \
		}; \
	public: \
		_PARENT##_NAME<_TYPE> _NAME;

#define h0wXD_SAFE_DELETE(_POINTER) \
	if (_POINTER) \
	{ \
		delete _POINTER; \
		_POINTER = nullptr; \
	}

#define h0wXD_SAFE_DELETE_ARRAY(_POINTER) \
	if (_POINTER) \
	{ \
		delete [] _POINTER; \
		_POINTER = nullptr; \
	}

#define h0wXD_SAFE_DELETE_THREAD(_POINTER) \
	if (_POINTER && \
		_POINTER->joinable()) \
	{ \
		_POINTER->join(); \
		delete _POINTER; \
		_POINTER = nullptr; \
	}

#endif
