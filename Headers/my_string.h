#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream>

namespace my {


class String {

private:
    char*   mb_ptr {nullptr};
    int     mb_length {0};
public:
    String() = default;
    String(const char* string);
    ~String();

    // тут посмотреть
//    String(String&) = delete;
//    String& operator=(String&) = delete;

    friend std::ostream& operator<<(std::ostream& out, const String& string);
    friend std::istream& operator>>(std::istream& in, String& string);


};

std::ostream& operator<<(std::ostream& out, const String& string);
std::istream& operator>>(std::istream& in, String& string);


} // End of namespace "my{}"


#endif  // MY_STRING_H
