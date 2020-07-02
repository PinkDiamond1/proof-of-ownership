#include <eosio/eosio.hpp>
using namespace eosio;

CONTRACT ownership : public contract {
   public:
      using contract::contract;

      ACTION prove( name user, std::string code );

      using prove_action = action_wrapper<"prove"_n, &ownership::prove>;
};