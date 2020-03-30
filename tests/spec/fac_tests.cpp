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

BACKEND_TEST_CASE( "Testing wasm <fac_0_wasm>", "[fac_0_wasm_tests]" ) {
   using backend_t = backend<standalone_function_t, TestType>;
   auto code = read_wasm( std::string(wasm_directory) + "fac.0.wasm");
   backend_t bkend( code, get_wasm_allocator() );
   CHECK(bkend.call_with_return("env", "fac-rec", UINT64_C(25))->to_ui64() == UINT32_C(7034535277573963776));
   CHECK(bkend.call_with_return("env", "fac-iter", UINT64_C(25))->to_ui64() == UINT32_C(7034535277573963776));
   CHECK(bkend.call_with_return("env", "fac-rec-named", UINT64_C(25))->to_ui64() == UINT32_C(7034535277573963776));
   CHECK(bkend.call_with_return("env", "fac-iter-named", UINT64_C(25))->to_ui64() == UINT32_C(7034535277573963776));
   CHECK(bkend.call_with_return("env", "fac-opt", UINT64_C(25))->to_ui64() == UINT32_C(7034535277573963776));
}
