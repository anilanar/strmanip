//
//  mnp_string_iterator.h
//  str_manip
//
//  Created by Anil Anar on 27.06.2014.
//  Copyright (c) 2014 Urnware. All rights reserved.
//

#ifndef str_manip_mnp_string_iterator_h
#define str_manip_mnp_string_iterator_h

template<class CharT, class Traits, class Allocator>
class mnp::basic_string<CharT, Traits, Allocator>::mnp_string_iterator {
private:
    friend class mnp::basic_string<CharT, Traits, Allocator>;
    bool m_is_reversed;
    const CharT* m_ptr;
    
    mnp_string_iterator(const CharT* ptr, bool is_reversed):
        m_ptr(ptr),
        m_is_reversed(is_reversed) {}
public:
    
    mnp_string_iterator operator+(const size_t i) const {
        if(!m_is_reversed)
            return mnp_string_iterator(m_ptr + i, m_is_reversed);
        else
            return mnp_string_iterator(m_ptr - i, m_is_reversed);
    }
    
    mnp_string_iterator& operator++() {
        if(!m_is_reversed)
            ++m_ptr;
        else
            --m_ptr;
        
        return *this;
    }
    
    mnp_string_iterator operator++(int) {
        mnp_string_iterator r(m_ptr, m_is_reversed);
        ++(*this);
        return r;
    }
    
    mnp_string_iterator operator-(const size_t i) const {
        if(!m_is_reversed)
            return mnp_string_iterator(m_ptr - i, m_is_reversed);
        else
            return mnp_string_iterator(m_ptr + i, m_is_reversed);
    }
    
    mnp_string_iterator& operator--() {
        if(!m_is_reversed)
            --m_ptr;
        else
            ++m_ptr;
        return *this;
    }
    
    mnp_string_iterator operator--(int) {
        mnp_string_iterator r(m_ptr);
        --(*this);
        return r;
    }
    
    size_t operator-(const CharT* ptr) {
        return m_ptr - ptr;
    }
    
    size_t operator-(const mnp_string_iterator& it) {
        return m_ptr - it.m_ptr;
    }
    
    const CharT& operator*() {
        return *m_ptr;
    }
    
    bool operator==(const mnp_string_iterator& o) {
        return m_ptr == o.m_ptr;
    }
    
    bool operator!=(const mnp_string_iterator& o) {
        return m_ptr != o.m_ptr;
    }
    
    const CharT* operator->() {
        return m_ptr;
    }
    
    
    
};
#endif
