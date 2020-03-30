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

BACKEND_TEST_CASE( "Testing wasm <labels_0_wasm>", "[labels_0_wasm_tests]" ) {
   using backend_t = backend<standalone_function_t, TestType>;
   auto code = read_wasm( std::string(wasm_directory) + "labels.0.wasm");
   backend_t bkend( code, get_wasm_allocator() );
   CHECK(bkend.call_with_return("env", "block")->to_ui32() == UINT32_C(1));
   CHECK(bkend.call_with_return("env", "loop1")->to_ui32() == UINT32_C(5));
   CHECK(bkend.call_with_return("env", "loop2")->to_ui32() == UINT32_C(8));
   CHECK(bkend.call_with_return("env", "loop3")->to_ui32() == UINT32_C(1));
   CHECK(bkend.call_with_return("env", "loop4", UINT32_C(8))->to_ui32() == UINT32_C(16));
   CHECK(bkend.call_with_return("env", "loop5")->to_ui32() == UINT32_C(2));
   CHECK(bkend.call_with_return("env", "loop6")->to_ui32() == UINT32_C(3));
   CHECK(bkend.call_with_return("env", "if")->to_ui32() == UINT32_C(5));
   CHECK(bkend.call_with_return("env", "if2")->to_ui32() == UINT32_C(5));
   CHECK(bkend.call_with_return("env", "switch", UINT32_C(0))->to_ui32() == UINT32_C(50));
   CHECK(bkend.call_with_return("env", "switch", UINT32_C(1))->to_ui32() == UINT32_C(20));
   CHECK(bkend.call_with_return("env", "switch", UINT32_C(2))->to_ui32() == UINT32_C(20));
   CHECK(bkend.call_with_return("env", "switch", UINT32_C(3))->to_ui32() == UINT32_C(3));
   CHECK(bkend.call_with_return("env", "switch", UINT32_C(4))->to_ui32() == UINT32_C(50));
   CHECK(bkend.call_with_return("env", "switch", UINT32_C(5))->to_ui32() == UINT32_C(50));
   CHECK(bkend.call_with_return("env", "return", UINT32_C(0))->to_ui32() == UINT32_C(0));
   CHECK(bkend.call_with_return("env", "return", UINT32_C(1))->to_ui32() == UINT32_C(2));
   CHECK(bkend.call_with_return("env", "return", UINT32_C(2))->to_ui32() == UINT32_C(2));
   CHECK(bkend.call_with_return("env", "br_if0")->to_ui32() == UINT32_C(29));
   CHECK(bkend.call_with_return("env", "br_if1")->to_ui32() == UINT32_C(1));
   CHECK(bkend.call_with_return("env", "br_if2")->to_ui32() == UINT32_C(1));
   CHECK(bkend.call_with_return("env", "br_if3")->to_ui32() == UINT32_C(2));
   CHECK(bkend.call_with_return("env", "br")->to_ui32() == UINT32_C(1));
   CHECK(bkend.call_with_return("env", "shadowing")->to_ui32() == UINT32_C(1));
   CHECK(bkend.call_with_return("env", "redefinition")->to_ui32() == UINT32_C(5));
}

BACKEND_TEST_CASE( "Testing wasm <labels_1_wasm>", "[labels_1_wasm_tests]" ) {
   using backend_t = backend<standalone_function_t, TestType>;
   auto code = read_wasm( std::string(wasm_directory) + "labels.1.wasm");
   CHECK_THROWS_AS(backend_t(code, nullptr), std::exception);
}

BACKEND_TEST_CASE( "Testing wasm <labels_2_wasm>", "[labels_2_wasm_tests]" ) {
   using backend_t = backend<standalone_function_t, TestType>;
   auto code = read_wasm( std::string(wasm_directory) + "labels.2.wasm");
   CHECK_THROWS_AS(backend_t(code, nullptr), std::exception);
}

BACKEND_TEST_CASE( "Testing wasm <labels_3_wasm>", "[labels_3_wasm_tests]" ) {
   using backend_t = backend<standalone_function_t, TestType>;
   auto code = read_wasm( std::string(wasm_directory) + "labels.3.wasm");
   CHECK_THROWS_AS(backend_t(code, nullptr), std::exception);
}
