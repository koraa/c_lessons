/*
 * File: boolarr.c
 * Date: 18.1.2012
 * Author: Karolin Varner
 * Header: boolarr.hpp
 */
#include "boolarr.h"
#include <stdlib.h>

using namespace std;

BoolArr::BoolArr(size_t cap) {
    this->data = NULL;
    resize(cap);
}
BoolArr::~BoolArr() {
    free(this->data);
}

bool BoolArr::get(size_t at) {
    size_t idx   = at/norm_t_l,
           shift = at%norm_t_l;
    return this->data[idx] & (0x1 << shift);
}
void BoolArr::set(size_t at, bool val) {
    size_t idx   = at/norm_t_l,
           shift = at%norm_t_l;
    norm_t mask = (0x1 << shift);
    this->data[idx] = (this->data[idx] & !mask) | (val << shift);
}

void BoolArr::resize(size_t cap) {
    this->data_cap = (cap / norm_t_l) + (cap%norm_t_l ? 1 : 0);
    this->bool_cap = this->data_cap * norm_t_l;

    this->data = (norm_t*)malloc(this->data_cap * norm_t_l);
}

size_t BoolArr::capacity() {
    return this->bool_cap;
}
