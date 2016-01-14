/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-14
* Description:
* * * * * * * * * * * * * * * */

#ifndef VARIABLE_H_
#define VARIABLE_H_

#include <string>
#include <FileStream.h>
#include <MessageToken.pb.h>

class Variable
{
public:

    static std::string          mode;
    static std::string          master_ip;
    static std::string          remote_path;
    static std::string          local_path;
    static FileStream           file_stream;
    static size_t               block_index;
    static uptr<MessageToken>   token;
};

#endif // !VARIABLE_H_
