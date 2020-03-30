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

BACKEND_TEST_CASE( "Testing wasm <e_memory_0_wasm>", "[e_memory_0_wasm_tests]" ) {
   using backend_t = backend<standalone_function_t, TestType>;
   auto code = read_wasm( std::string(wasm_directory) + "e_memory.0.wasm");
   CHECK_THROWS_AS(backend_t(code, nullptr), std::exception);
}

BACKEND_TEST_CASE( "Testing wasm <e_memory_1_wasm>", "[e_memory_1_wasm_tests]" ) {
   using backend_t = backend<standalone_function_t, TestType>;
   auto code = read_wasm( std::string(wasm_directory) + "e_memory.1.wasm");
   backend_t bkend( code, get_wasm_allocator() );
}

BACKEND_TEST_CASE( "Testing wasm <e_memory_2_wasm>", "[e_memory_2_wasm_tests]" ) {
   using backend_t = backend<standalone_function_t, TestType>;
   auto code = read_wasm( std::string(wasm_directory) + "e_memory.2.wasm");
   backend_t bkend( code, get_wasm_allocator() );
}

BACKEND_TEST_CASE( "Testing wasm <e_memory_3_wasm>", "[e_memory_3_wasm_tests]" ) {
   using backend_t = backend<standalone_function_t, TestType>;
   auto code = read_wasm( std::string(wasm_directory) + "e_memory.3.wasm");
   backend_t bkend( code, get_wasm_allocator() );
}
