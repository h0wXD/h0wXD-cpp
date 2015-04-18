
#ifndef H0WXD_TYPES_HPP
#define H0WXD_TYPES_HPP

#include <cstdint>
#include <thread>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <queue>
#include <deque>
#include <list>
#include <array>
#include <stack>

#include "h0wXD/Threading/Mutex.hpp"

namespace h0wXD
{
	typedef std::int8_t						int8;
	typedef std::uint8_t					uint8;
	typedef std::uint8_t					byte;
	typedef std::uint8_t					uchar;

	typedef std::int16_t					int16;
	typedef std::uint16_t					uint16;
	typedef std::uint16_t					word;
	typedef std::uint16_t					ushort;

	typedef std::int32_t					int32;
	typedef std::uint32_t					uint32;
	typedef std::uint32_t					dword;
	typedef std::uint32_t					uint;

	typedef float							single;

	typedef std::int64_t					int64;
	typedef std::uint64_t					uint64;
	typedef std::uint64_t					qword;

	typedef std::string						string;
	typedef std::wstring					wstring;
	
	typedef void *							handle;
	typedef std::thread						thread;
	typedef h0wXD::Threading::mutex			mutex;

	template<class _K, class _Ty, class _Pr = std::less<_K>, class _A = std::allocator<_Ty>>
	class map : public std::map< _K, _Ty, _Pr, _A>{};
	template<class _K, class _Ty, class _Pr = std::less<_K>, class _A = std::allocator<_Ty>>
	class map_mt : public std::map< _K, _Ty, _Pr, _A>, public mutex {};

	template<class _Kty, class _Ty, class _Hasher = std::hash<_Kty>, class _Keyeq = std::equal_to<_Kty>, class _Alloc = std::allocator<std::pair<_Kty, _Ty>>>
	class umap : public std::unordered_map<_Kty, _Ty, _Hasher, _Keyeq, _Alloc>{};
	template<class _Kty, class _Ty, class _Hasher = std::hash<_Kty>, class _Keyeq = std::equal_to<_Kty>, class _Alloc = std::allocator<std::pair<_Kty, _Ty>>>
	class umap_mt : public std::unordered_map<_Kty, _Ty, _Hasher, _Keyeq, _Alloc>, public mutex {};

	template<class _K, class _Pr = std::less<_K>, class _A = std::allocator<_K>>
	class set : public std::set<_K, _Pr, _A>{};
	template<class _K, class _Pr = std::less<_K>, class _A = std::allocator<_K>>
	class set_mt : public std::set<_K, _Pr, _A>, public mutex {};

	template<class _Ty, class _A = std::allocator<_Ty>>
	class vector : public std::vector<_Ty, _A>{};
	template<class _Ty, class _A = std::allocator<_Ty>>
	class vector_mt : public std::vector<_Ty, _A>, public mutex {};

	template<class _Ty, class _Seq = std::deque<_Ty>>
	class queue : public std::queue<_Ty, _Seq>{};
	template<class _Ty, class _Seq = std::deque<_Ty>>
	class queue_mt : public std::queue<_Ty, _Seq>, public mutex {};

	template<class _Ty, class _A = std::allocator<_Ty>>
	class deque : public std::deque<_Ty, _A>{};
	template<class _Ty, class _A = std::allocator<_Ty>>
	class deque_mt : public std::deque<_Ty, _A>, public mutex {};

	template<class _Ty, class _A = std::allocator<_Ty>>
	class list : public std::list<_Ty, _A>{};
	template<class _Ty, class _A = std::allocator<_Ty>>
	class list_mt : public std::list<_Ty, _A>, public mutex {};

	template<class _Ty, std::size_t _Size>
	class array : public std::array<_Ty, _Size>{};
	template<class _Ty, std::size_t _Size>
	class array_mt : public std::array<_Ty, _Size>, public mutex {};

	template<class _Ty, class _A = std::deque<_Ty>>
	class stack : public std::stack<_Ty, _A>{};
	template<class _Ty, class _A = std::deque<_Ty>>
	class stack_mt : public std::stack<_Ty, _A>, public mutex {};
}

#endif
