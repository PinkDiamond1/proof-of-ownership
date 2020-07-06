#include <ownership.hpp>

ACTION ownership::prove( name user, checksum256 code ) {
  require_auth(permission_level(user, "owner"_n));

  userstable ustore(_self, _self.value);

  print_f("Name : %\nCode : %\n",user,code);

  if ( ustore.begin() == ustore.end() ) {
    ustore.emplace(_self, [&](auto& u) {
      u.user = user;
      u.code = code;
    });
  } else {
    ustore.modify(*ustore.begin(), _self, [&]( auto& u ) {
      u.user = user;
      u.code = code;
    });
  }
}
