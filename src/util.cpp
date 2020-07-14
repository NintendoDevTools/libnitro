//
// Created by mart on 6/16/20.
//

#include <cstdlib>
#include <cstring>
#include "../include/util.h"

buffer::buffer(int size) {
    buf = (char*)malloc(size);
    index = 0;
}

buffer::buffer(char* buf) {
    this->buf = buf;
    index = 0;
}

buffer* buffer::pack(char c) {
    buf[index] = c;
    index++;
    return this;
}

buffer* buffer::pack(short s) {
    for (int i = 0; i < 2; i++) {
        buf[index] = (s >> (i*8)) & 0xFF;
        index++;
    }
    return this;
}

buffer* buffer::pack(int i) {
    for (int j = 0; j < 4; j++) {
        buf[index] = (i >> (j * 8)) & 0xFF;
        index++;
    }
    return this;
}

buffer* buffer::pack(char* buf_, int size) {
    for (int i = 0; i < size; i++) {
        buf[index] = buf_[i];
        index++;
    }
    return this;
}

bool buffer::unpackBool() {
    bool x = buf[index] == '\1';
    index++;
    return x;
}

char buffer::unpackChar() {
    char b = buf[index];
    index++;
    return b;
}

short buffer::unpackShort() {
    short s = 0;
    for (int i = 0; i < 2; i++) {
        s += buf[index] << (i * 8);
        index++;
    }
    return s;
}

int buffer::unpackInt() {
    short s = 0;
    for (int i = 0; i < 4; i++) {
        s += buf[index] << (i * 8);
        index++;
    }
    return s;
}

char* buffer::unpackBuffer(int size) {
    char* newBuffer = (char*)malloc(size);
    memcpy(newBuffer, &buf[index], size);
    index += size;
    return newBuffer;
}

char* buffer::getBuf() {
    return buf;
}

