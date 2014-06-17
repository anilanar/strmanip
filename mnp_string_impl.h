//
//  mnp_string_impl.h
//  str_manip
//
//  Created by Anil Anar on 17.06.2014.
//  Copyright (c) 2014 Urnware. All rights reserved.
//

#ifndef str_manip_mnp_string_impl_h
#define str_manip_mnp_string_impl_h

#define __TEMPL__  template<class CharT, class Traits, class Allocator>
#define __CLS__ mnp::basic_string<CharT, Traits, Allocator>
#define _INNER_ typename __CLS__


__TEMPL__
__CLS__::basic_string():
    _allocator(),
    _arr(_allocate(0)),
    _size(0) { }

__TEMPL__
__CLS__::basic_string(const_ref_t str):
    _allocator(str.get_allocator()),
    _arr(_allocate(str.size())),
    _size(str.size())
{
    _IMPL::copy(str._arr, _arr, _size);
}

__TEMPL__
__CLS__::basic_string(const_ref_o str):
    _allocator(str.get_allocator()),
    _arr(_allocate(str.size())),
    _size(str.size())
{
    _IMPL::copy(str.c_str(), _arr, _size);
}

__TEMPL__
__CLS__::basic_string(const CharT* s):
    _allocator()
{
    _size = _IMPL::size(s);
    _arr = _allocate(_size);
    _IMPL::copy(s, _arr, _size);
}

__TEMPL__
_INNER_::ref_t __CLS__::operator=(const_ref_o str) {
    _copy_from_arr(str.c_str(), str.size());
    return *this;
}

__TEMPL__
_INNER_::ref_t __CLS__::operator=(const_ref_t str) {
    _copy_from_arr(str._arr, str._size);
    return *this;
}

__TEMPL__
_INNER_::ref_t __CLS__::operator=(const CharT* s) {
    size_t size = _IMPL::size(s);
    _copy(s, size);
    return *this;
}

__TEMPL__
_INNER_::ref_t __CLS__::operator=(CharT ch) {
    _copy_from_arr(&ch, 1);
    return *this;
}

__TEMPL__
size_t __CLS__::find(const_ref_t str) const {
    return 0;
}

__TEMPL__
size_t __CLS__::find(const_ref_o str) const {
    return 0;
}

__TEMPL__
size_t __CLS__::find(const CharT* str) const {
    return 0;
}

__TEMPL__
size_t __CLS__::count(const_ref_t str) const {
    return 0;
}

__TEMPL__
size_t __CLS__::count(const_ref_o str) const {
    return 0;
}

__TEMPL__
size_t __CLS__::count(const CharT* str) const {
    return 0;
}

__TEMPL__
size_t __CLS__::size() const {
    return _size;
}

__TEMPL__
size_t __CLS__::c_str(CharT *arr) const {
    _IMPL::copy(_arr, arr, _size);
    return _size;
}

__TEMPL__
Allocator __CLS__::get_allocator() const {
    return _allocator;
}

__TEMPL__
CharT* __CLS__::_allocate(size_t size) {
    return _allocator.allocate(size + 1);
}

__TEMPL__
void __CLS__::_deallocate() {
    _allocator.deallocate(_arr, _size + 1);
}

__TEMPL__
void __CLS__::_copy(const CharT* from, size_t size) {
    if(_size == size)
        _IMPL::copy(from, _arr, _size + 1);
    else {
        _deallocate();
        _size = size;
        _arr = _allocate(_size);
        _IMPL::copy(from, _arr, _size);
    }
}

#undef _INNER_
#undef __CLS__
#undef __TEMPL__
#endif
