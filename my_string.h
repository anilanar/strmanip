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
        class basic_string_impl {
        public:
            static size_t size(const CharT* arr) {
                size_t i;
                for(i = 0; arr[i]; i++);
                return i;
            }
            
            static void copy(const CharT* from, CharT* to, size_t size) {
                memcpy(to, from, (size + 1) * sizeof(CharT));
            }
        };
        
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
        
        CharT* _allocate(size_t size) {
            return _allocator.allocate(_size + 1);
        }
        
        void _deallocate(CharT* arr, size_t size) {
            _allocator.deallocate(arr, size + 1);
        }
        
        void _copy_from_arr(const CharT* from, size_t size) {
            if(_size == size)
                _IMPL::copy(from, _arr, _size + 1);
            else {
                _deallocate(_arr, _size);
                _size = size;
                _arr = _allocate(_size);
                _IMPL::copy(from, _arr, _size);
            }
        }
        
        
    public:
        basic_string():
            _allocator(),
            _arr(_allocate(0)),
            _size(0)
        {
        }
        
        basic_string(const_ref_t str):
            _allocator(str.get_allocator()),
            _arr(_allocate(str.size())),
            _size(str.size())
        {
            _IMPL::copy(str._arr, _arr, _size);
        }
        
        basic_string(const_ref_o str):
            _allocator(str.get_allocator()),
            _arr(_allocate(str.size())),
            _size(str.size())
        {
            _IMPL::copy(str.c_str(), _arr, _size);
        }
        
        basic_string(const CharT* s):
            _allocator()
        {
            _size = _IMPL::size(s);
            _arr = _allocate(_size);
            _IMPL::copy(s, _arr, _size);
        }
        
        ref_t operator=(const_ref_o str) {
            _copy_from_arr(str.c_str(), str.size());
            return *this;
        }
        
        ref_t operator=(const_ref_t str) {
            _copy_from_arr(str._arr, str._size);
            return *this;
        }
        
        ref_t operator=(const CharT* s) {
            size_t size = _IMPL::size(s);
            _copy_from_arr(s, size);
            return *this;
        }
        
        ref_t operator=(CharT ch) {
            _copy_from_arr(&ch, 1);
            return *this;
        }
        
        str_t& operator[](size_t pos) const {
            
        }
        
        str_t& operator[](std::initializer_list<int>) {
            return *this;
        }
        
        size_t size() const {
            return _size;
        }
                                 
        Allocator get_allocator() const {
            return _allocator;
        }
        
        size_t c_str(CharT *arr) const {
            _IMPL::copy(_arr, arr, _size);
            return _size;
        }
        
        size_t count(const CharT *arr) const {
            return 0;
        }
        
        size_t count(const_ref_t str) const {
            return 0;
        }
        
        size_t count(const_ref_o str) const {
            return 0;
        }
        
        size_t find(const CharT *arr) const {
            return 0;
        }
        
        size_t find(const_ref_t str) const {
            return 0;
        }
        
        size_t find(const_ref_o str) const {
            return 0;
        }
    };
    
    typedef basic_string<char, std::char_traits<char>, std::allocator<char>> string;
}

#endif /* defined(__str_manip__string__) */
