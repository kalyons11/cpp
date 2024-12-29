#ifndef __SCOPE_DUR_LINK_LINKAGE_HPP_H
#define __SCOPE_DUR_LINK_LINKAGE_HPP_H

extern int g_globalVariable;

// Functions have external linkage by default
void show_linkage();

// We can define a function with internal linkage by using the static keyword
[[maybe_unused]] static void show_internal_linkage();

extern const int g_externConst;  // declare an external const variable

// Best practice
// Only use extern for global variable forward declarations or const global
// variable definitions. Do not use extern for non-const global variable
// definitions (they are implicitly extern).

#endif  // __SCOPE_DUR_LINK_LINKAGE_HPP_H
