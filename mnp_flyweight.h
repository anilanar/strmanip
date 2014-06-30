//
//  mnp_flyweight.h
//  str_manip
//
//  Created by Anil Anar on 26.06.2014.
//  Copyright (c) 2014 Urnware. All rights reserved.
//

#ifndef str_manip_mnp_flyweight_h
#define str_manip_mnp_flyweight_h

template<class CharT, class Traits, class Allocator>
class mnp::basic_string<CharT, Traits, Allocator>::flyweight {
private:
    struct counter {
        size_t count;
        size_t size;
    };
    
    static kora::x_fast_trie<uintptr_t, 64, counter> s_map;
    
public:
    static void insert(CharT* arr, size_t size) {
        s_map.insert({uintptr_t(arr), {1, size}});
    }
    static void increment(CharT* arr) {
        counter &c = s_map.find(uintptr_t(arr))->second;
        c.count++;
    }
    static void decrement(CharT* arr) {
        counter &c = s_map.find(uintptr_t(arr))->second;
        
        c.count--;
        if(!c.count) {
            size_t size = c.size;
            Allocator().deallocate(arr, size);
        }
    }
};

template<class CharT, class Traits, class Allocator>
typename kora::x_fast_trie<uintptr_t, 64, typename mnp::basic_string<CharT, Traits, Allocator>::flyweight::counter> mnp::basic_string<CharT, Traits, Allocator>::flyweight::s_map;

#endif
