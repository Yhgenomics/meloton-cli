/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-03-01
* Description:
* * * * * * * * * * * * * * * */

#ifndef PATH_FILE_H_
#define PATH_FILE_H_

#include <string>

class Path
{
public:

    Path( std::string path ,char spliter );
    Path( char * path , int len , char spliter );

    std::string file_name();
    std::string path();

private:

    char        spliter_;
    std::string path_;
    std::string filename_;
    std::string filename_without_extention_;

    void parse(std::string path);

};

#endif // !PATH_FILE_H_
