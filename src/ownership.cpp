#include <ownership.hpp>

ACTION ownership::prove( name user, std::string code ) {
	require_auth(permission_level(user, "owner"_n));

  print_f("Name : %\nCode : %\n",user,code);
}
