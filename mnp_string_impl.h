//
//  mnp_string_impl.h
//  str_manip
//
//  Created by Anil Anar on 17.06.2014.
//  Copyright (c) 2014 Urnware. All rights reserved.
//

#ifndef str_manip_mnp_string_impl_h
#define str_manip_mnp_string_impl_h

#define _TEMP_  template<class CharT, class Traits, class Allocator>
#define _CLASS_ mnp::basic_string<CharT, Traits, Allocator>
#define _INNER_ typename _CLASS_


_TEMP_
_CLASS_::basic_string():
    _allocator(),
    _arr(_allocate(0)),
    _size(0) { }

_TEMP_
_CLASS_::basic_string(const_ref_t str):
    _allocator(str.get_allocator()),
    _arr(_allocate(str.size())),
    _size(str.size())
{
    _IMPL::copy(str._arr, _arr, _size);
}

_TEMP_
_CLASS_::basic_string(const_ref_o str):
    _allocator(str.get_allocator()),
    _arr(_allocate(str.size())),
    _size(str.size())
{
    _IMPL::copy(str.c_str(), _arr, _size);
}

_TEMP_
_CLASS_::basic_string(const CharT* s):
    _allocator()
{
    _size = _IMPL::size(s);
    _arr = _allocate(_size);
    _IMPL::copy(s, _arr, _size);
}

_TEMP_
_INNER_::ref_t _CLASS_::operator=(const_ref_o str) {
    _copy_from_arr(str.c_str(), str.size());
    return *this;
}

_TEMP_
_INNER_::ref_t _CLASS_::operator=(const_ref_t str) {
    _copy_from_arr(str._arr, str._size);
    return *this;
}

_TEMP_
_INNER_::ref_t _CLASS_::operator=(const CharT* s) {
    size_t size = _IMPL::size(s);
    _copy(s, size);
    return *this;
}

_TEMP_
_INNER_::ref_t _CLASS_::operator=(CharT ch) {
    _copy_from_arr(&ch, 1);
    return *this;
}

_TEMP_
size_t _CLASS_::size() const {
    return _size;
}

_TEMP_
size_t _CLASS_::c_str(CharT *arr) const {
    _IMPL::copy(_arr, arr, _size);
    return _size;
}

_TEMP_
Allocator _CLASS_::get_allocator() const {
    return _allocator;
}

_TEMP_
CharT* _CLASS_::_allocate(size_t size) {
    return _allocator.allocate(size + 1);
}

_TEMP_
void _CLASS_::_deallocate() {
    _allocator.deallocate(_arr, _size + 1);
}

_TEMP_
void _CLASS_::_copy(const CharT* from, size_t size) {
    if(_size == size)
        _IMPL::copy(from, _arr, _size + 1);
    else {
        _deallocate();
        _size = size;
        _arr = _allocate(_size);
        _IMPL::copy(from, _arr, _size);
    }
}

_TEMP_
class _CLASS_::basic_string_impl {
public:
    static size_t size(const CharT* arr);
    static void copy(const CharT* from, CharT* to, size_t size);
};

_TEMP_
size_t _CLASS_::basic_string_impl::size(const CharT* arr) {
    size_t i;
    for(i = 0; arr[i]; i++);
    return i;
}

_TEMP_
void _CLASS_::basic_string_impl::copy(const CharT* from, CharT* to, size_t size) {
    memcpy(to, from, (size + 1) * sizeof(CharT));
}

#undef _INNER_
#undef _CLASS_
#undef _TEMP_
#endif
