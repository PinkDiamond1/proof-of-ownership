#include <eosio/eosio.hpp>
using namespace eosio;

CONTRACT ownership : public contract {
   public:
      using contract::contract;

      TABLE users {
        name user;
        checksum256 code;

        uint64_t primary_key() const {return user.value;}
      };
      typedef eosio::multi_index<"users"_n, users> userstable;

      ACTION prove( name user, checksum256 code );
      using prove_action = action_wrapper<"prove"_n, &ownership::prove>;
};