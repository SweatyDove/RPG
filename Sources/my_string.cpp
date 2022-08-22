#include "my_string.h"


// #### Constructor
// #########
my::String::String(const char* string)
{
    const char* strPtr {string};
    char* tempPtr {nullptr};
    int length {1};                         // 1 - for '\0'

    // Derermine the length of the input string
    while (*strPtr++ != '\0') {
        ++length;
    }
    mb_length = length;

    // Allocate memory in the heap
    mb_ptr = new char[mb_length];
    tempPtr = mb_ptr;

    // Copy source [string] into [mb_ptr]
    strPtr = string;
    while (--length > 0) {
        *tempPtr++ = *strPtr++;
    }
    *tempPtr = '\0';
}


// #### Destructor
// #########
my::String::~String()
{
    delete[] mb_ptr;
}

// #### Overloaded [operator>>]
// #########
std::istream& my::operator>>(std::istream& in, String& string)
{
    int base {40};
    int bufSize{base};
    char ch {};
    char* bufPtr = new char[bufSize];
    char* bufStart {bufPtr};
    int length {0};


    bool skipLeadingSpaces {true};

    while ((ch = in.get()) != '\n' && !in.eof()) {

        // ## Skip the leading whitespaces
        if (skipLeadingSpaces && (ch == ' ' || ch == '\t')) {
            continue;
        }
        else { /* Nothing to do */ }
        skipLeadingSpaces = false;

        *bufPtr = ch;
        ++length;

        // ## Resize buffer
        if (length < bufSize) {
            ++bufPtr;
        }
        else {
            bufSize += base;
            bufPtr = new char[bufSize];
            for (int ii {0}; ii < bufSize; ++ii) {
                bufPtr[ii] = bufStart[ii];
            }
            delete[] bufStart;
            bufStart = bufPtr;
        }

    } /* End of while() */
    *bufPtr = '\0';
    ++length;

    // ## Transfer input string into my::String
    if (string.mb_ptr != nullptr)
        delete[] string.mb_ptr;
    else { /* Nothing to do */ }

    string.mb_ptr = bufStart;
    string.mb_length = length;

    bufStart = bufPtr = nullptr;

    return in;

}



// #### Overloaded [operator<<]
// #########
std::ostream& my::operator<<(std::ostream& out, const String& string)
{
    int length {string.mb_length};
    char* strPtr {string.mb_ptr};

    // Output symbols except last '\0'
    while (--length > 0) {
        out << *strPtr++;
    }

    return out;
}
