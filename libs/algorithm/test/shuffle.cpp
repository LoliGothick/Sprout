#ifndef SPROUT_LIBS_ALGORITHM_TEST_SHUFFLE_CPP
#define SPROUT_LIBS_ALGORITHM_TEST_SHUFFLE_CPP

#include <sprout/algorithm/shuffle.hpp>
#include <sprout/random.hpp>
#include <sprout/random/unique_seed.hpp>
#include <sprout/array.hpp>
#include <sprout/sub_array.hpp>
#include <sprout/container.hpp>
#include <testspr/tools.hpp>

namespace testspr {
	static void algorithm_shuffle_test() {
		using namespace sprout;
		{
			SPROUT_STATIC_CONSTEXPR auto arr1 = array<int, 10>{{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};

			// �V���b�t��
			{
				SPROUT_STATIC_CONSTEXPR auto shuffled = sprout::shuffle(
					arr1,
					sprout::random::hellekalek1995(SPROUT_UNIQUE_SEED)
					);
				TESTSPR_DOUBLE_ASSERT(testspr::is_permutation(
					shuffled,
					arr1
					));
			}
			{
				SPROUT_STATIC_CONSTEXPR auto shuffled = sprout::fit::shuffle(
					arr1,
					sprout::random::hellekalek1995(SPROUT_UNIQUE_SEED)
					);
				TESTSPR_DOUBLE_ASSERT(testspr::is_permutation(
					shuffled,
					arr1
					));
			}
			// �V���b�t��
			// �͈͂̐؂�o��
			{
				SPROUT_STATIC_CONSTEXPR auto shuffled = sprout::shuffle(
					sprout::sub(arr1, 2, 8),
					sprout::random::hellekalek1995(SPROUT_UNIQUE_SEED)
					);
				TESTSPR_DOUBLE_ASSERT(testspr::is_permutation(
					shuffled,
					sprout::sub(arr1, 2, 8)
					));
				TESTSPR_DOUBLE_ASSERT(testspr::is_permutation(
					sprout::get_internal(shuffled),
					arr1
					));
			}
			{
				SPROUT_STATIC_CONSTEXPR auto shuffled = sprout::fit::shuffle(
					sprout::sub(arr1, 2, 8),
					sprout::random::hellekalek1995(SPROUT_UNIQUE_SEED)
					);
				TESTSPR_DOUBLE_ASSERT(testspr::is_permutation(
					shuffled,
					sprout::sub(arr1, 2, 8)
					));
				TESTSPR_DOUBLE_ASSERT(testspr::is_permutation(
					sprout::get_internal(shuffled),
					arr1
					));
			}
		}
	}
}	// namespace testspr

#ifndef TESTSPR_CPP_INCLUDE
#	define TESTSPR_TEST_FUNCTION testspr::algorithm_shuffle_test
#	include <testspr/include_main.hpp>
#endif

#endif	// #ifndef SPROUT_LIBS_ALGORITHM_TEST_SHUFFLE_CPP