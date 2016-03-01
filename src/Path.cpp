#include <Path.h>

Path::Path( std::string path , char spliter )
{
    this->spliter_ = spliter;
    parse( path );
}

Path::Path( char * path , int len , char spliter )
{
    std::string str = std::string( path , len );
    this->spliter_ = spliter;
    parse( str );
}

std::string Path::file_name()
{
    return this->filename_;
}

std::string Path::path()
{
    return this->path_;
}

void Path::parse( std::string path )
{
    int head , tail;
    
    head = tail = 0;
    
    while ( tail < path.size() )
    {
        if ( path.at( tail ) == this->spliter_ )
        {
            path_ += path.substr( head , tail - head + 1 );
            head = tail + 1;
        }

        tail++;
    }

    this->filename_ = path.substr( head  , tail - head + 1 );
}
