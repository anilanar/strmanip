//
//  mnp_string_funcs.h
//  str_manip
//
//  Created by Anil Anar on 17.06.2014.
//  Copyright (c) 2014 Urnware. All rights reserved.
//

#ifndef str_manip_mnp_string_funcs_h
#define str_manip_mnp_string_funcs_h

template<class CharT, class Traits, class Allocator>
class mnp::basic_string<CharT, Traits, Allocator>::string_funcs {
private:
    friend class mnp::basic_string<CharT, Traits, Allocator>;
    static size_t size(const CharT* arr);
    static void copy(const CharT* from, CharT* to, size_t size);
};

#include "mnp_string_funcs_impl.h"

#endif
