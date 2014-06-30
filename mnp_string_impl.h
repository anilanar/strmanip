//
//  mnp_string_impl.h
//  str_manip
//
//  Created by Anil Anar on 17.06.2014.
//  Copyright (c) 2014 Urnware. All rights reserved.
//

#ifndef str_manip_mnp_string_impl_h
#define str_manip_mnp_string_impl_h

#define __TMPL  template<class CharT, class Traits, class Allocator>
#define __CLS mnp::basic_string<CharT, Traits, Allocator>
#define __INNER typename __CLS

#include <cstring>

__TMPL
__CLS::basic_string():
    basic_string("", 0)
{
}

__TMPL
__CLS::~basic_string() {
    if(m_is_long)
        _FLY::decrement(m_back_end.l.arr);
}

__TMPL
__CLS::basic_string(const_ref_t str)
{
    m_allocator = str.m_allocator;
    memcpy(&m_back_end, &(str.m_back_end),
           sizeof(__back_end));
    m_is_long = str.m_is_long;
    m_size = str.m_size;
    if(m_is_long)
        _FLY::increment(m_back_end.l.arr);
}

__TMPL
__CLS::basic_string(const_ref_o str):
    basic_string(str.c_str(),
                 str.size(),
                 str.get_allocator())
{
}

__TMPL
__CLS::basic_string(const CharT* s):
    basic_string(s, _IMPL::size(s))
{
}

__TMPL
__CLS::basic_string(const CharT* arr,
                    size_type size,
                    const Allocator& allocator):
    m_allocator(allocator),
    m_size(size)
{
    f_init_copy(arr);
}

__TMPL
__CLS::basic_string(CharT* arr,
                    size_type size,
                    size_type start,
                    bool is_reversed,
                    const Allocator& allocator):
    m_allocator(allocator),
    m_size(size)
{
    f_init_ref(arr, start, is_reversed);
}

__TMPL
__INNER::ref_t __CLS::operator=(const_ref_o str) {
    if(m_is_long)
        _FLY::decrement(m_back_end.l.arr);
    m_size = str.size();
    m_allocator = str.get_allocator();
    f_init_copy(str.c_str());
    return *this;
}

__TMPL
__INNER::ref_t __CLS::operator=(const_ref_t str) {
    if(m_is_long)
        _FLY::decrement(m_back_end.l.arr);
    m_allocator = str.m_allocator;
    memcpy(&m_back_end, &(str.m_back_end),
           sizeof(__back_end));
    m_is_long = str.m_is_long;
    m_size = str.m_size;
    if(m_is_long)
        _FLY::increment(m_back_end.l.arr);
    return *this;
}

__TMPL
__INNER::ref_t __CLS::operator=(const CharT* s) {
    if(m_is_long)
        _FLY::decrement(m_back_end.l.arr);
    m_size = _IMPL::size(s);
    m_is_long = f_is_long(m_size);
    f_init_copy(s);
    return *this;
}

__TMPL
__INNER::ref_t __CLS::operator=(CharT ch) {
    if(m_is_long)
        _FLY::decrement(m_back_end.l.arr);
    m_size = 1;
    m_is_long = false;
    m_back_end.s[0] = ch;
    m_back_end.s[1] = '\0';
    return *this;
}

__TMPL
__INNER::size_type __CLS::find(const_ref_t str) const {
    return f_find(str.cbegin(), 0, str.m_size);
}

__TMPL
__INNER::size_type __CLS::find(const_ref_o str) const {
    return f_find(const_iterator(str.c_str(), false), 0, str.size());
}

__TMPL
__INNER::size_type __CLS::find(const CharT *str) const {
    return f_find_c(str, 0);
}

__TMPL
__INNER::size_type __CLS::index(const_ref_t str) const {
    return f_index(str);
}

__TMPL
__INNER::size_type __CLS::index(const_ref_o str) const {
    return f_index(str);
}

__TMPL
__INNER::size_type __CLS::index(const CharT *str) const {
    return f_index(str);
}

__TMPL
__INNER::size_type __CLS::count(const_ref_t str) const {
    return f_count(str.cbegin(), str.m_size);
}

__TMPL
__INNER::size_type __CLS::count(const_ref_o str) const {
    return f_count(const_iterator(str.c_str(), false), str.size());
}

__TMPL
__INNER::size_type __CLS::count(const CharT *str) const {
    if(!str) return 0;
    if(!str[0]) return m_size + 1;
    size_type i = 0, j, c = 0;
    while(i < m_size) {
        if(-1 != (j = f_find_c(str, i))) {
            i = i + j + 1;
            c++;
        }
        else return c;
    }
    return c;
}

__TMPL
__INNER::str_t __CLS::substr(size_type s, size_type e) const {
    const size_type s_r = s < 0 ? m_size + s : s;
    const size_type e_r = e < 0 ? m_size + e : e;
    if(s_r < 0 || s_r >= m_size || e_r < -1 || e_r > m_size)
        throw std::out_of_range("");
    const bool is_reversed = s_r > e_r;
    const bool double_reversed = is_reversed && m_is_long && m_back_end.l.is_reversed;
    size_type size = s_r - e_r;
    size = size < 0 ? -size : size;
    
    if(f_is_long(size))
        return __CLS(m_back_end.l.arr,
                     size,
                     double_reversed ? (is_reversed ? e_r + 1 : e_r - 1) : s_r,
                     is_reversed && !double_reversed,
                     m_allocator);
    else {
        __CLS sub_str;
        if(!is_reversed || double_reversed) {
            memcpy(sub_str.m_back_end.s,
                   (cbegin() + s_r).m_ptr,
                   size * sizeof(CharT));
        }
        else {
            const_iterator it = cbegin() + s_r;
            for(int i = 0; i < size; ++i, --it)
                sub_str.m_back_end.s[i] = *it;
        }
        
        sub_str.m_size = size;
        sub_str.m_back_end.s[size] = '\0';
        
        return sub_str;
    }
}

__TMPL
__INNER::const_iterator __CLS::cbegin() const {
    return
    const_iterator(m_is_long ? m_back_end.l.arr + m_back_end.l.start : m_back_end.s,
                   m_is_long ? m_back_end.l.is_reversed : false);
}

__TMPL
__INNER::const_iterator __CLS::cend() const {
    return cbegin() + m_size;
}

__TMPL
__INNER::size_type __CLS::size() const {
    return m_size;
}

__TMPL
__INNER::size_type __CLS::c_str(CharT *str) const {
    const_iterator it = cbegin();
    if(!m_is_long || !m_back_end.l.is_reversed)
        memcpy(str, it.m_ptr, m_size * sizeof(CharT));
    else {
        for(int i = 0; i < m_size; i++)
            str[i] = *it++;
    }
    str[m_size] = '\0';
    return m_size;
}

__TMPL
const CharT* __CLS::data() const {
    return cbegin().m_ptr;
}


__TMPL
void __CLS::f_init_ref(CharT *const arr,
                       const size_type& start,
                       const bool& is_reversed) {
    m_is_long = f_is_long(m_size);
    if(m_is_long) {
        m_back_end.l.arr = arr;
        _FLY::increment(arr);
        m_back_end.l.start = start;
        m_back_end.l.is_reversed = is_reversed;
        m_back_end.l.is_parent = false;
    } else {
        f_copy(arr, m_back_end.s, m_size);
    }
}

__TMPL
void __CLS::f_init_copy(const CharT *const arr) {
    m_is_long = f_is_long(m_size);
    if(m_is_long) {
        m_back_end.l.arr = m_allocator.allocate(m_size + 1);
        _FLY::insert(m_back_end.l.arr, m_size + 1);
        _IMPL::copy(arr, m_back_end.l.arr, m_size);
        m_back_end.l.start = 0;
        m_back_end.l.is_reversed = false;
        m_back_end.l.is_parent = true;
    } else {
        f_copy(arr, m_back_end.s, m_size);
    }
}

__TMPL
int __CLS::f_class_size() const {
    return
        sizeof(Allocator) +
        sizeof(__back_end) +
        sizeof(bool) +
        sizeof(size_type);
}


__TMPL
bool __CLS::f_is_long(size_type sz) const {
    return (sz + 1) > __back_end::f_max_size();
}

__TMPL
void __CLS::f_copy(const CharT *from, CharT *to, size_type s) {
    memcpy(to, from, s);
    to[s] = '\0';
}

__TMPL
__INNER::size_type __CLS::f_find(const_iterator str,
                     const size_type start_index,
                     const size_type size) const {
    if(m_size - start_index < size) return -1;
    if(!size) return 0;
    
    const_iterator org = cbegin();
    const_iterator it = org + start_index;
    for(; it != cend() - (size - 1); ++it) {
        if(*it == str.m_ptr[0]) {
            const_iterator it2 = it;
            ++it2;
            const_iterator str2 = str;
            ++str2;
            for(;str2 != str + size; ++str2, ++it2)
                if(*str2 != *it2) break;
            if(str2 == str + size)
                return it - org;
        }
    }
    return -1;
}

__TMPL
__INNER::size_type __CLS::f_find_c(const CharT* const str,
                       const size_type start_index) const {
    if(!str) return -1;
    if(!str[0]) return 0;
    
    const_iterator org = cbegin();
    const_iterator it = org + start_index;
    
    if(!m_is_long || !m_back_end.l.is_reversed) {
        const CharT* found = strstr(it.m_ptr, str);
        if(!found) return -1;
        return found - org.m_ptr;
    }
    
    for(; it != cend() - 1; ++it) {
        if(*it == str[0]) {
            const_iterator it2 = it;
            ++it2;
            const CharT* str2 = str;
            str2++;
            while(*str2 && it2 != cend())
                if(*str2++ != *it2++) break;
            if(!*str2)
                return it2 - org;
        }
    }
    return -1;
}

__TMPL
__INNER::size_type __CLS::f_count(const_iterator str,
                      const size_type size) const {
    if(!size) return m_size + 1;
    size_type i = 0, j, c = 0;
    while(i <= m_size - size) {
        if(-1 != (j = f_find(str, i, size))) {
            i = j + 1;
            c++;
        }
        else return c;
    }
    return c;
}

__TMPL
template<class T>
__INNER::size_type __CLS::f_index(T param) const {
    size_type r = find(param);
    if(r == -1) throw std::out_of_range("");
    return r;
}


#undef __INNER
#undef __CLS
#undef __TMPL
#endif
