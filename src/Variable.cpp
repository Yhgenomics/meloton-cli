#include <Variable.h>

std::string Variable::local_path    = "";
std::string Variable::remote_path   = "";
std::string Variable::mode          = "";
std::string Variable::master_ip     = "";
uptr<MessageToken> Variable::token  = nullptr;
size_t Variable::block_index        = 0;
size_t Variable::file_offset        = 0;
std::ofstream Variable::ostream;
std::ifstream Variable::istream;