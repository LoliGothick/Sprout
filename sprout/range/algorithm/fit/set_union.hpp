#ifndef SPROUT_RANGE_ALGORITHM_FIT_SET_UNION_HPP
#define SPROUT_RANGE_ALGORITHM_FIT_SET_UNION_HPP

#include <sprout/config.hpp>
#include <sprout/fixed_container/traits.hpp>
#include <sprout/fixed_container/functions.hpp>
#include <sprout/algorithm/fit/result_of.hpp>
#include <sprout/algorithm/fit/set_union.hpp>

namespace sprout {
	namespace range {
		namespace fit {
			//
			// set_union
			//
			template<typename Input1, typename Input2, typename Result, typename Compare>
			SPROUT_CONSTEXPR inline typename sprout::fixed::result_of::algorithm<Result>::type set_union(
				Input1 const& input1,
				Input2 const& input2,
				Result const& result,
				Compare comp
				)
			{
				return sprout::fit::set_union(sprout::begin(input1), sprout::end(input1), sprout::begin(input2), sprout::end(input2), result, comp);
			}

			//
			// set_union
			//
			template<typename Input1, typename Input2, typename Result>
			SPROUT_CONSTEXPR inline typename sprout::fixed::result_of::algorithm<Result>::type set_union(
				Input1 const& input1,
				Input2 const& input2,
				Result const& result
				)
			{
				return sprout::fit::set_union(sprout::begin(input1), sprout::end(input1), sprout::begin(input2), sprout::end(input2), result);
			}
		}	// namespace fit
	}	// namespace range
}	// namespace sprout

#endif	// #ifndef SPROUT_RANGE_ALGORITHM_FIT_SET_UNION_HPP