/*
 * Efficient storage of booleans using booleans.
 *
 * Author: Karolin Varner
 * Date    18.1.2012
 * File:   boolar.hpp
 *
 * TODO: Exception handling
 */

#include <cstring>

typedef unsigned int norm_t;
#define norm_t_l sizeof(norm_t)

class BoolArr {
public:
    /** 
     * Initialize from capacity.
     * Note that the capacity must always be
     * a multiple of norm_t_l.
     * The capacity might therefor be anythin up to:
     * capacity + norm_t_l -1
     */
    BoolArr(size_t cap);
    ~BoolArr();

    /** Get the elem at */
    bool get(size_t at);
    /** Set element at return the old val */
    void set(size_t at, bool val);

    /** Resize the buffer */
    void resize(size_t cap);

    /** Getter for the capacity */
    size_t capacity();
protected:
    norm_t* data;
    size_t data_cap;
    size_t bool_cap;
};
