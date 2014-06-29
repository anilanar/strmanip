//
//  mnp_string_funcs_impl.h
//  str_manip
//
//  Created by Anil Anar on 17.06.2014.
//  Copyright (c) 2014 Urnware. All rights reserved.
//

#ifndef str_manip_mnp_string_funcs_impl_h
#define str_manip_mnp_string_funcs_impl_h

#define __TEMPL__  template<class CharT, class Traits, class Allocator>
#define __CLS__ mnp::basic_string<CharT, Traits, Allocator>::string_funcs

__TEMPL__
size_t __CLS__::size(const CharT* arr) {
    size_t i;
    for(i = 0; arr[i]; i++);
    return i;
}

__TEMPL__
void __CLS__::copy(const CharT* from, CharT* to, size_t size) {
    memcpy(to, from, size * sizeof(CharT));
}

#undef __CLS__
#undef __TEMPL__

#endif
