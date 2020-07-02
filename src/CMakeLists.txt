project(ownership)

set(EOSIO_WASM_OLD_BEHAVIOR "Off")
find_package(eosio.cdt)

add_contract( ownership ownership ownership.cpp )
target_include_directories( ownership PUBLIC ${CMAKE_SOURCE_DIR}/../include )
target_ricardian_directory( ownership ${CMAKE_SOURCE_DIR}/../ricardian )