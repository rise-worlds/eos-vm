#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdlib>
#include <catch2/catch.hpp>
#include <utils.hpp>
#include <wasm_config.hpp>
#include <eosio/vm/backend.hpp>

using namespace eosio;
using namespace eosio::vm;

BACKEND_TEST_CASE( "Testing wasm <unreachable_0_wasm>", "[unreachable_0_wasm_tests]" ) {
   using backend_t = backend<standalone_function_t, TestType>;
   auto code = read_wasm( std::string(wasm_directory) + "unreachable.0.wasm");
   backend_t bkend( code, get_wasm_allocator() );
   CHECK_THROWS_AS(bkend("env", "type-i32"), std::exception);
   CHECK_THROWS_AS(bkend("env", "type-i64"), std::exception);
   CHECK_THROWS_AS(bkend("env", "type-f32"), std::exception);
   CHECK_THROWS_AS(bkend("env", "type-f64"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-func-first"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-func-mid"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-func-last"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-func-value"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-block-first"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-block-mid"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-block-last"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-block-value"), std::exception);
   CHECK(bkend.call_with_return("env", "as-block-broke")->to_ui32() == UINT32_C(1));
   CHECK_THROWS_AS(bkend("env", "as-loop-first"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-loop-mid"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-loop-last"), std::exception);
   CHECK(bkend.call_with_return("env", "as-loop-broke")->to_ui32() == UINT32_C(1));
   CHECK_THROWS_AS(bkend("env", "as-br-value"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-br_if-cond"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-br_if-value"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-br_if-value-cond"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-br_table-index"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-br_table-value"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-br_table-value-2"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-br_table-value-index"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-br_table-value-and-index"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-return-value"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-if-cond"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-if-then", UINT32_C(1), UINT32_C(6)), std::exception);
   CHECK(bkend.call_with_return("env", "as-if-then", UINT32_C(0), UINT32_C(6))->to_ui32() == UINT32_C(6));
   CHECK_THROWS_AS(bkend("env", "as-if-else", UINT32_C(0), UINT32_C(6)), std::exception);
   CHECK(bkend.call_with_return("env", "as-if-else", UINT32_C(1), UINT32_C(6))->to_ui32() == UINT32_C(6));
   CHECK_THROWS_AS(bkend("env", "as-select-first", UINT32_C(0), UINT32_C(6)), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-select-first", UINT32_C(1), UINT32_C(6)), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-select-second", UINT32_C(0), UINT32_C(6)), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-select-second", UINT32_C(1), UINT32_C(6)), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-select-cond"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-call-first"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-call-mid"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-call-last"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-call_indirect-func"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-call_indirect-first"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-call_indirect-mid"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-call_indirect-last"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-local.set-value"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-local.tee-value"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-global.set-value"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-load-address"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-loadN-address"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-store-address"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-store-value"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-storeN-address"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-storeN-value"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-unary-operand"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-binary-left"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-binary-right"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-test-operand"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-compare-left"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-compare-right"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-convert-operand"), std::exception);
   CHECK_THROWS_AS(bkend("env", "as-memory.grow-size"), std::exception);
}
