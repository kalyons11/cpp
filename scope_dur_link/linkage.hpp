#ifndef __SCOPE_DUR_LINK_LINKAGE_HPP_H
#define __SCOPE_DUR_LINK_LINKAGE_HPP_H

extern int g_globalVariable;

// Functions have external linkage by default
void show_linkage();

// We can define a function with internal linkage by using the static keyword
[[maybe_unused]] static void show_internal_linkage();

#endif  // __SCOPE_DUR_LINK_LINKAGE_HPP_H
