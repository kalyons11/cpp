#include <iostream>

namespace MyNamespace  // namespace declaration
{
    void my_function()
    {
        // do something
        std::cout << "Hello from MyNamespace!" << '\n';
    }

    // Nested namespace
    namespace InnerNamespace
    {
        void inner_function()
        {
            // do something
            std::cout << "Hello from InnerNamespace!" << '\n';
        }
    }  // namespace InnerNamespace
}  // namespace MyNamespace
