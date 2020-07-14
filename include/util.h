//
// Created by mart on 6/16/20.
//

#ifndef LIBNITRO_UTIL_H
#define LIBNITRO_UTIL_H

class buffer {
private:
    char* buf;
    int index;

public:
    buffer(int size);
    buffer(char* buf);

    buffer* pack(char c);
    buffer* pack(short s);
    buffer* pack(int i);
    buffer* pack(char* buf_, int size);

    bool unpackBool();
    char unpackChar();
    short unpackShort();
    int unpackInt();
    char* unpackBuffer(int size);

    char* getBuf();
};

#endif //LIBNITRO_PY_UTIL_H
