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

BACKEND_TEST_CASE( "Testing wasm <memory_redundancy_0_wasm>", "[memory_redundancy_0_wasm_tests]" ) {
   using backend_t = backend<standalone_function_t, TestType>;
   auto code = read_wasm( std::string(wasm_directory) + "memory_redundancy.0.wasm");
   backend_t bkend( code, get_wasm_allocator() );
   CHECK(bkend.call_with_return("env", "test_store_to_load")->to_ui32() == UINT32_C(128));
bkend("env", "zero_everything");
   CHECK(bkend.call_with_return("env", "test_redundant_load")->to_ui32() == UINT32_C(128));
bkend("env", "zero_everything");
   CHECK(bit_cast<uint32_t>(bkend.call_with_return("env", "test_dead_store")->to_f32()) == UINT32_C(35));
bkend("env", "zero_everything");
   CHECK(bkend.call_with_return("env", "malloc_aliasing")->to_ui32() == UINT32_C(43));
}
