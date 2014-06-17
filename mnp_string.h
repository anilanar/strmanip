//
//  string.h
//  str_manip
//
//  Created by Anil Anar on 15.06.2014.
//  Copyright (c) 2014 Urnware. All rights reserved.
//

#ifndef __str_manip__string__
#define __str_manip__string__

#include <string>
#include <cstring>
#include <initializer_list>

namespace mnp {
    template<
        class CharT = char,
        class Traits = std::char_traits<CharT>,
        class Allocator = std::allocator<CharT>
    > class basic_string {
        
    private:
        class basic_string_impl;
        
        typedef basic_string<CharT, Traits, Allocator> str_t;
        typedef std::basic_string<CharT, Traits, Allocator> str_o;
        typedef basic_string_impl _IMPL;
        
        typedef str_t&          ref_t;
        typedef const str_t&    const_ref_t;
        typedef str_o&          ref_o;
        typedef const str_o&    const_ref_o;
        
        Allocator           _allocator;
        CharT*              _arr;
        size_t              _size;
        
        CharT* _allocate(size_t size);
        void _deallocate();
        void _copy(const CharT* from, size_t size);
        
    public:
        basic_string();
        
        basic_string(const_ref_t str);
        basic_string(const_ref_o str);
        basic_string(const CharT* s);
        
        ref_t operator=(const_ref_o str);
        ref_t operator=(const_ref_t str);
        ref_t operator=(const CharT* s);
        ref_t operator=(CharT ch);
        
        size_t size() const;
        size_t c_str(CharT *arr) const;
        
        Allocator get_allocator() const;
    };
    
    typedef basic_string<char, std::char_traits<char>, std::allocator<char>> string;
}

#include "mnp_string_impl.h"

#endif /* defined(__str_manip__string__) */
