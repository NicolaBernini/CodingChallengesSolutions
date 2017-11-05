// Temporary Lifecycle Example
// See it running on 
// https://ideone.com/TFoudI

#include <cstdio>
#include <string>

void fun(const char* c)
{
    printf("--> %s\n", c);
}

std::string get()
{
    std::string str = "Hello World";
    return str;
}

int main() 
{
    const char *cc = get().c_str();
    // cc is not valid at this point. As it is pointing to
    // temporary string internal buffer, and the temporary string
    // has already been destroyed at this point.
    fun(cc);

    // But I am surprise this call will yield valid result.
    // It seems that the returned temporary string is valid within
    // scope (...)
    // What my understanding is, scope means {...}
    // Is this valid behavior guarantee by C++ standard? Or it depends
    // on your compiler vendor implementations?
    fun(get().c_str());

    getchar();
}
