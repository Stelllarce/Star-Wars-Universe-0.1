#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <cstring>
#include <sstream>
class String {

    private:
    size_t capacity, len;
    char* string;

    void resize(size_t capacity);
    public:

    //constructors
    String();
    String(char *s);
    String(const char *s);
    String(const String& s);
    String(String&& s);
    ~String();

    //capacity
    size_t get_size();
    size_t get_capacity();
    // char* get_string();
    char get_at(size_t pos);
    char get_back();
    char get_front();

    //modifiers (could put const char* as arguments) 
    String& operator=(const String& s);
    String& my_append(const String& s);
    void my_push_back(char c);
    String& my_insert (size_t p, const String& s);
    String& erasePos(size_t pos);//*
    String& eraseChar(char c);//*
    String& my_replace(size_t pos, const String& s);//*should these have len as arguments?
    void my_swap(String& s);
    void my_pop_back();

    //friend functions
    friend bool operator<(const String& s, const String& s1);
    friend bool operator>(const String& s, const String& s1);
    friend bool operator==(const String& s, const String& s1);
    friend bool operator>=(const String& s, const String& s1);
    friend bool operator<=(const String& s, const String& s1);
    friend bool operator!=(const String& s, const String& s1);

    friend String operator+(const String s, const String s1);
    friend std::ostream& operator<<(std::ostream& os, const String& s);
    friend std::istream& operator>>(std::istream& is, String& s);

    //operations
    const char* cStr() const;
    String my_substr(size_t pos, size_t len) const;
    template <typename T>
    void toString(T type);
    String toString2(int);
    
};
    //strcat
    String operator+(const String s, const String s1);

    //strlen
    unsigned int strlen_a(const char *s);

    //strcpy
    char* strcpy_a(char* destination, const char* source);

    //compare operators
    bool operator<(const String& s, const String& s1);
    bool operator>(const String& s, const String& s1);
    bool operator==(const String& s, const String& s1);
    bool operator>=(const String& s, const String& s1);
    bool operator<=(const String& s, const String& s1);
    bool operator!=(const String& s, const String& s1);
    
    //output/input stream
    std::ostream& operator<<(std::ostream& os, const String& s);
    std::istream& operator>>(std::istream& is, String& s);
    
    template <typename T>
    void String::toString(T type) {

        std::string st = std::to_string(type);
        char const* cstr = st.c_str();
        capacity = strlen(cstr);
        len = strlen(cstr);
        delete[] string;
        string = new char[capacity + 1];
        strcpy(string, cstr);

    }
    
    

#endif
