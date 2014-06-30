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
#include <initializer_list>
#include <memory>
#include <map>
#include "x_fast_trie.h"

namespace mnp {
    
    template<
        class CharT = char,
        class Traits = std::char_traits<CharT>,
        class Allocator = std::allocator<CharT>
    > class basic_string {
        
    public:
        typedef intptr_t   size_type;
        
    private:
        class string_funcs;
        class flyweight;
        class mnp_string_iterator;
        
        typedef basic_string<CharT, Traits, Allocator>      str_t;
        typedef std::basic_string<CharT, Traits, Allocator> str_o;
        typedef string_funcs                                _IMPL;
        typedef flyweight                                   _FLY;
        
        typedef str_t&          ref_t;
        typedef const str_t&    const_ref_t;
        typedef str_o&          ref_o;
        typedef const str_o&    const_ref_o;
        
        
        struct __long {
            CharT*                  arr;
            size_type                  start;
            bool                    is_reversed;
            bool                    is_parent;
        };
        union __back_end {
            constexpr static size_type f_max_size() {
                return sizeof(__long) / sizeof(CharT);
            }
            
            __long  l;
            CharT  s[f_max_size()];
        };

        // private class members
        Allocator       m_allocator;
        __back_end      m_back_end;
        bool            m_is_long;
        size_type          m_size;
        
        
        // private class functions
        void            f_init_ref(CharT* const arr,
                                   const size_type& start,
                                   const bool& is_reversed);
        
        void            f_init_copy(const CharT* const arr);
        int             f_class_size() const;
        size_type          f_find(mnp_string_iterator str,
                               const size_type start_index,
                               const size_type count) const;
        size_type          f_find_c(const CharT* const str,
                                 const size_type start_index) const;
        size_type          f_count(mnp_string_iterator str,
                                const size_type size) const;
        
        template<class T>
        size_type          f_index(T param) const;
        
        bool                 f_is_long(size_type sz) const;
        void                 f_copy(const CharT* from, CharT* to, size_type s);
        
        
        //private ref-copy constructor
        basic_string(CharT* arr,
                     size_type size,
                     size_type start,
                     bool is_reversed,
                     const Allocator& allocator = Allocator());
        
    public:
        typedef basic_string<CharT, Traits, Allocator>::mnp_string_iterator const_iterator;
        
        basic_string();
        
        virtual ~basic_string();
        
        basic_string(const_ref_t str);
        basic_string(const_ref_o str);
        basic_string(const CharT* s);
        
        //hard-copy constructor
        basic_string(const CharT* arr,
                     size_type size,
                     const Allocator& allocator = Allocator());
        
        ref_t operator=(const_ref_o str);
        ref_t operator=(const_ref_t str);
        ref_t operator=(const CharT* s);
        ref_t operator=(CharT ch);
        
        size_type find(const_ref_t str) const;
        size_type find(const_ref_o str) const;
        size_type find(const CharT* str) const;
        
        size_type index(const_ref_t str) const;
        size_type index(const_ref_o str) const;
        size_type index(const CharT* str) const;
        
        size_type count(const_ref_t str) const;
        size_type count(const_ref_o str) const;
        size_type count(const CharT* str) const;
        
        str_t substr(size_type s, size_type e) const;
        
        const_iterator cbegin() const;
        const_iterator cend() const;
        
        size_type size() const;
        size_type c_str(CharT* str) const;
        const CharT* data() const;
        
        Allocator get_allocator() const;
        
    };
    
    typedef basic_string<char, std::char_traits<char>, std::allocator<char>> string;
}


#include "mnp_string_iterator.h"
#include "mnp_string_impl.h"
#include "mnp_string_funcs.h"
#include "mnp_flyweight.h"


#endif /* defined(__str_manip__string__) */
