#ifndef SPROUT_WEED_CONTEXT_PARSE_CONTEXT_TERMINAL_OPERATOR_BITWISE_OR_HPP
#define SPROUT_WEED_CONTEXT_PARSE_CONTEXT_TERMINAL_OPERATOR_BITWISE_OR_HPP

#include <type_traits>
#include <sprout/config.hpp>
#include <sprout/tuple/tuple.hpp>
#include <sprout/weed/eval_result.hpp>
#include <sprout/weed/expr/tag.hpp>
#include <sprout/weed/expr/eval.hpp>
#include <sprout/weed/attr_cnv/result_of/bitwise_or.hpp>
#include <sprout/weed/attr_cnv/bitwise_or.hpp>
#include <sprout/weed/traits/expr/tag_of.hpp>
#include <sprout/weed/traits/parser/attribute_of.hpp>
#include <sprout/weed/context/parse_context_fwd.hpp>

namespace sprout {
	namespace weed {
		//
		// parse_context::eval
		//
		template<typename Iterator>
		template<typename Expr>
		struct parse_context<Iterator>::eval<
			Expr,
			typename std::enable_if<
				std::is_same<
					typename sprout::weed::traits::tag_of<Expr>::type,
					sprout::weed::tag::bitwise_or
				>::value
			>::type
		> {
		private:
			typedef sprout::weed::parse_context<Iterator> context_type;
			typedef typename sprout::tuples::tuple_element<0, typename Expr::args_type>::type expr1_type;
			typedef typename sprout::tuples::tuple_element<1, typename Expr::args_type>::type expr2_type;
			typedef typename sprout::weed::traits::attribute_of<expr1_type, Iterator, context_type>::type attr1_type;
			typedef typename sprout::weed::traits::attribute_of<expr2_type, Iterator, context_type>::type attr2_type;
		public:
			typedef typename sprout::weed::attr_cnv::result_of::bitwise_or<
				typename sprout::weed::traits::attribute_of<expr1_type, Iterator, context_type>::type,
				typename sprout::weed::traits::attribute_of<expr2_type, Iterator, context_type>::type
			>::type attribute_type;
			typedef sprout::weed::eval_result<context_type, Iterator, attribute_type> result_type;
		private:
			template<typename Result2>
			SPROUT_CONSTEXPR result_type call_2(
				typename Expr::args_type const& args,
				context_type const& ctx,
				Result2 const& res
				) const
			{
				return res.success()
					? result_type(
						true,
						res.current(),
						sprout::weed::attr_cnv::bitwise_or<attr1_type, attr2_type>(res.attr()),
						context_type(ctx, res.current())
						)
					: result_type(false, ctx.begin(), attribute_type(), ctx)
					;
			}
			template<typename Result1>
			SPROUT_CONSTEXPR result_type call_1(
				typename Expr::args_type const& args,
				context_type const& ctx,
				Result1 const& res
				) const
			{
				return res.success()
					? result_type(
						true,
						res.current(),
						sprout::weed::attr_cnv::bitwise_or<attr1_type, attr2_type>(res.attr()),
						context_type(ctx, res.current())
						)
					: call_2(args, ctx, sprout::weed::eval(sprout::tuples::get<1>(args), ctx))
					;
			}
			SPROUT_CONSTEXPR result_type call(
				typename Expr::args_type const& args,
				context_type const& ctx
				) const
			{
				return call_1(args, ctx, sprout::weed::eval(sprout::tuples::get<0>(args), ctx));
			}
		public:
			SPROUT_CONSTEXPR result_type operator()(
				Expr const& expr,
				context_type const& ctx
				) const
			{
				return call(expr.args(), ctx);
			}
		};
	}	// namespace weed
}	// namespace sprout

#endif	// #ifndef SPROUT_WEED_CONTEXT_PARSE_CONTEXT_TERMINAL_OPERATOR_BITWISE_OR_HPP