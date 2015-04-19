
#ifndef H0WXD_HASOPERATOR_HPP
#define H0WXD_HASOPERATOR_HPP

namespace h0wXD
{
	template<bool B, typename T = void>
	using disable_if = std::enable_if<!B, T>;

	namespace HasOperator
	{
		typedef char no[7];
		template<typename T> no &operator == (const T &, const T &);
		template<typename T> no &operator << (const std::ostream &, const T &);

		template <typename T>
		struct Equality
		{
			enum { value = (sizeof(*(T*)(0) == *(T*)(0))) != sizeof(no) };
		};
		template <typename T>
		struct Insertion
		{
			enum { value = (sizeof(*(std::ostream*)(0) << *(T*)(0))) != sizeof(no) };
		};
	}
}

#endif
