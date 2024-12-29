#ifndef __SCOPE_DUR_LINK_NAME_HPP_H
#define __SCOPE_DUR_LINK_NAME_HPP_H

namespace MyNamespace  // namespace declaration
{
    void my_function();

    namespace InnerNamespace
    {
        void inner_function();
    }

    // namespaces can have global variables
    int globalVariable{10};
}  // namespace MyNamespace

#endif  // __SCOPE_DUR_LINK_NAME_HPP_H
