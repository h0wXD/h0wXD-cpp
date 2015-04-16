
#ifndef H0WXD_MACROS_HPP
#define H0WXD_MACROS_HPP

#define ACCESSOR(_TYPE, _METHOD, _VARIABLE) \
	inline _TYPE Get##_METHOD() { return _VARIABLE; } \
	inline void Set##_METHOD(_TYPE _value) { _VARIABLE = _value; }

#define ACCESSOR_GET(_TYPE, _METHOD, _VARIABLE) \
	inline _TYPE Get##_METHOD() { return _VARIABLE; } 

#define ACCESSOR_SET(_TYPE, _METHOD, _VARIABLE) \
	inline void Set##_METHOD(_TYPE _value) { _VARIABLE = _value; }

#define SAFE_DELETE(_POINTER) \
	if (_POINTER) \
	{ \
		delete _POINTER; \
		_POINTER = nullptr; \
	}

#define SAFE_DELETE_ARRAY(_POINTER) \
	if (_POINTER) \
	{ \
		delete [] _POINTER; \
		_POINTER = nullptr; \
	}

#define SAFE_DELETE_THREAD(_POINTER) \
	if (_POINTER && \
		_POINTER->joinable()) \
	{ \
		_POINTER->join(); \
		delete _POINTER; \
		_POINTER = nullptr; \
	}

#endif
